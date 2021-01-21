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
		ll a, b, p;
		cin >> a >> b >> p;
		ll mi = INT_MAX, ma = floor((a + b) / p);
		if (a % p == 0 || b % p == 0 || (floor(a / p) + floor(b / p) == ma))
			mi = 0;
		else {
			ll gb = -1, ga = -1;
			if (p - a % p <= b )
				gb = p - a % p;
			if (p - b % p <= a)
				ga = p - b % p;

			if (ga != -1 && gb != -1 )
			{
				ll na = a - ga, nb = b + ga;
				if (floor(na / p) + floor(nb / p) == ma)
					mi = ga;
				na = a + gb, nb = b - gb;
				if (floor(na / p) + floor(nb / p) == ma )
					mi = min(mi, gb);
			}
			else if (ga == -1) {
				ll na = a + gb, nb = b - gb;
				if (floor(na / p) + floor(nb / p) == ma )
					mi = min(mi, gb);

			}
			else if (gb == -1) {
				ll na = a - ga, nb = b + ga;
				if (floor(na / p) + floor(nb / p) == ma)
					mi = ga;

			}





		}


		cout << ma << " " << ((mi == INT_MAX) ? 0 : mi ) << endl;


	}
	return 0;
}
