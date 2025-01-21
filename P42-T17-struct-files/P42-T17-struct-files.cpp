#include "Card.h"
#include "ArrayTemplate.h"
//Load 1 or Create 0
#define Load 1

int main()
{

/*
    srand(time(0));
    FILE* file_client = nullptr;

    Card Valeria;
#if Load == 0
    Valeria.createCard();
    Valeria.showCard();
#else
    Valeria.showCard();

   // fopen_s(&file_client, "bank.txt", "r");
    fopen_s(&file_client, "bank.bin", "rb");
    if (file_client != nullptr)
        //Valeria.loadFromTextFile(file_client);
        Valeria.loadFromBinFile(file_client);
    fclose(file_client);

    Valeria.showCard();
#endif // Load == 0
//---------------------------------------------------------

    Valeria.cash += 2000.99;

    //fopen_s(&file_client, "bank.txt", "w");
    fopen_s(&file_client, "bank.bin", "wb");
    if (file_client != nullptr)
        // Valeria.saveToTextFile(file_client);
        Valeria.saveToBinFile(file_client);
    fclose(file_client);

   */
    FILE* file_bank = nullptr;

    int sizeOfCards = 0;        //Кількість карток - Розмір масиву
    Card* arrCards = nullptr;   //Масив карток

    //------------------------------------------------
    //Load or Create
#if Load == 0 //Create array
    sizeOfCards = 4;
    arrCards = new Card[4]{
        {"Golovina Valeria", 1234567, 1000},
        {"Kuznetsov Oleksiy", 987654, 900.99},
        {"Nikitenko Maksym", 5679876, 1500.5},
        {"Zymbal Mykhailo", 1672830, 1200.99}
    };
#else //Load array
    //Вивантаження данних із файлу
    fopen_s(&file_bank, "bank_arr.bin", "rb"); //!!!!!!!!!!!!!
    if (file_bank == nullptr) cout << "Error: not loaded\n";
    else {
        fread(&sizeOfCards, sizeof(int), 1, file_bank);
        arrCards = new Card[sizeOfCards];
        for (int i = 0; i < sizeOfCards; i++)
        {
            arrCards[i].loadFromBinFile(file_bank);
        }
        fclose(file_bank);
        cout << "Loaded\n";
    }
#endif

   //------------------------------------------------
   // Menu system

    int menu = 0;
    Card tmp;
    while (true) {
        cout << "---------------------------\n";
        cout << "\t\tMENU: \n";
        cout << "\t 1. Show all cards\n";
        cout << "\t 2. Add a new card\n";
        cout << "---------------------------\n";
        cout << "\t 0. Save and Exit\n";
        cout << "---------------------------\n";
        cin >> menu;

        if (menu == 0) {
            cout << "Have a nice day! =)\n"; break;
        }
        switch (menu)
        {
        case 1: for (int i = 0; i < sizeOfCards; i++)
                {
                     arrCards[i].showCard();
                }
              break;
        case 2: //???????????????
            cin.ignore();
            tmp.createCard();
            addItemBack(arrCards, sizeOfCards, tmp);
            cout << "Added!\n";
            break;
        default:
            break;
        }

    }




    //------------------------------------------------
    //Save arr
    fopen_s(&file_bank, "bank_arr.bin", "wb");
    if (file_bank == nullptr) cout << "Error: not saved\n";
    else {
        fwrite(&sizeOfCards, sizeof(int), 1, file_bank);
        for (int i = 0; i < sizeOfCards; i++)
        {
            arrCards[i].saveToBinFile(file_bank);
        }
        fclose(file_bank);
        cout << "Saved =)\n";
    }
}
