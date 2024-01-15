#include "Manager.h"

// Name: Manager (constructor)
// Desc: Creates a Manager to manage workouts
// Preconditions:  None
// Postconditions: A manager is created to populate m_workouts
Manager::Manager(string fileName) {
    m_fileName = fileName;
    ReadFile();
    MainMenu();
}

// Name:  Manager (destructor)
// Desc: Deallocates all dynamic aspects of a Manager
// Preconditions: There is an existing Workout
// Postconditions: All workouts are cleared
Manager::~Manager() {
    for (Workout* workout : m_workouts) {
        delete workout;
    }
}
// Name:  DisplayWorkouts
// Desc: Displays each workout in m_workouts
// Preconditions: At least one workout is in m_workouts
// Postconditions: Displays all items in a workout for all
//                 workouts in m_workouts
void Manager::DisplayWorkouts() {
    if (m_workouts.empty()) {
        cout << "No workouts available." << endl;
        return;
    }

    for (Workout* workout : m_workouts) {
        cout << "******************" << endl;
        cout << "Workout for " << workout->GetName() << endl;
        cout << *workout << endl;
    }
}

int totalExercises = 0; // initializes total exercieses and workouts
int totalWorkouts = 0;

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
void Manager::ReadFile() {
    ifstream inputFile(m_fileName);
    if (!inputFile.is_open()) {
        cout << "Unable to open file: " << m_fileName << endl;
        return;
    }

    string line;
    string workoutName, category, exerciseName;
    int reps, weight;

    while (getline(inputFile, line)) {
        size_t found = 0;
        size_t prevFound = 0;
        found = line.find(';');

        if (found != string::npos) {
            workoutName = line.substr(prevFound, found - prevFound);
            prevFound = found + 1;
        }
        found = line.find(';', prevFound);

        if (found != string::npos) {
            category = line.substr(prevFound, found - prevFound);
            prevFound = found + 1;
        }
        found = line.find(';', prevFound);

        if (found != string::npos) {
            exerciseName = line.substr(prevFound, found - prevFound);
            prevFound = found + 1;
        }
        found = line.find(';', prevFound);

        if (found != string::npos) {
            reps = stoi(line.substr(prevFound, found - prevFound));
            prevFound = found + 1;
        }

        weight = stoi(line.substr(prevFound));

        int workoutIndex = FindWorkout(workoutName);

        if (workoutIndex == -1) {
            Workout* newWorkout = new Workout(workoutName);
            m_workouts.push_back(newWorkout);
            workoutIndex = m_workouts.size() - 1;
            totalWorkouts++;
        }

        Exercise* newExercise = new Exercise(category, exerciseName, reps, weight);
        m_workouts[workoutIndex]->InsertEnd(newExercise);
        totalExercises++;
    }

    inputFile.close();
}

// Name: FindWorkout
// Desc: Returns the index of the workout from m_workouts else -1
// Preconditions: Populated m_workouts
// Postconditions: Returns the index of workout with the matching name or it returns -1
int Manager::FindWorkout(string schedName) {
    for (size_t i = 0; i < m_workouts.size(); i++) {
        if (m_workouts[i]->GetName() == schedName) {
            return static_cast<int>(i);
        }
    }
    return -1;
}


// Name:  MainMenu
// Desc: Displays the main menu and manages exiting
// Preconditions: Populated m_workouts
// Postconditions: None
void Manager::MainMenu() {
    int choice;
    do {
        cout << "Opened File" << endl;
        cout << totalExercises << " exercises loaded across " << totalWorkouts << " workouts at the program open" << endl;
        cout << "What would you like to do?:\n"
             << "1. Display Workouts\n"
             << "2. Reverse Workouts\n"
             << "3. Insert New Exercise\n"
             << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                DisplayWorkouts();
                break;
            case 2:
                ReverseWorkout();
                break;
            case 3:
                InsertNewExercise();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

// Name: ReverseWorkout
// Desc: User chooses a workout and the workout is reversed
//       If only one workout in m_workouts, automatically reverses it without prompting the user
// Preconditions: Populated m_workouts
// Postconditions: Reverses a specific workout replacing in place
void Manager::ReverseWorkout() {
    if (m_workouts.empty()) {
        cout << "No workouts available to reverse." << endl;
        return;
    }

    if (m_workouts.size() == 1) {
        m_workouts[0]->ReverseWorkout();
        cout << "Reversed the only available workout." << endl;
    } else {
        cout << "Choose a workout to reverse:" << endl;
        for (size_t i = 0; i < m_workouts.size(); i++) {
            cout << i + 1 << ". " << m_workouts[i]->GetName() << endl;
        }

        size_t choice;
        do {
            cout << "Enter the number of the workout: ";
            cin >> choice;
            if (choice < 1 || choice > m_workouts.size()) {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice < 1 || choice > m_workouts.size());

        m_workouts[choice - 1]->ReverseWorkout();
        cout << "Reversed the selected workout: " << m_workouts[choice - 1]->GetName() << endl;
    }
}

// Name: InsertNewExercise
// Desc: Asks the user which workout they would like to insert into (uses FindWorkout)
//       If new workout, inserts a new workout and indicates a new workout was created
//       Prompts user for time and name of item then inserts item into workout
// Preconditions: Populated m_workouts
// Postconditions: Either inserts into existing workout or inserts into a new workout
void Manager::InsertNewExercise() {
    if (m_workouts.empty()) {
        cout << "No workouts available. Please create a workout first." << endl;
        return;
    }

    cout << "Choose a workout to insert a new exercise into:" << endl;
    for (size_t i = 0; i < m_workouts.size(); i++) {
        cout << i + 1 << ". " << m_workouts[i]->GetName() << endl;
    }

    size_t choice;
    do {
        cout << "Enter the number of the workout: ";
        cin >> choice;
        if (choice < 1 || choice > m_workouts.size()) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice < 1 || choice > m_workouts.size());

    string category, name;
    int reps, weight;

    cout << "Enter the name of the workout: "; // Prompt for the workout name.
    cin.ignore();
    getline(cin, workoutName); // Store the workout name entered by the user.

    cout << "Enter the category of the exercise: ";
    cin >> category;

    cout << "Enter the name of the exercise: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the number of reps: ";
    cin >> reps;

    cout << "Enter the weight (in lbs): ";
    cin >> weight;

    Exercise* newExercise = new Exercise(category, name, reps, weight);

    int workoutIndex = FindWorkout(workoutName);
    if (workoutIndex != -1) {
        // Insert the new exercise into the specified workout.
        m_workouts[workoutIndex]->InsertSorted(newExercise);
        cout << "New exercise inserted into the selected workout." << endl;
    } else {
        // If the workout doesn't exist, create a new one and insert the exercise.
        Workout* newWorkout = new Workout(workoutName);
        newWorkout->InsertSorted(newExercise);
        m_workouts.push_back(newWorkout);
        cout << "New workout created and exercise inserted." << endl;
    }
}
void Manager::ExportWorkouts() {
    cout << "Enter the name for the new exported file: ";
    string exportFileName;
    cin >> exportFileName;

    ofstream outputFile(exportFileName);
    if (!outputFile.is_open()) {
        cout << "Unable to create the export file: " << exportFileName << endl;
        return;
    }

    for (Workout* workout : m_workouts) {
        outputFile << "Workout for " << workout->GetName() << endl;
        Exercise* current = workout->GetHead();
        while (current != nullptr) {
            outputFile << current->GetCategory() << ";" << current->GetName() << ";" << current->GetReps() << ";" << current->GetWeight() << endl;
            current = current->GetNext();
        }
    }

    outputFile.close();
    cout << "Data exported to " << exportFileName << " successfully." << endl;
}

