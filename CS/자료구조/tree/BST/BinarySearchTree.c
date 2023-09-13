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

BTreeNode* BSTRemove(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pVRoot = MakeBTreeNode();
    BTreeNode* pNode = pVRoot;
    BTreeNode* cNode = *pRoot;
    BTreeNode* dNode;

    ChangeRightSubTree(pVRoot, *pRoot);

    while(cNode!=NULL && GetData(cNode) != data){
        pNode = cNode;
        if(data < GetData(cNode)){
            cNode = GetLeftSubTree(cNode);
        }else{
            cNode = GetRightSubTree(cNode);
        }
    }
    if(cNode == NULL)
        return NULL;
    
    dNode = cNode;

    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode)== NULL){
        if(GetLeftSubTree(pNode) == dNode){
            RemoveLeftTree(pNode);
        }else{
            RemoveRightTree(pNode);
        }
    }
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode)== NULL)
    {
        BTreeNode * dcNode;
        if(GetLeftSubTree(dNode) != NULL){
            dcNode = GetLeftSubTree(dNode);
        }else{
            dcNode = GetRightSubTree(dNode);
        }

        if(GetLeftSubTree(pNode) == dNode){
            ChangeLeftSubTree(pNode, dcNode);
        }else{
            ChangeRightSubTree(pNode, dcNode);
        }
    }else{
        BTreeNode* mNode = GetRightSubTree(dNode);
        BTreeNode* mpNode = dNode;
        int delData;

        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        if(GetLeftSubTree(mpNode) == mNode){
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        }else{
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }
    }
    if(GetRightSubTree(pVRoot) != *pRoot){
        *pRoot = GetRightSubTree(pVRoot);
    }
    free(pVRoot);
    return dNode;

}
void ShowIntData(int data)
{
    printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst)
{
    InorderTraverse(bst, ShowIntData);
}