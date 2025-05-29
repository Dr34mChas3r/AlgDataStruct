#include <iostream>
#include <string>
using namespace std;

const int T = 10;

struct Participant {
    string passport;
    string surname;
    string school;
    int age;
};

void printParticipants(Participant arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". "
            << "Passport: " << arr[i].passport << ", "
            << "Surname: " << arr[i].surname << ", "
            << "School: " << arr[i].school << ", "
            << "Age: " << arr[i].age << endl;
    }
    cout << "-------------------------------" << endl;
}

void selectionSortByPassport(Participant arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j].passport < arr[minIdx].passport)
                minIdx = j;
        }
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

void insertionSortByAge(Participant arr[], int size) {
    for (int i = 1; i < size; ++i) {
        Participant key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].age > key.age) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    Participant list[T];

    cout << "Enter information about " << T << " participants:" << endl;
    for (int i = 0; i < T; ++i) {
        cout << "\nParticipant #" << i + 1 << endl;
        cout << "Passport series: ";
        cin >> ws;
        getline(cin, list[i].passport);

        cout << "Surname: ";
        getline(cin, list[i].surname);

        cout << "School: ";
        getline(cin, list[i].school);

        cout << "Age: ";
        cin >> list[i].age;
    }

    int choice;
    cout << "Choose sorting option:" << endl;
    cout << "0 - original order" << endl;
    cout << "1 - sort by passport (selection sort)" << endl;
    cout << "2 - sort by age (insertion sort)" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
    case 0:
        cout << "\n--- Original data ---" << endl;
        break;
    case 1:
        selectionSortByPassport(list, T);
        cout << "\n--- Sorted by passport ---" << endl;
        break;
    case 2:
        insertionSortByAge(list, T);
        cout << "\n--- Sorted by age ---" << endl;
        break;
    default:
        cout << "\nInvalid choice. Data remains unchanged." << endl;
        break;
    }

    printParticipants(list, T);

    return 0;
}
