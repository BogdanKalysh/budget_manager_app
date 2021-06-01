#ifndef USERSETTINGSDIALOG_H
#define USERSETTINGSDIALOG_H

#include "constants.h"
#include <QDialog>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <user.h>
#include <category.h>

namespace Ui {
class UserSettingsDialog;
}

class UserSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingsDialog(User& user, QSharedPointer<QNetworkAccessManager> manager, QWidget *parent = nullptr);
    ~UserSettingsDialog();
    User getUser();

public slots:
    void updateCategories();
    void readCategories();

private slots:
    void on_saveButton_clicked();
    void updatePassword();
    void updateUser(User& user);

    void on_deleteCategoryButton_clicked();

private:
    Ui::UserSettingsDialog *ui;
    User user;
    QSharedPointer<QNetworkAccessManager> manager;
    QVector<Category> categories;

    void finishedUpdateUser();
};

#endif // USERSETTINGSDIALOG_H
