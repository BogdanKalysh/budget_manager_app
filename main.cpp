#include <bits/stdc++.h>
#include <pqxx/pqxx>
using namespace std;
const string conn_string = "postgres://pavlo:xxxx@34.118.91.164:5432/budget-manager";

int main(int, char *argv[])
{
    pqxx::connection c{conn_string};
    pqxx::work txn{c};
    pqxx::result r{txn.exec("SELECT name, mail FROM users")};
    for (auto row: r)
        std::cout
                // Address column by name.  Use c_str() to get C-style string.
                << row["name"].c_str()<<endl;
}