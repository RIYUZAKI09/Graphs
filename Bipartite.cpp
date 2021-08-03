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

// void Djikstra()

int32_t main(){
  in_out();
  int n;
  cin>>n;
  vector<int> adj[n];
  int e;
  cin>>e;
  for(int i =0;i<e;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> colored (n,-1);
  colored[0] = 0;

  queue<int> q;
  q.push(0);
  bool alpha = true;
  while(!q.empty()){
    int k = q.front();
    q.pop();
    for(auto child : adj[k]){
      if(colored[child] == -1){
        colored[child] = 1-colored[k];
        q.push(child);
      }else if(colored[child] == colored[k]){
        alpha = false;
        break;
      }
    }
  }

  for(int i =0;i<colored.size();i++) cout<<colored[i]<<" ";
    cout<<endl;
  if(alpha) cout<<"Bipartite"<<endl;
  else cout<<"Not Bipartite"<<endl;


  return 0;
} 