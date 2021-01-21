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
	int n, m, x, y;
	cin >> n >> m;
	string s;
	cin >> s;

	int indeg[n + 1];
	memset(indeg, 0, sizeof(indeg));
	vector<ll> adj[n + 1];
	while (m--)
		cin >> x >> y, adj[x].pb(y), indeg[y]++;
	ll dp[n + 1][26];
	memset(dp, 0, sizeof(dp));

	queue<int> q;
	ll cnt = 0;
	loop(i, 1, n)
	if (indeg[i] == 0)
		q.push(i), cnt++, dp[i][s[i - 1] - 'a'] = 1;

	if (q.empty())
	{
		cout << -1 << endl;
		return 0;
	}
	ll ans = -1;
	while (!q.empty()) {

		int siz = q.size();
		while (siz--) {
			int ind = q.front();
			q.pop();


			for (auto it : adj[ind]) {
				indeg[it]--;
				loop(i, 0, 25)
				dp[it][i] = max(dp[it][i]  , dp[ind][i] + ((s[it - 1] - 'a') == i));
				if (indeg[it] == 0)
					q.push(it), cnt++;
			}
		}

	}


	if (cnt < n )
		cout << -1  << endl;
	else
	{
		loop(i, 1, n)
		loop(j, 0, 25)
		ans = max(ans, dp[i][j]);
		cout << ans << endl;
	}






	return 0;
}
