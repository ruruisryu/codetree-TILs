#include <iostream>
#include <unordered_map>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
int N, arr[4][5001],ans;
int main() {
    fastio;
    cin>>N;
    for(int i=0; i<4; i++){
        for(int j=0; j<N; j++)
            cin>>arr[i][j];
    }
    unordered_map<int, int>umab, umcd;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            umab[arr[0][i] + arr[1][j]] += 1;
            umcd[arr[2][i] + arr[3][j]] += 1;
        }
    for(auto e = umab.begin(); e!=umab.end(); e++){
        auto umcditer = umcd.find(-1 * e->first);
        if(umcditer != umcd.end()){
            //cout<<e->first<<' '<<umcditer->first<<endl;
            ans += e->second * umcditer->second;
        }
    }
    cout<<ans;
    return 0;
}