#include <stdio.h>
#include <stdlib.h>


// TODO: Implement a helper named check_permissions that matches the prototype below.
int check_permissions(char *, char *);

int check_permissions(char * char_1, char * char_2){
	int index_val = 1; //index holder, start at 1 because first is directory
	int return_val = 1; //starting the return value as false
	while (index_val < 10){
		if (char_1[index_val] == 'r'){
			if (char_1[index_val] != char_2[index_val]){
				index_val= index_val + 1; 
			}
			else{
				index_val = index_val + 1;
				return_val = 0;
			}
		}
		if (char_1[index_val] == 'w'){
			if (char_1[index_val] != char_2[index_val]){
				index_val= index_val + 1;
			}
			else{
				index_val = index_val + 1;
				return_val = 0;
			}
		}
		if (char_1[index_val] == 'x'){
			if (char_1[index_val] != char_2[index_val]){
				index_val= index_val + 1;
			}
			else{
				index_val = index_val + 1;
				return_val = 0;
			}
		}
		else{
			index_val = index_val + 1;
		}
	}

	return return_val;
}


int main(int argc, char** argv) {


	int total_files = 0;

	int file_size;

	char file_permissions[11];

	int long sizer_1 = strtol(argv[1], NULL, 10);

	int sizer_final  = (int) sizer_1;

	








    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE:\n\tcount_large size [permissions]\n");
        return 1;
    }


    scanf("%*s %*d\n");
	int eof = scanf("%10s %*d %*s %*s %d %*s %*s %*s %*s", file_permissions, &file_size);
    if (argc == 2){
    	while (eof != EOF){
			
    		if (file_permissions[0] != 'd'){
    			if (file_size > sizer_final){
    				total_files = total_files + 1;
    			}
    		
	

    		}
		eof = scanf("%10s %*d %*s %*s %d %*s %*s %*s %*s", file_permissions, &file_size);

    	}
    	

    }
    if (argc == 3){
    	while (eof != EOF){
			
    		if (file_permissions[0] != 'd'){
    			if (file_size > sizer_final){
    				int permission_num;
    				permission_num = check_permissions(file_permissions, argv[2]);
    				if (permission_num == 0){
    					total_files = total_files + 1;

    				}
				
    			}
			 	
    		}
		
    		eof = scanf("%10s %*d %*s %*s %d %*s %*s %*s %*s", file_permissions, &file_size);

    	}

    }

    // TODO: Process command line arguments.

    // TODO Call check permissions and then print the returned value.

    printf("%d\n", total_files);
}
