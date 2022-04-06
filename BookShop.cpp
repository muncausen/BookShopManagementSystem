#include <iostream>
#include <string.h>

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
    Book books[SIZE];
    int lastEntry = 0;

    void entry(const Book newbook)
    {

        books[lastEntry] = newbook;
        lastEntry++;
        // for (int i = 0; i < SIZE; i++)
        // {
        //     Book book = books[i];
        //     if (&books[i] == NULL)
        //     {
        //         books[i] = newbook;
        //         cout << "\nBook was succesfully added.";
        //         return;
        //     }
        //     else
        //     {
        //         cout << "\nWe're sorry, there are no more empty spaces in our store.";
        //     }
        // 1}
    }

    void edit(Book *book_to_edit)
    {
        // COUT AND CIN TO CHANGE POINTERS TO THE BOOK PARAMETERS
        // cout << "\nEnter a book's new title: "; //ADD THIS TI THE MENU CLASS
        // cin >> book_to_edit->title;
        // cout << "\nEnter a book's new author: ";
        // cin >> book_to_edit->author;
        // cout << "\nBook's author and title was succesfully changed";
        // for (int i = 0; i < SIZE; i++)
        // {
        //     if (books[i]->author == author && books[i]->title == title){
        //         cout << "\nEnter a new author name: ";
        //         getline(cin, author);
        //         cout << "\nEnter a new title: ";
        //         getline(cin, title);

        //         books[i]->author = author;
        //         books[i]->title = title;

        //         cout << "\nAuthor and title have been changed successfully!";

        //     }
        //     else
        //     {
        //         cout << "\nWe're sorry, there is no such book...";

        //     }
        // }
        string author, title;
        cout << "\nEnter a new author name: ";
        getline(cin, author);
        cout << "\nEnter a new title: ";
        getline(cin, title);

        book_to_edit->author = author;
        book_to_edit->title = title;

        cout << "\nAuthor and title have been changed successfully!";
    }

    Book *search(const string author, const string title)
    {
        // TODO FIND SEARCHED_BOOK BY TITLE AND AUTHOR

        /*cout << "\nEnter a book's author: ";
        cin >> searched_book.author;
        cout << "\nEnter a book's title: ";
        cin >> searched_book.title;*/
        // ADD ABOVE TO THE MENU
        for (int i = 0; i < SIZE; i++)
        {
            if (books[i].author.compare(author) == 0 && books[i].title.compare(title) == 0)
                {
                    return &books[i];
                }
            
        }
        return NULL;
    }

    void buy(Book *book_to_buy, int amount)
    {
        // CHECK IF ASKED AMOUNT IS AVAILABLE THEN PRINT PRICE AND DEDUCT
        // ELSE NOTIFY NOT AVAILABLE
        // IF NOT AVAILABLE SUGGEST TO BUY LEFTOVERS (CALL RECURSIVE METHOD)
        char choice;
        if (amount <= book_to_buy->stock)
        {
            cout << "\nYou can buy " << amount << " books at a price of: " << amount * book_to_buy->price << "\nWould you like to buy it? (Y/N): ";
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
    void ShowSearchBook()
    {
        Book searched_book;
        cin.ignore(); // TO IGNORE ENTER FROM THE CHOICE INPUT
        cout << "\nEnter a book's author: ";
        getline(cin, searched_book.author);

        cout << "\nEnter a book's title: ";
        getline(cin, searched_book.title);

        Book *found_book = shop.search(searched_book.author, searched_book.title); 

        if (found_book == NULL){
            cout << "\nBook is not found";
        }
        else
        {
            cout << "\nBook is found";
        }
        

    }
    /***METHOD OF A CLASS SHOP TO __BUY__ A BOOK***/
    void ShowBuyBook()
    {
        Book book_to_buy;
        int amount;
         cin.ignore();

        cout << "\nEnter a book's author you want to buy: ";
        getline(cin, book_to_buy.author);
       
        cout << "\nEnter a book's title you want to buy: ";
        getline(cin, book_to_buy.title);
       
        cout << "\nEnter amount: ";
        cin >> amount;

        shop.buy(&book_to_buy, amount);
    }
    /***METHOD OF A CLASS SHOP TO __EDIT__ A BOOK***/
    void ShowEditDetails()
    {
        string title, author;
        cin.ignore();
        cout << "\nEnter the title of the book you want to edit: ";
        cin >> title;
        cout << "\nEnter the author of the book you want to edit: ";
        cin >> author;

        Book *book_to_edit = shop.search(author, title);

        if (book_to_edit != NULL)
        {
            shop.edit(book_to_edit);
        }
        else
        {
            cout << "\nWe're sorry, there is no such book...";
        }
    }

    /***METHOD OF A CLASS SHOP TO __SHOW_A_MENU__***/
    void ShowMainMenu()
    {
        int choice;
        cout << "\n**********MENU**********";
        cout << "\n1. Entry Of a New Book";
        cout << "\n2. Buy a Book";
        cout << "\n3. Search For a Book ";
        cout << "\n4. Edit Details Of a Book";
        cout << "\n5. Exit";
        cout << "\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ShowAddNewBookMenu();
            ShowMainMenu();
            break;
        case 2:
            ShowBuyBook();
            ShowMainMenu();

            break;
        case 3:
            ShowSearchBook();
            ShowMainMenu();
            break;
        case 4:
            ShowEditDetails();
            ShowMainMenu();
            break;
        }
    }

    /***METHOD OF A CLASS SHOP TO __ADD__ A BOOK***/
    void ShowAddNewBookMenu()
    {
        Book newbook;
        cin.ignore(); // TO IGNORE ENTER FROM THE CHOICE INPUT

        cout << "\nEnter Author Name: ";
        getline(cin, newbook.author);

        cout << "\nEnter Title Of The Book: ";
        getline(cin, newbook.title);

        cout << "\nEnter Publisher Name: ";
        getline(cin, newbook.publisher);

        cout << "\nEnter Price: ";
        cin >> newbook.price;

        cout << "\nEnter Number Of Copies: ";
        cin >> newbook.stock;

        shop.entry(newbook);
    }
};

int main()
{
    Shop shop;
    Menu menu(shop);
    menu.ShowMainMenu();
    // Test new commit
    return 0;
}