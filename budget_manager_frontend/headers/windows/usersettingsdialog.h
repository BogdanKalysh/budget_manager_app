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
    explicit UserSettingsDialog(const User &user, const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent = nullptr);
    ~UserSettingsDialog();
    User getUser();

public slots:
    void updateCategories();
    void readCategories();

private slots:
    void on_saveButton_clicked();
    void updatePassword();
    void updateUser(const User &user);
    void on_deleteCategoryButton_clicked();
    void finishedUpdateUser();
    void finishedDeleteCategory();

private:
    Ui::UserSettingsDialog *ui;
    User user;
    QSharedPointer<QNetworkAccessManager> manager;
    QVector<Category> categories;
};

#endif // USERSETTINGSDIALOG_H
