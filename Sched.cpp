#include "Schedule.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


// Name: Schedule() - Default Constructor
// Desc: Used to build a new Schedule
// Preconditions: None
// Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr and size = 0
Schedule::Schedule(){
    m_name = "";
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
// Name: Schedule(string) - Overloaded Constructor
// Desc: Used to build a new Schedule with the schedule name passed
// Preconditions: None
// Postconditions: Creates a new Schedule where m_head and m_tail point to nullptr and schedule name is passed
Schedule::Schedule(string name){
    m_name = name;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}
// Name: ~Schedule() - Destructor
// Desc: Used to destruct a strand of Schedule
// Preconditions: There is an existing Schedule strand with at least one node
// Postconditions: Schedule is deallocated (including all dynamically allocated nodes)
//                 to have no memory leaks!
Schedule::~Schedule(){
    Item *next = m_head->GetNext();
    while(next != nullptr){ // iterates through the list until the end is found
        delete m_head; // delete the head
        m_head = next; // iterate m_head
        m_size--;
        next = next->GetNext(); // iterate the next ptr
    }
    delete m_head; // clean up the last node
    m_head = nullptr; // always set hanging pointers to nullptr
    
    
}
// Name: InsertSorted
// Desc: Inserts a new item into the schedule. Inserts it from earliest time (0) to highest time (2359) ascending
//       Does NOT insert at correct location when reversed
// Preconditions: Takes in an Item pointer. Inserts the node based on time.
//                Requires a Schedule
// Postconditions: Adds the new item into the Schedule.
void Schedule::InsertSorted(Item* new_item){
    
//    int i =0;
    
    if (m_head == nullptr){
        m_head = new_item;
        m_tail = m_head;
        m_size++;
    }
    
    else if (m_head != nullptr){
        Item *next = m_head;
        m_tail = new_item;
        while (next->GetNext() != nullptr){
            next = next->GetNext();
        }
        next->SetNext(m_tail);
        m_size++;
    }
    
//    Item *item = m_head;
//
//    while (i < m_size){
//
//        item = item->GetNext();
//
//        while (i < m_size){
//
//          if (item->GetTime() < item->GetNext()->GetTime()){
//
//            Item *temp = item;
//
//            item = item->GetNext();
//
//          }
//        }
//      }

    
}
// Name: GetName()
// Preconditions: Requires a Schedule
// Postconditions: Returns m_name;
string Schedule::GetName(){
    return m_name;
}
// Name: GetSize()
// Preconditions: Requires a Schedule
// Postconditions: Returns m_size;
int Schedule::GetSize(){
    return m_size;
}
// Name: ReverseSchedule
// Preconditions: Reverses the Schedule
// Postconditions: Schedule is reversed in place; nothing returned
void Schedule::ReverseSchedule(){
    

}
// Name: GetData
// Desc: Returns the time at a specific location in the Schedule
//       Pass
// Preconditions: Requires a Schedule
// Postconditions: Returns data from specific item
// Note: May not be used in project but still required
Item* Schedule::GetData(int nodeNum){
    
    if (m_name == ""){
        cout << "No schedules imported" << endl;
    }
    
    else{
        Item* required_node = m_head;
        
        for (int i = 0; i < nodeNum; i++){
            required_node = required_node->GetNext();
        }
        
        return required_node;
    
    }
    
    return nullptr;
    
}
// Name: operator<<
// Desc: Allows you to cout a Schedule object
//       Overloaded << operator to return ostream from Schedule
//       Should not have any cout statements!
// Preconditions: Requires a Schedule sequence
// Postconditions: Returns ostream populated for each Item in Schedule
ostream &operator<< (ostream &output, Schedule &mySchedule){
    
    output << "Schedule for " << mySchedule.m_name << endl;
    
    output << mySchedule.m_size << " activities scheduled" << endl;
    
    Item *item = mySchedule.m_head;
    
    while (item != nullptr){
        cout << *item << endl;
        item = item->GetNext();
    }
    
    return output;
}
