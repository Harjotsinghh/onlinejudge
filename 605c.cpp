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

	int inp[3]; ll x;
	cin >> inp[0] >> inp[1] >> inp[2];
	vector<ll> mii;
	vector<ll> mss;
	ll sum = 0;
	loop(i, 0, 2) {
		ll mi = INT_MAX;
		ll s_temp = 0;
		loop(j, 1, inp[i])
		{
			cin >> x;
			sum += x;
			s_temp += x;
			mi = min(x, mi);
		}
		mss.push_back(s_temp);
		mii.pb(mi);
	}
	sort(mss.begin(), mss.end());
	sort(mii.begin(), mii.end());

	cout << sum - 2ll * min(mss[0], mii[0] + mii[1]) << endl;


	return 0;
}
