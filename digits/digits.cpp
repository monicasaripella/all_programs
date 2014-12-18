#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
int enter_int=0;
int digit1=0, digit10=0, digit100=0;

cout << "Enter an integer between 0 and 999" << endl;
cin >> enter_int;
digit1=enter_int%10;
enter_int=enter_int-digit1;
digit10=(enter_int%100)/10;
enter_int=enter_int-digit10;
digit100=enter_int/100;




cout << "1's digit is " << digit1 << endl;
cout << "10's digit is " << digit10 << endl;
cout << "100's digit is " << digit100 << endl;

return 0;
}