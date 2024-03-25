#include <iostream>

using namespace std;

// Akkor tudujuk elosztani ket parosba, hogyha paros a bemenet, es tobb mint ketto, mert 2-t csak 1-1, 0-2-be tudunk elosztani, ami nem jo.

int main() {
    int i;
    cin >> i;
    if (i%2==0 && i>2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}