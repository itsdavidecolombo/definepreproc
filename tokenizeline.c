//
//  tokenizeline.c
//  
//
//  Created by Davide Colombo on 12/07/21.
//

#include "tablelookup.h"

#define MAXLEN 100
#define MAXTOKENS 100

static char **alloctokenarray(void);
static char *strdup_(char *);

/* a function for splitting the content of the input 'line' array of char by using 'sep' */

char **tokenizeline(char *line, char sep){
    
    char **tokens = alloctokenarray();              /* pointer to pointer to char for saving all tokens in this line */
    char *token;                                    /* pointer to char: points to the memory location of the token */
    int ntoken = 0;                                 /* counter of the number of tokens detected */
    int i, e;                                       /* i = start of the token index, e = end of the token index */
    for(i = e = 0; *(line+i+e) != '\0'; e++)
        if(*(line+i+e) == sep || *(line+i+e) == '\n'){
            *(line+i+e) = '\0';
            token = strdup_(line+i);
            tokens[ntoken++] = token;
            i += (e+1);
            e = 0;
        }
    
    return tokens;
}


static char **alloctokenarray(void){
    return (char **)malloc(sizeof(char *) * MAXTOKENS);
}

/* a function for allocating memory for the array of char of a single token */

static char *strdup_(char *t){
    char *ptr;
    ptr = (char *)malloc(strlen(t+1));          /* +1 for '\0' */
    if(ptr != NULL)
        strcpy(ptr, t);
    return ptr;
}

