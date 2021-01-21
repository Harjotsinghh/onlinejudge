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
		int n, q; cin >> n >> q;
		string s; cin >> s;
		pair<int, int> dp1[n + 2];
		pair<int, int> dp2[n + 2];
		int psum[n + 1];
		psum[0] = 0;
		dp1[0] = {0, 0};

		loop(i, 1, n) {
			int add = (s[i - 1] == '-') ? -1 : 1;
			psum[i] = psum[i - 1] + add;
			dp1[i] = {min(psum[i], dp1[i - 1].first), max(psum[i], dp1[i - 1].second)};
		}

		dp2[n + 1] = {0, 0};
		loopr(i, 1, n) {
			int add = (s[i - 1] == '-') ? -1 : 1;

			dp2[i] = {min(0, dp2[i + 1].first + add), max(0, dp2[i + 1].second + add)};
		}

		while (q--) {
			int l, h;
			cin >> l >> h;

			int offset = psum[l - 1];
			int min1 = dp1[l - 1].first, max1 = dp1[l - 1].second;
			int min2 = dp2[h + 1].first + offset, max2 = dp2[h + 1].second + offset;

			cout << max(max1, max2) - min(min1, min2) + 1 << endl;
		}


	}

	return 0;
}
