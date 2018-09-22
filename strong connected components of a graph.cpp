#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>

using namespace std;
const int maxn = 1000;
long n;
int color[maxn];
map<int, vector<int>> adjacency_list;
map<int, vector<int>> transpose;
stack<int> inventory;
stack<int> reverse_invent;

void init(){
    memset(color, 0, sizeof(color));
}

void turn_graph(){
    for(auto it:adjacency_list){
        for(int c:it.second){
            if(transpose.find(c) == transpose.end()){
                transpose[c] = vector<int> ();
            }
            transpose[c].push_back(it.first);
        }
    }
}
void dfs_visit(int cur, map<int, vector<int>> adjacency_list, stack<int>& invent){
    color[cur] = 1;
    for(auto i:adjacency_list[cur]){
        if(color[i]==0) dfs_visit(i, adjacency_list, invent);
    }
    color[cur] = 2;
    invent.push(cur);
}

void dfs_global(map<int, vector<int>>& adjacency_list){
    init();
    for(auto it:adjacency_list){
        if(color[it.first]==0){
            dfs_visit(it.first, adjacency_list, inventory);
        }
    }
}

void dfs_global_reverse(){
    init();
    while(!inventory.empty()){
        int it = inventory.top();
        inventory.pop();
        if(color[it]==0){
            dfs_visit(it, transpose,reverse_invent);
            while(!reverse_invent.empty()){
                cout<<reverse_invent.top()<<" ";
                reverse_invent.pop();
            }
            cout<<"one tree"<<endl;
        }
    }
}

void input(){
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        auto it = adjacency_list.find(a);
        if(it==adjacency_list.end()){
            adjacency_list[a] = vector<int> ();
        }
        adjacency_list[a].push_back(b);
    }
}


int core(){
    input();
    dfs_global(adjacency_list);
    turn_graph();
    dfs_global_reverse();
    return 0;
}

int main(){
    core();
    return 0;
}
