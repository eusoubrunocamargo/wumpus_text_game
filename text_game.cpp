#include <iostream>
#include <string>
using namespace std;

int main()
{

    int position = 33;
    int goldPosition = 44;
    int monsterPosition = 41;
    int option;
    string alert;
    string goldAlert, monsterAlert;
    bool showAlert;

    cout << "WUMPUS ADVENTURE!\n";
    cout << "You're in the middle of a 5x5 table, so your initial position is 33. Your goal is to find the gold, avoiding the monster. You can request SENSOR to give you an alert if there's a monster in adjacences. Let's begin!\n";

    for (int i = 0;; i++)
    {

        if (position == goldPosition)
        {
            cout << "Parabéns! Você encontrou o ouro!" << endl;
            return 0;
        }

        if (position == monsterPosition)
        {
            cout << "Que pena! Você morreu ..." << endl;
            return 0;
        }

        showAlert &&cout << alert << endl;
        cout << "--> Sua posição é: " << position << "\n\n";

        showAlert = false;
        alert = "";

        cout << "Escolha uma opção:\n";

        cout << "1. Go right\n";
        cout << "2. Go left\n";
        cout << "3. Go up\n";
        cout << "4. Go down\n";
        cout << "5. Read SENSOR\n";

        cin >> option;

        if (option == 1)
        {
            if (position % 5 == 0)
            {
                // cout << "Há um muro aqui!\n";
                showAlert = true;
                alert = "--> Há um muro aqui!";
            }
            else
            {
                position += 1;
            }
        }
        else if (option == 2)
        {
            if (position == 11 || position == 21 || position == 31 || position == 41 || position == 51)
            {
                showAlert = true;
                alert = "--> Há um muro aqui!";
            }
            else
            {
                position -= 1;
            }
        }
        else if (option == 3)
        {
            if (position > 50)
            {
                showAlert = true;
                alert = "--> Há um muro aqui!";
            }
            else
            {
                position += 10;
            }
        }
        else if (option == 4)
        {
            if (position >= 11 && position <= 15)
            {
                showAlert = true;
                alert = "--> Há um muro aqui!";
            }
            else
            {
                position -= 10;
            }
        }
        else if (option == 5)
        {
            cout << "<---------------------------------->\n";
            cout << "Sua posição é " << position << "\n";
            cout << "Informações sobre o ouro: ";
            if (goldPosition == position + 10 || goldPosition == position - 10 || goldPosition == position - 1 || goldPosition == position + 1)
            {
                cout << "O ouro está próximo!\n";
            }
            else
            {
                cout << "Nada no sensor...\n";
            }
            cout << "Sensor de perigo: ";
            if (monsterPosition == position + 10 || monsterPosition == position - 10 || monsterPosition == position - 1 || monsterPosition == position + 1)
            {
                cout << "Cuidado! O monstro está à espreita...\n";
            }
            else
            {
                cout << "Nada no sensor...\n";
            }
            cout << "<---------------------------------->\n";
        }
        else
        {
            cout << "Opção inválida!\n";
        }
        cout << "\n\n";
    }
}