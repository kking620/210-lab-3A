//COMSC-210 | Lab 3A | Kristofer King
//IDE Used: VSC

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//initializing the Restaurant structure for user inputted restaurant info
struct Restaurant
{
    string name;
    string address;
    string cuisineType;
    double avgRating;
    double avgCostPerPerson;
};

//prototype functions to fill the temporary structures with user input and outputs it in an organized format respectively
Restaurant populateRestaurant();
void outputRestaurant(const Restaurant &);

int main()
{
    //initializing and declaring variables
    const int SIZE = 100;
    int index = 0;
    char repeat;

    //initializing the array that will be filled with the restaurant info
    Restaurant restaurantInfo[SIZE];

    //for loop so the user can choose how many times they wish to input restaurant info
    for (repeat != 'n'; repeat != 'N';)
    {
        //gathers character input to determine if the user wishes to input restaurant info
        cout << "Would you like to input information on a restaurant? (Y/N)\n";
        cin >> repeat;
        cin.ignore();

        //these if statements check to make sure that the character is a valid input and perform different functions upon recognizing different characters
        if (repeat == 'n' || repeat == 'N') break;
        else if (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y')
            cout << "Invalid character. Please try again.\n";
        
        //if the user chooses to input information we call the function to fill a temporary structure that we then insert into our array
        else if (repeat == 'y' || repeat == 'Y')
            {
                Restaurant nRestaurant = populateRestaurant();
                
                //setting the values of the temporary structure in the main function to equal those gathered in the user input function 
                Restaurant temp;
                    temp.name = nRestaurant.name;
                    temp.address = nRestaurant.address;
                    temp.cuisineType = nRestaurant.cuisineType;
                    temp.avgRating = nRestaurant.avgRating;
                    temp.avgCostPerPerson = nRestaurant.avgCostPerPerson;

                //sets the value of a structure at this given location within an array
                restaurantInfo[index++] = temp;
            }
        }

    //once the user is done inputting information, all of the information is displayed in a readable format
    cout << "Outputting Restaurant Info \n\n";
    for (int i = 0; i < index; i++)
    {
        cout << "Restaurant #" << i + 1 << endl;
        outputRestaurant(restaurantInfo[i]);
    }

    return 0;
}

//function designed to gather user input and returns a temporary structure
Restaurant populateRestaurant()
{
    Restaurant temp;

    cout << "What is the name of the restaurant? \n";
    getline(cin, temp.name);
    
    cout << "What is the address of the restaurant? \n";
    getline(cin, temp.address);
    
    cout << "What type of cuisine is served at the restaurant? \n";
    getline(cin, temp.cuisineType);

    cout << "What is the average rating of this restaurant? \n";
    cin >> temp.avgRating;
    cin.ignore();

    cout << "What is the average cost per person? \n";
    cin >> temp.avgCostPerPerson;
    cin.ignore();

    return temp;
}

//function that displays the information stored in the structures in an organized manner
void outputRestaurant(const Restaurant &r)
{
    cout << "Restaurant Name: " << r.name << endl;
    cout << "Restaurant Address: " << r.address << endl;
    cout << "Restaurant Cuisine: " << r.cuisineType << endl;

    //formats the double values so that only two decimal places will be shown
    cout << fixed << showpoint << setprecision(2);

    cout << "Average Rating: " << r.avgRating << endl;
    cout << "Average Cost Per Person: " << r.avgCostPerPerson << " dollars" << endl << endl;
}