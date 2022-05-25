#ifndef FORMSPO2_H
#define FORMSPO2_H

#include <QWidget>
#include "packunpack.h"

namespace Ui {
class FormSPO2;
}

class FormSPO2 : public QWidget
{
    Q_OBJECT

public:
    explicit FormSPO2(QString sens, QWidget *parent = nullptr);
    ~FormSPO2();

    PackUnpack mPackUnpack;

signals:
    void sendSPO2Data(QString sens, QByteArray data);

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void on_sensComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::FormSPO2 *ui;

    QString mSPO2Sens;
};

#endif // FORMSPO2_H
