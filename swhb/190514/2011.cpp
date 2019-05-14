#include <iostream>
#include <string>
using namespace std;
#define mod 1000000
int main(void){
 
    char secret[5001];
    int secretSize;
    int Dp[5010] = {};
    Dp[0] = 1;
    Dp[1] = 1;
    string s;
    scanf("%s", secret);
    s = secret;
    secretSize = s.size();
 
    for (int i = 2; i <= secretSize; i++)
    {
        int now = i - 1;
        if (secret[now] > '0')
            Dp[i] = Dp[i - 1] % mod;
 
        int x = (secret[now- 1]-'0') * 10 + secret[now]-'0';
        
        if (10 <= x && x <= 26)
            Dp[i] = (Dp[i] + Dp[i - 2]) % mod;
    }
    
    printf("%d\n", Dp[secretSize]);
 
}



