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
	int n, x;
	cin >> n;
	ll p = powl(2, n);
	vector < pair < ll, int>> arr;
	loop(i, 1, p)
	{
		cin >> x;
		arr.pb({x, i});
	}
	int ans;
	reverse(arr.begin(), arr.end());
	loop(i, 1, n) {
		vector<pair<ll, int>> temp;
		ll cn = powl(2, n - i);
		loop(j, 1, cn)
		{
			bool f = arr.size() == 2;
			pair<ll, int> cc1 = arr.back();
			arr.pop_back();
			// cout << cc.second << " ";
			pair<ll, int> cc2 = arr.back();
			arr.pop_back();

			if (cc1.first < cc2.first)
			{
				if (f)
					ans = cc1.second;

				temp.push_back(cc2);
			}
			else
			{
				if (f)
					ans = cc2.second;
				temp.push_back(cc1);
			}

		}

		for (auto it = temp.rbegin(); it != temp.rend(); it++)
			arr.push_back(*it);

	}

	cout << ans << endl;

	return 0;
}
