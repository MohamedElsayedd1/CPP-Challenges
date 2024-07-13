#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGIJKLMNOPQRSTUVWXYZ"};
    string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    string recieved_msg;
    char encrypted_msg[100];
    char decrypted_msg[100];
    cout << "Enter your secret message : ";
    getline(cin, recieved_msg);
    for (size_t i = 0; i < recieved_msg.length(); i++)
    {
        encrypted_msg[i] = recieved_msg[i];
        for (size_t j = 0; j < alphabet.length(); j++)
        {
            if (recieved_msg[i] == alphabet[j])
            {
                encrypted_msg[i] = key[j];
            }
            else{

            }
        }
        encrypted_msg[i+1] = '\0';
    }

        cout << endl;
        cout << "Encrypting message ..." << endl << endl;
        cout << "Encrypted Message : " << encrypted_msg << endl << endl;
    
        for (size_t i = 0; i < strlen(encrypted_msg); i++)
        {
            decrypted_msg[i] = encrypted_msg[i];
            for(size_t j = 0; j < key.length(); j++){
                if(encrypted_msg[i] == key[j]){
                    decrypted_msg[i] = alphabet[j];
                }
                else{

                }
            }
            decrypted_msg[i + 1] = '\0';
        }

        cout << endl;
        cout << "Decrypting message ..." << endl << endl;
        cout << "Encrypted Message : " << decrypted_msg << endl << endl;
}
