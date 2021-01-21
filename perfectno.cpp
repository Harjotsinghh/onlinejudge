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
bool check(ll n) {
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum == 10;
}

int main()
{
	io();
	ll k;
	cin >> k;

	ll curr = 19;
	while (--k) {
		curr += 9;
		while (!check(curr))
			curr += 9;
	}
	cout << curr << endl;





	return 0;
}
