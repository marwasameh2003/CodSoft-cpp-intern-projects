#include <iostream>
#include<iomanip>
#include<vector>
using namespace std;
const int Row = 5;
const int Col = 10;

class movie
{
public:
    string name;
    int price;
    int counter=0;
    movie(string n, int p)
    {
        name = n;
        price = p;
    }
    bool seats[Row][Col]= {false};
    void display()
    {
        cout<<"  ";
        for (int i = 1 ; i<= Col ; i++)
        {
            cout<< setw(3)<<i;
        }
        cout<<endl;

        for(int j = 0; j<Row; j++)
        {
            cout<< static_cast<char>('A'+j)<<" ";
            for(int i = 0 ; i<Col ; i++)
            {
                if(seats[j][i])
                {
                    cout<<setw(3)<< "X";
                }
                else
                {
                    cout<<setw (3)<<"-";
                }
            }
            cout<< endl;
        }
    }
    void reservation( )
    {
        counter++;
        cout<< "How many seats do you want? ";
        int seat;
        cin>>seat;
        while(seat--)
        {
        int col;
        char row;
        cout<<"Enter Row(A-E): ";
        cin>>row;
        cout<<"Enter Column(1-10): ";
        cin>>col;
        if(row < 'A' || row> 'E' || col <1 || col>10)
        {
            cout<<"Enter valid Row or Column \n";
        }
        if(seats[row-'A'][col-1])
        {
            cout<<"Seat is already booked\n";
        }
        else
        {
            seats[row-'A'][col -1]=true;
            cout<<"You have booked the seat successfully\n";
        }
        cout<<"\n";
        display();
        cout<<"\n";
        }

    }
    void calculateCost()
    {
     cout<< "The total cost is "<< (counter * this.price)<< " for "<< counter<< " tickets for "<<name << " movie\n";
     cout<< "See you soon!\n";
    }
    void program()
    {
        display();
        cout<<"\n";
        reservation();
    }

};

int main()
{
    vector<movie> movies;
    movie m1("Nemo", 65);
    movie m2("Soul", 70);
    movie m3("Dumbo", 85);
    movie m4("Incredible", 60);
    movies.push_back(m1);
    movies.push_back(m2);
    movies.push_back(m3);
    movies.push_back(m4);
    cout<<"Welcome to our movie ticket management system \n \n";
    cout<<"These are the available movies right now:\n";
    cout<<"1- Nemo\n2- Soul\n3- Dumbo\n4- Incredible\n\n";
    cout<<"Enter the number of the movie you want to book: ";
    int choice;
    cin>>choice;
    movies[choice-1].program();

}
