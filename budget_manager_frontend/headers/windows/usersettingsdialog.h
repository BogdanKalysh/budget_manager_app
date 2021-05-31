#ifndef USERSETTINGSDIALOG_H
#define USERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class UserSettingsDialog;
}

class UserSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingsDialog(QWidget *parent = nullptr);
    ~UserSettingsDialog();

private:
    Ui::UserSettingsDialog *ui;
};

#endif // USERSETTINGSDIALOG_H
