#include <iostream>
using namespace std;

int main() {

    // 상, 우, 하, 좌
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int n, m;
    int arr[202][202];

    cin >> n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1;j<=m;j++){
            cin >> arr[i][j];
        }
    }


    int max_num = 0;

    for(int i = 1; i<=n;i++){
        for(int j =1; j<=m;j++){
            
   
            //가로줄 탐색
            if(j + 2 <=m){
                int sum = arr[i][j] + arr[i][j+1] +arr[i][j+2];
                max_num = max(sum, max_num);
            }


            // 세로줄 탐색
            if (i + 2 <= n) { 
                int sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
                max_num = max(sum, max_num);
            }
        
            // 4가지의 L자 모양 탐색
            for(int k = 0;k<4;k++){
            
                int sum = arr[i][j];
                
                int nx = i + dx[k];
                int ny = j + dy[k];

                int nx2 = i + dx[(k+1) % 4];
                int ny2 = j + dy[(k+1) % 4];

                if(1 <= nx && nx <= n && 1 <= ny && ny <= m && 1 <= nx2 && nx2 <= n && 1 <= ny2 && ny2 <= m ){
                    sum = sum + arr[nx][ny] + arr[nx2][ny2];
                    max_num = max(sum, max_num);                
                }
            }
        }
    }

    cout<<max_num;    
    return 0;
}