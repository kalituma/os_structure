#include <iostream>
#include <unistd.h>

// methods used for checking the 'execution in usr and system space' in linux system
// use them with strace_helloworld.sh

namespace system_usr_space{
    void hello_world(){
        std::cout << "Hello, World!" << std::endl;
    };

    void call_inf_loop(){
        for(;;)
            //;
            getppid();
    };
}

int main() {
//    call_inf_loop();
    system_usr_space::hello_world();
    return 0;
}
