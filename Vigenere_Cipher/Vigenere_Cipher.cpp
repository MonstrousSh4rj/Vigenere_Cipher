#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
void input(char sentence[], char key[]);
void sequence(char sentence[], char key[], char words_sequence[]);
void encrypt(char sentence[], char words_sequence[], char encrypted[]);
void decrypt(char sentence[], char words_sequence[], char encrypted[]);
void encrypt_file();
void sequence_file(char key_sequence_file[], string line, string keystring, int& index_sequence);
void encrypt_line_file(string line, char key_sequence_line[], int &index_encrypt, char encrypted[] );
void decrypt_file();
void decrypt_line_file(string line, char key_sequence_line[], int& index_decrypt, char decrypted[]);
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
            cout << "3. Ecrypt a File" << endl;
            cout << "4. Decrypt a File" << endl;
            cout << "5. Exit" << endl;
            cout << "======Vigenere Cipher======" << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            if ((choice < 1 || choice > 5) || cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid choice! Try again." << endl;
            }
        } while (!(choice >= 1 && choice <= 5));
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
            encrypt_file();
            break;
        }
        case 4:
        {
            decrypt_file();
            break;
        }
        case 5:
        {
            cout << "Exited the Program!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice :(";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}
void input(char sentence[], char key[])
{
    cin.ignore();
    Sentence:
    cout << "Enter sentence: ";
    cin.getline(sentence, 100);
    for (int a = 0; sentence[a] != '\0'; a++)
    {
        if (!((sentence[a] >= 'A' && sentence[a] <= 'Z') || (sentence[a] >= 'a' && sentence[a] <= 'z')))
        {
            cout << "No special Characters!" << endl;
            goto Sentence;
        }
    }
    Key:
    cout << "Enter Key: ";
    cin.getline(key, 100);
    for (int a = 0; key[a] != '\0'; a++)
    {
        if (!((key[a] >= 'A' && key[a] <= 'Z') || (key[a] >= 'a' && key[a] <= 'z')))
        {
            cout << "No special Characters!" << endl;
            goto Key;
        }
    }
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
                encrypted[index] = (((sentence[index] - 'A') + (words_sequence[index] - 'a')) % 26) + 'A';
            }
        }
        else if (sentence[index] >= 'a' && sentence[index] <= 'z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                encrypted[index] = (((sentence[index] - 'a') + (words_sequence[index] - 'A')) % 26) + 'a';
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
                decrypted[index] = (((sentence[index] - 'A') - (words_sequence[index] - 'a') + 26) % 26) + 'A';
            }
        }
        else if (sentence[index] >= 'a' && sentence[index] <= 'z')
        {
            if (words_sequence[index] >= 'A' && words_sequence[index] <= 'Z')
            {
                decrypted[index] = (((sentence[index] - 'a') - (words_sequence[index] - 'A') + 26) % 26) + 'a';
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
void encrypt_file()
{
    string i_file, o_file, keystring;
    cout << "Enter input file: ";
    cin.ignore();
    getline(cin, i_file);
    cout << "Enter output file: ";
    getline(cin, o_file);
    Keystring:
    cout << "Enter Key: ";
    getline(cin, keystring);
    int limit = keystring.length();
    for (int a = 0; a<limit; a++)
    {
        if (!((keystring[a] >= 'A' && keystring[a] <= 'Z') || (keystring[a] >= 'a' && keystring[a] <= 'z')))
        {
            cout << "No special Characters!" << endl;
            goto Keystring;
        }
    }
    ifstream infile(i_file);
    string line;
    char key_sequence_file[1000];
    int index_sequence = 0;
    while (getline(infile, line))
    {
        sequence_file(key_sequence_file, line, keystring, index_sequence);
    }
    infile.close();
    ifstream infile_1(i_file);
    ofstream outfile(o_file);
    int index_encrypt = 0;
    char encrypted[1000];
    while (getline(infile_1, line))
    {
        encrypt_line_file(line, key_sequence_file, index_encrypt, encrypted);
        outfile << encrypted << endl;
    }
    infile.close();
    outfile.close();
    cout << "Encrypted contents saved to " << o_file << endl;
}
void sequence_file(char key_sequence_file[], string line, string keystring, int& index_sequence)
{
    int length = 0;
    length = keystring.length();
    int a = 0, line_length = 0;
    line_length = line.length();
    while (a != line_length)
    {
        if (line[a] != ' ')
        {
            key_sequence_file[index_sequence] = keystring[a % length];
            a++;
            index_sequence++;
        }
        else
        {
            key_sequence_file[index_sequence] = ' ';
            a++;
            index_sequence++;
        }
    }
    key_sequence_file[index_sequence] = '\0';
}
void encrypt_line_file(string line, char key_sequence_line[], int &index_encrypt, char encrypted[])
{
    int index = 0;
    int length_line = line.length();
    while (index < length_line)
    {
        if (line[index] >= 'A' && line[index] <= 'Z')
        {
            if (key_sequence_line[index_encrypt] >= 'A' && key_sequence_line[index_encrypt] <= 'Z')
            {
                encrypted[index] = (((line[index] - 'A') + (key_sequence_line[index_encrypt] - 'A')) % 26) + 'A';
            }
            else if (key_sequence_line[index_encrypt] >= 'a' && key_sequence_line[index_encrypt] <= 'z')
            {
                encrypted[index] = (((line[index] - 'A') + (key_sequence_line[index_encrypt] - 'a')) % 26) + 'A';
            }
        }
        else if (line[index] >= 'a' && line[index] <= 'z')
        {
            if (key_sequence_line[index_encrypt] >= 'A' && key_sequence_line[index_encrypt] <= 'Z')
            {
                encrypted[index] = (((line[index] - 'a') + (key_sequence_line[index_encrypt] - 'A')) % 26) + 'a';
            }
            else if (key_sequence_line[index_encrypt] >= 'a' && key_sequence_line[index_encrypt] <= 'z')
            {
                encrypted[index] = (((line[index] - 'a') + (key_sequence_line[index_encrypt] - 'a')) % 26) + 'a';
            }
        }
        else
        {
            encrypted[index] = line[index];
        }
        index++;
        index_encrypt++;
    }
    encrypted[index] = '\0';
}
void decrypt_file()
{
    string i_file, o_file, keystring;
    cout << "Enter input file: ";
    cin.ignore();
    getline(cin, i_file);
    cout << "Enter output file: ";
    getline(cin, o_file);
    cout << "Enter key: ";
    getline(cin, keystring);
    ifstream infile(i_file);
    string line;
    char key_sequence_file[1000];
    int index_sequence = 0;
    while (getline(infile, line))
    {
        sequence_file(key_sequence_file, line, keystring, index_sequence);
    }
    infile.close();
    ifstream infile_1(i_file);
    ofstream outfile(o_file);
    int index_encrypt = 0;
    char decrypted[1000];
    while (getline(infile_1, line))
    {
        decrypt_line_file(line, key_sequence_file, index_encrypt, decrypted);
        outfile << decrypted << endl;
    }
    infile.close();
    outfile.close();
    cout << "Decrypted contents saved to " << o_file << endl;
}
void decrypt_line_file(string line, char key_sequence_line[], int& index_decrypt, char decrypted[])
{
    int index = 0;
    int length_line = line.length();
    while (index < length_line)
    {
        if (line[index] >= 'A' && line[index] <= 'Z')
        {
            if (key_sequence_line[index_decrypt] >= 'A' && key_sequence_line[index_decrypt] <= 'Z')
            {
                decrypted[index] = (((line[index] - 'A') - (key_sequence_line[index_decrypt] - 'A') + 26) % 26) + 'A';
            }
            else if (key_sequence_line[index_decrypt] >= 'a' && key_sequence_line[index_decrypt] <= 'z')
            {
                decrypted[index] = (((line[index] - 'A') - (key_sequence_line[index_decrypt] - 'a') + 26) % 26) + 'A';
            }
        }
        else if (line[index] >= 'a' && line[index] <= 'z')
        {
            if (key_sequence_line[index_decrypt] >= 'A' && key_sequence_line[index_decrypt] <= 'Z')
            {
                decrypted[index] = (((line[index] - 'a') - (key_sequence_line[index_decrypt] - 'A') + 26) % 26) + 'a';
            }
            else if (key_sequence_line[index_decrypt] >= 'a' && key_sequence_line[index_decrypt] <= 'z')
            {
                decrypted[index] = (((line[index] - 'a') - (key_sequence_line[index_decrypt] - 'a') + 26) % 26) + 'a';
            }
        }
        else
        {
            decrypted[index] = line[index];
        }
        index++;
        index_decrypt++;
    }
    decrypted[index] = '\0';
}