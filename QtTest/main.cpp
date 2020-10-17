#include <vtkAutoInit.h>
#include <vtkoutputwindow.h>
#include <Runtime.h>
#include "qttest.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
#include "QVTKOpenGLWidget.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
using namespace NP1;
int main(int argc, char* argv[])
{
	vtkOutputWindow::SetGlobalWarningDisplay(0);
	QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
	QApplication a(argc, argv);

	QtTest* w = Runtime::getInstance()->getMainWindow();
	w->show();
	return a.exec();
}


