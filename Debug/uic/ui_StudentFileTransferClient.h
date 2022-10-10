/********************************************************************************
** Form generated from reading UI file 'StudentFileTransferClient.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTFILETRANSFERCLIENT_H
#define UI_STUDENTFILETRANSFERCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentFileTransferClientClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_close;
    QLabel *lab_title;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btn_connect;
    QLineEdit *line_ip;
    QLineEdit *line_seat;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_path;
    QLineEdit *line_path;
    QPushButton *btn_test;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudentFileTransferClientClass)
    {
        if (StudentFileTransferClientClass->objectName().isEmpty())
            StudentFileTransferClientClass->setObjectName(QStringLiteral("StudentFileTransferClientClass"));
        StudentFileTransferClientClass->resize(376, 185);
        StudentFileTransferClientClass->setMinimumSize(QSize(376, 185));
        StudentFileTransferClientClass->setMaximumSize(QSize(376, 185));
        centralWidget = new QWidget(StudentFileTransferClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 357, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btn_close = new QPushButton(layoutWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        verticalLayout->addWidget(btn_close);

        lab_title = new QLabel(layoutWidget);
        lab_title->setObjectName(QStringLiteral("lab_title"));

        verticalLayout->addWidget(lab_title);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        btn_connect = new QPushButton(layoutWidget);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));

        gridLayout->addWidget(btn_connect, 1, 0, 1, 1);

        line_ip = new QLineEdit(layoutWidget);
        line_ip->setObjectName(QStringLiteral("line_ip"));

        gridLayout->addWidget(line_ip, 1, 1, 1, 1);

        line_seat = new QLineEdit(layoutWidget);
        line_seat->setObjectName(QStringLiteral("line_seat"));

        gridLayout->addWidget(line_seat, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_path = new QPushButton(layoutWidget);
        btn_path->setObjectName(QStringLiteral("btn_path"));

        horizontalLayout->addWidget(btn_path);

        line_path = new QLineEdit(layoutWidget);
        line_path->setObjectName(QStringLiteral("line_path"));

        horizontalLayout->addWidget(line_path);


        verticalLayout->addLayout(horizontalLayout);

        btn_test = new QPushButton(centralWidget);
        btn_test->setObjectName(QStringLiteral("btn_test"));
        btn_test->setGeometry(QRect(334, 70, 111, 23));
        StudentFileTransferClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StudentFileTransferClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StudentFileTransferClientClass->setStatusBar(statusBar);

        retranslateUi(StudentFileTransferClientClass);

        QMetaObject::connectSlotsByName(StudentFileTransferClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudentFileTransferClientClass)
    {
        StudentFileTransferClientClass->setWindowTitle(QApplication::translate("StudentFileTransferClientClass", "StudentFileTransferClient", nullptr));
        btn_close->setText(QApplication::translate("StudentFileTransferClientClass", "\345\205\263\351\227\255\347\250\213\345\272\217", nullptr));
        lab_title->setText(QApplication::translate("StudentFileTransferClientClass", "\345\260\235\350\257\225\350\277\236\346\216\245\344\270\255...", nullptr));
        label->setText(QApplication::translate("StudentFileTransferClientClass", "Ip", nullptr));
        btn_connect->setText(QApplication::translate("StudentFileTransferClientClass", "\350\277\236\346\216\245", nullptr));
        label_2->setText(QApplication::translate("StudentFileTransferClientClass", "\345\272\247\344\275\215\345\217\267", nullptr));
        label_3->setText(QApplication::translate("StudentFileTransferClientClass", "\346\234\254\346\234\272\344\277\241\346\201\257", nullptr));
        label_4->setText(QApplication::translate("StudentFileTransferClientClass", "\346\226\207\344\273\266\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        btn_path->setText(QApplication::translate("StudentFileTransferClientClass", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        btn_test->setText(QApplication::translate("StudentFileTransferClientClass", "\346\265\213\350\257\225\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentFileTransferClientClass: public Ui_StudentFileTransferClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTFILETRANSFERCLIENT_H
