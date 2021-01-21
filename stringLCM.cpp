#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
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
int gcd(int m, int n) {
	if (m == 0) return n;
	if (n == 0) return m;
	if (m == n) return n;
	if (m > n)
		return gcd(m - n, n);
	return gcd(m, n - m);
}

int lcm(int a, int b) {
	return (a * b) / (gcd(a, b));
}

int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;

		int n = a.length(), m = b.length();
		if (n % m != 0 || n < m) {
			int o = lcm(n, m) / n;
			// cout << o << endl;
			string temp = a;
			while (--o) {
				a += temp;
			}
		}
		// cout << a << endl;
		int nl = a.length();
		bool f = true;
		for (int i = 0; i < nl; i += m) {
			string d = a.substr(i,  m);
			// cout << d << "::";
			if (d != b) {
				f = false;
				break;
			}

		}
		if (!f)
			cout << -1 << endl;
		else {
			cout << a << endl;
		}


	}

	return 0;
}
