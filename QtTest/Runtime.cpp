#include "Runtime.h"
using namespace NP1;
Runtime::Runtime()
{
	w = nullptr;
}
Runtime* Runtime::instance = nullptr;
QVTKWidget* Runtime:: getVTKWidget()
{
	if (VtkWidget == nullptr)
	{
		VtkWidget= new QVTKWidget();
	}
	return VtkWidget;
}
 Runtime* Runtime::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Runtime();
	}
	return instance;
}
 QtTest* Runtime::getMainWindow()
 {
	 if (w == nullptr)
	 {
		 w= new QtTest();
	 }
	 return w;
 }
