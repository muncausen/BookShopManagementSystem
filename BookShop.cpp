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
        
    }

    void edit(Book *book_to_edit)
    {
        string author, title, publisher;
        int stock;
        float price;
        cin.ignore();
        cout << "\nEnter a new author name: ";
        getline(cin, author);
        cout << "\nEnter a new title: ";
        getline(cin, title);
        cout << "\nEnter a new publisher: ";
        getline(cin, publisher);
        cout << "\nEnter a new price: ";
        cin >> price;
        cout << "\nEnter a new amount: ";
        cin >> stock;

        book_to_edit->author = author;
        book_to_edit->title = title;
        book_to_edit->publisher = publisher;
        book_to_edit->price = price;
        book_to_edit->stock = stock;


        cout << "\nBook details have been changed successfully!";
    }

    Book *search(const string author, const string title)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (books[i].author.compare(author) == 0 && books[i].title.compare(title) == 0)
                {
                    cout << "Book found succesfully!" << endl;
                    return &books[i];
                }
            
        }
        return NULL;
    }

    void buy(Book *book_to_buy, int amount)
    {
        char choice;
        if (amount <= book_to_buy->stock)
        {
            cout << "\nYou can buy " << amount << " books at a price of: $" << amount * book_to_buy->price << "\nWould you like to buy it? (Y/N): ";
            cin >> choice;
            if (choice == 'Y'|| choice == 'y')
            {
                book_to_buy->stock = book_to_buy->stock - amount;
                cout << "\nBooks Bought Succesfully!";
            }
            else
            {
                cout << "\nYou Didn't Buy Any Books!";
            }
        }
        else
        {
            cout << "\nWe have only " << book_to_buy->stock << ".\nWould you like to buy it at a price of: $" << book_to_buy->stock * book_to_buy->price << "? (Y/N): ";
            cin >> choice;
            if (choice == 'Y'|| choice == 'y')
            {
                book_to_buy->stock = 0;
                cout << "\nBooks Bought Succesfully!";
            }
            else
            {
                cout << "\nYou Didn't Buy Any Books!";
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
            cout << "\nBook is not found" << endl;
        }
        else
        {
            cout << "\nBook found succesfully" << endl;
            cout << "Title Name: " << found_book->title << endl;
            cout << "Author Name: " << found_book->author << endl;
            cout << "Publisher Name: " << found_book->publisher << endl;
            cout << "Number of Copies: " << found_book->stock << endl;
            cout << "Price: $" << found_book->price << endl;
        }
        

    }
    /***METHOD OF A CLASS SHOP TO __BUY__ A BOOK***/
    void ShowBuyBook()
    {
        string author, title;
        int amount;
        
        cin.ignore();
        cout << "\nEnter a book's author you want to buy: ";
        getline(cin, author);
        cout << "\nEnter a book's title you want to buy: ";
        getline(cin, title);
        cout << "\nEnter amount: ";
        cin >> amount;

        Book *book_to_buy = shop.search(author,title);

        if (book_to_buy != NULL)
        {
            if (book_to_buy->stock != 0)
            {
                shop.buy(book_to_buy, amount);
            }
            else 
            {
                cout << "\nSorry, we're out of stock" << endl;
            }
        }
        else
        {
            cout << "\nSorry, we don't have this book" << endl;
        }
        
    }
    /***METHOD OF A CLASS SHOP TO __EDIT__ A BOOK***/
    void ShowEditDetails()
    {
        string author, title;
        cin.ignore();
        cout << "\nEnter the author of the book you want to edit: ";
        getline(cin, author);
        cout << "\nEnter the title of the book you want to edit: ";
        getline(cin, title);

        Book *book_to_edit = shop.search(author, title);

        if (book_to_edit != NULL)
        {
            shop.edit(book_to_edit);
        }
        else
        {
            cout << "\nWe're sorry, there is no such book..." << endl;
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
        cout << "\nPlease select from the menu list by entering number of operation: ";
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
    return 0;
}