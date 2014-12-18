#include "delist.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstddef>
#include <iomanip>
using namespace std;


DEList::DEList(){
head=NULL;
	tail=NULL;
}

DEList::~DEList(){
struct DEItem* current=head;
	struct DEItem* next;
	while (current!=tail)
{next=current->next;
//delete current;
current=next;
}
delete head;
  delete tail;
}
 /// returns a Boolean 'true' if the list is empty
  bool DEList::empty(){

return (head!=NULL && tail!=NULL);
}
  /// returns number of items in the list
  int DEList::size(){
int size_list=0;
struct DEItem* current=head;

while (current!=NULL)
{
size_list++;
current=current->next;

}
return size_list;
}
  /// returns front item or -1 if empty list
  int DEList::front(){
if (size()!=0){
return head->val;}
else {return -1;}

}
  /// returns back item or -1 if empty list
  int DEList::back(){
if (size()!=0){
return tail->val;}
else {return -1;}

}
  /// Adds a new integer to the front of the list
  void DEList::push_front(int new_val){
DEItem *myptr=new struct DEItem();

if (head==NULL){
myptr->val=new_val;
myptr->prev=NULL;
myptr->next=NULL;
head=myptr;
tail=myptr;


}//if

else{
myptr->val=new_val;
myptr->next=head;
head->prev=myptr;
head=myptr;
myptr->prev=NULL;

}

}

  /// Adds a new integer to the back of the list
  void DEList::push_back(int new_val){
DEItem *myptr=new struct DEItem();
if (tail==NULL){
myptr->val=new_val;
myptr->prev=NULL;
myptr->next=NULL;
head=myptr;
tail=myptr;

}//if

else{
myptr->val=new_val;
myptr->prev=tail;
tail->next=myptr;
tail=myptr;
myptr->next=NULL;

}
}

  /// Removes the front item of the list (if it exists)
  void DEList::pop_front()
{
struct DEItem* current;
if (head!=NULL){
current=head;
head=head->next;}
else {cout << " hello" <<endl; }

delete current;
}
  /// Removes the back item of the list (if it exists)
  void DEList::pop_back(){
struct DEItem* current;
if (tail!=NULL){
current=tail;
tail=tail->prev;}
delete current;
}
