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
	fp=fopen("text1.dat","w");
	cout<<"请输入姓名,编号"<<endl;
	for(int i=0;i<n;i++){
		struct reader p2;
		struct reader *ptr2;
		ptr2=&p2;
		cin>>p2.name>>p2.non;
		for(int i=0;i<6;i++) p2.mm[i]='1';
		p2.bkld[1]=0; p2.bkld[2]=0; p2.bkld[3]=0;
		fwrite(ptr2,tt,1,fp);
	}
	fclose(fp);
}
int main()
{
	int nn;
	cout<<"请输入录入用户的数量：";
	cin>>nn; 
	homesetuser(nn);
}
