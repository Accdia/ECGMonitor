#ifndef FORMNIBP_H
#define FORMNIBP_H

#include <QWidget>
#include "packunpack.h"

namespace Ui {
class FormNIBP;
}

class FormNIBP : public QWidget
{
    Q_OBJECT

public:
    explicit FormNIBP(QString mode, QWidget *parent = nullptr);
    ~FormNIBP();

    PackUnpack mPackUnpack;

signals:
    void sendNIBPSetData(QString mode);
    void sendNIBPData(QByteArray data);

private slots:
    void on_startMeasButton_clicked();
    void on_stopMeasButton_clicked();
    void on_nibpModeComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::FormNIBP *ui;

    QString mNIBPMode;
};

#endif // FORMNIBP_H
