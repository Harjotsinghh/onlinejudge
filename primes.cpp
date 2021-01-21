#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define mk make_pair
#define vll vector<long long >
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define loopr(i,a,b) for(ll i=b;i>=a;i--)
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
		ll a, b;
		cin >> a >> b;
		ll no = ceil(sqrt(b)) + 1;
		vector<ll> primes;
		bool seive[no + 1];

		memset(seive, false, sizeof(seive));
		seive[0] = seive[1] = true;
		loop(i, 2, no) {
			if (!seive[i])
			{
				primes.pb(i);
				for (int j = i + i ; j <= no; j += i) {
					seive[j] = true;
				}
			}
		}


		bool seg_seive[b - a + 1];
		memset(seg_seive, false, sizeof(seg_seive));
		for (auto it : primes) {
			int l = floor(a / it) * it;
			if (l < a)
				l += it;
			if (l == it)
				l += it;

			for (int j = l ; j <= b; j += it)
				if (j != it)
					seg_seive[j - a] = true;
		}

		loop(i, a, b)
		if (!seg_seive[i - a] && i != 1)
			cout << i  << " ";
		cout << endl;
	}

	return 0;
}
