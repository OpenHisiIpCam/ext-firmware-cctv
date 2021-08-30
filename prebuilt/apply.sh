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
echo "Output dir ${output_dir}"

GNU_TARGET_NAME=$(make -C ${output_dir} --no-print-directory print-gnu-target-name)
if [ -z "${GNU_TARGET_NAME}" ]; then
	echo "Can't get toolchain name from output dir" >&2
	exit 1
fi

echo "Applying prebuilt" >&2

IFS=$'\n'
FILES=$(find  ${source_dir} -print)

for f in ${FILES}
do
	path=$(realpath -s "${f}" --relative-to="${source_dir}")
	if [ -d "${source_dir}/${path}" ] && [ ! -L "${source_dir}/${path}" ]; then
                mkdir -p "${output_dir}/${path}"
        else
		(cd ${source_dir}; cp -p -P --parent "${path}" "${output_dir}")

                if [ ! -L "${output_dir}/${path}" ]; then
                        # 0 is text, 1 is not text
                        file -b --mime-type "${output_dir}/${path}" | grep -q '^text'
                        if [ $? -eq 0 ]; then
				t=$(stat -c %y "${output_dir}/${path}")
                                sed -i "s|___NEWPATH___|${output_dir}|g" "${output_dir}/${path}"
                                sed -i "s|___GNUTARGETNAME___|${GNU_TARGET_NAME}|g" "${output_dir}/${path}"
				touch -d "$t" "${output_dir}/${path}"
                        fi
                fi
        fi

done

mv ${output_dir}/host/gnu-target-name ${output_dir}/host/${GNU_TARGET_NAME}

echo "Done" >&2
