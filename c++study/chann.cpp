#include <iostream>
using namespace std;

int main() {
    int l;
    cin >> l;

    if (l >= 620 && l <= 780) {
        cout << "Red" << endl;
    } else if (l >= 590 && l < 620) {
        cout << "Orange" << endl;
    } else if (l >= 570 && l < 590) {
        cout << "Yellow" << endl;
    } else if (l >= 495 && l < 570) {
        cout << "Green" << endl;
    } else if (l >= 450 && l < 495) {
        cout << "Blue" << endl;
    } else if (l >= 425 && l < 450) {
        cout << "Indigo" << endl;
    } else if (l >= 380 && l < 425) {
        cout << "Violet" << endl;
    }

    return 0;
}
