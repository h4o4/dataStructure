#include <stdio.h>

typedef struct BST {
    int *node;
    struct BST *lchild;
    struct BST *rchild;
} BST;

BST newBST() {
    BST temp;
    temp.node = NULL;
    temp.lchild = NULL;
    temp.rchild = NULL;
    return temp;
}

void insert(BST *bst, int *data) {
    if (bst->node) {
        printf("%d, %d\n", *data, *bst->node);
        if (*data > *bst->node) {
            if (bst->rchild) {
                insert(bst->rchild, data);
            } else {
                *bst->rchild = newBST();
                bst->rchild->node = data;
            }
        } else {
            if (bst->lchild) {
                insert(bst->lchild, data);
            } else {
                *bst->lchild = newBST();
                bst->lchild->node = data;
            }
        }
    } else {
        bst->node = data;
    }
}



int main(void) {
    BST a = newBST();
    insert(&a, (int *)1);
    // printf("%d\n", *a.node);
    // insert(&a, (int *)3);
    // printf("%d\n", a.rchild==NULL?1:0);
    // insert(&a, (int *)2);
    // insert(&a, (int *)6);
    return 0;
}