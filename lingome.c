#include <stdio.h>
#include <string.h>

void hitme(){
    printf("hitme()\n");
}

void add(){
    printf("add()\n");
}

void verb(){
    printf("verb()\n");
}

void noun(){
    printf("noun()\n");
}





int main(int argc, char *argv[]){

    if (argc == 1){
        hitme();

    } else if (strcmp(argv[1],"add")==0){
        add();

    } else if (strcmp(argv[1],"verb")==0){
        verb();

    } else if (strcmp(argv[1],"noun")==0){
        noun();
    }


    return 0;
}