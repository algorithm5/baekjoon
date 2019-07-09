#include <iostream>
using namespace std;
int map[100][100], rev_map[100][100];
int n,l, res;

void check(int row, int a[100][100]) {
    bool c[101] = { false, };
    int temp = a[row][0];
    for (int i = 0; i < n; i++) {
        if (a[row][i] != temp) {
            if (abs(a[row][i] - temp) > 1) {
				return; 
			}
            if (a[row][i] < temp) { 
                int num = -1;
                for (int j = i; j <= i + l - 1; j++) {
                    if (j >= n || c[j]) return;
                    c[j] = true;
                    if (num == -1) {
                        num = a[row][j];
                        continue;
                    }
                    if (num != -1 && a[row][j] != num) return;
                }
                i = i + l - 1;
                if (i >= n){
                	break;
				} 
            }
            else { 
                int num = -1;
                for (int j = i - 1; j >= i - l; j--) {
                    if (j < 0 || c[j]) return;
                    c[j] = true;
                    if (num == -1) {
                        num = a[row][j];
                        continue;
                    }
                    if (num != -1 && a[row][j] != num) {
                    	return;
					}
                }
            }
            temp = a[row][i];
        }
    }
    ++res;
}
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>l;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>map[i][j];
			rev_map[j][i] = map[i][j];
		}
	}
	  for (int i = 0; i < n; i++) {
        check(i, map);
        check(i, rev_map);
    }
    cout << res << endl;
}
