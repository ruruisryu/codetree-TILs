#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> numbers(n);
    unordered_map<int, int> freq_map;
    
    // 입력받고 빈도 계산
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        freq_map[numbers[i]]++;
    }
    
    // pair<숫자, 빈도수>를 저장하는 벡터
    vector<pair<int, int>> freq_vec;
    
    // freq_map을 freq_vec으로 변환
    for (const auto& entry : freq_map) {
        freq_vec.push_back(entry);
    }
    
    // 정렬 기준: 1) 빈도수 내림차순 2) 숫자 내림차순
    sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;  // 숫자가 클수록 우선
        }
        return a.second > b.second;  // 빈도수가 클수록 우선
    });
    
    // 상위 k개의 숫자 출력
    for (int i = 0; i < k; i++) {
        cout << freq_vec[i].first << " ";
    }
    cout << endl;

    return 0;
}