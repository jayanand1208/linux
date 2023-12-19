#!/bin/bash

# Loop through all arguments (filenames)
for file in "$@"; do

  # Check if file exists
  if [ ! -f "$file" ]; then
    echo "File $file does not exist."
    continue
  fi

  # Count the occurrence of each word
  echo "Word count for $file:"
  cat "$file" | tr '[:upper:]' '[:lower:]' | tr -cs '[:alpha:]' '\n' | sort | uniq -c | sort -nr

done

