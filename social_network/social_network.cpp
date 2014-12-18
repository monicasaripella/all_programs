#include "network.h"
#include "user.h"
#include<iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[])
{   //ifstream ifile(argv[1]);
    Network n;
    n.read_friends(argv[1]);
    char filename[100];
    // n.write_friends("hello.out");
    int choice;

    //User* user1;
    //User *user2;
    int user1id, user2id;
    while (true) {
        cout << "Enter the number for the option you wish to choose:" << endl;
        cout << "1. Add a user" << endl;
        cout << "2. Add friend connection" << endl;
        cout << "3. Remove friend connection" << endl;
        cout << "4. Print users" << endl;
        cout << "5. List friends" << endl;
        cout << "6. Write to file" << endl;
        cout << "7. Find relational distance between 2 users" << endl;
        cout << "8. Find groups sets" << endl;
        cout << "9. Find friend suggestions" << endl;
        cout << "Enter any other number to exit program" << endl;
        cin >> choice;
        string name, first_name, last_name;
        string name1, name2, first_name1, last_name1,first_name2, last_name2;
        int birthdate, zipcode;
        if (choice==1) {
            cin >> first_name >> last_name >> birthdate >> zipcode;
            name= first_name+" " + last_name;
            User* user1=new User(name,birthdate,zipcode);
//user id provided by network
            n.add_user(user1);
        }//if

        else if (choice==2) {
            cout <<"Enter 2 names" << endl;
            cin >> first_name1 >> last_name1 >> first_name2 >> last_name2;
            name1= first_name1+" " + last_name1;
            name2= first_name2+" " + last_name2;
            cout << first_name1<<last_name1<<first_name2<<last_name2;
            user1id=n.get_id(name1);
            user2id=n.get_id(name2);

            n.add_connection(user1id, user2id);
        }//if

        else if (choice==3) {
            cin >> first_name1 >> last_name1 >> first_name2 >> last_name2;
            name1= first_name1+" " + last_name1;
            name2= first_name2+" " + last_name2;
            user1id=n.get_id(name1);
            user2id=n.get_id(name2);
            n.remove_connection(user1id, user2id);
        }//if

        else if (choice==4) {
            n.list_users();

        }//if

        else if (choice==5) {
            string username;
            cin >> first_name >> last_name;
            username= first_name+" " + last_name;


            n.get_friends(username);

        }//if

        else if (choice==6) {
            cout << "enter filename" << endl;
            cin >> filename;
            n.write_friends(filename);
        }//if

        else if(choice==7) {
            cout <<"Enter 2 names" << endl;
            cin >> first_name1 >> last_name1 >> first_name2 >> last_name2;
            name1= first_name1+" " + last_name1;
            name2= first_name2+" " + last_name2;

            user1id=n.get_id(name1);
            user2id=n.get_id(name2);

            vector<int>output=n.shortest_path(user1id, user2id);
            cout << "Distance: " << (int)output.size()<<endl;
            for (int i=0; i<(int)output.size(); i++) {

                cout <<  n.get_username(output[i]);

                if (i!=(int)output.size()-1) {
                    cout << " -> " ;
                }
            }//for
            cout << endl;
        }//if


        else if(choice==8) {
            vector<vector<int> >output=n.groups();
            for(int i=0; i<(int)output.size(); i++) {
                cout << "Set " << i+1<<"=>" ;
                vector<int>newvector=output[i];

                for (int j=0; j<(int)newvector.size(); j++) {
                    cout << n.get_username(newvector[j]);
                    if (j!=((int)newvector.size()-1)) {
                        cout << "," ;
                    }

                }//for
                cout << endl;
            }//for


        }

        else if(choice==9) {
            cout <<"Enter 1 name" << endl;
            cin >> first_name1 >> last_name1 ;
            name1= first_name1+" " + last_name1;


            user1id=n.get_id(name1);
            if (user1id==-1) {
                cout << "invalid user";
                break;
            }
            int score=0;
            vector<int>output=n.suggest_friends(user1id, score);
            cout <<"The suggested friend(s) is/are:" << endl;
            for (int i=0; i<(int)output.size(); i++) {
                cout <<  n.get_username(output[i]);
                i++;
                cout << "    Score: " << score << endl;
            }


        }//if
        else {
            break;
        }
    }//while
    return 0;
}