#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->email_line->setPlaceholderText("email");
    ui->password_line->setPlaceholderText("password");
    signUpWindow = new SignUpWindow();
    connect(signUpWindow, &SignUpWindow::loginWindow, this, &LoginWindow::show);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    //connect to db
    QString email = ui->email_line->text();
    QString password = ui->password_line->text();

    //if(database.open()){

    if(email=="qwerty" && password == "123123"){
        mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    }
    else{
        QMessageBox::critical(this, "Failed", "Wrong login or password");
    }


}


void LoginWindow::on_signUpLoginButton_clicked()
{
    signUpWindow->show();
    this->close();
}
