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
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll arr1[n], arr2[m];

		loop(i, 1, n)
		cin >> arr1[i - 1];
		loop(i, 1, m)
		cin >> arr2[i - 1];

		sort(arr1, arr1 + n);
		int j = 0;
		ll sum = 0;
		int i = n - 1;
		while (i >= 0) {
			if (arr2[arr1[i] - 1] <= arr2[j] || j == m) {
				sum += arr2[arr1[i] - 1];

			}
			else {
				sum += arr2[j];
				j++;
			}
			i--;

		}
		cout << sum << endl;


	}

	return 0;
}
