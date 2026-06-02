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
    echo "Usage: ${filename} <options> filename"
    echo
    echo "Avaliable Options:"
    echo "-a    : Create a c file with a corresponding header file."
    echo "-c    : Create a CMakeLists.txt file."
    echo "-g    : Create a generic c file."
    echo "-h    : helper function"
    echo "-r    : Compile and Run a c file."
    exit 1
}

# c start writeup
FILE="
/* A complete C Program */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){

    printf(\"Hello, World!\n\");
    return EXIT_SUCCESS;
}
"


function create_cmake() {
    filename="${1}"
    cfilename="CMakeLists.txt"
    {
        echo "cmake_minimum_required(VERSION 3.10)"
        echo "project(${filename%.*} LANGUAGES C)"
        echo "add_executable(\${PROJECT_NAME})"
        echo "# uncomment the following line to use glob to find source files"
        echo "# file(GLOB_RECURSE SOURCES src/*.c)"
        echo "# then change the following line to use glob to find source files"
        echo "# target_sources(\${PROJECT_NAME} PRIVATE \${SOURCES})"
        echo "target_sources(\${PROJECT_NAME} PRIVATE src/${filename}.c)"
        echo "target_compile_features(\${PROJECT_NAME} PRIVATE c_std_23)"
        #echo "target_link_libraries(\${PROJECT_NAME} )"
    } > "${cfilename}"
}

# make a makefile
function create_makefile() {
    filename="${1}"
    {
        echo "${filename}: ${filename}.o"
        echo ""
        printf '%s\n'"\tgcc ${filename}.o -o ${filename}"
        echo ""
        echo "${filename}.o: ${filename}.c"
        echo ""
        printf '%s\n'"\tgcc -Wall -std=c17 -c ${filename}.c -o ${filename}.o"
        echo ""
        printf "run:\n"
        printf '%s\n'"\t./${filename}"
        echo ""
        printf "\n.PHONY: clean\n"
        printf "clean:\n"
        printf '%s\n'"\trm -f ${filename} *.o"
    } >> Makefile
}

# creating a h file
#
function create_header_file() {
  filename="${1%*.}"
  header="__${filename^^}__"
echo "

#ifndef ${header}
#define ${header}
#

#endif  /* ${header} */

" > "${filename}.h"
}

# creating a c file
function create_file() {
    filename="${1}"
    filext="${filename#*.}"

# muted rust file creation
    # create a rust file
    #rust_file="${filename}.rs"
    #echo "
    #![allow(dead_code, unused)]

#fn main() {
#  println!("Hello, World!");
#}" > "${rust_file}"
    # make a file with c extension
    [[ "${filext}" == "${filename}" ]] && filename="${filename}.c"

    if [[ -e "${filename}" ]]; then
        echo "${filename}" "exist."
        printf "Do you want to overwrite it? [y|n]: "
        while read -r ans; do
            case "${ans,,}" in
                y)
                echo "/* ${filename} */" > "${filename}"
                echo "${FILE}" >> "${filename}"
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
        echo "/* ${filename} */" > "${filename}"
        echo "${FILE}" >> "${filename}"
    fi
}

if [[ "${#}" != 2 ]]; then
    usage
fi

optstring="a:c:d:g:r:h"

while getopts "${optstring}" opt; do
    case "${opt}" in
        a)
            filename="${OPTARG,,}"
            create_header_file "${filename}" # header file creation
            create_file "${filename}"
            ./"${0}" -r "${filename}"
        ;;
        c)
            filename="${OPTARG,,}"
            create_cmake "${filename}"
            create_file "${filename%.*}.c"
            mkdir -p src
            mv "${filename%.*}.c" src/
            cmake -S . -B build && cmake --build build
            ./build/"${filename%.*}"
            rm -rf build
        ;;
        d)
        filename="${OPTARG,,}"
        for file in *.*; do
            if [[ "${filename}" = "${file}" ]]; then
                echo "Do you want to delete ${file}? [y|n]: "
                while read -r ans; do
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
        ;;
        r)
            filename="${OPTARG}"
            file_o_run="${filename%.*}";
            while read -r -e -p "Compile and Run either with 'make' or 'cmake' [m/c]: " line; do
                case "${line,,}" in
                    m)
                        gcc -Wall -std=c17  -o "${file_o_run}" "${filename}"
                        chmod +x "${file_o_run}"
                        # make a makefile
                        create_makefile "${file_o_run}"
                        # run make command
                        make
                        ./"${file_o_run}"
                        echo
                        make clean # run make clean
                        #rm "${file_o_run}"
                       exit 0;;
                    c) cmake -S . -B build && cmake --build build
                       ./build/"${file_o_run}"
                       rm -rf build
                       exit 0;;
                    *) printf "Can only use 'm' for make, and 'c' for cmake.\n"
                       continue
                       ;;
                esac
            done
        ;;
        *.*);;
    esac
done
