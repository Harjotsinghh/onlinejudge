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
	fastio
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string no = "989";

		string rep = "0123456789";
		int cc = 3;
		while (cc < n) {
			no += rep;
			cc += 10;
		}
		while (cc > n) {
			no.pop_back();
			cc--;


		}

		cout << no << endl;
	}

	return 0;
}
