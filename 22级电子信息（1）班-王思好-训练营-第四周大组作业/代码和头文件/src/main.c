#include"BST.h"

int main()
{
	BSTNode* root = NULL;
	int choice, data;
	do
	{
		show();
		choice = judge_int();//读取用户输入的操作选项
		system("cls");          //清屏

		switch (choice)
		{
		case 1:
		{
			printf("请输入结点数据，以-1结束：");
			while (true)
			{
				scanf("%d", &data);
				if (data == -1)
					break;
				root = Insert(root, data);
			}
			printf("二叉排序树创建完成！\n");
			break;
		}
		case 2:
		{
			printf("请输入要查找的结点数据：");
			scanf("%d", &data);
			BSTNode* p = Search(root, data);
			if (p == NULL)
				printf("未找到该结点！\n");
			else
				printf("已找到该结点！\n");
			break;
		}
		case 3:
		{
			printf("请输入要插入的结点数据：");
			scanf("%d", &data);
			root = Insert(root, data);
			printf("插入成功！\n");
			break;
		}
		case 4:
		{
			printf("请输入要删除的结点数据：");
			scanf("%d", &data);
			if (DeleteBST(root, data))
				printf("删除成功！\n");
			else
				printf("删除失败！\n");
			break;
		}
		case 5:
		{
			printf("递归前序遍历：\n");
			PreOrderTraverse(root);
			printf("\n");
			break;
		}
		case 6:
		{
			printf("递归中序遍历：\n");
			InOrderTraverse(root);
			printf("\n");
			break;
		}
		case 7:
		{
			printf("递归后序遍历：\n");
			PostOrderTraverse(root);
			printf("\n");
			break;
		}
		case 8:
		{
			printf("非递归前序遍历：\n");
			preorder(root);
			printf("\n");
			break;
		}
		case 9:
		{
			printf("非递归中序遍历：\n");
			inorder(root);
			printf("\n");
			break;
		}
		case 10:
		{
			printf("非递归后序遍历：\n");
			postorder(root);
			printf("\n");
			break;
		}
		case 11:
		{
			printf("层序遍历遍历：\n");
			levelorder(root);
			printf("\n");
			break;
		}
		case 12:
		{
			printf("感谢使用，程序已退出！\n");
			exit(0);
			break;
		}
		default:
		{
			printf("请重新输入选择！\n");
			break;
		}
		}
		system("pause");
		system("cls");
	} while (choice != 12);
	return 0;
}