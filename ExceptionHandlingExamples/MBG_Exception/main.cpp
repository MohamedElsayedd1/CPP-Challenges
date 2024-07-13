#include <iostream>
using namespace std;

int main()
{
    int miles; 
    int gallons;
    double miles_per_gallons;
    cout << "--------- miles per gallons ------\n";
    cout << "Enter number of miles : ";
    cin >> miles;
    cout << "Enter number of gallons : ";
    cin >> gallons;
    // miles_per_gallons = miles/gallons; // program craches if gallons = 0
    try {
        if (gallons == 0)
            throw gallons;
        miles_per_gallons = (double)miles/gallons; // results +-inf if gallons = 0
        cout << "Miles per gallons : " << miles_per_gallons << endl;
    }
    catch(int &exp){
        cerr << "Sorry, can't devide by zero.\n";
    }
    return 0;
}