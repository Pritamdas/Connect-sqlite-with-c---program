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




}c;
void MCA::insert()
{
    cout<<"\n\n              This is inserting Data into Database";
   cout<<"\n\nEnter the name:";
    cin>>name;
    cout<<"Enter thr Regno:";
    cin>>regno;
    cout<<"Enter the Age:";
    cin>>age;
    sql << "insert into Student(Name,Age,Regno)\
    values (:name,:age,:regno)",
                use (name),
                use (age),
                use (regno);
    cout<<"\n\n Successfully Inserted";
}

int main()
{
    sql << "create table if not exists Student\
    (Name varchar,Age integer primary key,Regno varchar\)";
    c.insert();

return 0;
}
