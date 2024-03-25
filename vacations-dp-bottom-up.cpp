#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/698/A
// feladatra a megoldas dinamikus programozassal

int n; // napok szama
vector<int> a; // adott napon lehetseges aktivitasok szama
vector<vector<int>> dp; // dp[i][j] = -1, ha meg nem szamoltuk ki
//									= megold(nap_ind=i, elozo_napi_aktivitas=j), ha mar kiszamoltuk

// nap_ind - az adott nap indexe
// elozo_napi_aktivitas - 	0 = semmi nem volt
//							1 = programozott
//							2 = edzett
// a fuggveny a maximalisan aktivan toltott napok szamat mondja meg a nap_ind naptol kezdve (azt is beleszamitva)

int main() {
	cin >> n;
	a.resize(n);
	// beolvasas
	for(auto &x : a) cin >> x;

	// a top-down verziohoz kepest, ahol a rekurziv hivasok idejet is ki kellett varni gyorsabb a bottom-up modszer
	// azonban sokszor nehezebb leprogramozni
	// lenyege annyi, hogy amig a sima top-down-ban rekurziv hivas utan kapjuk meg a reszproblemara a megoldast
	// azonban, ha megfelelo sorrendben dolgoznank fel a reszproblemakat, akkor nem lenne szukseg rekurzivitasra
	dp.assign(n+1, vector<int>(3, 0));
	for(int nap_ind = n-1; nap_ind >= 0; nap_ind--){
		for(int elozo_napi_aktivitas = 0; elozo_napi_aktivitas <= 2; elozo_napi_aktivitas++){
			bool van_verseny = a[nap_ind] == 1 || a[nap_ind] == 3;
			bool van_edzes = a[nap_ind] == 2 || a[nap_ind] == 3;
			int legtobb_nap_aktiv = 0;
			legtobb_nap_aktiv = max(legtobb_nap_aktiv, (dp[nap_ind+1][van_verseny] + van_verseny)*(!elozo_napi_aktivitas || elozo_napi_aktivitas == 2));
			legtobb_nap_aktiv = max(legtobb_nap_aktiv, (dp[nap_ind+1][van_edzes*2] + van_edzes)*(!elozo_napi_aktivitas || elozo_napi_aktivitas == 1));
			dp[nap_ind][elozo_napi_aktivitas] = legtobb_nap_aktiv;
		}
	}

	// kiirjuk a megoldast
  	// azert vonjuk ki dp[0][0]-t n-ből, mert dp[0][0] a maximalisan aktivan toltott napok szama
  	// es nekunk a minimalisan pihenessel toltott napok szama kell
	cout << n-dp[0][0] << "\n";
}
