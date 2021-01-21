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
map < int, vector<pair<int, int>>> mp;
vector < pair<int, int>> ans;
map<int, int> freq;
int removed;
int total;

bool find(int sum, int i, int j ) {
	// cout << i << " :" << freq[i] << " " << j << " :" << freq[j] << " ," << removed << endl;

	freq[i]--;
	freq[j]--;
	removed += 2;

	ans.push_back({i, j});
	if (removed == total )
		return true;
	int next_sum = max(i, j);
	for (auto it : mp[next_sum]) {
		int x = it.first, y = it.second;
		if (x == y)
			if (freq[x] < 2)
				continue;
		if ((freq[x] <= 0 || freq[y] <= 0))
			continue;
		if (find(next_sum, x, y))
			return true;

	}
	ans.pop_back();
	freq[i]++; freq[j]++;
	removed -= 2;
	return false;

}
int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		total = 2 * n;
		int m = n * 2;
		int arr[m];
		freq.clear();
		int max_ele = INT_MIN;
		loop(i, 0, m - 1)
		cin >> arr[i], freq[arr[i]]++, max_ele = max(max_ele, arr[i]);

		ans.clear();
		mp.clear();
		loop(i, 0, m - 2)
		{
			loop(j, i + 1, m - 1)
			mp[arr[i] + arr[j]].push_back({arr[i], arr[j]});
		}
		removed = 0;
		ll res = -1;
		for (auto it = mp.rbegin(); it != mp.rend(); it++) {
			if (it->first <= max_ele)
				break;
			if (it->second.size() > 1)
				continue;
			for (auto it1 : it->second) {
				if (find(it->first, it1.first, it1.second))
				{
					res = it->first; break;
				}

			}
			removed = 0;
			if (res != -1)
				break;

			ans.clear();
		}

		if (res != -1)
		{
			cout << "YES" << endl << res << endl;
			for (auto it : ans)
				cout << it.first << " " << it.second << endl;
		}
		else
			cout << "NO" << endl;

	}

	return 0;
}
