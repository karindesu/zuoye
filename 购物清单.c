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
}//�����Ʒ�������嵥 
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
}//�ӹ����嵥���Ƴ���Ʒ 
void displayList(){
	struct Shoppingltem* current=shoppingList;
	printf("�����嵥:\n");
	if(current==NULL)printf("Ŀǰ��ʲô��û��Ŷ\n"); 
	while(current!=NULL){
		printf("%s - ����: %d\n",current->name,current->quantity);
		current=current->next;
	}
}//�鿴�����嵥 
void updateQuantity(char itemName[],int newltemQuantity){
	struct Shoppingltem*current=shoppingList;
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			current->quantity=newltemQuantity;
			break;
		}
		current=current->next;
	}
}//�޸Ĺ����嵥����Ʒ������ 
void clearList(){
	struct Shoppingltem *temp;
	while(shoppingList!=NULL){
		temp=shoppingList;
		shoppingList=shoppingList->next;
		free(temp);
	}
}//��չ����嵥 
int totalQuantity(){
	struct Shoppingltem* current=shoppingList;
	int total=0;
	while(current!=NULL){
		total+=current->quantity;
		current=current->next;
	}
	return total;
}//���㹺���嵥����Ʒ�������� 
void findltem(char itemName[]){
	struct Shoppingltem* current=shoppingList;
	printf("������Ʒ \"%s\" : \n",itemName);
	while(current!=NULL){
		if(strcmp(current->name,itemName)==0){
			printf("%s - ����: %d\n",current->name,current->quantity);
			return;
		}
		current=current->next;
	} 
	printf("δ�ҵ���Ʒ \"%s\"�� \n",itemName);
}//���ҹ����嵥�е���Ʒ 
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
}//�������嵥 
struct Shoppingltem *qd(){
	printf("����x��ֹͣ�����嵥�������");
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
}//���������嵥����
void mergeLists(struct Shoppingltem** list1,struct Shoppingltem** list2){
	struct Shoppingltem* current =*list1;
	while(current->next!=NULL)current=current->next;
	current->next=*list2;
	*list2=NULL;
} //�ϲ������嵥 
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
}//ɾ�������嵥�е���Ʒ 
int main(){
	struct Shoppingltem *list1,*list2,*q,*p,*h;
	int sr=1,quantity;
	char name[50];
	while(sr!=0){
	printf("������0~10��ִ�ж�Ӧ������\n1.�����Ʒ�������嵥\n2.�ӹ����嵥���Ƴ���Ʒ\n3.�鿴�����嵥\n4.�޸��嵥����Ʒ������\n5.��չ����嵥\n6. ���㹺���嵥����Ʒ��������\n7.���ҹ����嵥�е���Ʒ\n8.�������嵥\n9.�ϲ������嵥\n10.ɾ�������嵥�е���Ʒ\n0.�˳�����\n");
	scanf("%d",&sr);
	if(sr==0){
		printf("�����������ӭ�´�ʹ��\n");
	    return 0;
    }
	if(sr==1){
		printf("������Ҫ��ӵ���Ʒ������Ʒ����\n");
		scanf("%s%d",name,&quantity);
		addltem(name,quantity);
	}
	if(sr==2){
		printf("������Ҫ�Ƴ�����Ʒ��\n");
		scanf("%s",name);
		removeltem(name);
	}
	if(sr==3){
		displayList(); 
	}
	if(sr==4){
		printf("������Ҫ�޸���Ʒ����Ʒ�����޸ĺ������\n");
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
		printf("������Ҫ���ҵ���Ʒ��\n");
		scanf("%s",name);
		findltem(name);
	}
	if(sr==8){
		sortList();
	}
	if(sr==9){
		printf("�������һ�������嵥��\n");
		list1=qd();//��������
		printf("������ڶ��������嵥: \n");
		list2=qd(); 
		mergeLists(&list1,&list2);
		shoppingList=list1;
	}
	if(sr==10){
		printf("������Ҫɾ������Ʒ�����Ƿ�Ҫɾ������ͬ����Ʒ������������1���粻��������0");
		scanf("%s%d",name,&quantity);
		deleteltem(name,quantity);
	}
	printf("������ִ�У�\n");
}
}
