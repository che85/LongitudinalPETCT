/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLVolumeRenderingParametersNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
// .NAME vtkMRMLLongPETCTFindingNode
// This node keeps pointers to the two elements of the Finding: annotation
// and markup.
//
// Annotation element will (eventually) contain the Finding template and the
// user-initialized fields of the template.
//
// Markup element will point to the hierarchy of the markup elements.
//
// On export/import, this node will be used by the IO logic to determine how
// to code the formatted Finding.
// .SECTION Description
// This node keeps pointers to the two elements of the Finding: annotation
// and markup.
//

#ifndef __vtkMRMLLongPETCTFindingNode_h
#define __vtkMRMLLongPETCTFindingNode_h

// MRML includes
//#include "vtkDoubleArray.h"
#include "vtkMRML.h"
#include "vtkMRMLNode.h"

#include <vtkSlicerLongPETCTModuleMRMLExport.h>

class map;
class vector;

class vtkMRMLLongPETCTStudyNode;
class vtkMRMLAnnotationROINode;
class vtkMRMLScalarVolumeNode;
class vtkMRMLLongPETCTSegmentationNode;

#include <vtkMRMLAnnotationROINode.h>
#include <vtkNew.h>
#include <vtkSmartPointer.h>
/// \ingroup Slicer_QtModules_LongPETCTFindingNode
class VTK_SLICER_LONGPETCT_MODULE_MRML_EXPORT vtkMRMLLongPETCTFindingNode : public vtkMRMLNode
{
  public:   

  static vtkMRMLLongPETCTFindingNode *New();
  vtkTypeMacro(vtkMRMLLongPETCTFindingNode,vtkMRMLNode);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual vtkMRMLNode* CreateNodeInstance();

  /// Set node attributes
  virtual void ReadXMLAttributes( const char** atts);

  /// Write this node's information to a MRML file in XML format.
  virtual void WriteXML(ostream& of, int indent);

  /// Copy the node's attributes to this object
  virtual void Copy(vtkMRMLNode *node);

  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() {return "Finding";};


  bool AddSegmentationForStudy(vtkMRMLLongPETCTStudyNode* study, vtkMRMLLongPETCTSegmentationNode* segmentation);
  vtkMRMLLongPETCTSegmentationNode* RemoveSegmentationForStudy(const vtkMRMLLongPETCTStudyNode* study);

  vtkMRMLLongPETCTSegmentationNode* GetSegmentationForStudy(const vtkMRMLLongPETCTStudyNode* study);

  vtkGetMacro(TypeName, const char*);
  vtkSetMacro(TypeName, const char*);

  //vtkGetMacro(ColorID, int);
  //vtkSetMacro(ColorID, int);

  vtkGetMacro(SegmentationROI,vtkMRMLAnnotationROINode*);
  vtkSetMacro(SegmentationROI,vtkMRMLAnnotationROINode*);

  int GetColorID();
  void SetColorID(int id);

protected:
  vtkMRMLLongPETCTFindingNode();
  ~vtkMRMLLongPETCTFindingNode();
  vtkMRMLLongPETCTFindingNode(const vtkMRMLLongPETCTFindingNode&);
  void operator=(const vtkMRMLLongPETCTFindingNode&);

  std::map<vtkMRMLLongPETCTStudyNode*,vtkMRMLLongPETCTSegmentationNode*> StudyToSegmentationMap;
  vtkMRMLAnnotationROINode* SegmentationROI;

  const char* TypeName;
  int ColorID;

};

#endif

