#ifndef FORMTEMP_H
#define FORMTEMP_H

#include <QWidget>
#include "packunpack.h"

namespace Ui {
class FormTemp;
}

class FormTemp : public QWidget
{
    Q_OBJECT

public:
    explicit FormTemp(QString prbType, QWidget *parent = nullptr);
    ~FormTemp();

    PackUnpack mPackUnpack;

signals:
    void sendTempData(QString prbType, QByteArray data);

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();
    void on_prbTypeComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::FormTemp *ui;

    QString mPrbType;

    //数据处理方法
    void procUARTData();
    void dealRcvPackData();
};

#endif // FORMTEMP_H
