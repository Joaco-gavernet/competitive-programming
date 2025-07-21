#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

struct Edge {
    int u, v, w, idx;
};

int n, m, s, t;
vector<vector<pair<int, int>>> adj, rev;
vector<Edge> edges;

vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    adj.assign(n + 1, {});
    rev.assign(n + 1, {});
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
        adj[u].emplace_back(v, w);
        rev[v].emplace_back(u, w);
    }

    // Get shortest paths from s and to t
    vector<int> d1 = dijkstra(s, adj);
    vector<int> d2 = dijkstra(t, rev);
    int D = d1[t];

    // Build shortest-path subgraph
    vector<vector<pair<int, int>>> sp_graph(n + 1);  // edges in shortest paths
    for (const auto& e : edges) {
        int u = e.u, v = e.v, w = e.w;
        if (d1[u] + w + d2[v] == D) {
            sp_graph[u].emplace_back(v, d1[u]);  // we store entry time (d1[u]) for sorting
        }
    }

    // For each node, sort outgoing edges by d1[u] to d1[v] intervals
    map<pair<int, int>, vector<int>> edge_intervals;
    for (const auto& e : edges) {
        if (d1[e.u] + e.w + d2[e.v] == D) {
            edge_intervals[{d1[e.u], d1[e.v]}].push_back(e.idx);
        }
    }

    // Output logic
    vector<string> result(m);
    for (const auto& e : edges) {
        int u = e.u, v = e.v, w = e.w, idx = e.idx;

        if (d1[u] + w + d2[v] == D) {
            // On some shortest path — check if unique interval
            if (edge_intervals[{d1[u], d1[v]}].size() == 1) {
                result[idx] = "YES";
            } else {
                result[idx] = "NO";
            }
        } else {
            // Try to reduce weight
            int needed = D - d1[u] - d2[v] - 1;
            if (needed >= 1 && needed < w) {
                result[idx] = "CAN " + to_string(needed);
            } else {
                result[idx] = "NO";
            }
        }
    }

    for (const auto& res : result) {
        cout << res << '\n';
    }

    return 0;
}

