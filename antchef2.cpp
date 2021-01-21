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
		int n, m, x; cin >> n;

		map<ll, ll> mp;
		set<ll> dist;
		deque<ll> negative[n + 1];
		deque<ll> positive[n + 1];

		loop(j, 1, n) {
			cin >> m;
			loop(i, 1, m) {
				cin >> x;
				// if (x == 0)
				// 	continue;
				if (x < 0)
					negative[j - 1].push_back(x);
				else
				{
					positive[j - 1].push_back(x);
				}

				mp[abs(x)]++;
			}

		}
		ll ans = 0;
		auto it = mp.begin();
		// for (auto it : mp)
		// 	cout << it.first << " ";
		while (it != mp.end())
		{
			ll smallest = it->first;
			cout << smallest << " ";

			if (it->second == 1)
			{
				loop(i, 0, n - 1)
				{
					if (negative[i].empty() && positive[i].empty())
						continue;

					if ((!negative[i].empty() && abs(negative[i].back()) == smallest) || (!positive[i].empty() && positive[i].front() == smallest))
					{

						double next = ((double)negative[i].back() + positive[i].front()) / 2;
						if (next > 0) {
							negative[i].pop_back();
							ans += positive[i].size() ;

						}
						else if (next < 0) {
							positive[i].pop_front();
							ans += negative[i].size();
						}
						break;

					}
					else if (positive[i].empty() && abs(negative[i].back()) == smallest)
					{
						negative[i].pop_back();
					}
					else if (negative[i].empty() && positive[i].front() == smallest)
						positive[i].pop_front();




				}
			}
			else if (it->second > 1)
			{


				loop(i, 0, n - 1)
				{
					if (positive[i].empty() && negative[i].empty())
						continue;

					if (!negative[i].empty() && abs(negative[i].back()) == smallest)
					{
						ans += negative[i].size() - 1;
						negative[i].pop_back();


					}
					if (!positive[i].empty() && abs(positive[i].front()) == smallest)
					{
						ans += positive[i].size() - 1;
						positive[i].pop_front();

					}

				}

				ans += 1;
			}

			it++;
		}


		cout << ans << endl;
	}

	return 0;
}
