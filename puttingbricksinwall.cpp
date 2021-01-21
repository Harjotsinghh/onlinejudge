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
char arr[201][201];

int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		loop(i, 0, n - 1) {
			loop(j, 0, n - 1) {
				cin >> arr[i][j];
			}
		}
		vector <pair<int, int> > ans;
		int count = 0;

		if ((arr[0][1] == '0' && arr[1][0] == '0')) {
			if (arr[n - 1][n - 2] == '0')
				ans.pb(mk(n, n - 1)), count++;
			if (arr[n - 2][n - 1] == '0')
				ans.pb(mk(n - 1, n)), count++;

		}
		else if ((arr[0][1] == '1' && arr[1][0] == '1')) {
			if (arr[n - 1][n - 2] == '1')
				ans.pb(mk(n, n - 1)), count++;
			if (arr[n - 2][n - 1] == '1')
				ans.pb(mk(n - 1, n)), count++;

		}
		else if ((arr[0][1] == '0' && arr[1][0] == '1') || (arr[0][1] == '1' && arr[1][0] == '0')) {
			if ((arr[n - 1][n - 2] == '0' && arr[n - 2][n - 1] == '1') || (arr[n - 1][n - 2] == '1' && arr[n - 2][n - 1] == '0'))
			{
				count += 2;
				if (arr[0][1] == '0') {
					ans.pb(mk(1, 2));
					if (arr[n - 1][n - 2] == '1')
						ans.pb(mk(n, n - 1));
					else
						ans.pb(mk(n - 1, n));

				}
				else
				{
					ans.pb(mk(1, 2));
					if (arr[n - 1][n - 2] == '0')
						ans.pb(mk(n, n - 1));
					else
						ans.pb(mk(n - 1, n));


				}

			}
			else {
				if (arr[n - 1][n - 2] == '0') {
					if (arr[0][1] == '0')
						count++, ans.pb(mk(1, 2));
					else
						count++, ans.pb(mk(2, 1));
				}
				else {
					if (arr[0][1] == '1')
						count++, ans.pb(mk(1, 2));
					else
						count++, ans.pb(mk(2, 1));

				}
			}

		}
		cout << count << endl;
		for (pair<int, int> it : ans) {
			cout << it.first << " " << it.second << endl;
		}

	}
	return 0;
}
