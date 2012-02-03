#include<iostream>
#include<string.h>
#include<soci.h>
#include<soci-sqlite3.h>
using namespace std;
using namespace soci;
session sql (sqlite3, "First.db");
 class MCA
{
    public:
    string name,regno;
    int age;
    void update1();

}c;
void MCA::update1()
{
    cout<<"\n\n                    This is updating data into Database";
    cout << "\n\nEnter your Age:";
    cin>>age;
    sql << "select Name,Age,Regno from Student where Age = :age",
    use (age),
    into (c.name),
    into (c.age),
    into (c.regno);
    cout<<c.name<<"\t\t"<<c.age<<"\t\t"<<c.regno;
    cout<<"\n------------------------------------------";


    cout<<"\n\nEnter the name:";
    cin>>name;
    cout<<"Enter thr Regno:";
    cin>>regno;

        sql << "update Student set Name= :name,Regno= :regno\
                      where Age = :age",
        use (age),
        use (name),
        use (regno),
        into (c.age),
        into (c.name),
        into (c.regno);
 cout<<"\n\n Successfully Edited";
}
int main()
{
    sql << "create table if not exists Student\
    (Name varchar,Age integer primary key,Regno varchar\)";

    c.update1();
return 0;
}
