#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];

// 인접리스트
vector<vector<int>> graph(n+1, vector<int>());

// 방문 기록 벡터
vector<bool> visited(n+1, false);

int answer = 0;

void DFS(int v){
    for(int curr_v : graph[v]){
        if(visited[curr_v]) continue;

        visited[curr_v] = true;
        answer++;
        DFS(curr_v);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // Please write your code here.

    // 인접리스트 채우기
    for(int i=0; i<10000; i++){
        graph[from[i]].push_back(to[i]);
    }

    DFS(1);

    cout << answer;

    return 0;
}
