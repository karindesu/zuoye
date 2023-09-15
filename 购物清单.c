#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Shoppingltem{
	char name[50];
	int quantity;
	struct Shoppingltem* next;
};
struct Shoppingltem* shoppingList=NULL;
void addltem(char itemName[],int itemQuantity){
	struct Shoppingltem* newltem=(struct Shoppingltem*)malloc(sizeof(struct Shoppingltem)),*p;
	strcpy(newltem->name,itemName);
	newltem->quantity=itemQuantity;
	if(shoppingList==NULL)shoppingList=newltem;
	else{
		p=shoppingList;
		while(p->next!=NULL)p=p->next;
		p->next=newltem;
		}
	newltem->next=NULL;
}//添加商品到购物清单 
void removeltem(char itemName[]){
	struct Shoppingltem* current =shoppingList;
	struct Shoppingltem* previous=NULL;
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			if(previous!=NULL){
				previous->next=current->next;
			}else{
				shoppingList=current->next;
			}
			free(current);
			break;
		}
		previous=current;
		current=current->next;
	}
}//从购物清单中移除商品 
void displayList(){
	struct Shoppingltem* current=shoppingList;
	printf("购物清单:\n");
	if(current==NULL)printf("目前还什么都没有哦\n"); 
	while(current!=NULL){
		printf("%s - 数量: %d\n",current->name,current->quantity);
		current=current->next;
	}
}//查看购物清单 
void updateQuantity(char itemName[],int newltemQuantity){
	struct Shoppingltem*current=shoppingList;
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			current->quantity=newltemQuantity;
			break;
		}
		current=current->next;
	}
}//修改购物清单中商品的数量 
void clearList(){
	struct Shoppingltem *temp;
	while(shoppingList!=NULL){
		temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}//清空购物清单 
int totalQuantity(){
	struct Shoppingltem* current=shoppingList;
	int total=0;
	while(current!=NULL){
		total+=current->quantity;
		current=current->next;
	}
	return total;
}//计算购物清单中商品的总数量 
void findltem(char itemName[]){
	struct Shoppingltem* current=shoppingList;
	printf("查找商品 \"%s\" : \n",itemName);
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			printf("%s - 数量: %d\n",current->name,current->quantity);
			return;
		}
		current=current->next;
	} 
	printf("未找到商品 \"%s\"。 \n",itemName);
}//查找购物清单中的商品 
void sortList(){
	struct Shoppingltem*current=shoppingList;
	struct Shoppingltem* nextltem=NULL;
	char tempName[50];
	int tempQuantity;
	while(current!=NULL){
		nextltem=current->next;
		while(nextltem!=NULL){
			if(strcmp(current->name,nextltem->name)>0){
				strcpy(tempName,current->name);
				strcpy(current->name,nextltem->name);
				strcpy(nextltem->name,tempName);
				tempQuantity=current->quantity;
				current->quantity=nextltem->quantity;
				nextltem->quantity=tempQuantity;
			}
			nextltem=nextltem->next;
		}
		current=current->next;
	}
}//排序购物清单 
struct Shoppingltem *qd(){
	printf("输入x则停止购物清单继续添加");
	struct Shoppingltem *p,*q,*h=NULL;
	while(1){
		p=(struct Shoppingltem*)malloc(sizeof(struct Shoppingltem));
		scanf("%s",p->name);
		if(strcmp(p->name,"x")==0)break;
		scanf("%d",&p->quantity);
		if(h==NULL)h=p;
		else q->next=p;
		q=p;
		p->next=NULL;
	}
	return h;
}//建立购物清单链表
void mergeLists(struct Shoppingltem** list1,struct Shoppingltem** list2){
	struct Shoppingltem* current =*list1;
	while(current->next!=NULL)current=current->next;
	current->next=*list2;
	*list2=NULL;
} //合并购物清单 
void deleteltem(char itemName[],int deleteAll){
	struct Shoppingltem* current=shoppingList;
	struct Shoppingltem* prev=NULL;
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			if(prev==NULL){
				struct Shoppingltem* temp=shoppingList;
				shoppingList=shoppingList->next;
				current=shoppingList;
				free(temp);
				if(!deleteAll)break;
			}else{
				prev->next=current->next;
				free(current);
				current=prev->next;
				if(!deleteAll)break;
			}
		}else{
			prev=current;
			current=current->next;
		}
	} 
}//删除购物清单中的商品 
int main(){
	struct Shoppingltem *list1,*list2,*q,*p,*h;
	int sr=1,quantity;
	char name[50];
	while(sr!=0){
	printf("请输入0~10以执行对应操作：\n1.添加商品到购物清单\n2.从购物清单中移除商品\n3.查看购物清单\n4.修改清单中商品的数量\n5.清空购物清单\n6. 计算购物清单中商品的总数量\n7.查找购物清单中的商品\n8.排序购物清单\n9.合并购物清单\n10.删除购物清单中的商品\n0.退出程序\n");
	scanf("%d",&sr);
	if(sr==0){
		printf("程序结束，欢迎下次使用\n");
	    return 0;
    }
	if(sr==1){
		printf("请输入要添加的商品名及商品数量\n");
		scanf("%s%d",name,&quantity);
		addltem(name,quantity);
	}
	if(sr==2){
		printf("请输入要移除的商品名\n");
		scanf("%s",name);
		removeltem(name);
	}
	if(sr==3){
		displayList(); 
	}
	if(sr==4){
		printf("请输入要修改商品的商品名及修改后的数量\n");
		scanf("%s%d",name,&quantity);
		updateQuantity(name,quantity);
	}
	if(sr==5){
		clearList();
	}
	if(sr==6){
		quantity=totalQuantity();
		printf("%d\n",quantity);
	}
	if(sr==7){
		printf("请输入要查找的商品名\n");
		scanf("%s",name);
		findltem(name);
	}
	if(sr==8){
		sortList();
	}
	if(sr==9){
		printf("请输入第一个购物清单：\n");
		list1=qd();//建立链表
		printf("请输入第二个购物清单: \n");
		list2=qd(); 
		mergeLists(&list1,&list2);
		shoppingList=list1;
	}
	if(sr==10){
		printf("请输入要删除的商品名及是否要删除所有同名商品，如是请输入1，如不是则输入0");
		scanf("%s%d",name,&quantity);
		deleteltem(name,quantity);
	}
	printf("程序已执行！\n");
}
}
