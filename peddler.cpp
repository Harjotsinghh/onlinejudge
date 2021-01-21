#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define mk make_pair
#define vll vector<long long >
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define loopr(i,a,b) for(int i=b;i>=a;i--)
#define vii vector<vector<int>>
#define ll long long
void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
ll max_price[200001];
bool vis[200001];
ll ans;

ll dfs(int s, vector<int> *adj, ll* prices)
{
	if (vis[s])
		return max_price[s];
	vis[s] = true;
	for (auto it : adj[s]) {
		ll get = dfs(it, adj, prices);
		max_price[s] = max(max_price[s], dfs(it, adj, prices));
		ans = max(ans, get - prices[s]);
	}
	return max_price[s];
}

int main()
{
	io();
	int n, m, u, v;
	cin >> n >> m;
	ll prices[n + 1];
	loop(i, 1, n)
	{
		cin >> prices[i];
		max_price[i] = prices[i];
	}
	vector<int> adj[n + 1];
	while (m--) {
		cin >> u >> v;
		adj[u].pb(v);
	}
	memset(vis, false, sizeof(vis));
	ans = INT_MIN;
	loop(i, 1, n)
	if (!vis[i])
		dfs(i, adj, prices);

	cout << ans << endl;









	return 0;
}
