#include <stdio.h>
#include <stdlib.h>

typedef int bool;
typedef int TYPEKEY;

typedef struct node {
    TYPEKEY key;
    struct node *right, *left;
} Node;

typedef Node * PTR;

void em_ordem(PTR raiz) {
    PTR aux = raiz;

    if(raiz == NULL) return;

    while(aux) {
        aux = aux->left;
        if(aux) printf("%d ", aux->key);
    } 

    printf("%d ", raiz->key);
    aux = raiz;

    while(aux) {
        aux = aux->right;
        if(aux) printf("%d ", aux->key);
    }
}