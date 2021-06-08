#include "testloginwindow.h"

void testloginwindow::testlogin(){
    LoginWindow loginwindow = LoginWindow();
    //Test incorrect login
    loginwindow.setEmail("andriypasemko@gmail.com");
    loginwindow.setPassword("incorrect_password");
    loginwindow.on_loginButton_clicked();
    QVERIFY(loginwindow.user.getName()!="andriypasemko@gmail.com");
    //Test correct login
    loginwindow.setEmail("andriypasemko@gmail.com");
    loginwindow.setPassword("qwerty123");
    loginwindow.on_loginButton_clicked();
    QCOMPARE(loginwindow.user.getEmail(),"8dbbf61e04d6fbc2cac7cf4f1fc2226335");
}
