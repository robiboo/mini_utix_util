#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int my_sed(char *buffer, char *find_term, char *replace_term){
    // printf("%s",buffer);
    // printf("%s\n",find_term);
    // printf("%s\n",replace_term);
    
    char *new_buffer = NULL;
    strcpy(new_buffer, buffer);
    // int x = 0;
    
    while(strlen(new_buffer) >0 ){
        char *ptr_str = strstr(new_buffer, find_term );
        printf("%s", new_buffer);

        strcpy(new_buffer, ptr_str);
    }
    return 0;
}


int main(int argc, char *argv[]){
	// check for at least one file in the command line
	if (argc < 3){
		printf("my-sed: find term replace term [file ...]\n");
		exit(1);
	}
    if (argc < 4){
        //stdin


        char buffer_stdin[256];
        printf("Enter Input: \n");
        char *find_term = argv[1];
        char *replace_term = argv[2];

        fgets(buffer_stdin, 256, stdin);
        my_sed(buffer_stdin, find_term, replace_term);

        return 0;
    }


	// int i = 3;
	// // for each file in the command line
	// while (i < argc){
	// 	FILE *fp = fopen(argv[i], "r");
	// 	// check if opening file was a success
	// 	if (fp == NULL) {
	// 		printf("my-sed: cannot open file\n");
	// 		exit(1);
	// 	}

	// 	char str[256];
		
	// 	// print contents of the file
	// 	while (fgets(str, 256, fp)){
	// 		printf("%s", str);
	// 	}

	// 	fclose(fp);
	// 	i++;
	// }

	return 0;
}