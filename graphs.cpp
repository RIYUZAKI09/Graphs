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

void DFS(vector<int> *arr, int *visited , int k){
  visited[k] = 1;
  // cout<<k<<"->";
  for(auto child:arr[k]){
    if(visited[child] == 0){
      DFS(arr,visited,child);
    }
  }
}

int connected_components(vector<int> *arr,int n, int* visited, int k){
  int count = 0;
  for(int i = 0;i<n;i++){
    if(visited[i] == 0){
      DFS(arr,visited,i);
      count++;
    }
    
  }
  return count;
}


bool isTree(vector<int> *arr, int n, int e){
  int visited[n] = {0};
  if(connected_components(arr, n, visited,0) == 1 and e == n-1){
    return true;
  }else{
    return false;
  }
}

void single_source_shortest_path(vector<int> *arr, int n, int *visited,int* distance, int k, int dis){
  visited[k] = 1;
  distance[k] = dis;

  for(auto child : arr[k]){
    if(visited[child] == 0){
      single_source_shortest_path(arr,n,visited,distance,child,distance[k] +1);
    }
  }
}

bool isBipartite(vector<int> *arr, int *visited, int* colored, int node, int color){
  visited[node] = 1;
  colored[node] = color;

  for(auto child:arr[node]){
    if(visited[child] == 0 and !isBipartite(arr,visited,colored,child, color^1)){
      return false;
    }else{
      if(colored[node] == colored[child]) return false;
    }
  }
  return true;
}

bool cycle(vector<int> *arr,int* visited, int node, int parent){
  visited[node] = 1;
  for(auto child: arr[node]){
    if(visited[child] == 0 ){
      if(cycle(arr,visited,child,node) /* for other nodes dumbass. */) return true;
    }else{
      if(child != parent){ // this is cus the parent is one node behind the child and cycle of min 3 is possible and parent must be one behind
        return true;
      }
    }
  }
  return false;
}


int timer = 1;
void InOut1st(vector<int> *arr, int *visited, int node, int *in, int *out){
  visited[node] = 1;
  in[node] = timer++;
  for(auto child:arr[node]){
    if(visited[child] == 0){
      InOut1st(arr,visited,child,in,out);
    }
  }
  out[node] = timer++;
}



int maxDis, maxNode = 0;
void Diameter(vector<int> *arr, int *visited, int node, int dis){
  maxDis = -1;
  visited[node] = 1;
  if(dis > maxDis){
    maxDis = dis;
    maxNode = node;
  } 

  for(auto child: arr[node]){
    if(visited[child] == 0){
      Diameter(arr,visited,child,dis+1);
    }
  }
}

void BFS(vector<int> *arr, int k,int* visited){
  queue<int> q;
  q.push(k);
  visited[k] = 1;


  while(!q.empty()){
    int z = q.front();
    q.pop();
    cout<<z<<" ";
    for(auto child: arr[z]){
      if(visited[child] == 0){
        q.push(child);
        visited[child] = 1;
      }
    }
  }
  cout<<endl;
}

void topological(vector<int> *arr, vector<int> &indeg,int n){
  queue<int> q;
  int count = 0;
  for(int i =0;i<n;i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }
  while(!q.empty()){
    count++;
    int x = q.front();
    cout<<x<<" ";
    q.pop();
    for(auto child : arr[x]){
      indeg[child]--;
      if(indeg[child] == 0){
        q.push(child);
      }
    }
  }
  cout<<endl;
}



int32_t main()
{
  in_out();
  int n;
  cin>>n;
  vector<int> arr[n];
  vector<int> indeg(n,0);
  w(e){
    int a,b;
    cin>>a>>b;
    indeg[a]++;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
  for(int i =0;i<n;i++){
    cout<<"List of "<<i<<" is: ";
    for(auto k : arr[i]){
      cout<<k<<" -> ";
    }
    cout<<endl;
  }


  int visited[n] = {0};
  DFS(arr,visited,0);
  cout<<"DFS";
  cout<<endl;


  int visited1[n] = {0};
  cout<<"CC ";
  cout<<connected_components(arr,n,visited1,0)<<endl;


  int visited2[n] = {0};
  int distance[n] = {0};
  cout<<"SSSP ";
  single_source_shortest_path(arr,n,visited2,distance,0,0);
  for(int i =0;i<n;i++){
    cout<<distance[i]<<" ";
  }cout<<endl;

  if(isTree(arr,n,e)) cout<<"Is Tree: "<<1<<endl;
  else cout<<"Not a tree"<<endl;


  int visited3[n] = {0}, colored[n] = {0} , color = 0;
  // if(isBipartite(arr,visited3,colored,0,color)) cout<<"Bipartite"<<endl;
  // else cout<<"Not Bipartite"<<endl;

  // for multiple connected components, check for every node.
  bool k  = true;
  for(int i =0;i<n;i++){
    if(visited3[i] == 0){
      if(isBipartite(arr,visited3,colored,0,color)) k = true;
      else k = false;
    }
  }
  if(k) cout<<"Bipartite"<<endl;
  else cout<<"Not Bipartite"<<endl;


  int visited4[n] = {0};
  if(cycle(arr,visited4,0,1)) cout<<"Cycle Detected"<<endl;
  else cout<<"No cycle present"<<endl;



  int visited5[n] = {0}, in[n] = {0}, out[n] = {0};
  InOut1st(arr,visited5,0,in,out);
  cout<<"In time array: ";
  for(int i: in) cout<<i<<" ";
  cout<<endl;
  cout<<"Out time array is: ";
  for(int i: out) cout<<i<<" ";
  cout<<endl;

  
  
  int visited6[n] = {0};
  maxDis = -1;
  int dia = 0;
  for(int i =0;i<n;i++){
    maxDis = 0;
    for( auto j: visited6) visited6[j] = 0;
    Diameter(arr,visited6,i,0);
    cout<<maxDis<<" ";
    // maxDis = -1;
    // Diameter(arr,visited6,maxNode,0);
    dia = max(dia,maxDis);
    maxDis = 0;
  }
  cout<<"Diameter of the graph is : "<<dia<<endl;

  int visited7[n] = {0};
  int kj = 0;

  BFS(arr,kj,visited7);

  topological(arr,indeg,n);
  
  return 0;
}
