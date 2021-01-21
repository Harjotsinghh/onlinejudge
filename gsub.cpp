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
		int n, q;
		cin >> n >> q;
		int arr[n + 1];
		loop(i, 1, n)
		cin >> arr[i];
		int largest_left[n + 1];
		int largest_right[n + 1];
		largest_left[1] = 1;
		loop(i, 2, n)
		{
			if (arr[i] == arr[i - 1])
				largest_left[i] = 1;
			else
				largest_left[i] = largest_left[i - 1] + 1;

		}
		largest_right[n] = 1;
		loopr(i, 1, n - 1) {
			if (arr[i] == arr[i + 1])
				largest_right[i] = 1;
			else
				largest_right[i] = largest_right[i + 1] + 1;
		}


		int a, b;
		while (q--) {
			cin >> a >> b;



		}




	}

	return 0;
}
