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
		sort(arr, arr + n);

		int turn = 1, i = n - 1;
		ll alice = 0, bob = 0;
		while (i >= 0) {
			if (turn && arr[i] % 2 == 0)
				alice += arr[i];


			else if (!turn && arr[i] % 2 != 0)
				bob += arr[i];

			i--;


			turn ^= 1;
		}
		// cout << alice << " " << bob << endl;
		if (alice < bob)
			cout << "Bob" << endl;
		else if (bob < alice)
			cout << "Alice" << endl;
		else
			cout << "Tie" << endl;




	}

	return 0;
}
