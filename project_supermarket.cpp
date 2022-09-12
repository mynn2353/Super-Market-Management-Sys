#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void receipt();
    void list();
};

void shopping ::menu()
{

    int choice = 1;
    do
    {
        string email;
        string password;

        cout << "\t\t\t\t____________________________\n";
        cout << "\t\t\t\t                            \n";
        cout << "\t\t\t\t          S U P E R         \n";
        cout << "\t\t\t\t         M A R K E T        \n";
        cout << "\t\t\t\t                            \n";
        cout << "\t\t\t\t____________________________\n";
        cout << "\t\t\t\t                            \n";
        cout << "\t\t\t\t|    1) Administrator      |\n";
        cout << "\t\t\t\t|    2) Buyer              |\n";
        cout << "\t\t\t\t|    3) Exit               |\n";
        cout << "\t\t\t\t                            \n";
        cout << "\n\t\t\t     Please select ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "\t\t\t   Please Login ";
            cout << "\t\t\t   Enter Email  ";
            cin >> email;
            cout << "\t\t\t   Password     ";
            cin >> password;

            if (email == "mayank@gmail.com" && password == "Mayank")
            {
                administrator();
            }
            else
            {
                cout << " Invalid Username or Password" << endl;
            }
            break;
        }
        case 2:
        {
            buyer();
            break;
        }
        case 3:
        {
            return;
        }

        default:
        {
            cout << "Please select from the given options : ";
            break;
        }
        }
    } while (choice == 1);
}

void shopping ::administrator()
{
m5:
    cout << "           Administrators menu: " << endl;
    cout << endl;
    cout << "           1) Add products-" << endl;
    cout << endl;
    cout << "           2) Modify available products-" << endl;
    cout << endl;
    cout << "           3) Delete product-" << endl;
    cout << endl;
    cout << "           4) Back to Main menu-" << endl;
    cout << "           Please enter your choice : ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {

        edit();
        break;
    }
    case 3:
    {

        rem();
        break;
    }
    case 4:
    {

        menu();
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        goto m5;
    }
    return;
}

void shopping ::buyer()
{
m2:
    int choice;
    cout << "     Buyer    " << endl;
    cout << "   1) Buy product    " << endl;
    cout << "   2) Go back        " << endl;
    cout << "Enter your choice : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "Invalid choice. Try again " << endl;
        goto m2;
    }
}

void shopping ::add()
{
m3:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "           Add new products" << endl
         << endl;
    cout << "           Enter product code : ";
    cin >> pcode;

    cout << "           Name of product : ";
    cin >> pname;

    cout << "           Price of product : ";
    cin >> price;

    cout << "           Discount on product : ";
    cin >> dis;

    data.open("databae.txt", ios ::in);

    if (!data)
    {
        data.open("database.txt", ios ::app);
        data << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis << "\n";
        cout << endl;
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
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
        goto m3;
    else
    {
        data.open("database.txt", ios ::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    cout << "Record inserted !" << endl;
    return;
}

void shopping ::edit()
{
m1:
    fstream data, data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;

    cout << "       Modify the record" << endl;
    cout << "       Product code " << endl;
    cin >> pkey;

    data.open("database.txt", ios ::in);
    if (!data)
    {
        cout << "       File doesnt exists !" << endl;
    }

    else
    {
        data1.open("database.txt", ios ::app | ios ::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "       Product new code : ";
                cin >> c;

                cout << "       Name of the product : ";
                cin >> n;

                cout << "       Price : ";
                cin >> p;

                cout << "       Discount : ";
                cin >> d;

                data1 << " " << c << " " << n << " " << p << " " << d << " "
                      << "\n";
                cout << "       Record edited" << endl;
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
            cout << "       Record not found sorry !";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "       Delete product" << endl;
    cout << "       Product code : ";
    cin >> pkey;
    data.open("database.txt", ios ::in);

    if (!data)
    {
        cout << "       File not found !";
    }

    else
    {
        data1.open("database1.txt", ios ::app | ios ::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "       Product deleted succesfully";
                token++;
            }

            else
            {
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "       Record not found !";
        }
    }
    return;
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios ::in);
    // cout<<"Product no.  "<<"Name    "<<"price   "<<"Discount    "<<endl;
    cout << "Product No.\t\tName\t\tPrice\t\tDiscount\n";
    data >> pcode >> pname >> price >> dis;

    if (data.is_open())
    {
        string tp;
        while (getline(data, tp))
        {
            cout << tp << "\n";
        }
        data.close();
    }

    // while(!data.eof())
    // {
    //     cout<<pcode<<"      "<<pname<<"     "<<price<<"     "<<dis;
    // }
    // data.close();
}

void shopping ::receipt()
{
    fstream data;

    int arr[100];
    int arrq[100];
    char choice;
    int c = 0;

    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << " RECEIPT " << endl;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "Empty database";
    }

    else
    {
        data.close();

        list();
        cout << " P L E A S E   P L A C E   O R D E R " << endl;

        do
        {
        m:
            cout << "Enter product code : ";
            cin >> arr[c];
            cout << "Enter the product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arr[c] == arr[i])
                {
                    cout << "Duplicate product code. Please try again ";
                    goto m;
                }
            }
            c++;
            cout << "Do you want to buy another product? if yes press y else n : ";
            cin >> choice;
        } while (choice == 'y');

        cout << "--------------R E C E I P T ---------------" << endl
             << endl;
        cout << "Product no   "
             << "Product name    "
             << "Quantity    "
             << "Price   "
             << "Amount  "
             << "Amount with Discount" << endl;

        for (int i = 0; i <= c; i++)
        {
            data.open("database.txt", ios ::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arr[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << pcode << "       " << pname << "            " << arrq[i] << "         " << price << "          " << amount << "           " << dis << endl;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << " T O T A L  A M O U N T : " << total << endl;
}

int main()
{
    shopping s;
    s.menu();

    return 0;
}