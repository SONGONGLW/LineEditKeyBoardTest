#include "MLineEdit.h"

MLineEdit::MLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);
}

void MLineEdit::mousePressEvent(QMouseEvent *e)
{
    QLineEdit::mousePressEvent(e);
}

void MLineEdit::mouseReleaseEvent(QMouseEvent *e)
{
    QLineEdit::mouseReleaseEvent(e);
    NumberForm::getInstance(this)->ShowBar(this);
    this->insert("");
    this->setFocus();
}

void MLineEdit::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);
}
