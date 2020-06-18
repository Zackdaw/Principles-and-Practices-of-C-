#include "std_lib_facilities.h"

int main()
{
    string first_name = " ";
    int age = -1;
    string age_substring = " ";
    string friend_name = " ";
    string body_substring = " ";

    cout << "\tWelcome to the Name program!" << "\n\nPlease enter your name:\n";
    cin >> first_name;

    string personal_substring = "\nHello " + first_name + ",\n";
    string sign_off = "\n\tBest regards,\n\n\n\t\tHenry.\n\n";


    while (age < 0 || age > 110)
    {
        cout << "How old are you?\n";
        cin >> age;
        if (age > 0 && age < 12)
        {
            string age_int_to_string = std::to_string(age + 1);
            age_substring = "I heard you have a birthday coming up! You'll be " + age_int_to_string + " years old!\n";
            break;
        }
        if (age == 17)
        {
            age_substring = "Next year you'll be able to vote!\n";
            break;
        }
        if (age > 70)
        {
            age_substring = "I hope you're enjoying retirement!\n";
            break;
        }
        if (age > 0 && age < 110)
        {
            age_substring = "I hope you're doing well.\n";
            break;
        }
        cout << "Error! Age is " << age;
        age = -1;
    }

    cout << "What is the name of your friend?\n";
    cin >> friend_name;

    while (body_substring != "Male" || body_substring != "Female")
    {
        cout << "Are they male or female? (Use M or F)\n";
        cin >> body_substring;

        if (body_substring == "M" || body_substring == "m")
        {
            body_substring = "If you see " + friend_name + " please have him call me. ";
            break;
        }
        if (body_substring == "F" || body_substring == "f")
        {
            body_substring = "If you see " + friend_name + " please have her call me. ";
            break;
        }
        cout << "/nError: No valid gender entered./n";
        body_substring = " ";
    }

    cout << personal_substring + body_substring + age_substring + sign_off;

    keep_window_open();
    return 0;
}