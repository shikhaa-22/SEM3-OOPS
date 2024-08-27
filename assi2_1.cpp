#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
 int main(){
    int count[6]={0,0,0,0,0,0},n,vote;
    cout<<"Enter number of voters\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nEnter the candidate you would like to vote for\n";
        cout<<"1.PARTY 1\n2.PARTY 2\n3.PARTY 3\n4.PARTY 4\n5.PARTY 5\n";
        cin>>vote;
        if(vote<1||vote>5){
            cout<<"Spoilt Ballot!\n";
        }
        if(vote>5||vote<1)
        vote=6;
        count[vote-1]++;
    }
    for(int j=0;j<5;j++){
        cout<<"\nCandidate "<<j+1<<" has gotten "<<count[j]<<" votes";
    }
    if(count[5]>0)
    cout<<"\nThere were "<<count[5]<<" spoilt ballots\n";
    else
    cout<<"\nThere were no spoilt ballots\n";
    return 0;
 }