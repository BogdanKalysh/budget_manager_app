#include "usersettingsdialog.h"
#include "ui_usersettingsdialog.h"

UserSettingsDialog::UserSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingsDialog)
{
    ui->setupUi(this);
}

UserSettingsDialog::~UserSettingsDialog()
{
    delete ui;
}
