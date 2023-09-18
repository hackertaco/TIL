#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode *bt)
{
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data)
{
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}
void MakeLeftSubTree(BTreeNode *bt, BTreeNode *sub)
{
    if (bt->left != NULL)
        free(bt->left);
    bt->left = sub;
}

void MakeRightSubTree(BTreeNode *bt, BTreeNode *sub)
{
    if (bt->right != NULL)
        free(bt->right);
    bt->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode *bt)
{
    if (bt == NULL)
        return;
    DeleteTree(bt->left);
    DeleteTree(bt->right);

    free(bt);
}
void ChangeLeftSubTree(BTreeNode *bt, BTreeNode *sub)
{
    bt->left = sub;
}
void ChangeRightSubTree(BTreeNode *bt, BTreeNode *sub)
{
    bt->right = sub;
}
BTreeNode *RemoveLeftTree(BTreeNode *bt)
{
    BTreeNode *delNode;
    if (bt != NULL)
    {
        delNode = delNode->left;
        bt->left = NULL;
    }
    return delNode;
}

BTreeNode *RemoveRightTree(BTreeNode *bt)
{
    BTreeNode *delNode;
    if (bt != NULL)
    {
        delNode = delNode->right;
        bt->right = NULL;
    }
    return delNode;
}