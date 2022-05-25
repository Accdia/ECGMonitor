#include "formresp.h"
#include "ui_formresp.h"
#include <QDebug>

FormResp::FormResp(QString gain, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormResp)
{
    ui->setupUi(this);

    //设置窗体显示在最前，Qt::WindowStaysOnTopHint
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("呼吸参数设置"));

    mRespGain = gain;
    ui->gainComboBox->setCurrentText(mRespGain);
}

FormResp::~FormResp()
{
    delete ui;
}

void FormResp::closeEvent(QCloseEvent *event)

{
    //窗口关闭之前需要的操作
    qDebug() << "close call";
}

void FormResp::on_okButton_clicked()
{
    this->close();
}

void FormResp::on_cancelButton_clicked()
{
    this->close();
}

void FormResp::on_gainComboBox_currentIndexChanged(const QString &arg1)
{
    mRespGain = ui->gainComboBox->currentText();

    int respGain = ui->gainComboBox->currentIndex();

    if(respGain < 0)
    {
        return;
    }

    QList<uchar> dataList;
    uchar sensData = respGain ;   //增益设置：0-*0.25；1-*0.5；2-*1；3-*2；4-*4
    dataList.append(0x80);				//二级ID-0x80
    dataList.append(sensData);

    QByteArray data;
    dataList.insert(0, 0x11);			//一级ID-0x11
    dataList.append(0);
    dataList.append(0);
    dataList.append(0);
    dataList.append(0);
    dataList.append(0);
    dataList.append(0);
    dataList.append(0);
    mPackUnpack.packData(dataList);

    int len = dataList.count();

    for(int i = 0; i < len; i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendRespData(mRespGain, data));
}
