#include <iostream>

using namespace std;
const int SIZE = 50;

class Book
{
public:
    string author;
    string title;
    string publisher;
    float price;
    int stock;

    Book() {}
    Book(string author, string title, string publisher, float price, int stock)
    {
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->price = price;
        this->stock = stock;
    }
};

class Shop
{
public:
    Book *books[SIZE];

    void entry(Book *newbook)
    {
        // SomeClass* myArray[2];
        //  myArray[0] = new SomeClass();
        //  myArray[1] = NULL;

        // if (myArray[0] != NULL) { // this will be executed }
        // if (myArray[1] != NULL) { // this will NOT be executed }
        // DON'T FORGET TO ADD SUCCESS MESSAGE IF THERE ARE MORE SPACES

        // Book* books[SIZE];
        //  books[0] = new Book();
        //  books[1] = NULL;

        for (int i = 0; i < SIZE; i++)
        {
            if (books[i] == NULL)
            {
                books[i] = newbook;
                cout << "\nBook was succesfully added.";
                return;
            }
            else
            {
                cout << "\nWe're sorry, there are no more empty spaces in our store.";
            }
        }
    }

    void edit(Book *book_to_edit)
    {
        // COUT AND CIN TO CHANGE POINTERS TO THE BOOK PARAMETERS
        cout << "\nEnter a book's new title: ";
        cin >> book_to_edit->title;
        cout << "\nEnter a book's new author: ";
        cin >> book_to_edit->author;
        cout << "\nBook's author and title was succesfully changed";
    }

    Book *search(string author, string title)
    {
        // TODO FIND SEARCHED_BOOK BY TITLE AND AUTHOR

        /*cout << "\nEnter a book's author: ";
        cin >> searched_book.author;
        cout << "\nEnter a book's title: ";
        cin >> searched_book.title;*/
        // ADD ABOVE TO THE MENU
        for (int i = 0; i < SIZE; i++)
        {
            if (books[i]->author == author && books[i]->title == title)
            {
                return books[i];
            }
        }
        return NULL;
    }

    void buy(Book *book_to_buy, int amount)
    {
        // CHECK IF ASKED AMOUNT IS AVAILABLE THEN PRINT PRICE AND DEDUCT
        // ELSE NOTIFY NOT AVAILABLE
        // IF NOT AVAILABLE SUGGEST TO BUY LEFTOVERS (CALL RECURSIVE METHOD)
        //  cout << "\nEnter a book's title you want to buy: "; <----ADD TO MENU
        //  cin >> book_to_buy->title;
        //  cout << "\nEnter amount: ";
        //  cin >> amount;

        char choice;
        if (amount >= book_to_buy->stock)
        {
            cout << "\nYou can buy" << amount << " books at a price of: " << amount * book_to_buy->price << "\nWould you like to buy it? (Y/N): ";
            cin >> choice;
            if (choice == 'Y')
            {
                book_to_buy->stock--;
            }
        }
        else
        {
            cout << "\nWe have only " << book_to_buy->stock << ".\nWould you like to buy it at a price of: " << book_to_buy->stock * book_to_buy->price << "? (Y/N): ";
            cin >> choice;
            if (choice == 'Y')
            {
                book_to_buy->stock = 0;
            }
        }
    }
};

class Menu
{
public:
    Shop shop;
    Menu(Shop shop) { this->shop = shop; }
    void ShowSearchBook(){};
    void ShowBuyBook(){};
    void ShowEditDetails(){};

    void ShowMainMenu()
    {
        // ADD MENU OPTIONS AS TEXT
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ShowAddNewBookMenu();
            break;
        case 2:
            ShowBuyBook();
            break;
        case 3:
            ShowSearchBook();
            break;
        case 4:
            ShowEditDetails();
            break;        
        }
    }

    void ShowAddNewBookMenu()
    {
        Book newbook;

        cout << "\nEnter Author Name: ";
        getline(cin, newbook.author);
        cin.ignore();

        cout << "\nEnter Title Of The Book: ";
        getline(cin, newbook.title);
        cin.ignore();

        cout << "\nEnter Publisher Name: ";
        getline(cin, newbook.publisher);
        cin.ignore();

        cout << "\nEnter Price: ";
        cin >> newbook.price;
        cin.ignore();

        cout << "\nEnter Number Of Copies: ";
        cin >> newbook.stock;
        cin.ignore();

        shop.entry(&newbook);
    }
};

int main()
{

    Shop shop;
    Menu menu(shop);
    menu.ShowMainMenu();
    //Test new commit
    return 0;
}