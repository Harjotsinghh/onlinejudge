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
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.length();

		int no_of_ones[n][n];
		loop(i, 1, n) {
			int ones = 0;
			loop(j, i, n) {
				if (s[j - 1] == '1')
					ones++;
				no_of_ones[i - 1][j - 1] = ones;

			}
		}
		unordered_set<string> st;

		int ans = 0;

		//considering all substrings of length 1 and 2
		unordered_set<string> dp[n][n];

		loop(i, 1, n) {
			//string with length 1
			if (st.find(s.substr(i - 1, 1)) == st.end()) {
				ans ++;
				// cout << ": " << ans << " " << s.substr(i - 1, 1) << endl;
				st.insert(s.substr(i - 1, 1));
				dp[i - 1][i - 1].insert(s.substr(i - 1, 1));
			}

			//string with length two
			if (i + 1 <= n) {
				if (st.find(s.substr(i - 1, 2)) == st.end() ) {
					ans ++;
					// cout << ": " << ans << " " << s.substr(i - 1, 2) << endl;
					st.insert(s.substr(i - 1, 2));
					dp[i - 1][i].insert(s.substr(i - 1, 2));

				}
			}
		}

		//considering all substrings of length >=3

		loop(i, 3, n) {
			loop(j, 0, n - i ) {
				int k = i + j - 1;

				bool f = (no_of_ones[j][k] != 0 && no_of_ones[j][k] % 2 == 0);
				bool flag = false;
				//hereby three cases are possible for substring s[j]..s[k]
				//case 1: s[j+1]...s[k] has even ones

				for (auto it : dp[j + 1][k]) {
					string curr = s[j] + it;
					// cout << s[j] << " " << it << " :" << curr << endl;
					if (st.find(curr) != st.end()) {
						flag = true;
					}
					else {
						dp[j][k].insert(curr);
						if (f)
						{
							reverse(curr.begin(), curr.end());
							if (st.find(curr) != st.end()) {
								flag |= true;
							}
							dp[j][k].insert(curr);
						}
					}

				}


				//case 2: s[j+1]..s[k-1]  has even ones
				for (auto it : dp[j + 1][k - 1]) {

					string curr = s[j] + it + s[k];
					// cout << curr << endl;
					if (st.find(curr) != st.end()) {
						flag = true;
					}
					else {
						dp[j][k].insert(curr);
						if (f)
						{
							reverse(curr.begin(), curr.end());
							if (st.find(curr) != st.end()) {
								flag |= true;
							}
							dp[j][k].insert(curr);
						}
					}

				}

				//case 3:  s[j][k-1] has even ones

				for (auto it : dp[j][k - 1]) {
					string curr = it + s[k];
					// cout << curr << endl;
					if (st.find(curr) != st.end()) {
						flag = true;
					}
					else {
						dp[j][k].insert(curr);
						if (f)
						{
							reverse(curr.begin(), curr.end());
							if (st.find(curr) != st.end()) {
								flag |= true;
							}
							dp[j][k].insert(curr);
						}
					}

				}
				if (flag == false && st.find(s.substr(j, i)) == st.end())
				{
					ans += 1;

				}

				for (auto it : dp[j][k])
					st.insert(it);

			}

		}
		// for (auto it : st)
		// 	cout << it << endl;

		cout << ans << endl;


	}

	return 0;
}
