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
int get_index(char c) {
	return  ((int)c - 97 + 1 );
}
int smallest_dfs(int s, bool *vis, vector<int> *adj) {
	int sm = s;
	vis[s] = true;
	for (auto it : adj[s] ) {
		if (!vis[it]) {
			sm = min(sm, smallest_dfs(it, vis, adj));
		}
	}
	return sm;
}

int main()
{
	io();
	string a, b, c;
	cin >> a >> b >> c;
	vector<int> adj[27];
	auto it = a.begin(), it1 = b.begin(), it2 = c.begin();
	while (it != a.end() && it1 != b.end())
	{
		int ind1 = get_index(*it);
		int ind2 = get_index(*it1);
		adj[ind1].pb(ind2);
		adj[ind2].pb(ind1);
		it++; it1++;
	}
	it1 = b.begin();
	while (it1 != b.end() && it2 != c.end())
	{
		int ind1 = get_index(*it1);
		int ind2 = get_index(*it2);
		adj[ind1].pb(ind2);
		adj[ind2].pb(ind1);
		it1++; it2++;
	}
	bool vis[27];
	string ans = "";
	for (auto it : a) {
		int ind = get_index(it);
		memset(vis, false, sizeof(vis));
		int sm = smallest_dfs(ind, vis, adj);
		// cout << sm << " ";
		ans += char(97 + sm - 1);
	}

	cout << ans << endl;
	return 0;
}
