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
		ll n, x;
		cin >> n >> x;
		ll sum = 0;
		ll arr[n];
		loop(i, 1, n)
		{
			cin >> arr[i - 1];
			sum += arr[i - 1];
		}
		if (n == 0)
		{
			cout << 0 << endl;
			continue;

		}



		if (x == 0) {
			cout << sum << endl;
			continue;
		}
		queue<pair<ll, int>> q;
		ll i = 0;
		while (i < n)
		{
			if (arr[i] % x == 0 && arr[i] != 0)
			{
				q.push({arr[i] / x, 1});
				sum += arr[i];
			}
			else
				break;
			i++;

		}

		if (i == n) {
			while (!q.empty()) {
				ll fr = q.front().first;
				ll pp = q.front().second;
				q.pop();

				if (fr % x == 0)
				{
					sum += fr * powl(x, pp);
					q.push({fr / x, pp + 1});

				}
				else
					break;

			}

		}
		cout << sum << '\n';




	}

	return 0;
}
