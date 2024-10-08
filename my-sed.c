#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int my_sed(char *buffer, char *find_term, char *replace_term){
    //this function replaces the find_term with the replace_term
    
    
    char new_buffer[256];
    strcpy(new_buffer, buffer);

    //replaces the newline at the end of the buffer string with a null character
    if ( new_buffer[strlen(new_buffer) - 1] == '\n'){
        new_buffer[strlen(new_buffer) - 1] = '\0';
    }
    
    char *ptr_str = strstr(new_buffer, find_term );

    //loops through each instance of the find_word; check if valid then replace
    for(;;){
        if (ptr_str == NULL){
            printf("%s\n", new_buffer);
            break;
        }

        if (strlen(new_buffer) == strlen(ptr_str)){
            char *is_space = ptr_str + strlen(find_term);

            //checks if the word is at the very beginning or the only word in the line
            if ( ' ' == is_space[0] || '\0' == is_space[0]){
                char end_substr[256];

                strcpy(end_substr, is_space);

                int chr = 0;

                //replaces each character
                for(chr = 0; chr < strlen(replace_term); chr++){
                    ptr_str[chr] = replace_term[chr];
                }
                ptr_str[strlen(replace_term)] = '\0';

                char new_str[256];
                strcpy(new_str, ptr_str);
                strcat(new_str, end_substr);
                printf("%s\n", new_str);
                break;
            }
        }
        else{
            char *n = ptr_str - 1;
            char *is_space = ptr_str + strlen(find_term);

            //checks if the subtring begins with the find_term
            if(n[0] == ' '){

                //if the word is at the end of the line
                if(is_space[0] == '\0'){
                    int chr = 0;

                    //replaces each character
                    for(chr = 0; chr < strlen(replace_term); chr++){
                        ptr_str[chr] = replace_term[chr];
                    }
                    ptr_str[strlen(replace_term)] = '\0';
                    printf("%s\n", new_buffer);
                    break;
                }

                //if the word is in the middle of the line; ends with a space character 
                if(is_space[0] == ' '){
                    int chr = 0;

                    char end_substr[256];
                    strcpy(end_substr, is_space);

                    //replaces each character
                    for(chr = 0; chr < strlen(replace_term); chr++){
                        ptr_str[chr] = replace_term[chr];
                    }
                    ptr_str[strlen(replace_term)] = '\0';

                    char new_str[256];
                    strcpy(new_str, new_buffer);
                    strcat(new_str, end_substr);
                    printf("%s\n", new_str);
                    break;
                }
            }
           
        }
        ptr_str = strstr(ptr_str +1, find_term);
    }    
    return 0;
}


int main(int argc, char *argv[]){
	// check for at least one file in the command line

    char *find_term = argv[1];
    char *replace_term = argv[2];
	if (argc < 3){
		printf("my-sed: find term replace term [file ...]\n");
		exit(1);
	}
    if (argc < 4){
        //ask user for an input from stdin


        char buffer_stdin[256];
        char *stdin_array = NULL;
        printf("Enter Input: \n");
 
        size_t buff_size = 256;
        while((getline(&stdin_array, &buff_size, stdin)) != 1){
            strcpy(buffer_stdin, stdin_array);
            my_sed(buffer_stdin, find_term, replace_term);

        }       
        free(stdin_array);
    
        return 0;
    }

    if (argc > 3){

        int i = 3;

        //loops through each command line argument
        while(i < argc){
            FILE *fp = fopen(argv[i], "r");

            if (fp == NULL){
                printf("my-sed: cannot open file\n");
			    exit(1);
            }

            char str[256];
            while(fgets(str, 256, fp)){
                my_sed(str, find_term, replace_term);
            }
            fclose(fp);
            i++;
    
        }
    }

	return 0;
}