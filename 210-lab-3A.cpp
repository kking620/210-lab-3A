#include <iostream>
#include <string>
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
    char repeat;
    
    for (repeat != 'n'; repeat != 'N';)
    {

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

void outputRestaurant(const Restaurant &c)
{

}