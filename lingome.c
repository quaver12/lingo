#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// ------------------------------------------ General Utility Functions ------------------------------------------

// Returns number of lines in a .txt file
int countFileLines(char *fileName){
    // Counts numbers of lines in txt file by counting number of '\n's used.

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

// ------------------------------------------ Application Options ------------------------------------------

// Random question
// Incomplete
void hitme(){
    printf("hitme()\n");
}

// Adds entered verb to file library.
// Incomplete
void addv(){
    printf("addv()\n");
}

// Adds entered noun to nounlib files, formatted correctly
// Working
void addn(char *inputs[], int numOfInputs){
    
    if (numOfInputs == 5){

        FILE *nounlib;
        nounlib = fopen("nounslib.txt","a");
        
        fprintf(nounlib, "\n%s",inputs[0]);

        for (int i = 1; i<numOfInputs;i++){
            fprintf(nounlib, ",");
            fprintf(nounlib, inputs[i]);
        }

        fclose(nounlib);
        printf("Successfully added '%s %s' to noun library!\n", inputs[1], inputs[2]);

    } else{

        printf("Please give addn input in form: <english word> <article> <noun> <plural article> <plural ending>. Thanks!\n");

    }
}

// Tests you on random verb
// Incomplete
void verb(){
    printf("verb()\n");
}

// Tests you on random noun
// Incomplete
void noun(){

    FILE *nounlib;
    nounlib = fopen("nounslib.txt","r");
    
    srand(time(NULL));
    int randLine = rand() % countFileLines("nounslib.txt") + 1;

    char stringOfLine[41];
    char *itemisedLineArray[5];

    int n = 40;
    for (int i = 0; i < randLine;i++){
        fgets(stringOfLine,n, nounlib);
    }

    itemisedLineArray[0] = strtok(stringOfLine,",");
    for (int i = 1 ; i < 5 ; i++){
        itemisedLineArray[i] = strtok(NULL,",");
    }

    int ranQuestion = rand()%3;
    int right = 0 ;
    char yn[2];
    

    //just in to force option 3 atm
    ranQuestion = 99;


    if (ranQuestion == 0){
        // test on english word -- > german
        printf("What is the plural article and ending of '%s' in german? ",itemisedLineArray[0]);
        /*
        while (right != 1){
            printf("What is the plural article and ending of '%s' in german? ",itemisedLineArray[0]);

        }
        */
    }else if (ranQuestion == 1){
        while (right != 1){
            printf("What is '%s' in german? (singular) ",itemisedLineArray[0]);
            //scanf("%s",&input);
            //if (input == )
        }

    }else{

        // test on german word --> english
        while (right != 1){

            char input1[600], input2[600];

            printf("Was ist '%s %s' im Englisch? ",itemisedLineArray[1],itemisedLineArray[2]);
            scanf("%s %s",&input1, &input2);
            
            //printf ("%s\n", input1);
            //printf ("%s\n", input2);

            if ((strcmp(input1,"the")==0) && (strcmp(input2,itemisedLineArray[0])==0)){
                printf("Perfect! Well done :)\n");
                    right = 1;
            
            }else{
                printf("Not quite! Want to try again? y/n:");
                scanf("%s",&yn);
                if (yn=="n"){
                    right = 1;
                }
            }  
        }
    }

    fclose(nounlib);

}

// ------------------------------------------ Main ------------------------------------------

int main(int argc, char *argv[]){


    if (argc == 1){
        hitme();

    } else if (strcmp(argv[1],"addv")==0){
        addv();

    } else if (strcmp(argv[1],"addn")==0){
        //prep inputs for addn()
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