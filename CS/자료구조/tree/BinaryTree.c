#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode(void){
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

    nd->left = NULL;
    nd->right= NULL;
    return nd;
}

BTData GetData(BTreeNode* bt)
{
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}
void MakeLeftSubTree(BTreeNode* bt, BTreeNode* sub)
{
    if(bt->left != NULL)
        free(bt->left);
    bt->left = sub;
}

void MakeRightSubTree(BTreeNode* bt, BTreeNode* sub)
{
    if(bt->right != NULL)
        free(bt->right);
    bt->right = sub;
}