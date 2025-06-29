#ifndef NUMBERFORM_H
#define NUMBERFORM_H

#include <QWidget>

namespace Ui {
class NumberForm;
}

class NumberForm : public QWidget
{
    Q_OBJECT

public:
    static NumberForm* getInstance(QWidget *p);

    explicit NumberForm(QWidget *parent = nullptr);
    ~NumberForm();

    void ShowBar(QWidget *p);

private slots:
    void SlotButtonClicked(int id);

protected:

    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void enterEvent(QEvent *event) override;

private:
    Ui::NumberForm *ui;
    QWidget *_text_wgt;

};

#endif // NUMBERFORM_H
