#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <set>
#include <string>
#include <fstream>
using namespace std;

class OpeningFile
{
public:
    void error(void) const { cout << "Can't open file.\n"; };
};

void display(const map<string, int> &m)
{
    ofstream out_file("../output.txt");
    out_file << "Part1 =======================================\n";
    out_file << setw(15) << left << "Word"
         << setw(15) << right << "Occurrence" << endl;
    out_file << setw(33) << setfill('=') << " " << endl;
    out_file << setfill(' ');
    for (auto const &elem : m)
    {
        out_file << setw(15) << left << elem.first
             << setw(15) << right << elem.second << endl;
    }
}

void display_map_set(const map<string, set<int>> &m){
    ofstream out_file("../output.txt",ios::app);
    out_file << "Part2 =======================================\n";
    out_file << setw(15) << left << "Word"
         << setw(15) << right << "Occurrence" << endl;
    out_file << setw(33) << setfill('=') << " " << endl;
    out_file << setfill(' ');
    for(auto const &elem : m){
        out_file << setw(15) << left << elem.first 
        << setw(15) << right << "[ ";
        for(auto const &sec_elem : elem.second){
            out_file << sec_elem << " "; 
        }
        out_file << "]" << endl;
    }
}

string clear_string(const string &str)
{
    string newstr;
    for (char ch : str)
    {
        if (isalpha(ch))
        {
            newstr += ch;
        }
    }
    return newstr;
}

void part1(void)
{
    map<string, int> my_map;
    ifstream in_file("../words.txt");
    if (!in_file)
    {
        throw OpeningFile();
    }

    cout << "File 1 opened successfully.\n";
    string line;
    string word;
    while (getline(in_file, line))
    { // Read from in_file
        stringstream ss(line);
        while (ss >> word)
        { // Read each word in the line
            word = clear_string(word);
            my_map[word]++;
        }
    }

    display(my_map);

    in_file.close();
}

void part2(void)
{
    map<string, set<int>> m;
    ifstream in_file{"../words.txt"};
    if (!in_file)
    {
        throw OpeningFile();
    }
    cout << "File 1 opened successfully.\n";
    string word, line;
    int line_counter = 0;
    while (getline(in_file, line))
    {
        line_counter++;
        stringstream ss{line};
        while(ss >> word){
            word = clear_string(word);
            m[word].insert(line_counter);
        }
    }
    display_map_set(m);
}

int main()
{
    map<string, int> m{{"frank", 0}};

    try
    {
        part1();
        part2();
    }
    catch (const OpeningFile &ex)
    {
        ex.error();
    }

    return 0;
}