#include "shell.h"
/**
 * shell的入口
 */
void prefix() {
    char cwd[255];
    getcwd(cwd, sizeof(cwd));
    printf("%s$ ", cwd);
}
//cd
int changeDirectory(char* buffer){
    char dir[255];
        strcpy(dir, buffer + 3);
        if(chdir(dir)) {
            printf("%s: No such file or directory\n", buffer + 3);
        }
        log_push(&Log,buffer);
    return 1;
}

int exitCommand(char* buffer){
    free(buffer);
    return 0;
}

int displayFormerCommand(node* n) {
    if(n==NULL)
        return 1;
    displayFormerCommand(n->next);
    printf("%s\n",n->cmd);
    return 1;
}

int findCommandWithPrefix(char* buffer){
        char* search = log_search(&Log, buffer + 1);
        if(search != NULL) {
            log_push(&Log, search);
            execute(search);
        } else {
            printf("No Match\n");
        }
    return 1;
}

int listFiles(){
    log_push(&Log, "ls");
    system("ls");
    return 1;
}

int outerExecute(char* buffer){
    char* argv[255], argc[255], blank[] = " ", * token;
    int i = 0;
    token = strtok(buffer, blank);
    argv[i++] = token;
    strcpy(argc, "./");
    strcat(argc, token);
    while(token != NULL){
        token = strtok(NULL, blank);
        argv[i++] = token;
    }
    int pid = fork();
    if(pid == 0){
        if(execvp(argc, argv) < 0){
            printf("%s: no such command\n", buffer);
        }
        exit(1);
    }else{
        log_push(&Log,buffer);
        wait(pid);
    }
    return 1;
}

int execute(char* buffer) {
    if(buffer[0] == 'c' && buffer[1] == 'd'  && buffer[2] == ' ') {
        return changeDirectory(buffer);
    }else if(strcmp(buffer, "exit" ) == 0) {
        return exitCommand(buffer);
    }else if(buffer[0] == '!' && buffer[1] == '#') {
        return displayFormerCommand(Log.head);
    }else if(buffer[0] == '!' && buffer[1] != '#') {
        return findCommandWithPrefix(buffer);
    }else if(strcmp(buffer, "ls") == 0) {
        return listFiles();
    }else{
        return outerExecute(buffer);
    }
    return 1;
}
