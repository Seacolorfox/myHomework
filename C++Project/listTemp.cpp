#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	char name[20];

	struct node* next;  //ָ����һ����ַ��ָ��
};  //����һ������,��ʱ�ڴ治�����ڴ�

typedef struct node Node; //������,������д,̫����struct node 
typedef struct node* Link;
//���캯��,ʵ�ִ�������ͷָ��ָ��һ���յ�����
void creat_node(Link *head) //�β�Ϊ����ָ��,�����Ķ�����ָ�������ָ��,���������֮ǰ�����˺ܾ�,�����׻�.�͵��������Ϊ�Ա�����ֵ���в���,���������ָ��{*head = NULL; //*head��ָ�������}
							//ͷ��,�����нڵ�Ĳ��뷽ʽ
	void insert_head(Link *head, Link p) //�����������β���ͷָ�����ָ��ĵ�ַ,��Ҫ�ı�ͷָ���ָ��,���Ե��õ��Ƕ���ָ��{Link a;a = *head; if(a == NULL){a = p;p -> next = NULL;}else{p -> next = *head;// *head -> next = NULL;��䱻ע�͵���,������ҵ�ʱ���Ĵ�,����������ʹ����ʧ*head = p;}}
										 //β��
	void insert_tail(Link *head, Link p) //ԭ��ͬͷ��,β��ʱע���½ڵ��nextָ��Ҫָ��NULL,��������ѭ��ʱע��ѭ������������ѭ����ִ�еĲ���
{
	Link a;
	a = *head;

	if (*head == NULL) //ͷָ��ָ���ʱ,û�нڵ�
	{
		*head = p;
		p->next = NULL;
	}
	else
	{
		//	*head -> next = p; ��䷸��ͬ��,�����ϵ�
		while (a->next != NULL) //���ѭ��,�����������ҵ��������һλ,���½ڵ�������ȥ
		{
			a = a->next;
		}
		a->next = p;
		p->next = NULL;
	}

}

//�ͷ�����ָ��Ŀռ�
void release_node(Link head) //�ͷſռ䲻��Ҫͷָ����ƶ�,�βε���head��һ��ָ��,��head��ָ���ַ,ͷָ������ݸı�ʱ,ͷָ���ָ��ı�,Ч������ͷָ����ƶ�
{
	Link p;  //����һ��ָ��,ָ��head,ʵ�ֶ�����Ĳ���
	p = head;

	while (p != NULL)
	{
		free(p); //�ͷ�ָ�����pָ��Ŀռ�
		p = p->next;   // pΪ����,������p��ֵ,Ч����ָ�����p����ָ��p����һ���ڵ�
	}
}

//��ӡ�����е�����
void display_node(Link head)  //������Ĳ���,����Ҫ�ƶ�head��λ��,�β�ȡhead��һ��ָ��
{
	Link a; //����һ����ָ�����a,ָ��head��λ��
	a = head;

	while (a != NULL)  //��ӡ�ڵ�����,ָ�����aָ����һ���ڵ�,ʵ�ֺ��Ƶ�ѭ��,ֱ��aָ��һ��NULL
	{
		printf("num = %d name = %s\n", a->num, a->name);
		a = a->next;
	}
}

//���㷵��һ����������ĳ���
int length_node(Link head)  //������Ĳ���,����Ҫ�ƶ�head��λ��,�β�ȡhead��һ��ָ��
{
	Link p;
	int i = 0; //��¼�ڵ����
	p = head;

	while (p != NULL)  //ֱ��pָ��Ŀռ���NULL
	{
		i++;    //i+1����
		p = p->next;  //pָ����һ���ڵ�
	}

	return i; //����ֵi��int��,Ҫ���������ķ���ֵ
}

//����������ָ���ڵ������
void check_node(Link head, int k)  //������Ĳ���,����Ҫ�ƶ�head��λ��,�β�ȡhead��һ��ָ��,kΪָ���ڵ���
{
	Link p;
	p = head;

	if (p == NULL)
		printf("����Ϊ��,�����ݿɲ�\n");
	else
	{
		while (p != NULL)  //�ҵ������е�ָ���ڵ��ӡ����
		{
			if (p->num == k)
			{
				printf("name = %s\n", p->name);
				break; //��ӡ��ɺ�Ҫ�ǵ��˳�ѭ��
			}
			else
				p = p->next; //pָ��p�ĺ�һλ�ֽ�
		}
	}
}

//ɾ��ָ���ڵ�
void delete_node(Link head, int x)  //������Ĳ���,����Ҫ�ƶ�head��λ��,�β�ȡhead��һ��ָ��,kΪָ���ڵ���
{
	Link p, q;
	p = head;

	if (head == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}

	if (head->next == NULL)  //������ֻ��һ���ڵ�
	{
		if (p->num == x)
		{
			free(p);
			p = NULL;
			return;
		}
		else
		{
			printf("û�иýڵ�\n");
			return;
		}
	}

	while (p->num != x) //�ҵ�ָ���ڵ�ɾ��
	{
		q = p; //��¼��ǰpָ���λ��,p����ѭ������ʱ,qָ��p��ǰһ���ڵ��ַ
		p = p->next;
	}

	q->next = p->next;
	p->next = NULL;     //�Ͽ�pָ����ֽ��������е�����˳��
	free(p);    //�ͷſռ�

}

//�м��, �½ڵ�嵽����λ��
void add_node(Link *head, Link m, int y) //��Ҫ����head��ָ��,ȡ����ָ��,�½ڵ��ָ��,����ڵ��λ��
{
	Link p, q;
	p = *head;

	while (p->num != (y - 1)) //ָ��pͣ��Ҫ����λ�õ�ǰһ���ڵ�
	{

		p = p->next;
	}

	q = p->next;
	p->next = m;
	m->next = q;

	m->num = y;  //���ָ���ָ�����
}
//ָ��num�����ظ�ֵ,
void replay_num(Link head)
{
	Link p;
	p = head;
	int i = 0;

	while (p != NULL)
	{
		p->num = i + 1;
		p = p->next;
		i++;
	}

}

//������
int main()
{
	Link head = NULL;//headָ��NULL ��ֹҰָ��
	Link p = NULL; //����һ��ָ��Pָ��NULL,��ֹҰָ��
	int k, x, y = 0, i = 0;
	Link m = NULL; //��ֹҰָ��

	creat_node(&head); //headָ��һ����

	printf("����������:\n");
	for (i = 0;i < 3;i++)
	{
		p = (Link)malloc(sizeof(Node)); //malloc()��������Node��С�Ŀռ�,����ת��ΪLink��,ָ����p

		if (p == NULL)//�ռ����ʧ��
		{
			printf("malloc error!\n");
			exit(-1);  //�������� �ļ�����stdlib.h
		}

		p->num = i + 1;
		scanf("%s", p->name);

		//	insert_head(&head,p); //ͷ��
		insert_tail(&head, p); //β��
	}

	display_node(head);

	printf("������:%d\n", length_node(head));

	printf("��������Ҫ��ѯ�Ľڵ�:\n");
	scanf("%d", &k);
	check_node(head, k);

	printf("��������Ҫɾ���Ľڵ�:\n");
	scanf("%d", &x);
	delete_node(head, x);

	display_node(head);

	m = (Link)malloc(sizeof(Node)); //mָ��һ���·���Ŀռ�
	printf("��������Ҫ����Ľڵ�����:\n");
	scanf("%s", m->name);
	printf("��������Ҫ����Ľڵ�λ��:\n");
	scanf("%d", &y);
	add_node(&head, m, y);

	replay_num(head); //����add_node()�������num��������������

	display_node(head);


	release_node(head); //�ͷź���Ҫ������� ���в����������ͷſռ�
	return 0;
}
