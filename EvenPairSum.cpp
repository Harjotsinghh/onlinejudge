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
	int t;
	cin >> t;
	while (t--) {

		ll a, b;
		cin >> a >> b;

		int e1 = floor(a / 2);
		int o1 = a - e1;
		int e2 = floor(b / 2);
		int o2 = b - e2;

		cout << (e1 * e2) + (o1 * o2) << endl;
	}

	return 0;
}

