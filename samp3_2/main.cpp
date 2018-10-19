#include <QApplication>
#include <QtGlobal>
#include <QList>
#include <QVector>
#include <QStack>
#include <QQueue>
#include <QSet>
#include <QMap>
#include <QMultiMap>
#include <QMultiHash>
#include <QListIterator>
#include <QMutableListIterator>
#include <QMapIterator>
#include <QMutableMapIterator>
#include <QtDebug>

void c3_2()
{
    // QT全局定义
    qDebug("FBI warnning!");
}

void c3_3()
{
    // 容器 QList QLinkedList QVector QStack QQueue
    QList<QString> aList;
    aList.append("星期一");
    aList.append("星期二");
    aList.append("Wednesday");
    QString tmp = aList[0];
    qDebug() << tmp;
    qDebug() << aList[1];

    QList<QString> list;
    list<< "one 一" << "tow ";
    QString str1 = list[1];
    QString str0 = list.at(0);
    qDebug() << "Str1:" << str1<< "str0" <<str0;

    //QLinkedList
    // 不连续内存，没有下标索引

    // QVector 连续内存，速度更快
    QVector<QString> vec;

    // QStack
    // 后入先出LIFO
    QStack<int> stack;
    stack.push(10);
    stack.push(30);
    stack.push(40);
    while (!stack.empty()) {
        qDebug()<<stack.pop();
    }

    //QQueue
    // 先入先出FIFO,enqueue,dequeue
    QQueue<int> queue;
    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(400);
    while (!queue.empty()) {
        qDebug() << queue.dequeue();
    }

    // 关联容器 QMAP QMultiMap QHash QMultiHash QSet
    // QSet
    // 存储顺序不定,速度快
    QSet<QString> set;
    set << "大师" << " Chongqing" <<"2018";
    if( set.contains("大师"))
        qDebug() << "存在！";

    // QMap
    // 按照键值顺序存储，一个key一个value
    QMap<QString,int> map;
    map["大师"] = 30;
    map["马云"] = 60;
    map.insert("QT", 20);
    int ret = map.value("大师",18);
    int ret2 = map.value("大师2",18);
    qDebug() << "大师 :" << ret << "大师2 : " << ret2;

    // QMultiMap
    // 多值映射, 不提供[]访问
    QMultiMap<QString,int> map1, map2, map3;
    map1.insert("大师", 18);
    map1.insert("大师", 30);
    map2.insert("大师", 100);
    map3 = map1 + map2;
    QList<int> values = map3.values("大师");
    for(int i=0; i < values.size(); i++)
        qDebug() << "大师： " << values[i];

    // QHash
    // 1、比QMAP快
    // 2、数据项任意顺序
    // 3、必须提供==运算符和qHash()全局散列函数
    // QMultiHash 是一对多的QHash

}

void c3_4()
{
    // 容器的迭代器
    // JAVA类型的好用高级
    // C++类型的高效
    QList<QString> aList;
    aList.append("星期一");
    aList.append("星期二");
    aList.append("Wednesday");
    QListIterator<QString> i(aList);
    while ( i.hasNext() ) {
        qDebug()<< i.next();
    }

    QListIterator<QString> ib(aList);
    ib.toBack();
    while ( ib.hasPrevious()) {
        qDebug() << ib.previous();
    }

    QMutableListIterator<QString> mi(aList);
    while ( mi.hasNext()) {
        if( mi.next() == "星期二")
            mi.remove(); // 删除
        else
            mi.setValue(mi.value()+"_new"); //修改
    }
    QListIterator<QString> new_i(aList);
    while ( new_i.hasNext() ) {
        qDebug()<< new_i.next();
    }

    // STL类型迭代器
    aList<< "迭代器" << "JAVA" << "STL";
    QList<QString>::const_iterator ci;
    for( ci = aList.begin(); ci != aList.end(); ++ci){
        qDebug() << *ci;
    }
    auto ai = aList.rbegin();
    for( ; ai != aList.rend(); ++ai){
        qDebug() << *ai;
    }

    QMultiMap<QString,int> map1, map2, map3;
    map1.insert("大师", 18);
    map1.insert("大师", 30);
    map2.insert("大师", 100);
    map3 = map1 + map2;
    QMultiMap<QString,int>::const_iterator map_it;
    for( map_it = map3.constBegin(); map_it != map3.constEnd(); ++map_it){
        qDebug()<< map_it.key() << ":" << map_it.value();
    }

    QString str;
    foreach( str, aList)
        qDebug() << str;

    foreach ( const QString &str, map3.uniqueKeys()){
        foreach( int i, map3.values(str))
            qDebug() << str << ":" << i;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    c3_2();

    c3_3();

    c3_4();

    return a.exec();
}
