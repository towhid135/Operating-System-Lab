#include <bits/stdc++.h>
using namespace std;
vector<int> val;

int main(){
    freopen("scan.txt","r",stdin);
    int low,up,head,add=0,i,j,in,element,hind,siz;
    cin>>low>>up>>head>>element;
    val.push_back(low);
    val.push_back(head);
	val.push_back(up);
    for(i=0; i<element; i++){
        cin>>in;
        val.push_back(in);
    }
    sort(val.begin(),val.end()); //sorting
	
	
    for(i=0; i<val.size(); i++) {
            if(val[i]==head){
                hind = i;
                break;
            }
    }
    cout<<"Path: ";
    for(i=hind; i>=0; i--){
        if(i!=0){
            add += val[i]-val[i-1];
        }
        cout<<val[i]<<" ";
    }
    //cout<<endl;
    //cout<<add;
    siz = val.size()-1;
    for(i=hind; i<siz; i++){
        if(i==hind) add += val[hind+1];
        else if(i<siz-1) add+= val[i+1]-val[i];
        if(i>hind) cout<<val[i]<<" ";
    }
    //cout<<endl;
    //cout<<add;
    cout<<endl;
    cout<<"absolute difference: "<<add;

return 0;
}
