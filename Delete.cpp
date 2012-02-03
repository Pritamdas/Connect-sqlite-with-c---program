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
void MCA::delete1()
{
    cout<<"\n\n                    This is deleting data from Database";
    cout << "\n\nEnter your Age:";
    cin>>age;
    sql << "select Name,Age,Regno from Student where Age = :age",
    use (age),
    into (c.name),
    into (c.age),
    into (c.regno);

    cout<<c.name<<"\t\t"<<c.age<<"\t\t"<<c.regno;
    cout<<"\n\n Successfully Deleted";
        sql << "delete from Student \
                      where Age = :age",
        use (age);

}
int main()
{
    sql << "create table if not exists Student\
    (Name varchar,Age integer primary key,Regno varchar\)";

    c.delete1();
return 0;
}
