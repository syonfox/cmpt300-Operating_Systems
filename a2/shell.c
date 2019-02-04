// Shell starter file
// You may make any changes to any part of this file.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
//#include <errno.h>

#define COMMAND_LENGTH 1024
#define NUM_TOKENS (COMMAND_LENGTH / 2 + 1)
#define DIR_LENGTH 256
#define HISTORY_LENGTH 10

static volatile sig_atomic_t keep_running = 1;
static volatile sig_atomic_t show_help = 0;
static void sig_handler(int _)
{
    (void)_;
    //keep_running = 0;
    show_help = 1;
}


/**
 * Command Input and Processing
 */

/*
 * Tokenize the string in 'buff' into 'tokens'.
 * buff: Character array containing string to tokenize.
 *       Will be modified: all whitespace replaced with '\0'
 * tokens: array of pointers of size at least COMMAND_LENGTH/2 + 1.
 *       Will be modified so tokens[i] points to the i'th token
 *       in the string buff. All returned tokens will be non-empty.
 *       NOTE: pointers in tokens[] will all point into buff!
 *       Ends with a null pointer.
 * returns: number of tokens.
 */
int tokenize_command(char *buff, char *tokens[])
{
    int token_count = 0;
    _Bool in_token = false;
    int num_chars = strnlen(buff, COMMAND_LENGTH);
    for (int i = 0; i < num_chars; i++) {
        switch (buff[i]) {
            // Handle token delimiters (ends):
            case ' ':
            case '\t':
            case '\n':
                buff[i] = '\0';
                in_token = false;
                break;

                // Handle other characters (may be start)
            default:
                if (!in_token) {
                    tokens[token_count] = &buff[i];
                    token_count++;
                    in_token = true;
                }
        }
    }
    tokens[token_count] = NULL;
    return token_count;
}

/**
 * Read a command from the keyboard into the buffer 'buff' and tokenize it
 * such that 'tokens[i]' points into 'buff' to the i'th token in the command.
 * buff: Buffer allocated by the calling code. Must be at least
 *       COMMAND_LENGTH bytes long.
 * tokens[]: Array of character pointers which point into 'buff'. Must be at
 *       least NUM_TOKENS long. Will strip out up to one final '&' token.
 *       tokens will be NULL terminated (a NULL pointer indicates end of tokens).
 * in_background: pointer to a boolean variable. Set to true if user entered
 *       an & as their last token; otherwise set to false.
 */
void read_command(char *buff, char *tokens[], _Bool *in_background)
{
    *in_background = false;

    // Read input
    int length = read(STDIN_FILENO, buff, COMMAND_LENGTH-1);

    if ( (length < 0) ){
        perror("Unable to read command from keyboard. Terminating.\n");
        exit(-1);
    }

    // Null terminate and strip \n.
    buff[length] = '\0';
    if (buff[strlen(buff) - 1] == '\n') {
        buff[strlen(buff) - 1] = '\0';
    }

    // Tokenize (saving original command string)
    int token_count = tokenize_command(buff, tokens);
    if (token_count == 0) {
        return;
    }

    // Extract if running in background:
    if (token_count > 0 && strcmp(tokens[token_count - 1], "&") == 0) {
        *in_background = true;
        tokens[token_count - 1] = 0;
    }
}

void read_history(char *buff, char *tokens[], _Bool *in_background)
{
    *in_background = false;

    // Tokenize (saving original command string)
    int token_count = tokenize_command(buff, tokens);
    if (token_count == 0) {
        return;
    }

    // Extract if running in background:
    if (token_count > 0 && strcmp(tokens[token_count - 1], "&") == 0) {
        *in_background = true;
        tokens[token_count - 1] = 0;
    }
}

void print(char * s){
    write(STDOUT_FILENO, s, strlen(s));
}
/**
 * Main and Execute Commands
 */
int main(int argc, char* argv[])
{

    signal(SIGINT, sig_handler);

    char input_buffer[COMMAND_LENGTH];
    char *tokens[NUM_TOKENS];

    char history_buffers[HISTORY_LENGTH][COMMAND_LENGTH];
    int hist_end = 0;
    int hist_len = 0;

    //setenv('TERM', 'xterm', 0);
    //  putenv("TERM=xterm");
    char cwd[DIR_LENGTH];
    char prompt[DIR_LENGTH+32];
    while (keep_running) {

        // Get command
        // Use write because we need to use read() to work with
        // signals, and read() is incompatible with printf().
        getcwd(cwd, DIR_LENGTH);
        strcpy(prompt,cwd);
        strcat(prompt, "$ ");
        write(STDOUT_FILENO, prompt, strlen(prompt));
        _Bool in_background = false;
        read_command(input_buffer, tokens, &in_background);

        // DEBUG: Dump out arguments:
        for (int i = 0; tokens[i] != NULL; i++) {
            write(STDOUT_FILENO, "   Token: ", strlen("   Token: "));
            write(STDOUT_FILENO, tokens[i], strlen(tokens[i]));
            write(STDOUT_FILENO, "\n", strlen("\n"));
        }
        if (in_background) {
            write(STDOUT_FILENO, "Run in background.",
                    strlen("Run in background."));
        }
        //write(STDOUT_FILENO, "CDs", strlen("CDs"));
        //write(STDOUT_FILENO, "CDs", strlen("CDs"));

//        hist_end++;
//        if(hist_end == HISTORY_LENGTH) hist_end = 0;
//        hist_len++;
//        strcpy(history_buffers[hist_end], input_buffer);

        if(show_help == 1) {
            write(STDOUT_FILENO,
                        "Internal Commands: \n pwd - prints working directory\n cd - change directory\n exit - quit this shell \n help - help on a program, usage: help {program}\n",
                        strlen("Internal Commands: \n pwd - prints working directory\n cd - change directory\n exit - quit this shell \n help - help on a program, usage: help {program}\n")
                        );
            show_help = 0;
            continue;
        }

        if(tokens[0] != NULL) {
            if(tokens[0][0] == '!') {
                //write(STDOUT_FILENO,"Bang", strlen("Bang"));
                int cmd;
                if(tokens[0][1] == '!') {
                    //write(STDOUT_FILENO,"Bang", strlen("Bang"));
                   cmd = hist_end;
                }
                else {
                    //char* num = tokens[0]+1;
                    //write(STDOUT_FILENO,num, strlen(num));
                    cmd = atoi(tokens[0]+1);
                    cmd++;
                    cmd =  cmd % HISTORY_LENGTH;
                }
                strcpy(input_buffer, history_buffers[cmd]);
                read_history(input_buffer, tokens, &in_background);
                write(STDOUT_FILENO, input_buffer, strlen(input_buffer));


            }
        }

        hist_end++;
        if(hist_end == HISTORY_LENGTH) hist_end = 0;
        hist_len++;
        strcpy(history_buffers[hist_end], input_buffer);

        if(tokens[0] == NULL){
            continue;
        }
        else if(strcmp(tokens[0], "history") == 0) {
            int hst = hist_len ;
            char snum[32];
            for(int i = 0; i < HISTORY_LENGTH; i++) {

                sprintf(snum, "%d", hst);
                write(STDOUT_FILENO, snum, strlen(snum));
                write(STDOUT_FILENO, "   ", strlen("   "));
                write(STDOUT_FILENO, history_buffers[(hist_end-i+1)%HISTORY_LENGTH], strlen(history_buffers[(hist_end-i+1)%HISTORY_LENGTH]));
                write(STDOUT_FILENO, "\n", strlen("\n"));
                hst--;
                if(hst<0) break;
            }
        }
        else if(strcmp(tokens[0], "cd") == 0) {
            if(tokens[1] != NULL){
                chdir(tokens[1]);
            }
        }
        else if(strcmp(tokens[0], "pwd") == 0) {
            write(STDOUT_FILENO, cwd, strlen(cwd));
            write(STDOUT_FILENO, "\n", strlen("\n"));
        }
        else if(strcmp(tokens[0], "exit") == 0) {
            if(tokens[1] != NULL){
                write(STDOUT_FILENO,
                        "Aborting Exit: Improper Usage, see 'help exit'\n",
                        strlen("Aborting Exit: Improper Usage, see 'help exit'\n")
                        );
            }
            else {
                write(STDOUT_FILENO, "Exiting.\n", strlen("Exiting.\n"));
                return 0;
            }
        }
        else if(strcmp(tokens[0], "help") == 0) {
            if(tokens[1] != NULL){
                if(tokens[3] != NULL) {
                    write(STDOUT_FILENO, "Error Unexpected Token 3", strlen("Error Unexpected Token 3"));
                }
                else if(strcmp(tokens[1], "cd") == 0) {
                    write(STDOUT_FILENO,
                          "'cd' is a builtin command for changing the current working directory.\n",
                          strlen("'cd' is a builtin command for changing the current working directory.\n"));
                }
                else if(strcmp(tokens[1], "pwd") == 0) {
                    write(STDOUT_FILENO,
                          "'pwd' is a builtin command for printing the current working directory.\n",
                          strlen("'pwd' is a builtin command for printing the current working directory.\n"));
                }
                else if(strcmp(tokens[1], "exit") == 0) {
                    write(STDOUT_FILENO,
                          "'exit' is a builtin command for quiting this shell no paramaters are accepted.\n",
                          strlen("'exit' is a builtin command for quiting this shell no paramaters are accepted.\n"));
                } else {
                    write(STDOUT_FILENO,"'",strlen("'"));
                    write(STDOUT_FILENO,tokens[1],strlen(tokens[1]));
                    write(STDOUT_FILENO,
                            "' is an external command or application\n",
                            strlen("' is an external command or application\n"));
                }
            }
            else {
                write(STDOUT_FILENO,
                        "Internal Commands: \n pwd - prints working directory\n cd - change directory\n exit - quit this shell \n help - help on a program, usage: help {program}\n",
                        strlen("Internal Commands: \n pwd - prints working directory\n cd - change directory\n exit - quit this shell \n help - help on a program, usage: help {program}\n")
                        );
            }
        }
        else{//try and run it externally

            /**
             * Steps For Basic Shell:
             * 1. Fork a child process
             * 2. Child process invokes execvp() using results in token array.
             * 3. If in_background is false, parent waits for
             *    child to finish. Otherwise, parent loops back to
             *    read_command() again immediately.
             */


            pid_t pid = fork();
            if (pid == -1) {
                //print("Failed to fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                execvp(tokens[0], tokens);
                write(STDOUT_FILENO, "Command not found\n", strlen("Command not found\n"));
                return 0;
            } else {
                if (!in_background) {
                    //write(STDOUT_FILENO, "test", strlen("test"));
                    waitpid(0, NULL, NULL);
                }

                // Cleanup any previously exited background child processes
                // (The zombies)
                while (waitpid(-1, NULL, WNOHANG) > 0); // do nothing.
            }
        }
    }

    if (keep_running) {
       return 0;
    }
    write(STDOUT_FILENO, "Stopped by signal 'SIGINT'\n", strlen("Stopped by signal 'SIGINT'\n"));

    return EXIT_SUCCESS;
}
