#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> coor;
#define X first
#define Y second

int board[100][100];
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//뱀이 없는 경우 1, 뱀이 있는 경우 0
int main() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n ; i++){
        for (int j = 0 ;j<m;j++){
            cin >> board[i][j];
        }
        fill(visited[i], visited[i]+m, false);
    }

    queue<coor> Q;
    Q.push({0,0});
    visited[0][0] = true;

    while(!Q.empty()){
        coor cur = Q.front(); Q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >=n || ny <0 || ny>=m) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    cout << static_cast<int>(visited[n-1][m-1]);

}