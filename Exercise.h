//Desc: This file contains the header details for an exercise
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Exercise{
public:
    // Name: Exercise (default constructor)
    // Desc: Default constructor for Exercise
    // Preconditions: None
    // Postconditions: Creates a new Exercise
    Exercise();
    // Name: Exercise (overloaded constructor)
    // Desc: Sets values of a new Exercise (an exercise is a node in a linked list)
    //       Category, name, reps, and weight.
    // Preconditions: None
    // Postconditions: Creates a new node using the category, name, reps, and weight
    Exercise(string, string, int, int);
    // Name: GetCategory
    // Desc: Returns the category of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Returns the category of the exercise
    string GetCategory();
    // Name: GetName
    // Desc: Returns the name of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Returns the name of the exercise
    string GetName();
    // Name: GetReps
    // Desc: Returns the number of reps of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Returns the number of reps of the exercise
    int GetReps();
    // Name: GetWeight
    // Desc: Returns the weight of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Returns the weight of the exercise
    int GetWeight();
    // Name: GetNext
    // Desc: Returns the pointer to the next exercise
    // Preconditions: Exercise must exist
    // Postconditions: Returns the pointer to the next exercise
    Exercise* GetNext();
    // Name: SetCategory
    // Desc: Sets the category of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Sets the category of the exercise
    void SetCategory(string);
    // Name: SetName
    // Desc: Sets the name of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Sets the name of the exercise
    void SetName(string);
    // Name: SetReps
    // Desc: Sets the number of reps of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Sets the reps of the exercise
    void SetReps(int);
    // Name: SetWeight
    // Desc: Sets the weight (in lbs) of the exercise
    // Preconditions: Exercise must exist
    // Postconditions: Sets the weight of the exercise
    void SetWeight(int);
    // Name: SetNext
    // Desc: Sets the next exercise
    // Preconditions: Exercise must exist
    // Postconditions: Sets the next exercise
    void SetNext(Exercise*);
    // Name: operator<<
    // Desc: Overloaded << operator to return ostream from an Exercise
    // Preconditions: Requires an Exercise
    // Postconditions: Returns ostream with name, reps, and weight
    friend ostream &operator<< (ostream &output, Exercise &myExercise){
        output << myExercise.m_category << ":" << myExercise.m_name
               << "(" << myExercise.m_reps << "@"
               << myExercise.m_weight << "lbs)";
        return output;
    }
private:
    string m_category; //Category of exercise (chest, bicep, legs etc)
    string m_name; //Name of the exercise (Bench press)
    int m_reps; //Number of repetitions (3)
    int m_weight; //Weight of exercise (205lbs)
    Exercise* m_next; //Pointer to next node in linked list
};


#endif
