/* C++
입력
cin 사용
예) cin >> var;
출력
cout 사용
예) cout << var;
필수 라이브러리 iostream
권장사항
using namespace std;
ios::sync_with_stdio(false);
cin.tie(NULL);

홍익대학교는 1946년에 개교하였다.

특정 년도가 주어졌을 때, 그 해가 개교 몇 주년인지 출력하라. */

#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int year;
    cin >> year;
    cout << year - 1946 <<endl;

}