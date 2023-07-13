#include <QCoreApplication>
#include <QTimer>
//#include <QDebug>
#include "test.hpp"

void	printEcho(void)
{
	QTextStream	qin(stdin);
	QTextStream	qout(stdout);
	QString		input;

	qout << "Tell me something to echo, please: ";
	qout.flush();
	input = qin.readLine();
	qout << input << "\n";
}

void	printHelloWorld(void)
{
	QTextStream	out(stdout);

	out << "Hello World!\n";
}

void	useVariables(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int	main(int argc, char **argv)
{
	QCoreApplication	a(argc, argv);
	Test			*test = new Test(nullptr, "test");
	QTimer			timer;
	Test			*dog = new Test(test, "dog");
	Test			*cat = new Test(dog, "cat");

	useVariables(argc, argv);
	//QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);
	delete(test);
	(void)cat;
	timer.singleShot(7000, &a, &QCoreApplication::quit); // counts in a separate thread
	qInfo() << "A =" << &a;

	return a.exec();
}
