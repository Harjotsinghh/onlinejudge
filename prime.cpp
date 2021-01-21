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
	vector<int> primes;
	vector<int> non_primes;
	bool vis[50001];
	memset(vis, false, sizeof(vis));

	loop(i, 2, 50000)
	{

		if (!vis[i])primes.pb(i);
		else {
			non_primes.pb(i);
			continue;
		}

		for (int j = i + i; j <= 50000; j += i) {
			vis[j] = true;
		}
	}
	for (auto it : non_primes)
		cout << it << ",";

	return 0;
}
