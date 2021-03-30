#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TYPEKEY;

typedef struct node {
    TYPEKEY key;
    struct node *right, *left;
} Node;

typedef Node * PTR;

PTR incicializa() {
    return NULL;
}

PTR add_node(PTR source, PTR node) {
    if(source == NULL) return node;
    if(node->key < source->key) source->left = add_node(source->left, node);
    else source->right = add_node(source->right, node);

    return source;
}

PTR create_node(TYPEKEY key) {
    PTR node = (PTR)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->key = key;

    return node;
}

PTR search(TYPEKEY key, PTR source) {
    if(source == NULL) return NULL;
    if(source->key == key) return source;
    if(source->key > key) return search(key, source->left);

    return search(key, source->right);
}

// Sub-árvore esquerda -- Raiz -- Sub-árvore direita
int tree_size(PTR source) {
    if(!source) return 0;

    return(tree_size(source->left) + 1 + tree_size(source->right));
}

// Raiz -- Sub-árvore esquerda -- Sub-árvore direita
void print_tree(PTR source) {
    if(source != NULL) {
        printf("%d ", source->key);
        printf("(");
        print_tree(source->left);
        print_tree(source->right);
        printf(")");
    }
}

void em_ordem(PTR p) {
    int d = 0; 
    PTR q; 
    PTR pai;

    while(p != NULL) {
        switch (d){
            case 0:
                printf("%d ", p->key);
                if(p->left != NULL) {
                    pai = p;
                    p = p->left;
                } 
                else d = 1;
                break;

            case 1:
                printf("%d ", p->key);
                if(p->right != NULL) {
                    pai = p;
                    p = p->right;
                    d = 0;
                }
                else d = 2;
                break;

            case 2:
                // printf("%d ", p->key);
                q = p;
                p = pai;
                if(p != NULL) if(p->left == q) d = 1;
                break;
        }
    }
}


PTR search_node(PTR source, TYPEKEY key, PTR *dad) {
    PTR current = source;
    *dad = NULL;

    while(current) {
        if(current->key == key) return current;
        *dad = current;
        if(key < current->key) current = current->left;
        else current = current->right;
    }

    return NULL;
}

PTR remove_node(PTR source, TYPEKEY key) {
    PTR dad, node, p, q;
    node = search_node(source, key, &dad);

    if(node == NULL) return(source);
    if(!node->left || !node->right) {
        if(!node->left) q = node->right;
        else q = node->left;
    } else {
        p = node;
        q = node->left;

        while(q->right) {
            p = q;
            q = q->right;
        }

        if(p != node) {
            p->right = q->left;
            q->left = node->left;
        }

        q->right = node->right;
    }

    if(!dad) {
        free(node);
        return q;
    }

    if(key < dad->key) dad->left = q;
    else dad->right = q;

    free(node);
    return source;
}

int main() {

    PTR source = incicializa();
    TYPEKEY aux;

    while(scanf("%d", &aux) != EOF) {
        PTR node = create_node(aux);
        source = add_node(source, node);
    }

    // PTR find_key = search(12, source);

    // printf("Chave 12 encontrada = %d\n", find_key != NULL ? find_key->key : 0);

    // printf("Tamanho = %d elementos\n", tree_size(source));

    print_tree(source);
    printf("\n");

    em_ordem(source);
    printf("\n");

    return 0;
}