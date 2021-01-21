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
bool check(string s) {
	int i = 0, j = s.length() - 1;
	while (i <= j)
	{
		if (s[i] != s[j])
			return false;


		i++; j--;
	}
	return true;
}
int main()
{
	io();
	string s;
	cin >> s;
	int n = s.length();
	int j = n - 1;
	if (check(s))
	{
		cout << 0 << endl;
		return 0;
	}
	while (j > 1) {
		if (s[j] == s[0])
			break;
		j--;
	}
	if (j != 1) {
		cout << 2 << endl;
		cout << "R" << " " << j << endl;
		cout << "R" << " " << n + (n - j) - 1 << endl;
		return 0;
	}
	int i = n - 2;
	while (i < n - 2) {
		if (s[i] == s[n - 1])
			break;
		i++;
	}
	if (i != n - 1) {
		cout << 2 << endl;
		cout << "L" << " " << i + 1 << endl;
		cout << "L" << " " << 2 << endl;
		return 0;
	}
	return 0;



}
