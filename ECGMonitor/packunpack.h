#ifndef _PACKUNPACK_H_
#define _PACKUNPACK_H_


#include <QList>

class PackUnpack
{

public:
    const int MAX_PACK_LEN = 10;

    //定义m_listBuf
    //m_listBuf[0]  : 对应packId
    //m_listBuf[1-8]: 对应arrData
    //m_listBuf[9]  : 对应checkSum
    QList<uchar> mListBuf;  //缓冲，逐个读取字符
    QList<int> mListPackLen;   //文件包的长度，因为当第八位是0的时候，就开始计数

    PackUnpack();
    int packData(QList<uchar> &listPack);
    bool unpackData(uchar data);
    QList<uchar> getUnpackRslt();

private:
    int  mPackLen;       //数据包长度
    bool mGotPackId;     //获取到ID的标志，获得正确的ID即为TRUE，否则为FALSE
    int  mRestByteNum;   //剩余字节数

    void packWithCheckSum(QList<uchar> &pack);
    bool unpackWithCheckSum(QList<uchar> &listPack);  //解包算上校验和

};

#endif //_PACKUNPACK_H_
