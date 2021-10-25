#include "Manager.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int QUIT = 4;

// Name: Manager (constructor)
// Desc: Creates a Manager to manage schedules
// Preconditions:  None
// Postconditions: A manager is created to populate m_schedules
Manager::Manager(string fileName){
    m_fileName = fileName;
}
// Name:  Manager (destructor)
// Desc: Deallocates all dynamic aspects of a Manager
// Preconditions: There is an existing Schedule
// Postconditions: All schedules are cleared
Manager::~Manager(){
    int size = static_cast<int>(m_schedules.size());
    
    for(int i = 0; i < size; i++){// delete all class pointers stored
        
        delete m_schedules.at(i);
        
        m_schedules.at(i) = nullptr; // set them to null
        
    }
    m_schedules.clear();
    
}

// Name:  DisplaySchedules
// Desc: Displays each schedule in m_schedules
// Preconditions: At least one schedule is in m_schedules
// Postconditions: Displays all items in a schedule for all schedules in m_schedules
void Manager::DisplaySchedules(){
    // display courses gotten from file
    
    int size = static_cast<int>(m_schedules.size());
    
    for (int i = 0; i < size; i++){
        
        cout << i + 1 << *m_schedules.at(i) << endl;
        
        
    }
    
    
    
}

// Name:  ReadFile
// Desc: Reads in a file that has the schedule name then semicolon the starting time then a semicolon
//       then the name of the activity.
//       Input files are an indeterminate length. There are an indeterminate number of schedules in
//       an input file. There are an indeterminate number of items in each file.
//       The vector can hold many schedules.
// Preconditions: Valid file name of schedules
// Postconditions: Populates each schedule and puts in m_schedules
void Manager::ReadFile(){
    
    string sched_name, time, activity_name;
    
    ifstream inputStream;
    
    inputStream.open(m_fileName);
    
    if (!inputStream.is_open())
        
        cout << m_fileName << "Not open" << endl;
    
    else{
        // store info of each student
        while (getline(inputStream, sched_name, ';')){
            
            getline(inputStream, time, ';');
            
            getline(inputStream, activity_name, '\n');
            
            int num = FindSchedule(sched_name);
            
            int in_It = -1;
            
            // if the class does not exist
            if (num == in_It){
                
                m_schedules.push_back(new Schedule(sched_name));
                
                m_schedules.at(m_schedules.size() - 1)->InsertSorted(new Item(activity_name, stoi(time)));
                
            }
            
            // if the class exists
            else{
                
                m_schedules.at(num)->InsertSorted(new Item(activity_name, stoi(time)));
            }
            
            
        }
    }
    
    // close file
    inputStream.close();
    
    
}
// Name: InsertNewItem
// Desc: Asks the user which schedule they would like to insert into (uses FindSchedule)
//       If new schedule, inserts a new schedule and indicates a new schedule was created
//       Prompts user for time and name of item then inserts item into schedule
// Preconditions: Populated m_schedules
// Postconditions: Either inserts into existing schedule or inserts into a new schedule
void Manager::InsertNewItem(){
    string sched_name, activity_name;
    int time;
    
    cout << "What is the name of the schedule you would like to insert into? ";
    cin >> sched_name;
    cout << endl;
    cout << "What is the start time of the activity? ";
    cin >> time;
    cout << endl;
    cout << "What is the name of the activity? ";
    cin >> activity_name;
    cout << endl;
    
    int num = FindSchedule(sched_name);
    
    int in_It = -1;
    
    // if the class does not exist
    if (num == in_It){
        
        m_schedules.push_back(new Schedule(sched_name));
        
        m_schedules.at(m_schedules.size() - 1)->InsertSorted(new Item(activity_name, time));
        
    }
    
    // if the class exists
    else{
        
        m_schedules.at(num)->InsertSorted(new Item(activity_name, time));
    }
    
}

// Name: FindSchedule
// Desc: Returns the index of the schedule from m_schedules else -1
// Preconditions: Populated m_schedules
// Postconditions: Returns the index of schedule with the matching name or it returns -1
int Manager::FindSchedule(string schedName){
    int size  = static_cast<int>(m_schedules.size());
    
    int in_It = -1;
    
    // checks if a class exists
    for (int i = size - 1; i >= 0; i--){
        
        if (m_schedules.at(i)->GetName() == schedName)
            
            return i; // index of class
        
    }
    
    return in_It;
    
}

// Name:  MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_schedules
// Postconditions: None
void Manager::MainMenu(){
    
    int response = 0;
    
    
    // display while user doesn`t quit
    do{
        cout << "1. Display Schedules" << endl;
        cout << "2. Reverse Schedules" << endl;
        cout << "3. Insert New Item" << endl;
        cout << "4. Exit" << endl;
        cin >> response;
        cout << endl;
        
        // display according to the users wishes
        switch (response){
                
            case 1:
                
                DisplaySchedules();
                
                break;
                
            case 2:
                
                ReverseSchedule();
                
                break;
                
            case 3:
                
                InsertNewItem();
                
                break;
                
            case 4:
                
                break;
        }
        
    }while (response != QUIT);
}

// Name: ReverseSchedule
// Desc: User chooses a schedule and the schedule is reversed
//       If only one schedule in m_schedules, automatically reverses it without prompting the user
// Preconditions: Populated m_schedules
// Postconditions: Reverses a specific schedule replacing in place
void Manager::ReverseSchedule(){
    
    int size  = static_cast<int>(m_schedules.size());
    
    
    if (size < 2){
        m_schedules.at(m_schedules.size() - 1)->ReverseSchedule();
    }
    
    else{
        
        for (int i = 0; i < size; i++){
            
            cout << i + 1 << m_schedules.at(i)->GetName() << endl;
            
        }
        
        string sched_name;
        
        cout << "What is the name of the schedule you would like to reverse? ";
        
        cin >> sched_name;
        
        cout << endl;
        
        int num = FindSchedule(sched_name);
        
        m_schedules.at(num)->ReverseSchedule();
        
    }
    
}
