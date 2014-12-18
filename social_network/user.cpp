#include "user.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

User::User( string name, int userbirthyear, int userzipcode) {
//    id=userid;
    username=name;
    birthyear=userbirthyear;
    zipcode=userzipcode;
}
User::User(int userid, string name, int userbirthyear, int userzipcode)
{
    id=userid;
    username=name;
    birthyear=userbirthyear;
    zipcode=userzipcode;
}

User::User() {
}
void User::add_friend(int friendID)
{
    bool foundfriend=false;
    for (int i=0; i<(int)currfriendIDs.size(); i++) {
        if (currfriendIDs[i]==friendID) {
            foundfriend=true;
        }//if
    }//for
    if (foundfriend==false) {
        currfriendIDs.push_back(friendID);

    }//if

}//addfriend

//void User::add_friendID(int I
void User::delete_friend(int remove_friend)

{   for (int i=0; i<(int)currfriendIDs.size(); i++) {
        if (currfriendIDs[i]==remove_friend) {
            currfriendIDs.erase(currfriendIDs.begin()+i);
        }//if
    }//for
}//deletefriend


vector<int> User::get_friends() {

    return currfriendIDs;


}//fct


int User::get_id(string inusername)
{
    if (username.compare(inusername)==0) {
        return id;
    }//if
    else {
        return -1;
    }

}//fct





