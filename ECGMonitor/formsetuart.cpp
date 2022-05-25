#include "formsetuart.h"
#include "ui_formsetuart.h"

FormSetUART::FormSetUART(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSetUART)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowCloseButtonHint);
    setWindowTitle(tr("串口设置"));

    if(gUARTOpenFlag)
    {
        ui->openUARTButton->setText(tr("关闭串口"));
        ui->uartStsLabel->setPixmap(QPixmap(":/new/prefix1/image/open.png"));
    }
    else
    {
        ui->openUARTButton->setText(tr("打开串口"));
        ui->uartStsLabel->setPixmap(QPixmap(":/new/prefix1/image/close.png"));
    }

    ui->uartNumComboBox->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->uartNumComboBox->addItem(info.portName());
    }
}

FormSetUART::~FormSetUART()
{
    delete ui;
}

void FormSetUART::on_openUARTButton_clicked()
{
    emit(uartSetData(ui->uartNumComboBox->currentText(), ui->baudRateComboBox->currentText().toInt(),
                     ui->dataBitsComboBox->currentIndex(), ui->stopBitsComboBox->currentIndex(),
                     ui->parityComboBox->currentIndex(), gUARTOpenFlag));
    close();
}
