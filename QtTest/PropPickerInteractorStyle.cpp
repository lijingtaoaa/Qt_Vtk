#include "PropPickerInteractorStyle.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkPropPicker.h"
void PropPickerInteractorStyle::OnLeftButtonDown()
{
	int* clickPos = this->GetInteractor()->GetEventPosition();
	vtkSmartPointer<vtkPropPicker> picker = vtkSmartPointer<vtkPropPicker>::New();
	picker->Pick(clickPos[0], clickPos[1],0, this->GetDefaultRenderer());

	double* pos = picker->GetPickPosition();
	if (this->LastPickedActor)
	{
		this->LastPickedActor->GetProperty()->DeepCopy(this->LastPickedProperty);
	}
	this->LastPickedActor = picker->GetActor();
	if (this->LastPickedActor)
	{
		this->LastPickedProperty->DeepCopy(this->LastPickedActor->GetProperty());
		this->LastPickedActor->GetProperty()->SetColor(1.0, 0, 0);
		this->LastPickedActor->GetProperty()->SetDiffuse(1.0);
		this->LastPickedActor->GetProperty()->SetSpecular(0.0);
		vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
	}

}