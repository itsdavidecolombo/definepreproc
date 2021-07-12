//
//  tablelookup.h
//  
//
//  Created by Davide Colombo on 12/07/21.
//

#ifndef tablelookup_h
#define tablelookup_h

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

enum commands {DEFINE = 228, INCLUDE};

unsigned hash(char *s);
int getline_(char *, int);
char **tokenizeline(char *, char);

#endif /* tablelookup_h */
