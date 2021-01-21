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

		ll n;
		cin >> n;

		ll arr[n];
		loop(i, 1, n)
		cin >> arr[i - 1];
		if (n < 3)
		{
			cout << 0 << endl;
			continue;
		}


		int val[n];
		//1 ->hill 2->valley 0->nothing
		ll hill = 0;
		ll valley = 0;
		loop(i, 1, n - 2)
		{
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
				val[i] = 1, hill++;
			else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
				val[i] = 2, valley++;

			else
				val[i] = 0;

		}
		val[0] = val[n - 1] = 0;
		// cout << hill + valley << " -" << endl;

		if (hill + valley == 0)
			cout << 0 << endl;
		else
		{
			ll cc1 = 0;
			ll cc2 = 0;
			ll cc3 = 0;
			loop(i, 1, n - 2)
			{
				if (val[i] != 0)
				{
					if (val[i - 1] != 0 && val[i + 1] != 0 && val[i] != val[i - 1]  && val[i - 1] == val[i + 1])
						cc1++;
					else if ((val[i - 1] != 0 || val[i + 1] != 0))
						cc2++;
					else if ( val[i - 1] == 0 && val[i + 1] == 0)
						cc3++;
				}
			}



			if (cc1 > 0)
				cout << ( (hill + valley - 3) <= 0 ? 0 : hill + valley - 3 ) << endl;
			else if (cc2 > 0)
				cout << ((hill + valley - 2) <= 0 ? 0 : hill + valley - 2 ) << endl;
			else if (cc3 > 0)
				cout << ((hill + valley - 1) <= 0 ? 0 : hill + valley - 1 ) << endl;
			else
				cout << hill + valley << endl;
		}

	}

	return 0;
}
