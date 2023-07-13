#ifndef TEST_HPP
# define TEST_HPP

#include <QObject>
#include <QString>
#include <QDebug>

class Test : public QObject
{
	Q_OBJECT
	public:
		explicit	Test(QObject *parent);
		explicit	Test(QObject *parent, QString const name);
				~Test(void);

	signals:
		void		close();
	
	public slots:
		void		slotFunctionThatEmitsClose(void);

	private:
		//
};

#endif
