#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>

//function prototypes for view.c

//function to view tags
void view_tag(FILE*);

//function to convert big to little endian
void Big_To_Little_endian(void *,int);

//function to print tag contents
void print_tag(char*, char*);

//function prototypes for edit.c
void edit_tag(char*, char*, char*);

//function to convert endian
void endian_conversion(void*,int);
#endif