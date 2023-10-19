#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int D[1001];
int N;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	v.resize(N);
	for (int i=0;i<N;i++) cin >> v[i];
	for (int i = 0; i < N; i++) {
		D[i] = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && D[i] < D[j] + 1) D[i] = D[j] + 1;
		}
	}
	cout << *max_element(D, D + N + 1) + 1;
}