#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Artifact {
    int weight, profit;
    double ratio;
};

bool cmp(Artifact a, Artifact b) {
    return a.ratio > b.ratio;
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<Artifact> artifacts(n);
    for (int i = 0; i < n; i++) {
        cin >> artifacts[i].profit >> artifacts[i].weight;
        artifacts[i].ratio = (double)artifacts[i].profit / artifacts[i].weight;
    }
    sort(artifacts.begin(), artifacts.end(), cmp);
    double total_profit = 0;
    for (int i = 0 ; i < n && W > 0; i++) {
        int weight = min(W, artifacts[i].weight);
        total_profit += weight * artifacts[i].ratio;
        W -= weight;
    }
    cout << total_profit << endl;

    return 0;
}
