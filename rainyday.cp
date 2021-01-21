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
	int n, x, y;
	cin >> n >> x >> y;
	int arr[n];
	loop(i, 1, n)
	cin >> arr[i - 1];

	loop(i, 0, n - 1) {
		int ls = INT_MAX, rs = INT_MAX;

		for (int j = i - 1; j >= i - x && j >= 0; j--)
			ls = min(ls, arr[j]);

		for (int k = i + 1; k < n && k <= i + y; k++)
			rs = min(rs, arr[k]);

		if (arr[i] < ls && arr[i] < rs)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}

	return 0;
}
