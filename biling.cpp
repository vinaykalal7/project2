#include <iostream>
#include <fstream>

using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void Menu();
    void Administrator();
    void Buyer();
    void Add();
    void Edit();
    void rem();
    void list();
    void receipt();
};

void shopping::Menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t________________________________________\n";
    cout << "\t\t\t\t                                          \n";
    cout << "\t\t\t\t             Supermarket Main Menu         \n";
    cout << "\t\t\t\t                                          \n";
    cout << "\t\t\t\t________________________________________\n";

    cout << "\t\t\t\t      1 - Administrator                       |\n";
    cout << "\t\t\t\t                                              |\n";
    cout << "\t\t\t\t      2 - Buyer                               |\n";
    cout << "\t\t\t\t                                              |\n";
    cout << "\t\t\t\t      3 - Exit                                |\n";

    cout << "\n\t\t\t  Please select: ";

    cin >> choice;
    switch (choice)
    {

    case 1:{
        cout << "\t\t\t Please Login\n";
        cout << "\t\t\t Enter Email\n";
        cin >> email;
        cout << "\t\t\t  Password \n";
        cin >> password;

        if (email == "vin@gmail.com" && password == "vin@123")
        {
            Administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
          break;
    }
    case 2:
    {
        Buyer();
    }

    case 3:
    {
        exit(0);
    }
    default:
    
    {
        cout << "Please Enter from given options ";
    }
    }

    goto m;
}

void shopping::Administrator()
{
m:
    int choice;
    cout << "\n\n\n\n\n\t\t\t Administrator Menu";
    cout << "\n\n\n\n\n\t\t\t 1- Add the product    |";
    cout << "\n\n\t\t\t                             |";
    cout << "\n\n\n\n\n\t\t\t 2- Modify the product |";
    cout << "\n\n\t\t\t                             |";

    cout << "\n\n\n\n\n\t\t\t 3- Delete the product |";
    cout << "\n\n\t\t\t                             |";

    cout << "\n\n\n\n\n\t\t\t 4- Back to main menu  |";

    cout << "\n\n\t  Please Enter Your Choice ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        Add();
        break;
    case 2:
        Edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        Menu();
        break;

    default:
        cout << "Invalid choice! ";
    }

    goto m;
}

void shopping::Buyer()
{
m:
    int choice;
    cout << "\t\t\t       Buyer  \n ";
    cout << "\t\t\t______________\n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t  1- Buy product \n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t  2- Go back   \n ";
    cout << "\t\t\t  Enter your choice : \n";

    cin >> choice;

    switch (choice)
    {

    case 1:
        receipt();
        break;

    case 2:
        Menu();
        //   break;
    default:
        cout << "Invalid choice";
    }
    goto m;
}

void shopping::Add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t  Add new product";
    cout << "\n\n\t  product code of the product:   ";
    cin >> pcode;
    cout << "\n\n\t  Name of the product:  ";

    cin >> pname;
    cout << "\n\n\t  Price of the product:  ";
    cin >> price;
    cout << "\n\n\t Discount on product:  ";
    cin >> dis;

    data.open("database.txt", ios::in); // open in reading mode

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    
    if (token == 1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    }
    cout << "\n\n\t\t  Record Inserted!";
}

void shopping ::Edit()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code:  ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out); // write mode
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {

            if (pkey == pcode)
            {
                cout << "\n\t\t Product New code";
                cin >> c;
                cout << "\n\t\t Name of the product: ";
                cin >> n;
                cout << "\n\t\t Price: ";
                cin >> p;
                cout << "\n\t\t Discount: ";
                cin >> d;
                data1 <<" "<<c<<" "<<" "<<p<<""<<d<<"\n";
                cout << "\n\n\t\t Record Edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not Found Sorry!";
        }
    }
}

void shopping ::rem()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete Product";

    cout << "\n\n\t  Product Code: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not Found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n__________________________________________________\n";
    cout << "ProNo \t\t Name\t\tPrice\n";
    cout << "\n\n__________________________________________________\n";
    data >> pcode >> pname >> price >> dis;

    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{

    fstream data;
    int arrc[100];
    int arrQ[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\n\t\t\t\t RECEIPT";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty Database";
    }
    else
    {
        data.close();
        list();
        cout << "\n_________________________________________\n";
        cout << "\n_________________________________________\n";
        cout << "\n         Please Place the Order          \n";
        cout << "\n_________________________________________\n";
        cout << "\n_________________________________________\n";

        do
        {
        m:
            cout << "\n\n Enter Product Code: ";
            cin >> arrc[c];
            cout << "\n\nn Enter the product Quantity: ";
            cin >> arrQ[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate Product code. Please Try Again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another Product press -y for YES else -n for NO: ";
            cin >> choice;
        } 
        while (choice == 'y');
        cout << "\n\n\t\t\t_________________ RECEIPT____________________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\t price\tAmount\tAmount with Discount \n";

        for (int i = 0; i < c; i++)
        {

            data.open("database.txt", ios::in);

            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price*arrQ[i];
                    dis = amount - (amount * (dis / 100));
                    total = total + dis;
                    cout << "\n"<< pcode << "\t\t" << pname << "\t\t" << arrQ[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        
        }
        data.close();
    }

    cout << "\n\n___________________________________________________________";
    cout << "\n Total Amount: " << total;
}

int main()
{

    shopping s;

    s.Menu();
}