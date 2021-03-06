// Problem Link - 
/* By Shubham Anand */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
	string s1,s2;

set<string> st;
	// vector<string> st;
void printLCS(int i,int j,string out,vector<vector<ll>> &dp){
	if(i==0||j==0){
		reverse(out.begin(),out.end());
		st.insert(out);
		return;
	}

	if(s1[i-1]==s2[j-1]){
		printLCS(i-1,j-1,out+s1[i-1],dp);
	}else{
		if(dp[i-1][j]>dp[i][j-1]){
			printLCS(i-1,j,out,dp);
		}else{
			if(dp[i-1][j]<dp[i][j-1]){
				printLCS(i,j-1,out,dp);
			}else{
				printLCS(i-1,j,out,dp);
				printLCS(i,j-1,out,dp);
			}
		}
	}
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	ll t;
	cin>>t;
	while(t--){
		vector<vector<ll>> dp(81,vector<ll> (81,0));
		cin>>s1>>s2;

		for(int i=1;i<=s1.size();i++){
			for(int j=1;j<=s2.size();j++){
				if(s1[i-1]==s2[j-1]){
					dp[i][j]=1+dp[i-1][j-1];
				}else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		// for(int i=0;i<=s1.size();i++){
		// 	for(int j=0;j<=s2.size();j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int i=s1.size();
		int j=s2.size();
		string ans="";
		// while(i>0 and j>0){
		// 	if(s1[i-1]==s2[j-1]){
		// 		ans+=s1[i-1];
		// 		i=i-1;
		// 		j=j-1;
		// 	}else{
		// 		if(dp[i-1][j]>dp[i][j-1]){
		// 			i=i-1;
		// 		}else{
		// 			j=j-1;
		// 		}
		// 	}
		// }
		// reverse(ans.begin(),ans.end());
		// cout<<ans<<endl;
		printLCS(i,j,"",dp);
		// sort(all(st));
		for(auto &el:st){
			cout<<el<<endl;
		}
	}






	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

