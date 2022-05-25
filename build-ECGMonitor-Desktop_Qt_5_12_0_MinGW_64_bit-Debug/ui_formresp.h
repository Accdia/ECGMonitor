/********************************************************************************
** Form generated from reading UI file 'formresp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMRESP_H
#define UI_FORMRESP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormResp
{
public:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QComboBox *gainComboBox;
    QLabel *gainSetLabel;

    void setupUi(QWidget *FormResp)
    {
        if (FormResp->objectName().isEmpty())
            FormResp->setObjectName(QString::fromUtf8("FormResp"));
        FormResp->resize(292, 170);
        okButton = new QPushButton(FormResp);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(30, 110, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        okButton->setFont(font);
        cancelButton = new QPushButton(FormResp);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(160, 110, 101, 41));
        cancelButton->setFont(font);
        gainComboBox = new QComboBox(FormResp);
        gainComboBox->addItem(QString());
        gainComboBox->addItem(QString());
        gainComboBox->addItem(QString());
        gainComboBox->addItem(QString());
        gainComboBox->addItem(QString());
        gainComboBox->setObjectName(QString::fromUtf8("gainComboBox"));
        gainComboBox->setGeometry(QRect(130, 30, 131, 31));
        gainComboBox->setFont(font);
        gainSetLabel = new QLabel(FormResp);
        gainSetLabel->setObjectName(QString::fromUtf8("gainSetLabel"));
        gainSetLabel->setGeometry(QRect(30, 30, 91, 31));
        gainSetLabel->setFont(font);

        retranslateUi(FormResp);

        QMetaObject::connectSlotsByName(FormResp);
    } // setupUi

    void retranslateUi(QWidget *FormResp)
    {
        FormResp->setWindowTitle(QApplication::translate("FormResp", "Form", nullptr));
        okButton->setText(QApplication::translate("FormResp", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QApplication::translate("FormResp", "\345\217\226\346\266\210", nullptr));
        gainComboBox->setItemText(0, QApplication::translate("FormResp", "X0.25", nullptr));
        gainComboBox->setItemText(1, QApplication::translate("FormResp", "X0.5", nullptr));
        gainComboBox->setItemText(2, QApplication::translate("FormResp", "X1", nullptr));
        gainComboBox->setItemText(3, QApplication::translate("FormResp", "X2", nullptr));
        gainComboBox->setItemText(4, QApplication::translate("FormResp", "X4", nullptr));

        gainSetLabel->setText(QApplication::translate("FormResp", "\345\242\236\347\233\212\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormResp: public Ui_FormResp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMRESP_H
