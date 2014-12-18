#include "bigint.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream
using namespace std;

BigInt::BigInt(){

}

BigInt::BigInt(string s){
int single_digit;
for(int i=0;i<(int)s.length();i++){
	single_digit=(int)(s[i]-'0');
	num.push_back(single_digit);

}//for 
//std::reverse(num.begin(),num.end());

}

void BigInt:: println()
{
for (int i=0;i<(int)num.size();i++){
cout << num[i];

}//for

cout << endl;
}//println



void BigInt:: add(BigInt b)
{

int total=0,quotient=0,remainder=0, diff=0;
if ((int)num.size()<(int)b.num.size()){
diff=(int)b.num.size()-(int)num.size()-1;
	for (int i=0;i<=diff;i++){
	num.insert(num.begin(),0);
	}//for
	// println();
}//if

else if ((int)num.size()>(int)b.num.size()){
diff=(int)num.size()-(int)b.num.size();
	for (int i=0;i<diff;i++){
	b.num.insert(b.num.begin(),0);
	}//for
	// println();
}//if
for (int i=(int)num.size();i>=0;i--){


	total= num[i]+b.num[i]+quotient;
	remainder=total%10;
	quotient=total/10;
	num[i]=remainder;


	
}//for
//println();
if(quotient!=0){
	num.insert(num.begin(),quotient);
}



}//add



BigInt::~BigInt(){

	//delete ;
//for 

}



