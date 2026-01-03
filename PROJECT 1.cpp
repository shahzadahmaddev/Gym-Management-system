//semester project
//bank management system formed by
//SHAHZAD AHMED        251301023
//NAMRA IRFAN          251301014
//START
#include<iostream>
#include <string>
using namespace std;

// Maximum number of members
const int MAX_MEMBERS = 50;

// Arrays to store member data
int memberID[MAX_MEMBERS];
string memberName[MAX_MEMBERS];
int memberAge[MAX_MEMBERS];
float memberWeight[MAX_MEMBERS];
string membership[MAX_MEMBERS];
int totalMembers = 0;

// Function to add a new member
void addMember() {
    if (totalMembers >= MAX_MEMBERS) {
        cout << "\n** Gym is full! Cannot add more members. **\n";
        return;
    }
    
    cout << "\n--- Add New Member ---\n";
    
    memberID[totalMembers] = totalMembers + 1;
    cout << "Member ID: " << memberID[totalMembers] << endl;
    
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, memberName[totalMembers]);
    
    cout << "Enter Age: ";
    cin >> memberAge[totalMembers];
    
    cout << "Enter Weight (kg): ";
    cin >> memberWeight[totalMembers];
    
    cout << "Enter Membership Type (Monthly/3Months): ";
    cin >> membership[totalMembers];
    
    totalMembers++;
    cout << "\n** Member added successfully! **\n";
}

// Function to display all members
void displayAllMembers() {
    if (totalMembers == 0) {
        cout << "\n** No members registered yet! **\n";
        return;
    }
    
    cout << "\n--- All Members ---\n";
    for (int i = 0; i < totalMembers; i++) {
        cout << "\nMember " << (i + 1) << ":\n";
        cout << "ID: " << memberID[i] << endl;
        cout << "Name: " << memberName[i] << endl;
        cout << "Age: " << memberAge[i] << endl;
        cout << "Weight: " << memberWeight[i] << " kg" << endl;
        cout << "Membership: " << membership[i] << endl;
    }
}

// Function to search member by ID
void searchMember() {
    if (totalMembers == 0) {
        cout << "\n** No members registered yet! **\n";
        return;
    }
    
    int searchID;
    cout << "\nEnter Member ID to search: ";
    cin >> searchID;
    
    bool found = false;
    for (int i = 0; i < totalMembers; i++) {
        if (memberID[i] == searchID) {
            cout << "\n--- Member Found ---\n";
            cout << "ID: " << memberID[i] << endl;
            cout << "Name: " << memberName[i] << endl;
            cout << "Age: " << memberAge[i] << endl;
            cout << "Weight: " << memberWeight[i] << " kg" << endl;
            cout << "Membership: " << membership[i] << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\n** Member not found! **\n";
    }
}

// Function to calculate total gym revenue
void calculateRevenue() {
    float totalRevenue = 0;
    
    for (int i = 0; i < totalMembers; i++) {
        if (membership[i] == "Monthly" || membership[i] == "monthly") {
            totalRevenue += 1000; // Monthly fee
        } else if (membership[i] == "3Months" || membership[i] == "3months") {
            totalRevenue += 2500; // 3 months fee
        }
    }
    
    cout << "\n--- Revenue Report ---\n";
    cout << "Total Members: " << totalMembers << endl;
    cout << "Total Revenue: Rs. " << totalRevenue << endl;
}

// Function to display members by age category
void displayByAgeCategory() {
    if (totalMembers == 0) {
        cout << "\n** No members registered yet! **\n";
        return;
    }
    
    cout << "\n--- Members by Age Category ---\n";
    
    cout << "\nYouth (18-30):\n";
    for (int i = 0; i < totalMembers; i++) {
        if (memberAge[i] >= 18 && memberAge[i] <= 30) {
            cout << memberName[i] << " (Age: " << memberAge[i] << ")\n";
        }
    }
    
    cout << "\nAdult (31-50):\n";
    for (int i = 0; i < totalMembers; i++) {
        if (memberAge[i] >= 31 && memberAge[i] <= 50) {
            cout << memberName[i] << " (Age: " << memberAge[i] << ")\n";
        }
    }
    
    cout << "\nSenior (51+):\n";
    for (int i = 0; i < totalMembers; i++) {
        if (memberAge[i] > 50) {
            cout << memberName[i] << " (Age: " << memberAge[i] << ")\n";
        }
    }
}

int main() {
    int choice;
    
    cout << "========================================\n";
    cout << "   GYM MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    
    // Main loop
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Add New Member\n";
        cout << "2. Display All Members\n";
        cout << "3. Search Member by ID\n";
        cout << "4. Calculate Revenue\n";
        cout << "5. Display Members by Age Category\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        // If-else statements for menu selection
        if (choice == 1) {
            addMember();
        } else if (choice == 2) {
            displayAllMembers();
        } else if (choice == 3) {
            searchMember();
        } else if (choice == 4) {
            calculateRevenue();
        } else if (choice == 5) {
            displayByAgeCategory();
        } else if (choice == 6) {
            cout << "\n** Thank you for using Gym Management System! **\n";
            break;
        } else {
            cout << "\n** Invalid choice! Please try again. **\n";
        }
    }
    
    return 0;
}
//END
