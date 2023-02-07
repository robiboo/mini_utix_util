#include<stdlib.h>
#include<string.h>
#include<stdio.h>


// Open file
// read a line and save it to a temp variable
// print the line
// read the next line and compare it with the next variable 
// if the next line is not the same as the previous then print it and set it as the temp 
// else do nothing and go to the next line




int main(int argc, char *argv[]){
	// if there are no files specified, take input from stdin
    // printf("%d", argc);
	if (argc < 2){
		//stdin
        int bytes_read = 2;
        size_t size = 10;
        char *string = NULL;
        printf("Enter Input: \n");
        while(bytes_read != EOF) {
            string = (char *) malloc(size);
            if(string == NULL) {
                printf("unable to allocate buffer");
                exit(1);
            }
            bytes_read = getline(&string, &size,stdin);

            printf("%s", string);
            // printf("%d", bytes_read);
        }
        
        

        // char buffer_stdin[256];
        // printf("Enter Input: \n");
        // characters = getline(&buffer, &bufsize, stdin);
       
        // printf("you typed: '%s'\n",buffer);
        // printf("%s", buffer_stdin);


    // If there is a file specified
	} else {

        int i = 1;
        while (i < argc){
            int bytes_read = 1;
            size_t size = 10;
            char *string = NULL;
            char *temp = NULL;
            FILE *fp = fopen(argv[i], "r");

            // check if opening file was a success
            if (fp == NULL) {
                printf("my-uniq: cannot open file\n");
                exit(1);
            }

            while(bytes_read != EOF) {
                string = (char *) malloc(size);
                bytes_read = getline(&string, &size, fp);
                // duplicate case 
                printf("compare");
                if (strcmp(temp, string) == 0) {
                    printf("duplicate found");

                } else {
                    temp = strdup(string);
                    printf("%s", temp);
                    printf("%s", string);
                }
            }
            fclose(fp);
            i++;

        }

    
	}





	return 0;
}