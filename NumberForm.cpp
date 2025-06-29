#include "NumberForm.h"
#include "ui_NumberForm.h"

#include <QDebug>
#include <QButtonGroup>
#include <QLineEdit>

NumberForm *NumberForm::getInstance(QWidget* p)
{
    static NumberForm *instance = new NumberForm(p);
    static QWidget *activeWindow = p;
    if(instance && p != activeWindow)
    {
        delete instance;
        instance = new NumberForm(p);
    }
    activeWindow = p;
    return instance;
}

NumberForm::NumberForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::NoFocus); // 禁止获取焦点
    this->setStyleSheet("QWidget#widget{border: 2px solid #567487;}");

    QButtonGroup *groupButton = new QButtonGroup(this);
    groupButton->addButton(ui->pushButton0, 0);
    groupButton->addButton(ui->pushButton1, 1);
    groupButton->addButton(ui->pushButton2, 2);
    groupButton->addButton(ui->pushButton3, 3);
    groupButton->addButton(ui->pushButton4, 4);
    groupButton->addButton(ui->pushButton5, 5);
    groupButton->addButton(ui->pushButton6, 6);
    groupButton->addButton(ui->pushButton7, 7);
    groupButton->addButton(ui->pushButton8, 8);
    groupButton->addButton(ui->pushButton9, 9);
    groupButton->addButton(ui->pushButtonD, 10);
    groupButton->addButton(ui->pushButtonO, 11);
    groupButton->addButton(ui->pushButtonT, 12);
    groupButton->addButton(ui->pushButtonJ, 12);
    connect(groupButton,  qOverload<int>(&QButtonGroup::buttonClicked), this, &NumberForm::SlotButtonClicked);
}

NumberForm::~NumberForm()
{
    delete ui;
}

void NumberForm::ShowBar(QWidget *p)
{
    _text_wgt = p;
    QPoint pos = p->mapToGlobal(p->mapFromParent(p->pos()));
    pos.setY(pos.y() + p->height());
    this->move(pos);
    this->show();
}

void NumberForm::SlotButtonClicked(int id)
{
    if(id <= 9)
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(_text_wgt);
        if(lineEdit)
        {
            lineEdit->insert(QString::number(id));
            lineEdit->setFocus();

        }
    }

    if(id == 10)
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(_text_wgt);
        if(lineEdit)
        {
            lineEdit->backspace();
            lineEdit->setFocus();
        }
    }
}

void NumberForm::focusInEvent(QFocusEvent *event)
{
}

void NumberForm::enterEvent(QEvent *event)
{

}
