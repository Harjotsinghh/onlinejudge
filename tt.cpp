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
#define ll long long;
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
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> adj[n + 1];
		int u, v;
		loop(i, 1, n - 1) {
			cin >> u >> v;

			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ans[n + 1];
		bool vis[n + 1];
		memset(vis, false, sizeof(vis));
		queue<int> q;
		q.push(1);
		bool odd = true;
		while (!q.empty()) {
			int s = q.size();
			loop(i, 1, s) {
				int curr = q.front();
				q.pop();
				vis[curr] = true;
				if (odd)
					ans[curr] = 1;
				else
					ans[curr] = 2;
				for (auto it : adj[curr]) {
					if (!vis[it])
						q.push(it);
				}


			}
			odd ^= 1;
		}
		loop(i, 1, n)
		cout << ans[i] << " ";
		cout << endl;

	}


	return 0;
}
