//Desc: This file contains the header details for the Workout class

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Exercise.h"
using namespace std;

class Workout {
public:
    // Name: Workout() - Default Constructor
    // Desc: Used to build a new Workout
    // Preconditions: None
    // Postconditions: Creates a new Workout where m_head and
    //                 m_tail point to nullptr and size = 0
    Workout();
    // Name: Workout(string) - Overloaded Constructor
    // Desc: Used to build a new Workout with the workout name passed
    // Preconditions: None
    // Postconditions: Creates a new Workout where m_head and m_tail point
    //                 to nullptr and workout name is passed
    Workout(string);
    // Name: ~Workout() - Destructor
    // Desc: Used to destruct a strand of Workout
    // Preconditions: There is an existing Workout strand with at least one node
    // Postconditions: Workout is deallocated to have no memory leaks
    //                 (including all dynamically allocated nodes)
    ~Workout();
    // Name: InsertEnd
    // Desc: Inserts a new item to the end of the workout using m_tail.
    // Preconditions: Takes in an Exercise pointer. Inserts the new node to the tail.
    //                Requires a Workout
    // Postconditions: Adds the new item into the Workout.
    void InsertEnd(Exercise*);
    // Name: GetName()
    // Preconditions: Requires a Workout
    // Postconditions: Returns m_name;
    string GetName();
    // Name: GetSize()
    // Preconditions: Requires a Workout
    // Postconditions: Returns m_size;
    int GetSize();
    // Name: ReverseWorkout
    // Preconditions: Reverses the Workout (updates m_head and m_tail)
    //                Updates the pointers only - does not create a new list
    // Postconditions: Workout is reversed in place; nothing returned
    void ReverseWorkout();
    // Name: GetData
    // Desc: Returns the time at a specific location in the Workout
    //       Pass
    // Preconditions: Requires a Workout
    // Postconditions: Returns data from specific item
    // Note: May not be used in project but still required
    Exercise* GetData(int nodeNum);
    // Name: InsertSorted
    // Desc: Inserts a new exercise into the workout in alphabetical order by category.
    // Preconditions: Takes in an Exercise pointer. Inserts the new exercise while maintaining alphabetical order.
    //                Requires a Workout.
    // Postconditions: Adds the new exercise into the Workout in alphabetical order by category.
    void InsertSorted(Exercise* exercise);

    // Name: operator<<
    // Desc: Allows you to cout a Workout object
    //       Overloaded << operator to return ostream from Workout
    //       Should not have any cout statements!
    // Preconditions: Requires a Workout sequence
    // Postconditions: Returns ostream populated for each Exercise in Workout
    Exercise* GetHead() {
        return m_head;
    }

    friend ostream &operator<< (ostream &output, Workout &myWorkout);
private:
    string m_name; //Name of the Workout
    Exercise *m_head; //Front of the Workout
    Exercise *m_tail; //End of the Workout
    int m_size; //Total size of the Workout
};


#endif
