#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void ruler()
{
    cout << "\n12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n\n";
}

struct City
{
    string name;
    long int population;
    double cost;
};

struct Country
{
    string name;
    vector<City> cities;
};

struct Tours
{
    string title;
    vector<Country> countries;
};

int main()
{
    int flag = 1;
    Tours tour = {
        "Tours ticket prices from Miami to South America",
        {{"Colombia",
          {{"Bogota", 18152301, 500.99},
           {"Cali", 9808802, 424.1},
           {"Medellin", 1023991, 450.55},
           {"Cartagena", 972000, 399.91}}},
         {"Brazil",
          {{"Rio De Janiero", 13500000, 576.45},
           {"Sao Paulo", 11310000, 975.2},
           {"Salvador", 18244000, 855.99}}},
         {"Chile",
          {{"Valdivia", 260000, 533.12},
           {"Santiago", 7040000, 420.55}}},
         {"Brazil",
          {{"Buenos Aires", 3010000, 723.23}}}}};

    // for(const auto &country : tour.countries){
    //     cout << country.name << endl;
    //     for(const auto &cities : country.cities){
    //         cout << "\t" << cities.name;
    //         cout << "\t" << cities.population;
    //         cout << "\t" << cities.cost << endl;
    //     }
    // }

    ruler();
    cout << setw(75) << right << tour.title << endl
         << endl;
    cout << setw(30) << left << "Country"
         << setw(30) << left << "City"
         << setw(30) << left << "Population"
         << setw(30) << left << "Cost" << endl;

    cout << setfill('-') << setw(96) << right << " " << endl;

    for (auto &country : tour.countries)
    {
        cout << setfill(' ');

        for (auto &city : country.cities)
        {
            if (flag == 1)
            {
                cout << setw(30) << left << country.name;
                cout << setw(30) << left << city.name
                     << setw(30) << left << city.population
                     << setw(30) << left << city.cost << endl;
                flag = 0;
            }
            else
            {
                cout << setw(30) << left << " ";
                cout << setw(30) << left << city.name
                     << setw(30) << left << city.population
                     << setw(30) << left << city.cost << endl;
            }
        }
        flag = 1;
        cout << setfill('-') << setw(96) << right << " " << endl;
    }
    return 0;
}
