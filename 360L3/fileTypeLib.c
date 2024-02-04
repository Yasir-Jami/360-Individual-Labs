#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/*
 *fp = fopen(fileloc, "r");
        if (fp == NULL){
                printf("Could not open file.\n");
                continue;
           }
*/


/* fileSystemTests
 * Purpose: Takes a filename as argument, and returns a number indicating its file type
 * regular file=0, directory=1, characterSpecial=2, blockSpecial=3,
 * pipe=4, symbolicLink=5, socket=6
 * Parameters: char* filename: name of file to be examined
 * Return: int indicating the file's type
 */
int fileSystemTests(char* file){
        stat(fileloc, st_mode); // name st_mode of type mode_t



        return 0;
}

/* magicNumberTests
 * Purpose: Takes a filename (which can be assumed to be a regular file) as an argument and determines
 * whether the file is an ELF (relocatable=0, executable=1, shared object=2, core=3)
 * or an executable script (BASH=4, python=5).
 * Parameters: char* filename: name of file to be examined
 * Return: int indicating whether it is an ELF or executable, and what kind it is
 */
int magicNumberTests(char* file){
        return 0;
}

/* asciiOrBinary
 * Purpose: Takes a filename and determines if the file is in ASCII or Binary format
 * Parameters: char* filename: name of file to be examined
 * Return: int indicating whether the file contents are in ASCII or BINARY
 */
int asciiOrBinary(char* file){
        return 0;
}

/* Additional Notes:
 * Filenames can not be used to determine the type (don't look at extension to determine type)
 * Can look at first four bytes of a file to determine if it is an ELF file
 */

