/*
 ________         ___          ___    ___     ___  ___         ________         ________         ___  __           ___     
|\   __  \       |\  \        |\  \  /  /|   |\  \|\  \       |\_____  \       |\   __  \       |\  \|\  \        |\  \    
\ \  \|\  \      \ \  \       \ \  \/  / /   \ \  \\\  \       \|___/  /|      \ \  \|\  \      \ \  \/  /|_      \ \  \   
 \ \   _  _\      \ \  \       \ \    / /     \ \  \\\  \          /  / /       \ \   __  \      \ \   ___  \      \ \  \  
  \ \  \\  \|      \ \  \       \/  /  /       \ \  \\\  \        /  /_/__       \ \  \ \  \      \ \  \\ \  \      \ \  \ 
   \ \__\\ _\       \ \__\    __/  / /          \ \_______\      |\________\      \ \__\ \__\      \ \__\\ \__\      \ \__\
    \|__|\|__|       \|__|   |\___/ /            \|_______|       \|_______|       \|__|\|__|       \|__| \|__|       \|__|
                             \|___|/                                                                                       */

#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)    substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)     cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void in_out()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  FIO;
}


int32_t main(){
  in_out();

  int n;
  cin>>n;
  int e;
  cin>>e;
  vector<vector<int> > edges;
  for(int i =0;i<e;i++){
    int a,b,c;
    cin>>a>>b>>c;
    edges.push_back({a,b,c});
  }

  vector<int> dist(n,1000000007);
  int src;
  cin>>src;

  dist[src] = 0;
  // Answer will be calculated in n-1 passes.
  for(int i =0;i<n-1;i++){
    for(auto j : edges){
      int u = j[0];
      int v = j[1];
      int wt = j[2];
      dist[v] = min(dist[v],dist[u] +wt);
    }
  }

  for(auto i : dist){
    cout<<i<<" ";
  }cout<<endl;


  return 0;
}