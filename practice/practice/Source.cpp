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

int main() {
	link head, ptr, newnode,last,before;
	int i, j, findword = 0;
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
	ptr = head;
	i = 0;
	printf("原始員工串列節點資料:\n");
	while (ptr!=NULL)
	{
		printf("[%2d %6s %3d] -> ", ptr->num, ptr->name, ptr->score);
		i++;
		if(i >= 3) {
			printf("\n");
			i = 0;
		}
		ptr = ptr->next;
	}
	ptr = head;
	before = NULL;
	printf("\n反轉後串列節點資料:\n");
	while (ptr != NULL) {
		last = before;
		before = ptr;
		ptr = ptr->next;
		before->next = last;
	}
	ptr = before;
	while (ptr != NULL) {
		printf("[%2d %6s %3d] -> ", ptr->num, ptr->name, ptr->score);
		i++;
		if (i >= 3) {
			printf("\n");
			i = 0;
		}
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
