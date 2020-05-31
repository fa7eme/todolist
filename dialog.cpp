#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TodoList)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    readFromFile();
}

Dialog::~Dialog()
{
    ofile.close();
    ifile.close();
    delete ui;
}


void Dialog::writeToFile(QString data)
{
    if(!ofile.is_open())
    {
        ofile.open("todo.txt", ios_base::app /*| ios_base::out*/);
    }
    ofile<<data.toStdString()<<endl;
}

void Dialog::readFromFile()
{
    string data1;
    ifile.open("todo.txt", ios::in);
    while(getline(ifile,data1))
    {
        ui->listWidget->addItem(data1.data());
    }
    ifile.close();
}

//is called whenever Add is clicked
void Dialog::on_pushButton_clicked()
{
    QString a;
    a = ui->textEdit->toPlainText();
    ui->listWidget->addItem(a);
    writeToFile(a);
    ofile.close();
    ui->textEdit->clear();//clearing text box every time
}

void Dialog::on_pbRemove_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    char const *address = "todo.txt";
    removeLine(address,ui->listWidget->currentRow());
    delete item;
}

void Dialog::removeLine(const char *sourcefile, int line){

    char tempPath[100]="temp.txt";
    ifile.open(sourcefile,ios::in);
    if(ifile){
        int numLine=countLine(sourcefile);
        if(numLine<line){
            cout<<"\nNo line to delete\n.";
            return;
        }
        ofile.open(tempPath,ios::out);
        string data;
        int i=0;
        while(getline(ifile,data)){
            if(i != line)
            {
                ofile<<data<<"\n";
            }
            i++;
        }
        ofile.close();
    }
    ifile.close();
    remove(sourcefile);
    rename(tempPath,sourcefile);
}

int Dialog::countLine(const char *sourcefile){

    ifstream infile;
    infile.open(sourcefile,ios::in);
    string data;
    int line=0;
    while(getline(infile,data))
    {
        line++;
    }
    infile.close();
    return line;
}
