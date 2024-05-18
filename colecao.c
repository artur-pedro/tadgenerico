#include "colecao.h"
struct gCofo{
    int numItens;
    int maxItens;
    int cur;
    void **item;
    int id;
};

gCofo *gcofCreate(int maxItens) {
    gCofo *gc;
    if(maxItens > 0) {
        gc = (gCofo *)malloc(sizeof(gCofo)*1);
        if (gc != NULL) {
            gc->item = (void **)malloc(sizeof(void *) * maxItens);
            if (gc->item != NULL) {
                gc->numItens = 0;
                gc->maxItens = maxItens;
                gc->cur = -1;
                return gc;
            }
            free(gc);
        }
    }
    return NULL;
}
int gcofInsert(gCofo *gc, void *item) {
    if (gc != NULL) {
        if (gc->numItens < gc->maxItens) {
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}
void *gcofQuery(gCofo *c, void *key, int (*cmp)(void*, void*) ) {
    void *data;
    int i, stat;
    if (c != NULL) {
        if (c->numItens > 0) {
            i = 0;
            stat = cmp(key, c->item[i]);
            while (i < c->numItens-1 && stat != TRUE) {
                i++;
                stat = cmp(key, c->item[i]);
            }
            if (stat == TRUE) {
                data = c->item[i];
                return data;
            }
        }
    }
    return NULL;
}
void *gcofRemove(gCofo *c, void *key, int (*cmp)(void *, void *) )
{
    int i;
    void *data;
    int stat;
    if ( c != NULL) {
        if (c->numItens > 0 ) {
            i = 0; 
            stat = cmp(key, c->item[i]);
            while ( i < c->numItens-1 && stat != TRUE) {
                i++;
                stat = cmp(key, c->item[i]);
            }
            if (stat == TRUE) {
                data = c->item[i];
                for (int j=i; j< c->numItens; j++) {
                    c->item[j] = c->item[j+1];
            }
            c->numItens--;
            return data;
            }           
        }
    }
    return NULL;
}
int gcofDestroy(gCofo *c) {
    if (c != NULL) {
        if (c->numItens == 0) {
            free(c->item);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}
void *gcofGetFirst(gCofo *c)
{
    if(c != NULL) {
        if(c->numItens >0) {
            c->cur = 0;
            return c->item[c->cur];
        }

    }
    return NULL;


}
void *gcofGetNext(gCofo *c)
{
    if(c != NULL) {
        if(c->cur < c->numItens -1) {
            c->cur++;
            return c->item[c->cur];
        }

    }
    return NULL;


}
void *gcofEmpty(gCofo *c) {
    if (c != NULL) {
        void *item = gcofGetFirst(c);

        while (item != NULL) {
            free(item); 
            item = gcofGetNext(c); 
        }
        c->numItens = 0;
    }
}
