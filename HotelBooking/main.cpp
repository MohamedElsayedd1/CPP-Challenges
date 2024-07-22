// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HotelRoom
{
private:
    int bedrooms;
    int bathrooms;

public:
    HotelRoom(int b, int r) : bedrooms(b), bathrooms{r}
    {
    }
    virtual int get_price()
    {
        return 50 * bedrooms + 100 * bathrooms;
    }
};

class HotelAppertment : public HotelRoom
{
public:
    HotelAppertment(int b, int r) : HotelRoom(b, r)
    {
    }
    int get_price() override
    {
        return HotelRoom::get_price() + 100;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<HotelRoom *> rooms;
    while (n--)
    {
        string type;
        int no_rooms;
        int no_bath;
        cin >> type >> no_rooms >> no_bath;
        if (type == "standard")
        {
            rooms.push_back(new HotelRoom(no_rooms, no_bath));
        }
        else
        {
            rooms.push_back(new HotelAppertment(no_rooms, no_bath));
        }
    }

    int total = 0;
    for (auto room : rooms)
    {
        total += room->get_price();
    }

    cout << total;

    return 0;
}