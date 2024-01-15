//Desc: This file contains the header details for the Manager class

#ifndef MANAGER_H
#define MANAGER_H

#include "Exercise.h"
#include "Workout.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Manager {
public:
    // Name: Manager (constructor)
    // Desc: Creates a Manager to manage workouts
    // Preconditions:  None
    // Postconditions: A manager is created to populate m_workouts
    Manager(string fileName);
    // Name:  Manager (destructor)
    // Desc: Deallocates all dynamic aspects of a Manager
    // Preconditions: There is an existing Workout
    // Postconditions: All workouts are cleared
    ~Manager();
    // Name:  DisplayWorkouts
    // Desc: Displays each workout in m_workouts
    // Preconditions: At least one workout is in m_workouts
    // Postconditions: Displays all items in a workout for all
    //                 workouts in m_workouts
    void DisplayWorkouts();
    // Name:  ReadFile
    // Desc: Reads in a file that has each part of the workout
    //       Starts with category, name, reps, and weight.
    //       Input files are an indeterminate length.
    //       There are an indeterminate number of workouts in
    //       an input file.
    //       There are an indeterminate number of exercises in each file.
    //       The vector can hold many workouts.
    // Preconditions: Valid file name of workouts
    // Postconditions: Populates each workout and puts in m_workouts
    void ReadFile();
    // Name: InsertNewExercise
    // Desc: Asks the user which workout they would like to insert into (uses FindWorkout)
    //       If new workout, inserts a new workout and indicates a new workout was created
    //       Prompts user for time and name of item then inserts item into workout
    // Preconditions: Populated m_workouts
    // Postconditions: Either inserts into existing workout or inserts into a new workout
    void InsertNewExercise();
    // Name: FindWorkout
    // Desc: Returns the index of the workout from m_workouts else -1
    // Preconditions: Populated m_workouts
    // Postconditions: Returns the index of workout with the matching name or it returns -1
    int FindWorkout(string schedName);
    // Name:  MainMenu
    // Desc: Displays the main menu and manages exiting
    // Preconditions: Populated m_workouts
    // Postconditions: None
    void MainMenu();
    // Name: ReverseWorkout
    // Desc: User chooses a workout and the workout is reversed
    //       If only one workout in m_workouts, automatically reverses it without prompting the user
    // Preconditions: Populated m_workouts
    // Postconditions: Reverses a specific workout replacing in place
    void ReverseWorkout();
    // Name: ExportWorkouts
    // Desc: Exports the data to a new input file
    // Preconditions: None
    // Postconditions: Creates a new input file with the data from m_workouts
    void ExportWorkouts();

private:
    vector<Workout*> m_workouts; //Vector of all workouts
    string m_fileName; //File to read in
    string workoutName;

};


#endif

