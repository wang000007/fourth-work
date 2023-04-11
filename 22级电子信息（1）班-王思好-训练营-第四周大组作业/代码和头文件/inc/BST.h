#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;

//二叉排序树的结点定义
typedef struct BSTNode
{
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

//函数声明
 
//二叉树结点的创建
BSTNode* CreateTreeNode(int x);
//二叉排序树的查找
BSTNode* Search(BSTNode* root, int x);
//二叉排序树的插入
BSTNode* Insert(BSTNode* root, int x);
//二叉排序树的删除
bool Delete(BSTNode* p);
//删除函数
bool DeleteBST(BSTNode* root, int x);
//递归前序遍历
void PreOrderTraverse(BSTNode* root);
//递归中序遍历
void InOrderTraverse(BSTNode* root);
//递归后序遍历
void PostOrderTraverse(BSTNode* root);
//非递归前序遍历
void preorder(BSTNode* root);
//非递归中序遍历
void inorder(BSTNode* root);
//非递归后序遍历
void postorder(BSTNode* root);
//层序遍历
void levelorder(BSTNode* root);
//显示菜单
void show();
//判断用户输入的是否为整数
int judge_int();

#endif