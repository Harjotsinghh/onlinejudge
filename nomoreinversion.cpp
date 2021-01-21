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
		int n, k; cin >> n >> k;
		vector<int> arr;
		loop(i, 1, n) {
			if (i > k)
				arr.push_back(i - k);
			else
				arr.push_back(i);
		}
		int m = min(n - k, k - 1);
		reverse(arr.begin() + k - m - 1, arr.begin() + k);
		loop(i, 1, k)
		cout << arr[i - 1] << " ";
		cout << endl;



	}

	return 0;
}
