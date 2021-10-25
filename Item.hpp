#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Item{
 public:
  // Name: Item (default constructor)
  // Desc: Sets default values of a new Item (an item is a node in a linked list)
  // Preconditions: None
  // Postconditions: Creates a new node with a generic time and name with a pointer to nullptr
  // Note: May not be used in project 3 but still implement
  Item();
  // Name: Item (overloaded constructor)
  // Desc: Sets values of a new Item (an item is a node in a linked list)
  // Preconditions: None
  // Postconditions: Creates a new node using the passed name and time with a pointer to nullptr
  Item(string name, int time);
  // Name: GetName
  // Desc: Returns the name of the item
  // Preconditions: Item must exist
  // Postconditions: Returns the name of the item
  // Note: May not be used in project 3 but still implement
  string GetName();
  // Name: GetTime
  // Desc: Returns the time of the item
  // Preconditions: Item must exist
  // Postconditions: Returns the time of the item
  // Note: May not be used in project 3 but still implement
  int GetTime();
  // Name: GetNext
  // Desc: Returns the pointer to the next item
  // Preconditions: Item must exist
  // Postconditions: Returns the pointer to the next item
  // Note: May not be used in project 3 but still implement
  Item* GetNext();
  // Name: SetName
  // Desc: Sets the name of the item
  // Preconditions: Item must exist
  // Postconditions: Sets the name of the item
  // Note: May not be used in project 3 but still implement
  void SetName(string name);
  // Name: SetTime
  // Desc: Sets the time of the item
  // Preconditions: Item must exist
  // Postconditions: Sets the time of the item
  // Note: May not be used in project 3 but still implement
  void SetTime(int time);
  // Name: SetNext
  // Desc: Sets the next item
  // Preconditions: Item must exist
  // Postconditions: Sets the next item
  // Note: May not be used in project 3 but still implement
  void SetNext(Item* next);
  // Name: operator<<
  // Desc: Overloaded << operator to return ostream from an Item
  // Preconditions: Requires an Item
  // Postconditions: Returns ostream populated with Item's time and Item's name
  // **PROVIDED** Do not edit
  friend ostream &operator<< (ostream &output, Item &myItem){
    output << myItem.m_time << " : " << myItem.m_name;
    return output;
  }
private:
  string m_name; //Name of the activity
  int m_time; //Time activity starts
  Item* m_next; //Pointer to next node in linked list
};

#endif /* Item_hpp */
