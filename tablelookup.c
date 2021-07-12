//
//  tablelookup.c
//  
//
//  Created by Davide Colombo on 12/07/21.
//

#include "tablelookup.h"

#define MAXLEN 1000

/* a structure for a linked list that stores the name and the relative substitution text */
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

/* the hash table in which each block is linked to the next and indexed by its name's hash */
static struct nlist *hashtab[HASHSIZE];

/* a function for searching the value in the table */
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
struct nlist *undef(char *);

int main(int argc, char *argv[]){
    
    char line[MAXLEN];
    char **tokens;
    char sep = ' ';
    
    struct nlist *np = NULL;
    
    while(getline_(line, MAXLEN) > 0){
        tokens = tokenizeline(line, sep);
        if(strcmp(*tokens, "#define") == 0){
            np = install(tokens[1], tokens[2]);
            if(np != NULL)
                printf("np->name = %s\tnp->defn = %s\n", np->name, np->defn);
        }
    }
    
    return 0;
}

struct nlist *lookup(char *s){
    
    struct nlist *np;
    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(np->name, s) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn){
    
    struct nlist *np;
    unsigned hashval;
    
    if((np = lookup(name)) == NULL){
        np = (struct nlist *)malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL) /* assign and check */
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];                        /* set the next element in the list */
        hashtab[hashval] = np;                              /* insert this element in the table */
    }else
        free((void *)np->defn);
    if((np->defn = strdup(defn)) == NULL)                   /* assign and check */
        return NULL;
    return np;
}

struct nlist *undef(char *name){
    
    struct nlist *np;
    struct nlist *temp;
    unsigned hashval = hash(name);
    for(np = temp = hashtab[hashval]; np != NULL; temp = np, np = np->next)
        if(strcmp(np->name, name) == 0){
            if(np == hashtab[hashval])
                hashtab[hashval] = np->next;
            else
                temp->next = np->next;
            free((void *)np);
            return temp;
        }
    return NULL;
}
