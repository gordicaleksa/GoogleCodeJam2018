//#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// convert int to string
string itos(int i) {
	stringstream s;
	s << i;
	return s.str();
}

int trouble_sort(vector<int>& v) {
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) a.push_back(v[i]);
		else b.push_back(v[i]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < b.size(); i++) {
		if (b[i] >= a[i]) {
			if (i + 1 < a.size()) {
				if (b[i] <= a[i + 1]) continue;
				return 2 * i + 1;
			}
			else continue;
		}
		return 2 * i;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); // gives speed to C++ IO
	int T;
	int N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<int> v(N);

		for (int j = 0; j < N; j++) {
			cin >> v[j];
		}
		int res = trouble_sort(v);
		cout << "Case #" << i + 1 << ": " << (res >= 0 ? itos(res) : "OK") << endl;
	}


	return 0;
}

