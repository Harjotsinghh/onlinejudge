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
struct node {
	int maxx, minn;
	node() {
		maxx = INT_MIN;
		minn = INT_MAX;
	}
};
void build(int *dp, node *seg, int l, int h, int se) {
	if (l == h)
	{
		seg[se].maxx = dp[l];
		seg[se].minn = dp[l];
		return;
	}
	int mid = (l + h) >> 1;
	build(dp, seg, l, mid, 2 * se + 1);
	build(dp, seg, mid + 1, h, 2 * se + 2);

	seg[se].maxx = max(seg[2 * se + 1].maxx, seg[2 * se + 2].maxx);
	seg[se].minn = min(seg[2 * se + 1].minn, seg[2 * se + 2].minn);
	return ;
}
node query(node *seg, int l, int h, int a, int b, int se) {
	node curr = node();
	if (a > h || b < l)
		return curr;
	if (l >= a && h <= b)
		return seg[se];

	int mid = (l + h) >> 1;
	node one = query(seg, l, mid, a, b, 2 * se + 1);
	node two = query(seg, mid + 1, h, a, b, 2 * se + 2);

	curr.maxx = max(one.maxx, two.maxx);
	curr.minn = min(one.minn, two.minn);

	return curr;


}

int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		string s;
		cin >> s;
		int dp[n + 1];
		dp[0] = 0;
		loop(i, 1, n) {
			dp[i] = (s[i - 1] == '-') ? dp[i - 1] - 1 : dp[i - 1] + 1;
		}
		int size = 2 * pow(2, ceil(log2(n + 1))) - 1 ;
		node seg[size];
		build(dp, seg, 0, n , 0);
		while (q--) {
			int l, h;
			cin >> l >> h;
			node ans1 = query(seg, 0, n , 0, l - 1, 0);
			node ans2 = query(seg, 0, n , h + 1, n , 0);
			int mm = max(ans1.maxx, ans2.maxx);
			int mn = min(ans1.minn, ans2.minn);
			// cout << mm << " " << mn << "," << mm - mn + 1 << " ";
			if (l == 1 && h == n) {
				cout << 1 << endl;
			}
			else if (l > 1 && h < n) {

				if (mm == mn)
					cout << (mm == 0 ? 1 : 2) << endl;
				// else cout <<
				else cout << mm - mn + 1 << endl;

			}
			else if (h == n) {
				// cout << ans1.maxx << " " << ans1.minn << " , ";
				cout << ans1.maxx - ans1.minn + 1 << endl;

			}
			else if (l == 1)
			{
				cout << mm - mn + 1 << endl;
			}




		}

	}

	return 0;
}
