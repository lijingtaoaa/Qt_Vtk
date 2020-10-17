#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_qttest.h"
#include <qfiledialog.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkEventQtSlotConnect.h>
namespace NP1
{
	class QtTest : public QMainWindow
	{
		Q_OBJECT
	public:
		virtual void resizeEvent(QResizeEvent* event);
		QtTest(QWidget* parent = Q_NULLPTR);
		QVTKWidget* getVTKWideget()
		{
			return ui.qvtkWidget;
		}
	public slots:
		void test(vtkObject *);
		void openFile();
		void draw();
	private:
		Ui::QtTestClass ui;
		vtkRenderWindowInteractor* interactor;
		vtkRenderWindow* renderWindow;
		vtkSmartPointer<vtkRenderer> renderer;
		vtkEventQtSlotConnect* vtkCon;
	};

}
