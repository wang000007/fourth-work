#include"BST.h"

int main()
{
	BSTNode* root = NULL;
	int choice, data;
	do
	{
		show();
		choice = judge_int();//��ȡ�û�����Ĳ���ѡ��
		system("cls");          //����

		switch (choice)
		{
		case 1:
		{
			printf("�����������ݣ���-1������");
			while (true)
			{
				scanf("%d", &data);
				if (data == -1)
					break;
				root = Insert(root, data);
			}
			printf("����������������ɣ�\n");
			break;
		}
		case 2:
		{
			printf("������Ҫ���ҵĽ�����ݣ�");
			scanf("%d", &data);
			BSTNode* p = Search(root, data);
			if (p == NULL)
				printf("δ�ҵ��ý�㣡\n");
			else
				printf("���ҵ��ý�㣡\n");
			break;
		}
		case 3:
		{
			printf("������Ҫ����Ľ�����ݣ�");
			scanf("%d", &data);
			root = Insert(root, data);
			printf("����ɹ���\n");
			break;
		}
		case 4:
		{
			printf("������Ҫɾ���Ľ�����ݣ�");
			scanf("%d", &data);
			if (DeleteBST(root, data))
				printf("ɾ���ɹ���\n");
			else
				printf("ɾ��ʧ�ܣ�\n");
			break;
		}
		case 5:
		{
			printf("�ݹ�ǰ�������\n");
			PreOrderTraverse(root);
			printf("\n");
			break;
		}
		case 6:
		{
			printf("�ݹ����������\n");
			InOrderTraverse(root);
			printf("\n");
			break;
		}
		case 7:
		{
			printf("�ݹ���������\n");
			PostOrderTraverse(root);
			printf("\n");
			break;
		}
		case 8:
		{
			printf("�ǵݹ�ǰ�������\n");
			preorder(root);
			printf("\n");
			break;
		}
		case 9:
		{
			printf("�ǵݹ����������\n");
			inorder(root);
			printf("\n");
			break;
		}
		case 10:
		{
			printf("�ǵݹ���������\n");
			postorder(root);
			printf("\n");
			break;
		}
		case 11:
		{
			printf("�������������\n");
			levelorder(root);
			printf("\n");
			break;
		}
		case 12:
		{
			printf("��лʹ�ã��������˳���\n");
			exit(0);
			break;
		}
		default:
		{
			printf("����������ѡ��\n");
			break;
		}
		}
		system("pause");
		system("cls");
	} while (choice != 12);
	return 0;
}