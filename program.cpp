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

set<int> *seg;
void build(int i , int l, int h, int *arr)
{
	if (l == h)
	{
		seg[i].insert(arr[l]);
		return;
	}
	int  mid = (h + l) / 2;
	build(2 * i + 1, l, mid, arr);
	build(2 * i + 2, mid + 1, h, arr);
	seg[i].insert(seg[2 * i + 1].begin(), seg[2 * i + 1].end());
	seg[i].insert(seg[2 * i + 2].begin(), seg[2 * i + 2].end());
	return;

}
set<int> query(int i , int l, int h, int se, int sh) {

	set<int> left, right, result;
	if (l > sh || h < se)
		return result;
	if (l <= se && h >= sh)
		return seg[i];
	int  mid = (se + sh) / 2;
	left = query(2 * i + 1, l, h, se , mid);
	result.insert(left.begin(), left.end());
	right = query(2 * i + 2, l, h, mid + 1, sh);
	result.insert(right.begin(), right.end());

	return result;


}


int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		n++;
		int arr[n];
		arr[0] = 0;

		loop(i, 1, n - 1)
		{
			if (s[i - 1] == '-')
				arr[i] = arr[i - 1] - 1;
			else
				arr[i] = arr[i - 1] + 1;
			// cout << arr[i] << " ";
		}
		int size = 2 * pow(2, ceil(log2(n))) - 1;
		seg = new set<int>[size];
		build(0, 0, n - 1, arr);
		while (q--) {
			int l, h;
			cin >> l >> h;
			if (l == h) {
				set<int> ans = query(0, 0, n - 1, 0, n - 1);
				ans.erase(arr[l]);
				cout << ans.size() + 1 << endl;
				continue;
			}
			set<int> one = query(0, 0, l - 1, 0, n - 1);
			set<int> two = query(0, h + 1, n - 1, 0, n - 1);
			one.insert(two.begin(), two.end());
			cout << one.size() << endl;

		}



	}

	return 0;
}
