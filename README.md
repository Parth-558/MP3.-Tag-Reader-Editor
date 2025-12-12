MP3 Tag Reader & Editor (ID3v1) – README
📌 Overview

This project is a C-based MP3 Tag Reader & Editor designed to extract and modify ID3v1 metadata stored in MP3 files. The application reads the last 128 bytes of the audio file, interprets fields such as Title, Artist, Album, Year, and Comment, and provides a CLI interface to display or update them.
It demonstrates strong fundamentals in file handling, binary parsing, structures, and pointer logic—core skills for embedded and systems programming.

✨ Features

Read ID3v1 metadata from any MP3 file

Display Title, Artist, Album, Year, Comment, and Genre

Edit specific fields without corrupting audio data

Validate ID3v1 tag using the "TAG" header

Clean CLI interface for user-friendly operation

Lightweight and fast — zero external dependencies

📂 Project Structure
├── main.c          # CLI controller  
├── reader.c        # Handles reading ID3v1 tag  
├── editor.c        # Handles editing MP3 metadata  
├── id3.h           # Structure definition for ID3v1  
├── reader.h        # Read function prototypes  
├── editor.h        # Edit function prototypes  
└── Makefile        # Build automation

🚀 How It Works

User provides an MP3 file as input

Program reads the last 128 bytes using fseek()

Metadata fields are mapped into a structured id3v1 layout

User can display or update tag values

Updated data is written back safely without modifying audio bytes

🧠 Skills Demonstrated

C Programming

File Handling & Binary Processing

Hexdump Interpretation

Struct Design & Offset Mapping

CLI Development

Debugging & Error Handling

Problem Solving

🛠️ Build & Run
Compile
make

Run the Reader
./mp3reader song.mp3

Run the Editor
./mp3editor song.mp3

📌Help Menu

<img width="428" height="270" alt="mp31" src="https://github.com/user-attachments/assets/8b6a0cad-ad57-4cea-9133-bd8a3b5ba079" />



📌 Sample Output

<img width="524" height="365" alt="Screenshot 2025-12-12 145853" src="https://github.com/user-attachments/assets/0526af63-092f-4ba4-ad75-31a990437fb2" />




🌱 Future Enhancements

Support for ID3v2 tags

Batch tag editing

GUI version

Album art extraction

Unicode support

👤 Author

Parth Pawar
Embedded Systems Developer | C Programmer
