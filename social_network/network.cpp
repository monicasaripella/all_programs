#include "network.h"
#include "user.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

Network::Network() {
}
int Network::read_friends(char* filename)
{

    int num_users;
    int id, birthdate, zipcode;
    string first_name, last_name, name;
    string myline;
    ifstream ifile(filename);
    if(!ifile) {
        return -1;
    }
    getline(ifile,myline);
    stringstream stream_numusers(myline);
    stream_numusers>>num_users;
    cout << num_users << endl;


    for(int i=0; i<num_users; i++) {
        getline(ifile, myline);
        stringstream streamid(myline);
        streamid >> id;
        cout << endl << id << endl;
        getline(ifile, myline);
        stringstream streamname(myline);
        streamname >> first_name >> last_name;
        name=first_name+" " + last_name;
        cout << first_name << " " << last_name << endl;

        getline(ifile, myline);
        stringstream streambirthdate(myline);
        streambirthdate >> birthdate;
        cout << birthdate << endl;
        getline(ifile, myline);
        stringstream streamzipcode(myline);
        streamzipcode >> zipcode;
        cout << zipcode << endl;
        User* user1ptr= new User(id, name, birthdate, zipcode);

        getline(ifile, myline);
        istringstream iss(myline);

        do
        {
            int friendID;

            iss >> friendID;
            if (iss) {
                user1ptr->putcurrfriendIDs(friendID);
                cout  << friendID << " " ;
            }//if
        } while (iss);
        all_users.push_back(user1ptr);
    }//for

    return 0;

}//fct

int Network::write_friends(char* filename)

{   ofstream ofile(filename);

    if (!ofile) {
        return -1;
    }
    ofile << (int)all_users.size() << endl;
    for (int i=0; i<(int)all_users.size(); i++) {
        ofile <<  i << endl;
        ofile << "\t"<< all_users[i]->getusername() << endl;
        ofile << "\t"<<  all_users[i]->getbirthyear() << endl;
        ofile << "\t"<<  all_users[i]->getzipcode() << endl;
        ofile << "\t";
        for (int j=0; j<(int)all_users[i]->getcurrfriendIDsize(); j++) {


            ofile << (int)all_users[i]->getcurrfriendIDs(j) << " ";

        }

        ofile << endl;

    }//for
    return 0;
}//writefriends



void Network::list_users() {
    cout  << "ID" << setw(10);
    cout <<"Username" << setw(10) << "Birthyear" << setw(10)<< "Zip Code" << endl;
    cout <<"=====================================";
    cout << "==========================================="<<endl;
    for (int i=0; i<(int)all_users.size(); i++) {
        int myid=all_users[i]->getid();
        cout  << myid << setw(15);
        cout << all_users[i]->getusername() << setw(5);
        cout << all_users[i]->getbirthyear() << setw(10);
        cout << all_users[i]->getzipcode() << endl;
//return
    }//for
}//list users


void Network::add_user(User* user1)
{
    cout << all_users.size();
    user1->putid(all_users.size());
    all_users.push_back(user1);

}
int Network::add_connection(int user1id, int user2id)
{   //addconnection

    bool founduser1=false, founduser2=false;

    int user1index, user2index;
    for (int i=0; i<(int)all_users.size(); i++) {
        if (all_users[i]->getid()==user1id) {
            founduser1=true;
            user1index=i;
        }
        if (all_users[i]->getid()==user2id) {
            founduser2=true;
            user2index=i;
        }
    }//for
    if (founduser1==true && founduser2==true) {
        all_users[user1index]->add_friend(user2id);
        all_users[user2index]->add_friend(user1id);
        return 0;
    }
    else {
        return -1;
    }

}//addconnection

int Network::remove_connection(int user1id, int user2id)
{   bool founduser1=false, founduser2=false;
    int user1index, user2index;
    for (int i=0; i<(int)all_users.size(); i++) {
        if (all_users[i]->getid()==user1id) {
            founduser1=true;
            user1index=i;
        }
        if (all_users[i]->getid()==user2id) {
            founduser2=true;
            user2index=i;
        }//if
    }//for
    if (founduser1 && founduser2) {
        all_users[user1index]->delete_friend(user2id);
        all_users[user2index]->delete_friend(user1id);
        return 0;
    }//if
    else {
        return -1;
    }
}//remove




int Network::get_id(string username)
{   int myid;

    for (int i=0; i<(int)all_users.size(); i++) {
        myid= all_users[i]->get_id(username);
        if (myid!=-1)
        {
            return myid;
        }
    }//for
    return -1;

}//fct

string Network::get_username(int id)
{   string name;
    name=all_users[id]->getusername();
    return name;


    /*
        for (int i=0; i<(int)all_users.size(); i++) {
            name= all_users[i]->get_username(id);
            if (name.compare("Not a valid User")!=0)
            {
                return name;
            }

        }//for
       // return "invalid";
    */
}//fct

void Network::get_friends(string name) {
    int ID=get_id(name);
    if (ID == -1) return;
    User* user_friend;
    cout  << "ID" << setw(10);
    cout <<"Username" << setw(10) << "Birthyear" << setw(10)<< "Zip Code" << endl;
    cout <<"=====================================";
    cout << "================================="<<endl;
    vector<int>temp=all_users[ID]->get_friends();
    for(int i=0; i<(int)temp.size(); i++) {
        user_friend=all_users[temp[i]];
//all_users[ID]->getfriends();

        cout  << temp[i] << setw(15);
        cout << user_friend->getusername() ;
        cout << setw(5) << user_friend->getbirthyear();
        cout << setw(10)<< user_friend ->getzipcode() << endl;


    }//for
}//fct
//////////////////////////////////////////////////////////////
int Network::common_friends(vector<int>array1, vector<int>array2) {
    int commonfriends=0;
    for (int i=0; i<(int)array1.size(); i++) {
        for (int j=0; j<(int)array2.size(); j++) {
            if (array1[i]==array2[j]) {
                commonfriends++;
            }

        }//for
    }//for

    return commonfriends;
}//fct


////////////////////////////////////////////////////////////

vector<int> Network::shortest_path(int user1id, int user2id) {
    queue<int> user_friends;
    vector<int>return_social;
    bool no_path=true;
//bool dealt_already=true;
    int num_users=all_users.size();
    int complete_list[num_users];
    for (int i=0; i<num_users; i++) {
        complete_list[i]=-1;
    }

    if (user1id==-1 || user2id==-1) {
        cout << "user doesn't exist" << endl;
        return_social.push_back(-1);
        return return_social;
    }//if

    user_friends.push(user1id);
//   complete_list[user1id]=-1;

    while (!user_friends.empty()) {
//find friends& add to end of queue
        int front=user_friends.front();
        vector<int>temp1=all_users[front]->get_friends();

        for (int i=0; i<(int)temp1.size(); i++) {
            if (complete_list[temp1[i]]<0) {
                user_friends.push(temp1[i]);
                complete_list[temp1[i]]=front;

            }//if
        }//for
//remove from front
        user_friends.pop();
        if (front==user2id) {
            no_path=false;

            break;
        }//if
    }//while

    if (no_path) {
        cout << "None" << endl;
//return_social.push_back(-1);
        return return_social;
    }//if
    int currentid=user2id;



    int distance=0;
    vector<int>printvec;
    while (user1id!=currentid) {


        currentid=complete_list[currentid];
        printvec.push_back(currentid);
        distance++;
    }//while


//return_social.push_back(distance);


    for (int i=(int)printvec.size()-1; i>=0; i--) {

        return_social.push_back(printvec[i]);
    }

    return_social.push_back(user2id);
    return return_social;


}//shortestpath


////////////////////////////////////////////////////////////

vector<vector<int> > Network::groups() {
    vector<vector<int> >return_social;
    queue<int> user_friends;
//bool dealt_already=true;
    int num_users=all_users.size();
    int complete_list[num_users];
    for (int i=0; i<num_users; i++) {
        complete_list[i]=-1;
    }
    int user1id=0;
    int setnum=0;
    complete_list[0]=0;
    vector<int>individual_set;
    while (user1id!=num_users) {
        setnum++;
        //cout << "Set " << setnum << "=> ";
        user_friends.push(user1id);
//   complete_list[user1id]=-1;

        while (!user_friends.empty()) {
//find friends& add to end of queue
            int front=user_friends.front();
            vector<int>temp1=all_users[front]->get_friends();
            for (int i=0; i<(int)temp1.size(); i++) {
                if (complete_list[temp1[i]]<0) {
                    user_friends.push(temp1[i]);
                    complete_list[temp1[i]]=front;

                }//if
            }//for
//remove from front
            string name=get_username(front);
            // cout << name ;
            individual_set.push_back(front);
            user_friends.pop();
            if (user_friends.size()!=0) {
                //  cout <<",";   //avoid last comma
            }

        }//while2
        cout << endl;
        return_social.push_back(individual_set);
        while (complete_list[user1id]!=-1&& user1id!=num_users) {
            user1id++;   //while
            individual_set.clear();
        }
        complete_list[user1id]=0;
//cout << "user1id= " << user1id << endl;
    }//while1

    return return_social;
}//groups

////////////////////////////////////////////////////////////

vector<int> Network::suggest_friends(int user1id, int& maxscore) {
    queue<int> user_friends;
    vector<int>return_social;


    int num_users=all_users.size();

    int complete_list[num_users];
    for (int i=0; i<num_users; i++) {
        complete_list[i]=-1;
    }

    user_friends.push(user1id);
    complete_list[user1id]=0;
    vector<int>level2_friends;
    vector<int>level2scores;
    while (!user_friends.empty()) {
//find friends& add to end of queue
        int front=user_friends.front();
        vector<int>friend_list=all_users[front]->get_friends();

        for (int i=0; i<(int)friend_list.size(); i++) {
            if (complete_list[friend_list[i]]<0) {
                user_friends.push(friend_list[i]);
                complete_list[friend_list[i]]=complete_list[front]+1;
                if (complete_list[friend_list[i]]==2) {
                    level2_friends.push_back(friend_list[i]);
                    level2scores.push_back(0); //to be filled in later

                }//if
            }//if
        }//for
//remove from front
        user_friends.pop();
    }//while
//Level 2 friends (candidates)
//    int maxscore=0;
    vector<int>level1_friends=all_users[user1id]->get_friends();
    for (int i=0; i<(int)level2_friends.size(); i++) {

        vector<int>other_level1friends=all_users[level2_friends[i]]->get_friends();
//common friends
        int score=common_friends(level1_friends,other_level1friends);
        level2scores[i]=score;
        if (score>maxscore) {
            maxscore=score;
        }

    }

    for (int i=0; i<(int)level2_friends.size(); i++) {

        if (level2scores[i]==maxscore) {
            string name=get_username(level2_friends[i]);
            return_social.push_back(level2_friends[i]);

            //  cout <<  name << "     Score:" << maxscore << endl;
        }
    }
//    int ID=get_id(name);
    return return_social;

}//suggest_friends




Network::~Network() {}
