
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;
typedef struct _bTreeNode
{
    /* data */
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
}BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTreE(BTreeNode* bt);

void MakeLeftSubTree(BtreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif