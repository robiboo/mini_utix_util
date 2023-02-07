#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int my_sed(char *buffer, char *find_term, char *replace_term){
    
    
    //replaces the newline at the end of the buffer string with a null character
    char new_buffer[256];
    strcpy(new_buffer, buffer);
    new_buffer[strlen(new_buffer) - 1] = '\0';

    char *ptr_str = strstr(new_buffer, find_term );

    int x = 0;
    while(x != 2){
        if (ptr_str == NULL){
            printf("Cannot find word\n");
            exit(1);
        }
        // if word exist at the very beginning
        if (strlen(new_buffer) == strlen(ptr_str)){
            int len_find = strlen(find_term);
            char *is_space = ptr_str + len_find;

            // printf(">>%c<<<<space?\n", is_space[0]);
         
            if ( ' ' == is_space[0]){
                char temp[256];

                strcpy(temp, is_space);

                int chr = 0;
                for(chr = 0; chr < strlen(replace_term); chr++){
                    ptr_str[chr] = replace_term[chr];
                }
                ptr_str[strlen(replace_term)] = '\0';

                char temp2[256];
                strcpy(temp2, ptr_str);
                strcat(temp2, temp);
                printf("%s\n", temp2);
                break;
            }
        }
        else{
            // if the word is in middle 
            // strcpy the first part the terminate
            // strcat the replace term
            // strcpy the end the strcat
            char *n = ptr_str - 1;
            printf(">>%c<<\n", n[0]);
        }

        // printf("%s\n", ptr_str);
        ptr_str = strstr(ptr_str +1, find_term);
        
        x++;
    }



    // printf("%s\n", new_ptr);


    // printf("%lu\n", strlen(new_buffer));
    // printf("%lu\n", strlen(ptr_str));
    // printf("%lu\n", strlen(find_term));


    
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