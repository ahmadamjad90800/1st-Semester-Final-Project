#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <windows.h>
void PrintHangman(int numberOfGuesses);
bool checkWin(char actualWord[], int length, char word[], int wordlenght);
bool ValidLetter(char guess, char repeatingWord[], int size);

using namespace std;
int main()
{
    string CountryNames[25] = 
    {
        "CHINA", "QATAR", "PAKISTAN", "OMAN", "AMERICA", 
        "GERMANY", "LUXEMBOURG", "ALBUQUERQUE", "JOHANNESBURG", "AFGHANISTAN", 
        "NETHERLANDS", "CANADA", "AUSTRALIA", "SWITZERLAND", "ENGLAND",
        "BEIJING", "DOHA", "ISLAMABAD", "MUSCAT", "AUSTIN", 
        "BERLIN", "LUXEMBOURG", "ALBUQUERQUE", "JOHANNESBURG",
        "KABUL"
    };
    int numberOfGuesses = 11, i = 0, j = 0;
    char guess;
    bool IsWin;
    int length = 0, k = 0;

    srand(time(0));
    int num = rand() % 25;  //select a random word

    while (CountryNames[num][k] != '\0')   //Calculating the length of the word
    {
        length++;
        k++;
    }
    char word[length];
    char actualWord[length];
    int a = 0, size = 50;
    char repeatingWord[size];

    cout<<endl;
    cout<<"Hang The Man"<<endl;
    cout<<endl;
    cout<<"I have thought of a country/city of the wide world. Can you guess it?"<<endl; 
    cout<<endl;

    cout<<"Rules:"<<endl;
    cout<<endl;
    cout<<"1.You have maximum of 11 chances to make a mistake."<<endl;
    cout<<endl;
    cout<<"2.Do not enter same letter twice."<<endl;
    cout<<endl;
    cout<<"3.Good Luck and do not hang the man! :)"<<endl;
    cout<<endl;

    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;


    for (int i = 0; i < length; i++)   //Remove garbage values
    {
        actualWord[i] = '_';
    }
    for (int i = 0; i < length; i++)    //Printing number of dashes equal to the length of the word
    {
        cout<<"_"<<"  ";
    }

    for (int i = 0; i < length; i++)    //Removing garbage values
    {
        repeatingWord[i] = '0';
    }


    cout<<endl;
    cout<<endl;

    while (CountryNames[num][j] != '\0')    //Copying the string into the array of chars
    {
        word[i] = CountryNames[num][j];
        i++;
        j++;
    }


    cout<<endl;
    do
    { 
        cout<<"\n";
        cout<<"\n";
        cout<<"Enter a letter: ";     //Ask user for a guess
        cin>>guess;
        int ifnotAlpha = isalpha(guess); //Checks if the entered letter is a letter or not
        if (ifnotAlpha == 0)
        {
            cout<<"Choose a letter!"<<endl;
        }
        if (guess >= 'a' || guess <= 'z')
        {
            guess = toupper(guess);
        }
        bool checkLetter = ValidLetter(guess, repeatingWord, size);  //Checking if user enters a letter more than once
        if (checkLetter == true)    
        {
            cout<<"You cannot enter the same letter!"<<endl;
            Beep(350, 50);
        }
        repeatingWord[a] = guess;
        a++;



        for (int i = 0; i < length; i++)    
        {
            if (word[i] == guess)   //Compare the guess
            {
                actualWord[i] = word[i];
            }
        }
    

        IsWin = checkWin(actualWord, length, word, length);   //Check if user wins

        if (IsWin == true)
        {
            Sleep(500);
            system("cls");
            cout<<endl;
            cout<<"Congralutions! You win!"<<endl;
            cout<<"The word was: ";
            for (int i = 0; i < length; i++)
            {
                cout<<word[i];
            }
            cout<<endl;
            cout<<"Thank you for saving me!"<<endl;
            cout<< "   +---+\n"
                << "   |   |\n"
                <<"       |\n"
                << "  \\O/  |\n"
                << "   |   |\n"
                << "  / \\  |\n"
                << "=========\n";
               
            break;
        }


        bool correctWord = false;
        for (int i = 0; i < length; i++)   //Check is entered word is correct or wrong
        {
            if (guess == word[i])
            {
                correctWord = true;
                break;
            }
        }

        if (!correctWord && checkLetter == false &&  ifnotAlpha != 0)   //If entered word is wrong then print the hangman and reduce number of mistakes  by 1
        {
            cout<<"Wrong Guess!\n";
            Beep(500, 500);
            numberOfGuesses--;
        }
    
        /* clear the system state
            but wait  before clearing everything.
        */
        Sleep(500);
        system("cls");
        /*
            print system summary before proceeding.
        */
        cout<<"=================";
        cout<<endl;
        cout<<"Mistakes left: "<<numberOfGuesses<<endl;
        cout<<"================="<<endl;
        cout<<endl;

        cout << "The Current State of the Game: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout<<actualWord[i]<<"  ";
        }
        cout << endl << endl;
        cout << "-- Hangman -- " << endl;
        PrintHangman(numberOfGuesses);

    }while (IsWin != true && numberOfGuesses != 0);



    if (numberOfGuesses == 0)      //If user loses
    {
        cout<<"You lost!!"<<endl;
        cout<<"Better luck next time"<<endl;
        cout<<"The word was: ";
    
    for (int i  = 0; i < length; i++)
    {
        cout<<word[i];
    }
    }
}

void PrintHangman(int numberOfGuesses)
{
    switch (numberOfGuesses) 
    {
        case 11:
                 cout << "       \n"
                      << "        \n"
                      << "        \n"
                      << "        \n"
                      << "        \n"
                      << "        \n"
                      << "=========\n";
            break;
        case 10:
                 cout << "        \n"
                      << "        \n"
                      << "        \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "=========\n";
            break;
        case 9:
                 cout << "        \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "=========\n";
            break;
        case 8:
                 cout << "    --+ \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "      | \n"
                      << "=========\n";
            break;
        case 7:
                 cout << "  +---+\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 6:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 5:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 4:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /    |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 3:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|   |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 2:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << "      |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 1:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << " /    |\n"
                      << "      |\n"
                      << "=========\n";
            break;
        case 0:
                 cout << "  +---+\n"
                      << "  |   |\n"
                      << "  O   |\n"
                      << " /|\\  |\n"
                      << " / \\  |\n"
                      << "      |\n"
                      << "=========\n";
            break;
    }
}


bool checkWin(char actualWord[], int length, char word[], int wordlenght)
{
    for (int i = 0; i < wordlenght; i++)
    {
        if (actualWord[i] != word[i])
        {
            return false;
        }
    }
    return true;
}

bool ValidLetter(char guess, char repeatingWord[], int size)
{

    for (int i = 0; i < size; i++)
    {
        if (repeatingWord[i] == guess)
        {
            return true;
        }
    }
    return false;
}