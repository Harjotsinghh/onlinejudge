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

// this function creates hash of all values that we have calculated for current window since max len=1000 so i've used 1000 as multiplier
ll key(int a, int b, int c, int d) {
	return   d + (b * 1000ll) + (c * 1000000ll) + (d * 1000000000ll);

}
ll find(string s, int l) {
// will use sliding window technique to store no of ones and zeroes of each window of same length
	int number_of_ones = 0, number_of_zeroes = 0;
	int n = s.length();



	// we will count no of even ones and odd ones  seperated by zeroes in each window
	int odd_ones = 0, even_ones = 0;
	loop(i, 0, l - 1) {
		if (s[i] == '1')
			number_of_ones++;
		else
		{
			if (number_of_ones % 2 == 0)
				even_ones++;
			else
				odd_ones++;

			number_of_zeroes++;
		}
	}


	unordered_set<ll> st;
	st.insert(key(number_of_ones, number_of_zeroes, even_ones, odd_ones));

	loop(i, 1, n - l) {
		if (s[i - 1] == '0')
		{
			//if element removed from previous window is zero
			even_ones--;
			number_of_zeroes--;
		}
		else
		{
			//if element removed from previous window is one then we are short of one 1 in current window, so even will become odd and vice versa
			int temp = odd_ones;
			odd_ones = even_ones;
			even_ones = temp;
			number_of_ones--;
		}

		if (s[i + l - 1] == '1')
			number_of_ones++;
		else
		{
			//if element inserted in current window is 0 then we will need to increment even_ones or odd_ones corresponding to inserted 0
			if (number_of_ones % 2 == 0)
				even_ones++;
			else
				odd_ones++;
			number_of_zeroes++;
		}

		st.insert( key(number_of_ones, number_of_zeroes, even_ones, odd_ones));


	}

	return st.size();

}

int main()
{
	io();
	int t = 0;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		ll ans = 0;
		//considering substrings length wise
		loop(i, 1, n) {
			ans += find(s, i);

		}
		cout << ans  << '\n';
	}

	return 0;
}
