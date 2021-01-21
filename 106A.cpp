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
	ll max = 1e18;
	ll n = 0;
	cin >> n; bool flag = true;
	// pair<ll, ll> ans = mk(-1ll, -1ll);

	for (ll i = 1; i < log(max) / log(5); i++) {
		for (ll j = 1; j < log(max) / log(3); j++) {
			if ((ll)powl(5, i) + (ll)powl(3, j) == (ll)(n))
			{
				flag = false;
				cout << j << " " << i << endl;
				break;
			}

		}
		if (!flag) break;

	}
	if (flag)
		cout << -1 << endl;



	return 0;
}

