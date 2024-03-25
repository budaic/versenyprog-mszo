#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/698/A
// feladatra a BRUTE-FORCE megoldas

int n; // napok szama
vector<int> a; // adott napon lehetseges aktivitasok szama

// nap_ind - az adott nap indexe
// elozo_napi_aktivitas - 	0 = semmi nem volt
//							1 = programozott
//							2 = edzett
// a fuggveny a maximalisan aktivan toltott napok szamat mondja meg a nap_ind naptol kezdve (azt is beleszamitva)
int megold(int nap_ind, int elozo_napi_aktivitas=0){
	if(nap_ind == n) return 0; // vege a hetnek

	bool van_verseny = a[nap_ind] == 1 || a[nap_ind] == 3;
	bool van_edzes = a[nap_ind] == 2 || a[nap_ind] == 3;

	int legtobb_nap_aktiv = 0;

	// nem csinalt semmit elozo napon, meg barmit csinalhat
	if(elozo_napi_aktivitas == 0){
		// van_verseny 0 erteket vesz fel, ha nincs verseny, igy az aktivitas is 0 lesz es az aktiv napok szama sem no
		// hasonlo a helyzet az edzesnel, viszont ott oda kell figyelni, hogy az elozo napi aktivitas megfelelo legyen
		// viszont, ha van verseny, akkor 1 erteket vesz fel es igy kijon minden
		legtobb_nap_aktiv = max(legtobb_nap_aktiv, megold(nap_ind+1, van_verseny) + van_verseny); 
		legtobb_nap_aktiv = max(legtobb_nap_aktiv, megold(nap_ind+1, van_edzes*2) + van_edzes);
	}
	// programozott elozo napon, szoval csak edzeni tud mar
	else if(elozo_napi_aktivitas == 1){
		legtobb_nap_aktiv = max(legtobb_nap_aktiv, megold(nap_ind+1, van_edzes*2) + van_edzes);
	}
	// edzett az elozo napon, szoval mar csak programozni tud
	else{
		legtobb_nap_aktiv = max(legtobb_nap_aktiv, megold(nap_ind+1, van_verseny) + van_verseny);
	}

	// kompaktabb megoldas:
	legtobb_nap_aktiv = 0;
	legtobb_nap_aktiv = max(legtobb_nap_aktiv, (megold(nap_ind+1, van_verseny) + van_verseny)*(!elozo_napi_aktivitas || elozo_napi_aktivitas == 2));
	legtobb_nap_aktiv = max(legtobb_nap_aktiv, (megold(nap_ind+1, van_edzes*2) + van_edzes)*(!elozo_napi_aktivitas || elozo_napi_aktivitas == 1));
	return legtobb_nap_aktiv;
}

int main() {
	cin >> n;
	a.resize(n);
	for(auto &x : a) cin >> x;

	// brute-force megoldas a feladatra:
	// rekurzivan kivalasztunk az lehetosegek kozul egyet az adott napon es 
	// tovabblepunk a kovetkezo napra
	// igy kiprobalgatjuk az osszes lehetseges hetet

	cout << n-megold(0) << "\n";



}
