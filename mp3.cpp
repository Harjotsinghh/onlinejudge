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
	int n;
	cin >> n;

	int arr[n];
	loop(i, 1, n)
	cin >> arr[i - 1];

	int minb[n]; minb[0] = arr[0];
	int maxe[n]; maxe[n - 1] = arr[n - 1];

	loopr(i, 0, n - 2)
	maxe[i] = max(arr[i], maxe[i + 1]);

	loop(i, 1, n - 1)
	minb[i] = min(arr[i], minb[i - 1]);

	int ans = 0, j = 0, i = 0;
	while (j < n && i <= j) {
		if (minb[i] <= maxe[j])
			ans = max(ans, j - i ), j++;
		else
			i++;
	}

	cout << ans << endl;

	return 0;
}
