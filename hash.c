//
//  hash.c
//  
//
//  Created by Davide Colombo on 12/07/21.
//

#include "tablelookup.h"

unsigned hash(char *s){
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31*hashval;
    return hashval % HASHSIZE;
}
