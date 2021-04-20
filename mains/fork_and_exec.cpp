#include <cstdio>
#include <cstdlib>
#include <err.h>
#include "unistd.h"

namespace fork_and_exec{
    static void child(){
        char *args[] = { "/bin/echo", "hello", NULL};
        printf("I'm child! my pid is %d.\n", getpid());
        fflush(stdout);
        execve("/bin/echo", args, NULL);
        err(EXIT_FAILURE, "exec() failed");
    }

    static void parent(pid_t pid_c){
        printf("I'm parent! my pid is %d and the pid of my child is %d. \n", getpid(), pid_c);
        exit(EXIT_SUCCESS);
    }
}

int main(){
    pid_t ret;
    ret = fork();
    if (ret == -1)
        err(EXIT_FAILURE, "fork() failed.");
    if (ret == 0){
        fork_and_exec::child();
    }else{
        fork_and_exec::parent(ret);
    }
    err(EXIT_FAILURE, "shouldn't reach here.");
}
