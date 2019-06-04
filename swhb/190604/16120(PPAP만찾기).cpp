#include <iostream>
using namespace std;
int t;
char tmp[1000003];
string s;

bool calcPPAP () {
    if (t < 4) return false;
    if (tmp[t-4]=='P'&&tmp[t-3]=='P'&&tmp[t-2]=='A'&&tmp[t-1]=='P') return true;
    return false;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	t=0;
	for(int i=0; i<s.size(); i++){
		tmp[t] = s[i];
		t++;
		while(calcPPAP()){
			t-=4;
			tmp[t] = 'P';
			t++;
		}
	}
	if(t==1 && tmp[0]=='P'){
		cout << "PPAP" << endl;
	} else {
		cout << "NP" << endl;
	}
}
