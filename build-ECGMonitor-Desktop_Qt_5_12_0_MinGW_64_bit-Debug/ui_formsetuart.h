/********************************************************************************
** Form generated from reading UI file 'formsetuart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETUART_H
#define UI_FORMSETUART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSetUART
{
public:
    QLabel *uartNumLabel;
    QComboBox *uartNumComboBox;
    QLabel *baudRateLabel;
    QComboBox *baudRateComboBox;
    QLabel *dataBitsLabel;
    QComboBox *dataBitsComboBox;
    QLabel *stopBitsLabel;
    QComboBox *stopBitsComboBox;
    QLabel *parityLabel;
    QComboBox *parityComboBox;
    QPushButton *openUARTButton;
    QLabel *uartStsLabel;

    void setupUi(QWidget *FormSetUART)
    {
        if (FormSetUART->objectName().isEmpty())
            FormSetUART->setObjectName(QString::fromUtf8("FormSetUART"));
        FormSetUART->resize(433, 415);
        uartNumLabel = new QLabel(FormSetUART);
        uartNumLabel->setObjectName(QString::fromUtf8("uartNumLabel"));
        uartNumLabel->setGeometry(QRect(31, 20, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(14);
        uartNumLabel->setFont(font);
        uartNumComboBox = new QComboBox(FormSetUART);
        uartNumComboBox->setObjectName(QString::fromUtf8("uartNumComboBox"));
        uartNumComboBox->setGeometry(QRect(160, 20, 231, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font1.setPointSize(14);
        uartNumComboBox->setFont(font1);
        baudRateLabel = new QLabel(FormSetUART);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));
        baudRateLabel->setGeometry(QRect(31, 80, 121, 41));
        baudRateLabel->setFont(font);
        baudRateComboBox = new QComboBox(FormSetUART);
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->addItem(QString());
        baudRateComboBox->setObjectName(QString::fromUtf8("baudRateComboBox"));
        baudRateComboBox->setGeometry(QRect(160, 80, 231, 41));
        baudRateComboBox->setFont(font1);
        dataBitsLabel = new QLabel(FormSetUART);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));
        dataBitsLabel->setGeometry(QRect(31, 140, 121, 41));
        dataBitsLabel->setFont(font);
        dataBitsComboBox = new QComboBox(FormSetUART);
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->addItem(QString());
        dataBitsComboBox->setObjectName(QString::fromUtf8("dataBitsComboBox"));
        dataBitsComboBox->setGeometry(QRect(160, 140, 231, 41));
        dataBitsComboBox->setFont(font1);
        stopBitsLabel = new QLabel(FormSetUART);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));
        stopBitsLabel->setGeometry(QRect(31, 200, 121, 41));
        stopBitsLabel->setFont(font);
        stopBitsComboBox = new QComboBox(FormSetUART);
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->addItem(QString());
        stopBitsComboBox->setObjectName(QString::fromUtf8("stopBitsComboBox"));
        stopBitsComboBox->setGeometry(QRect(160, 200, 231, 41));
        stopBitsComboBox->setFont(font1);
        parityLabel = new QLabel(FormSetUART);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));
        parityLabel->setGeometry(QRect(31, 260, 121, 41));
        parityLabel->setFont(font);
        parityComboBox = new QComboBox(FormSetUART);
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->addItem(QString());
        parityComboBox->setObjectName(QString::fromUtf8("parityComboBox"));
        parityComboBox->setGeometry(QRect(160, 260, 231, 41));
        parityComboBox->setFont(font1);
        openUARTButton = new QPushButton(FormSetUART);
        openUARTButton->setObjectName(QString::fromUtf8("openUARTButton"));
        openUARTButton->setGeometry(QRect(30, 350, 131, 41));
        openUARTButton->setFont(font);
        uartStsLabel = new QLabel(FormSetUART);
        uartStsLabel->setObjectName(QString::fromUtf8("uartStsLabel"));
        uartStsLabel->setGeometry(QRect(290, 340, 61, 61));
        uartStsLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/close.png")));
        uartStsLabel->setScaledContents(true);

        retranslateUi(FormSetUART);

        baudRateComboBox->setCurrentIndex(4);
        dataBitsComboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(FormSetUART);
    } // setupUi

    void retranslateUi(QWidget *FormSetUART)
    {
        FormSetUART->setWindowTitle(QApplication::translate("FormSetUART", "Form", nullptr));
        uartNumLabel->setText(QApplication::translate("FormSetUART", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        baudRateLabel->setText(QApplication::translate("FormSetUART", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        baudRateComboBox->setItemText(0, QApplication::translate("FormSetUART", "4800", nullptr));
        baudRateComboBox->setItemText(1, QApplication::translate("FormSetUART", "9600", nullptr));
        baudRateComboBox->setItemText(2, QApplication::translate("FormSetUART", "19200", nullptr));
        baudRateComboBox->setItemText(3, QApplication::translate("FormSetUART", "38400", nullptr));
        baudRateComboBox->setItemText(4, QApplication::translate("FormSetUART", "115200", nullptr));

        baudRateComboBox->setCurrentText(QApplication::translate("FormSetUART", "115200", nullptr));
        dataBitsLabel->setText(QApplication::translate("FormSetUART", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        dataBitsComboBox->setItemText(0, QApplication::translate("FormSetUART", "7", nullptr));
        dataBitsComboBox->setItemText(1, QApplication::translate("FormSetUART", "8", nullptr));

        dataBitsComboBox->setCurrentText(QApplication::translate("FormSetUART", "8", nullptr));
        stopBitsLabel->setText(QApplication::translate("FormSetUART", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        stopBitsComboBox->setItemText(0, QApplication::translate("FormSetUART", "1", nullptr));
        stopBitsComboBox->setItemText(1, QApplication::translate("FormSetUART", "2", nullptr));

        parityLabel->setText(QApplication::translate("FormSetUART", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        parityComboBox->setItemText(0, QApplication::translate("FormSetUART", "NONE", nullptr));
        parityComboBox->setItemText(1, QApplication::translate("FormSetUART", "ODD", nullptr));
        parityComboBox->setItemText(2, QApplication::translate("FormSetUART", "EVEN", nullptr));

        openUARTButton->setText(QApplication::translate("FormSetUART", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        uartStsLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormSetUART: public Ui_FormSetUART {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETUART_H
