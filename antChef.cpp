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
		cin >> n;
		vector<int> arr[n];
		int ans = 0;
		loop(i, 1, n)
		{
			cin >> m;
			int x;
			int cc = 0, cc2 = 0;
			loop(j, 1, m)
			{
				cin >> x;
				if (x < 0)
					cc++;
				else
					cc2++;
				arr[i - 1].pb(x);
			}
			ans += cc * cc2;
		}


		cout << ans << endl;
	}

	return 0;
}
