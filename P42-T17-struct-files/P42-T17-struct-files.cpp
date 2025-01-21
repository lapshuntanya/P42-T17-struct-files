#include "Card.h"
#define Load 1

int main()
{
    srand(time(0));
    FILE* file_client = nullptr;

    Card Valeria;
#if Load == 0
    Valeria.createCard();
    Valeria.showCard();
#else
    Valeria.showCard();

    fopen_s(&file_client, "bank.txt", "r");
    if (file_client != nullptr)
        Valeria.loadFromTextFile(file_client);
    fclose(file_client);

    Valeria.showCard();
#endif // Load == 0
//---------------------------------------------------------

    Valeria.cash += 2000.99;

    fopen_s(&file_client, "bank.txt", "w");
    if (file_client != nullptr)
        Valeria.saveToTextFile(file_client);
    fclose(file_client);

}
