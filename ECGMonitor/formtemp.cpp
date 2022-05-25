#include "formtemp.h"
#include "ui_formtemp.h"

FormTemp::FormTemp(QString prbType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTemp)
{
    ui->setupUi(this);

    //设置窗体显示在最前，Qt::WindowStaysOnTopHint
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("体温参数设置"));

    mPrbType = prbType;
    ui->prbTypeComboBox->setCurrentText(mPrbType);
}

FormTemp::~FormTemp()
{
    delete ui;
}

void FormTemp::on_okButton_clicked()
{
    this->close();
}

void FormTemp::on_cancelButton_clicked()
{
    this->close();
}

void FormTemp::on_prbTypeComboBox_currentIndexChanged(const QString &arg1)
{
    mPrbType = ui->prbTypeComboBox->currentText();

    int tempPrbType = ui->prbTypeComboBox->currentIndex();

    if(tempPrbType < 0)
    {
        return;
    }

    QList<uchar> dataList;
    QByteArray data;

    dataList.append(0x12);
    dataList.append(0x80);

    switch(tempPrbType)
    {
    case 0:
        for(int i = 0; i < 8; i++)
        {
            dataList.append(0x00);
        }
        break;
    case 1:
        dataList.append(0x01);
        for(int i = 0; i < 7; i++)
        {
            dataList.append(0x00);
        }
        break;
    default:
        break;
    }

    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendTempData(mPrbType, data));
}
