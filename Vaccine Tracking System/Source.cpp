#include <iostream>
#include "Linkedlist.h"
#include "Users.h"
using namespace std;
int main()
{
    Users user;
    string x;
    int choice;
    string id;
    string password;
    int your_choice;
    string username;
    while (true)
    {
        cout << "Please choose your option:(1/User - 2/Admin - 3/Exit)" << endl;
        cout << "Enter your option" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            do {
                cout << "Please enter your choice: (1/SignUp - 2/Display/Edit/Delete)" << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    user.SignUp();
                    break;
                }
                case 2: {
                    cout << "Enter your id \n";
                    cin >> id;
                    cout << "Enter your password \n";
                    cin >> password;
                    string user_id = user.Login(id, password);
                    cout << "Enter your choice: (1/Display - 2/Edit- 3/Delete)" << endl;
                    cin >> your_choice;
                    switch (your_choice)
                    {
                    case 1:
                    {
                        user.DisplayInfo(user_id);
                        break;
                    }
                    case 2:
                    {
                        user.UpdateInfo(user_id);
                        break;
                    }
                    case 3:
                    {
                        user.Delete_user_record(user_id);
                        break;

                    }
                    }
                    break;
                }
                }
                cout << "Do you want to continue ?" << endl;
                cin >> x;

            } while (x == "y");

            break;
        }

        case 2:
        {

            do {

                cout << "Please enter your choice: (1/Login)" << endl;
                cin >> choice;
                switch (choice)
                {

                case 1:
                {
                    cout << "enter your username \n";
                    cin >> username;
                    cout << "enter your password \n";
                    cin >> password;
                    user.Login_Admin(username,password);
                    cout << "Enter your choice: (1/DisplayAll - 2/displayOneUser- 3/DeleteAll - 4/deleteOne - 5/%of all people - 6/% unvaccinated- 7/% vaccinatedone - 8/% vaccinatedtwo - 9/%ageVac - 10/%femaleVac - 11/%femalunVac - 12/%countryVac)" << endl;
                    cin >> your_choice;
                    switch (your_choice)
                    {
                    case 1:
                    {
                        user.DisplayAllUsers();
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter User's id" << endl;
                        cin >> id;
                        user.DisplayInfo(id);
                        break;
                    }
                    case 3:
                    {
                        user.DeleteAllUsers();
                        break;

                    }
                    case 4: {
                        cout << "Enter User's id" << endl;
                        cin >> id;
                        user.Delete_user_record(id);
                        break;
                    }
                    case 5: {
                        user.calcAllpeople();
                        break;
                    }
                    case 6: {
                        user.calcUnvacinated();
                        break;
                    }
                    case 7: {
                        user.Vac_with_oneDose();
                        break;
                    }
                    case 8: {
                        user.Vac_with_twoDoses();
                        break;
                    }
                    case 9: {
                        user.calcVac_age();
                        break;
                    }
                    case 10: {
                        user.calcVac_female();
                        break;
                    }
                    case 11: {
                        user.calcunVac_female();
                        break;
                    }
                    case 12: {
                        user.calcVac_country();
                        break;
                    }
                
                }
                    break;
                }

                
                }
                cout << "Do you want to continue ?" << endl;
                cin >> x;

            } while (x == "y");
            break;
        }
        case 3:
        {
            exit(0);
            break;

        }
        }

    }


    return 0;
}