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
ll arr[1000000];

int find( int i , int n)
{
	if (i == 0 || i == n - 1)
		return 0;

	if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
		return 1;
	if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
		return 1;
	return 0;
}

int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		loop(i, 1, n)
		cin >> arr[i - 1];

		int total = 0;
		loop(i, 1, n - 1)
		{
			total += find(i, n);
		}
		int ans = total;
		loop(i, 1, n - 2) {

			if (find(i, n) == 0)
				continue;
			int old = total - find(i, n) - find(i - 1, n) - find(i + 1, n);
			int tmp = arr[i];
			arr[i] = arr[i - 1];
			ans = min(ans, old + find(i, n) + find(i - 1, n) + find(i + 1, n) );
			arr[i] = arr[i + 1];
			ans = min(ans, old + find(i, n) + find(i - 1, n) + find(i + 1, n) );
			arr[i] = tmp;

		}
		cout << ans << endl;
	}

	return 0;
}
