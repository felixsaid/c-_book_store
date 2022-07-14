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

int book::searchbook(char tbuy[50],char abuy[50] ){}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
