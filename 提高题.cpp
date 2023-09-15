#include <stdio.h>
#include <stdlib.h>
// define
struct ListNode {
 int val;
 struct ListNode *next;
};
// create
struct ListNode* createList(int arr[], int n) {
 if (n <= 0) {
 return NULL;
 }
 struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
 head->val = arr[0];
 head->next = NULL;
 struct ListNode* cur = head;
 for (int i = 1; i < n; i++) {
 struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
 newNode->val = arr[i];
 newNode->next = NULL;
 cur->next = newNode;
 cur = newNode;
 }
 return head;
}
// TODO
struct ListNode* reverseN(struct ListNode* head, int n) {
    struct ListNode *jc,*nexthead,*p,*q=NULL,*h= (struct ListNode*)malloc(sizeof(struct ListNode));
	int i;
	p=head;
	for(i=1;i<n;i++){
		head=head->next;
		if(head->next==NULL)break;
	}
	if(head->next!=NULL){
		nexthead=head->next;
		head->next=NULL;
	}
	while(1){
		jc=p->next;
		h->next=p;
		p->next=q;
		q=p;
		if(jc==NULL)break;
		p=jc;
	}
	head=h->next;
	while(h->next){
		h=h->next;
	}
	h->next=nexthead;
	return head;
// TODO: 补充代码
}
// PRINT
void printList(struct ListNode* head) {
 struct ListNode* cur = head;
 while (cur != NULL) {
 printf("%d -> ", cur->val);
 cur = cur->next;
 }
 printf("NULL\n");
}
int main() {
 int arr[] = {1, 2, 3, 4, 5};
 int n = sizeof(arr) / sizeof(arr[0]);
 struct ListNode* head = createList(arr, n);
 printf("原始链表：");
 printList(head);
 int m = 3; // 反转前 m 个节点
 head = reverseN(head, m);
 printf("反转后的链表：");
 printList(head);
 return 0;
}
