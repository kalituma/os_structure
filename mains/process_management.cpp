
#include <iostream>
#include <unistd.h>
#include <err.h>

namespace process{
    static void child(){
        std::cout << "I'm child! my pid is " << getpid() << "." << std::endl;
        exit(EXIT_SUCCESS);
    }

    static void parent(pid_t pid_c){
        std::cout << "I'm parent! my pid is " << getpid() << " and the pid of my child is " << pid_c << "." << std::endl;
        exit(EXIT_SUCCESS);
    }
}


int main(){
    pid_t ret;
    ret = fork();
    if (ret == -1)
        err(EXIT_FAILURE, "fork() failed.");
    if (ret == 0){
        process::child();
    }else{
        process::parent(ret);
    }
    err(EXIT_FAILURE, "shouldn't reach here.");
}