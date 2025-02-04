#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

// Structure for Member
struct Member {
    int id;
    string name;
    string contact;
    string password;
    vector<string> fitnessProgress;
    float height; // in meters
    float weight; // in kg
    Member* next;

    Member(int _id, string _name, string _contact, string _password)
        : id(_id), name(_name), contact(_contact), password(_password), height(0), weight(0), next(nullptr) {}

    // Function to calculate BMI
    float calculateBMI() {
        if (height > 0 && weight > 0) {
            return weight / (height * height);
        }
        return 0;
    }


    // Function to update the user profile
    void updateProfile() {
        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                               UPDATE YOUR PROFILE                               \n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                             ENTER NEW USER NAME:                               \n";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\t<|                             ENTER NEW CONTACT:                                 \n";
        getline(cin, contact);
        cout << "\t\t\t<|                             ENTER NEW PASSWORD:                               \n";
        getline(cin, password);
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|__________________________________________________________________________________\n";
    }
};

// Structure for Gym Classes
struct GymClass {
    string className;
    string schedule;
    string trainerName;
    int capacity;
    int enrolled;

    GymClass(string _className, string _schedule, string _trainerName, int _capacity)
        : className(_className), schedule(_schedule), trainerName(_trainerName), capacity(_capacity), enrolled(0) {}
};

class GymManagement {
private:
    Member* head;
    vector<GymClass> classes;
    unordered_map<string, string> adminAccounts;

public:
    GymManagement() : head(nullptr) {
        adminAccounts["admin"] = "admin123";  // Default admin credentials
    }

     void displayGymFacilities() {
    cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "\t\t\t< __________________________________________________________________________________ >\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|                            WELCOME TO OUR GYM FACILITIES!                         |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|                        Available Facilities for Your Fitness Journey:              |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   1. **Cardio Zone**:                                                          |>\n";
    cout << "\t\t\t<|      - State-of-the-art cardio equipment including treadmills, ellipticals, and   |>\n";
    cout << "\t\t\t<|        stationary bikes for cardiovascular fitness.                             |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   2. **Sauna & Steam Room**:                                                  |>\n";
    cout << "\t\t\t<|      - Relax and detoxify with our sauna and steam room after your workout.      |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   3. **Strength Training Area**:                                              |>\n";
    cout << "\t\t\t<|      - Fully equipped with free weights, weight machines, and benches to help    |>\n";
    cout << "\t\t\t<|        you build muscle and strength.                                           |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   4. **Group Fitness Classes**:                                               |>\n";
    cout << "\t\t\t<|      - Join our variety of group fitness classes such as yoga, pilates, Zumba,  |>\n";
    cout << "\t\t\t<|        and more!                                                                |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   5. **Personal Training Services**:                                          |>\n";
    cout << "\t\t\t<|      - Get personalized guidance from our certified trainers for a tailored      |>\n";
    cout << "\t\t\t<|        workout plan.                                                            |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   6. **Nutrition Counseling**:                                                |>\n";
    cout << "\t\t\t<|      - Consult with our nutrition experts to optimize your diet for your goals. |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   7. **Swimming Pool**:                                                       |>\n";
    cout << "\t\t\t<|      - Refresh yourself and enjoy a swim in our heated swimming pool.           |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|   8. **Massage & Recovery Area**:                                             |>\n";
    cout << "\t\t\t<|      - Rejuvenate your muscles with our post-workout massage and recovery area.  |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|                  Please let us know which facility you'd like to explore!       |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|                                                                                  |>\n";
    cout << "\t\t\t<|__________________________________________________________________________________|>\n";
    cout << "\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}

    bool adminLogin() {
        string username, password;
        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                 ADMIN LOGIN                                     \n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                             Enter Admin Username:                               \n";
        cin >> username;
        cout << "\t\t\t<|                             Enter Admin Password:                               \n";
        cin >> password;

        if (adminAccounts.count(username) && adminAccounts[username] == password) {
            cout << "\n Admin login successful!\n";
            return true;
        }
        cout << "\n Invalid login credentials!\n";
        return false;
    }

    // Register a member (for Admin to use)
    void addMember() {
        int id;
        string name, contact, password;

        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                   ADD MEMBER                                    \n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                             Enter Member ID:                                     \n";
        cin >> id;
        cout << "\t\t\t<|                             Enter Name:                                         \n";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\t<|                             Enter Contact:                                     \n";
        getline(cin, contact);
        cout << "\t\t\t<|                             Create Password:                                   \n";
        getline(cin, password);

        Member* newMember = new Member(id, name, contact, password);
        if (!head) {
            head = newMember;
        } else {
            Member* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newMember;
        }
        cout << "\n Member added successfully!\n";
    }

    // Register a member (for User to use)
    void registerMember() {
        int id;
        string name, contact, password;

        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                 REGISTER MEMBER                                 \n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                             Enter Member ID:                                     \n";
        cin >> id;

        // Check if ID already exists
        Member* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "\n ID already exists. Please choose a different ID.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "\t\t\t<|                             Enter Name:                                         \n";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\t<|                             Enter Contact:                                     \n";
        getline(cin, contact);
        cout << "\t\t\t<|                             Create Password:                                   \n";
        getline(cin, password);

        Member* newMember = new Member(id, name, contact, password);
        if (!head) {
            head = newMember;
        } else {
            Member* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newMember;
        }
        cout << "\n Member registered successfully!\n";

    }

    Member* memberLogin() {
        int id;
        string password;

        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                   MEMBER LOGIN                                    \n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                             Enter Member ID:                                     \n";
        cin >> id;
        cout << "\t\t\t<|                             Enter Password:                                     |>\n";
        cin.ignore();
        getline(cin, password);

        Member* temp = head;
        while (temp) {
            if (temp->id == id && temp->password == password) {
                cout << "\n Login successful!\n";
                displayGymFacilities();

                return temp;
            }
            temp = temp->next;
        }
        cout << "\n Invalid credentials!\n";
        return nullptr;
    }

    void addClass(string className, string schedule, string trainerName, int capacity) {
        classes.push_back(GymClass(className, schedule, trainerName, capacity));
        cout << "\n Class added successfully!\n";
    }

    void displayClasses() {
        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                 AVAILABLE GYM CLASSES                         \n";
        cout << "\t\t\t<|                                                                                 \n";
        cout << "\t\t\t<|                            Available Classes:                                    \n";

        if (classes.empty()) {
            cout << "\t\t\t<|                               No classes available.                           |>\n";
        } else {
            for (const auto& gymClass : classes) {
                cout << "\t\t\t<| Class: " << gymClass.className << ", Schedule: " << gymClass.schedule
                     << ", Trainer: " << gymClass.trainerName << ", Capacity: " << gymClass.capacity
                     << " (Enrolled: " << gymClass.enrolled << ")                              |>\n";
            }
        }

        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|__________________________________________________________________________________\n";
    }

    void signUpForClass(Member* member, string className) {
        for (auto& gymClass : classes) {
            if (gymClass.className == className) {
                if (gymClass.enrolled < gymClass.capacity) {
                    gymClass.enrolled++;
                    cout << "\n " << member->name << " successfully signed up for " << className << "!\n";
                    cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|_________________________________________________________________________________\n";
                } else {
                    cout << "\n Class is full!\n";
                }
                return;
            }
        }
        cout << "\n⚠️ Class not found!\n";
    }

    void displayMembers() {
        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        cout << "\t\t\t< __________________________________________________________________________________ >\n";
        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|                                 MEMBERS LIST                                     \n";
        cout << "\t\t\t<|                                                                                  \n";

        if (!head) {
            cout << "\t\t\t<|                              No members to display.                         \n";
        } else {
            Member* temp = head;
            while (temp) {
                cout << "\t\t\t<| ID: " << temp->id << ", Name: " << temp->name << ", Contact: " << temp->contact << " |>\n";
                temp = temp->next;
            }
        }

        cout << "\t\t\t<|                                                                                  \n";
        cout << "\t\t\t<|_________________________________________________________________________________\n";
    }

    // Function to search for a member by ID
    //method used is Linear Search
    Member* searchMemberByID(int id) {
        Member* temp = head;
        while (temp) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to delete a member by ID
    void deleteMember(int id) {
        Member* temp = head;
        Member* prev = nullptr;

        if (temp != nullptr && temp->id == id) {
            head = temp->next;
            delete temp;
            cout << "\n Member deleted successfully!\n";
            return;
        }

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "\n Member not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\n Member deleted successfully!\n";
    }
};

int main() {
    GymManagement gym;
    string userType;

    cout << "\n Welcome to the Gym Management System! \n";
    while (true) {
        cout << "\nAre you an ADMIN or USER? (Enter 'exit' to quit): ";
        cin >> userType;

        if (userType == "exit") break;
        if (userType == "admin" || userType == "ADMIN") {
            if (gym.adminLogin()) {
                int choice;
                while (true) {
                    cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                    cout << "\t\t\t< __________________________________________________________________________________ >\n";
                    cout << "\t\t\t<|                                                                                  \n";
                    cout << "\t\t\t<|                                ADMIN MENU                                       \n";
                    cout << "\t\t\t<|                                                                                  \n";
                    cout << "\t\t\t<| 1. Add Member                                                               \n";
                    cout << "\t\t\t<| 2. Add Class                                                         \n";
                    cout << "\t\t\t<| 3. Display Classes                                                         \n";
                    cout << "\t\t\t<| 4. Search Member by ID                                                     \n";
                    cout << "\t\t\t<| 5. Delete Member                                                           \n";
                    cout << "\t\t\t<| 6. Display All Members                                                    \n";
                    cout << "\t\t\t<| 7. Logout                                                                  \n";
                    cout << "\t\t\t<| Enter choice:                                                               \n";
                    cin >> choice;

                    if (choice == 2) {
                        string className, schedule, trainerName;
                        int capacity;
                        cout << "\t\t\t<| Enter Class Name:                                                        |>\n";
                        cin.ignore();
                        getline(cin, className);
                        cout << "\t\t\t<| Enter Schedule:                                                          |>\n";
                        getline(cin, schedule);
                        cout << "\t\t\t<| Enter Trainer Name:                                                     |>\n";
                        getline(cin, trainerName);
                        cout << "\t\t\t<| Enter Capacity:                                                         |>\n";
                        cin >> capacity;
                        gym.addClass(className, schedule, trainerName, capacity);

                    } else if (choice == 3) {
                        gym.displayClasses();

                    } else if (choice == 1) {
                        gym.addMember();  // Admin adds a member

                    } else if (choice == 4) {
                        int memberId;
                        cout << "\t\t\t<| Enter Member ID to search:                                             |>\n";
                        cin >> memberId;
                        Member* member = gym.searchMemberByID(memberId);
                        if (member) {
                            cout << "\nMember Found: ID: " << member->id << ", Name: " << member->name << ", Contact: " << member->contact << "\n";
                        } else {
                            cout << "\n Member not found!\n";
                        }

                    } else if (choice == 5) {
                        int memberId;
                        cout << "\t\t\t<| Enter Member ID to delete:                                             |>\n";
                        cin >> memberId;
                        gym.deleteMember(memberId);
                    } else if (choice == 6) {
                        gym.displayMembers();
                    } else break;
                }
            }
        } else if (userType == "user" || userType == "USER") {
            cout << "\n1. Register \n2. Login\nEnter choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                gym.registerMember();  // User registers
            } else {
                Member* member = gym.memberLogin();
                if (member) {
                    while (true) {
                        cout << "\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
                        cout << "\t\t\t< __________________________________________________________________________________ ";
                        cout << "\t\t\t<|                                                                                  \n";
                        cout << "\t\t\t<|                               USER MENU                                       \n";
                        cout << "\t\t\t<|                                                                                  \n";
                        cout << "\t\t\t<| 1. View Profile                                                           \n";
                        cout << "\t\t\t<| 2. Sign Up for Class                                                      \n";
                        cout << "\t\t\t<| 3. View Classes                                                           \n";
                        cout << "\t\t\t<| 4. Update Profile                                                         \n";
                        cout << "\t\t\t<| 5. Calculate BMI                                                          \n";
                        cout << "\t\t\t<| 6. Logout                                                                 \n";
                        cout << "\t\t\t<| Enter choice:                                                              \n";
                        cin >> choice;

                        if (choice == 3) gym.displayClasses();

                        else if (choice == 2) {
                            string className;
                            cout << "\t\t\t<| Enter Class Name:                                                        \n";
                            cin.ignore();
                            getline(cin, className);
                            gym.signUpForClass(member, className);

                        } else if (choice == 1) {
                            cout << "\nProfile:\nName: " << member->name << "\nContact: " << member->contact << "\n";

                        } else if (choice == 4) {
                            member->updateProfile();

                        } else if (choice == 5) {

                            cout << "\t\t\t<| Enter your height in meters:                                          \n";
                            cin >> member->height;
                            cout << "\t\t\t<| Enter your weight in kg:                                              \n";
                            cin >> member->weight;

                            float bmi = member->calculateBMI();
                            if (bmi > 0) {
                                cout << "\nYour BMI: " << bmi << "\n";
                            } else {
                                cout << "\n  Invalid height or weight!\n";
                            }
                        } else break;
                    }
                }
            }
        } else {
            cout << "\n  Invalid input! Please enter 'USER' or 'ADMIN'. ⚠️\n";
        }
    }
    return 0;
}
