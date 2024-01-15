#include "Workout.h"

// Name: Workout() - Default Constructor
// Desc: Used to build a new Workout
// Preconditions: None
// Postconditions: Creates a new Workout where m_head and
//                 m_tail point to nullptr and size = 0
Workout::Workout() {
    m_name = "Default";
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// Name: Workout(string) - Overloaded Constructor
// Desc: Used to build a new Workout with the workout name passed
// Preconditions: None
// Postconditions: Creates a new Workout where m_head and m_tail point
//                 to nullptr and workout name is passed
Workout::Workout(string name) {
    m_name = name;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// Name: ~Workout() - Destructor
// Desc: Used to destruct a strand of Workout
// Preconditions: There is an existing Workout strand with at least one node
// Postconditions: Workout is deallocated to have no memory leaks
//                 (including all dynamically allocated nodes)
Workout::~Workout() {
    Exercise* current = m_head;
    while (current != nullptr) {
        Exercise* next = current->GetNext();
        delete current;
        current = next;
    }
}

// Name: InsertEnd
// Desc: Inserts a new item to the end of the workout using m_tail.
// Preconditions: Takes in an Exercise pointer. Inserts the new node to the tail.
//                Requires a Workout
// Postconditions: Adds the new item into the Workout.
void Workout::InsertEnd(Exercise* exercise) {
    if (m_tail == nullptr) {
        m_head = exercise;
        m_tail = exercise;
    } else {
        m_tail->SetNext(exercise);
        m_tail = exercise;
    }
    m_size++;
}

// Name: GetName()
// Preconditions: Requires a Workout
// Postconditions: Returns m_name;
string Workout::GetName() {
    return m_name;
}

// Name: GetSize()
// Preconditions: Requires a Workout
// Postconditions: Returns m_size;
int Workout::GetSize() {
    return m_size;
}

// Name: ReverseWorkout
// Preconditions: Reverses the Workout (updates m_head and m_tail)
//                Updates the pointers only - does not create a new list
// Postconditions: Workout is reversed in place; nothing returned
void Workout::ReverseWorkout() {
    Exercise* prev = nullptr;
    Exercise* current = m_head;
    Exercise* next = nullptr;

    m_tail = m_head;

    while (current != nullptr) {
        next = current->GetNext();
        current->SetNext(prev);
        prev = current;
        current = next;
    }

    m_head = prev;
}

// Name: GetData
// Desc: Returns the time at a specific location in the Workout
//       Pass
// Preconditions: Requires a Workout
// Postconditions: Returns data from specific item
Exercise* Workout::GetData(int nodeNum) {
    if (nodeNum < 0 || nodeNum >= m_size) {
        return nullptr;
    }

    Exercise* current = m_head;
    for (int i = 0; i < nodeNum; i++) {
        current = current->GetNext();
    }

    return current;
}

// Name: InsertSorted
// Desc: Inserts a new exercise into the workout in alphabetical order by category.
// Preconditions: Takes in an Exercise pointer. Inserts the new exercise while maintaining alphabetical order.
//                Requires a Workout.
// Postconditions: Adds the new exercise into the Workout in alphabetical order by category.
void Workout::InsertSorted(Exercise* exercise) {
    if (m_head == nullptr) {
        // If the workout is empty, set the new exercise as the head and tail.
        m_head = exercise;
        m_tail = exercise;
    } else {
        // Find the correct position to insert the exercise based on the category.
        Exercise* prev = nullptr;
        Exercise* current = m_head;

        while (current != nullptr && exercise->GetCategory() > current->GetCategory()) {
            prev = current;
            current = current->GetNext();
        }

        if (prev == nullptr) {
            // If the new exercise is inserted at the beginning of the list.
            exercise->SetNext(m_head);
            m_head = exercise;
        } else {
            // Insert the new exercise in the middle or at the end of the list.
            prev->SetNext(exercise);
            exercise->SetNext(current);
            if (current == nullptr) {
                // If the new exercise is inserted at the end of the list.
                m_tail = exercise;
            }
        }
    }

    m_size++;
}

// Name: operator<<
// Desc: Allows you to cout a Workout object
//       Overloaded << operator to return ostream from Workout
// Preconditions: Requires a Workout sequence
// Postconditions: Returns ostream populated for each Exercise in Workout
ostream& operator<<(ostream& output, Workout& myWorkout) {
    output << myWorkout.m_size << " " << "exercises" << endl;
    Exercise* current = myWorkout.m_head;

    while (current != nullptr) {
        output << *current << endl;
        current = current->GetNext();
    }

    return output;
}
