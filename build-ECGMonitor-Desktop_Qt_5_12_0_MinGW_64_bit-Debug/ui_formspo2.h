/********************************************************************************
** Form generated from reading UI file 'formspo2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSPO2_H
#define UI_FORMSPO2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSPO2
{
public:
    QLabel *countSensLabel;
    QComboBox *sensComboBox;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *FormSPO2)
    {
        if (FormSPO2->objectName().isEmpty())
            FormSPO2->setObjectName(QString::fromUtf8("FormSPO2"));
        FormSPO2->resize(292, 170);
        countSensLabel = new QLabel(FormSPO2);
        countSensLabel->setObjectName(QString::fromUtf8("countSensLabel"));
        countSensLabel->setGeometry(QRect(20, 30, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        countSensLabel->setFont(font);
        sensComboBox = new QComboBox(FormSPO2);
        sensComboBox->addItem(QString());
        sensComboBox->addItem(QString());
        sensComboBox->addItem(QString());
        sensComboBox->setObjectName(QString::fromUtf8("sensComboBox"));
        sensComboBox->setGeometry(QRect(130, 30, 141, 31));
        sensComboBox->setFont(font);
        okButton = new QPushButton(FormSPO2);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(20, 100, 91, 41));
        okButton->setFont(font);
        cancelButton = new QPushButton(FormSPO2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(180, 100, 91, 41));
        cancelButton->setFont(font);

        retranslateUi(FormSPO2);

        QMetaObject::connectSlotsByName(FormSPO2);
    } // setupUi

    void retranslateUi(QWidget *FormSPO2)
    {
        FormSPO2->setWindowTitle(QApplication::translate("FormSPO2", "Form", nullptr));
        countSensLabel->setText(QApplication::translate("FormSPO2", "\350\256\241\347\256\227\347\201\265\346\225\217\345\272\246\357\274\232", nullptr));
        sensComboBox->setItemText(0, QApplication::translate("FormSPO2", "\351\253\230", nullptr));
        sensComboBox->setItemText(1, QApplication::translate("FormSPO2", "\344\270\255", nullptr));
        sensComboBox->setItemText(2, QApplication::translate("FormSPO2", "\344\275\216", nullptr));

        okButton->setText(QApplication::translate("FormSPO2", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("FormSPO2", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormSPO2: public Ui_FormSPO2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSPO2_H
