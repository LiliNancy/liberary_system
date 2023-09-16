#include<iostream>
using namespace std;
template <class T>
struct one{
	T a;
	one<T> next;
};
template <class T>
class caculate{
	private:
		one<T>* head;
		int num;
	public:
		caculate(){
			head=NULL;
			num=0;
		}
		void push(T pp){
			one<T>*pt;
			pt=new one<T>;
			pt->a=pp;
			pt->next=head;
			head=pt;
		}
		T pop(){
			if(head==NULL) return NULL;
			one<T>* pt=head;
			head=head->next;
			T ap=pt->a;
			delete pt;
			return ap;
		}
}; 
int main(){                            //5+(6-4/2)*3  5+1*3-4
	class caculate<char> numb,sign;
	string tr;
	cin>>tr;
}
