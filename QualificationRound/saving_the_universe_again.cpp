//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// convert int to string
string itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

void find(string& P, int& delta, int& index) {
	delta = 1;
	bool flag = false;
	for (int i = P.size() - 1; i >= 0; i--) {
		if (P[i] == 'C' && flag) delta <<= 1;
		else if (!flag && P[i] == 'S' && P[i - 1] == 'C') {
			index = i;
			flag = true;
		}
	}
}

int save_the_universe(int D, string& P) {
	int dmg_power = 1; // initial laser power
	int resulting_dmg = 0; // damage done by the robot's program before hacking it
	int n_c = 0; // number of charging in program
	int n_s = 0; // number of shooting in program
	// gather some intel
	for (int i = 0; i < P.size(); i++) {
		if (P[i] == 'S') {
			resulting_dmg += dmg_power;
			n_s++;
		}
		else {
			dmg_power <<= 1; // speedy way to increase by 2 ^^ (not so readable though xD)
			n_c++;
		}
	}
	if (n_s > D) return -1; // universe is doomed!
	else if (resulting_dmg <= D) return 0; // no hacks needed...
	else { // see how many hacks we need
		int delta = 1;
		int index = -1;
		int cnt = 0;
		while (resulting_dmg > D) {
			cnt++;
			find(P, delta, index);
			char tmp = P[index - 1];
			P[index - 1] = P[index];
			P[index] = tmp;
			resulting_dmg -= delta / 2; // robot's program damage after current hack
		}
		return cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // gives speed to C++ IO
	int T;
	int D; // damage our algorithms can endure!
	string P; // evil robot's program!

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> D >> P;
		int res = save_the_universe(D, P);
		cout << "Case #" << i + 1 << ": " << (res >= 0 ? itos(res) : "IMPOSSIBLE") << endl;
	}


	return 0;
}
