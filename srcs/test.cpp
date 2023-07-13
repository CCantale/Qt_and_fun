#include "test.hpp"
#include <unistd.h>

Test::Test(QObject *parent, QString const name) : QObject(parent)
{
	this->setObjectName(name);
	qInfo() << "I was created:" << this << this->parent();
}

Test::~Test(void)
{
	qInfo() << "I just died: " << this << this->parent();
}

void Test::slotFunctionThatEmitsClose(void)
{
	qInfo() << "Hello from a humble slot!\n";
	sleep(6);
	emit close();
}

#include "moc_test.cpp"
