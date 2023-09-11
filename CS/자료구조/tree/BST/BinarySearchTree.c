#include "BinarySearchTree.h"
#include <stdio.h>
#include "BinaryTree2.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}
void BSTInsert(BTreeNode** pRoot, BSTData data){
    BTreeNode * pNode =NULL;
    BTreeNode * cNode = *pRoot;
    BTreeNode * nNode = NULL;

    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;
        pNode = cNode;
        if(GetData(cNode) > data)
        {
            cNode = GetLeftSubTree(cNode);
        } else{
            cNode = GetRightSubTree(cNode);
        }
    }
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else 
    {
        *pRoot = nNode;
    }

}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
    BTreeNode* cNode = bst;
    BSTData currentData;

    while (cNode != NULL)
    {
        currentData = GetData(cNode);
        if(target == currentData)
            return cNode;
        else if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    return NULL;
    
}