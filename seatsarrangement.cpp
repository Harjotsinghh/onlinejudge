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
	int n, m, k;
	cin >> n >> m >> k;
	char arr[n][m];
	loop(i, 1, n)
	{
		loop(j, 1, m)
		cin >> arr[i - 1][j - 1];
	}



	ll dp[n][m];
	memset(dp, 0, sizeof(dp));
	ll ans = 0;
	loop(i, 0, n - 1)
	loop(j, 0, m - 1) {

		if ((i == 0 && j == 0) || i == 0) {
			dp[i][j] = (arr[i][j] == '.') ? 1 : 0;
			if (dp[i][j] >= k)
				ans += 1;

		}

		else {
			if (arr[i][j] == '.')
			{
				dp[i][j] = 1 + dp[i - 1][j];
				if (dp[i][j] >= k)
					ans += 1;
			}

		}

	}

	if (k != 1) {
		memset(dp, 0, sizeof(dp));
		loop(i, 0, n - 1) {
			loop(j, 0, m - 1) {

				if ((i == 0 && j == 0 ) || j == 0) {
					dp[i][j] = (arr[i][j] == '.') ? 1 : 0;
					if (dp[i][j] >= k && i != 0 && j != 0)
						ans += 1;
				}

				else {
					if (arr[i][j] == '.') {
						dp[i][j] = 1 + dp[i][j - 1];
						if (dp[i][j] >= k)
							ans += 1;
					}

				}


			}

		}

	}



	cout << ans << endl;

	return 0;
}
