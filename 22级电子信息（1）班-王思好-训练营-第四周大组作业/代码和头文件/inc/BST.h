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

//�����������Ľ�㶨��
typedef struct BSTNode
{
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

//��������
 
//���������Ĵ���
BSTNode* CreateTreeNode(int x);
//�����������Ĳ���
BSTNode* Search(BSTNode* root, int x);
//�����������Ĳ���
BSTNode* Insert(BSTNode* root, int x);
//������������ɾ��
bool Delete(BSTNode* p);
//ɾ������
bool DeleteBST(BSTNode* root, int x);
//�ݹ�ǰ�����
void PreOrderTraverse(BSTNode* root);
//�ݹ��������
void InOrderTraverse(BSTNode* root);
//�ݹ�������
void PostOrderTraverse(BSTNode* root);
//�ǵݹ�ǰ�����
void preorder(BSTNode* root);
//�ǵݹ��������
void inorder(BSTNode* root);
//�ǵݹ�������
void postorder(BSTNode* root);
//�������
void levelorder(BSTNode* root);
//��ʾ�˵�
void show();
//�ж��û�������Ƿ�Ϊ����
int judge_int();

#endif