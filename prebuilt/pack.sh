#!/usr/bin/env bash

if [ -z "${1}" ]; then
	echo "Source dir is not set" >&2
	exit 1
fi
source_dir=$(realpath ${1})
echo "Source dir ${source_dir}" >&2

if [ -z "${2}" ]; then
        echo "Output dir is not set" >&2
        exit 1
fi
output_dir=$(realpath ${2})
echo "Output dir ${output_dir}" >&2

source packages

FILES=".applied_patches_list \
       .files-list-host.txt \
       .files-list-staging.txt \
       .files-list.txt \
       .stamp_built \
       .stamp_configured \
       .stamp_downloaded \
       .stamp_extracted \
       .stamp_host_installed \
       .stamp_installed \
       .stamp_patched"

GNU_TARGET_NAME=i586-buildroot-linux-uclibc

for package in ${PACKAGES}
do
    IFS=$'\n'
    path_arr=($(find ${source_dir}/build -name "${package}*"))
    path=${path_arr[0]}

    package_name=$(basename ${path})

    mkdir -p "${output_dir}/build/${package_name}"
    
    if [ ! $(stat -c%s "${path}/.files-list-staging.txt") -eq 0 ]; then
        echo "WARNING: ${path}/.files-list-staging.txt is not null!" >&2
    fi
    if [ ! $(stat -c%s "${path}/.files-list.txt") -eq 0 ]; then
        echo "WARNING: ${path}/.files-list.txt is not null!" >&2
    fi

    IFS=$' \t\n'
    for file in ${FILES}
    do
	cp -P -p "${path}/${file}" "${output_dir}/build/${package_name}"
    done

    mkdir -p "${output_dir}/host"

    while read -r line; 
    do
	target=$(echo ${line} | cut -d',' -f2-)
	if [ -d "${source_dir}/host/${target}" ] && [ ! -L "${source_dir}/host/${target}" ]; then
		mkdir -p "${output_dir}/host/${target}"
	else	
		(cd ${source_dir}/host; cp -P -p --parent "${target}" "${output_dir}/host")

		if [ ! -L "${output_dir}/host/${target}" ]; then
			# 0 is text, 1 is not text
			file -b --mime-type "${output_dir}/host/${target}" | grep -q '^text/'
			if [ $? -eq 0 ]; then
				t=$(stat -c %y "${output_dir}/host/${target}")
				sed -i "s|${source_dir}|___NEWPATH___|g" "${output_dir}/host/${target}"
				sed -i "s|${GNU_TARGET_NAME}|___GNUTARGETNAME___|g" "${output_dir}/host/${target}"
				touch -d "$t" "${output_dir}/host/${target}"
			fi	
		fi
	fi
    done < "${path}/.files-list-host.txt"
done

if [ -d ${source_dir}/host/${GNU_TARGET_NAME} ]; then
	cp -a "${source_dir}/host/${GNU_TARGET_NAME}" "${output_dir}/host"
	mv "${output_dir}/host/${GNU_TARGET_NAME}" "${output_dir}/host/gnu-target-name"
fi

echo "Done" >&2
