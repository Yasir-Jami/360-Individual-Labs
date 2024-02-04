#include <stdio.h>
#include <sys/stat.h>

/* fileSystemTests
 * Purpose: Takes a filename as argument, and returns a number indicating its file type
 * regular file=0, directory=1, characterSpecial=2, blockSpecial=3,
 * pipe=4, symbolicLink=5, socket=6
 * Parameters: char* filename: name of file to be examined
 * Return: int indicating the file's type
 */
int main(void){
	char filename[50] = "./object.o";
	//FILE fp* = NULL;
	struct stat file_stat;

	//fopen(file.c);
	

	if (S_IFMT == S_IFREG){
		printf("Regular file.");
	}

	printf("IFMT: %d\nIFREG: %d\nIFCHR: %d\nIFDIR: %d\nIFIFO: %d\nIFLNK: %d\nIFSOCK: %d\n", S_IFMT, S_IFREG, S_IFCHR, S_IFDIR, S_IFIFO, S_IFLNK, S_IFSOCK);

	 switch (file_stat.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
	 


/*	
	printf("Current mode: %ls\n", st_mode);
	stat(file, st_mode); // name st_mode of type mode_t	

	printf("Mode after: %ls\n", st_mode);
*/	

	printf("File mode: %u\n", file_stat.st_mode);
	
	return 0;
}
