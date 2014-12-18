#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

int main () {
    int n;
    double fairness;
    double average;
    int n_simulations=0;
    int coins[3];
    int toss1=0, toss2=0,toss3=0, turn_counter=0;
    cout << "Enter the number of coins each player will start with." << endl;
    cin >> n;
   
    cout << "Enter the fairness of the coins as a decimal between 0 and 1" << endl;
    cin >> fairness;
    if (fairness <0 || fairness >1)
    {  cout << "Please enter a valid number"<< endl;
        cin >> fairness;
    }
    cout << "Enter the number of simulations" << endl;
    cin >> n_simulations;
    fairness*=10;
    fairness+=1;
         srand(time(0));
   

    for (int i=0; i<n_simulations; i++) {
        coins[0]=n;
        coins[1]=n;
        coins[2]=n;
    while (coins[0]>0 && coins[1]>0 && coins[2]>0){
        
        toss1=rand()%11+1;
        toss2=rand()%11+1;
        toss3=rand()%11+1;
        if ( (toss1<=fairness && toss2<=fairness && toss3<=fairness) ||(toss1>=fairness && toss2>=fairness && toss3>=fairness)){
            continue;

        }
        else if (toss1<=fairness && toss2<=fairness && toss3>fairness){
            coins[2]+=2;

        coins[1]--;
            coins[0]--;}
        else if (toss1<=fairness && toss2>fairness && toss3>fairness){
            coins[0]+=2;
            coins[2]--;
            coins[1]--;}
        else if (toss1>=fairness && toss2<=fairness && toss3>=fairness){
            coins[1]+=2;
        coins[2]--;
            coins[0]--;}
        else if (toss1>fairness && toss2<=fairness && toss3<=fairness){
            coins[0]+=2;
        coins[1]--;
            coins[2]--;}
        else if (toss1>fairness && toss2>fairness && toss3<=fairness){
            coins[2]+=2;
        coins[1]--;
            coins[0]--;}
        else if (toss1<=fairness && toss2>fairness && toss3<=fairness){
            coins[1]+=2;
            coins[2]--;
            coins[0]--;
        }
        
        turn_counter++;
        
    }
       
        

    }

    average=double(turn_counter)/double(n_simulations);
    

    
    
    cout << "Total number of turns: " << turn_counter <<endl;
    cout << "Average number of turns per simulation:" << average<<endl;

    
    return 0;
}