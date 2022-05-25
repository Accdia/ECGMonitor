#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "formsetuart.h"
#include "QSerialPort"
#include "QSerialPortInfo"
#include "packunpack.h"
#include <QMutex>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void uiInit();

    PackUnpack *mPackUnpack; //打包解包类

protected:
    void timerEvent(QTimerEvent *event); //重载定时器方法
    bool eventFilter(QObject *obj, QEvent *ev);

private slots:
    void menuSetUART();
    void menuOpen();
    void initSerial(QString portNum, int baudRate, int dataBits, int stopBits, int parity, bool isOpened);
    void readSerial();                 //串口数据读取
    void writeSerial(QByteArray data); //串口数据写入

    //体温设置
    void recPrbType(QString type, QByteArray data);

    //血压设置
    void recNIBPSetData(QString mode);

    //呼吸设置
    void recRespGain(QString gain, QByteArray data);

    //血氧设置
    void recSPO2Data(QString sens, QByteArray data);

    //心电设置
    void recECGData(int lead1, int gain1, int lead2, int gain2, QByteArray data);

private:
    Ui::MainWindow *ui;
    QStringList mCSVList;

    QLabel *mFirstStatusLabel;
    QSerialPort *mSerialPort;

    QByteArray mRxData; //接收数据暂存
    QByteArray mTxData; //发送数据暂存
    QList<uchar> mPackAfterUnpackList;  //解包后的数据
    uchar **mPackAfterUnpackArr;        //定义一个二维数组作为接收解包后的数据缓冲
    int mPackHead;   //当前需要处理的缓冲包的序号
    int mPackTail;   //最后处理的缓冲包的序号，mPackHead不能追上mPackTail,追上的话表示收到的数据超出2000的缓冲

    //接收定时器及线程锁
    QMutex mMutex;

    //定时器
    int mTimer;

    //演示相关
    bool mDisplayModeFlag;			//演示标志位

    //体温探头
    QString mPrbType;

    //血压
    QString mNIBPMode;      //血压测量模式
    bool mNIBPEnd;          //血压测量结束标志位
    int mCufPressure = 0;   //袖带压
    int mSysPressure = 0;   //收缩压
    int mDiaPressure = 0;   //舒张压
    int mMapPressure = 0;   //平均压
    int mPulseRate   = 0;   //脉率

    //呼吸
    QString mRespGain;          //呼吸增益
    QList<ushort> mRespWave;    //线性链表，内容为Resp的波形数据
    QPixmap mPixmapResp;        //呼吸画布
    int mRespXStep;             //Resp横坐标
    int mRespWaveNum;           //Resp波形数
    bool mDrawResp;             //画图标志位
    ushort mRespWaveData;       //演示模式画图纵坐标

    //血氧
    QString mSPO2Sens;          //血氧灵敏度
    QList<ushort> mSPO2Wave;    //线性链表，内容为SPO2的波形数据
    QPixmap mPixmapSPO2;        //血氧画布
    int mSPO2XStep;             //SPO2横坐标
    int mSPO2WaveNum;           //SPO2波形数
    bool mDrawSPO2;             //画图标志位
    ushort mSPO2WaveData;       //演示模式画图纵坐标

    //心电
    int mECG1Gain;              //ECG1增益
    int mECG1Lead;              //ECG1导联
    int mECG2Gain;              //ECG2增益
    int mECG2Lead;              //ECG2导联
    QPixmap mPixmapECG1;        //ECG1画布
    QPixmap mPixmapECG2;        //ECG2画布
    QList<ushort> mECG1Wave;    //线性链表，内容为ECG1的波形数据
    QList<ushort> mECG2Wave;    //线性链表，内容为ECG2的波形数据
    int mECG1XStep;             //ECG1横坐标
    int mECG2XStep;             //ECG2横坐标
    int mECG1WaveNum;           //ECG1波形数
    int mECG2WaveNum;           //ECG2波形数
    bool mDrawECG1;
    bool mDrawECG2;
    ushort mECG1WaveData;       //画图模式纵坐标
    ushort mECG2WaveData;       //画图模式纵坐标

    //数据处理方法
    void procUARTData();
    void dealRcvPackData();
    bool unpackRcvData(uchar recData);

    void analyzeTempData(uchar packAfterUnpack[]); //分析体温
    void analyzeNIBPData(uchar packAfterUnpack[]); //分析血压
    void analyzeRespData(uchar packAfterUnpack[]); //分析呼吸
    void drawRespWave();                           //画呼吸波形
    void analyzeSPO2Data(uchar packAfterUnpack[]); //分析血氧
    void drawSPO2Wave();                           //画血氧波形
    void analyzeECGData(uchar packAfterUnpack[]);  //分析心电
    void drawECG1Wave();                           //画心电1波形
    void drawECG2Wave();                           //画心电2波形
};

#endif // MAINWINDOW_H
