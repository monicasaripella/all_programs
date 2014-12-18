#ifndef NETWORK_H
#define NETWORK_H
#include "user.h"
#include <queue>

class Network {
public:
    Network();
    ~Network();
    int read_friends(char* filename);
    int write_friends(char* filename);
    void get_friends(string username);
    void list_users();
    void add_user(User* user1);
    int add_connection(int user1id, int user2id);
    int remove_connection(int user1id,int user2id);
    int get_id(string username);
    string get_username(int id);
    vector<int> shortest_path(int user1id, int user2id);
    vector<vector<int> > groups();
    vector<int> suggest_friends(int user1id,int&maxscore);
    int common_friends(vector<int>array1, vector<int>array2);
private:
    vector<User*>all_users;

};


#endif