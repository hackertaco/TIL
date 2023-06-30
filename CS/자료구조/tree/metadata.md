### 트리 구현 방법
- 배열 기반: 매우 빈번한 탐색을 할 때 유리하다.
- 연결 리스트 기반: 조금 더 유연하다. 

매일매일 공부해도 까먹는, 이진트리의 분류
1. 포화 이진트리: 모든 레벨이 꽉 찬 이진트리.
2. 완전 이진 트리: 모든 레벨이 꽉 차지는 않았지만, 차곡차곡 빈 틈 없이 채워진 상태

BinaryTree.h
```c
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode // 이진 트리의 노드이면서, 이진트리의 표현도 된다. 자식 노드가 하나도 없는 노드도 그 자체로 이진 트리다.
{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * Right;
} BTreeNode;

BTreeNode * MakeBtreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

typedef void (*VisitFuncPtr)(BTData data);
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
#endif
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode * MakeBtreeNode(void){
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
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

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if(main->left != NULL) // 한 번의 free 함수호출이 전부라서, 삭제할 서브 트리가 하나의 노드로 이루어져 있다면 문제되지 않지만, 그렇지 않다면 메모리의 누수로 이어진다.
        free(main->left);
    main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if(main->right != NULL) // 한 번의 free 함수호출이 전부라서, 삭제할 서브 트리가 하나의 노드로 이루어져 있다면 문제되지 않지만, 그렇지 않다면 메모리의 누수로 이어진다.
        free(main->right);
    main->right = sub;
}
```
둘 이상의 노드로 이루어져 있는 서브 트리를 완전히 삭제하려면, 서브 트리를 구성하는 모든 노드를 대상으로 free 함수를 호출해야한다. 

BinaryTreeMain.c
```c
#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    BTreeNode* bt1 = MakeBtreeNode();
    BTreeNode* bt2 = MakeBtreeNode();
    BTreeNode* bt3 = MakeBtreeNode();
    BTreeNode* bt4 = MakeBtreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);

    printf("%d \n", GetData(GetLeftSubTree(bt1)));
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    return 0;
}
```

순회라고하면, 중위순회, 후위순회, 전위순회 세가지가 있고, 세가지 순회 방법을 재귀적으로 구현만 하면 된다. 

```c
#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    InOrderTraverse(bt->left);
    action(bt->data);
    InOrderTraverse(bt->right);
}
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    action(bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}
void PostTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if(bt == NULL)
        return;
    PostTraverse(bt->left);
    PostTraverse(bt->right);
    action(bt->data);
}
```

## 수식 트리의 구현

```c
#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]); // 수식 트리 구성, 후위 표기법의 수식을 문자열의 형태로 입력 받는다. 
int EvaluateExpTree(BTreeNode * bt); //수식 트리 계산

void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif
```

피 연산자는 스택으로 옮기고, 연산자가 나오면 스택에서 피연산자 2개를 꺼낸다. 그리고 그 피연산자를 연결해서 만들어진 트리를 다시 스택으로 옮긴다. 


```c
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pnode;

    int expLen = strlen(exp);
    int i;

    StackInit(&stack);
    for(i=0; i<expLen; i++)
    {
        pnode = MakeBTreeNode();
        if(isdigit(exp[i])){
            SetData(pnode, exp[i]-'0');
        }else{
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        SPush(&stack, pnode);
    }
    return SPop(&stack);
}

void ShowNodeData(int data)
{
    if(data >= 0 && data <= 9)
    {
        printf("%d ", data);
    }else
    {
        printf("%c ", data);
    }
}

void ShowPrefixTypeExt(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExt(BTreeNode * bt)
{
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExt(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;
    if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)
		return GetData(bt);
    op1 = GetData(GetLeftSubTree(bt));
    op2 = GetData(GetRightSubTree(bt));
    switch(GetData(bt))
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
    return 0;
}
```

