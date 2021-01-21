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
		int n, k;
		cin >> n >> k;

		int arr[n + 1];
		loop(i, 1, n)
		arr[i] = i;

		int j = 1;
		int ng = n - k;
		while (ng && j <= n) {
			arr[j] = -j;

			j += 2;
			ng--;
		}

		j = (n % 2 == 0) ? n : n - 1;

		while (ng && j >= 0) {

			arr[j] = -j;
			j -= 2;
			ng--;
		}
		loop(i, 1, n)
		cout << arr[i] << " ";

		cout << endl;




	}
	return 0;
}

