#include<iostream>
using namespace std;
void home(void);
void digitget(void);
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
const int t=sizeof(struct book);
void homeset(int n){
	FILE* fp;
	fp=fopen("text.dat","wb");
	 
	for(int i=0;i<n;i++){
		struct book p2;
		struct book *ptr2;
		ptr2=&p2;
		cout<<"������ͼ����: ";
		cin>>p2.no;
		cout<<"������ͼ����: ";
		cin>>p2.bkname;
		cout<<"������ͼ������: ";
		cin>>p2.zuozhe;
		cout<<"������ͼ�������: ";
		cin>>p2.chuban;
		cout<<"������ͼ������: ";
		cin>>p2.num;
		p2.yx=p2.num;
		for(int i=0;i<10;i++){
			p2.lender[i][0]='\0';
		}
		fwrite(ptr2,t,1,fp);
	}
	fclose(fp);
}
void lurubk(void)
{
	int n;
	cout<<"������¼�����������";
	cin>>n; 
	homeset(n);
	digitget();
	home();
}
