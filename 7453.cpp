#include <iostream>
#include <algorithm>
using namespace std;
long long AB[4000*4000], CD[4000*4000];

int main(void){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); //실행속도 향상
	
	long A[4000] = {0,};
	long B[4000] = {0,};
	long C[4000] = {0,};
	long D[4000] = {0,};

	int t=0;
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}
	
	int index = 0;
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			AB[index] = A[i]+B[j];
			CD[index++] = C[i]+D[j];
		}
	}
	
	sort(CD, CD + t*t);
	
	long long cnt = 0;
    long left = 0, right = t*t;
 
    for (int i = 0; i < t * t; i++) {    
 
        while (left < right) {
            long long mid = (left + right) / 2;
            if (AB[i] + CD[mid] < 0) left = mid + 1;
            else right = mid;
        }
        long lower_bound = right;
        left = 0, right = t*t;
 
        while (left < right) {
            long long mid = (left + right) / 2;
 
            if (AB[i] + CD[mid] <= 0) left = mid + 1;
            else right = mid;
        }
        long upper_bound = right;
 
        cnt += upper_bound - lower_bound;
        left = 0, right = t*t;
    }
    cout<<cnt<<endl;
}
