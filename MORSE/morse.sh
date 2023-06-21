#!/bin/bash
###########################
# Author: <Autorname>
# Created: <creation date>
# Modified: <last modification date>
# Description: <short description>
###########################
VERSION=0.0.2
MODIFICATIONDATE="30.10.2022"
AUTHOR="Yannick Englert, Adrian Maurer, Yannick Lattion"

DESCRIPTION="Script for Morse Assembly RaspberryPI"

## Help ausgabe
usage() {
  cat<<EOF
  USAGE
    $0 [-h]
    $0 [-w]
  OPTIONS
    -h  Show this message
    -w  Input for the assembly Morse Code 
  EXAMPLES
    $0 -h
    $0 -w 
--
  IMPLEMENTATION
    version      $0 ${VERSION} (${MODIFICATIONDATE})
    author       ${AUTHOR}
    description  ${DESCRIPTION}
EOF
}

validate() {
  if [ -z "$STRING" ]; then
      echo "Nothing provided"
      usage
      exit 1
  else
    if ! [[ "$STRING" =~ [^a-zA-Z\ ] ]]; then
      STRING=$(echo "$STRING" | tr '[:lower:]' '[:upper:]')
      sed -i'.bak' -e '/MainLoop:/,$d' source/project.s
      mv source/project.s source/project.s.tmp
      tr -d $'\r' < source/project.s.tmp > source/project.s
      split
    else
      echo "Only letters allowed!"
      exit 1
    fi
  fi
}

split() {
  echo "MainLoop:" >> source/project.s
  for (( i=0; i<${#STRING}; i++ )); do
    if ! [[ "${STRING:$i:1}" =~ [^\ ] ]]; then
      echo "        bl space" >> source/project.s
    else
      echo "        bl ${STRING:$i:1}" >> source/project.s
   fi
  done
  echo "   b MainLoop" >> source/project.s
}

## Get options
while getopts "hw:" OPTION
do
  case "$OPTION" in
    h)
      usage
      exit 1
      ;;
    w) STRING=${OPTARG}  ;;
  esac
done
validate
rm source/*bak source/*tmp
make clean
make all
