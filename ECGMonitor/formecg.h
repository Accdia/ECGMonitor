#ifndef FORMECG_H
#define FORMECG_H

#include <QWidget>
#include "packunpack.h"

namespace Ui {
class FormECG;
}

class FormECG : public QWidget
{
    Q_OBJECT

public:
    explicit FormECG(int lead1,int gain1, int lead2, int gain2, QWidget *parent = nullptr);
    ~FormECG();
    
    PackUnpack mPackUnpack;

signals:
    void sendECGData(int lead1, int gain1, int lead2, int gain2, QByteArray data);

private slots:
    void on_ecg1LeadSetComboBox_currentIndexChanged(const QString &arg1);
    void on_ecg1GainSetComboBox_currentIndexChanged(const QString &arg1);
    void on_ecg2LeadSetComboBox_currentIndexChanged(const QString &arg1);
    void on_ecg2GainSetComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::FormECG *ui;

    int mECG1Lead;
    int mECG1Gain;
    int mECG2Lead;
    int mECG2Gain;

};

#endif // FORMECG_H
