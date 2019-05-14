/*
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��		256 MB		10378	5292	4468		53.909%

����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. �Ѥ� �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include <iostream>
using namespace std;
int deque[10000], front=-1;
int main(){
	int n=0;
	cin>>n;	
	for(int i=0; i<n && n>1 && n<=10000; i++){
		string s;
		cin>>s;
		if(s=="push_front"){
			// �պκ� ����
			int val;
			cin>>val;
			for(int i=front+1; i>0; i--){
				deque[i] = deque[i-1];
			}
			deque[0] = val;
			++front;
		} else if(s=="push_back"){
			int val;
			cin>>val;
			deque[++front] = val;
			// �޺κ� ���� 
		} else if(s=="pop_front"){
			if(front>=0){
				cout<<deque[0]<<endl;
				for(int j=0; j<front;j++){
					deque[j]=deque[j+1];
				}
				--front;
			} else cout<<-1<<endl;
			// �պκ� ���� 
		} else if(s=="pop_back"){
			if(front>=0){
				cout<<deque[front]<<endl;
				deque[front]=0;
				--front;
			} else  cout<<-1<<endl;
			// �޺κ� ���� 
		} else if(s=="size"){
			if(front>-1){
				cout<<front+1<<endl;
			} else {
				cout<<0<<endl;
			}
		} else if(s=="empty"){
			if(front>-1){
				cout<<0<<endl;
			} else {
				cout<<1<<endl;
			}
		} else if(s=="front"){
			if(front>-1){
				cout<<deque[0]<<endl;
			}else {
				cout<<front<<endl;
			}
		} else if(s=="back"){
			if(front>-1){
				cout<<deque[front]<<endl;
			}else {
				cout<<front<<endl;
			}
		} else {
			cout<<"Please Check your command"<<endl;
			--i;
		}
	}
}

/*
���� �Է� 1 
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front

���� ��� 1 
2
1
2
0
2
1
-1
0
1
-1
0
3

���� �Է� 2 
22
front
back
pop_front
pop_back
push_front 1
front
pop_back
push_back 2
back
pop_front
push_front 10
push_front 333
front
back
pop_back
pop_back
push_back 20
push_back 1234
front
back
pop_back
pop_back

���� ��� 2 
-1
-1
-1
-1
1
1
2
2
333
10
10
333
20
1234
1234
20
*/
