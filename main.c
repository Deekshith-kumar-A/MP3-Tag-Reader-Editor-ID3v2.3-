/*
MP3 Tag Reader and Editor for ID3v2
---------------------------------------------
Name: Deekshith Kumar A
Roll No: 25021_344
Course: ECEP
Date: 20th Nov 2025

This project, developed by Deekshith Kumar A, focuses on implementing an MP3 metadata (ID3v2.3) 
reader and editor using the C programming language.

The primary goal is to parse and manipulate metadata such as the Title, Artist, Album, Year, Genre, and Comment
embedded within MP3 files.

ID3 tags play an essential role in organizing and identifying audio files across media players,
music libraries, and streaming platforms. This project demonstrates low-level file handling, binary parsing, and an understanding of multimedia metadata standards.


Objective

1. The objectives of this project are:
2. To study and understand the structure of ID3v2.3 tags used in MP3 files.
3. To develop a tool that can view and edit ID3 metadata.
4. To implement binary file parsing in C using pointers, file streams, and memory allocation.
5. To modify and rewrite metadata frames without affecting the audio content.

Functional Flow

1. View Mode

1. Skip ID3 header
2. Read each frame header
3. Parse frame size and flags
4. Read and decode content
5. Display mapped tag values

2. Edit Mode

1. Locate target frame
2. Replace content with new text
3. Update frame size
4. Rewrite MP3 metadata area
5. Preserve audio data and other frames

Sample Output:

------------------Selected View details------------------

---------------------------------------------
MP3 Tag Reader and Editor for ID3v2
---------------------------------------------
Title   :  Karabuu
Artist  :  Chandan Shetty
Album   :  Pogaru
Year    :  2021
Genre   :  Indian Film Pop
Comment :  Updated comment
---------------------------------------------

-------------Details displayed successfully--------------

*/

#include<stdio.h>
#include<string.h>
#include "header.h"

//main function
void main(int argc,char *argv[])
{
    // file pointer
    FILE *fp;

    //Step 1: check for arguments
    if(argc==3 && strcmp(argv[1],"-v")==0 )
    {
        //open file in read mode
        fp=fopen(argv[2],"rb");

        //validate file pointer
        if(fp==NULL)
        {
            printf("file not present\n");
            return;
        } 
        //call view_tag function
        view_tag(fp);
        fclose(fp); 
    }

    //Step 2: edit tag
    else if(argc==5 && strcmp(argv[1],"-e")==0 )
    {
       edit_tag(argv[2],argv[3],argv[4]);
    }

    //Step 3: help menu
    else if(argc==2)
    {
        printf("---------------HELP MENU----------------\n");
        printf("1. -v -> to view mp3 file contents\n");
        printf("2. -e -> to edit mp3 file contents\n");
        printf("2.1. -t -> to edit song title\n");  
        printf("2.1. -a -> to edit artist name\n");
        printf("2.1. -A -> to edit album name\n");
        printf("2.1. -y -> to edit year\n");
        printf("2.1. -g -> to edit content\n");
        printf("2.1. -c -> to edit comment\n");
        printf("----------------------------------------\n");
    }
    else
    //Step 4: invalid arguments
    {
     printf("------------------------------------------\n");
     printf("INVALID ARGUMENTS\n");
     printf("USAGE :\n");
     printf("* To view please pass like: ./a.out -v sample.mp3\n");
     printf("* To edit please pass like: ./a.out -e sample.mp3 -y 2025\n");
     printf("* To get help pass like: ./a.out --help\n");
     printf("------------------------------------------\n");
    }
}