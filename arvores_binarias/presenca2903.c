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

// Raiz -- Sub-árvore esquerda -- Sub-árvore direita === PRE-ORDER
void print_tree_pre_order(PTR source) {
    if(source != NULL) {
        printf("%d ", source->key);
        print_tree_pre_order(source->left);
        print_tree_pre_order(source->right);
    }
}

// POS-ORDER
void print_tree_pos_order(PTR source) {
    if(source != NULL) {
        print_tree_pos_order(source->left);
        print_tree_pos_order(source->right);
        printf("%d ", source->key);
    }
}

// IN-ORDER
void print_tree_in_order(PTR source) {
    if(source != NULL) {
        print_tree_in_order(source->left);
        printf("%d ", source->key);
        print_tree_in_order(source->right);
    }
}

int main() {

    PTR source = incicializa();
    TYPEKEY aux;

    while(scanf("%d", &aux) != EOF) {
        PTR node = create_node(aux);
        source = add_node(source, node);
    }

    print_tree_pre_order(source);
    printf(".\n");
    
	print_tree_in_order(source);
    printf(".\n");

    print_tree_pos_order(source);
    printf(".\n");

    return 0;
}