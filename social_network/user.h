#ifndef USER_H
#define USER_H
#include<iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    User(string name, int userbirthyear, int userzipcode);
    User(int userid, string name, int userbirthyear, int userzipcode);
    User ();
    ~User();

    void add_friend(int friendID);
    void delete_friend(int remove_friend);
    vector<int> get_friends();

    int getid() {
        return id;
    }
    void putid(int user_id) {
        id=user_id;
    }
    string getusername() {
        return username;
    }

    int getzipcode() {
        return zipcode;
    }
    void putzipcode(int zip) {
        zipcode=zip;
    }
    int getbirthyear() {
        return birthyear;
    }

    int getnum_friends() {
        return  num_friends;
    }
    int get_id(string username);
    void putcurrfriendIDs(int friendID) {
        currfriendIDs.push_back(friendID);
    }
    int getcurrfriendIDsize() {
        return currfriendIDs.size();
    }
    int getcurrfriendIDs(int j) {
        return currfriendIDs[j];
    }
    string get_username(int inid);

private:


    int id;
    string username;
    int birthyear;
    int zipcode;
    int num_friends;
    vector<int>currfriendIDs;

};


#endif