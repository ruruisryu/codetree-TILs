#include <iostream>
#include <vector>

using namespace std;

#define SNAKE 0
#define EMPTY 1
#define VISITED 2

// 방향 배열
int dx[] = {1, 0};
int dy[] = {0, 1};

// x, y 현재 체크하고 있는 칸의 인덱스
void DFS(int x, int y, int n, int m, vector<vector<int>>& board)
{
    board[x][y] = VISITED;
    for(int i = 0; i<2; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        // 만약 보드 밖의 좌표라면 continue;
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m){
            continue;
        }
        // 방문한적없고 뱀이 존재하지 않는 칸이라면 탐색
        if(board[new_x][new_y] == EMPTY){
            DFS(new_x, new_y, n, m, board);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    
    // 입력을 받은 배열을 방문 체크 용도로도 사용
    // 갈 수 있는 길 : 0
    // 뱀이 있는 길 : 1
    // 이미 지나간 길 : 2
    vector<vector<int>> board(n, vector<int>(m, 0));

    // 입력
    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            cin >> board[i][j];
        }
    }

    // 연산
    DFS(0, 0, n, m, board);

    // 출력
    if(board[n-1][m-1] == 2){
        cout << 1;
    }
    else{
        cout << 0;
    }

    return 0;
}
