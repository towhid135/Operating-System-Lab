#include <bits/stdc++.h>
using namespace std;
pair<string,int> pa;
queue< pair<string,int> > qu;
vector<int> Wait,Btime;
vector<string> key;
map<string,int> Mark;
int main(){

char ara[2];
int i,j,add=0,quantam,Pnumber,value,step=0;
float waitingTime;

freopen("round_robin.txt","r",stdin);

//cout<<"Enter Quantam Number: ";
cin>>quantam;
//cout<<"Enter Total process Number: ";
cin>>Pnumber;

for(i=0; i<Pnumber; i++){
    scanf("%s %d",ara,&value);
    pa.first = ara;
    pa.second = value;
    qu.push(pa);
    key.push_back(ara);
    Btime.push_back(value);
    //cout<<process[i]<<" "<<Btime[i]<<endl;
}

while(!qu.empty()){

    pa = qu.front();
    qu.pop();
    if(step==0){
        if(pa.second>quantam){
            Wait.push_back(quantam);
            Mark[pa.first] = Wait[step];
            pa.second -= quantam;
            qu.push(pa);
        }
        else{
            Wait.push_back(pa.second);
            Mark[pa.first] = Wait[step];
        }
        //cout<<Wait[step]<<" ";
       cout<<"0 "<<pa.first<<" "<<Wait[step];
    }
    else{
        if(pa.second>quantam){
            Wait.push_back( Wait[step-1]+quantam );
            Mark[pa.first] = Wait[step];
            //cout<<Wait[step]<<endl;
            pa.second -= quantam;
            qu.push(pa);
        }
        else{
            Wait.push_back(Wait[step-1]+pa.second);
            Mark[pa.first] = Wait[step];
            //cout<<Wait[step]<<endl;
        }
        //cout<<Wait[step]<<" ";
       cout<<" "<<pa.first<<" "<<Wait[step];
    }
    step++;
}
cout<<endl;
for(i=0; i < key.size(); i++){
    Mark[ key[i] ] = Mark[ key[i] ] - Btime[i];
    add += Mark[ key[i] ];
    //cout<<Mark[ key[i] ]<<" ";
}
waitingTime = add/(float)Pnumber;
printf("Average waiting time will be, %0.1fms. ",waitingTime);
return 0;
}
