//
// Created by Administrator on 2017-5-19.
//

#include "lineedit.h"

void LineEdit::enterEvent(QEvent *event)
{

    this->selectAll();
    this->setFocus();

}

