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
	ll n, C;
	cin >> n >> C;
	ll ans = 0;
	ll a, b, c;

	map<int, ll> mp;
	set<ll>st;
	loop(i, 1, n)
	{
		cin >> a >> b >> c;
		mp[a] += c;
		mp[b + 1] -= c;
		st.insert(a);
		st.insert(b + 1);
	}

	vector<ll> arr(st.begin(), st.end());

	int no = arr.size();

	ll sum = 0;
	loop(i, 0, no - 2)
	{
		sum += mp[arr[i]];

		ans += min(C, sum) * (arr[i + 1] - arr[i]);



	}
	cout << ans << endl;


	return 0;
}
