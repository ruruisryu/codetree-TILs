#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];

int answer = 0;

void DFS(int v, vector<vector<int>>& graph, vector<bool>& visited){
    for(int curr_v : graph[v]){
        if(!visited[curr_v]){
            visited[curr_v] = true;
            answer++;
            DFS(curr_v, graph, visited);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }

    // Please write your code here.

    // 인접리스트
    vector<vector<int>> graph(n+1, vector<int>());

    // 방문 기록 벡터
    vector<bool> visited(n+1, false);

    // 인접리스트 채우기
    for(int i=0; i<10000; i++){
        graph[from[i]].push_back(to[i]);
        graph[to[i]].push_back(from[i]);
    }

    visited[1] = true;
    DFS(1, graph, visited);

    cout << answer;

    return 0;
}
