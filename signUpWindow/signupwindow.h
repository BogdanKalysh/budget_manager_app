#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

signals:
    void loginWindow();

private slots:
    void on_signUpButton_clicked();

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
