/**
 * Author: Masato Shinokawa
 * License: CC0
 * Source: https://shino16.github.io/cpp-library/dp/knuth_partition.hpp
 * Description: An implementation of Knuth DP.
 *   Minimizes cost of $k$-partitions of $\left[0, n\right)$ with $k \leq max_k$
 *   ($k = max_k$ if $cost(i,i) = inf$).
 *   Requires $cost(a,c) + cost(b,d) \leq cost(a,d) + cost(b,c)$
 *   for $a < b < c < d$ (wider is worse).
 * Time: O(kn + n^2)
 */


template <class F>
auto knuth_partition_dp(int max_k, int n, F cost) {
	using T = decltype(cost(0, 0));
	vector<T> dp(n + 1), dp2(n + 1);
	vector<int> opt(n + 2), opt2(n + 2);
	rep(i, n + 1) dp[i] = cost(0, i);
	rep2(k, 1, max_k) {
		fill(all(dp2), numeric_limits<T>::max() / 2);
		opt2[n+1] = n;
		repr(i, n + 1) rep2(j, opt[i], min(i, opt2[i + 1]) + 1) {
			if (dp2[i] > dp[j] + cost(j, i)) dp2[i] = dp[j] + cost(j, i), opt2[i] = j;
		}
		swap(dp, dp2);
		swap(opt, opt2);
	}
	return dp;
}