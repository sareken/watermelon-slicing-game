/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_kesilen_sayisi;
    QLabel *label_kacirilan_sayisi;
    QLabel *label_sure;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1350, 750);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 100, 1350, 750));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/arkaplan/back.jpg);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(660, 20, 211, 24));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label_3->setFont(font);
        label_kesilen_sayisi = new QLabel(centralwidget);
        label_kesilen_sayisi->setObjectName(QString::fromUtf8("label_kesilen_sayisi"));
        label_kesilen_sayisi->setGeometry(QRect(860, 20, 61, 24));
        QPalette palette;
        QBrush brush(QColor(0, 249, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        label_kesilen_sayisi->setPalette(palette);
        label_kesilen_sayisi->setFont(font);
        label_kacirilan_sayisi = new QLabel(centralwidget);
        label_kacirilan_sayisi->setObjectName(QString::fromUtf8("label_kacirilan_sayisi"));
        label_kacirilan_sayisi->setGeometry(QRect(880, 60, 31, 24));
        QPalette palette1;
        QBrush brush1(QColor(255, 38, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        label_kacirilan_sayisi->setPalette(palette1);
        label_kacirilan_sayisi->setFont(font);
        label_sure = new QLabel(centralwidget);
        label_sure->setObjectName(QString::fromUtf8("label_sure"));
        label_sure->setGeometry(QRect(100, 30, 71, 24));
        QPalette palette2;
        QBrush brush2(QColor(4, 51, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        label_sure->setPalette(palette2);
        label_sure->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(660, 60, 229, 24));
        label_4->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 70, 26));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Kesilen Karpuz Say\304\261s\304\261:", nullptr));
        label_kesilen_sayisi->setText(QString());
        label_kacirilan_sayisi->setText(QString());
        label_sure->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Ka\303\247\304\261r\304\261lan Karpuz Say\304\261s\304\261:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "S\303\274re:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
