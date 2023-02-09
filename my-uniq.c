#include<stdlib.h>
#include<string.h>
#include<stdio.h>

// function that removes duplicates in file name specified
int remove_dup(char *name){
    int bytes_read = 1;
    size_t size = 10;
    char *string = NULL;
    char *temp = "";
    FILE *fp;

    fp = fopen(name, "r");
    // check if opening file was a success
    if (fp == NULL) {
        printf("my-uniq: cannot open file\n");
        exit(1);
    }

    string = (char *) malloc(size);
    while(bytes_read != EOF) {
        bytes_read = getline(&string, &size, fp);
        // check if lines are not duplicates
        if (strcmp(temp, string) != 0) {
            // free any previous temp strings
            if (strcmp(temp, "") != 0){
                free(temp);
            }
            temp = strdup(string);
            printf("%s", string);
        } 

    }
    free(temp);
    free(string);
    fclose(fp);

    return 0;
}

int main(int argc, char *argv[]){
	// if there are no files specified, take input from stdin
    FILE *fp;
	if (argc < 2){
        size_t size = 10;
        char *string = NULL;

        // temp file to store input from stdin
        fp = fopen("temp.txt", "w+");
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

        // call function to remove duplicates from temp file
        remove_dup("temp.txt");

        remove("temp.txt");

    // If there are any files specified
	} else {

        int i = 1;
        // for each input file, call remove duplicates function
        while (i < argc){
            remove_dup(argv[i]);
            i++;
        }
    
	}

	return 0;
}