//
// Created by Administrator on 2017-5-19.
//

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit : public QLineEdit
{

protected:
    void enterEvent(QEvent *event);

};


#endif //LINEEDIT_H
