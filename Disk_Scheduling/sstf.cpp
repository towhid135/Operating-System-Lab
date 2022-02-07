#include <bits/stdc++.h>
using namespace std;
queue<int> qu;
vector<int> holdRange,Qval;

int main(){
    freopen("fcfs.txt","r",stdin);

    int head,qsize,i,j,add=0,value,hold,mini=10000,indx,diff;
    cin>>qsize>>head;
    //add = head;
    cout<<"path: "<<head<<" ";
    for(i=0; i<qsize; i++){
        cin>>value;
        Qval.push_back(value);
    }

    for(i=0; i<=Qval.size(); i++){
        for(j=0; j<Qval.size(); j++){
            if(Qval[j]!=-1){

                if(Qval[j]-head < 0) diff = (Qval[j]-head)*(-1);
                else diff = (Qval[j]-head);
                if(diff<mini){
                    indx = j;
                    mini = diff;
                }

            }
        }
        if(i!=Qval.size()){
                cout<<Qval[indx]<<" ";
                add += mini;
        }
        head = Qval[indx];
        Qval[indx] = -1;
        mini = 10000;
    }


    cout<<endl;
    cout<<"total distance: "<<add<<endl;

return 0;
}

