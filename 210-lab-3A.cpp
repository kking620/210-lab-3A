#include <iostream>
#include <vector>

using namespace std;

struct Restaurant
{
    string name;
    string address;
    string cuisineType;
    double avgRating;
    double avgCostPerPerson;
};

Restaurant populateRestaurant();
void outputRestaurant(const Restaurant &);

int main()
{
    while(true)
    {
        char repeat;
        
        cout << "Would you like to input information on a restaurant? (Y/N)\n";
        cin >> repeat;
        cin.ignore();

        if (repeat == 'y' || repeat == 'Y')
        {
            Restaurant nRestaurant = populateRestaurant();
        }

        else if (repeat == 'n' || repeat == 'N') break;
        else if (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y')
            cout << "Invalid character. Please try again.\n";

    }

}

Restaurant populateRestaurant()
{
    Restaurant temp;

    cout << "What is the name of the restaurant? \n";
    cin >> temp.name;
    cin.ignore();
    
    cout << "What is the address of the restaurant? \n";
    cin >> temp.address;
    cin.ignore();
    
    cout << "What type of cuisine is served at the restaurant? \n";
    cin >> temp.cuisineType;
    cin.ignore();

    cout << "What is the average rating of this restaurant? \n";
    cin >> temp.avgRating;
    cin.ignore();

    cout << "What is the average cost per person? \n";
    cin >> temp.avgCostPerPerson;
    cin.ignore();

    return temp;
}