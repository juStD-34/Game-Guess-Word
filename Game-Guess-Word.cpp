#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const string wordArray[]={
    "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};

const string figrue[]={
    " ------------- \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",

     " ------------- \n"
    " |            | \n"
    " | \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",

    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " | \n"
    " | \n"
    " | \n"
    " ----- \n",

    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " |          | \n"
    " | \n"
    " | \n"
    " ----- \n",

    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " |         /| \n"
    " | \n"
    " | \n"
    " ----- \n",

    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " |         /|\\ \n"
    " | \n"
    " | \n"
    " ----- \n",

    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " |         /|\\ \n"
    " |         / \n"
    " | \n"
    " ----- \n",
    
    " ------------- \n"
    " |          | \n"
    " |          O \n"
    " |         /|\\ \n"
    " |         / \\ \n"
    " | \n"
    " ----- \n",
};

string RandomWord();
char getGuess();
string updateWord(string GuessWord,string secretWord,char guessLetter);
bool checkGuess(string secretWord,char guessLetter);
void renderGuess(string GuessWord,int falseGuessCount);
void guessWord();
string takeAnswer();

int main()
{
    while (takeAnswer() =="yes")
    {
        guessWord();
    }
    return 0;
}

void guessWord()
{
    string secretWord=RandomWord();
    string GuessWord=string(secretWord.length(),'-');
    int falseGuessCount=0;

    do
    {
        renderGuess(GuessWord,falseGuessCount);
        char guessLetter=getGuess();
        if (checkGuess(secretWord,guessLetter)==true)
        {
            GuessWord=updateWord(GuessWord,secretWord,guessLetter);
        }
        else 
        {
            falseGuessCount++;
            cout<<"You are false!!"<<endl;
        }
    } 
    while (falseGuessCount<7 && secretWord!=GuessWord);

    renderGuess(GuessWord,falseGuessCount);
    
    if (falseGuessCount<7) 
        cout<<"Congraduation!You win!"<<endl; 
    else 
        cout<<" You lose! The correct word is "<<secretWord<<endl; 

}

string RandomWord()
{
    srand(time(NULL));
    int randomNum=rand()% 200+1;
    return wordArray[randomNum];
}
char getGuess()
{
    char playerGuess;
    cout<<"Write your guess:(a letter) ";
    cin>>playerGuess;
    return playerGuess; 
}
bool checkGuess(string secretWord,char guessLetter)
{
    bool check1=false;
    for (int i=0;i<secretWord.length();i++)
    {
        if (secretWord[i]==guessLetter)
        {
            check1=true;
            break;
        }
    }
    return check1;
}
string updateWord(string GuessWord,string secretWord,char guessLetter)
{
    for (int i=0;i<secretWord.length();i++)
    {
        if (secretWord[i]==guessLetter)
        {
            GuessWord[i]=secretWord[i];
        }
    }
    return GuessWord;
}

void renderGuess(string GuessWord,int falseGuessCount)
{
    cout<<figrue[falseGuessCount]<<endl;
    cout<<GuessWord<<endl;
    cout<<"Number of wrong guesses "<<falseGuessCount<<endl;
}

string takeAnswer()
{
    cout<<"Do you want to guess a new word? (yes/no)";
    string answer;
    cin>>answer;
    return answer;
}