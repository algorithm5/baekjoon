#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left=NULL;
	Node* right=NULL;
};

int count = 0;
Node* root;

int insert(int x, Node *N){
	count++;
	if(N->data>x){
		if(N->left==NULL){
			Node* tmp = new Node;
			tmp->data = x;
			N->left = tmp;
			cout << count << endl;
		} else {
			insert(x, N->left);
		}
	} else {
		if(N->right==NULL){
			Node* tmp = new Node;
			tmp->data = x;
			N->right = tmp;
			cout << count << endl;
		} else {
			insert(x, N->right);
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int tmp;
	
	for(int i=0; i<n; i++){
		cin>>tmp;
		if(i==0){
			root = new Node;
			root->data=tmp;
			cout<<count<<"\n";
		} else {
			insert(tmp, root);	
		}
	}
} 
