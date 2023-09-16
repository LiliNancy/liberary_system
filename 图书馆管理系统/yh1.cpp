#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
struct reader{
	char name[10];
	char non[10];
	char mm[7];
	int bkld[3];
	struct reader* next;
};
const int tt=sizeof(struct reader);
struct reader* headt;
void homesetuser(int n){
	FILE* fp;
	fp=fopen("text1.dat","wb");
	cout<<"ÇëÊäÈëÐÕÃû"<<endl;
	for(int i=0;i<n;i++){
		struct reader p2;
		struct reader *ptr2;
		ptr2=&p2;
		cout<<"ÇëÊäÈëÐÕÃû"<<endl;
		cin>>p2.name;
		cout<<"ÇëÊäÈë±àºÅ"<<endl;
		cin>>p2.non;
		for(int i=0;i<7;i++) p2.mm[i]='0';
		p2.bkld[1]=0; p2.bkld[2]=0; p2.bkld[3]=0;
		fwrite(ptr2,tt,1,fp);
	}
	fclose(fp);
}
void homeuser(void){
	struct reader *p1,*p2,*p3;
	headt=NULL;
	p1=new struct reader;
	p2=new struct reader;
	headt=p2;
	FILE* fp;
	fp=fopen("text1.dat","rb");
	if(fp == NULL) {
		cout << "ÎÄ¼þ´ò¿ªÊ§°Ü £¡" << endl;
		exit(1);
		return;
    }
	while(!feof(fp)){
		int cc=fread(p2,tt,1,fp);
		if(cc==0) break;
		p2->next=p1;
		p3=p2;
		p2=p1;
		p1=new struct reader;
	}
	delete p1;
	delete p2;
	p3->next=NULL;
	fclose(fp);
}
void digitgetuser(void){
	struct reader *p5,*p6;
	p5=headt;
	FILE* fp;
	fp=fopen("text1.dat","wb");
	while(p5!=NULL){
		fwrite(p5,tt,1,fp);
		p6=p5;
		p5=p5->next;
		delete p6;
	}
	fclose(fp);
}
void luruser(void)
{
	int nn;
	cout<<"ÇëÊäÈëÂ¼ÈëÓÃ»§µÄÊýÁ¿£º";
	cin>>nn; 
	homesetuser(nn);
	digitgetuser();
	homeuser();
}
void yhzhuce(void){
	struct reader *ph;
	ph=new struct reader;
	cout<<"ÇëÊäÈëÐÕÃû£¨²»ÒªÌ«³¤£©£º";
	cin>>ph->name;
	cout<<"ÇëÊäÈë½èÔÄºÅ£º";
	cin>>ph->non;
	cout<<"ÇëÊäÈëÁùÎ»ÃÜÂë£º";
	cin>>ph->mm; 
	ph->bkld[1]=0;
	ph->bkld[2]=0;
	ph->bkld[3]=0;
	ph->next=headt;
	headt=ph;
}
void showldbk(struct reader* a); 
void showyh(void){
	struct reader *yh;
	yh=headt;
	while(yh!=NULL){
		cout<<"ÐÕÃû£º"<<yh->name<<" ½èÔÄºÅ£º"<<yh->non<<endl;
		cout<<"ÒÑ½èÔÄÍ¼Êé±àºÅ£º";
		for(int i=0;i<3;i++){
			if(yh->bkld[i]!=0)cout<<yh->bkld[i]<<"   ";
		}
		cout<<endl;
		yh=yh->next;
	}
}
struct reader* rdfd(char a[]){
	struct reader* rd;
	rd=headt;
	while(rd!=NULL){
		int i;
		for(i=0;i<10;i++){
			if(rd->non[i]!=a[i])break;
		}
		if(i==10) return rd;
		else rd=rd->next;
	}
	return NULL; 
}
void showldbk(struct reader* a){
	cout<<"ÐÕÃû£º"<<a->name<<endl;
	cout<<"½èÔÄºÅ£º"<<a->non<<endl;
	cout<<"ÃÜÂë£º"<<a->mm<<endl;
	cout<<"ÒÑ¾­½èÔÄÍ¼Êé±àºÅ£º";
	for(int i=0;i<3;i++){
		if(a->bkld[i]!=0) cout<<a->bkld[i]<<"   ";
	}
	cout<<endl;
}
int mmbd(struct reader* t,char a[]){
	if(t==NULL) return 0;
	int k=0;
	for(int i=0;i<6;i++){
		if(t->mm[i]==a[i])k++;
	}
	if(k==6)return 1;
	else return 0;
}
void mmgg(struct reader* p){
	cout<<"ÇëÊäÈëÐÂµÄÃÜÂë£º";
	cin>>p->mm;
} 
