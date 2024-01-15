#include "Exercise.h"

// Name: Exercise (default constructor)
// Desc: Default constructor for Exercise
// Preconditions: None
// Postconditions: Creates a new Exercise
Exercise::Exercise() {
    m_category = "New Exercise"; // Initialize m_category with a default value
    m_name = "";                // Initialize m_name with an empty string
    m_reps = 0;                 // Initialize m_reps with 0
    m_weight = 0;               // Initialize m_weight with 0
    m_next = nullptr;           // Initialize m_next with a nullptr
}

// Name: Exercise (overloaded constructor)
// Desc: Sets values of a new Exercise (an exercise is a node in a linked list)
//       Category, name, reps, and weight.
// Preconditions: None
// Postconditions: Creates a new node using the category, name, reps, and weight
Exercise::Exercise(string category, string name, int reps, int weight) {
    m_category = category;  // Set the m_category to the provided category
    m_name = name;          // Set the m_name to the provided name
    m_reps = reps;          // Set the m_reps to the provided reps
    m_weight = weight;      // Set the m_weight to the provided weight
    m_next = nullptr;       // Initialize m_next with a nullptr
}

// Name: GetCategory
// Desc: Returns the category of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the category of the exercise
string Exercise::GetCategory() {
    return m_category;
}

// Name: GetName
// Desc: Returns the name of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the name of the exercise
string Exercise::GetName() {
    return m_name;
}

// Name: GetReps
// Desc: Returns the number of reps of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the number of reps of the exercise
int Exercise::GetReps() {
    return m_reps;
}

// Name: GetWeight
// Desc: Returns the weight of the exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the weight of the exercise
int Exercise::GetWeight() {
    return m_weight;
}

// Name: GetNext
// Desc: Returns the pointer to the next exercise
// Preconditions: Exercise must exist
// Postconditions: Returns the pointer to the next exercise
Exercise* Exercise::GetNext() {
    return m_next;
}

// Name: SetCategory
// Desc: Sets the category of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the category of the exercise
void Exercise::SetCategory(string category) {
    m_category = category;
}

// Name: SetName
// Desc: Sets the name of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the name of the exercise
void Exercise::SetName(string name) {
    m_name = name;
}

// Name: SetReps
// Desc: Sets the number of reps of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the reps of the exercise
void Exercise::SetReps(int reps) {
    m_reps = reps;
}

// Name: SetWeight
// Desc: Sets the weight (in lbs) of the exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the weight of the exercise
void Exercise::SetWeight(int weight) {
    m_weight = weight;
}

// Name: SetNext
// Desc: Sets the next exercise
// Preconditions: Exercise must exist
// Postconditions: Sets the next exercise
void Exercise::SetNext(Exercise* next) {
    m_next = next;
}

