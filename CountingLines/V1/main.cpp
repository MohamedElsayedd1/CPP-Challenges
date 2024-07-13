#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream in_file {"../poem.txt", ios::in};
    ofstream out_file {"../output.txt", ios::out};
    string line{};

    int line_counter = 1;
    if(!in_file){
        cout << "Can't find input file\n";
        return 0;
    }
    if(!out_file){
        cout << "Can't create output file\n";
        return 0;
    }
    while(getline(in_file, line)){
        out_file << setw(8) << left << line_counter++;
        out_file << line << endl;
    }
    cout << "Input file has been copied to output file successfully.\n";
    return 0;
}