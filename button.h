//
// Created by Administrator on 2017-5-19.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
//#include <QtWidgets/QPushButton>

class Button : public QPushButton
{

protected:
    void enterEvent(QEvent *event);

};


#endif //BUTTON_H
