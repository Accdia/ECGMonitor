#include "formecg.h"
#include "ui_formecg.h"
#include <QDebug>

FormECG::FormECG(int lead1,int gain1, int lead2, int gain2, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormECG)
{
    ui->setupUi(this);

    //设置窗体显示在最前，Qt::WindowStaysOnTopHint
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("心电参数设置"));

    mECG1Lead = lead1;
    mECG1Gain = gain1;
    mECG2Lead = lead2;
    mECG2Gain = gain2;

    ui->ecg1LeadSetComboBox->setCurrentIndex(mECG1Lead);
    ui->ecg1GainSetComboBox->setCurrentIndex(mECG1Gain);
    ui->ecg2LeadSetComboBox->setCurrentIndex(mECG2Lead);
    ui->ecg2GainSetComboBox->setCurrentIndex(mECG2Gain);
}

FormECG::~FormECG()
{
    delete ui;
}

void FormECG::on_ecg1LeadSetComboBox_currentIndexChanged(const QString &arg1)
{
    mECG1Lead = ui->ecg1LeadSetComboBox->currentIndex();

    QList<uchar> dataList;
    dataList.append(0x14);
    dataList.append(0x81);

    uchar ch = (0 << 4) | (mECG1Lead + 1);
    qDebug() << ch;
    dataList.append(ch);

    for(int i = 0; i < 7; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;

    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendECGData(mECG1Lead, mECG1Gain, mECG2Lead, mECG2Gain, data));
}

void FormECG::on_ecg1GainSetComboBox_currentIndexChanged(const QString &arg1)
{
    mECG1Gain = ui->ecg1GainSetComboBox->currentIndex();

    QList<uchar> dataList;
    dataList.append(0x10);
    dataList.append(0x83);
    dataList.append(mECG1Gain);

    for(int i = 0; i < 7; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;
    
    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendECGData(mECG1Lead, mECG1Gain, mECG2Lead, mECG2Gain, data));
}

void FormECG::on_ecg2LeadSetComboBox_currentIndexChanged(const QString &arg1)
{
    mECG2Lead = ui->ecg2LeadSetComboBox->currentIndex();

    QList<uchar> dataList;
    dataList.append(0x10);
    dataList.append(0x81);

    uchar ch = (1 << 4) | (mECG2Lead + 1);
    qDebug() << ch;
    dataList.append(ch);

    for(int i = 0; i < 7; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;
    
    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendECGData(mECG1Lead, mECG1Gain, mECG2Lead, mECG2Gain, data));
}

void FormECG::on_ecg2GainSetComboBox_currentIndexChanged(const QString &arg1)
{
    mECG2Gain = ui->ecg2GainSetComboBox->currentIndex();

    QList<uchar> dataList;
    dataList.append(0x10);
    dataList.append(0x83);
    uchar ch = (1 << 4) | (mECG2Gain);
    qDebug() << ch;

    dataList.append(ch);

    for(int i = 0; i < 7; i++)
    {
        dataList.append(0x00);
    }

    QByteArray data;

    mPackUnpack.packData(dataList);

    for(int i = 0; i < dataList.count(); i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendECGData(mECG1Lead, mECG1Gain, mECG2Lead, mECG2Gain, data));
}
