#include "../utilities/template.h"

bool valid(vi deg) {
	int n = sz(deg);
	sort(all(deg));
	reverse(all(deg));
	int sum = 0;
	rep2(i,0,n) sum += deg[i];
	if (sum & 1) return 0;
	rep2(k,0,n) {
		int s = 0, t = 0;
		rep2(i,0,k+1)
			s += deg[i];
		rep2(i,k+1,n)
			t += min(deg[i], k + 1);
		if (s > k * (k+1) + t) return 0;
	}
	return 1;
}

int main() {
	rep2(N,0,7) {
		vector<pii> possibleEd;
		rep2(i,0,N) rep2(j,0,i) possibleEd.emplace_back(i, j);
		set<vi> valids;
		rep2(bi,0,(1 << sz(possibleEd))) {
			vi deg(N);
			rep2(i,0,sz(possibleEd)) if (bi & (1 << i)) {
				int a, b;
				tie(a, b) = possibleEd[i];
				deg[a]++;
				deg[b]++;
			}
			assert(valid(deg));
			valids.insert(deg);
		}

		vi de(N);
		function<void(int)> rec = [&](int at) {
			if (at == N) {
				assert(valid(de) == valids.count(de));
			} else {
				rep2(a,0,N) {
					de[at] = a;
					rec(at + 1);
				}
			}
		};
		rec(0);
	}
	cout << "Tests passed!" << endl;
}
