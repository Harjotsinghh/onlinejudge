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
		int n;
		cin >> n;

		ll arr[n];
		loop(i, 1, n)
		cin >> arr[i - 1];

		ll sum[n];
		sum[n - 1] = arr[n - 1];
		ll ans = sum[n - 1];

		int i = n - 2;
		while (i >= 0) {

			if (i + arr[i] < n)
				sum[i] = arr[i] + sum[i + arr[i]];
			else
				sum[i] = arr[i];

			ans = max(ans, sum[i]);


			i--;
		}

		cout << ans << endl;




	}

	return 0;
}
