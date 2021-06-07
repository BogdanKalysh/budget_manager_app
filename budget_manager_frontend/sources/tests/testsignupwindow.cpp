#include "testsignupwindow.h"


void TestSignUpWindow::testSignUp()
{
    QSharedPointer<QNetworkAccessManager> manager;
    manager.reset(new QNetworkAccessManager);
    //Tests for something empty
    SignUpWindow signUpWindow = SignUpWindow(manager);
    signUpWindow.setName("");
    signUpWindow.setEmail("");
    signUpWindow.setPassword("");
    signUpWindow.setPasswordConfirmation("");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),1);
    //Tests for passwords do not match
    signUpWindow.setName("Username");
    signUpWindow.setEmail("username@gmail.com");
    signUpWindow.setPassword("password");
    signUpWindow.setPasswordConfirmation("passpord");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),1);
    //Tests for wrong password
    signUpWindow.setName("Username");
    signUpWindow.setEmail("username@gmail.com");
    signUpWindow.setPassword("passwo");
    signUpWindow.setPasswordConfirmation("passwo");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),3);
    //Tests for wrong password
    signUpWindow.setName("Username");
    signUpWindow.setEmail("username@gmail.com");
    signUpWindow.setPassword("passwo");
    signUpWindow.setPasswordConfirmation("passwo");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),3);
    //Tests for wrong email
    signUpWindow.setName("Username");
    signUpWindow.setEmail("usernamegmail.com");
    signUpWindow.setPassword("password");
    signUpWindow.setPasswordConfirmation("password");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),3);
    //Test for all correct
    signUpWindow.setName("Username");
    signUpWindow.setEmail("username@gmail.com");
    signUpWindow.setPassword("password");
    signUpWindow.setPasswordConfirmation("password");
    QCOMPARE(signUpWindow.on_signUpButton_clicked(),0);
}
