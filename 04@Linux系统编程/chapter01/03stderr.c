#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    while(1) {
        perror("Hello World"); 
        sleep(1);
    }
    return 0;
}
