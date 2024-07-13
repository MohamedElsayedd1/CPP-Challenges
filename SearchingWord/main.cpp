#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in_poem;
    string word;
    string myword;
    string line;
    int counter = 0;
    int words_number = 0;
    in_poem.open("../poem.txt");
    if(!in_poem){
        cout << "\nCan't open file\n";
        return 0;
    }
    cout << "\nFile opened successfully.\n\n";

    cout << "Enter a word to find : ";
    cin >> word;

    while(in_poem >> myword){
        words_number++;       
        if(myword.find(word) != string::npos){
            counter++;
        }
    }

    

    cout << words_number << " words were searched...\n";
    cout << word << " was found " << counter << " times.\n";
    return 0;
}