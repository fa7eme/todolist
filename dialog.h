#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
#include <fstream>

//#include "mytextedit.h"

using namespace std;

namespace Ui {
class TodoList;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void writeToFile(QString data);
    void readFromFile();
    void removeLine(char const* sourcefile,int line);
    int countLine(char const* sourcefile);

private slots:
    void on_pushButton_clicked();
    void on_pbRemove_clicked();

private:
    Ui::TodoList *ui;
    ofstream ofile;
    fstream ifile;

};

#endif // DIALOG_H




