#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to view tags
void view_tag(FILE *fp)
{
    // display header
    printf("\n\n");
    printf("------------------Selected View details------------------\n\n");
    printf("---------------------------------------------\n");
    printf("MP3 Tag Reader and Editor for ID3v2\n");
    printf("---------------------------------------------\n");

    char tag[5];
    int size;

    // skip 10 bytes for header file
    fseek(fp, 10, SEEK_SET);

    // loop for 6 times
    for (int i = 0; i < 6; i++)
    {
        // read tag (4 bytes)
        if (fread(tag, 1, 4, fp) != 4) break;

        // null terminate tag
        tag[4] = '\0';

        // read tag size (4 bytes)
        if (fread(&size, sizeof(int), 1, fp) != 1) break;

        // convert big to little endian (your helper)
        Big_To_Little_endian(&size, sizeof(size));

        // skip 2 bytes of flags (NOT 3)
        fseek(fp, 2, SEEK_CUR);

        if (size <= 0) {
            // nothing to read for this frame
            continue;
        }

        // allocate dynamic memory (correctly)
        char *content = malloc(size + 1); // size bytes + NUL
        if (!content) {
            printf("Memory allocation failed\n");
            return;
        }

        // read full content (size bytes)
        if (fread(content, 1, size, fp) != (size_t)size) {
            free(content);
            break;
        }

        // null-terminate buffer
        content[size] = '\0';

        // print the tag (but skip encoding byte for text frames)
        if (strcmp(tag, "TIT2") == 0 ||strcmp(tag, "TPE1") == 0 ||strcmp(tag, "TALB") == 0 ||strcmp(tag, "TYER") == 0 ||strcmp(tag, "TCON") == 0)
        {
            // text frame — skip encoding byte
            if (size >= 1)
                print_tag(tag, content + 1);
            else
                print_tag(tag, "");
        }
        //
        else if (strcmp(tag, "COMM") == 0)
        {
            // comment frame — skip encoding, language, description
            int idx = 0;
            if (size >= 1) idx++;     // skip encoding
            if (size >= 4) idx += 3;  // skip language

            // skip description until null terminator
            while (idx < size && content[idx] != '\0')
            {
                idx++;
            }

            // skip description null terminator
            if (idx < size && content[idx] == '\0') 
            {
                idx++;
            }
            
            // now idx points to the start of the actual comment text
            if (idx < size)
                print_tag(tag, content + idx);
            else
                print_tag(tag, "");
        }
        else
        {
            
            print_tag(tag, content);
        }

        // free dynamic memory
        free(content);
    }
    printf("--------------------------------------------\n\n");
    printf("-------------Details displayed successfully--------------\n\n");
}
// convert big to little endian
void Big_To_Little_endian(void *p, int size)
{
    char t;
    char *p1 = (char *)p;

    // swap bytes
    for (int i = 0; i < size / 2; i++)
    {
        t = p1[i];
        p1[i] = p1[size - 1 - i];
        p1[size - 1 - i] = t;
    }
}
// print tag contents
void print_tag(char *tag, char *content)
{
    // print based on tag type
    if (strcmp(tag, "TIT2") == 0)
        printf("Title    :   %s\n", content);
    else if (strcmp(tag, "TPE1") == 0)
        printf("Artist   :   %s\n", content);
    else if (strcmp(tag, "TALB") == 0)
        printf("Album    :   %s\n", content);
    else if (strcmp(tag, "TYER") == 0)
        printf("Year     :   %s\n", content);
    else if (strcmp(tag, "TCON") == 0)
        printf("Genre    :   %s\n", content);
    else if (strcmp(tag, "COMM") == 0)
        printf("Comment  :   %s\n", content);
    else
        printf("Comment  :   %s\n", content);
}
