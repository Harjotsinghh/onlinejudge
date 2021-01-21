#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define mk make_pair
#define vll vector<long long >
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=b;i>=a;i--)
#define vii vector<vector<int>>
#define ll long long
void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void dfs(int s, bool*vis, vector<int> *adj) {
	vis[s] = true;
	for (auto it : adj[s])
		if (!vis[it]) dfs(it, vis, adj);
}
int main()
{
	io();
	ll n, m, a, b, u, v;
	cin >> n >> m >> a >> b;


	vector<ll> adj[n + 1];

	loop(i, 1, m) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bool vis[n + 1];
	memset(vis, false, sizeof(vis));
	ll cc = 0;
	loop(i, 0 , n) {
		if (adj[i].empty())
			continue;
		if (vis[i])
			continue;
		cc += 1;
		dfs(i, vis, adj);
	}
	ll ans;
	ans = a * cc;
	loop(i, 2, cc)
	ans = min(ans, ((i - 1) * b + a + ((cc - i) * a) ));
	cout << ans << endl;

	return 0;
}
