/*
 Developer: LIN, Hao-Chih (Jim, LIN)
 Email: f44006076@gmail.com
 Advisor: Boris, Segret
 Final modified date: 23/10/2015
 ==============================================================
 ===========================LICENSE============================
 ==============================================================
 This file is part of DOCKS.

 DOCKS is free software: you can redistribute it and/or modify
 it under the terms of the  GNU LESSER GENERAL PUBLIC LICENSE
 as published by the Free Software Foundation, either version
 3 of the License, or any later version.

 DOCKS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU LESSER GENERAL PUBLIC LICENSE for more details.

 You should have received a copy of the
 GNU LESSER GENERAL PUBLIC LICENSE along with DOCKS.
 If not, see <http://www.gnu.org/licenses/lgpl.txt>.
*/

#ifndef SETTING_STELA_H
#define SETTING_STELA_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_STELA;
}

class Setting_STELA : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_STELA(QWidget *parent = 0);
    ~Setting_STELA();

private:
    Ui::Setting_STELA *ui;
    QString software_location;
    QString default_software_location;
    bool first_launch_flag = 0;

public slots:
    void Import_default(st_STELA &st_stela, bool reset = 0);
    void Export_result(st_STELA &st_stela);

private slots:
    void on_PB_soft_location_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    bool on_line_soft_location_editingFinished();
};

#endif // SETTING_STELA_H
