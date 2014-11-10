/********************************************************************************
** Form generated from reading UI file 'lamp.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAMP_H
#define UI_LAMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TLamp
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *leHostName;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConnect;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnExit;
    QFrame *frame;

    void setupUi(QWidget *TLamp)
    {
        if (TLamp->objectName().isEmpty())
            TLamp->setObjectName(QString::fromUtf8("TLamp"));
        TLamp->resize(413, 281);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TLamp->sizePolicy().hasHeightForWidth());
        TLamp->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(TLamp);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(TLamp);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leHostName = new QLineEdit(TLamp);
        leHostName->setObjectName(QString::fromUtf8("leHostName"));
        leHostName->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(leHostName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnConnect = new QPushButton(TLamp);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        horizontalLayout_2->addWidget(btnConnect);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnExit = new QPushButton(TLamp);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout->addWidget(btnExit);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        frame = new QFrame(TLamp);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(381, 201));
        frame->setMaximumSize(QSize(381, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(TLamp);
        QObject::connect(btnConnect, SIGNAL(clicked()), TLamp, SLOT(slotBtnConnectClicked()));
        QObject::connect(btnExit, SIGNAL(clicked()), TLamp, SLOT(slotBtnExitClicked()));

        QMetaObject::connectSlotsByName(TLamp);
    } // setupUi

    void retranslateUi(QWidget *TLamp)
    {
        TLamp->setWindowTitle(QApplication::translate("TLamp", "\320\242\320\265\321\201\321\202\320\276\320\262\320\276\320\265 \320\267\320\260\320\264\320\260\320\275\320\270\320\265 \"\320\244\320\276\320\275\320\260\321\200\321\214\"", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TLamp", "\320\245\320\276\321\201\321\202:\320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        btnConnect->setText(QApplication::translate("TLamp", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("TLamp", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TLamp: public Ui_TLamp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAMP_H
