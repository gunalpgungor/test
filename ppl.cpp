#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    string surname;
    string birthday;
    string gender;
    Person* next;
};

class PersonList {
private:
    Person* head;

public:
    PersonList() {
        head = nullptr;
    }

    void addPerson(const string& name, const string& surname, const string& birthday, const string& gender) {  // add person
        Person* newPerson = new Person;
        newPerson->name = name;
        newPerson->surname = surname;
        newPerson->birthday = birthday;
        newPerson->gender = gender;
        newPerson->next = nullptr;

        if (head == nullptr) {
            head = newPerson;
        }
        else {
            Person* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPerson;
        }
    }

    void displayPeople() {  // display the list
        cout << "People List:\n";
        cout << "------------\n";

        Person* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->name << " " << current->surname << endl;
            cout << "Birthday: " << current->birthday << endl;
            cout << "Gender: " << current->gender << endl;
            cout << "------------\n";
            current = current->next;
        }
    }

    void sortByName() {  // sort by name
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;
        Person* ptr1;
        Person* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->name > ptr1->next->name) {
                    swap(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void sortByAge() {  // sort by age
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;
        Person* ptr1;
        Person* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->birthday > ptr1->next->birthday) {
                    swap(ptr1, ptr1->next);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void swap(Person* a, Person* b) {  // swap data
        string tempName = a->name;
        string tempSurname = a->surname;
        string tempBirthday = a->birthday;
        string tempGender = a->gender;

        a->name = b->name;
        a->surname = b->surname;
        a->birthday = b->birthday;
        a->gender = b->gender;

        b->name = tempName;
        b->surname = tempSurname;
        b->birthday = tempBirthday;
        b->gender = tempGender;
    }

    void findPerson(const string& name) {  // search by name
        Person* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Person Info:\n";
                cout << "------------\n";
                cout << "Name: " << current->name << " " << current->surname << endl;
                cout << "Birthday: " << current->birthday << endl;
                cout << "Gender: " << current->gender << endl;
                cout << "------------\n";
                return;
            }
            current = current->next;
        }

        cout << "Person not found!\n";
    }

    Person* getYoungestPerson() {  // youngest person
        Person* youngestPerson = nullptr;
        string youngestBirthday;

        Person* current = head;
        while (current != nullptr) {
            if (youngestBirthday.empty() || current->birthday < youngestBirthday) {
                youngestBirthday = current->birthday;
                youngestPerson = current;
            }
            current = current->next;
        }
        return youngestPerson;
    }

    Person* getOldestPerson() {  // oldest person
        Person* oldestPerson = nullptr;
        string oldestBirthday;

        Person* current = head;
        while (current != nullptr) {
            if (oldestBirthday.empty() || current->birthday > oldestBirthday) {
                oldestBirthday = current->birthday;
                oldestPerson = current;
            }
            current = current->next;
        }
        return oldestPerson;
    }
};

int main() {
    PersonList people;

    int choice;
    string name, surname, birthday, gender, searchName;

    do {
        cout << "Menu:\n";
        cout << "1. Add new person\n";
        cout << "2. List sorted by name\n";
        cout << "3. List sorted by age\n";
        cout << "4. Show youngest and oldest person\n";
        cout << "5. Find person\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the following details:\n";
                cout << "Name: ";
                cin >> name;
                cout << "Surname: ";
                cin >> surname;
                cout << "Birthday (format: YYYY-MM-DD): ";
                cin >> birthday;
                cout << "Gender: ";
                cin >> gender;
                people.addPerson(name, surname, birthday, gender);
                cout << "Person added!\n";
                break;

            case 2:
                people.sortByName();
                people.displayPeople();
                break;

            case 3:
                people.sortByAge();
                people.displayPeople();
                break;

            case 4: {
                Person* youngestPerson = people.getYoungestPerson();
                Person* oldestPerson = people.getOldestPerson();

                if (youngestPerson != nullptr) {
                    cout << "Youngest person:\n";
                    cout << "Name: " << youngestPerson->name << " " << youngestPerson->surname << endl;
                    cout << "Birthday: " << youngestPerson->birthday << endl;
                    cout << "Gender: " << youngestPerson->gender << endl;
                }

                if (oldestPerson != nullptr) {
                    cout << "Oldest person:\n";
                    cout << "Name: " << oldestPerson->name << " " << oldestPerson->surname << endl;
                    cout << "Birthday: " << oldestPerson->birthday << endl;
                    cout << "Gender: " << oldestPerson->gender << endl;
                }
                break;
            }

            case 5:
                cout << "Enter the name of the person to search: ";
                cin >> searchName;
                people.findPerson(searchName);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}

