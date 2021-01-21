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
unordered_map < ll, ll > dp;
ll dfs(ll y, ll x) {
	if (x == y)
		return 0;
	if (y == 1)
		return dp[y] = abs(x - y);

	if (dp.find(y) != dp.end())
		return dp[y];
	if (y > x) {
		if (y % 2 == 0) {
			return dp[y] =  min(y - x, 1 + dfs( y / 2, x));
		}
		else

			return dp[y] = min(1 + dfs(y - 1, x), 1 + dfs(y + 1, x));
	}
	else {
		return dp[y] = abs(x - y);
	}

}

int main()
{
	io();
	ll x, y;
	dp.clear();
	cin >> x >> y;

	cout << dfs(y, x) << endl;
	return 0;
}
