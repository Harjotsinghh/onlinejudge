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
struct tpl {
	int h, w, ind;
	bool operator<(const tpl &a) const {
		return tie()
	}
}

int main()
{

	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<tpl> ht;
		vector<tpl> wt;

		loop(i, 0, n - 1) {
			int a, b;
			cin >> a >> b;
			ht.push_back({a, b, i});
			wt.push_back({b, a, i});

		}

		sort(ht.begin(), ht.end(), mysort);
		sort(wt.begin(), wt.end(), mysort);



	}
	return 0;
}