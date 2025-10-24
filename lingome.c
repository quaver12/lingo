#include <stdio.h>
#include <string.h>

void hitme(){
    printf("hitme()\n");
}

void addv(){
    printf("addv()\n");
}

void addn(char *inputs[], int numOfInputs){

    printf("addn\n");

    FILE *lanlib;
    lanlib = fopen("nounlibrary.txt","a");
    
    fprintf(lanlib, "\n");
    for (int i = 0; i<numOfInputs;i++){
        fprintf(lanlib, inputs[i]);
        fprintf(lanlib, ", ");
    }


    



    fclose(lanlib);
}

void verb(){
    printf("verb()\n");
}

void noun(){
    printf("noun()\n");
}





int main(int argc, char *argv[]){

    //for (int i=0;i<argc;i++){
    //    printf("%c",*argv[i]);
//
  //  }


    if (argc == 1){
        hitme();

    } else if (strcmp(argv[1],"addv")==0){
        addv();

    } else if (strcmp(argv[1],"addn")==0){

        char *input[10];

        // shift argc left 2 so it is only the words to be added to file
        // save that as 'input'
        for (int i = 0; i < argc-2; i++){
            // sets pointers in input array to the location of relevant pointers in argv
            input[i] = argv[i+2];
        }

        //printf("%c",*input[1]);
        addn(input, argc-2);

    } else if (strcmp(argv[1],"verb")==0){
        verb();

    } else if (strcmp(argv[1],"noun")==0){
        noun();
    }


    return 0;
}