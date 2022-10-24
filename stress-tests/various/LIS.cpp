#include "../utilities/template.h"

#include "../../content/various/LIS.h"

template<class I> vi lisWeak(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(sz(S));
	typedef pair<I, int> p;
	vector<p> res;
	rep2(i,0,sz(S)) {
		// 0 -> i for longest non-decreasing subsequence
		auto it = lower_bound(all(res), p{S[i], i});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

int main() {
	rep2(weak,0,2) {
		auto lt = [weak](int a, int b) { return weak ? a <= b : a < b; };
		rep2(it,0,1000000) {
			int n = rand() % 7;
			vi v(n);
			for(auto &x: v) x = rand() % 4;
			vi inds = weak ? lisWeak(v) : lis(v);
			rep2(i,0,sz(inds)-1) {
				assert(lt(v[inds[i]], v[inds[i+1]]));
			}
			rep2(bi,0,(1 << n)) {
				int si = (int)bitset<32>(bi).count();
				if (si <= sz(inds)) continue;
				int prev = INT_MIN;
				rep2(i,0,n) if (bi & (1 << i)) {
					if (!lt(prev, v[i])) goto next;
					prev = v[i];
				}
				cout << "exists lis of size " << si << " but found only " << sz(inds) << endl;
				for(auto &x: v) cout << x << ' ';
				cout << endl;
				abort();
	next:;
			}
		}
	}
	cout << "Tests passed!" << endl;
}
