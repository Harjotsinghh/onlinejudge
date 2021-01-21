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
	int n, m;
	cin >> n >> m;
	double ans = -1;
	while (n--) {
		int a , b;
		cin >> a >> b;
		double val = ((double)a / b) * m;
		if (ans == -1)
			ans = val;
		else
			ans = min(ans, val);

	}

	cout << setprecision(6) << fixed << ans << endl;
	return 0;
}
