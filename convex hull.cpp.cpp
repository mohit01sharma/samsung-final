#include <bits/stdc++.h>
using namespace std;

int cou;
int dx[8]={-2,2,1,-1,-2,2,1,-1};
int dy[8]={1,1,2,2,-1,-1,-2,-2};

int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r){
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);
 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}

bool cmp(pair<int,int> &a, pair<int,int>pair<int,int> &b){
    if(a.first==b.first&&a.second==b.second)
        cou++;
    
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

bool myFunc(pair<int,int> &a, pair<int,int> &b){
    return (a.first==b.first && a.second==b.second);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if (n < 3){
            cout << "-1";
            continue;    
        } 
	    pair<int,int> points[n];
	    for(int i=0;i<n;i++){
	        cin>>points[i].first>>points[i].second;
	    }
	    int l=0;
	    int min_x=points[0].first;
	    for(int i=1;i<n;i++){
	        if(min_x>points[i].first){
	            min_x=points[i].first;
	            l=i;
	        }
	    }
	    int p=l,q;
	    vector<pair<int,int>> convex;
	    do{
	        convex.push_back(points[p]);
	        q=(p+1);
	        for(int i=0;i<n;i++){
	            if(orientation(points[p],points[i],points[q])==2){
	                q=i;
	            }
	        }
	        p=q;
	    }while(p!=l);
	    cou=0;
	    sort(convex.begin(),convex.end(),comp);
	    auto it=unique(convex.begin(),convex.end(),func);
	    convex.erase(it,convex.end());
	    if(n < 4 && cou > 0 || convex.size()<3) cout<<-1;
	    else{
	        for (int i = 0; i < convex.size(); i++){
            if(i != convex.size() - 1)
                cout << convex[i].first << " " << convex[i].second << ", ";
            else
                cout << convex[i].first << " " << convex[i].second; 
        }
	    }
	}
}
