#include <stdio.h>
#include <string.h>

void hitme(){
    printf("hitme()\n");
}

void addv(){
    printf("addv()\n");
}

void addn(){
    printf("addn\n");

    FILE *lanlib;
    lanlib = fopen("nounlibrary.txt","w");

    fprintf(lanlib, "This is a noun");



    fclose(lanlib);
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

    } else if (strcmp(argv[1],"addv")==0){
        addv();

    } else if (strcmp(argv[1],"addn")==0){
        addn();

    } else if (strcmp(argv[1],"verb")==0){
        verb();

    } else if (strcmp(argv[1],"noun")==0){
        noun();
    }


    return 0;
}