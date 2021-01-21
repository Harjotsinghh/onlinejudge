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
		int n, d, x;
		cin >> n >> d;
		int gt = 0;
		vector<int>lower;
		loop(i, 1, n)
		{
			cin >> x;
			if (x > d) {
				gt++;
			}
			else {
				lower.pb(x);

			}
		}
		sort(lower.begin(), lower.end());
		if (gt == 0) {
			cout << "YES" << endl;
		}
		else {
			if (lower.size() < 2) {
				cout << "NO" << endl;
			}
			else
			{
				if (lower[0] + lower[1] <= d)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}

		}



	}

	return 0;
}
