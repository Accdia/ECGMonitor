#include "formspo2.h"
#include "ui_formspo2.h"

FormSPO2::FormSPO2(QString sens, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSPO2)
{
    ui->setupUi(this);

    //设置窗体显示在最前，Qt::WindowStaysOnTopHint
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    setWindowTitle(tr("血氧参数设置"));

    mSPO2Sens = sens;
    ui->sensComboBox->setCurrentText(mSPO2Sens);
}

FormSPO2::~FormSPO2()
{
    delete ui;
}

void FormSPO2::on_okButton_clicked()
{
    this->close();
}

void FormSPO2::on_cancelButton_clicked()
{
    this->close();
}

void FormSPO2::on_sensComboBox_currentIndexChanged(const QString &arg1)
{
    mSPO2Sens = ui->sensComboBox->currentText();

    int spo2Sens = ui->sensComboBox->currentIndex();

    if(spo2Sens < 0)
    {
        return;
    }

    uchar sensData = spo2Sens + 1;   //计算灵敏度：1-高；2-中；3-低
    QList<uchar> dataList;
    dataList.append(0x80);				//二级ID-0x80
    dataList.append(sensData);
    dataList.insert(0, 0x13);			//模块ID-0x13
    mPackUnpack.packData(dataList);

    int len = dataList.count();
    QByteArray data;
    for(int i = 0; i < len; i++)
    {
        data.append(dataList.at(i));
    }

    emit(sendSPO2Data(mSPO2Sens, data));
}
