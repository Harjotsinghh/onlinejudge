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

int  dfs(int *arr, int s1, int s2, int k, int i, int total) {
	if (dp[s1][s2] != -1)
		return dp[s1][s2];
	if (i < 0) {
		if (s1 >= k && s2 >= k)
		{
			if (dp[k][k] == -1)
				return dp[k][k] = total;
			else
				return	dp[k][k] = min(dp[k][k], total);
		}
		else
			return INT_MAX;


	}
	if (s1 >= k && s2 >= k)
	{	if (dp[k][k] == -1)
			return dp[k][k] = total;
		else
			return	dp[k][k] = min(dp[k][k], total);
	}

	return dp[s1][s2] = min(dfs(arr, s1 + arr[i], s2, k, i - 1, total + 1),
	                        dfs(arr, s1, s2 + arr[i], k, i - 1, total + 1));



}


int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		loop(i, 1, n)
		cin >> arr[i - 1];

		sort(arr, arr + n);
		memset(dp, -1, sizeof(dp));
		int prefix[n + 1];

		dfs(arr, 0, 0, k, n - 1, 0) ;
		cout << dp[k][k]  << endl;


	}

	return 0;
}
