#include <bits/stdc++.h>
using namespace std;

vector<string> process;
vector<int> Btime;

int main(){

char ara[2];
int i,add=0,value,Pnumber,j;
freopen("shortest_first.txt","r",stdin);

//cout<<"Enter total process number:";
cin>>Pnumber;
//cout<<"Enter process and burst time"<<endl;

for(i=0; i<Pnumber; i++){
    scanf("%s %d",ara,&value);

    process.push_back(ara);
    Btime.push_back(value);
}

for(i=0; i<Pnumber-1; i++){ // sorting
    for(j=0; j<(Pnumber-1)-i; j++ ){
        if(Btime[j+1]<Btime[j]){
            swap(Btime[j],Btime[j+1]);
            swap(process[j],process[j+1]);
        }
    }
}

for(i=0; i<Pnumber; i++){
    if(i==0) {
        cout<<"0 "<<process[i]<<" "<<Btime[i];
        add += Btime[i];
    }
    else{
        Btime[i] = Btime[i-1]+Btime[i];
        if( i!=(Pnumber-1) ) add += Btime[i];
        cout<<" "<<process[i]<<" "<<Btime[i];
    }
}
cout<<endl<<endl;
float Wtime = add/(float)Pnumber;
printf("Average waiting time: %0.1fms.",Wtime);
return 0;

return 0;
}
