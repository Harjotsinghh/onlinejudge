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
	string a, b , c;
	cin >> a >> b >> c;

	int n = a.length(), m = b.length(), p = c.length();
	int dp[n + 1][m + 1][p + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= p; k++)
			{
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 0;
				else {
					if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
						dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
					else
					{
						dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
					}
				}
			}
		}
	}

	int i = n - 1, j = m - 1, k = p - 1;
	string ans = "";
	while (i > 0 && j > 0 && k > 0)
	{
		int x = dp[i - 1][j][k], y = dp[i][j - 1][k], z = dp[i][j][k - 1];
		if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
		{
			ans = a[i - 1] + ans;
			i--, j--, k--;
		}
		else if (x >= y && x >= z)
			i--;
		else if (y >= x && y >= z)
			j--;
		else
			k--;
	}
	cout << ans << endl;

	return 0;
}
