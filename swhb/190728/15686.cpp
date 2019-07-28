#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[51][51];
bool isused[14];

vector<pair<int, int>> chicken;
vector<pair<int, int>> person;

void Dfs(int cur_num, int cur_cnt){
    if (cur_num > chicken.size()) return;

    if (cur_cnt == m){
        int cmp = 0;
        for (int i = 0; i < person.size(); i++){
            int dist = 9999;
            for (int j = 0; j < chicken.size(); j++){
                if (isused[j]){
                    int px = person[i].first, py = person[i].second;
                    int samx = chicken[j].first, samy = chicken[j].second;
                    int d = abs(px - samx) + abs(py - samy);
                    dist = min(dist, d);
                }
            }
            cmp += dist;
        }
        ans = min(ans, cmp);
        return;
    }

    isused[cur_num] = 1;
    Dfs(cur_num + 1, cur_cnt + 1);
    
    isused[cur_num] = 0;
    Dfs(cur_num + 1, cur_cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
            if (map[i][j] == 1)
                person.push_back(make_pair(i, j));
            else if (map[i][j] == 2)
                chicken.push_back(make_pair(i, j));
        }
    }

    ans = 9999;
    Dfs(0, 0);

    cout << ans << '\n';

    return 0;
}
