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
		ll n, x;
		cin >> n >> x;

		ll arr[n + 1];
		loop(i, 1, n)
		cin >> arr[i];


		int i = 1;
		while (x) {
			if (i == n)
				break;
			while (arr[i] != 0 && x) {
				int j = i + 1;
				int msb = floor(log2(arr[i]));
				while (j < n) {
					if ((arr[j] ^ (1 << msb) ) <= arr[j])
						break;
					j++;

				}
				arr[i] ^= (1 << msb);
				arr[j] ^= (1 << msb);
				x--;

			}
			if ( arr[i] == 0 )
				i++;

		}

		if (n == 2 && x % 2 != 0 && x)
			arr[2] ^= 1, arr[1] ^= 1;


		loop(i, 1, n)
		cout << arr[i] << " ";
		cout << endl;

	}

	return 0;
}
