#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
struct book{
	
	int no;
	char bkname[20];
	char zuozhe[20];
	char chuban[20];
	int num;
	int yx;
	char lender[10][10];
	struct book* next;
};
struct book* head;
void home(void);
void digitget(void);
const int t=sizeof(struct book);
void peopleselect(void); 
struct reader{
	char name[10];
	char non[10];
	char mm[7];
	int bkld[3];
	struct reader*next;
};
const int tt=sizeof(struct reader);
extern struct reader* headt;
void homeuser(void);
void digitgetuser(void);
 
int main(int argc, char** argv) {
	cout<<"如果系统无法正常打开，请使用LRW.cpp,LRYH.cpp进行初始录入"<<endl; //text.dat,text1.dat文件如果为空或没有则不能正常运行 
	home();
	homeuser();
	peopleselect(); 
	digitgetuser();
	digitget();
	
}

void home(void){
	struct book *p1,*p2,*p3;
	head=NULL;
	p1=new struct book;
	p2=new struct book;
	head=p2;
	FILE* fp;
	fp=fopen("text.dat","rb");
	if(fp == NULL) {
		cout << "文件打开失败 ！" << endl;
		exit(1);
		return;
    }
	while(!feof(fp)){
		int cc=fread(p2,t,1,fp);
		if(cc==0) break;
		p2->next=p1;
		p3=p2;
		p2=p1;
		p1=new struct book;
	}
	delete p1;
	delete p2;
	p3->next=NULL;
	fclose(fp);
}
void digitget(void){
	struct book *p5,*p6;
	p5=head;
	FILE* fp;
	fp=fopen("text.dat","wb");
	while(p5!=NULL){
		fwrite(p5,t,1,fp);
		p6=p5;
		p5=p5->next;
		delete p6;
	}
	fclose(fp);
}
