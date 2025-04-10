#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구해야하는 것: 마을의 개수, 마을에 있는 사람의 수 (오름차순으로 정렬)
// 벽 : 0
// 사람 : 1 

/*
    이차원 벡터를 돌면서, DFS로 마을에 있는 사람의 수를 찾음, 
    온전한 DFS의 시행횟수가 마을의 개수
*/

enum Space{
    Wall,
    Person,
    Visited
};

int people = 1;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int n, int x, int y, vector<vector<int>>& board){
    // 방문 체크
    board[x][y] = Visited;
    
    for(int i=0; i<size(dx); i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        // 보드 밖을 나간다면 탐색하지 않음
        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n){
            continue;
        }

        // 해당 칸이 Person이라면 마을 내 사람 수를 1증가시키고 해당칸 DFS 탐색
        if(board[new_x][new_y] == Person){
            people++;
            DFS(n, new_x, new_y, board);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n,0));
    vector<int> people_num;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    // 이차원 벡터를 돌면서 마을 찾기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == Person){
                DFS(n, i, j, board);
                people_num.push_back(people);
                people = 1;
            }
        }
    }

    // 출력
    sort(people_num.begin(), people_num.end());
    cout << people_num.size() << '\n';

    for(int people : people_num){
        cout << people << '\n';
    }
}
