#include <iostream>
using namespace std;

int stack[10000], top=-1;

/*
*
���� 
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
int main(){
	int n=0;
	cin>>n;
	for(int i=0; i<n; ++i){
		string s;
		cin>>s;
		if(s== "push"){
			int val;
			cin>>val;
			stack[++top]=val;
		} else if(s=="top"){
			if(top>=0) cout<<stack[top]<<endl;
			else cout << -1 << endl;
		} else if(s=="size"){
			cout<<top+1<<endl;
		} else if(s=="empty"){
			if(top>=0) cout<<0<<endl;
			else cout<<1<<endl;
		} else if(s=="pop"){
			if(top>=0){
				cout<<stack[top]<<endl;
				stack[top]=0;
				--top;
			} else cout<<-1<<endl;
			
		} else {
			cout<<"Please Check your command"<<endl;
			--i;
		}
		
	}
	return 0;
}
/*
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top

7
pop
top
push 123
top
pop
top
pop
*/
