-------bai 1--------
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topological_sort(int n, vector<vector<int>>& adj) {
    vector<int> in_degree(n + 1, 0);
    for (auto& v : adj) {
        in_degree[v[1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto& v : adj) {
            if (v[0] == u) {
                in_degree[v[1]]--;
                if (in_degree[v[1]] == 0) {
                    q.push(v[1]);
                }
            }
        }
    }
    return order;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> adj[i][0] >> adj[i][1];
    }
    vector<int> order = topological_sort(n, adj);
    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}

-------bai 2--------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void merge(int x, int y, vector<int>& parent) {
    int px = find(x, parent);
    int py = find(y, parent);
    if (px != py) {
        parent[px] = py;
    }
}

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    vector<Edge> mst;
    sort(edges.begin(), edges.end(), cmp);
    for (auto& e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            merge(e.u, e.v, parent);
            mst.push_back(e);
        }
        if (mst.size() == n - 1) {
            break;
        }
    }
    return mst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<Edge> mst = kruskal(n, edges);
    int cost = 0;
    for (auto& e : mst) {
        cost += e.w;
    }
    cout << cost << endl;
    for (auto& e : mst) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }

    return 0;
}

