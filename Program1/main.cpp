#include "GameOfThrones.h"
using namespace std;

int main() {
    // Part 1: Character and Dragon data
    TwoDArray<string> charactersAndDragons(10, 10); // Fixed array size assumption
    char choice;
    int characterIndex = 0;

    cout << "Character & Dragon data entry:\n";
    while (characterIndex < 10) {
        cout << "Would you like to enter a character? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear newline character from the input buffer

        if (choice == 'n' || choice == 'N') break;

        string characterName;
        cout << "Enter the character name: ";
        getline(cin, characterName);
        charactersAndDragons.set(characterIndex, 0, characterName);

        int numDragons = 0;
        cout << "How many dragons would you like to enter for the character? ";
        cin >> numDragons;
        cin.ignore();  // Clear newline character from the input buffer

        int j = 1;
        while (j <= numDragons && j < 10) {
            string dragonName;
            cout << "Enter the name of dragon " << j << ": ";
            getline(cin, dragonName);
            charactersAndDragons.set(characterIndex, j, dragonName);
            j++;
        }

        characterIndex++;
    }

    cout << "\nCharacter and Dragon data entry:\n";
    charactersAndDragons.display();

    // Part 2: Kingdoms and Army Sizes data
    ParallelVectors<string> kingdomsAndArmies;

    cout << "\nKingdoms and Army Data:\n";
    while (true) {
        cout << "Would you like to enter a kingdom? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear newline character from the input buffer

        if (choice == 'n' || choice == 'N') break;

        string kingdomName;
        int armySize;

        cout << "Enter the kingdom name: ";
        getline(cin, kingdomName);

        cout << "Enter the size of the army: ";
        cin >> armySize;
        cin.ignore();  // Clear newline character from the input buffer

        kingdomsAndArmies.add(kingdomName, armySize);
    }

    cout << "\nKingdoms and Army Sizes:\n";
    kingdomsAndArmies.display();

    return 0;
}
