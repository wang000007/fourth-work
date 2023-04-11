#include"BST.h"

//二叉树结点的创建
BSTNode* CreateTreeNode(int x)
{
	BSTNode* p = (BSTNode*)malloc(sizeof(BSTNode));
	p->data = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}

//二叉排序树的查找
BSTNode* Search(BSTNode* root, int x)
{
	if (root == NULL || root->data == x)
		return root;
	else if (x < root->data)
		return Search(root->lchild, x);
	else
		return Search(root->rchild, x);
}

//二叉排序树的插入
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

//二叉排序树的删除
bool Delete(BSTNode* p)
{
	//在二叉排序树中删除结点p，并重新连接它的左右子树
	BSTNode* q, * s;
	//1.p为叶子结点
	if (p->lchild == NULL && p->rchild == NULL)
		p = NULL;

	//2.1 p左子树为空，重接右子树
	else if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;
		free(q);
	}

	//2.2 p右子树为空，重接左子树
	else if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;
		free(q);
	}

	//3.p左右子树均不为空
	else
	{
		q = p;
		s = p->rchild;//找到p的右子树的最左端（中序直接后继）
		while (s->lchild != NULL)
		{
			q = s;
			s = s->lchild;
		}
		p->data = s->data;

		if (q != p)//判断是否执行上述while循环
			q->lchild = s->rchild;//执行上述while循环，重接*q的左子树
		else
			q->rchild = s->rchild;//未执行上述while循环，重接*q的右子树
		free(s);
	}
	return TRUE;
}

//删除函数
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
//递归前序遍历
void PreOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	PreOrderTraverse(root->lchild);
	PreOrderTraverse(root->rchild);
}

//递归中序遍历
void InOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	InOrderTraverse(root->lchild);
	printf("%d ", root->data);
	InOrderTraverse(root->rchild);
}

//递归后序遍历
void PostOrderTraverse(BSTNode* root)
{
	if (root == NULL)
		return;
	PostOrderTraverse(root->lchild);
	PostOrderTraverse(root->rchild);
	printf("%d ", root->data);
}

//非递归前序遍历
void preorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];  // 定义一个栈来保存结点指针
	int top = -1;         // 栈顶指针初始化为-1
	stack[++top] = root;  // 根结点入栈

	while (top >= 0) {
		BSTNode* node = stack[top--];  // 出栈
		printf("%d ", node->data);     // 访问出栈的结点

		// 先将右子树入栈，再将左子树入栈，以便左子树后访问
		if (node->rchild != NULL) {
			stack[++top] = node->rchild;
		}
		if (node->lchild != NULL) {
			stack[++top] = node->lchild;
		}
	}
}

//非递归中序遍历
void inorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];  // 定义一个栈来保存结点指针
	int top = -1;         // 栈顶指针初始化为-1
	BSTNode* p = root;

	while (p != NULL || top >= 0) {
		// 先将当前结点的左子树全部入栈，直到左子树为空
		while (p != NULL) {
			stack[++top] = p;
			p = p->lchild;
		}

		// 左子树处理完成后，出栈访问结点，并将右子树入栈
		if (top >= 0) {
			p = stack[top--];
			printf("%d ", p->data);
			p = p->rchild;
		}
	}
}

//非递归后序遍历
void postorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* stack[100];      // 定义一个栈来保存结点指针
	int flag[100] = { 0 };      // 定义一个标志数组，用于标记结点是否已经出栈过
	int top = -1;             // 栈顶指针初始化为-1
	BSTNode* p = root;

	while (p != NULL || top >= 0) {
		// 先将当前结点的所有左子树入栈，直到左子树为空
		while (p != NULL) {
			stack[++top] = p;
			flag[top] = 0;  // 标志位初始化为0
			p = p->lchild;
		}

		// 左子树处理完成后，出栈访问结点，并将右子树入栈
		if (top >= 0) {
			p = stack[top];
			if (flag[top] == 0) {  // 如果标志位为0，说明结点还未被访问过
				flag[top] = 1;     // 将标志位改为1，表示结点已经出栈过
				p = p->rchild;      // 将右子树入栈
			}
			else {               // 如果标志位为1，说明结点已经被访问过
				printf("%d ", p->data);
				top--;
				p = NULL;          // 将p置为空指针，避免重复处理结点的右子树
			}
		}
	}
}

//层序遍历
void levelorder(BSTNode* root) {
	if (root == NULL) {
		return;
	}

	BSTNode* queue[100];  // 定义一个队列来保存结点指针
	int front = 0, rear = 0;  // 队首和队尾指针初始化为0
	queue[rear++] = root;  // 根结点入队

	while (front < rear) {
		BSTNode* node = queue[front++];  // 队首结点出队
		printf("%d ", node->data);       // 访问出队的结点

		// 左子树入队
		if (node->lchild != NULL) {
			queue[rear++] = node->lchild;
		}

		// 右子树入队
		if (node->rchild != NULL) {
			queue[rear++] = node->rchild;
		}
	}
}

//显示菜单
void show()
{
	printf("二叉排序树ADT\n");
	printf("1.创建二叉排序树\n");
	printf("2.查找结点\n");
	printf("3.插入结点\n");
	printf("4.删除结点\n");
	printf("5.递归前序遍历\n");
	printf("6.递归中序遍历\n");
	printf("7.递归后序遍历\n");
	printf("8.非递归前序遍历\n");
	printf("9.非递归中序遍历\n");
	printf("10.非递归后序遍历\n");
	printf("11.层序遍历\n");
	printf("12.退出\n");
	printf("请输入选择：");
}

//判断用户输入的是否为整数
int judge_int()
{
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j)//循环读入
	{
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++)
		{
			if (word[m] < '0' || word[m]>'9')  //检验是否有乱输入其他字符
			{
				printf("请输入整数：");
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
	for (m = 0; m < len; m++)  // 将字符重新转换为数字
	{
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}


