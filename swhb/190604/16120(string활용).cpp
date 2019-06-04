#include <iostream>
using namespace std;

int main(void){
	string s;
	cin >> s;
	if(s.size()<4){
		cout << "NP" << endl;
	} else {
		cout << "TEST = " << s << endl;
		while(s.find("PPAP")!=string::npos){
			int lo = s.find("PPAP");
			cout << "LO = " << lo << endl;
			cout << "TEST = " << s << endl;
			s.erase(lo,3);
		}
		if(s=="P"){
			cout << "PPAP" << endl;
		} else {
			cout << "NP" << endl;
		}
	}
}
