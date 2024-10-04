#include <iostream>
#include <fstream>
using namespace std;

class temp
{

    string id, name, author, search;

public:
    void addBook();
    void showAll();
    void extractBook();
} obj;
int main()
{

    char choice;
    cout << "--------------------------------" << endl;
    cout << "1-Show All Books" << endl;
    cout << "2-Extract Book" << endl;
    cout << "3-Add books(ADMIN)" << endl;
    cout << "4-Exit" << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter Your Choice ::  ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.showAll();
        break;

    case '2':
        cin.ignore();
        obj.extractBook();
        break;

    case '3':
        cin.ignore();
        obj.addBook();

        break;

    case '4':
        return 0;
        break;

    default:
        cout << "Invalid Choice........." << endl;
        break;
    }
    return 0;
}

void temp ::addBook()
{
    cout << "Enter book ID :: " << endl;
    getline(cin, id);
    cout << "Enter Book Name :: " << endl;
    getline(cin, name);
    cout << "Enter Author Name :: " << endl;
    getline(cin, author);

    ofstream fout;
    fout.open("bookData.txt",ios::app);
    fout << id << "*" << name << "*" << author << endl;
    fout.close();
};

void temp ::showAll()
{
    ifstream fin;
    fin.open("bookData.txt");
    getline(fin, id, '*');
    getline(fin, name, '*');
    getline(fin, author, '\n');
        cout << "\n\n";
        cout << "\t\tBook Id\t\t\t\tBook Name\t\t\tAuthor's Name"<<endl;
    while (!fin.eof())
    {
        cout << "\t\t" << id << "\t\t\t\t" << name << "\t\t\t\t" << author << endl;
        getline(fin,id,'*');
        getline(fin,name,'*');
        getline(fin,author,'\n');
    }
    fin.close();
}

void temp ::extractBook()
{

    showAll();
    cout << "Enter Book Id ::";
    getline(cin, search);

    ifstream fout;
    fout.open("bookData.txt");
    getline(fout, id, '*');
    getline(fout, name, '*');
    getline(fout, author, '\n');

    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t\t Book Name \t\t\t Author's Name ";

    while (!fout.eof())
    {
        if (search == id)
        {
            cout << "\t\t " << id << "\t\t\t\t" << name << " \t\t\t" << author << endl;
            cout << "Book Extracted Successfully" << endl;
        }
        getline(fout,id,'*');
        getline(fout,name,'*');
        getline(fout,author,'\n');
    }
    fout.close();
}