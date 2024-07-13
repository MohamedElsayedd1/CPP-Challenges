#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void print_header(int s){
    cout << setw(20) << left << "Student" << "Score" << "[" << s << "]" << endl;
    cout << setw(30) << right  << setfill('-')<< "" << endl;
    cout << setfill(' ');
}

int main()
{
    ifstream in_responses;
    int size;
    string answer;
    vector<string> names;
    vector<int> degrees;
    string temp_answer{};
    int temp_degree = 0;
    bool flag = true;
    double avg = 0;
    int students_number = 0;

    in_responses.open("../responses.txt");
    if(!in_responses){
        cout << "Error !! can't open file.\n";
        return 0;
    }
    cout << "\nFile opened successfully.\n\n";

    getline(in_responses, answer);

    size = answer.size();

    while(getline(in_responses, temp_answer)){
        if(flag == true){
            names.push_back(temp_answer);
            flag = false;
            students_number++;
        }
        else{
            for(int i = 0; i < size; i++){
                if(answer[i] == temp_answer[i]){
                    temp_degree++;
                }
                else{
                    // do nothing
                }
            }
            degrees.push_back(temp_degree);
            flag = true;
            temp_degree = 0;
        }
    }

    in_responses.close();

    print_header(size);

    for(int i = 0; i < students_number; i++){
        cout << setw(23) << left << names[i] << degrees[i] << endl;
    }

    cout << setw(30) << right  << setfill('-')<< "" << endl;
    cout << setfill(' ');

    for(auto &x : degrees){
        avg += x;
    }

    avg /= size;

    cout << setw(23) << left << "Average" << avg << endl;

    return 0;
}
