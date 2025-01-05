#include <iostream>

using namespace std;

int n, m;

void Swap(int& n, int& m){
    int temp = n;
    n = m;
    m = temp;
}

int main() {
    cin >> n >> m;
    Swap(n, m);
    cout << n << " " << m;

    return 0;
}