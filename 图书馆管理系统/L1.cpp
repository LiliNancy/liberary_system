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
extern struct book* head;
struct reader{
	char name[10];
	char non[10];
	char mm[7];
	int bkld[3];
	struct reader* next;
};
extern struct reader* headt;
 
void peoplemenu(void){
	cout << " -------------------------------------" << endl;
	cout << "       1.  ������  "<<endl;
	cout << "       2.  ����Ա  "<<endl;
	cout << "       0.  �˳�ϵͳ  "<<endl;
	cout << " -------------------------------------" << endl; 
}
void menul(void){
	cout << "               �û�ϵͳ               " << endl;
	cout << " -------------------------------------" << endl;
	cout << "       1.  ��ʾ����ͼ������  " << endl;
	cout << "       2.  ����ͼ��  " << endl;
	cout << "       3.  �黹ͼ��  " << endl;
	cout << "       4.  �鼮����       " << endl;
	cout << "       5.  ��ʾ�û�������Ϣ       " << endl;
	cout << "       6.  �������       " << endl;
	cout << "       0.  ����      " << endl;
	cout << " -------------------------------------" << endl;
}
void menug(void){
	cout << "               ����Աϵͳ             " << endl;
	cout << " -------------------------------------" << endl;
	cout << "       1.  ��ʾ����ͼ������  " << endl;
	cout << "       2.  ���ͼ��  " << endl;
	cout << "       3.  ɾ��ͼ��  " << endl;
	cout << "       4.  ��ʼ¼��ͼ�飨������ʹ�ã���ʹԭ����ɥʧ��  " << endl;
	cout << "       5.  �û���Ϣ¼�루�����Σ�  " << endl;
	cout << "       6.  �û���Ϣ��ʾ������й¶��  " << endl;
	cout << "       7.  ���û�ע��      " << endl;
	cout << "       8.  �û����������ʼ��       " << endl;
	cout << "       0.  ����  " << endl;
	cout << " -------------------------------------" << endl;
}
void anykey(){   
	cout << endl << "����������� ......";
	cin.get();
	cin.get();
	cout << endl;
}
struct book* putin(int a){
	struct book* pp,*pr;
	pr=NULL;
	pp=head;
	while(pp!=NULL&&pp->no<a){
		pr=pp;
		pp=pp->next;
	}
	return pr;
}
void add(void){
	struct book* p3,*p99,*p98;
	p3=new struct book;
	cout<<"������ͼ����: ";
	cin>>p3->no;
	cout<<"������ͼ������"; 
	cin>>p3->bkname;
	cout<<"������ͼ�����ߣ�";
	 cin>>p3->zuozhe;
	 cout<<"������ͼ������磺 ";
	cin>>p3->chuban;
	cout<<"������ͼ�������� ";
	cin>>p3->num;
	p3->yx=p3->num;
	int k=p3->no;
	p99=putin(k);
	if(p99==NULL){
		p3->next=head;
		head=p3;
	}
	else{
		p98=p99->next;
		p99->next=p3;
		p3->next=p98;
	}
}
void show1(struct book* l){
	cout<<"�����ˣ� ";
	for(int i=0;i<l->num-l->yx;i++){
		if(l->lender[i][0]!='\0')
		cout<<l->lender[i]<<" ";
	}
	cout<<endl;
}
void show(void){
	struct book* p1;
	p1=head;
	while(p1!=NULL){
		cout<<"No."<<p1->no<<" "<<p1->bkname<<" "<<p1->yx<<endl;
		show1(p1);
		p1=p1->next;
	}
}
void showm(void){
	struct book* p1;
	p1=head;
	while(p1!=NULL){
		cout<<"No."<<p1->no<<" "<<p1->bkname<<" "<<p1->zuozhe <<" "<<endl; 
		cout<<p1->chuban<<"����   "<<p1->yx<<endl;
		p1=p1->next;
	}
}
struct book* bookfind(int k){
	struct book* p0;
	p0=head;
	while(p0!=NULL&&p0->no!=k){
		p0=p0->next;
	}
		return p0;
}
struct book* bkfind(struct book* l){
	struct book* pt;
	pt=head;
	if(pt==l) return NULL;
	while(pt->next!=l){
		pt=pt->next;
	}
	return pt;
}
void dele(void){
	int k;
	cout<<"��������ı��"; 
	cin>>k;
	struct book* p1,*p2,*h;
	h=bookfind(k);
	if(h==NULL) {
		cout<<"�޴���"<<endl;
		return; 
	}
	p1=h->next;
	p2=bkfind(h);
	delete h;
	if(p2!=NULL)
	p2->next=p1;
	else head=p1;
	return;
}
int haveorn( char t[]){
	struct reader *yy;
	yy=headt;
	while(yy!=NULL){
		int i=0;
		for(;i<10;i++){
			if(yy->non[i]!=t[i]) break;
		}
		if(i==10){
			if(yy->bkld[1]==0||yy->bkld[2]==0||yy->bkld[3]==0)
			return 1;
			else return 0;
		} 
		else yy=yy->next;
	}
	return -1;
}
struct reader* rdfd(char a[]);
void lendbk(char ap[] ){
	struct book* h1;
	int bh;
	cout<<"������Ҫ���ĵ���ı��: ";
		cin>>bh;
		h1=bookfind(bh);
	if (h1!=NULL&&h1->yx!=0){
		int as=h1->num-h1->yx;
		for(int i=0;i<10;i++){
			h1->lender[as][i]=ap[i];
		}
		if(haveorn(h1->lender[as])>0){
			h1->yx--;
			struct reader* rd;
			rd=rdfd(h1->lender[as]);
			if(rd->bkld[1]==0) 
				rd->bkld[1]=bh;
			else if(rd->bkld[2]==0) 
				rd->bkld[2]=bh;
			else if(rd->bkld[3]==0) 
				rd->bkld[3]=bh;
			cout<<"���ĳɹ�"<<endl;
		}
		else {
			h1->lender[as][0]='\0';
			cout<<"���ɽ���"<<endl;
		}
	}
	else if(h1!=NULL&&h1->yx==0){
		 cout<<"�����Ѿ�ȫ�����"<<endl;  
	}
	else
	{
	cout<<"�޴���"<<endl; 
	}
}
void bkback(char a[],struct reader * tpyh){
	int k,t;
	cout<<"������黹���ţ�"; 
	cin>>k;
	struct book* pb;
	pb=bookfind(k);
	if(pb==NULL){
		cout<<"��Ŵ���"<<endl;
		return; 
	}
	pb->yx++;
	t=pb->num-pb->yx+1;
	for(int i=0;i<3;i++){
		if(tpyh->bkld[i]==k) {
			tpyh->bkld[i]=0;
			break;
		}
	}
	int i;
	for(i=0;i<t;i++){
		for(int j=0;j<10;j++){
			if(pb->lender[i][j]!=a[j]) break;
			if(pb->lender[i][j]==a[j]&&j==9){
				pb->lender[i][0]='\0';
				break;
			}
		}
		if(pb->lender[i][0]=='\0') break;
	}
	for(;i<t;i++){
		for(int j=0;j<10;j++){
			pb->lender[i][j]=pb->lender[i+1][j];
		}
	}
}
int bknamefd(char k[],int i){
	struct book *pn;
	pn=head;
	while(pn!=NULL){
		int j;
		for(j=0;j<i&&k[j]!='\0'&&pn->bkname[j]!='\0';j++){
			if(k[j]!=pn->bkname[j]) break;
		}
		if(pn->bkname[j]=='\0'&&k[j]=='\0'){
			return pn->no;
		}
		else pn=pn->next;
	}
	return 0;
}
void yhzhuce(void);
void showyh(void);
void showldbk(struct reader* a);
int mmbd(struct reader* t,char a[]);
void mmgg(struct reader* p);

void menulselect(){
	char knm[10],ms[7];
	cout<<"��������ĺţ�";
	cin>> knm;
	cout<<"���������룺";
	cin>>ms; 
	struct reader* ttt;
	ttt=rdfd(knm);
	int yon;
	yon=mmbd(ttt,ms);
	if(yon==0) cout<<"���ĺŻ��������"<<endl;
	while(yon){
		menul();
		int c;
		cout<<"��ѡ��: "; 
		cin>>c;
		switch(c){
			case 1:
				showm();
				anykey();
				break;
			case 2:
				lendbk(knm);
				anykey();
				break;
			case 3:
				bkback(knm,ttt);
				anykey();
				break;
			case 4:
				char k[20];
				int noo;
				cout<<"������Ҫ�����������: "; 
				cin>>k;
				noo=bknamefd(k,20);
				if(noo!=0) cout<<"��"<<k<<"�����Ϊ: "<<noo<<endl;
				else cout<<" �ޡ�"<<k<<"���Ȿ�� "<<endl; 
				anykey();
				break;
			case 5:
				showldbk(ttt);
				anykey();
				break;
			case 6:
				mmgg(ttt);
				anykey();
				return;
			case 0: 
				cout<<endl;
				return;
			default:
				break;
		}
	}
}

int glymm(char z[]){
	char a[7]="123456";
	int f=0;
	for(int i=0;i<6;i++){
		if(a[i]==z[i])f++;
	}
	if(f==6)return 1;
	else return 0;
}

void lurubk(void);
void luruser(void);
void menugselect(){
	int c;
	int toff;
	char z[7];
	cout<<"��������λ����Ա���룺";
	cin>>z;
	toff=glymm(z);
	if(toff==0) cout<<"�������"<<endl;
	while(toff){
		menug();
		cout<<"��ѡ��: "; 
		cin>>c;
		switch(c){
			case 1:
				show();
				anykey();
				break;
			case 2:
				add();
				anykey();
				break;
			case 3:
				dele();
				anykey();
				break;
			case 4:
				lurubk();
				anykey();
				break;	
			case 5:
				luruser();
				anykey();
				break;
			case 6:
				showyh();
				anykey();
				break;
			case 7:
				yhzhuce();
				anykey();
				break;
			case 8:
				struct reader *a;
				char b[10];
				cout<<"�������˺ţ�";
				cin>>b;
				a=rdfd(b);
				for(int i=0;i<6;i++){
					a->mm[i]='1';
				}
				a->mm[6]='\0';
				anykey();
				break; 
			case 0: 
			cout<<endl;
				return;
			default:
				break;
		}
	}
}
void peopleselect(void){
	cout<<"��ܰ��ʾ�������������˳�ϵͳ��ֱ�ӹرմ��������޷�����"<<endl;
	int p;
	while(1){
		peoplemenu();
		cout<<"�����룺 "; 
		cin>>p;
		switch(p){
			case 1:
				menulselect();
				break;
			case 2:
				menugselect();
				break;
			case 0:
				cout<<endl;
				return;
			default:
				break;
		}
	}
}
