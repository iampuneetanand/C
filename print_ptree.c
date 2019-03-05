#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ptree.h"



int main(int argc, char **argv) {
    // TODO: Update error checking and add support for the optional -d flag
    // printf("Usage:\n\tptree [-d N] PID\n");

    // NOTE: This only works if no -d option is provided and does not
    // error check the provided argument or generate_ptree. Fix this!
    if (argc < 3){ //too few arguments
    	fprintf(stderr, "%s", "Too few arguments provided\n");
    	return 1;
    }
    if (argc > 3){ //too many arguments
    	fprintf(stderr, "%s", "Too many arguments\n");
    	return 1;
    }
    if (argc == 2){ //if just one argument, is a tree, print whole thing

   		struct TreeNode *root = NULL;
    	generate_ptree(&root, strtol(argv[1], NULL, 10));
    	print_ptree(root, 0);
    	return 0;
	}

	if (argc == 3){ // if 2 arguments 
		if ((strncmp(argv[2], "-d", 2) != 0)){ //if second is not -d, fail
			fprintf(stderr, "%s", "Incorrect second argument\n");
			return 1;
		}
		else{ //if it is print up until the tree_depth provided
			int tree_depth;
			tree_depth = strtol(argv[2], NULL, 10);

			struct TreeNode *root = NULL;
    		generate_ptree(&root, strtol(argv[1], NULL, 10));
    		print_ptree(root, tree_depth);
    		return 0;

			}
		}
	}





