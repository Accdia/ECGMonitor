#ifndef FORMSETUART_H
#define FORMSETUART_H

#include <QWidget>
#include "global.h"
#include "QSerialPort"
#include "QSerialPortInfo"

namespace Ui {
class FormSetUART;
}

class FormSetUART : public QWidget
{
    Q_OBJECT

public:
    explicit FormSetUART(QWidget *parent = nullptr);
    ~FormSetUART();

signals:
    void uartSetData(QString portNum, int baudRate, int dataBits,
                     int stopBits, int parity, bool isOpened);

private slots:
    void on_openUARTButton_clicked();

private:
    Ui::FormSetUART *ui;
};

#endif // FORMSETUART_H
