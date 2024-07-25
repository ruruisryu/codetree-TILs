#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> coor;
#define X first
#define Y second

int board[100][100];
bool vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//  숫자 0은 해당 칸이 이동 가능
//  숫자 1은 해당 칸이 이동 불가능
int main() {
    int n, k;
    cin >> n >> k;
    int count = k;

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    queue<coor> Q;
    for(int i=0; i<k; i++){
        int tmpX, tmpY;
        cin >> tmpX >> tmpY;
        tmpX--; tmpY--;
        Q.push({tmpX, tmpY});
        vis[tmpX][tmpY] = true;
    }

    while(!Q.empty()){
        coor cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >=n || ny <0 || ny>=n) continue;
            if(vis[nx][ny] || board[nx][ny] == 1) continue;
            count++;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    cout << count;
}