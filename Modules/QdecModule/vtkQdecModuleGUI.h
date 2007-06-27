/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkQdecModuleGUI.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
#ifndef __vtkQdecModuleGUI_h
#define __vtkQdecModuleGUI_h

#include "vtkQdecModuleWin32Header.h"
#include "vtkSlicerModuleGUI.h"

#include "vtkQdecModule.h"
#include "vtkMRMLScene.h"
#include "vtkQdecModuleLogic.h"

class vtkKWFrame;
class vtkKWScaleWithEntry;
class vtkKWPushButton;
class vtkSlicerNodeSelectorWidget;
class vtkKWLoadSaveButtonWithLabel;
class vtkKWEntryWithLabel;
class vtkKWMultiColumnListWithScrollbars;
class vtkKWListBoxWithScrollbarsWithLabel;
class VTK_QDECMODULE_EXPORT vtkQdecModuleGUI : public vtkSlicerModuleGUI
{
public:

  static vtkQdecModuleGUI *New();
 // vtkTypeMacro(vtkQdecModuleGUI,vtkSlicerModuleGUI);

  void PrintSelf(ostream& os, vtkIndent indent);

  void SetAndObserveModuleLogic ( vtkQdecModuleLogic *logic )
  { this->SetAndObserveLogic ( vtkObjectPointer (&this->Logic), logic ); }

   // Description: Get/Set MRML node
  vtkGetObjectMacro (Logic, vtkQdecModuleLogic);
  vtkSetObjectMacro (Logic, vtkQdecModuleLogic);
  
  // Description:
  // Create widgets
  virtual void BuildGUI ( );

  // Description:
  // Add obsereves to GUI widgets
  virtual void AddGUIObservers ( );
  
  // Description:
  // Remove obsereves to GUI widgets
  virtual void RemoveGUIObservers ( );
  virtual void RemoveMRMLNodeObservers ( );
  virtual void RemoveLogicObservers ( );
  
  // Description:
  // Process events generated by Logic
  virtual void ProcessLogicEvents ( vtkObject *caller, unsigned long event,
                                  void *callData ){};

  // Description:
  // Process events generated by GUI widgets
  virtual void ProcessGUIEvents ( vtkObject *caller, unsigned long event,
                                  void *callData );

  // Description:
  // Process events generated by MRML
  virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event, 
                                  void *callData);
  // Description:
  // Describe behavior at module startup and exit.
  virtual void Enter ( ){};
  virtual void Exit ( ){};

  // Description:
  // Get methods on class members ( no Set methods required. )
  vtkGetObjectMacro ( LoadTableButton, vtkKWLoadSaveButtonWithLabel );
  vtkGetObjectMacro ( ContinuousFactorsListBox, vtkKWListBoxWithScrollbarsWithLabel );
  vtkGetObjectMacro ( DiscreteFactorsListBox, vtkKWListBoxWithScrollbarsWithLabel );

  // Description:
  // Update the elements of the multi column list box
  void UpdateElement(int row, int col, char *str);
  
protected:
  vtkQdecModuleGUI();
  ~vtkQdecModuleGUI();
  vtkQdecModuleGUI(const vtkQdecModuleGUI&);
  void operator=(const vtkQdecModuleGUI&);

  // Description:
  // Updates GUI widgets based on parameters values in MRML node
  void UpdateGUI();

  // Description:
  // Updates parameters values in MRML node based on GUI widgets 
  void UpdateMRML();

  // Description:
  // GUI elements
  vtkKWLabel *NAMICLabel;
  vtkKWLoadSaveButtonWithLabel* LoadTableButton;
  vtkKWListBoxWithScrollbarsWithLabel *DiscreteFactorsListBox;
  vtkKWListBoxWithScrollbarsWithLabel *ContinuousFactorsListBox;
  vtkKWPushButton* ApplyButton;
  vtkKWMultiColumnListWithScrollbars *MultiColumnList;
  vtkKWLoadSaveButtonWithLabel* SubjectsDirectoryButton;
  vtkKWEntryWithLabel *DesignEntry;
  
  // Description:
  // Pointer to the module's logic class
  vtkQdecModuleLogic *Logic;

};

#endif

