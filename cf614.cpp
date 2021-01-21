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

		ll m, n, k, x;
		cin >> m >> n >> k;
		set<ll> st;
		while (k--) {
			cin >> x, st.insert(x);
		}

		ll i = n, j = n;
		while (st.find(i) != st.end())
			i++;
		while (st.find(j) != st.end() && j > 0)
			j--;

		if (j <= 0)
			cout << abs(i - n) << endl;
		else {
			if (i <= m)
				cout << min(i - n, n - j) << endl;
			else
				cout << n - j << endl;

			{

			};
		}

	}

	return 0;
}
