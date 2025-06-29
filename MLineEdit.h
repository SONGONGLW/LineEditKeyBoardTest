#ifndef MLINEEDIT_H
#define MLINEEDIT_H

#include <QLineEdit>

#include "NumberForm.h"

class MLineEdit : public QLineEdit
{
public:
    explicit MLineEdit(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *) override;
    virtual void mouseReleaseEvent(QMouseEvent *) override;


protected:
    virtual void focusInEvent (QFocusEvent * event);

};

#endif // MLINEEDIT_H
