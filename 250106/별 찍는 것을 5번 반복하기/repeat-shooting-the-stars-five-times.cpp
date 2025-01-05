#include <iostream>

using namespace std;

void PrintTenStar(){
    for(int i=0; i<10; i++){
        cout << "*";
    }
    cout << "\n";
}

int main() {
    // Write your code here!
    for(int i=0; i<5; i++){
        PrintTenStar();
    }
    return 0;
}