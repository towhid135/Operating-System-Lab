#include <bits/stdc++.h>
using namespace std;
queue<int> qu;

int main(){
    freopen("fcfs.txt","r",stdin);

    int head,qsize,i,j,add=0,value,hold;
    cin>>qsize>>head;
    //add = head;
    cout<<"path: "<<head<<" ";
    for(i=0; i<qsize; i++){
        cin>>value;
        qu.push(value);
        cout<<value<<" ";
    }
    cout<<endl;
    while(!qu.empty()){
        hold = qu.front();
        qu.pop();
        if(hold-head< 0){
            add += (hold - head)*(-1);
            head = hold;  // head position changing
        }
        else{
            add += (hold-head);
            head = hold;
        }

    }
    cout<<"total distance: "<<add<<endl;

return 0;
}
