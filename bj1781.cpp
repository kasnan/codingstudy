#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//무한대 표기법
//const int INF = 1e9 + 10;

vector<pair<int, int>> v;
int n;

bool cmp(pair<int, int> a, pair<int, int> b) {
    // 데드라인을 기준으로 내림차순으로 정렬
	return a.first > b.first;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
        // 데드라인과 컵라면 수 입력
		cin >> a >> b;
		v.push_back(make_pair(a, b));
        // 문제 해결에 1의 시간이 걸리므로 1제거하고 비교
		v[i].first--;
	}

	sort(v.begin(), v.end(),cmp);

	long long sum = 0;

    // 오름차순 우선순위 큐
	priority_queue<int> pq;

    // 데드라인이 큰 문제부터 선택
	for (int i=n-1,j=0;i>=0;i--) {
        // 데드라인이 오버하지 않은 경우
		while (j < n&& i== v[j].first) {
			pq.push(v[j].second);
			j++;
		}
	
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	
	}

	cout << sum;
}

