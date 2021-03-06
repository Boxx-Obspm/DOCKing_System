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

#ifndef SETTING_CCSDS_H
#define SETTING_CCSDS_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QWidget>

// Include definitions of dialog used struct
#include "setting_dialog_struct.h"

namespace Ui {
class Setting_CCSDS;
}

class Setting_CCSDS : public QDialog
{
    Q_OBJECT

public:
    explicit Setting_CCSDS(QWidget *parent = 0);
    ~Setting_CCSDS();

private:
    Ui::Setting_CCSDS *ui;

    // Declare same parameters as in "setting_dialog_struct.h"
    QString Satellite_name;
    QString Satellite_Axes;
    QString Satellite_3ds = "";
    QString Satellite_quaternion = "";
    QString Satellite_position = "";
    QString Satellite_parentpath;
    QString Satellite_ref_frame_A;
    QString Satellite_ref_frame_B;
    QString Satellite_attitude_dir;
    QString Satellite_att_type;
    QString Satellite_time_system;

    QString Satellite_3ds_dir = Default_input_dir;
    QString Satellite_quaternion_dir = Default_input_dir;
    QString Satellite_position_dir = Default_input_dir;

    QString Bodyname = "";
    QString Parentname = "";

    bool first_launch_flag = 0; // 0-> first launch
    bool finish_flag = 0; // 1-> finished, 0-> not finished


public slots:  //All listed public function will be called by "dock_main.cpp"  (called by reference)
    // Use "Import" function to get initial value from "dock_main.cpp"
    void Import_default(VTS_CIC_para &vts_cic, bool reset = 0);
    // Use "Export" function to export parameters to "dock_main.cpp"
    void Export_result(VTS_CIC_para &vts_cic);

private slots:
    // PB means the "Push button"
    void on_PB_Satellite_3ds_clicked();
    void on_PB_Satellite_quaternion_clicked();
    void on_PB_Satellite_position_clicked();
    void on_PB_OK_clicked();
    void on_PB_Cancel_clicked();
    void on_PB_Clear_all_clicked();
    void on_line_Satellite_3ds_editingFinished();
    void on_line_Satellite_quaternion_editingFinished();
    void on_line_Satellite_position_editingFinished();
    void on_line_Satellite_name_editingFinished();
    void on_line_Satellite_Axes_editingFinished();
    void on_comboBox_frameA_currentTextChanged(const QString &arg1);
    void on_comboBox_frameB_currentTextChanged(const QString &arg1);
    void on_comboBox_dir_currentTextChanged(const QString &arg1);
    void on_comboBox_type_currentTextChanged(const QString &arg1);
    void on_comboBox_time_currentTextChanged(const QString &arg1);
    void on_comboBox_body_currentTextChanged(const QString &arg1);
};

#endif // SETTING_CCSDS_H
