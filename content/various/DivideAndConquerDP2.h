/**
 * Author: Masato Shinokawa
 * License: CC0
 * Source: https://shino16.github.io/cpp-library/dp/d_and_c.hpp
 * Description: An implementation of Divide and Conquer DP.
 *   Minimizes cost of k-partitions of $\left[0, n\right)$ with $k \leq max_k$
 *   ($k = max_k$ if $cost(i,i) = inf$).
 *   Requires $cost(a,c) + cost(b,d) \leq cost(a,d) + cost(b,c)$
 *   for $a < b < c < d$ (wider is worse).
 * Time: O(kn \log n)
 */

template <class F>
auto d_and_c_dp(int max_k, int n, F cost) {
	using T = decltype(cost(0, 0));
	vector<T> dp(n + 1), nxt(n + 1);
	rep(i, n + 1) dp[i] = cost(0, i);
	auto rec = [&](auto&& f, int l, int r, int optl, int optr) -> void {
		if (l == r) return;
		int m = (l + r) / 2;
		T best = numeric_limits<T>::max() / 2;
		int opt = -1;
		rep2(j, optl, min(m, optr) + 1) {
			if (best > dp[j] + cost(j, m)) best = dp[j] + cost(j, m), opt = j;
		}
		nxt[m] = best;
		f(f, l, m, optl, opt);
		f(f, m + 1, r, opt, optr);
	};
	rep2(k, 1, max_k) rec(rec, 0, n + 1, 0, n - 1), swap(dp, nxt);
	return dp;
}
