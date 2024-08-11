#!/bin/bash

# Define the build directory
BUILD_DIR=$(dirname "$0")

# List of files and directories to keep
FILES_AND_DIRS_TO_KEEP=("clean.sh" "dc.sh" "build.sh" "cd")

# Find all files and directories in the build directory
ALL_FILES_AND_DIRS=$(find "$BUILD_DIR" -maxdepth 1)

# Delete files that are not in the keep list
for ITEM in $ALL_FILES_AND_DIRS; do
    ITEM_BASENAME=$(basename "$ITEM")
    if [[ -f "$ITEM" && ! " ${FILES_AND_DIRS_TO_KEEP[@]} " =~ " ${ITEM_BASENAME} " ]]; then
        rm "$ITEM"
    elif [[ -d "$ITEM" && ! " ${FILES_AND_DIRS_TO_KEEP[@]} " =~ " ${ITEM_BASENAME} " && "$ITEM_BASENAME" != "." ]]; then
        rm -rf "$ITEM"
    fi
done