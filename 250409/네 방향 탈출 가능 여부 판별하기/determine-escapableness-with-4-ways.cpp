#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SNAKE 0
#define EMPTY 1
#define VISITED 2

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

typedef pair<int, int> pi;
#define X first
#define Y second

void BFS(int n, int m, vector<vector<int>>& board){
    // BFS 탐색을 위한 큐 선언
    queue<pi> q;
    // 시작 칸을 큐에 넣고 방문 처리
    q.push({0,0});

    while(!q.empty()){
        pi curr_pi = q.front(); q.pop();
        board[curr_pi.X][curr_pi.Y] = VISITED;
        for(int i=0; i<size(dx); i++){
            int x = curr_pi.X + dx[i];
            int y = curr_pi.Y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= m){
                continue;
            }
            if(board[x][y] == EMPTY){
                q.push({x, y});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));
    
    // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    // 연산
    BFS(n, m, board);

    // 출력
    if(board[n-1][m-1] == 2){
        cout << 1;
    }
    else{
        cout << 0;
    }


    return 0;
}
