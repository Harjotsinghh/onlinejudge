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
		int n;
		cin >> n;
		int m = 2 * n;
		int arr[m];
		loop(i, 1, m)
		cin >> arr[i - 1];
		vector<pair<int, int>> ans;
		int res = -1;
		sort(arr, arr + m);
		loop(i, 0, m - 2) {
			ans.push_back({arr[i], arr[m - 1]});
			multiset<int> mp;
			loop(j, 0, m - 2)
			if (j != i)
				mp.insert(arr[j]);
			bool flag = true;
			int sum = arr[m - 1];
			while (!mp.empty()) {
				int last = *mp.rbegin();

				mp.erase(mp.find(last));
				int next_to_rem = sum - last;

				if (mp.find(next_to_rem) != mp.end())
				{
					ans.pb({next_to_rem, last});
					mp.erase(mp.find(next_to_rem));
					sum = last;


				}
				else
				{
					flag = false;
					break;
				}


			}

			if (flag)
			{
				res = arr[i] + arr[m - 1];
				break;
			}
			else
				ans.clear();


		}
		if (res != -1)
		{
			cout << "YES" << endl << res << endl;
			for (auto it : ans)
				cout << it.first << " " << it.second << endl;

		}
		else
			cout << "No" << endl;

	}

	return 0;
}
