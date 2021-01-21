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
		ll n, m, x;
		cin >> n;

		deque<ll> negative[n + 1], positive[n + 1];
		loop(i, 1, n) {
			cin >> m;
			loop(j, 1, m) {
				cin >> x;
				if (x < 0)
					negative[i].push_back(x);
				else
					positive[i].push_back(x);
			}
		}
		ll ans = 0;

		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

		loop(i, 1, n) {
			if (!negative[i].empty())
				pq.push({abs(negative[i].back()), i});
			if (!positive[i].empty())
				pq.push({positive[i].front(), i});

		}

		while (!pq.empty()) {

			vector<pair<ll, ll>> st;
			pair<ll, ll>  curr = pq.top();
			st.push_back(curr);
			pq.pop();
			while (!pq.empty() && pq.top().first == curr.first)
			{
				st.push_back(pq.top());
				// cout << pq.top().first << " ";
				pq.pop();
			}

			if (st.size() == 1)
			{
				ll ind = st.begin()->second;
				// ll ele = st.begin()->first;
				// cout << ele << " ";

				if (!negative[ind].empty() && !positive[ind].empty())
				{
					ll pt = negative[ind].back() + positive[ind].front();
					if (pt < 0) {
						ans += negative[ind].size() ;
						positive[ind].pop_front();
						if (!positive[ind].empty())
							pq.push({abs(positive[ind].front()), ind});

					}
					else {
						ans += positive[ind].size() ;
						negative[ind].pop_back();
						if (!negative[ind].empty())
							pq.push({abs(negative[ind].back()), ind});

					}

				}
				else if (!negative[ind].empty()) {
					negative[ind].pop_back();
					if (!negative[ind].empty())
						pq.push({abs(negative[ind].back()), ind});

				}
				else if (!positive[ind].empty()) {
					positive[ind].pop_front();
					if (!positive[ind].empty())
						pq.push({abs(positive[ind].front()), ind});

				}


			}
			else {

				for (auto it : st) {

					ll ind = it.second;
					ll ele = it.first;
					// cout << ele << " ";
					if (!negative[ind].empty() && abs(negative[ind].back()) == ele) {
						ans += negative[ind].size() - 1;
						negative[ind].pop_back();
						if (!negative[ind].empty())
							pq.push({abs(negative[ind].back()), ind});

					}
					if (!positive[ind].empty() && positive[ind].front() == ele) {
						ans += positive[ind].size() - 1;
						positive[ind].pop_front();
						if (!positive[ind].empty())
							pq.push({abs(positive[ind].front()), ind});
					}
				}

				ans += 1;

			}

		}
		cout << ans << endl;

	}

	return 0;
}
