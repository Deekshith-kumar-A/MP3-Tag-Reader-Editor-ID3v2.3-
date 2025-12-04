This version includes:

✔ Better structure

✔ Professional badges

✔ Clear descriptions

✔ Table of contents

✔ Screenshots/ASCII UI preview section

✔ Contribution guidelines

✔ Future enhancements


MP3 Tag Reader & Editor (ID3v2.3)

A clean and efficient command-line utility written in ANSI C for parsing and editing MP3 metadata stored in ID3v2.3 tags.
This project demonstrates binary parsing, memory handling, safe file operations, and modular C design — ideal for learning low-level file structure manipulation.

📑 Table of Contents

1. Overview

2. Features

3. Project Structure

4. Build Instructions

5. Usage

6. Example Output

7. Technical Concepts

8. Future Enhancements

📌 Overview

MP3 files store metadata such as Title, Artist, Album, and Year in structured ID3v2.3 frames.
This project enables you to:

  1. View complete metadata

  2. Modify individual frames

  3. Analyze ID3 header structure

  4. Understand MP3 internals at a binary level

  5. The program safely updates tags using temporary file techniques to avoid corruption — ensuring reliable editing.

✨ Features

Read & parse ID3v2.3 tag header

Display major metadata frames:

  1. TIT2 – Title

  2. TPE1 – Artist

  3. TALB – Album

  4. TYER – Year

  5. TCON – Genre

  6. COMM – Comment

✔Edit/overwrite a selected tag frame

✔Handles frame header, size, and encoding

✔No external libraries required

✔Clean modular design (easy to extend)


📁 Project Structure

MP3-Tag-Reader/

│

├── main.c          # Program entry

├── view.c          # View tag functionality

├── edit.c          # Edit tag functionality

├── utils.c         # Helper functions

├── header.h        # Common declarations

├── Makefile        # Build automation (optional)

└── README.md       # Documentation

🛠️ Build Instructions
Using GCC:

gcc -o mp3_tag_reader main.c view.c edit.c utils.c

Using Makefile:

 make

▶️ Usage

✔View all metadata:

 ./mp3_tag_reader -v <filename.mp3>


✔Edit a specific tag:

 ./mp3_tag_reader -e -t TIT2 -d "New Title" <filename.mp3>

✔Show help:

 ./mp3_tag_reader --help

🖥️ Example Output:

***** MP3-Tag-Reader-Editor-ID3v2.3 *****

Title   :  Karabuu

Artist  :  Chandan Shetty

Album   :  Pogaru

Year    :  2021

Genre   :  Indian Film Pop

Comment :  Updated comment

🧠 Technical Concepts Used

This project showcases important systems-level programming concepts:

🔹 Binary file parsing

1. Reading raw bytes using fread()

2. Understanding ID3v2.3 frame layout

Handling sync-safe integers

🔹 Memory & buffer handling

🔹Dynamic buffers

🔹Safe string operations

🔹 Modular C Programming

🔹Separation into .c and .h files

🔹Organized build using Makefile

🔹 Safe file modifications

🔹Write changes to a temporary file

🔹Replace original only after success

🚀 Future Enhancements

These features can make the tool more powerful:

1. Support for ID3v2.4 tags

2. Add/remove frames dynamically

3. GUI version (Tk, GTK, or HTML-based)

4. Batch processing of multiple MP3 files

5. Genre list auto-detection

6. Support for album art (APIC frame)

If you want, I can implement any of these.


👤 Author

Deekshith Kumar A

🔗 GitHub: Deekshith-kumar-A (https://github.com/Deekshith-kumar-A)
