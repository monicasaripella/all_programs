
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int processGuess(char* word, const char* targetWord);


const char *wordBank[] = {"computer","president","trojan","program","coffee",
    "library","football","popcorn","science","engineer"};

const int numWords = 10;

int main()
{
    srand(time(0));
 
    const char* targetWord = wordBank[rand()%10];
    int lengthWord = (int)strlen(targetWord);
    char word[lengthWord];
    word[lengthWord] ='\0';
    for (int k=0;k<lengthWord;k++)
    { word[k]='*';
    }

    cout << word[lengthWord];
    processGuess(word, targetWord);

    
    return 0;
}

int processGuess(char* word, const char* targetWord)
{
    char guess;
    int attempts=0;

    cout << word <<endl;
    while (attempts<10){
        cout << "Guess a letter\n";
        cin >> guess;
        int counter=0;
        
        for (int j=0;j<=(int) strlen(targetWord);j++){
            if (targetWord[j]==guess){
                word[j]=guess;
                counter++;
                
            }
            
        }
        if (counter==0)
        { attempts++;}
		cout << word << endl;
        cout << "You have " << 10-attempts << " guesses remaining"<<endl;
        
        if (10-attempts==0)
        {cout << "You have lost" << endl;
            break;
        }
        
        
        else  if (!strcmp(word, targetWord)){
            cout << "User has won" << endl;
            break;
        }
        
    }
    return attempts;
    
    
    
    
    
    
}
