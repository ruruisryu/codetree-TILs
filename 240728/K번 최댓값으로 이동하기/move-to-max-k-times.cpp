#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pos;
#define X first
#define Y second

int n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
vector<vector<bool>> vis(101, vector<bool>(101, false));
pos cur;

pos updateNextPos(pos curP, pos newP){
    if(board[newP.X][newP.Y] == board[curP.X][curP.Y]){
        if(newP.X == curP.X){
            pos result = newP.Y > curP.Y ? curP : newP;
            return result;
        }
        pos result = newP.X > curP.X ? curP : newP;
        return result; 
    }
    pos result = board[newP.X][newP.Y] < board[curP.X][curP.Y] ? curP : newP;
    return result;
}

pos getNextPos(pos start){
    pos next = {0, 0};                  // 다음에 갈 좌표를 담고 있는 변수
    int sNum = board[start.X][start.Y]; // start좌표의 숫자
    int nNum = 0;                       // next좌표의 숫자
    queue<pos> Q;
    Q.push(start);
    vis[start.X][start.Y] = true;

    while(!Q.empty()){
        pos cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;      // 보드 밖 좌표일 경우 무시
            if(vis[nx][ny] || board[nx][ny] >= sNum) continue;       // 이미 방문했거나 조건에 따라 갈 수 없는 좌표인 경우 무시
            vis[nx][ny] = true;     // 방문 처리
            Q.push({nx, ny});       // 큐에 넣어주기
            // next 업데이트 
            next = updateNextPos(next, {nx, ny});
        }
    }
    return next;
}

int main() {
    // 입력
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    cin >> cur.X >> cur.Y;

    // BFS
    for(int i=0; i<k; i++){
        pos tmp = getNextPos(cur);
        if(tmp.X == 0) break;
        cur = tmp;
        vis.assign(101, vector<bool>(101, false));
    }

    //출력
    cout << cur.X << " " << cur.Y;
}