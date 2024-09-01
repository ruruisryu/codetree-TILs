#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    unordered_map<int, int> num_count;
    int pair_count = 0;

    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // 각 숫자를 순회하며 두 수의 합이 k가 되는 쌍을 찾기
    for (int i = 0; i < n; i++) {
        int target = k - numbers[i];  // numbers[i]와 더해서 k가 되어야 하는 숫자
        
        // target 숫자가 이미 등장했다면 쌍을 만들 수 있음
        if (num_count[target] > 0) {
            pair_count += num_count[target];  // 쌍의 개수 추가
        }
        
        // 현재 숫자의 등장 횟수를 기록
        num_count[numbers[i]]++;
    }

    // 결과 출력
    cout << pair_count << endl;

    return 0;
}