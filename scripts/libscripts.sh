#
# Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
# SPDX-License-Identifier: MIT
#
# TODO brief description

function get_config_value() {
	local tmp=""
	tmp=$(grep "${1}" ${2})
	if [[ ! ${tmp:0:1} == "#" ]]; then
		echo "$(echo "${tmp}" | cut -d'=' -f2)"
	fi
}

#echo "Loading config"
#while IFS= read -r line
#do
#   str=$(echo "${line}" | sed 's/(/{/g' | sed 's/)/}/g')
#   if [[ ! ${str:0:1} == "#" ]] && [ ! -z "${str}" ]; then
#           #echo "${str}"; 
#           echo -n "."
#           export "${str}"
#   fi
#done < ".config"
#echo ""
#echo "Done"

