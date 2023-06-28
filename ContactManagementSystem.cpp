#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact {
public:
    string cName;
    int cGender;
    int cAge;
    string cPhone;
    string cAdd;

    Contact(const string& name, int gender, int age, const string& phone, const string& address)
        : cName(name), cGender(gender), cAge(age), cPhone(phone), cAdd(address) {}
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    void AddContact(const string& name, int gender, int age, const string& phone, const string& address) {
        contacts.emplace_back(name, gender, age, phone, address);
        cout << "Contact added successfully!" << endl;
    }

    void ShowContacts() {
        if (contacts.empty()) {
            cout << "No contacts available." << endl;
            return;
        }

        for (const Contact& contact : contacts) {
            cout << "Name: " << contact.cName << " Gender: " << (contact.cGender != 2 ? "Male" : "Female")
                 << " Age: " << contact.cAge << " Phone: " << contact.cPhone << " Address: " << contact.cAdd << endl;
        }
    }

    void DeleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->cName == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void SearchContact(const string& name) {
        for (const Contact& contact : contacts) {
            if (contact.cName == name) {
                cout << "Name: " << contact.cName << " Gender: " << (contact.cGender != 2 ? "Male" : "Female")
                     << " Age: " << contact.cAge << " Phone: " << contact.cPhone << " Address: " << contact.cAdd << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void ModifyContact(const string& name) {
        for (Contact& contact : contacts) {
            if (contact.cName == name) {
                cout << "Name: " << contact.cName << " Gender: " << (contact.cGender != 2 ? "Male" : "Female")
                     << " Age: " << contact.cAge << " Phone: " << contact.cPhone << " Address: " << contact.cAdd << endl;

                int gender;
                cout << "Enter the new gender: " << endl;
                cout << "1 ---- Male " << endl;
                cout << "2 ---- Female " << endl;
                cin >> gender;
                while (gender != 1 && gender != 2) {
                    cout << "Invalid input. Please try again!" << endl;
                    cin >> gender;
                }
                contact.cGender = gender;

                int age;
                cout << "Enter the new age: " << endl;
                cin >> age;
                contact.cAge = age;

                string phone;
                cout << "Enter the new phone number: " << endl;
                cin >> phone;
                contact.cPhone = phone;

                string add;
                cout << "Enter the new address: " << endl;
                cin >> add;
                contact.cAdd = add;

                cout << "Contact modified successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void ClearContacts() {
        contacts.clear();
        cout << "All contacts cleared!" << endl;
    }
};

void ShowMenu() {
    cout << "***** Address Book Management System *****" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display Contacts" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Search Contact" << endl;
    cout << "5. Modify Contact" << endl;
    cout << "6. Clear Contacts" << endl;
    cout << "0. Exit" << endl;
    cout << "***************************************" << endl;
    cout << "Enter your choice: ";
}

int main() {
    AddressBook addressBook;
    int choice;

    while (true) {
        ShowMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, phone, address;
                int gender, age;

                cout << "Enter the name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter the gender (1 - Male, 2 - Female): ";
                cin >> gender;

                cout << "Enter the age: ";
                cin >> age;

                cout << "Enter the phone number: ";
                cin >> phone;

                cout << "Enter the address: ";
                cin.ignore();
                getline(cin, address);

                addressBook.AddContact(name, gender, age, phone, address);
                break;
            }
            case 2:
                addressBook.ShowContacts();
                break;
            case 3: {
                string name;
                cout << "Enter the name of the contact to delete: ";
                cin.ignore();
                getline(cin, name);
                addressBook.DeleteContact(name);
                break;
            }
            case 4: {
                string name;
                cout << "Enter the name of the contact to search: ";
                cin.ignore();
                getline(cin, name);
                addressBook.SearchContact(name);
                break;
            }
            case 5: {
                string name;
                cout << "Enter the name of the contact to modify: ";
                cin.ignore();
                getline(cin, name);
                addressBook.ModifyContact(name);
                break;
            }
            case 6:
                addressBook.ClearContacts();
                break;
            case 0:
                cout << "Thank you for using the Address Book Management System!" << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again!" << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}
