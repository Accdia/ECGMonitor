#ifndef FORMRESP_H
#define FORMRESP_H

#include <QWidget>
#include "packunpack.h"

namespace Ui {
class FormResp;
}

class FormResp : public QWidget
{
    Q_OBJECT

public:
    explicit FormResp(QString gain, QWidget *parent = nullptr);
    ~FormResp();

    PackUnpack mPackUnpack;

protected:
     void closeEvent(QCloseEvent *event);

signals:
     void sendRespData(QString gain, QByteArray data);

private slots:
     void on_okButton_clicked();
     void on_cancelButton_clicked();
     void on_gainComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::FormResp *ui;

    QString mRespGain;
};

#endif // FORMRESP_H
