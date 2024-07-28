#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pos;
#define X first
#define Y second
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int dist[101][101];
pos start, dest;

int main() {
    int n;
    cin >> n >> start.X >> start.Y >> dest.X >> dest.Y;
    start.X--; start.Y--;
    dest.X--; dest.Y--;

    queue<pos> Q;
    dist[start.X][start.Y] = 1;
    Q.push(start);

    while(!Q.empty()){
        pos cur = Q.front(); Q.pop();
        for(int i=0; i<8; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx <0 || nx > n || ny <0 || ny>n) continue;
            if(dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});

            if(nx == dest.X && ny == dest.Y){
                cout << dist[nx][ny]-1;
                return 0;
            }
        }
    }
    cout << dist[dest.X][dest.Y] -1;
}