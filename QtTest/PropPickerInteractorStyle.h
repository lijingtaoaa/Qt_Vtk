#pragma once
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkProperty.h>
#include <vtkActor.h>
class PropPickerInteractorStyle :
	public vtkInteractorStyleTrackballCamera
{
public:
	static PropPickerInteractorStyle* New();
	vtkTypeMacro(PropPickerInteractorStyle, vtkInteractorStyleTrackballCamera);
	PropPickerInteractorStyle()
	{
		LastPickedActor = NULL;
		LastPickedProperty = vtkProperty::New();
	}
	virtual ~PropPickerInteractorStyle()
	{
		LastPickedProperty->Delete();
	}
	void OnLeftButtonDown();
private:
	vtkActor* LastPickedActor;
	vtkProperty* LastPickedProperty;
};

