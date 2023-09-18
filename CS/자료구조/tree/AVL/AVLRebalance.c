#include <stdio.h>
#include "BinaryTree2.h"

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    return cNode;
}

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;
    pNode = bst;
    cNode = GetLeftSubTree(pNode);
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}
BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode* pNode;
    BTreeNode* cNode;
    pNode = bst;
    cNode = GetRightSubTree(pNode);
    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

int GetHeight(BTreeNode* bst)
{
    int leftH;
    int rightH;
    if(bst == NULL)
    {
        return 0;
    }
    leftH = GetHeight(bst->left);
    rightH = GetHeight(bst->right);
    if(leftH > rightH){
        return leftH + 1;
    }else{
        return rightH +1;
    }
}
int GetHeightDiff(BTreeNode* bst)
{
    int lsh;
    int rsh;
    if(bst == NULL)
    {
        return 0;
    }
    lsh = GetHeight(bst->left);
    rsh = GetHeight(bst->right);
    return lsh - rsh;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
    int hDiff = GetHeightDiff(* pRoot);
    if(hDiff > 1){
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0){
            *pRoot = RotateLL(*pRoot);
        }else{
            *pRoot = RotateLR(*pRoot);
        }
    }
    if(hDiff < -1){
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0){
            *pRoot = RotateRR(*pRoot);
        }else{
            *pRoot = RotateRL(*pRoot);
        }
    }
    return *pRoot;
}