#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
	int num, score;
	char name[10];
	struct employee *next;
};
typedef struct employee node;
typedef node *link;
link del_ptr(link head, link ptr);
link findnode(link head, int num) {
	link ptr;
	ptr = head;
	while (ptr!=NULL)
	{
		if (ptr->num == num)
			return ptr;
		ptr = ptr->next;
	}
	return ptr;
}
link Insertnode(link head, link ptr, int num, int score, char name[10]) {
	link insertnode;
	insertnode = (link)malloc(sizeof(node));
	if (!insertnode)
		return NULL;
	insertnode->num = num;
	insertnode->score = score;
	strcpy_s(insertnode->name, name);
	insertnode->next = NULL;
	if (ptr == NULL) {
		insertnode->next = head;
		return insertnode;
	}
	else{
		if (ptr->next == NULL) {
			ptr->next = insertnode;
		}
		else {
			insertnode->next = ptr->next;
			ptr->next = insertnode;
		}
	}
	return head;
}

int main() {
	link head, ptr, newnode;
	int i, j,find;
	int findword=0;
	int data[12][2] = { 1001,32367,1002,24338,1003,27556,1007,31299,
		1012,42660,1014,25676,1018,44145,1043,52182,1031,32769,
		1037,21100,1041,32196,1046,25776 };
	char namedata[12][10] = { {"Allen"},{ "Scott" },{ "Marry" },{ "John" },
	{ "Mark" },{ "Ricky" },{ "Lisa" },{ "Jasica" },{ "Hanson" },{ "Amy" },{ "Bob" },
	{ "Jack" } };
	printf("員工編號 薪水 員工編號 薪水 員工編號 薪水 員工編號 薪水\n");
	printf("-------------------------------------------------------\n");

	for (i = 0;i < 3;i++) {
		for (j = 0;j < 4;j++) {
			printf("[%4d] $%5d ",data[j*3+i][0],data[j*3+i][1]);
		}
		printf("\n");
	}
	printf("-------------------------------------------------------\n");
	head = (link)malloc(sizeof(node));
	if (!head) {
		printf("Error!!記憶體配置失敗!!\n");
		exit(1);
	}
	head->num = data[0][0];
	for (j = 0;j < 10;j++) {
		head->name[j] = namedata[0][j];
	}
	head->score = data[0][1];
	head->next = NULL;
	ptr = head;
	for (i = 1;i < 12;i++) {
		newnode = (link)malloc(sizeof(node));
		newnode->num = data[i][0];
		for (j = 0;j < 10;j++) {
			newnode->name[j] = namedata[i][j];
		}
		newnode->score = data[i][1];
		newnode->next = NULL;
		ptr->next = newnode;
		ptr = ptr->next;
	}

	while (1)
	{
		printf("\n");
		printf("請輸入要刪除的員工編號,要結束插入過程,請輸入-1: ");
		scanf_s("%d", &findword);
		if (findword == -1)
			break;
		else {
			ptr = head;
			find = 0;
			while (ptr != NULL) {
				if (ptr->num == findword) {
					ptr = del_ptr(head, ptr);
					find++;
					head = ptr;
					break;
				}
				ptr = ptr->next;
			}
			if (find == 0)
				printf("######沒有找到######");
		}
	}
	ptr = head;
	printf("\n\t員工編號	姓名\t薪水\n");
	printf("\t================================\n");
	while (ptr != NULL) {
		printf("\t[%2d]\t[  %-7s]\t[%3d]\n", ptr->num, ptr->name, ptr->score);
		ptr = ptr->next;
	}
	system("pause");
	return 0;
}

link del_ptr(link head, link ptr) {
	link top;
	top = (link)malloc(sizeof(node));
	top = head;
	if (ptr->num == head->num) {
		head = head->next;
		printf("已刪除第 %d 號員工 姓名: %s 薪資:%d\n", ptr->num, ptr->name, ptr->score);
	}
	else {
		while (top->next!=ptr) {
			top = top->next;
		}
		if (ptr->next == NULL) {
			top->next = NULL;
			printf("已刪除第 %d 號員工 姓名: %s 薪資:%d\n", ptr->num, ptr->name, ptr->score);
		}
		else {
			top->next = ptr->next;
			printf("已刪除第 %d 號員工 姓名: %s 薪資:%d\n", ptr->num, ptr->name, ptr->score);
		}
	}
	free(ptr);
	return head;
}
