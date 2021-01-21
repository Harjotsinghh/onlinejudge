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

int dp[5000][5000];
int psum[4005];

ll dfs(ll *arr, int k, int i, ll sum, int n) {
	if (i >= n)
		return -2;

	if (dp[i][sum] != -1)
		return dp[i][sum];

	if ((sum >= k && (psum[i] - sum  >= k)) || (sum + arr[i] >= k && psum[i] - sum - arr[i] >= k))
		return 1;


	ll x = dfs(arr, k, i + 1, sum , n);
	ll y = dfs(arr, k, i + 1, sum + arr[i], n);

	if (x != -2 && y != -2)
		return dp[i][sum] = 1 + min(x, y);
	else if (x != -2)
		return dp[i][sum] = 1 + x;
	else if (y != -2)
		return dp[i][sum] = 1 + y;

	return dp[i][sum] = -2;



}
int main()
{

	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		ll arr[n];
		loop(i, 1, n)
		cin >> arr[i - 1];

		sort(arr, arr + n, greater<int>());
		memset(dp, -1, sizeof(dp));

		psum[0] = arr[0];
		loop(i, 1, n - 1)
		psum[i] = arr[i] + psum[i - 1];
		if (n == 1)
			cout << -1 << endl;
		else
		{
			ll ans = dfs(arr, k, 0, 0, n);
			cout << (ans == -2 ? -1 : ans ) << '\n';
		}


	}
	return 0;
}
