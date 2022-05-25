#include "formnibp.h"
#include "ui_formnibp.h"

FormNIBP::FormNIBP(QString mode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormNIBP)
{
    ui->setupUi(this);

    //设置窗体显示在最前，Qt::WindowStaysOnTopHint
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("血压参数设置"));

    mNIBPMode = mode;
    ui->nibpModeComboBox->setCurrentText(mNIBPMode); //显示上次选择的模式
}

FormNIBP::~FormNIBP()
{
    delete ui;
}

void FormNIBP::on_startMeasButton_clicked()
{
    QList<uchar> dataList;
    dataList.append(0x14);
    dataList.append(0x80);

    for(int i = 0; i < 8; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;

    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendNIBPData(data));

    this->close();
}

void FormNIBP::on_stopMeasButton_clicked()
{
    QList<uchar> dataList;
    dataList.append(0x14);
    dataList.append(0x81);

    for (int i = 0; i < 8; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;

    mPackUnpack.packData(dataList);

    for (int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendNIBPData(data));

    this->close();
}

void FormNIBP::on_nibpModeComboBox_currentIndexChanged(const QString &arg1)
{
    mNIBPMode = ui->nibpModeComboBox->currentText();
    emit(sendNIBPSetData(mNIBPMode));
}
