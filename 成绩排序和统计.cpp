#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct ss{
	char name[20];
	char id[20];
	float score;
	struct ss *next;
}s;
void cj(s *h){
		s *p1=h,*p2;
	char name[20],id[20];
	float score;
	while(p1->next){
		strcpy(name,p1->name);
		strcpy(id,p1->id);
		score=p1->score;
		p2=p1->next;
		while(p2){
			if(score<p2->score){
				strcpy(p1->name,p2->name);
				strcpy(p1->id,p2->id);
				p1->score=p2->score;
				strcpy(p2->name,name);
				strcpy(p2->id,id);
				strcpy(name,p1->name);
				strcpy(id,p1->id);
				p2->score=score;
						score=p1->score;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	FILE *fp1=fopen("cj.txt","w+");
	while(h){
		fprintf(fp1,"%s %s %.0f\n",h->id,h->name,h->score);
		h=h->next;
	}
	fclose(fp1);
	printf("文件已保存在cj.txt中\n"); 
}
void xm(s *h){
		s *p1=h,*p2;
	char name[20],id[20];
	float score;
	while(p1->next){
		strcpy(name,p1->name);
		strcpy(id,p1->id);
		score=p1->score;
		p2=p1->next;
		while(p2){
			if(name[0]>p2->name[0]){
				strcpy(p1->name,p2->name);
				strcpy(p1->id,p2->id);
				p1->score=p2->score;
				strcpy(p2->name,name);
				strcpy(p2->id,id);
				strcpy(name,p1->name);
				strcpy(id,p1->id);
				p2->score=score;
						score=p1->score;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	FILE *fp1=fopen("xm.txt","w+");
	while(h){
		fprintf(fp1,"%s %s %.0f\n",h->id,h->name,h->score);
		h=h->next;
	}
	fclose(fp1);
	printf("文件已保存在xm.txt中\n"); 
}
void tj(s *h){
		int i=1;
		s *h1;
	float pj=h->score,max=h->score;
	h1=h->next;
	while(h1){
		pj+=h1->score;
		if(max<h1->score)max=h1->score;
		h1=h1->next;
		i++;
	}
	pj/=i;
	FILE *fp1=fopen("cjtj.txt","w+");
	while(h){
		fprintf(fp1,"%s %s %.0f\n",h->id,h->name,h->score);
		h=h->next;
	}
	fprintf(fp1,"平均分:%.1f\n最高分:%.1f\n",pj,max);
	fclose(fp1);
	printf("结果已保存在cjtj中\n");
}
void td(s *h){
			int i=1;
		s *h1;
	float max1,min;
	printf("请先输入最高分后输入最低分"); 
	scanf("%f%f",&max1,&min);
	while(h){
		if(h->score>max1||h->score<min)h=h->next;
		else break;
	} 
	float pj=h->score,max=h->score;
	h1=h->next;
	while(h1){
		if(h1->score>max1||h1->score<min){
			h1=h1->next;
			continue;
		}
		pj+=h1->score;
		if(max<h1->score)max=h1->score;
		h1=h1->next;
		i++;
	}
	pj/=i;
	FILE *fp1=fopen("tdtj.txt","w+");
	while(h){
		if(h->score>max1||h->score<min){
			h=h->next;
			continue;
		}
		fprintf(fp1,"%s %s %.0f\n",h->id,h->name,h->score);
		h=h->next;
	}
	fprintf(fp1,"平均分:%.1f\n最高分:%.1f\n",pj,max);
	fclose(fp1);
	printf("结果已保存在tdtj中\n");
}
void fb(s *h){
	int t1=0,t2=0,t3=0,t4=0,t5=0;
	while(h){
		if(h->score<59)t1++;
		else if(h->score<69)t2++;
		else if(h->score<79)t3++;
		else if(h->score<89)t4++;
		else t5++;
		h=h->next;
	}
    FILE *fp1=fopen("tj.txt","w+");
	fprintf(fp1,"各分段成绩分布统计如下：\n0~59分:%d人\n60~69分:%d人\n70~79分:%d人\n80~89分:%d人\n90~100分:%d人\n",t1,t2,t3,t4,t5); 
	fclose(fp1);
	printf("结果保存在tj.txt中\n");
}
int main(){
	FILE *fp=fopen("list.txt","r+");
	s *p,*q,*h=NULL;
	while(1){
		p=(s*)malloc(sizeof(s));
		if(fscanf(fp,"%s",p->id)==EOF)break;
		fscanf(fp,"%s%f",p->name,&p->score);
		p->next=NULL;
		if(h==NULL)h=p;
		else q->next=p;
		q=p;
	}
    int n=1;
    printf("请输入0~5进行以下操作：\n1.按成绩降序排序\n2.按姓名升序排序\n3.成绩统计\n4.筛选特定范围成绩统计\n5.成绩分布统计\n0.退出程序");
    while(n!=0){
    	scanf("%d",&n);
    	if(n==1){
    		cj(h);
		}
		if(n==2){
			xm(h);
		}
		if(n==3){
			tj(h);
		}
		if(n==4){
			td(h);
		}
		if(n==5){
			fb(h);
		}
		printf("已执行！"); 
	}
	fclose(fp);
	return 0;
}
