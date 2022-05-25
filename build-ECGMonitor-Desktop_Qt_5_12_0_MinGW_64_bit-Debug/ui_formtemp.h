/********************************************************************************
** Form generated from reading UI file 'formtemp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTEMP_H
#define UI_FORMTEMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTemp
{
public:
    QLabel *label;
    QComboBox *prbTypeComboBox;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *FormTemp)
    {
        if (FormTemp->objectName().isEmpty())
            FormTemp->setObjectName(QString::fromUtf8("FormTemp"));
        FormTemp->resize(292, 170);
        label = new QLabel(FormTemp);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        label->setFont(font);
        prbTypeComboBox = new QComboBox(FormTemp);
        prbTypeComboBox->addItem(QString());
        prbTypeComboBox->addItem(QString());
        prbTypeComboBox->setObjectName(QString::fromUtf8("prbTypeComboBox"));
        prbTypeComboBox->setGeometry(QRect(130, 30, 111, 31));
        prbTypeComboBox->setFont(font);
        okButton = new QPushButton(FormTemp);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(30, 100, 101, 41));
        okButton->setFont(font);
        cancelButton = new QPushButton(FormTemp);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(160, 100, 101, 41));
        cancelButton->setFont(font);

        retranslateUi(FormTemp);

        QMetaObject::connectSlotsByName(FormTemp);
    } // setupUi

    void retranslateUi(QWidget *FormTemp)
    {
        FormTemp->setWindowTitle(QApplication::translate("FormTemp", "Form", nullptr));
        label->setText(QApplication::translate("FormTemp", "\346\216\242\345\244\264\347\261\273\345\236\213\357\274\232", nullptr));
        prbTypeComboBox->setItemText(0, QApplication::translate("FormTemp", " YSI", nullptr));
        prbTypeComboBox->setItemText(1, QApplication::translate("FormTemp", "CY-FI", nullptr));

        okButton->setText(QApplication::translate("FormTemp", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("FormTemp", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTemp: public Ui_FormTemp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTEMP_H
