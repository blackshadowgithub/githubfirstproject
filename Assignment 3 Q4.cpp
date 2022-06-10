
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, Q, t, a, b;
ll x[maxN+1], ds[maxN+1];

    

    
void add(int idx, ll delta){
    ll diff = delta - x[idx];
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += diff;
    x[idx] = delta;
}

ll sum(int idx){
    ll ret = 0;
    for(int i = idx; i > 0; i -= -i&i)
        ret += ds[i];
    return ret;
} 

int main(){
        cin>>N>>Q;
    for(int i = 1; i <= N; i++){
        cin>> x[0];
        add(i, x[0]);
    }
    for(int q = 0; q < Q; q++){
        cin>>t>>a>>b;
        if(t == 1)  add(a, b);
        else        cout<< sum(b)-sum(a-1)<<endl;
    }

	// your code goes here
	return 0;
}
