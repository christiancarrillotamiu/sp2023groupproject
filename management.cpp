#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void adminFileGeneration();

int main() 
{
    adminFileGeneration();

    string response, response2, teacherUser, teacherPass, teacherUserLogin, teacherPassLogin, teacherUserFile, teacherPassFile;

    cout << "               Welcome to Riverdale Academy! \nPlease specify if you are a student, teacher, or administrator.\n";
    cout << "\n";
    cout << "      A. Student       B. Teacher       C. Administrator\n";
    cout << "\n";

    cin >> response;

    if (response == "a" || response == "A" || response == "a." || response == "A.")
    {
        cout << "  \nWould you like to create a new account?";
    }
    else if (response == "b" || response == "B" || response == "b." || response == "B.")
    {
        cout << "  \nWould you like to:\n";
        cout << "A. Create a new account\n";
        cout << "B. Log In\n";
        cin >> response2;
        
        if (response2 == "A" || response2 == "a" || response2 == "A." || response2 == "a.")
        {
            cout << "  \n Please enter a username and password to create your faculty account.\n";
            cout << "Username: ";
            cin >> teacherUser;
            cout << "Password: ";
            cin >> teacherPass;

            ofstream teacherFile("teacher_login.txt"); // Creates new file containing teacher login info
            teacherFile << teacherUser << endl;
            teacherFile << teacherPass << endl;
            teacherFile.close();

            cout << "Please log in to your newly created faculty account.\n";
            cout << "\n";
            cout << "Username: ";
            cin >> teacherUserLogin;
            cout << "Password: ";
            cin >> teacherPassLogin;

            ifstream teacherFileCheck("teacher_login.txt"); // Open the file to assign 
            getline(teacherFileCheck, teacherUserFile);
            getline(teacherFileCheck, teacherPassFile);
            teacherFileCheck.close();

            if (teacherUserLogin == teacherUserFile && teacherPassLogin == teacherPassFile) // If the inputted username and password match up with what's stored on the teacher login info file, the login is successful
            {

            }
        }
        else if (response2 == "B" || response2 == "b" || response2 == "B." || response2 == "b.")
        {

        }
    }
    

}

void adminFileGeneration() // Creates the admin login info
{

    string adminUserFile, adminPassFile;

    ifstream adminFile("admin_login.txt");

    if (!adminFile.good()) // Checks if the file already exists
    {

        ofstream adminFile("admin_login.txt"); // Creates the file if it doesn't already exist
        adminFile << "admin" << endl;
        adminFile << "admin123" << endl;
        adminFile.close();

    }
    else

    {

        adminFile.close(); // If the file exists, does nothing

    }

    ifstream readFile("admin_login.txt");

    getline(readFile, adminUserFile);
    getline(readFile, adminPassFile);

    readFile.close();

}
