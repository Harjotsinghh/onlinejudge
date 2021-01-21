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
	while (t--) {
		int n;
		cin >> n;
		int cc = (n - 1);
		int no = cc / 2;
		int off = 1;
		int cd = cc;
		loop(i, 1, cc / 2) {

			loop(k, off, cd - 1)
			if (k <= no)
				cout << " ";
			else
				cout << k;
			no--;
			cd--;
			cout << endl;

		}
		cc = (n - 1);
		no = cc / 2;

		loop(i, 1, no - 1)
		cout << i;
		cout << endl;
		cd = no;
		int sp = 1;
		loop(i, 1, no ) {
			loop(k, 1, cd)
			if (k <= sp)
				cout << " ";
			else
				cout << k;
			cd++;
			sp++;
			cout << endl;
		}


	}
	return 0;
}
