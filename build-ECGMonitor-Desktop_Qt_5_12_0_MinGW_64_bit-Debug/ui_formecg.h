/********************************************************************************
** Form generated from reading UI file 'formecg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMECG_H
#define UI_FORMECG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormECG
{
public:
    QComboBox *ecg1LeadSetComboBox;
    QLabel *ecg1LeadSetLabel;
    QComboBox *ecg1GainSetComboBox;
    QLabel *ecg1GainSetLabel;
    QComboBox *ecg2LeadSetComboBox;
    QLabel *ecg2LeadSetLabel;
    QComboBox *ecg2GainSetComboBox;
    QLabel *ecg2GainSetLabel;

    void setupUi(QWidget *FormECG)
    {
        if (FormECG->objectName().isEmpty())
            FormECG->setObjectName(QString::fromUtf8("FormECG"));
        FormECG->resize(292, 170);
        ecg1LeadSetComboBox = new QComboBox(FormECG);
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->addItem(QString());
        ecg1LeadSetComboBox->setObjectName(QString::fromUtf8("ecg1LeadSetComboBox"));
        ecg1LeadSetComboBox->setGeometry(QRect(140, 10, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        ecg1LeadSetComboBox->setFont(font);
        ecg1LeadSetLabel = new QLabel(FormECG);
        ecg1LeadSetLabel->setObjectName(QString::fromUtf8("ecg1LeadSetLabel"));
        ecg1LeadSetLabel->setGeometry(QRect(10, 10, 121, 31));
        ecg1LeadSetLabel->setFont(font);
        ecg1GainSetComboBox = new QComboBox(FormECG);
        ecg1GainSetComboBox->addItem(QString());
        ecg1GainSetComboBox->addItem(QString());
        ecg1GainSetComboBox->addItem(QString());
        ecg1GainSetComboBox->addItem(QString());
        ecg1GainSetComboBox->setObjectName(QString::fromUtf8("ecg1GainSetComboBox"));
        ecg1GainSetComboBox->setGeometry(QRect(140, 50, 141, 31));
        ecg1GainSetComboBox->setFont(font);
        ecg1GainSetLabel = new QLabel(FormECG);
        ecg1GainSetLabel->setObjectName(QString::fromUtf8("ecg1GainSetLabel"));
        ecg1GainSetLabel->setGeometry(QRect(10, 50, 121, 31));
        ecg1GainSetLabel->setFont(font);
        ecg2LeadSetComboBox = new QComboBox(FormECG);
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->addItem(QString());
        ecg2LeadSetComboBox->setObjectName(QString::fromUtf8("ecg2LeadSetComboBox"));
        ecg2LeadSetComboBox->setGeometry(QRect(140, 90, 141, 31));
        ecg2LeadSetComboBox->setFont(font);
        ecg2LeadSetLabel = new QLabel(FormECG);
        ecg2LeadSetLabel->setObjectName(QString::fromUtf8("ecg2LeadSetLabel"));
        ecg2LeadSetLabel->setGeometry(QRect(10, 90, 121, 31));
        ecg2LeadSetLabel->setFont(font);
        ecg2GainSetComboBox = new QComboBox(FormECG);
        ecg2GainSetComboBox->addItem(QString());
        ecg2GainSetComboBox->addItem(QString());
        ecg2GainSetComboBox->addItem(QString());
        ecg2GainSetComboBox->addItem(QString());
        ecg2GainSetComboBox->setObjectName(QString::fromUtf8("ecg2GainSetComboBox"));
        ecg2GainSetComboBox->setGeometry(QRect(140, 130, 141, 31));
        ecg2GainSetComboBox->setFont(font);
        ecg2GainSetLabel = new QLabel(FormECG);
        ecg2GainSetLabel->setObjectName(QString::fromUtf8("ecg2GainSetLabel"));
        ecg2GainSetLabel->setGeometry(QRect(10, 130, 121, 31));
        ecg2GainSetLabel->setFont(font);

        retranslateUi(FormECG);

        QMetaObject::connectSlotsByName(FormECG);
    } // setupUi

    void retranslateUi(QWidget *FormECG)
    {
        FormECG->setWindowTitle(QApplication::translate("FormECG", "Form", nullptr));
        ecg1LeadSetComboBox->setItemText(0, QApplication::translate("FormECG", "\342\205\240", nullptr));
        ecg1LeadSetComboBox->setItemText(1, QApplication::translate("FormECG", "\342\205\241", nullptr));
        ecg1LeadSetComboBox->setItemText(2, QApplication::translate("FormECG", "\342\205\242", nullptr));
        ecg1LeadSetComboBox->setItemText(3, QApplication::translate("FormECG", "AVR", nullptr));
        ecg1LeadSetComboBox->setItemText(4, QApplication::translate("FormECG", "AVL", nullptr));
        ecg1LeadSetComboBox->setItemText(5, QApplication::translate("FormECG", "AVF", nullptr));
        ecg1LeadSetComboBox->setItemText(6, QApplication::translate("FormECG", "V", nullptr));

        ecg1LeadSetComboBox->setCurrentText(QApplication::translate("FormECG", "\342\205\240", nullptr));
        ecg1LeadSetLabel->setText(QApplication::translate("FormECG", "ECG1\345\257\274\350\201\224\350\256\276\347\275\256", nullptr));
        ecg1GainSetComboBox->setItemText(0, QApplication::translate("FormECG", "X0.25", nullptr));
        ecg1GainSetComboBox->setItemText(1, QApplication::translate("FormECG", "X0.5", nullptr));
        ecg1GainSetComboBox->setItemText(2, QApplication::translate("FormECG", "X1", nullptr));
        ecg1GainSetComboBox->setItemText(3, QApplication::translate("FormECG", "X2", nullptr));

        ecg1GainSetLabel->setText(QApplication::translate("FormECG", "ECG1\345\242\236\347\233\212\350\256\276\347\275\256", nullptr));
        ecg2LeadSetComboBox->setItemText(0, QApplication::translate("FormECG", "\342\205\240", nullptr));
        ecg2LeadSetComboBox->setItemText(1, QApplication::translate("FormECG", "\342\205\241", nullptr));
        ecg2LeadSetComboBox->setItemText(2, QApplication::translate("FormECG", "\342\205\242", nullptr));
        ecg2LeadSetComboBox->setItemText(3, QApplication::translate("FormECG", "AVR", nullptr));
        ecg2LeadSetComboBox->setItemText(4, QApplication::translate("FormECG", "AVL", nullptr));
        ecg2LeadSetComboBox->setItemText(5, QApplication::translate("FormECG", "AVF", nullptr));
        ecg2LeadSetComboBox->setItemText(6, QApplication::translate("FormECG", "V", nullptr));

        ecg2LeadSetComboBox->setCurrentText(QApplication::translate("FormECG", "\342\205\240", nullptr));
        ecg2LeadSetLabel->setText(QApplication::translate("FormECG", "ECG2\345\257\274\350\201\224\350\256\276\347\275\256", nullptr));
        ecg2GainSetComboBox->setItemText(0, QApplication::translate("FormECG", "X0.25", nullptr));
        ecg2GainSetComboBox->setItemText(1, QApplication::translate("FormECG", "X0.5", nullptr));
        ecg2GainSetComboBox->setItemText(2, QApplication::translate("FormECG", "X1", nullptr));
        ecg2GainSetComboBox->setItemText(3, QApplication::translate("FormECG", "X2", nullptr));

        ecg2GainSetLabel->setText(QApplication::translate("FormECG", "ECG2\345\242\236\347\233\212\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormECG: public Ui_FormECG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMECG_H
