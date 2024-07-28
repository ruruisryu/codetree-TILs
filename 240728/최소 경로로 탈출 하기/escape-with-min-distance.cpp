#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pos;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool board[100][100];
int dist[100][100];

int main() {
    // 입력
    int n, m;
    cin >> n >> m;

    for(int i=0 ;i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    queue<pos> Q;
    dist[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        pos cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<0 || nx>n || ny<0 || ny>n) continue;
            if(dist[nx][ny] != 0 || board[nx][ny] == 0)continue;
            dist[nx][ny] = dist[cur.X][cur.Y] +1;
            Q.push({nx, ny});
        }
    }


    cout << dist[n-1][m-1]-1;
}