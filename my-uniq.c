#include<stdlib.h>
#include<string.h>
#include<stdio.h>



int main(int argc, char *argv[]){
	// if there are no files specified, take input from stdin
    FILE *fp;
	if (argc < 2){
		//stdin
        int bytes_read = 1;
        size_t size = 10;
        char *string = NULL;
        char *temp = "";
        // temp file to store input from stdin
        fp = fopen("temp.txt", "r+");

        // check if opening file was a success
        if (fp == NULL) {
            printf("my-uniq: cannot open file\n");
            exit(1);
        }

        printf("Enter Input: \n");

        // write input to temp file
        while (getline(&string, &size, stdin) != 1) {
            fputs(string, fp);
        }
        fclose(fp);

        // go through file line by line and print out non duplicates
        fp = fopen("temp.txt", "r");
        while(bytes_read != EOF) {
            string = (char *) malloc(size);
            bytes_read = getline(&string, &size, fp);
            // duplicate case 
         
            if (strcmp(temp, string) != 0) {
                temp = strdup(string);
                printf("%s", string);
            } 
        }
        fclose(fp);
        remove("temp.txt");

   

    // If there is a file specified
	} else {

        int i = 1;
        while (i < argc){
            int bytes_read = 1;
            size_t size = 10;
            char *string = NULL;
            char *temp = "";
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
                // printf("compare");
                if (strcmp(temp, string) != 0) {
                    temp = strdup(string);
                    printf("%s", string);
                } 
            }
            fclose(fp);
            i++;

        }

    
	}
	return 0;
}