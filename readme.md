# **Explanation of the connection string**

postgres://pavlo:XXXX@34.118.91.164:5432/budget-manager (example of conenction string in my code)

Connection string to this database contains four elements:

username, user-password, host address and port and name of the database

In my connection string username and user password are "pavlo" and "XXXX". 
Address of database is 34.118.91.164:5432(port which uses postgres), budget-manager is name of the databse(NOT OF INSTANCE).

To create your own connection string you can just copy this string and change "pavlo" and "xxxx" on your own user and password.
Also you need check that your IP is in instance white-list(in this case conenction timeout error will be triggerred)

# **Explanation of my code**
At first I create connection to database.
To make queries I use variablle of type pqxx::work and exec method for executing query.
Result of queries is stored in pqxx::work variable.
To parse result you need loop through every row in foreach loop and get field you need in the result.


# **How to run my code on linux**
To run this code you must download libpqxx library.
Than you need to compile this code via `g++ name_of_your_file.cpp -lpqxx _lpq `command. 
After that your must run run `./a.out` command to execute your code. 