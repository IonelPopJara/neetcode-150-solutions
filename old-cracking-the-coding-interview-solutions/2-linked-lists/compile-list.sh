#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

if [ "$#" -eq 0 ]; then
    echo -e "${RED}Usage: ./compile.sh [your_linked_list_program.c]${NC}"
    exit 1
fi

filename="$1"
basename="${filename%.c}"
outname="$basename.out"

gcc $filename "single-linked-list.c" -o "$outname"

echo ""
echo -e "${GREEN}Running $basename:${NC}"
echo ""

./$outname

