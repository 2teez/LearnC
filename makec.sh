#!/usr/bin/env bash
# Date: 7th August, 2025
# Description: Make a file that can make a c file
# compile it and run.
# Author: omitida
#

## Help or usage function
# it display what the calling of the script is.
function usage() {
    filename="${0}"
    echo
    echo "Usage: ./${filename} <options> filename"
    echo
    echo "Avaliable Options:"
    echo "-g    : Create a generic c file."
    echo "-r    : Compile and Run a c file"
}

# c start writeup
FILE="
// A complete C Program
#include <stdio.h>

int main(int argc, char** argv){

    printf(\"Hello, World!\");

    return 0;
}
"

# creating a c file
function create_file() {
    filename="${1}"
    filext="${filename#*.}"

    # create a rust file
    rust_file="${filename}.rs"
    echo "
#![allow(dead_code, unused)]

fn main() {
  println!("Hello, World!");
}" > "${rust_file}"
    # make a file with cpp extension
    [[ "${filext}" == "${filename}" ]] && filename="${filename}.c"

    if [[ -e "${filename}" ]]; then
        echo "${filename}" "exist."
        printf "Do you want to overwrite it? [y|n]: "
        while read ans; do
            case "${ans,,}" in
                y)
                echo "// ${filename}" > "${filename}"
                printf "${FILE}" >> "${filename}"
                echo "${filename}" "is overwritten."
                break
                ;;
                n) exit 1
                ;;
                *) echo "can only you use 'y' or 'n'."
                continue
                ;;
            esac
        done
    else
        echo "// ${filename}" > "${filename}"
        echo "${FILE}" >> "${filename}"
    fi
}

if [[ "${#}" != 2 ]]; then
    usage
fi

optstring="d:g:r:h"

while getopts "${optstring}" opt; do
    case "${opt}" in
        d)
        filename="${OPTARG,,}"
        for file in $(ls); do
            if [[ "${filename}" = "${file}" ]]; then
                printf "Do you want to delete ${file}? [y|n]: "
                while read ans; do
                    case "${ans,,}" in
                        y) rm "${file}"
                           exit 0;;
                        n) break;;
                        *) printf "Can only use 'n' for no, and 'y' for yes.\n"
                        continue
                        ;;
                    esac
                done
            fi
        done

        ;;
        g)
          filename="${OPTARG,,}"
          create_file "${filename}"
          ./"${0}" -r "${filename}"
        ;;
        h) usage
           exit 1
        ;;
        r)
            filename="${OPTARG}"
            file_o_run="${filename%.*}";
            gcc -Wall -std=c17  -o "${file_o_run}" "${filename}"
            chmod +x "${file_o_run}"
            ./"${file_o_run}"
            rm "${file_o_run}"
        ;;
        *.*);;
    esac
done
