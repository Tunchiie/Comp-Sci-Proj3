#include "Item.h"
#include <iostream>
#include <string>
using namespace std;

// Name: Item (default constructor)
// Desc: Sets default values of a new Item (an item is a node in a linked list)
// Preconditions: None
// Postconditions: Creates a new node with a generic time and name with a pointer to nullptr
// Note: May not be used in project 3 but still implement
Item::Item(){
    SetTime(0);
    SetName("");
    SetNext(nullptr);
}
// Name: Item (overloaded constructor)
// Desc: Sets values of a new Item (an item is a node in a linked list)
// Preconditions: None
// Postconditions: Creates a new node using the passed name and time with a pointer to nullptr
Item::Item(string name, int time){
    SetTime(time);
    SetName(name);
    SetNext(nullptr);
}
// Name: GetName
// Desc: Returns the name of the item
// Preconditions: Item must exist
// Postconditions: Returns the name of the item
// Note: May not be used in project 3 but still implement
string Item::GetName(){
    return m_name;
}
// Name: GetTime
// Desc: Returns the time of the item
// Preconditions: Item must exist
// Postconditions: Returns the time of the item
// Note: May not be used in project 3 but still implement
int Item::GetTime(){
    return m_time;
}
// Name: GetNext
// Desc: Returns the pointer to the next item
// Preconditions: Item must exist
// Postconditions: Returns the pointer to the next item
// Note: May not be used in project 3 but still implement
Item* Item::GetNext(){
    return m_next;
}
// Name: SetName
// Desc: Sets the name of the item
// Preconditions: Item must exist
// Postconditions: Sets the name of the item
// Note: May not be used in project 3 but still implement
void Item::SetName(string name){
    m_name = name;
}
// Name: SetTime
// Desc: Sets the time of the item
// Preconditions: Item must exist
// Postconditions: Sets the time of the item
// Note: May not be used in project 3 but still implement
void Item::SetTime(int time){
    m_time = time;
}
// Name: SetNext
// Desc: Sets the next item
// Preconditions: Item must exist
// Postconditions: Sets the next item
// Note: May not be used in project 3 but still implement
void Item::SetNext(Item* next){
    m_next = next;
}
