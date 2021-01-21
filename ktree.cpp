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

bool dfs(int s, vector<int> *adj, int *arr, int xr, int nd, ll k)
{
	if (adj[s].empty()) {
		if (((xr ^ arr[s]) == k) || ((nd & arr[s]) == k))
			return true;
		else
			return false;
	}

	bool ans = false;
	for (auto it : adj[s]) {

		ans |= dfs(it,  adj, arr, (xr ^ arr[s]), (nd & arr[s]) , k);
	}
	return ans;
}
int main()
{
	io();
	int t ;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector<int> adj[n + 1];
		loop(i, 1, n - 1) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);

		}
		int arr[n + 1];
		loop(i, 1, n)
		cin >> arr[i];

		cout << ((dfs(1, adj, arr, 0, (1 << 31) - 1, k))  ? "YES" : "NO") << endl;



	}


	return 0;
}
