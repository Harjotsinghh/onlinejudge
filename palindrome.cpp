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
	int t = 0;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int arr[n][m];
		loop(i, 0, n - 1)
		loop(j, 0, m - 1)
		cin >> arr[i][j];

		int dp[n + m - 1][2];
		memset(dp, 0, sizeof(dp));

		loop(i, 0, n - 1)
		loop(j, 0, m - 1)
		dp[i + j][arr[i][j]]++;

		int s = (n + m - 3) / 2;
		ll ans = 0;
		loop(i, 0, s) {
			int j = n + m - 2 - i;
			ans += min(dp[i][0] + dp[j][0], dp[i][1] + dp[j][1]);
		}
		cout << ans << endl;
	}

	return 0;
}
