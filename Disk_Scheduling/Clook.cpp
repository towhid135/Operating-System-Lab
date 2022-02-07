#include <bits/stdc++.h>
using namespace std;
vector<int> val;

int main(){
    freopen("scan.txt","r",stdin);
    int low,up,head,add=0,i,j,in,element,hind,siz;
    cin>>low>>up>>head>>element;
    val.push_back(low);
    val.push_back(up);
    val.push_back(head);
    for(i=0; i<element; i++){
        cin>>in;
        val.push_back(in);
    }
    sort(val.begin(),val.end());
    for(i=0; i<val.size(); i++) {
            if(val[i]==head){
                hind = i;
                break;
            }
    }

    siz = val.size();
    cout<<"Path: ";
    for(i=hind; i<siz-1; i++){
        if(i<siz-2) add += val[i+1]-val[i];
        cout<<val[i]<<" ";
    }
    //cout<<endl;
    //siz = val.size()-1;
    add += val[siz-2]-val[1];
    for(i=1; i<hind; i++){
        if(i<hind-1) add += val[i+1] - val[i];
        cout<<val[i]<<" ";
    }
    //cout<<endl;
    //cout<<add;

    //cout<<endl;
    //cout<<add;
    cout<<endl;
    cout<<"absolute difference: "<<add;

return 0;
}


