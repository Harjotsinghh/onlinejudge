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




int main()
{
	io();
	ll n, m, k, a, u, v, t, sponsor;
	cin >> n >> m >> k;

	unordered_set<int> winners;
	loop(i, 1, m) cin >> a, winners.insert(a);
	vector<pair<ll, ll>> adj[n + 1];


	loop(i, 1, k) cin >> u >> v >> t, adj[u].pb({v, t}), adj[v].pb({u, t});

	cin >> sponsor;

	ll ans = INT_MIN;
	ll dist[n + 1];
	bool vis[n + 1];
	loop(i, 1, n)
	dist[i] = INT_MAX;
	memset(vis, false, sizeof(vis));
	dist[sponsor] = 0;
	loop(i, 1, n) {
		int ind = -1;
		loop(j, 1, n) {
			if (!vis[j] && (ind == -1 || dist[j] <= dist[ind]))
				ind = j;
		}

		if (ind == -1)
			break;
		if (dist[ind] == INT_MAX)
			break;

		vis[ind] = true;
		// cout << ind << " " << dist[ind] << endl;


		for (auto it : adj[ind])
		{
			int vv = it.first;
			int time = it.second;
			if (!vis[vv] && dist[ind] + time < dist[vv])
				dist[vv] = dist[ind] + time;
		}

	}
	bool valid = true;

	for (auto it : winners) {
		if (!vis[it])
		{
			valid = false;
			break;
		}
		else
			ans = max(ans, dist[it]);
	}

	if (!valid || ans == INT_MIN)
		cout << "It is not fault of sponsor..." << endl;
	else
		cout << "The good sponsor!" << '\n' << ans << endl;




	return 0;
}
