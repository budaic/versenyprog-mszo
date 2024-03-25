#include <iostream>
#include <vector>

using namespace std;

// A trukkos megoldas a masodik versenyfeladatra - prefix sum-al
// Az algoritmus lenyege, hogy nem nezzuk vegig az osszeget, csak megnezzuk, hogy mennyivel valtozik
// Mondjuk ezek a hosszak: (harmasaval nezzuk majd)
// 1 2 5 3 4 5 6
// Ekkor az elso osszeg x (=1+2+5=8)
// A masodikbol ez elso hianyzik, es a 4. jut be, tehat az osszeg: x-1+4=x+3 (=11)



// n a kerites hossza, k a kiszedendo rudak szama
int n, k;
// h_i az i-edik rud magassaga
vector<int> h;

int main() {
    // beolvasas
    cin >> n >> k;
    h.resize(n);
    for(int i=0;i<n;i++) {
        cin >> h[i];
    }

    // Kiszamolja az elso helyre az osszeget
    int elso_osszeg = 0;
    for(int j=0;j<k;j++) {
        elso_osszeg+=h[j];
    }

    // Legjobb kell az osszeghez
    int min_hely = 0;
    int min_osszeg = elso_osszeg;
    // Mennyivel volt a kulonbseg az elozo hely es a legjobb kozott
    int osszeg_most = elso_osszeg;
    // Mennyit fog valtozni?
    int delta = 0;

    // vegigmegy
    for(int i=1;i<n-k+1;i++) {
        // Kiszamoja, hogy mennyi lesz a valtozas az elozohoz kepest, ugye egy elemet kiveszunk es egyet berakunk, ugyhogy ez azoknak a kulonbsege lesz
        delta = h[i+k-1]-h[i-1];
        // Igy kevesebb szamolassal megvan, hogy mi az osszeg i helyen
        osszeg_most+=delta;
        if (osszeg_most<min_osszeg){
            min_osszeg=osszeg_most;
            min_hely = i;
        }
    }
    
    // 1-el el kell tolnunk, mert az indexeles 0-tol van, de a feladat emberi indexeket var el
    cout << min_hely+1 << endl;

    // Ez mar vegigfut, mert sokkal hatekonyabb algoritmus:)

    return 0;
}