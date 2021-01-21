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
	int t = 0;
	cin > t;
	while (t--) {
		string s;
		cin >> s;
		string a = "kick", b = "start";
		int kick = 0;
		int start = 0;
		int lps[4] = {0, 0, 0, 1};
		int lps2[5] = {0, 0, 0, 0, 0};
		int k_c[s.length()];
		int s_c[s.length()];
		memset(dp, 0, sizeof(dp));
		int i = 0, j = 0, k = 0;
		k_c[0] = 0;
		while (i < n - 1) {
			if (s[i] == a[j]) {
				i++;
				j++;
			}
			if (j == 4) {
				k_c[i] = 1 + k_c[i - 1];
				j = lps
			}



		}

		i = 0;
		while (i < n - 1) {

		}
	}

	return 0;
}
