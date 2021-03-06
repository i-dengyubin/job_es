#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    char buf[1024];
    int cnt = 0;

    fp = fopen("test.txt", "r");
    if(NULL == fp) {
        perror("fopen()"); 
        exit(EXIT_FAILURE);
    }

    while(fgets(buf, sizeof(buf), fp) != NULL) {
        if(buf[strlen(buf)-1] == '\n') 
            cnt++;
    }

    printf("cnt = %d\n", cnt);

    fclose(fp);
    return 0;
}
