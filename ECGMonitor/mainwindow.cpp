#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include <QMessageBox>
#include <QDebug>
#include <QPainter>
#include <QFileDialog>
#include "formtemp.h"
#include "formnibp.h"
#include "formresp.h"
#include "formspo2.h"
#include "formecg.h"

#define byte unsigned char

//模块ID
const uchar DAT_SYS     = 0x01;          //系统信息
const uchar DAT_ECG     = 0x10;          //心电信息
const uchar DAT_RESP    = 0x11;          //呼吸信息
const uchar DAT_TEMP    = 0x12;          //体温信息
const uchar DAT_SPO2    = 0x13;          //血氧信息
const uchar DAT_NIBP    = 0x14;          //无创血压信息

//二级ID
const uchar DAT_TEMP_DATA   = 0x02;  //体温实时数据

const uchar DAT_NIBP_CUFPRE = 0x02;  //无创血压实时数据
const uchar DAT_NIBP_END    = 0x03;  //无创血压测量结束
const uchar DAT_NIBP_RSLT1  = 0x04;  //无创血压测量结果1
const uchar DAT_NIBP_RSLT2  = 0x05;  //无创血压测量结果2

const uchar DAT_RESP_WAVE   = 0x02;  //呼吸波形数据
const uchar DAT_RESP_RR     = 0x03;  //呼吸率

const uchar DAT_SPO2_WAVE   = 0x02;  //血氧波形数据
const uchar DAT_SPO2_DATA   = 0x03;  //血氧数据

const uchar DAT_ECG_WAVE    = 0x02;  //心电波形数据
const uchar DAT_ECG_LEAD    = 0x03;  //心电导联信息
const uchar DAT_ECG_HR      = 0x04;  //心率

const int PACK_QUEUE_CNT = 4000;     //包数量

const int WAVE_X_SIZE = 1081; //图形区域长度
const int WAVE_Y_SIZE = 131;  //图形区域高度

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("生理监护系统"));  //设置标题
    setStyleSheet("background-color:black;");

    //边框
    ui->ecg1WaveLabel->setStyleSheet("border:1px solid white;");
    ui->ecg2WaveLabel->setStyleSheet("border:1px solid white;");
    ui->spo2WaveLabel->setStyleSheet("border:1px solid white;");
    ui->respWaveLabel->setStyleSheet("border:1px solid white;");

    //菜单栏设置
    //ui->menuBar->addAction(tr("串口设置"), this, SLOT(menuSetUART()));
    ui->menuBar->addAction(tr("数据存储"), this, SLOT(menuSaveData()));
    ui->menuBar->addAction(tr("打开数据"), this, SLOT(menuOpen()));
    ui->menuBar->setStyleSheet("color:white");
    //ui->menuBar->addAction(tr("退出"), this, SLOT(menuQuit()));

    //状态栏设置
    mFirstStatusLabel = new QLabel();
    mFirstStatusLabel->setMinimumSize(200, 18); //设置标签最小尺寸
    mFirstStatusLabel->setStyleSheet("color:white");
    QFont font("Microsoft YaHei", 10, 50);
    mFirstStatusLabel->setFont(font);
    mFirstStatusLabel->setText(tr("串口未配置"));
    ui->statusBar->addWidget(mFirstStatusLabel);

    mPackUnpack = new PackUnpack();//形成解包打包函数的对象
    mPackAfterUnpackArr = new uchar*[PACK_QUEUE_CNT];
    for(int i = 0; i < PACK_QUEUE_CNT; i++)
    {
        mPackAfterUnpackArr[i] = new uchar[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    }

    //呼吸画布初始化
    QPixmap pixResp(WAVE_X_SIZE, WAVE_Y_SIZE);
    mPixmapResp = pixResp;
    mPixmapResp.fill(Qt::black);

    //血氧画布初始化
    QPixmap pixSPO2(WAVE_X_SIZE, WAVE_Y_SIZE);
    mPixmapSPO2 = pixSPO2;
    mPixmapSPO2.fill(Qt::black);

    //心电画布初始化
    QPixmap pixECG(WAVE_X_SIZE, WAVE_Y_SIZE);
    mPixmapECG1 = pixECG;
    mPixmapECG2 = pixECG;
    mPixmapECG1.fill(Qt::black);
    mPixmapECG2.fill(Qt::black);

    //打开定时器
    mTimer = startTimer(20);

    //初始化参数
    uiInit();
    //事件滤波器，双击group组件可以响应，对鼠标的双击或单击产生反应
    ui->ecgInfoGroupBox->installEventFilter(this);
    ui->nibpInfoGroupBox->installEventFilter(this);
    ui->spo2InfoGroupBox->installEventFilter(this);
    ui->respInfoGroupBox->installEventFilter(this);
    ui->tempInfoGroupBox->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->ecgInfoGroupBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "ecgInfoGroupBox click";

            if((mSerialPort != NULL) && (mSerialPort->isOpen()))
            {
                FormECG *formECG = new FormECG(mECG1Lead, mECG1Gain, mECG2Lead, mECG2Gain);
                connect(formECG, SIGNAL(sendECGData(int, int, int, int, QByteArray)), this, SLOT(recECGData(int, int, int, int, QByteArray)));
                formECG->show();
            }
            else
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->nibpInfoGroupBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "nibpInfoGroupBox click";

            if((mSerialPort != NULL) && (mSerialPort->isOpen()))
            {
                FormNIBP *formNIBP = new FormNIBP(mNIBPMode);
                //更新显示测量模式
                connect(formNIBP, SIGNAL(sendNIBPSetData(QString)), this, SLOT(recNIBPSetData(QString)));
                formNIBP->show();
                //下发命令
                connect(formNIBP, SIGNAL(sendNIBPData(QByteArray)), this, SLOT(writeSerial(QByteArray)));
            }
            else
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->spo2InfoGroupBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "spo2InfoGroupBox click";

            if((mSerialPort != NULL) && (mSerialPort->isOpen()))
            {
                FormSPO2 *formSPO2 = new FormSPO2(mSPO2Sens);
                formSPO2->show();
                connect(formSPO2, SIGNAL(sendSPO2Data(QString, QByteArray)), this, SLOT(recSPO2Data(QString, QByteArray)));
            }
            else
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->respInfoGroupBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "respInfoGroupBox click";

            if((mSerialPort != NULL) && (mSerialPort->isOpen()))
            {
                FormResp *formResp = new FormResp(mRespGain);
                formResp->show();
                connect(formResp, SIGNAL(sendRespData(QString, QByteArray)), this, SLOT(recRespGain(QString, QByteArray)));
            }
            else
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(obj == ui->tempInfoGroupBox)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "tempInfoGroupBox click";

            if((mSerialPort != NULL) && (mSerialPort->isOpen()))
            {
                FormTemp *formTemp = new FormTemp(mPrbType);
                formTemp->show();
                connect(formTemp, SIGNAL(sendTempData(QString, QByteArray)), this, SLOT(recPrbType(QString, QByteArray)));
            }
            else
            {

            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}

void MainWindow::uiInit()
{
    mSerialPort = NULL;

    mPackHead = -1;    //当前需要处理的缓冲包的序号
    mPackTail = -1;    //最后处理的缓冲包的序号，mPackHead不能追上mPackTail,追上的话表示收到的数据超出2000的缓冲

    //初始化体温探头
    mPrbType  = "YSI";

    //初始化血压参数
    mNIBPMode = "手动";
    mNIBPEnd  = 0;
    mCufPressure = 0;   //袖带压
    mSysPressure = 0;   //收缩压
    mDiaPressure = 0;   //舒张压
    mMapPressure = 0;   //平均压
    mPulseRate   = 0;   //脉率

    //初始化呼吸参数
    mRespWave.clear();
    mRespXStep   = 0;     //Resp横坐标
    mRespWaveNum = 0;     //Resp波形数
    mDrawResp = false;
    mRespGain = "X0.25";  //呼吸增益设置
    mRespWaveData = 50;

    //初始化血氧参数
    mSPO2Wave.clear();
    mSPO2XStep   = 0;     //SPO2横坐标
    mSPO2WaveNum = 0;     //SPO2波形数
    mDrawSPO2 = false;
    mSPO2Sens = "中";     //血氧灵敏度设置
    mSPO2WaveData = 77;

    //初始化心电参数
    mECG1Gain = 2;
    mECG1Lead = 1;
    mECG2Gain = 2;
    mECG2Lead = 0;
    mECG1Wave.clear();
    mECG2Wave.clear();
    mECG1XStep = 0;    //ECG1横坐标
    mECG2XStep = 0;    //ECG2横坐标
    mECG1WaveNum = 0;  //ECG1波形数
    mECG2WaveNum = 0;  //ECG2波形数
    mDrawECG1 = false;
    mDrawECG2 = false;
    mECG1WaveData = 50;
    mECG2WaveData = 50;

    //初始化演示参数
    mDisplayModeFlag = true;
}

void MainWindow::menuSetUART()
{
    qDebug() << "click setUART";
    FormSetUART *formSetUART = new FormSetUART();
    connect(formSetUART, SIGNAL(uartSetData(QString, int, int, int, int, bool)), this, SLOT(initSerial(QString, int, int, int, int, bool)));
    formSetUART->show();
}

void MainWindow::initSerial(QString portNum, int baudRate, int dataBits, int stopBits, int parity, bool isOpened)
{
    qDebug() << "init serial ";
    qDebug() << portNum;

    if(!isOpened)
    {
        mSerialPort = new QSerialPort;
        mSerialPort->setPortName(portNum);

        if(mSerialPort->open(QIODevice::ReadWrite))
        {
            //设置波特率
            qDebug() << "baudRate:" << baudRate;
            mSerialPort->setBaudRate(baudRate);

            //设置数据位
            mSerialPort->setDataBits(QSerialPort::Data8);

            //设置停止位
            mSerialPort->setStopBits(QSerialPort::OneStop);

            //设置校验位
            mSerialPort->setParity(QSerialPort::NoParity);

            //设置流控制
            mSerialPort->setFlowControl(QSerialPort::NoFlowControl);
            mFirstStatusLabel->setStyleSheet("color:black;");
            mFirstStatusLabel->setText(portNum + "已打开");

            //连接信号槽
            connect(mSerialPort, &QSerialPort::readyRead, this, &MainWindow::readSerial);
        }
        else
        {
            QMessageBox::about(NULL, "提示", "串口无法打开\r\n不存在或已被占用");
            mFirstStatusLabel->setStyleSheet("color:red;");
            mFirstStatusLabel->setText(portNum + "无法打开");
            return;
        }

        gUARTOpenFlag = true;
    }
    else
    {
        mSerialPort->clear();
        mSerialPort->close();
        mSerialPort->deleteLater();

        gUARTOpenFlag = false;
        mFirstStatusLabel->setStyleSheet("color:black;");
        mFirstStatusLabel->setText(portNum + "已关闭");
    }
}

void MainWindow::readSerial()
{
    mRxData = mSerialPort->readAll();

    if(!mRxData.isEmpty())
    {
        procUARTData();    //PCT解包
        dealRcvPackData(); //数据分类保存
    }
}

void MainWindow::writeSerial(QByteArray data)
{
    qDebug() << "write serial";

    if(mSerialPort != NULL)
    {
        if(mSerialPort->isOpen())
        {
            mTxData = data;
            mSerialPort->write(mTxData);
        }
    }
}

void MainWindow::procUARTData()
{
    char *buf;

    if(mRxData.size() > 0)
    {
        buf = mRxData.data();
    }

    for(int i = 0; i < mRxData.size(); i++)
    {
        unpackRcvData(*(buf + i));
    }

    mRxData.clear();
}

bool MainWindow::unpackRcvData(uchar recData)
{
    bool findPack = false;
    findPack = mPackUnpack->unpackData(recData);

    if(findPack)
    {
        mPackAfterUnpackList = mPackUnpack->getUnpackRslt();  //获取解包结果

        if(mPackAfterUnpackList.size() > 10)
        {
            QMessageBox::information(NULL, tr("Info"), tr("长度异常"), "确定");
        }

        int head = (mPackHead + 1) % PACK_QUEUE_CNT;  //作显示用，一个head一个尾，叠加一次就要往后移位

        for(int i = 0; i < 8; i++)
        {
            mPackAfterUnpackArr[head][i] = mPackAfterUnpackList[i];
        }

        mMutex.lock();
        mPackHead = (mPackHead + 1) % PACK_QUEUE_CNT;   //当数据超过了限定长度，重新拉回来，所以求模
        //qDebug()<<mPackHead;

        if(mPackTail == -1)
        {
            mPackTail = 0;
        }

        mMutex.unlock();
    }

    return findPack;
}

void MainWindow::dealRcvPackData()
{
    int headIndex = -1;
    int tailIndex = -1;

    mMutex.lock();
    headIndex = mPackHead;  //串口进来的数据的序号
    tailIndex = mPackTail;  //处理串口数据的序号
    mMutex.unlock();

    if(headIndex < tailIndex)
    {
        headIndex = headIndex + PACK_QUEUE_CNT;
    }

    int index;
    int cnt = headIndex - tailIndex;

    for(int i = tailIndex; i < headIndex; i++)
    {
        index = i % PACK_QUEUE_CNT;
        //根据模块ID处理数据包
        switch(mPackAfterUnpackArr[index][0])
        {
        case DAT_TEMP:
            analyzeTempData(mPackAfterUnpackArr[index]);
            break;
        case DAT_NIBP:
            analyzeNIBPData(mPackAfterUnpackArr[index]);
            break;
        case DAT_RESP:
            analyzeRespData(mPackAfterUnpackArr[index]);
            break;
        case DAT_SPO2:
            analyzeSPO2Data(mPackAfterUnpackArr[index]);
            break;
        case DAT_ECG:
            analyzeECGData(mPackAfterUnpackArr[index]);
            break;
        default:
            break;
        }
    }

    mMutex.lock();
    mPackTail = (mPackTail + cnt) % PACK_QUEUE_CNT;
    mMutex.unlock();

    //刷新波形
    if(mRespWave.count() > 2)
    {
        mDrawResp = true;
    }

    //刷新波形
    if(mSPO2Wave.count() > 2)
    {
        mDrawSPO2 = true;
    }

    //刷新波形
    if(mECG1Wave.count() > 10)
    {
        mDrawECG1 = true;
        mDrawECG2 = true;
    }
}

void MainWindow::analyzeTempData(uchar packAfterUnpack[])
{
    float temp1Data;          //通道1体温数据
    float temp2Data;          //通道2体温数据
    bool temp1Lead;           //通道1导联状态
    bool temp2Lead;           //通道2导联状态

    int data;
    switch(packAfterUnpack[1])
    {
    case DAT_TEMP_DATA:
        data = packAfterUnpack[2];
        temp1Lead = (data & 0x01) != 1;
        temp2Lead = ((data >> 1) & 0x01) != 1;
        data = packAfterUnpack[3];
        data = (data << 8) | packAfterUnpack[4];
        temp1Data = (float)(data / 10.0);
        data = packAfterUnpack[5];
        data = (data << 8) | packAfterUnpack[6];
        temp2Data = (float)(data / 10.0);

        if(temp1Lead)
        {
            ui->temp1LeadLabel->setText("T1导联");
            ui->temp1LeadLabel->setStyleSheet("color:green;");
            ui->temp1ValLabel->setText(QString::number(temp1Data));
        }
        else
        {
            ui->temp1LeadLabel->setText("T1脱落");
            ui->temp1LeadLabel->setStyleSheet("color:red;");
            ui->temp1ValLabel->setText("--");
        }

        if(temp2Lead)
        {
            ui->temp2LeadLabel->setText("T2导联");
            ui->temp2LeadLabel->setStyleSheet("color:green;");
            ui->temp2ValLabel->setText(QString::number(temp2Data));
        }
        else
        {
            ui->temp2LeadLabel->setText("T2脱落");
            ui->temp2LeadLabel->setStyleSheet("color:red;");
            ui->temp2ValLabel->setText("--");
        }

        break;

    default:
        break;
    }
}

void MainWindow::analyzeNIBPData(uchar packAfterUnpack[])
{
    int data;

    switch (packAfterUnpack[1])
    {
    case DAT_NIBP_CUFPRE:
        data = packAfterUnpack[2];
        mCufPressure = (data << 8) | packAfterUnpack[3];
        break;

    case DAT_NIBP_END:
        data = packAfterUnpack[3];
        if(data != 0)
        {
            mNIBPEnd = true;
        }
        break;

    case DAT_NIBP_RSLT1:
        data = packAfterUnpack[2];
        mSysPressure = (data << 8) | packAfterUnpack[3];
        data = packAfterUnpack[4];
        mDiaPressure = (data << 8) | packAfterUnpack[5];
        data = packAfterUnpack[6];
        mMapPressure = (data << 8) | packAfterUnpack[7];
        break;

    case DAT_NIBP_RSLT2:
        data = packAfterUnpack[2];
        mPulseRate = (data << 8) | packAfterUnpack[3];
        mNIBPEnd = true;
        break;

    default:
        break;
    }

    ui->cufPressureLabel->setText(QString::number(mCufPressure));
    ui->sysPressureLabel->setText(QString::number(mSysPressure));
    ui->diaPressureLabel->setText(QString::number(mDiaPressure));
    ui->mapPressureLabel->setText(QString::number(mMapPressure));
    ui->nibpPRLabel->setText(QString::number(mPulseRate));
}

void MainWindow::analyzeRespData(uchar packAfterUnpack[])
{
    uchar respWave = 0;	        //呼吸波形数据
    ushort respRate = 0;	    //呼吸率值
    byte respRateHByte = 0;     //呼吸率高字节
    byte respRateLByte = 0;		//呼吸率低字节

    switch(packAfterUnpack[1])
    {
    //波形数据
    case DAT_RESP_WAVE:
        for(int i = 2; i < 7; i++)
        {
            respWave = packAfterUnpack[i];
            mRespWave.append(respWave);
        }
        break;

    //呼吸数据
    case DAT_RESP_RR:
        respRateHByte = packAfterUnpack[2];
        respRateLByte = packAfterUnpack[3];
        respRate = (ushort)(respRate | respRateHByte);
        respRate = (ushort)(respRate << 8);
        respRate = (ushort)(respRate | respRateLByte);

        if(respRate >= 255)
        {
            ui->respRateLabel->setText("---");	//呼吸率值最大不超过255，超过255则视为无效值，不显示呼吸率
        }
        else
        {
            ui->respRateLabel->setText(QString::number(respRate, 10));
        }

        break;

    default:
        break;
    }
}

void MainWindow::drawRespWave()
{
    if(mDrawResp)
    {
        //mDrawResp = false;

        int respCnt;
        ushort unRespData;
        ushort unRespWaveData;

        if(!mDisplayModeFlag)
        {
            respCnt = mRespWave.count() - 1;
        }
        else
        {
            respCnt = 2;
        }

        if(respCnt < 2)
        {
            return;
        }

        QPainter painterResp(&mPixmapResp);
        painterResp.setBrush(Qt::black);
        painterResp.setPen(QPen(Qt::black, 1, Qt::SolidLine));

        if(respCnt >= 1080 - mRespXStep)
        {
            QRect rct(mRespXStep, 0, 1080 - mRespXStep, 130);
            painterResp.drawRect(rct);

            QRect rect(0, 0, respCnt + mRespXStep - 1080, 130);
            painterResp.drawRect(rect);
        }
        else
        {
            QRect rct(mRespXStep, 0, respCnt, 130);
            painterResp.drawRect(rct);
        }

        painterResp.setPen(QPen(Qt::red, 2, Qt::SolidLine));

        //监护模式绘图
        if(!mDisplayModeFlag)
        {
            for(int i = 0; i < respCnt; i++)
            {
                QPoint point1(mRespXStep, 110 - mRespWave.at(i) / 2.55);
                QPoint point2(mRespXStep + 1, 110 - mRespWave.at(i + 1)/ 2.55);
                painterResp.drawLine(point1, point2);
                mRespXStep++;
                if(mRespXStep >= 1080)
                {
                    mRespXStep = 1;
                }
            }

            double tail = mRespWave.last();
            mRespWave.clear();
            mRespWave.append(tail);
        }
        //演示模式绘图
        else if(mDisplayModeFlag)
        {
            for(int i = 0; i < respCnt; i++)
            {
                unRespData = mRespWave.takeFirst();
                unRespWaveData = 110 - unRespData / 2.55;
                painterResp.drawLine(mRespXStep, mRespWaveData, mRespXStep + 1, unRespWaveData);
                mRespWaveData = unRespWaveData;
                mRespXStep++;

                if(mRespXStep >= 1080)
                {
                    mRespXStep = 1;
                }
                if(mRespWave.length()>1)
                {
                    mRespWave.removeFirst();
                }

            }
        }

        ui->respWaveLabel->setPixmap(mPixmapResp);
    }
}

void MainWindow::analyzeSPO2Data(uchar packAfterUnpack[])
{
    ushort spo2Wave = 0;	        //血氧波形数据
    ushort pulseRate = 0;			//脉率值
    byte pulseRateHByte = 0;		//脉率高字节
    byte pulseRateLByte = 0;		//脉率低字节
    byte spo2Value = 0;			    //血氧饱和度
    byte fingerLead = 0;			//手指连接信息
    byte probeLead = 0;			    //探头连接信息

    switch(packAfterUnpack[1])
    {
    //波形数据
    case DAT_SPO2_WAVE:
        for(int i = 2; i < 7; i++)
        {
            spo2Wave = (ushort)packAfterUnpack[i];
            mSPO2Wave.append(spo2Wave);
        }

        fingerLead = (byte)((packAfterUnpack[7] & 0x80) >> 7);		//手指脱落信息
        probeLead = (byte)((packAfterUnpack[7] & 0x10) >> 4);		//探头脱落信息

        if(fingerLead == 0x01)
        {
          ui->spo2FingerLeadLabel->setStyleSheet("color:red;");
          ui->spo2FingerLeadLabel->setText("手指脱落");
        }
        else
        {
          ui->spo2FingerLeadLabel->setStyleSheet("color:green;");
          ui->spo2FingerLeadLabel->setText("手指连接");
        }

        if(probeLead == 0x01)
        {
          ui->spo2PrbLeadLabel->setStyleSheet("color:red;");
          ui->spo2PrbLeadLabel->setText("探头脱落");
        }
        else
        {
          ui->spo2PrbLeadLabel->setStyleSheet("color:green;");
          ui->spo2PrbLeadLabel->setText("探头连接");
        }
        break;

    //血氧数据
    case DAT_SPO2_DATA:
        //脉率
        pulseRateHByte = packAfterUnpack[3];
        pulseRateLByte = packAfterUnpack[4];
        pulseRate = (ushort)(pulseRate | pulseRateHByte);
        pulseRate = (ushort)(pulseRate << 8);
        pulseRate = (ushort)(pulseRate | pulseRateLByte);

        if(pulseRate >= 300)
        {
            pulseRate = 0;		//脉率值最大不超过300，超过300则视为无效值，给其赋0即可
        }

        ui->spo2PRLabel->setText(QString::number(pulseRate, 10));

        //血氧饱和度
        spo2Value = packAfterUnpack[5];

        if((0 < spo2Value) && (100 > spo2Value))
        {
            ui->spo2DataLabel->setText(QString::number(spo2Value, 10));
        }
        else
        {
            ui->spo2DataLabel->setText("---");
        }

        break;

    default:
        break;
    }
}

void MainWindow::drawSPO2Wave()
{
    if(mDrawSPO2)
    {
        mDrawSPO2 = true;
        int spo2Cnt;
        ushort unSPO2Data;
        ushort unSPO2WaveData;

        if(!mDisplayModeFlag)
        {
            spo2Cnt = mSPO2Wave.count() - 1;
        }
        else
        {
            spo2Cnt = 10;
        }

        if(spo2Cnt < 2)
        {
            return;
        }

        QPainter painterSPO2(&mPixmapSPO2);
        painterSPO2.setBrush(Qt::black);
        painterSPO2.setPen(QPen(Qt::black, 1, Qt::SolidLine));

        if(spo2Cnt >= 1080 - mSPO2XStep)
        {
            QRect rct(mSPO2XStep, 0, 1080 - mSPO2XStep, 130);
            painterSPO2.drawRect(rct);

            QRect rect(0, 0, spo2Cnt + mSPO2XStep - 1080, 130);
            painterSPO2.drawRect(rect);
        }
        else
        {
            QRect rct(mSPO2XStep, 0, spo2Cnt, 130);
            painterSPO2.drawRect(rct);
        }

        painterSPO2.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));

        //监护模式绘图
        if(!mDisplayModeFlag)
        {
            for(int i = 0; i < spo2Cnt; i++)
            {
                QPoint point1(mSPO2XStep, 110 - mSPO2Wave.at(i) / 2.55);
                QPoint point2(mSPO2XStep + 1, 110 - mSPO2Wave.at(i + 1)/ 2.55);

                painterSPO2.drawLine(point1, point2);

                mSPO2XStep++;

                if(mSPO2XStep >= 1080)
                {
                    mSPO2XStep = 1;
                }
            }

            double tail = mSPO2Wave.last();
            mSPO2Wave.clear();
            mSPO2Wave.append(tail);
        }
        //演示模式绘图
        else if(mDisplayModeFlag)
        {
            for(int i = 0; i < spo2Cnt; i++)
            {
                unSPO2Data = mSPO2Wave.at(0);
                unSPO2WaveData = 110 - unSPO2Data / 2.55;
                painterSPO2.drawLine(mSPO2XStep, mSPO2WaveData, mSPO2XStep + 1, unSPO2WaveData);

                mSPO2WaveData = unSPO2WaveData;
                mSPO2XStep++;

                if(mSPO2XStep >= 1080)
                {
                    mSPO2XStep = 1;
                }

                if(mSPO2Wave.length()>1)
                {
                    mSPO2Wave.removeFirst();
                }
            }
        }

        ui->spo2WaveLabel->setPixmap(mPixmapSPO2);
    }
}

void MainWindow::analyzeECGData(uchar packAfterUnpack[])
{
    uchar ecg1HByte = 0;             //心电1波形高字节
    uchar ecg1LByte = 0;             //心电1波形低字节
    uchar ecg2HByte = 0;             //心电2波形高字节
    uchar ecg2LByte = 0;             //心电2波形低字节
    ushort ecgWave1 = 0;             //心电1波形数据
    ushort ecgWave2 = 0;             //心电2波形数据
    byte leadV = 0;                  //导联V导联信息
    byte leadRA = 0;                 //导联RA导联信息
    byte leadLA = 0;                 //导联LA导联信息
    byte leadLL = 0;                 //导联LL导联信息
    byte hrHByte = 0;                //心率高字节
    byte hrLByte = 0;                //心率低字节
    ushort hr = 0;                   //心率
    static byte paceFlag = 0;        //起搏

    switch (packAfterUnpack[1])
    {
    //心电波形
    case DAT_ECG_WAVE:
        ecg1HByte = packAfterUnpack[2];//两个byte构成十六位数据
        ecg1LByte = packAfterUnpack[3];
        ecgWave1 = (ushort)(ecgWave1 | ecg1HByte);
        ecgWave1 = (ushort)(ecgWave1 << 8);
        ecgWave1 = (ushort)(ecgWave1 | ecg1LByte);

        ecg2HByte = packAfterUnpack[4];
        ecg2LByte = packAfterUnpack[5];
        ecgWave2 = (ushort)(ecgWave2 | ecg2HByte);
        ecgWave2 = (ushort)(ecgWave2 << 8);
        ecgWave2 = (ushort)(ecgWave2 | ecg2LByte);

        mECG1WaveNum++;
        mECG2WaveNum++;

        if(mECG1WaveNum == 3) //每3个点取1个点（数据压缩）
        {
            mECG1WaveNum = 0;
            mECG1Wave.append(ecgWave1);
        }

        if(mECG2WaveNum == 3)  //每3个点取1个点
        {
            mECG2WaveNum = 0;
            mECG2Wave.append(ecgWave2);
        }

        break;

    //心电导联信息
    case DAT_ECG_LEAD:
        leadLL = (byte)(packAfterUnpack[2] & 0x01);
        leadLA = (byte)(packAfterUnpack[2] & 0x02);
        leadRA = (byte)(packAfterUnpack[2] & 0x04);
        leadV = (byte)(packAfterUnpack[2] & 0x08);   //定义的值

        if(leadLL == 0x01)
        {
            ui->leadLLLabel->setStyleSheet("color:red;");
            ui->leadLLLabel->setText("LL");
        }
        else
        {
            ui->leadLLLabel->setStyleSheet("color:green;");
            ui->leadLLLabel->setText("LL");
        }

        if(leadLA == 0x02)
        {
            ui->leadLALabel->setStyleSheet("color:red;");
            ui->leadLALabel->setText("LA");
        }
        else
        {
            ui->leadLALabel->setStyleSheet("color:green;");
            ui->leadLALabel->setText("LA");
        }

        if(leadRA == 0x04)
        {
            ui->leadRALabel->setStyleSheet("color:red;");
            ui->leadRALabel->setText("RA");
        }
        else
        {
            ui->leadRALabel->setStyleSheet("color:green;");
            ui->leadRALabel->setText("RA");
        }

        if(leadV == 0x08)
        {
            ui->leadVLabel->setStyleSheet("color:red;");
            ui->leadVLabel->setText("V");
        }
        else
        {
            ui->leadVLabel->setStyleSheet("color:green;");
            ui->leadVLabel->setText("V");
        }
        break;

    //心率
    case DAT_ECG_HR:
        hrHByte = (byte)(packAfterUnpack[2]);
        hrLByte = (byte)(packAfterUnpack[3]);
        hr = (ushort)(hr | hrHByte);
        hr = (ushort)(hr << 8);
        hr = (ushort)(hr | hrLByte);

        ui->heartRateLabel->setAlignment(Qt::AlignHCenter);

        if((0 < hr) && (300 > hr))
        {
            ui->heartRateLabel->setText(QString::number(hr, 10));
        }
        else
        {
            ui->heartRateLabel->setText("--");
        }

        break;

    default:
        break;
    }
}

void MainWindow::drawECG1Wave()
{
    if(mDrawECG1)
    {
        // mDrawECG1 = false;

        int ecg1Cnt;
        ushort unECG1Data;
        ushort unECG1WaveData;

        if(!mDisplayModeFlag)
        {
            ecg1Cnt = mECG1Wave.count() - 1;
        }
        else
        {
            ecg1Cnt = 10;
        }

        if(ecg1Cnt < 2)
        {
            return;
        }

        QPainter painterECG1(&mPixmapECG1);
        painterECG1.setBrush(Qt::black);
        painterECG1.setPen(QPen(Qt::black, 1, Qt::SolidLine));

        if(ecg1Cnt >= 1080 - mECG1XStep)
        {
            QRect rct(mECG1XStep, 0, 1080 - mECG1XStep, 130);
            painterECG1.drawRect(rct);

            QRect rect(0, 0, 10 + ecg1Cnt + mECG1XStep - 1080, 130);
            painterECG1.drawRect(rect);
        }
        else
        {
            QRect rct(mECG1XStep, 0, ecg1Cnt + 10, 130);
            painterECG1.drawRect(rct);
        }

        painterECG1.setPen(QPen(Qt::green, 2, Qt::SolidLine));

        //监护模式绘图
        if(!mDisplayModeFlag)
        {
            for(int i = 0; i < ecg1Cnt; i++)
            {
                QPoint point1(mECG1XStep, 50 - (mECG1Wave.at(i) - 2048) / 18);
                QPoint point2(mECG1XStep + 1, 50 - (mECG1Wave.at(i + 1) - 2048) / 18);

                painterECG1.drawLine(point1, point2);

                mECG1XStep++;

                if(mECG1XStep >= 1080)
                {
                    mECG1XStep = 1;
                }
            }

            double tail = mECG1Wave.last();
            mECG1Wave.clear();
            mECG1Wave.append(tail);
        }
        //演示模式绘图
        else if(mDisplayModeFlag)
        {
            for(int i = 0; i < ecg1Cnt; i++)
            {
                unECG1Data = mECG1Wave.at(0);
                unECG1WaveData = 50 - (unECG1Data - 2048) / 18;
                painterECG1.drawLine(mECG1XStep, mECG1WaveData, mECG1XStep + 1, unECG1WaveData);

                mECG1WaveData = unECG1WaveData;
                mECG1XStep++;

                if(mECG1XStep >= 1080)
                {
                    mECG1XStep = 1;
                }

                if(mECG1Wave.length()>1)
                {
                    mECG1Wave.removeFirst();
                }

            }
        }

        ui->ecg1WaveLabel->setPixmap(mPixmapECG1);
    }
}

void MainWindow::drawECG2Wave()
{
    if(mDrawECG2)
    {
        //mDrawECG2 = false;

        int ecg2Cnt;
        ushort unECG2Data;
        ushort unECG2WaveData;

        if(!mDisplayModeFlag)
        {
            ecg2Cnt = mECG2Wave.count() - 1;
        }
        else
        {
            ecg2Cnt = 10;
        }

        if(ecg2Cnt < 2)
        {
            return;
        }

        QPainter painterECG2(&mPixmapECG2);
        painterECG2.setBrush(Qt::black);
        painterECG2.setPen(QPen(Qt::black, 1, Qt::SolidLine));

        if(ecg2Cnt >= 1080 - mECG2XStep)
        {
            QRect rct(mECG2XStep, 0, 1080- mECG2XStep, 131);
            painterECG2.drawRect(rct);
            QRect rect(0, 0, 10 + ecg2Cnt + mECG2XStep - 1080, 131);
            painterECG2.drawRect(rect);
        }
        else
        {
            QRect rct(mECG2XStep, 0, ecg2Cnt + 10, 131);
            painterECG2.drawRect(rct);
        }

        painterECG2.setPen(QPen(Qt::blue, 2, Qt::SolidLine));

        //监护模式绘图
        if(!mDisplayModeFlag)
        {
            for(int i = 0; i < ecg2Cnt; i++)
            {
                QPoint point1(mECG2XStep, 50 - (mECG2Wave.at(i) - 2048) / 18);
                QPoint point2(mECG2XStep + 1,50 - (mECG2Wave.at(i + 1) - 2048) / 18);

                painterECG2.drawLine(point1, point2);

                mECG2XStep++;

                if(mECG2XStep >= 1080)
                {
                    mECG2XStep = 1;
                }
            }

            double tail = mECG2Wave.last();
            mECG2Wave.clear();
            mECG2Wave.append(tail);
        }
        //演示模式绘图
        else if(mDisplayModeFlag)
        {
            for(int i = 0; i < ecg2Cnt; i++)
            {
                unECG2Data = mECG2Wave.at(0);
                unECG2WaveData = 50 - (unECG2Data - 2048) / 18;
                painterECG2.drawLine(mECG2XStep, mECG2WaveData, mECG2XStep + 1, unECG2WaveData);
                mECG2WaveData = unECG2WaveData;
                mECG2XStep++;

                if(mECG2XStep >= 1080)
                {
                    mECG2XStep = 1;
                }
                if(mECG2Wave.length()>1)
                {
                    mECG2Wave.removeFirst();
                }
            }
        }

        ui->ecg2WaveLabel->setPixmap(mPixmapECG2);
    }
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == mTimer)
    {
        drawRespWave();
        drawSPO2Wave();
        drawECG1Wave();
        drawECG2Wave();
    }
}

void MainWindow::recPrbType(QString prbType, QByteArray data)
{
    mPrbType = prbType;
    writeSerial(data);
}

void MainWindow::recNIBPSetData(QString mode)
{
    mNIBPMode = mode;
    ui->nibpModeLabel->setText(mode);
}

void MainWindow::recRespGain(QString gain, QByteArray data)
{
    mRespGain = gain;
    writeSerial(data);
}

void MainWindow::recSPO2Data(QString sens, QByteArray data)
{
    mSPO2Sens = sens;
    writeSerial(data);
}

void MainWindow::recECGData(int lead1, int gain1, int lead2, int gain2, QByteArray data)
{
    mECG1Lead = lead1;
    mECG1Gain = gain1;
    mECG2Lead = lead2;
    mECG2Gain = gain2;
    writeSerial(data);
}

void MainWindow::menuOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this,"CSV Files","*.csv",0);  //打开，查找csv格式文件
    if(!fileName.isNull())
    {
        //filename是文件名
        qDebug() << fileName;

        QFile csvFile(fileName);

        mCSVList.clear();

        if(csvFile.open(QIODevice::ReadWrite))   //对数据进行读写
        {
            QTextStream stream(&csvFile);
            int i = 0;
            //QByteArray mDataList;
            while(!stream.atEnd())
            {
                mCSVList.push_back(stream.readLine());
                QString dataLine=mCSVList.at(i);
                QStringList dataList=dataLine.split(","); //以逗号间隔开，分割为独立的一个个字符串
                //qDebug()<<dataList;
                mRxData.clear();
                for (int j=0;j<dataList.length()-1;j++)   //将数据一个个读取进来
                {
                    QString str=dataList.value(j);
                    //qDebug()<<str<<"o";
                    mRxData.append(str.toUShort());  //字符转换成数字，byte，因为之前的mRxData也是byte，要转换成一致
                    //qDebug()<<mRxData.at(j)<<"k";
                }

                //qDebug()<<mRxData;

                //qDebug()<<mDataList.at(1);
                //mSPO2Wave.clear();
                procUARTData();//PCT解包
                dealRcvPackData();//数据分类保存
                i++;
            }
            csvFile.close();
        }

    }
}
