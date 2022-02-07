#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}


vector< int > v;
int page = 0,idx = 0;

void print(vector< int > &c,bool f){

    if( f ){

        page++;  // page fall counting

        for(int i = 0; i < 3; i++){

            if(c[ i ] == INT_MAX) cout << "-";
            else cout << c[ i ];
        }
    }
    else for(int i = 0; i < 3; i++) cout << "-"; // if there is no page fault then only print underscore

    cout << endl;
}

bool check(vector< int > &c,int val){ //checking weather the value is already in or not

    bool f = true;

    for(int i = 0; i < 3; i++)
        if(c[ i ] == val) f = false;

    if( !f ) print(c,f);

    return f;
}

void store(vector< int > &c,int val){

    c[ idx ] = val;

    idx++;
    idx %= 3;
    print(c,true);
}
int main(){

    file();

    int n;

    while(cin >> n) v.pb( n );
    vector< int > c(4,0);

    c[ 0 ] = INT_MAX;
    c[ 1 ] = INT_MAX;
    c[ 2 ] = INT_MAX;

    for(int i = 0; i < v.size(); i++){

        if(c[ i ] == INT_MAX){ // if index is empty (INT_MAX)

            c[ i ] = v[ i ];

            print(c,true);
        }
        else {  // if index is not empty

            bool chk = check(c,v[ i ]); //checking that weather the v[i] already in c

            if( chk ) store(c,v[ i ]);
        }
    }

    cout << "\nPage Fault = " << page << endl;

    return 0;
}
