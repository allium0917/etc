#include <iostream>
#include <cstring>
#define SIZE 50
using namespace std;

int main() {
    int n;
    char s[SIZE];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;

        if (strcmp(s, "Algorithm") == 0)
            cout << "204" << endl;
        else if (strcmp(s, "DataAnalysis") == 0)
            cout << "207" << endl;
        else if (strcmp(s, "ArtificialIntelligence") == 0)
            cout << "302" << endl;
        else if (strcmp(s, "CyberSecurity") == 0)
            cout << "B101" << endl;
        else if (strcmp(s, "Network") == 0)
            cout << "303" << endl;
        else if (strcmp(s, "Startup") == 0)
            cout << "501" << endl;
        else if (strcmp(s, "TestStrategy") == 0)
            cout << "105" << endl;
    }

    return 0;
}
