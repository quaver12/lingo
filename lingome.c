#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countFileLines(char *fileName){
    
    FILE *readInFile;
    readInFile = fopen(fileName,"r");

    int count = 0, lines = 0, character;

    while (character != EOF){
        character = fgetc(readInFile);
        if (character == '\n'){
            lines++;
        }
        count++;
    }

    fclose(readInFile);

    return lines;
}

void hitme(){
    printf("hitme()\n");
}

void addv(){
    printf("addv()\n");
}

void addn(char *inputs[], int numOfInputs){
    
    // Adds entered noun to nounlib files, formatted correctly

    if (numOfInputs == 5){

        FILE *nounlib;
        nounlib = fopen("nounslib.txt","a");
        
        fprintf(nounlib, "\n%s",inputs[0]);

        for (int i = 1; i<numOfInputs;i++){
            fprintf(nounlib, ", ");
            fprintf(nounlib, inputs[i]);
        }

        fclose(nounlib);
        printf("Successfully added '%s %s' to noun library!\n", inputs[1], inputs[2]);

    } else{

        printf("Please give addn input in form: <english word> <article> <noun> <plural article> <plural ending>. Thanks!\n");

    }
    
}

void verb(){
    printf("verb()\n");
}

void noun(){

    // Tests you on random noun

    printf("The file has %d lines",countFileLines("nounslib.txt"));



    printf("noun()\n");

    FILE *nounlib;
    nounlib = fopen("nounslib.txt","r");
    
    int linesintxtfile = 2;
    srand(2);
    int randnum = rand() % linesintxtfile;

    fclose(nounlib);


}

int main(int argc, char *argv[]){


    if (argc == 1){
        hitme();

    } else if (strcmp(argv[1],"addv")==0){
        addv();

    } else if (strcmp(argv[1],"addn")==0){

        char *input[10];

        // make array of only relevant input words from argv
        for (int i = 0; i < argc-2; i++){
            // sets pointers in input array to the location of relevant pointers in argv
            input[i] = argv[i+2];
        }

        addn(input, argc-2);

    } else if (strcmp(argv[1],"verb")==0){
        verb();

    } else if (strcmp(argv[1],"noun")==0){
        noun();
    } else{
        printf("Unknown lingome command. Please try again.\n");
    }


    return 0;
}