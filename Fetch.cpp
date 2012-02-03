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
    void insert();
    void fetch();
    void delete1();
}c;
void MCA::fetch()
{
    cout<<"\n\n                    This is Fetching data from Database";
    cout << "\n\nEnter your Age:";
    cin>>age;
    sql << "select Name,Age,Regno from Student\
     where Age = :age",
    use (age),
    into (c.name),
    into (c.age),
    into (c.regno);

    cout<<c.name<<"\t\t"<<c.age<<"\t\t"<<c.regno;
}
int main()
{
    //MCA c;
    sql << "create table if not exists Student\
    (Name varchar,Age integer primary key,Regno varchar\)";

    c.fetch();

return 0;
}
