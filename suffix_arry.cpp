#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5, LOG = 20;

int n, r[N][LOG + 1];
pair < pair <int, int>, int> tmp[N];
string s;

void input() {
	cin >> n >> s;
}

void prep() {
	for (int i = 0; i < n; i++)
		r[i][0] = (int)s[i]; //ASCII code
	for (int j = 0; j < LOG; j++) {
//  we want to find r[i][j + 1] for all i

// we use an alternative array to sort [i, i + (1 << (j + 1)) )  : tmp[i]

// tmp[i] : rank first, rank second, index
		for (int i = 0; i < n; i++) {
			if(i + (1 << j) < n)
				tmp[i] = make_pair(make_pair(r[i][j], r[i + (1 << j)][j]), i);
			else
				tmp[i] = make_pair(make_pair(r[i][j], -1), i);
		}
		sort(tmp, tmp + n); // sort O(nlog)
		r[tmp[0].second][j + 1] = 0;
//      if tmp[i] == tmp[i - 1] => they are equal so they have the same index (map)
		// tmp[i].first == tmp[i - 1].first ==> r[tmp[i].second][j + 1] == r[tmp[i - 1].second][j + 1]
		for (int i = 1; i < n; i++) {
			if(tmp[i].first == tmp[i - 1].first)
				r[tmp[i].second][j + 1] = r[tmp[i - 1].second][j - 1];
			else
				r[tmp[i].second][j + 1] = i;  // i > 0
		}
	}
}

void output() {
	vector <pair <int, int> > result;
	for (int i = 0; i < n; i++)
		result.push_back(make_pair(r[i][LOG], i));
	sort(result.begin(), result.end());
	for (int i = 0; i < n; i++) {
		cout << "THE " << i + 1 << "th element in suffix array is  : " << result[i].second + 1 << "\n"; 
	}
}

int main() {
	input();
	prep();
	output();
}
