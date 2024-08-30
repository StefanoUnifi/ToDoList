#include <iostream>
#include "ToDoList.h"

 void displayOptions();

int main() {
    ToDoList list;
    bool stop = false;
    int option;

    std::cout << std::endl;
    std::cout << "\t\t\t***** Welcome To my Todo List! *****" << std::endl;
    displayOptions();

    do{
        std::cin >> option;

        std::string title;
        std::string description;
        std::string stringDate;
        Date date;
        int choice;
        std::string newDesc;

        switch(option){
            case 0:
                stop = true;
                std::cout << "\n************************************************************" << std::endl;
                std::cout << "\n\t\tThank you for using my application...\n\t\t\tGoodbye!" << std::endl;
                std::cout << "\n************************************************************" << std::endl;
                break;

            case 1:
                std::cout << "Please enter the name of the todolist: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                list.setTitle(title);
                list.removeActivities();
                std::cout << "Your new todolist '"<< list.getTitle() <<"' was created!" << std::endl;
                break;

            case 2:
                std::cout << "Please enter the description of the activity: ";
                std::cin.ignore();
                std::getline(std::cin, description);

                std::cout << "Eneter also the due date of the activity (day/month/year):";
                std::cin.ignore();
                std::getline(std::cin, stringDate);

                date = Activity::getDateFromString(stringDate);
                list.addActivity(Activity(date, description));
                break;

            case 3:
                std::cout << "Please enter the description of the activity you want to remove: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                list.removeActivity(description);
                break;

            case 4:
                std::cout << "Please enter the description of the activity you want to modify: ";
                std::cin.ignore();
                std::getline(std::cin, description);

                std::cout << "What would you like to modify? (1-->description, 2-->date, 3-->completed): ";
                std::cin >> choice;

                if(choice == 1){
                    std::cout << "Enter the new description: ";
                    std::cin.ignore();
                    std::getline(std::cin, description);
                    list.modifyActivity(description, newDesc, date);
                }else if(choice == 2){
                    std::cout << "Enter the new date (day/month/year): ";
                    std::cin.ignore();
                    std::getline(std::cin, stringDate);
                    date = Activity::getDateFromString(stringDate);
                    list.modifyActivity(description, newDesc, date);
                }else if(choice == 3)
                    list.modifyActivity(description, newDesc, date);
                else
                    std::cout << "Invalid choice!" << std::endl;

                break;

            case 5:
                std::cout << "Please enter the description of the activity you want to set as completed: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                list.setActivityCompleted(description);
                break;

            case 6:
                displayOptions();
                break;

            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }

    }while(!stop);

    return 0;
}

void displayOptions(){
    std::cout << "\nList of options: " << std::endl;
    std::cout << "0) Exit " << std::endl;
    std::cout << "1) Create your NEW todolist " << std::endl;
    std::cout << "2) Add a new Activity " << std::endl;
    std::cout << "3) Remove an Activity " << std::endl;
    std::cout << "4) Modify an Activity " << std::endl;
    std::cout << "5) Set completed an Activity " << std::endl;
    std::cout << "6) Display the options" << std::endl;
}
