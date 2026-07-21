#include<iostream>
using namespace std;
void input(char sentence[], char key[]);
void sequence(char sentence[], char key[], char words_sequence[]);
void encrypt(char sentence[], char words_sequence[], char encrypted[]);
void decrypt(char sentence[], char words_sequence[], char encrypted[]);
void display(char[]);
int main()
{
    int choice = 0;
    do
    {
        do
        {
            cout << "======Vigenere Cipher======" << endl;
            cout << "===========Menu============" << endl;
            cout << "1. Encrypt" << endl;
            cout << "2. Decrypt" << endl;
            cout << "3. Exit" << endl;
            cout << "======Vigenere Cipher======" << endl;
            cout << "Enter Choice: ";
            cin >> choice;
        } while (!(choice >= 1 && choice <= 3));
        switch (choice)
        {
        case 1:
        {
            char sentence[100], key[100], words_sequence[100], encrypted[100];
            input(sentence, key);
            sequence(sentence, key, words_sequence);
            encrypt(sentence, words_sequence, encrypted);
            cout << "Encrypted Text = ";
            display(encrypted);
            cout << endl;
            break;
        }
        case 2:
        {
            char sentence[100], key[100], words_sequence[100], decrypted[100];
            input(sentence, key);
            sequence(sentence, key, words_sequence);
            decrypt(sentence, words_sequence, decrypted);
            cout << "Decrypted Text = ";
            display(decrypted);
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Exited the Program!" << endl;
            break;
        }
        }
    } while (choice != 3);
    return 0;
}
void input(char sentence[], char key[])
{
    cin.ignore();
    cout << "Enter sentence: ";
    cin.getline(sentence, 100);
    cout << "Enter key: ";
    cin.getline(key, 100);
}
void sequence(char sentence[], char key[], char words_sequence[])
{
    int length = 0;
    while (key[length] != 0)
    {
        length++;
    }
    int a = 0;
    while (sentence[a] != '\0')
    {
        words_sequence[a] = key[a % length];
        a++;
    }
    words_sequence[a] = '\0';
}
void encrypt(char sentence[], char words_sequence[], char encrypted[])
{
    int index = 0;
    while (sentence[index] != '\0')
    {
        if (sentence[index] >= 'A' && sentence[index] <= 'Z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                encrypted[index] = (((sentence[index] - 'A') + (words_sequence[index] - 'A')) % 26) + 'A';
            }
            else if (words_sequence[index] >= 'a' && words_sequence[index] <= 'z')
            {
                encrypted[index] = (((sentence[index] - 'A') + (words_sequence[index] - 'a')) % 26) + 'a';
            }
        }
        else if (sentence[index] >= 'a' && sentence[index] <= 'z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                encrypted[index] = (((sentence[index] - 'a') + (words_sequence[index] - 'A')) % 26) + 'A';
            }
            else if (words_sequence[index] >= 'a' && words_sequence[index] <= 'z')
            {
                encrypted[index] = (((sentence[index] - 'a') + (words_sequence[index] - 'a')) % 26) + 'a';
            }
        }
        else
        {
            encrypted[index] = sentence[index];
        }
        index++;
    }
    encrypted[index] = '\0';
}
void decrypt(char sentence[], char words_sequence[], char decrypted[])
{
    int index = 0;
    while (sentence[index] != '\0')
    {
        if (sentence[index] >= 'A' && sentence[index] <= 'Z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                decrypted[index] = (((sentence[index] - 'A') - (words_sequence[index] - 'A') + 26) % 26) + 'A';
            }
            else if (words_sequence[index] >= 'a' && words_sequence[index] <= 'z')
            {
                decrypted[index] = (((sentence[index] - 'A') - (words_sequence[index] - 'a') + 26) % 26) + 'a';
            }
        }
        else if (sentence[index] >= 'a' && sentence[index] <= 'z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                decrypted[index] = (((sentence[index] - 'a') - (words_sequence[index] - 'A') + 26) % 26) + 'A';
            }
            else if (words_sequence[index] >= 'a' && words_sequence[index] <= 'z')
            {
                decrypted[index] = (((sentence[index] - 'a') - (words_sequence[index] - 'a') + 26) % 26) + 'a';
            }
        }
        else
        {
            decrypted[index] = sentence[index];
        }
        index++;
    }
    decrypted[index] = '\0';
}
void display(char result[])
{
    for (int d = 0; result[d] != '\0'; d++)
    {
        cout << result[d];
    }
    cout << endl;
}