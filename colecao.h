#ifndef COLECAO_H
#define COLECAO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef struct gCofo gCofo;
gCofo *gcofCreate(int maxItens);
int gcofInsert(gCofo *c, void* item);
void *gcofRemove(gCofo *c, void* key,int (*cmp)(void*,void *));
void *gcofQuery( gCofo *c, void* key,int (*cmp)(void*,void*));
int gcofDestroy(gCofo *c);
void *gcofGetFirst(gCofo *c);
void *gcofGetNext(gCofo *c);
void *gcofEmpty(gCofo *c);
#endif