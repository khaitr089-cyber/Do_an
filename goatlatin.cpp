#include <iostream>
#include <sstream>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

string toGoatLatin(string sentence) {

    stringstream ss(sentence);
    string word, result;
    int index = 1;

    while(ss >> word) {

        if(isVowel(word[0])) {
            word += "ma";
        }
        else {
            word = word.substr(1) + word[0] + "ma";
        }

        word += string(index, 'a');

        if(result != "") result += " ";
        result += word;

        index++;
    }

    return result;
}

int main() {

    string sentence = "I speak Goat Latin";

    cout << toGoatLatin(sentence);

    return 0;
}
