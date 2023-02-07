#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	// check for at least one file in the command line
	if (argc < 2){
		printf("NOT ENOUGH ARGS\n");
		exit(1);
	}

	int i = 1;
	// for each file in the command line
	while (i < argc){
		FILE *fp = fopen(argv[i], "r");
		// check if opening file was a success
		if (fp == NULL) {
			printf("my-cat: cannot open file\n");
			exit(1);
		}

		char str[256];
		
		// print contents of the file
		while (fgets(str, 256, fp)){
			printf("%s", str);
		}

		fclose(fp);
		i++;
	}

	return 0;
}