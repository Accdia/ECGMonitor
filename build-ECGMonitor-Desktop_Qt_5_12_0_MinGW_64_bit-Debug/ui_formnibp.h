/********************************************************************************
** Form generated from reading UI file 'formnibp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMNIBP_H
#define UI_FORMNIBP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormNIBP
{
public:
    QLabel *nibpModeLabel;
    QPushButton *startMeasButton;
    QPushButton *stopMeasButton;
    QComboBox *nibpModeComboBox;

    void setupUi(QWidget *FormNIBP)
    {
        if (FormNIBP->objectName().isEmpty())
            FormNIBP->setObjectName(QString::fromUtf8("FormNIBP"));
        FormNIBP->resize(292, 170);
        nibpModeLabel = new QLabel(FormNIBP);
        nibpModeLabel->setObjectName(QString::fromUtf8("nibpModeLabel"));
        nibpModeLabel->setGeometry(QRect(20, 30, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        nibpModeLabel->setFont(font);
        startMeasButton = new QPushButton(FormNIBP);
        startMeasButton->setObjectName(QString::fromUtf8("startMeasButton"));
        startMeasButton->setGeometry(QRect(20, 100, 81, 41));
        startMeasButton->setFont(font);
        stopMeasButton = new QPushButton(FormNIBP);
        stopMeasButton->setObjectName(QString::fromUtf8("stopMeasButton"));
        stopMeasButton->setGeometry(QRect(180, 100, 91, 41));
        stopMeasButton->setFont(font);
        nibpModeComboBox = new QComboBox(FormNIBP);
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->addItem(QString());
        nibpModeComboBox->setObjectName(QString::fromUtf8("nibpModeComboBox"));
        nibpModeComboBox->setGeometry(QRect(130, 30, 141, 31));
        nibpModeComboBox->setFont(font);

        retranslateUi(FormNIBP);

        QMetaObject::connectSlotsByName(FormNIBP);
    } // setupUi

    void retranslateUi(QWidget *FormNIBP)
    {
        FormNIBP->setWindowTitle(QApplication::translate("FormNIBP", "Form", nullptr));
        nibpModeLabel->setText(QApplication::translate("FormNIBP", "\346\265\213\351\207\217\346\250\241\345\274\217\357\274\232", nullptr));
        startMeasButton->setText(QApplication::translate("FormNIBP", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        stopMeasButton->setText(QApplication::translate("FormNIBP", "\345\201\234\346\255\242\346\265\213\351\207\217", nullptr));
        nibpModeComboBox->setItemText(0, QApplication::translate("FormNIBP", "\346\211\213\345\212\250", nullptr));
        nibpModeComboBox->setItemText(1, QApplication::translate("FormNIBP", "1\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(2, QApplication::translate("FormNIBP", "2\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(3, QApplication::translate("FormNIBP", "3\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(4, QApplication::translate("FormNIBP", "4\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(5, QApplication::translate("FormNIBP", "5\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(6, QApplication::translate("FormNIBP", "10\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(7, QApplication::translate("FormNIBP", "15\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(8, QApplication::translate("FormNIBP", "30\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(9, QApplication::translate("FormNIBP", "60\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(10, QApplication::translate("FormNIBP", "90\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(11, QApplication::translate("FormNIBP", "120\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(12, QApplication::translate("FormNIBP", "180\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(13, QApplication::translate("FormNIBP", "240\345\210\206\351\222\237", nullptr));
        nibpModeComboBox->setItemText(14, QApplication::translate("FormNIBP", "480\345\210\206\351\222\237", nullptr));

    } // retranslateUi

};

namespace Ui {
    class FormNIBP: public Ui_FormNIBP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMNIBP_H
