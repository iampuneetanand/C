 #include <stdio.h>
// Add your system includes here.

#include "ptree.h"

// Defining the constants described in ptree.h
const unsigned int MAX_PATH_LENGTH = 1024;

// If TEST is defined (see the Makefile), will look in the tests 
// directory for PIDs, instead of /proc.
#ifdef TEST
    const char *PROC_ROOT = "tests";
#else
    const char *PROC_ROOT = "/proc";
#endif


/*
 * Creates a PTree rooted at the process pid. The root of the tree is
 * placed in root. The function returns 0 if the tree was created 
 * successfully and 1 if the tree could not be created or if at least
 * one PID was encountered that could not be found or was not an 
 * executing process.
 */
int generate_ptree(struct TreeNode **root, pid_t pid) {
    // Here's a trick to generate the name of a file to open. Note 
    // that it uses the PROC_ROOT variable
    char procfile[MAX_PATH_LENGTH + 1];
    if (snprintf(procfile, MAX_PATH_LENGTH + 1, "%s/%d/exe", PROC_ROOT, pid) < 0) {
        fprintf(stderr, "snprintf failed to produce a filename\n");
        return 1;
    }

    printf("%s\n", procfile);

    // Your implementation goes here.
    if (pid == NULL){
        return 1;
    }
    else{
        return 0;
}
}


/*
 * Prints the TreeNodes encountered on a preorder traversal of an PTree
 * to a specified maximum depth. If the maximum depth is 0, then the 
 * entire tree is printed.
 */
void print_ptree(struct TreeNode *root, int max_depth) {
    // Here's a trick for remembering what depth (in the tree) you're at
    // and printing 2 * that many spaces at the beginning of the line.

    static int depth = 0;
    
    if(max_depth ==0){
        printf("%*s", depth * 2, "");
        fprintf(stdout, "%d: %s\n", root->pid, root->name);
        depth = depth + 1;
        if(root-> child_procs == NULL && root -> next_sibling != NULL){
            print_ptree(root->next_sibling, max_depth);
        }
        if (root->child_procs != NULL){
            print_ptree(root->child_procs, max_depth);
        }
    }

    if(max_depth >= depth){
        printf("%*s", depth * 2, "");
        depth = depth + 1;
        fprintf(stdout, "%d: %s\n", root->pid, root->name);
        if(root->child_procs == NULL && root -> next_sibling != NULL){
            print_ptree(root->next_sibling, max_depth);
        }
        else{
            print_ptree(root->child_procs, max_depth);
        }
    }
    
    

}

