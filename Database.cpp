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
void MCA::insert()
{
    cout<<"\n\n              This is inserting Data into Database";
   cout<<"\n\nEnter the name:";
    cin>>name;
    cout<<"Enter thr Regno:";
    cin>>regno;
    cout<<"Enter the Age:";
    cin>>age;
    sql << "insert into Student(Name,Age,Regno)values (:name,:age,:regno)",
                use (name),
                use (age),
                use (regno);
    cout<<"\n\n Successfully Inserted";
}
void MCA::fetch()
{
    cout<<"\n\n                    This is Fetching data from Database";
    cout << "\n\nEnter your Age:";
    cin>>Age;
    sql << "select Name,Age,Regno from Student where Age = :age",
    use (Age),
    into (c.Name),
    into (c.Age),
    into (c.Regno);

    cout<<c.Name<<"\t\t"<<c.Age<<"\t\t"<<c.Regno;
}
void MCA::delete1()
{
    cout<<"\n\n                    This is deleting data from Database";
    cout << "\n\nEnter your Age:";
    cin>>Age;
    sql << "select Name,Age,Regno from Student where Age = :age",
    use (Age),
    into (c.Name),
    into (c.Age),
    into (c.Regno);

    cout<<c.Name<<"\t\t"<<c.Age<<"\t\t"<<c.Regno;
    cout<<"\n\n Successfully Deleted";
        sql << "delete from Student \
                      where Age = :age",
        use (Age);

}
int main()
{
    sql << "create table if not exists Student\
    (Name varchar,Age integer primary key,Regno varchar\)";
    c.insert();
    //c.fetch();
    //c.delete1();
return 0;
}
