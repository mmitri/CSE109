#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <whichtools.h>

int main(int argc, char** argv) {

    //char path_arr[1000];

    bool a_flag = false;
    int return_value = 0;

    // If we want the -a flag to be position independent, we need to make one 
    // pass through the input arguments to see if it exists. If it does then we
    // set a flag to use later. We can take this opportunity to check for 
    // illegal options as well.
    // We start iterating at 1 because element 0 is the program name, which is
    // not an input argument we will consider.
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) {
            // Set the flag here, we'll use it later
            a_flag = true;
        } else if (argv[i][0] == '-') {
            printf("Illegal option %s\n", argv[i]);
            printf("Usage: %s [-a] args\n", argv[0]);
            // When an illegal flag is passed, we return a 2.
            return 2;
        }
    }

    // This reads the PATH environment variable into a local c variable 
    char* path = getenv("PATH");
    
    // Declare this now, we'll store the token pointer here
    char* token;  
    
    // We'll count how many directories we have in the PATH and store that here
    int dir_count = 0;
    
    // Tokenize the PATH. Remember, this will replace the : with a NULL
    // So "/foo/bar:/foo/baz:/bar/quux" becomes "/foo/bar\0/foo/baz\0/bar/quux"
    // \0 is the NULL character.
    // Therefore it will only work once. If want to go through multiple times,
    // we need another way to do so. We can use the knowledge of how strtok()
    // works to move though the array ourselves.
    token = strtok(path, ":");
    while(token != NULL) {
        dir_count++; 
        token = strtok(NULL, ":");
    }

    // Now that we've tokenized the PATH, we can go through it as many times as
    // we want. We will go through each of the filenames, and concat it with
    // each of the directories in the PATH, hence the nested for loops.

    // We're going to have to manipulate some strings here. We have two variables:
    // 1) a string like this "/foo/bar\0/foo/baz"
    // 2) an array like this ["file1", "file2"]
    // We need to combine them to produce the following strings:
    // "/foo/bar/file1"
    // "/foo/baz/file1"
    // "/foo/bar/file2"
    // "/foo/baz/file2"

    // Go through each of the input arguments again
    for (int i = 1; i < argc; i++) {
        // Create a flag to keep track of whether we have found the current 
        // filename
        bool file_found = false;

        // Skip any flags
        if (argv[i][0] == '-') {
            continue;
        }

        // Point the token to the start of the path
        token = path;
        // Go though each directory. We know how many there are now.
        for (int j = 0; j < dir_count; j++) {
            
            // If we are going to manipulate strings, we need a place to store
            // the intermediate results. We'll allocate 1000 characters here to
            // do that. If our path is longer than 1000 chars the program will
            // segfault.
            char full_path_to_file[1000];

            // Copy the token into the scratch area
            strcpy(full_path_to_file,token);

            // We need to add a '/' to the end, but only if the directory path
            // doesn't already have one.

            // Get the number of characters in the directory path. Subtract 1
            // because the last char is actually the \0, so we want to look at
            // the second to last char.
            int end_of_string = strlen(full_path_to_file) - 1;

            // Get the last char in the string before the \0
            char last_char = full_path_to_file[end_of_string];

            // Check to see if the last char is a '/'. If it is not, add it.
            if (last_char != '/') {
                strcat(full_path_to_file,"/");
            }

            // Now we can cat the filename onto the full directory path.
            strcat(full_path_to_file, argv[i]);

            // Test to see if the file exists by calling the function we
            // created in lib.c
            if (file_exists(full_path_to_file)) {
                
                // We've found the file, set the flag to true.
                file_found = true;
                printf("%s\n", full_path_to_file);

                // If the a_flag hasn't been set, we are done. We don't need to
                // look through any other directories, so we break out of the
                // loop and move on to the next filename.
                if (a_flag == false) {
                    break;
                }
            }

            // Point to the next token by skipping past the '\0' at the end of 
            // the directory
            token += strlen(token) + 1;  
        }
        // If we've gotten down here, it means we've gone through all of the
        // directories in the PATH. If the file_found flag is still false, it
        // means that the file does not exist in any path, and we have to
        // return a 1 from the program.
        if (file_found == false) {
            return_value = 1;
        }
    }

    // Return value will be 0 if we've found all our files. It will be 1 if any
    // of the files we were looking for were not found.
    return return_value;
}
