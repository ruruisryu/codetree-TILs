#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

enum Space {
    Blank,
    Block,
    Visited
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int BFS(int n, int x, int y, vector<vector<int> > &board) {
    // 현재 인덱스에서 방문이 가능한 다른 칸의 수
    int count = 0;

    // BFS 탐색을 위한 큐 선언
    queue<pi> q;
    q.push({x, y});
    if (board[x][y] == Blank) {
        count++;
        board[x][y] = Visited;
    }

    while (!q.empty()) {
        pi curr_pi = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            auto [X, Y] = curr_pi;
            int new_x = X + dx[i];
            int new_y = Y + dy[i];

            // 새로 체크하는 칸이 보드 내에 있고,
            // 아직 방문하지 않은 칸이라면,
            // count를 1증가 시키고, 방문했다고 표시한 뒤, 큐에 넣는다.
            if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
                continue;
            }
            if (board[new_x][new_y] == Blank) {
                count++;
                board[new_x][new_y] = Visited;
                q.push({new_x, new_y});
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    int answer = 0;
    cin >> n >> k;

    vector<vector<int> > board(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산
    while (k--) {
        int x, y;
        cin >> x >> y;
        answer += BFS(n, x - 1, y - 1, board);
    }

    // 출력
    cout << answer;

    return 0;
}
