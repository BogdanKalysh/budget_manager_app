#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include "constants.h"
#include <QDialog>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

namespace Ui {
class AddCategoryDialog;
}

class AddCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    AddCategoryDialog(const int userId, const QString &type, const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent = nullptr);
    ~AddCategoryDialog();

public slots:
    void finishedPostCategory();

private slots:
    void on_addCategoryButton_clicked();

    void on_colorPicker_clicked();

private:
    Ui::AddCategoryDialog *ui;
    int userId;
    QString name;
    QString type;
    QString color;
    QSharedPointer<QNetworkAccessManager> manager;
};

#endif // ADDCATEGORYDIALOG_H
