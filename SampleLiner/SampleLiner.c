#include<stdio.h>
#include<stdlib.h>
#include <string.h>


struct list{
	int key;
	int score;
	char name[100];
	struct list *next;
};

struct list *get_list(void);
void print_list(struct list *p);
void insert(struct list *x, struct list *p);
void delete_it(struct list *p);
int get_data(void);
int liner_search (struct list *x, int list_size, int y);


#define EOD -1

int a[] = {1,EOD};

int main(void){
	struct list *listptr, *new1;
	int selection;
	int id;
	int list_size;
	int list_position;

	setvbuf(stdout,NULL,_IONBF,0);

	listptr = get_list();
	list_size = sizeof(listptr)/4;

	printf("現在のデータリスト\n");
	print_list(listptr);


	for(;;){
		printf("操作を選択してください。 表示：0、追加：1、検索：2、削除：3、終了4\n");
		scanf("%d", &selection);

		switch(selection){
		case 0:
			print_list(listptr);
			break;
		case 1:
			printf("追加する生徒の情報を入力して下さい。\n");

			new1 = (struct list*)malloc(sizeof(int)*2 + sizeof(char));

			printf("氏名：");
			scanf("%s", new1->name );

			printf("点数：");
			scanf("%d", &new1->score);

			list_size = sizeof(listptr)/4;
			new1->key = list_size;

			insert(new1, listptr);

			break;
		case 2:
			printf("検索する生徒のIDを入力してください。\nID:");
			printf("%d",id);

			list_position = liner_search(listptr,list_size,id);

			printf("ID：%d\t氏名：%s\t点数：%d\n", listptr[list_position].key, listptr[list_position].name,listptr[list_position].score );

			break;
		case 3:
			printf("削除する生徒のIDを入力して下さい。\n");
			scanf("%d",&id);

			list_position = liner_search (listptr,list_size,id);
			delete_it(&listptr[list_position]);
			list_size = sizeof(listptr)/4;

			break;
		case 4:
			return 0;
		}
	}
}

struct list *get_list(void){

	int d;
	struct list *p, *newp;

	p = NULL;
	while((d = get_data()) != EOD){
		newp = (struct list*)malloc(sizeof(struct list));/*新しい項目のメモリ確保*/

		newp->key = d;
		strcpy(newp->name,"Sample"),
		newp->score = 50;
		newp->next = p;
		p = newp;
	}
	return p;
}

int get_data(void){
	static int i = 0;

	return a[i++];
}

void print_list(struct list *p){
	while(p != NULL){
		printf("ID：%d\t氏名：%s\t点数：%d\n", p->key,p->name,p->score);
		p = p -> next;
	}
	printf("\n");
}

void insert(struct list *x, struct list *p){

	struct list temp;

	temp = *x;
	*x = *p;
	*p = temp;
	p -> next = x;
}

int liner_search (struct list *x, int list_size, int y) {
  int i = 0;
  while (i < list_size) {
    if (x[i].key == y) { return i; }
    i++;
  }
  return -1;
}

void delete_it(struct list *p){
	struct list *q;

	if(p -> next != NULL){
		q = p -> next;
		*p = *q;
		free(q);
	}
}
