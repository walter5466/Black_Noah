#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

std::string PS_memcard1 ="";
std::string PS_memcard2 ="";
std::string cmd="";
std::string filename="";
std::string ROM_path="";
std::string ROM_path_Saturn="";
std::string ROM_path_SNES = "";
std::string ROM_path_NES = "";
std::string ROM_path_N64 = "";
std::string ROM_path_MasterSystem = "";
std::string ROM_path_Genesis = "";
std::string ROM_path_PC88_floppy1 = "";
std::string ROM_path_PC88_floppy2 = "";
std::string ROM_path_PC98_floppy1 = "";
std::string ROM_path_PC98_floppy2 = "";
std::string ROM_path_PC98_CDROM = "";
std::string CRT_Shader="";
std::string region = "";
std::string region_Saturn ="";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string MACHINE;

}


MainWindow::~MainWindow()
{
    delete ui;
}

// File Chose section
// //////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_Chose_file1_clicked()
//chosing files and saving file path (Playstation)
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Compressed hundks of data (*.chd);;Cue Sheet (*.cue);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path = filename.toUtf8().constData();
    //QMessageBox::information(this,tr("File Name"),filename);
}



void MainWindow::on_Chose_file_Saturn_clicked()
//chosing files and saving file path (Saturn)
{
    QString filename_saturn = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Compressed hundks of data (*.chd);;Cue Sheet (*.cue);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_Saturn = filename_saturn.toUtf8().constData();
    //QMessageBox::information(this,tr("File Name"),filename_saturn);
}


void MainWindow::on_Chose_file_SNES_clicked()
//chosing files and saving file path (SNES)
{
    QString filename_SNES = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Zip files (*.zip);;Cartridge files (*.smc);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_SNES = filename_SNES.toUtf8().constData();
}



void MainWindow::on_Chose_file_NES_clicked()
//chosing files and saving file path (NES)
{
    QString filename_NES = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Zip files (*.zip);;Cartridge files (*.smc);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_NES = filename_NES.toUtf8().constData();
}


void MainWindow::on_Chose_file_PC88_floppy1_clicked()
{
    QString filename_PC88_floppy1 = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Floppy disk image (*.d88);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_PC88_floppy1 = filename_PC88_floppy1.toUtf8().constData();
}


void MainWindow::on_Chose_file_PC88_floppy2_clicked()
{
    QString filename_PC88_floppy2 = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Floppy disk image (*.d88);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_PC88_floppy2 = filename_PC88_floppy2.toUtf8().constData();
}

void MainWindow::on_Chose_file_PC98_floppy1_clicked()
//chosing files and saving file path (PC-98)
{
    QString filename_PC98_floppy1 = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Floppy disk image (*.fdi);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_PC98_floppy1 = filename_PC98_floppy1.toUtf8().constData();

}

void MainWindow::on_Chose_file_PC98_floppy2_clicked()
{
    QString filename_PC98_floppy2 = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Floppy disk image (*.fdi);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_PC98_floppy2 = filename_PC98_floppy2.toUtf8().constData();
}

void MainWindow::on_Chose_file_PC98_CDROM_clicked()
{
    QString filename_PC98_CDROM = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Compressed hunk of data (*.chd);;Disk image (*.iso);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_PC98_CDROM = filename_PC98_CDROM.toUtf8().constData();
}

void MainWindow::on_Chose_file_MasterSystem_clicked()
//chosing files and saving file path (Master System)
{
    QString filename_MasterSystem = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Zip files (*.zip);;Cartridge files (*.sms);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_MasterSystem = filename_MasterSystem.toUtf8().constData();
}


void MainWindow::on_Chose_file_MegaDrive_clicked()
//chosing files and saving file path (Genesis/Megadrive)
{
    QString filename_Genesis = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Zip files (*.zip);;Cartridge files (*.md);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_Genesis = filename_Genesis.toUtf8().constData();
}

void MainWindow::on_Chose_file_N64_clicked()
{
    QString filename_N64 = QFileDialog::getOpenFileName(
                this,
                tr("Chose Game"),
                "/home",
                "Zip files (*.zip);;Cartridge files (*.z64);;All files (*.*)"  // determines types of files and name to display in window
                );
    ROM_path_N64 = filename_N64.toUtf8().constData();
}


// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_launch_MAME_clicked()  // Launcher for MAME
{
    char cmd[]="mame";
    system(cmd);
}


void MainWindow::on_Launcher_Button_clicked()
{

    if(ui->CRT_Shader->isChecked()){
        CRT_Shader =" -glsl_shader_mame0 shader/Lottes_CRT";
    }


        if (ui->radioButton_NTSC_USA->isChecked()) {
             region = "psu";
        }

        if (ui->radioButton_PAL_EU->isChecked()) {
             region = "pse";
        }

        if (ui->radioButton_NTSC_Japan->isChecked()) {
             region = "psj";
        }


        std::string machine_cmd = "mame ";                  // run machine command linux version
        //std::string rompath = " -rompath roms/ ";         // assumes the drivers are placed in a "drivers" folder on the same directory as the mame executable
        std::string file1locale = ROM_path;                 // Path pointed in "ROM1"
        std::string load_cd = (" -cdrm ");                  // tell mame to load files onto cd tray
        PS_memcard1 = " -memc1 ~/.mame/memcard/psx.mc1";    // command and location of memory card 1
        PS_memcard2 = " -memc2 ~/.mame/memcard/psx.mc2";    // command and location of memory card 2
        std::string PS_command = machine_cmd + region + PS_memcard1 + PS_memcard2 + load_cd + "'"+ file1locale + "'"; // pass "'" before and after file path to send a proper quoted path to console
        const char *newcmd = PS_command.c_str();
        system(newcmd);                                     // send whole command to OS command line
        std::cout << newcmd << "\n";                        //check parsed system command

}


void MainWindow::on_Launcher_Button_Saturn_clicked()
{
    if (ui->radioButton_NTSC_USA_Saturn->isChecked()) {
         region_Saturn = "saturn";
    }

    if (ui->radioButton_PAL_EU_Saturn->isChecked()) {
         region_Saturn = "saturneu";
    }

    if (ui->radioButton_NTSC_Japan_Saturn->isChecked()) {
         region_Saturn = "saturnjp";
    }

    std::string machine_cmd = "mame ";                      // run machine command linux version
    std::string load_cd = (" -cdrm ");                      // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_Saturn;              // Path pointed in "ROM1"
    std::string command = machine_cmd + region_Saturn + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *Saturn_command = command.c_str();
    system(Saturn_command);
}



void MainWindow::on_Launcher_Button_SNES_clicked()
{
    std::string machine_cmd = "mame snes";                  // run machine command linux version
    std::string load_cd = (" -cartridge ");                 // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_SNES;                // Path pointed in "ROM1"
    std::string command = machine_cmd + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *SNES_command = command.c_str();
    system(SNES_command);

}



void MainWindow::on_Launcher_Button_NES_clicked()
{
    std::string machine_cmd = "mame nes";                   // run machine command linux version
    std::string load_cd = (" -cartridge ");                 // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_NES;                 // Path pointed in "ROM1"
    std::string command = machine_cmd + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *NES_command = command.c_str();
    system(NES_command);

}


void MainWindow::on_Launcher_Button_PC98_2_clicked()
{
    std::string machine_cmd = "mame pc8801ma2";             // run machine command linux version
    std::string load_foppy1 = (" -flop1 ");                 // tell mame to load files onto floppy disk tray
    std::string load_floppy2 = (" -flop2 ");                // tell mame to load files onto floppy disk tray
    std::string floppy1_locale = ROM_path_PC88_floppy1;     // Path pointed in "Floppy1"
    std::string floppy2_locale = ROM_path_PC88_floppy2;     // Path pointed in "Floppy2"
    std::string command = machine_cmd + load_foppy1 + "'"+ floppy1_locale + "'" + load_floppy2 + "'"+ floppy2_locale + "'" ;    // pass "'" before and after file path to send a proper quoted path to console
    const char *PC88_command = command.c_str();
    system(PC88_command);
}


void MainWindow::on_Launcher_Button_PC98_clicked() // PC98 launcher (NES_2 is a mistake)
{
    std::string machine_cmd = "mame pc9821ce2";             // run machine command linux version
    std::string load_foppy1 = (" -flop1 ");                 // tell mame to load files onto floppy disk tray
    std::string load_floppy2 = (" -flop2 ");                // tell mame to load files onto floppy disk tray
    std::string load_cd = (" -cdrm ");                      // tell mame to load files onto cd tray
    std::string CD_locale = ROM_path_PC98_CDROM;            // Path pointed in "CD_ROM"
    std::string floppy1_locale = ROM_path_PC98_floppy1;     // Path pointed in "Floppy1"
    std::string floppy2_locale = ROM_path_PC98_floppy2;     // Path pointed in "Floppy2"
    std::string command = machine_cmd + load_foppy1 + "'"+ floppy1_locale + "'" + load_floppy2 + "'"+ floppy2_locale + "'" + load_cd + "'"+ CD_locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *PC98_command = command.c_str();
    system(PC98_command);

}

void MainWindow::on_Launcher_Button_MasterSystem_clicked()
{
    std::string machine_cmd = "mame sms";                   // run machine command linux version
    std::string load_cd = (" -cartridge ");                 // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_MasterSystem;        // Path pointed in "ROM1"
    std::string command = machine_cmd + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *MasterSystem_command = command.c_str();
    system(MasterSystem_command);
}


void MainWindow::on_Launcher_Button_Megadrive_clicked()
{
    std::string machine_cmd = "mame genesis";               // run machine command linux version
    std::string load_cd = (" -cartridge ");                 // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_Genesis;             // Path pointed in "ROM1"
    std::string command = machine_cmd + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *Genesis_command = command.c_str();
    system(Genesis_command);
}


void MainWindow::on_Launcher_Button_N64_clicked()
{
    std::string machine_cmd = "mame n64";                   // run machine command linux version
    std::string load_cd = (" -cartridge ");                 // tell mame to load files onto cd tray
    std::string file1locale = ROM_path_N64;                 // Path pointed in "ROM1"
    std::string command = machine_cmd + load_cd + "'"+ file1locale + "'";    // pass "'" before and after file path to send a proper quoted path to console
    const char *N64_command = command.c_str();
    system(N64_command);
}


// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////


// Menu Bar section
void MainWindow::on_actionAbout_2_triggered()
{
    QMessageBox::information(this,"About","Developed by Rugaliz 2019");
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
// //////////////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////////////








