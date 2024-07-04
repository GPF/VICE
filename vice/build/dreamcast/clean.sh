#!/bin/bash

# Define the build directory
BUILD_DIR=$(dirname "$0")

# List of files to keep
FILES_TO_KEEP=("clean.sh" "dc.sh" "build.sh")

# Find all files in the build directory
ALL_FILES=$(find "$BUILD_DIR" -maxdepth 1 -type f)

# Delete files that are not in the keep list
for FILE in $ALL_FILES; 
do
    FILE_BASENAME=$(basename "$FILE")
    if [[ ! " ${FILES_TO_KEEP[@]} " =~ " ${FILE_BASENAME} " ]]; 
    then
        rm "$FILE"
    fi
done

# Remove directories and their contents
find "$BUILD_DIR" -maxdepth 1 -type d -not -name '.' -not -name '..' -not -path "$BUILD_DIR" | xargs rm -rf

