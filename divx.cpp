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
	bool primes[100001] = {false};


	loop(i, 2, 100000) {
		if (primes[i])
		{
			continue;
		}
		for (int j = i + i; j <= 100000; j += i) {
			primes[j] = true;
		}
	}
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ll ans = 1;
		ll i = n + 1;
		int cc = 0;
		while (i < 100000 && cc < 2) {
			if (!primes[i])
			{
				ans *= i;
				i += n;
				cc++;
			}
			else
				i++;


		}
		cout << ans << endl;

	}

	return 0;
}
