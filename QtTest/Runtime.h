#pragma once
#include "qttest.h"
#include "QVTKWidget.h"
#include <QVTKInteractor.h>

namespace NP1
{
	class Runtime
	{
	private:
		QtTest* w;
		static Runtime* instance;
		QVTKWidget* VtkWidget;
	private:
		Runtime();
	public:

		static Runtime* getInstance();
		QtTest* getMainWindow();
		QVTKWidget* getVTKWidget();
	};
}


