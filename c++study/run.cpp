#include <iostream>
using namespace std;

int main() {
    int first, second, third, fourth;
    int can;
    cin >> first >> second >> third >> fourth;
    int sum = first + second + third + fourth;
    if (1800-sum > 300) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}