#include <iostream>
using namespace std;

int main() {
    string w;
    cin >> w;

    if (w == "M") {
        cout << "MatKor" << endl;
    }
    else if (w == "W") {
        cout << "WiCys" << endl;
    }
    else if (w == "C") {
        cout << "CyKor" << endl;
    }
    else if (w == "A") {
        cout << "AlKor" << endl;
    }
    else if (w == "$") {
        cout << "$clear" << endl;
    }

    return 0;
}
