#include "qtutils.h"


QWidget *makeHBox(QWidget *parent, QWidget *a, QWidget *b) {
    QWidget *ret = new QWidget(parent);
    QHBoxLayout *layout = new QHBoxLayout(ret);
    ret->setLayout(layout);
    if (a)
        layout->addWidget(a);
    if (b)
        layout->addWidget(b);
    return ret;
}


QWidget *makeVBox(QWidget *parent, QWidget *a, QWidget *b) {
    QWidget *ret = new QWidget(parent);
    QVBoxLayout *layout = new QVBoxLayout(ret);
    ret->setLayout(layout);
    if (a)
        layout->addWidget(a);
    if (b)
        layout->addWidget(b);
    return ret;
}
