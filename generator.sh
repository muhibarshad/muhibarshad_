#!/bin/bash

# Define the path to the folder containing the images
folder="static/images/quotes"

# Define the output file
output="_notes/muhibarshad/Dua's/Quotes.md"

# Make sure the directory exists
if [ ! -d "$folder" ]; then
  echo "Directory $folder does not exist."
  exit 1
fi

# Check if the output file already exists, and create it if not
if [ ! -f "$output" ]; then
  touch "$output"
fi

# Find all jpg images in the folder and append them to the Duas.md file
find "$folder" -type f -iname "*.jpg" | while read -r image; do
  echo "![]($image)" >> "$output"
done

echo "All images have been added to Duas.md."