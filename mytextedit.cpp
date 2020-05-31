#include "mytextedit.h"

MyTextEdit::MyTextEdit(QWidget *parent):
     QTextEdit(parent)
{

}

void MyTextEdit::keyPressEvent(QKeyEvent *e){
    //do stuff with the key event
    if(e->key() == Qt::Key_Enter)
        {
//            d.on_pushButton_clicked();
        }
}
