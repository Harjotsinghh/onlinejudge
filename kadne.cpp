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
		int n, x;
		cin >> n;
		int arr[n];
		cin >> arr[0];
		int ans = arr[0];
		int csum = arr[0];
		loop(i, 1, n - 1) {
			cin >> x;
			if (csum + x < x)
				ans = max(csum, ans), csum = x;
			else
				csum += x, ans = max(csum, ans);

		}
		ans = max(csum, ans);
		cout << ans << endl;

	}

	return 0;
}
