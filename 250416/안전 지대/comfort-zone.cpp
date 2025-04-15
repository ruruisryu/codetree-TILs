#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define VISITED 0

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int x, int y, int k, int n, int m, vector<vector<int>>& board){
    board[x][y] = VISITED;
    for(int i=0; i<4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m){
            continue;
        }

        if(board[new_x][new_y] > k){
            DFS(new_x, new_y, k, n, m, board);
        }
    }
}

int getSafeZoneNum(int n, int m, int k, vector<vector<int>> board){
    int safe_zone_num = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 아직 방문하지 않은 안전 영역이라면 탐색 시작
            if(board[i][j] > k){
                DFS(i, j, k, n, m, board);
                safe_zone_num++;
            }
        }
    }
    return safe_zone_num;
}

int main() {
    int n, m, k;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            k = max(k, board[i][j]);
        }
    }

    int result_k = 0;
    int result_sz_num = 0;
    for(int i=1; i<=k; i++){
        int temp_sz_num = getSafeZoneNum(n, m, i, board);
        if(result_sz_num < temp_sz_num){
            result_k = i;
            result_sz_num = temp_sz_num;
        }
    }
    
    cout << result_k << " " << result_sz_num;
    return 0;
}
