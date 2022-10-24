/**
 * Author: jakobkogler
 * Source: cp-algorithms
 * Description: For all $v$, finds the shortest path from $s$ to $v$ and stores in $d[v]$.
 * $p[v]$ is the second-to-last node in the shortest path from $s$ to $v$.
 * Time: O(m \log n)
 * Status: works
 */
#pragma once

const int INF = 1000000000;
vector<vpii> adj;

void dijkstra(int s, vi &d, vi &p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}
