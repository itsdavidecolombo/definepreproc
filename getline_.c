//
//  readcommand.c
//  
//
//  Created by Davide Colombo on 12/07/21.
//

#include "tablelookup.h"

int getline_(char *s, int lim){

    int c, i;
    for(i = 0; --lim > 0 && (c = getchar()) != EOF && c != '\n'; i++, s++)
        *s = c;
    if(c == '\n')
        *s++ = c, i++;
    else
        return 0;
    *s = '\0';
    return i;
}
