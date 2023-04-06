#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    // zdefiniuj zmienne
    int dlugosc, zlozonosc;
    string haslo = "";

    // zainicjuj generator liczb pseudolosowych
    srand(time(0));

    // pobierz dane od użytkownika
    cout << "Podaj dlugosc hasla: ";
    cin >> dlugosc;

    cout << "Podaj zlozonosc hasla (1-3): ";
    cin >> zlozonosc;

    // wygeneruj haslo
    for (int i = 0; i < dlugosc; i++) {
        switch (zlozonosc) {
            case 1:
                // tylko cyfry
                haslo += to_string(rand() % 10);
                break;
            case 2:
                // cyfry i litery
                if (rand() % 2 == 0) {
                    haslo += to_string(rand() % 10);
                } else {
                    char litera = 'a' + (rand() % 26);
                    haslo += litera;
                }
                break;
            case 3:
                // cyfry, litery i znaki specjalne
                int losowa = rand() % 3;
                if (losowa == 0) {
                    haslo += to_string(rand() % 10);
                } else if (losowa == 1) {
                    char litera = 'a' + (rand() % 26);
                    if (rand() % 2 == 0) {
                        litera = toupper(litera);
                    }
                    haslo += litera;
                } else {
                    string specjalne = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
                    haslo += specjalne[rand() % specjalne.length()];
                }
                break;
            default:
                cout << "Niepoprawna zlozonosc!" << endl;
                return 1;
        }
    }

    // wyświetl hasło
    cout << "Twoje haslo to: " << haslo << endl;

    return 0;
}
