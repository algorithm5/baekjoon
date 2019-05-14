#include <iostream>
using namespace std;

int queue[10000], top=-1, point=0;
/*
����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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
		if(s=="push"){
			int val;
			cin>>val;
			queue[++top]=val;
		} else if(s=="front"){
			if(top>=0){
				cout<<queue[point]<<endl;
			} else {
				cout<<-1<<endl;
			}
		} else if(s=="back"){
			if(top>=0){
				cout<<queue[top]<<endl;
			} else {
				cout<<-1<<endl;
			}
		} else if(s=="size"){
			cout<<top+1<<endl;
		} else if(s=="empty"){
			if(top<0) cout<<1<<endl;
			else cout<<0<<endl;
		} else if(s=="pop"){
			if(top>=0){
				cout<<queue[point]<<endl;
				queue[point]=0;
				for(int j=point; j<top; j++){
					queue[j]=queue[j+1];
				}
				top--;
			} else {
				cout<<-1<<endl;
			}
		} else {
			cout<<"Please Check your command"<<endl;
			--i;
		}
	}
	return 0;
}
/*
15
push 1
push 2
front
back
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
front
*/
