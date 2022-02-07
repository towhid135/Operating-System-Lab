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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }
int page = 0;

vector< int > v;

void print(vector< int > &c,bool f){

    if( f ){

        page++;  //counting the page fault

        for(int i = 0; i < 3; i++){

            if(c[ i ] == INT_MAX) cout << "-";
            else cout << c[ i ];
        }
    }
    else for(int i = 0; i < 3; i++) cout << "-";  // if there is no page fault

    cout << endl;
}

bool check(vector< int > &c,int val){

    bool f = true; // the value is new/ absent in the current frame

    for(int i = 0; i < 3; i++)
        if(c[ i ] == val) f = false; // the value is already present

    if( !f ) print(c,f);

    return f;
}

void store(vector< int > &c,int val,int idx){

    map< int,int > mp;

    mp[ c[ 0 ] ] = INT_MAX;
    mp[ c[ 1 ] ] = INT_MAX;
    mp[ c[ 2 ] ] = INT_MAX;

    int cnt = 0;

    for(int i = idx; i < v.size(); i++)
        if(mp[ v[ i ] ] == INT_MAX) mp[ v[ i ] ] = ++cnt;


    int mx = mp[ c[ 0 ] ],x = 0;

    for(int i = 1; i < 3; i++){

        if(mx < mp[ c[ i ] ]){

            mx = mp[ c[ i ] ];
            x = i;
        }
    }

    c[ x ] = val;  // right most value is replacing with the new value

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

        if(c[ i ] == INT_MAX){

            c[ i ] = v[ i ];

            print(c,true);
        }
        else {

            bool f = check(c,v[ i ]); // checking all the values which one is in the right most position

            if( f ) store(c,v[ i ],i);
        }
    }

    cout << "\nPage Fault = " << page << endl;

    return 0;
}
