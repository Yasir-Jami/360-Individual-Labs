#include <stdio.h>
#include <string.h>

 /* asciiOrBinary
 * Purpose: Takes a filename and determines if the file is in ASCII or Binary format
 * Parameters: char* filename: name of file to be examined
 * Return: int indicating whether the file contents are in ASCII or BINARY
 */
int main(int argc, char* argv[]) {
	FILE *fp;
    	char file_contents[200]; // Holding first 200 bytes of a given file
	char* file = argv[1];
	int buffer_size = 200;	
	int i = 0;

    	// Read binary
    	if ((fp = fopen(file, "rb")) == NULL){
        	printf("Cannot open file.\n");
        	return -1;
	}

    	// Read the first 200 bytes of the provided file
    	fread(file_contents, buffer_size, 1, fp);
    	fclose(fp);	

	// Check each byte - if there is a non-ascii byte, it is binary
	while(i < buffer_size){
		if ((file_contents[i] < 0) || (file_contents[i] > 127)){
			return 1; // Not ASCII - contains non-ASCII bytes
		}
		i++;
	}	
	return 0;
}
