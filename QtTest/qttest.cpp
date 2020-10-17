#include "qttest.h"
#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkCamera.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QVTKOpenGLWidget.h>
#include <vtkContextView.h>
#include <vtkTable.h>
#include <vtkFloatArray.h>
#include <vtkChartXY.h>
#include <vtkContextScene.h>
#include <vtkPlot.h>
#include <vtkTimerLog.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkDistanceWidget.h>
#include <vtkDistanceRepresentation.h>
#include <vtkScalarBarActor.h>
#include <vtkScalarBarWidget.h>
#include <vtkLookupTable.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkTextWidget.h>
#include <vtkTextRepresentation.h>
#include "PropPickerInteractorStyle.h"
#include "Runtime.h"
using namespace NP1;
QtTest::QtTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->renderWindow = this->ui.qvtkWidget->GetRenderWindow();
	this->interactor = this->renderWindow->GetInteractor();
	this->renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<PropPickerInteractorStyle> propPicker = vtkSmartPointer<PropPickerInteractorStyle>::New();
	propPicker->SetInteractor(interactor);
	vtkCon = vtkEventQtSlotConnect::New();
	vtkCon->Connect(interactor, vtkCommand::LeftButtonPressEvent, this, SLOT(test(vtkObject*)));
}
void QtTest::test(vtkObject * obj)
{
	std::cout << obj->GetClassName() << endl;
}
void QtTest::openFile()
{
	QString fileName = QFileDialog::getOpenFileName();
	ui.lineEdit_fileName->setText(fileName);
}
class ResizeCommand :vtkCommand
{
	virtual void Execute(vtkObject* caller, unsigned long eventId,
		void* callData)
	{
		
	}
};
void QtTest::resizeEvent(QResizeEvent* event)
{
	this->ui.qvtkWidget->GetRenderWindow()->GetInteractor()->Render();
 }
void QtTest::draw()
{
	vtkSmartPointer<vtkConeSource> cone = vtkConeSource::New();
	cone->SetHeight(3.0);
	cone->SetRadius(1.0);
	cone->SetResolution(10);

	vtkSmartPointer<vtkPolyDataMapper> coneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	coneMapper->SetInputConnection(cone->GetOutputPort());
	vtkSmartPointer<vtkActor> coneActor = vtkSmartPointer<vtkActor>::New();
	coneActor->SetMapper(coneMapper);

	vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer <vtkRenderer>::New();
	ren1->AddActor(coneActor);
	ren1->SetBackground(0.1, 0.2, 0.4);
	ren1->ResetCamera();
	renderWindow->AddRenderer(ren1);	
		
	cout<<interactor->GetClassName()<<endl;
	//interactor->SetPicker();

	interactor->Initialize();
	interactor->Render();
	interactor->Start();
}

