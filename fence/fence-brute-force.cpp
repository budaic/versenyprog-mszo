#include <iostream>
#include <vector>

using namespace std;

// A brute force megoldas a masodik versenyfeladatra

// n a kerites hossza, k a kiszedendo rudak szama
int n, k;
// h_i az i-edik rud magassaga
vector<int> h;

// Ez a fuggveny megadja, hogy mennyi a rud-hosszak osszege a megadott elso rudtol az utolsoig:
// h[elso]+h[elso+1]+...+h[utolso]
int s(int start) {
    int osszeg = 0;
    for(int j=start;j<=start+k-1;j++) {
        osszeg+=h[j];
    }
    return osszeg;
}

int main() {
    // beolvasas
    cin >> n >> k;
    h.resize(n);
    for(int i=0;i<n;i++) {
        cin >> h[i];
    }

    // Kereso
    // min_pos az addigi legjobb lely, min_val az ottani ertek
    int min_pos = 0;
    int min_val = s(0);
    int val;
    for(int i=1;i<n-k+1;i++) {
        // Megnezi hogy i poziciobol nezve a kovetkezo k helyen mennyi lesz az oszlopok hosszanak osszege
        val = s(i);
        // Ha kevesebb mint az eddigi legjobb, akkor itt erdemesebb atvinni a zongorat
        if(val<min_val){
            min_pos = i;
            min_val = val;
        }
    }

    cout << min_pos+1 << endl;

    // Time limit exceeded lesz!!

    return 0;
}