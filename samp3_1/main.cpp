#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QMetaClassInfo>

// 声明不能放在函数内部
class TestClassInfo :public QObject{
    Q_OBJECT

    Q_CLASSINFO("author", "大师")
public:
    TestClassInfo();
};

void c3_1()
{
    QObject *obj = new QPushButton;
    QString name = obj->metaObject()->className();
    qDebug() << "className:" << name;

    //QMetaObject::newInstance();
    QTimer *timer = new QTimer;
    qDebug() << "is Qtimer?:" << timer->inherits("QTimer");
    qDebug() << "is QObject?:" << timer->inherits("QObject");
    qDebug() << "is QAbstractButton?:" << timer->inherits("QAbstractButton");

    qDebug() << QObject::tr("大师");
    //qDebug() << QObject::trUtf8("大师utf8");

    timer->setProperty("chongqing","重庆");
    qDebug() << timer->property("chongqing");

    //动态转换
    QTimer *btn = qobject_cast<QTimer*>(timer);
    qDebug() << btn->property("chongqing");

    //中文问题：不用QObject::tr,QObject::trUtf8, 或者网上推荐的各种乱七八糟的
    // 所有代码都用utf8,编辑器设置 display  file code
    // pro 文件增加: CONFIG += utf8_source
    // 这样就可以直接在代码里面写 "中文"
    qDebug() <<"//中文问题：不用QObject::tr,QObject::trUtf8, 或者网上推荐的各种乱七八糟的\n"
            <<"所有代码都用utf8,编辑器设置 display  file code\n"
           <<"pro 文件增加: CONFIG += utf8_source\n"
          <<"这样就可以直接在代码里面写 \"中文\"\n";

}


void c3_1_3()
{
    // 属性系统,给c++对象增加一些属性，READ、WRITE
    // QWidget
    //Q_PROPERTY(bool focus READ hasFocus)
    QPushButton *button = new QPushButton;
    QObject *object = button;
    object->setProperty("flat", true);
    qDebug() <<"isFlat" << object->property("flat");

    button->setProperty("Dashi", "true");

    const QMetaObject *metaobject = button->metaObject();
    int count = metaobject->propertyCount();
    for (int i=0; i<count; ++i) {
        QMetaProperty metaproperty = metaobject->property(i);
        const char *name = metaproperty.name();
        QVariant value = object->property(name);
        qDebug() << "name:" << name <<",value:" << value;
    }
}

void c3_1_4()
{

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // QT元对象
    //1,QObject是所有元对象的基类
    //2,Private声明的Q_OBJECT宏定义，可以使用元对象的特性：动态属性、信号、槽
    //3，MOC：元对象编译器

    c3_1();
    // 属性
    c3_1_3();

    // 槽
    c3_1_4();
    return a.exec();
}
