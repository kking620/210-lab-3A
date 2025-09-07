#include <iostream>
#include <iomanip>
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
    const int SIZE = 100;
    int index = 0;
    char repeat;

    Restaurant restaurantInfo[SIZE];
        
    string rName;
    string rAddress;
    string rCuisine;
    double rRating;
    double rCostPerPerson;

    for (repeat != 'n'; repeat != 'N';)
    {

        cout << "Would you like to input information on a restaurant? (Y/N)\n";
        cin >> repeat;
        cin.ignore();

        if (repeat == 'n' || repeat == 'N') break;
        else if (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y')
            cout << "Invalid character. Please try again.\n";
        else if (repeat == 'y' || repeat == 'Y')
            {
                Restaurant nRestaurant = populateRestaurant();
        
                Restaurant temp;
                    temp.name = nRestaurant.name;
                    temp.address = nRestaurant.address;
                    temp.cuisineType = nRestaurant.cuisineType;
                    temp.avgRating = nRestaurant.avgRating;
                    temp.avgCostPerPerson = nRestaurant.avgCostPerPerson;

                restaurantInfo[index++] = temp;
            }
        }

    cout << "Outputting Restaurant Info \n\n";
    for (int i = 0; i < index; i++)
    {
        cout << "Restaurant #" << i + 1 << endl;
        outputRestaurant(restaurantInfo[i]);
    }

    return 0;
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

void outputRestaurant(const Restaurant &r)
{
    cout << "Restaurant Name: " << r.name << endl;
    cout << "Restaurant Address: " << r.address << endl;
    cout << "Restaurant Cuisine: " << r.cuisineType << endl;

    cout.setf(ios::fixed|ios::showpoint);
    cout << setprecision(2);

    cout << "Average Rating: " << r.avgRating << endl;
    cout << "Average Cost Per Person: " << r.avgCostPerPerson << " dollars" << endl << endl;
}