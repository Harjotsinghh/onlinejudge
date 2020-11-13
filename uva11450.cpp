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
int prices[25][25];
bool dp[25][205];
int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int m, c;
		cin >> m >> c;

		loop(i, 1, c) {
			cin >> prices[i][0];
			loop(j, 1, prices[i][0])
			cin >> prices[i][j];
		}

		memset(dp, false, sizeof(dp));

		loop(i, 1, prices[1][0]) {
			if (m >= prices[1][i]) {
				dp[1][m - prices[1][i]] = true;

			}
		}

		loop(i, 2, c) {
			loop(k, 0, m) {
				if (dp[i - 1][k]) {
					loop(j, 1, prices[i][0]) {
						if (k >= prices[i][j]) {
							dp[i][k - prices[i][j]] = true;
						}
					}

				}
			}
		}
		int res = -1;

		loop(i, 0, m) {
			if (dp[c][i])
			{
				res = i;
				break;
			}
		}
		if (res == -1)cout << "no solution" << endl;
		else
			cout << m - res << endl;

	}

	return 0;
}
