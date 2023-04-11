#include"BST.h"

//���������Ĵ���
BSTNode* CreateTreeNode(int x)
{
	BSTNode* p = (BSTNode*)malloc(sizeof(BSTNode));
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

//�����������Ĳ���
BSTNode* Search(BSTNode* root, int x)
{
	if (root == NULL || root->data == x)
		return root;
	else if (x < root->data)
		return Search(root->lchild, x);
	else
		return Search(root->rchild, x);
}

//�����������Ĳ���
BSTNode* Insert(BSTNode* root, int x)
{
	if (root == NULL)
	{
		root = CreateTreeNode(x);
		return root;
	}
	if (x < root->data)
		root->lchild = Insert(root->lchild, x);
	if (x > root->data)
		root->rchild = Insert(root->rchild, x);
	return root;
}

//������������ɾ��
bool Delete(BSTNode* p)
{
	//�ڶ�����������ɾ�����p������������������������
	BSTNode* q, * s;
	//1.pΪҶ�ӽ��
	if (p->lchild == NULL && p->rchild == NULL)
		p = NULL;

	//2.1 p������Ϊ�գ��ؽ�������
	else if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		free(q);
	}

	//2.2 p������Ϊ�գ��ؽ�������
	else if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		free(q);
	}

	//3.p������������Ϊ��
	else
	{
		q = p;
		s = p->rchild;//�ҵ�p��������������ˣ�����ֱ�Ӻ�̣�
		while (s->lchild != NULL)
		{
			q = s;
			s = s->lchild;
		}
		p->data = s->data;

		if (q != p)//�ж��Ƿ�ִ������whileѭ��
			q->lchild = s->rchild;//ִ������whileѭ�����ؽ�*q��������
		else
			q->rchild = s->rchild;//δִ������whileѭ�����ؽ�*q��������
		free(s);
	}
	return TRUE;
}

//ɾ������
bool DeleteBST(BSTNode* root, int x)
{
	if (root == NULL)
		return FALSE;
	else
	{
		if (x == root->data)
			return Delete(root);
		else if (x < root->data)
			return DeleteBST(root->lchild, x);
		else
			return DeleteBST(root->rchild, x);
	}
}
//�ݹ�ǰ�����
void PreOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	PreOrderTraverse(root->lchild);
	PreOrderTraverse(root->rchild);
}

//�ݹ��������
void InOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	InOrderTraverse(root->lchild);
	printf("%d ", root->data);
	InOrderTraverse(root->rchild);
}

//�ݹ�������
void PostOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	PostOrderTraverse(root->lchild);
	PostOrderTraverse(root->rchild);
	printf("%d ", root->data);
}

//�ǵݹ�ǰ�����
void preorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];  // ����һ��ջ��������ָ��
	int top = -1;         // ջ��ָ���ʼ��Ϊ-1
	stack[++top] = root;  // �������ջ

	while (top >= 0) {
		BSTNode* node = stack[top--];  // ��ջ
		printf("%d ", node->data);     // ���ʳ�ջ�Ľ��

		// �Ƚ���������ջ���ٽ���������ջ���Ա������������
		if (node->rchild != NULL) {
			stack[++top] = node->rchild;
		}
		if (node->lchild != NULL) {
			stack[++top] = node->lchild;
		}
	}
}

//�ǵݹ��������
void inorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];  // ����һ��ջ��������ָ��
	int top = -1;         // ջ��ָ���ʼ��Ϊ-1
	BSTNode* p = root;

	while (p != NULL || top >= 0) {
		// �Ƚ���ǰ����������ȫ����ջ��ֱ��������Ϊ��
		while (p != NULL) {
			stack[++top] = p;
			p = p->lchild;
		}

		// ������������ɺ󣬳�ջ���ʽ�㣬������������ջ
		if (top >= 0) {
			p = stack[top--];
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

//�ǵݹ�������
void postorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];      // ����һ��ջ��������ָ��
	int flag[100] = { 0 };      // ����һ����־���飬���ڱ�ǽ���Ƿ��Ѿ���ջ��
	int top = -1;             // ջ��ָ���ʼ��Ϊ-1
	BSTNode* p = root;

	while (p != NULL || top >= 0) {
		// �Ƚ���ǰ����������������ջ��ֱ��������Ϊ��
		while (p != NULL) {
			stack[++top] = p;
			flag[top] = 0;  // ��־λ��ʼ��Ϊ0
			p = p->lchild;
		}

		// ������������ɺ󣬳�ջ���ʽ�㣬������������ջ
		if (top >= 0) {
			p = stack[top];
			if (flag[top] == 0) {  // �����־λΪ0��˵����㻹δ�����ʹ�
				flag[top] = 1;     // ����־λ��Ϊ1����ʾ����Ѿ���ջ��
				p = p->rchild;      // ����������ջ
			}
			else {               // �����־λΪ1��˵������Ѿ������ʹ�
				printf("%d ", p->data);
				top--;
				p = NULL;          // ��p��Ϊ��ָ�룬�����ظ��������������
			}
		}
	}
}

//�������
void levelorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* queue[100];  // ����һ��������������ָ��
	int front = 0, rear = 0;  // ���׺Ͷ�βָ���ʼ��Ϊ0
	queue[rear++] = root;  // ��������

	while (front < rear) {
		BSTNode* node = queue[front++];  // ���׽�����
		printf("%d ", node->data);       // ���ʳ��ӵĽ��

		// ���������
		if (node->lchild != NULL) {
			queue[rear++] = node->lchild;
		}

		// ���������
		if (node->rchild != NULL) {
			queue[rear++] = node->rchild;
		}
	}
}

//��ʾ�˵�
void show()
{
	printf("����������ADT\n");
	printf("1.��������������\n");
	printf("2.���ҽ��\n");
	printf("3.������\n");
	printf("4.ɾ�����\n");
	printf("5.�ݹ�ǰ�����\n");
	printf("6.�ݹ��������\n");
	printf("7.�ݹ�������\n");
	printf("8.�ǵݹ�ǰ�����\n");
	printf("9.�ǵݹ��������\n");
	printf("10.�ǵݹ�������\n");
	printf("11.�������\n");
	printf("12.�˳�\n");
	printf("������ѡ��");
}

//�ж��û�������Ƿ�Ϊ����
int judge_int()
{
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j)//ѭ������
	{
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++)
		{
			if (word[m] < '0' || word[m]>'9')  //�����Ƿ��������������ַ�
			{
				printf("������������");
				break;
			}
			else
			{
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
	{
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}


