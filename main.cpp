#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class book{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book(){
        author = new char[20];
        title = new char[50];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }

    void createbook();
    void editbook();
    void showbook();
    void buybook();
    int searchbook(char[], char[]);
};

void book::createbook()
{
    cin.ignore();
    cout << "\nEnter Author Name: "; cin.getline(author, 20);
    cout << "Enter Book Title Name: "; cin.getline(title, 50);
    cout << "Enter Publisher Name: "; cin.getline(publisher, 20);
    cout << "Enter Book Price: "; cin >> *price;
    cout << "Enter Number of Books: "; cin >> *stock;

}

void book::editbook()
{
    cout << "\nEnter Author Name: "; cin.getline(author, 20);
    cout << "Enter Book Title Name: "; cin.getline(title, 50);
    cout << "Enter Publisher Name: "; cin.getline(publisher, 20);
    cout << "Enter Book Price: "; cin >> *price;
    cout << "Enter Number of Books: "; cin >> *stock;
}

void book::showbook()
{
    cout << "\nAuthor: " << author;
    cout << "\nTitle: " << title;
    cout << "\nPublisher: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock: " << *stock;
}

void book::buybook()
{
    int count;
    cout << "\nEnter number of books to buy: "; cin >> count;
    if(count <= *stock)
    {
        *stock = *stock - count;
        cout << "\nTransaction was successful!";
        cout << "Total Cost is " << (*price) * count;
    }
    else
    {
        cout << "\nNo enough stock for this purchase!";
    }
}

int book::searchbook(char tbuy[50], char abuy[20])
{
    if(strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
        return 1;
    else
        return 0;
}

int main()
{
    book *B[50];
    int i = 0, r, j, choice;
    char abuy[20], tbuy[50];

    while(1){
        cout << "\n\nMain Menu";
        cout << "\n 1. Create a New Book";
        cout << "\n 2. Search for a Book";
        cout << "\n 3. Edit Book Details";
        cout << "\n 4. Buy a Book";
        cout << "\n 5. Exit";
        cout << "\n\n Enter Your Choice to Proceed" << endl;
        cin >> choice;

        switch(choice)
        {
        case 1:
            B[i] = new book;
            B[i]->createbook();
            i ++;
            break;
        case 2:
            cin.ignore();
            cout << "Enter Book Title: "; cin.getline(tbuy, 50);
            cout << "Enter Book Author: "; cin.getline(abuy, 20);

            for(j = 0; j < i; j ++)
            {
                if(B[j]->searchbook(abuy, tbuy))
                {
                    cout << "\n Book found successfully!";
                    B[j]->showbook();
                    break;
                }
            }

            if(j == 1)
            {
                cout << "\n This book was not found in stock!";
                break;
            }

        default:
            cout << "Invalid choice was entered!";
        }
    }

    return 0;
}
