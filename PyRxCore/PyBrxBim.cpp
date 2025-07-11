#include "stdafx.h"
#include "PyBrxBim.h"

#ifdef BRXAPP
#include "PyBimCore.h"
#include "PyBrxIFC.h"
#include "PyBrxBimObject.h"
#include "PyBrxBimImportExport.h"
#include "ifc/IfcApi.h"
#include "ifc/IfcSchemaId.h"


using namespace boost::python;

static BOOST_PYTHON_MODULE(PyBrxBim)
{
    docstring_options local_docstring_options(py_show_user_defined, py_show_py_signatures, py_show_cpp_signatures);

    makePyBimCoreWrapper();

    makePyIfcGuidWrapper();
    makePyIfcStringWrapper();
    makePyIfcBinaryWrapper();
    makePyIfcLogicalWrapper();
    makePyIfcVectorDescWrapper();
    makePyIfcVectorValueWrapper();
    makePyIfcSelectorDescWrapper();
    makePyIfcSelectValueWrapper();
    makePyIfcEnumValueWrapper();
    makePyIfcEntityDescWrapper();
    makePyIfcEntityWrapper();
    makePyIfcHeaderWrapper();
    makePyIfcModelWrapper();
    makePyIfcVariantWrapper();

    makePyBrxBimPoliciesWrapper();
    makePyBrxBimObjectWrapper();
    makePyBrxBimSpatialLocationWrapper();
    makeBrxBimStoryWrapper();
    makeBrxBimBuildingWrapper();
    makeBrxBimRoomWrapper();
    makeBrxBimSpaceWrapper();
    makeBrxBimMaterialWrapper();
    makeBrxBimHatchPatternWrapper();
    makeBrxBimInformationalAssetsWrapper();
    makeBrxBimAssetsWrapper();
    makeBrxBimPlyWrapper();
    makePyBrxBimCompositionWrapper();
    makePyBrxBimProfileWrapper();
    makeBrxBimLinearGeometryWrapper();
    makeBrxBimClassificationWrapper();
    makeBrxBimNameSpacesWrapper();
    makePyBrxBimPropertySetsWrapper();
    makePyBrxBimAttributeSetWrapper();
    makePyBrxBimDialogsWrapper();

    makePyBrxIfcImportOptionsWrapper();
    makePyBrxBimIfcImportInfoWrapper();
    makePyBrxBimIfcImportContextWrapper();
    makePyBimIfcImportReactorWrapper();

    makePyBimIfcProjectDataWrapper();
    makePyBrxIfcExportOptionsWrapper();
    makePyBrxBimIfcExportContextWrapper();
    makePyBimIfcExportReactorWrapper();



    enum_<BimApi::EIfcImportModelOrigin>("IfcImportModelOrigin")
        .value("eIfcGlobalOrigin", BimApi::eIfcGlobalOrigin)
        .value("eIfcSiteLocation", BimApi::eIfcSiteLocation)
        .value("eIfcProjectLocation", BimApi::eIfcProjectLocation)
        .export_values()
        ;

    enum_<BrxBimMaterial::EHatchType>("BimHatchType")
        .value("eHatchNone", BrxBimMaterial::EHatchType::eHatchNone)
        .value("eHatchUserDefined", BrxBimMaterial::EHatchType::eHatchUserDefined)
        .value("eHatchPredefined", BrxBimMaterial::EHatchType::eHatchPredefined)
        .value("eHatchCustom", BrxBimMaterial::EHatchType::eHatchCustom)
        .export_values()
        ;

    enum_<BrxBimPolicies::EPolicyOptions>("BimPolicyOptions")
        .value("eNothing", BrxBimPolicies::EPolicyOptions::eNothing)
        .value("eInstantSave", BrxBimPolicies::EPolicyOptions::eInstantSave)
        .export_values()
        ;

    enum_<BimApi::BimObjectType>("BimObjectType")
        .value("eBimUnknownObject", BimApi::BimObjectType::eBimUnknownObject)
        .value("eBimSpatialLocation", BimApi::BimObjectType::eBimSpatialLocation)
        .value("eBimStory", BimApi::BimObjectType::eBimStory)
        .value("eBimBuilding", BimApi::BimObjectType::eBimBuilding)
        .value("eBimComposition", BimApi::BimObjectType::eBimComposition)
        .value("eBimRoomObject", BimApi::BimObjectType::eBimRoomObject)
        .value("eBimPly", BimApi::BimObjectType::eBimPly)
        .value("eBimMaterial", BimApi::BimObjectType::eBimMaterial)
        .export_values()
        ;

    enum_<BimApi::BimElementType>("BimElementType")
        .value("eBimGenericBuildingElt", BimApi::BimElementType::eBimGenericBuildingElt)
        .value("eBimSection", BimApi::BimElementType::eBimSection)
        .value("eBimWall", BimApi::BimElementType::eBimWall)
        .value("eBimWindow", BimApi::BimElementType::eBimWindow)
        .value("eBimDoor", BimApi::BimElementType::eBimDoor)
        .value("eBimColumn", BimApi::BimElementType::eBimColumn)
        .value("eBimSlab", BimApi::BimElementType::eBimSlab)
        .value("eBimBeam", BimApi::BimElementType::eBimBeam)
        .value("eBimRoom", BimApi::BimElementType::eBimRoom)
        .value("eBimCovering", BimApi::BimElementType::eBimCovering)
        .value("eBimCurtainWall", BimApi::BimElementType::eBimCurtainWall)
        .value("eBimFlowTerminal", BimApi::BimElementType::eBimFlowTerminal)
        .value("eBimFurnishingElement", BimApi::BimElementType::eBimFurnishingElement)
        .value("eBimMember", BimApi::BimElementType::eBimMember)
        .value("eBimPile", BimApi::BimElementType::eBimPile)
        .value("eBimRailing", BimApi::BimElementType::eBimRailing)
        .value("eBimRamp", BimApi::BimElementType::eBimRamp)
        .value("eBimRampFlight", BimApi::BimElementType::eBimRampFlight)
        .value("eBimRoof", BimApi::BimElementType::eBimRoof)
        .value("eBimSite", BimApi::BimElementType::eBimSite)
        .value("eBimStair", BimApi::BimElementType::eBimStair)
        .value("eBimStairFlight", BimApi::BimElementType::eBimStairFlight)
        .value("eBimFooting", BimApi::BimElementType::eBimFooting)
        .value("eBimXReference", BimApi::BimElementType::eBimXReference)
        .value("eBimDistributionControlElement", BimApi::BimElementType::eBimDistributionControlElement)
        .value("eBimDistributionPort", BimApi::BimElementType::eBimDistributionPort)
        .value("eBimDistributionFlowElement", BimApi::BimElementType::eBimDistributionFlowElement)
        .value("eBimDistributionChamberElement", BimApi::BimElementType::eBimDistributionChamberElement)
        .value("eBimEnergyConversionDevice", BimApi::BimElementType::eBimEnergyConversionDevice)
        .value("eBimFlowFitting", BimApi::BimElementType::eBimFlowFitting)
        .value("eBimFlowController", BimApi::BimElementType::eBimFlowController)
        .value("eBimFlowMovingDevice", BimApi::BimElementType::eBimFlowMovingDevice)
        .value("eBimFlowSegment", BimApi::BimElementType::eBimFlowSegment)
        .value("eBimFlowStorageDevice", BimApi::BimElementType::eBimFlowStorageDevice)
        .value("eBimFlowTreatmentDevice", BimApi::BimElementType::eBimFlowTreatmentDevice)
        .value("eBimReinforcingBar", BimApi::BimElementType::eBimReinforcingBar)
        .value("eBimReinforcingMesh", BimApi::BimElementType::eBimReinforcingMesh)
        .value("eBimTendon", BimApi::BimElementType::eBimTendon)
        .value("eBimTendonAnchor", BimApi::BimElementType::eBimTendonAnchor)
        .value("eBimPlate", BimApi::BimElementType::eBimPlate)
        .value("eBimDiscreteAccessory", BimApi::BimElementType::eBimDiscreteAccessory)
        .value("eBimFastener", BimApi::BimElementType::eBimFastener)
        .value("eBimMechanicalFastener", BimApi::BimElementType::eBimMechanicalFastener)
        .value("eBimSchedule", BimApi::BimElementType::eBimSchedule)
        .value("eBimGridAxis", BimApi::BimElementType::eBimGridAxis)
        .value("eBimGrid", BimApi::BimElementType::eBimGrid)
        .value("eBimFlowConnectionPoint", BimApi::BimElementType::eBimFlowConnectionPoint)
        .value("eBimOpening", BimApi::BimElementType::eBimOpening)
        .value("eBimAnnotation", BimApi::BimElementType::eBimAnnotation)
        .value("eBimSpatialElementType", BimApi::BimElementType::eBimSpatialElementType)
        .value("eBimSpaceType", BimApi::BimElementType::eBimSpaceType)
        .value("eBimBuildingType", BimApi::BimElementType::eBimBuildingType)
        .value("eBimStoryType", BimApi::BimElementType::eBimStoryType)
        .value("eBimViewportType", BimApi::BimElementType::eBimViewportType)
        .value("eBimProduct", BimApi::BimElementType::eBimProduct)
        .value("eBimDetail", BimApi::BimElementType::eBimDetail)
        .value("eNoBuildingElement", BimApi::BimElementType::eNoBuildingElement)
        .export_values()
        ;

    enum_<BimApi::ResultStatus>("ResultStatus")
        .value("eOk", BimApi::ResultStatus::eOk)
        .value("eNoDbResidentObject", BimApi::ResultStatus::eNoDbResidentObject)
        .value("eDbNotAccessible", BimApi::ResultStatus::eDbNotAccessible)
        .value("eDbObjectNotSupported", BimApi::ResultStatus::eDbObjectNotSupported)
        .value("eDbNotOpenForWrite", BimApi::ResultStatus::eDbNotOpenForWrite)
        .value("eModelSpaceNotAccessible", BimApi::ResultStatus::eModelSpaceNotAccessible)
        .value("eProjectDbNotAccessible", BimApi::ResultStatus::eProjectDbNotAccessible)
        .value("eAssociatedLibraryNotAccessible", BimApi::ResultStatus::eAssociatedLibraryNotAccessible)
        .value("eNotApplicableForTheseParameters", BimApi::ResultStatus::eNotApplicableForTheseParameters)
        .value("eInvalidSpatialLocation", BimApi::ResultStatus::eInvalidSpatialLocation)
        .value("eInvalidMaterial", BimApi::ResultStatus::eInvalidMaterial)
        .value("eInvalidMaterialComposition", BimApi::ResultStatus::eInvalidMaterialComposition)
        .value("eObjectAlreadyExists", BimApi::ResultStatus::eObjectAlreadyExists)
        .value("eObjectCouldNotBeDeleted", BimApi::ResultStatus::eObjectCouldNotBeDeleted)
        .value("eXmlFileCouldNotBeParsed", BimApi::ResultStatus::eXmlFileCouldNotBeParsed)
        .value("eInvalidXmlFormat", BimApi::ResultStatus::eInvalidXmlFormat)
        .value("eInvalidName", BimApi::ResultStatus::eInvalidName)
        .value("eNotLinearBuildingElement", BimApi::ResultStatus::eNotLinearBuildingElement)
        .value("eInvalidValue", BimApi::ResultStatus::eInvalidValue)
        .value("eNotAssignedToLibrary", BimApi::ResultStatus::eNotAssignedToLibrary)
        .value("eNullObject", BimApi::ResultStatus::eNullObject)
        .value("eNullObjectId", BimApi::ResultStatus::eNullObjectId)
        .value("eNullDatabase", BimApi::ResultStatus::eNullDatabase)
        .value("eNullDocument", BimApi::ResultStatus::eNullDocument)
        .value("eNullString", BimApi::ResultStatus::eNullString)
        .value("eObjectNotExisting", BimApi::ResultStatus::eObjectNotExisting)
        .value("eObjectNotSupported", BimApi::ResultStatus::eObjectNotSupported)
        .value("eNoProfileAssigned", BimApi::ResultStatus::eNoProfileAssigned)
        .value("eNoData", BimApi::ResultStatus::eNoData)
        .value("eUnknownData", BimApi::ResultStatus::eUnknownData)
        .value("eWrongDataType", BimApi::ResultStatus::eWrongDataType)
        .value("eUnassignedEntity", BimApi::ResultStatus::eUnassignedEntity)
        .value("eBimNotImplementedYet", BimApi::ResultStatus::eBimNotImplementedYet)
        .value("eBimNotAvailable", BimApi::ResultStatus::eBimNotAvailable)
        .value("eInternalError", BimApi::ResultStatus::eInternalError)
        .value("eUnknownError", BimApi::ResultStatus::eUnknownError)
        .value("eInvalidIndex", BimApi::ResultStatus::eInvalidIndex)
        .value("eInvalidInput", BimApi::ResultStatus::eInvalidInput)
        .value("eNoNameSpace", BimApi::ResultStatus::eNoNameSpace)
        .value("eNameSpaceAlreadyExists", BimApi::ResultStatus::eNameSpaceAlreadyExists)
        .value("eNoPropertySet", BimApi::ResultStatus::eNoPropertySet)
        .value("ePropertySetAlreadyExists", BimApi::ResultStatus::ePropertySetAlreadyExists)
        .value("eNoProperty", BimApi::ResultStatus::eNoProperty)
        .value("eNotImplemented", BimApi::ResultStatus::eNotImplemented)
        .value("eInvalidArgument", BimApi::ResultStatus::eInvalidArgument)
        .value("eNoAttributeSet", BimApi::ResultStatus::eNoAttributeSet)
        .export_values()
        ;

    enum_<Ice::IfcApi::Result>("IfcResult")
        .value("eOk", Ice::IfcApi::Result::eOk)
        .value("eNotInitialized", Ice::IfcApi::Result::eNotInitialized)
        .value("eWrongName", Ice::IfcApi::Result::eWrongName)
        .value("eWrongType", Ice::IfcApi::Result::eWrongType)
        .value("eInternalError", Ice::IfcApi::Result::eInternalError)
        .export_values()
        ;

    enum_<Ice::IfcApi::ValueType>("IfcValueType")
        .value("eBool", Ice::IfcApi::ValueType::eBool)
        .value("eInt", Ice::IfcApi::ValueType::eInt)
        .value("eUInt", Ice::IfcApi::ValueType::eUInt)
        .value("eReal", Ice::IfcApi::ValueType::eReal)
        .value("eString", Ice::IfcApi::ValueType::eString)
        .value("eEntity", Ice::IfcApi::ValueType::eEntity)
        .value("eLogical", Ice::IfcApi::ValueType::eLogical)
        .value("eBinary", Ice::IfcApi::ValueType::eBinary)
        .value("eGuid", Ice::IfcApi::ValueType::eGuid)
        .value("eEnum", Ice::IfcApi::ValueType::eEnum)
        .value("eSelect", Ice::IfcApi::ValueType::eSelect)
        .value("eVector", Ice::IfcApi::ValueType::eVector)
        .value("eEmpty", Ice::IfcApi::ValueType::eEmpty)
        .export_values()
        ;

    enum_<Ice::EIfcSchemaId>("IfcSchemaId")
        .value("eIFC2X3", Ice::EIfcSchemaId::eIFC2X3)
        .value("eIFC4", Ice::EIfcSchemaId::eIFC4)
        .value("eIFC4X1", Ice::EIfcSchemaId::eIFC4X1)
        .value("eIfcSchemaLast", Ice::EIfcSchemaId::eIfcSchemaLast)
        .export_values()
        ;

    enum_<EBimCategory>("BimCategory")
        .value("kStandard", EBimCategory::kStandard)
        .value("kBricsys", EBimCategory::kBricsys)
        .value("kIFC2x3", EBimCategory::kIFC2x3)
        .value("kIFCCustom", EBimCategory::kIFCCustom)
        .value("kUser", EBimCategory::kUser)
        .value("kQuantity", EBimCategory::kQuantity)
        .value("kClassfication", EBimCategory::kClassfication)
        .value("kIFC4", EBimCategory::kIFC4)
        .value("kIFCQuantity", EBimCategory::kIFCQuantity)
        .export_values()
        ;

    enum_<EBimSpaceRepresentation>("BimSpaceRepresentation")
        .value("eSolid", EBimSpaceRepresentation::eSolid)
        .value("eFootprint", EBimSpaceRepresentation::eFootprint)
        .export_values()
        ;


    enum_<BimApi::BrxIfcExportOptions::EModelViewDefType>("IfcModelViewDefType")
        .value("eNotSet", BimApi::BrxIfcExportOptions::EModelViewDefType::eNotSet)
        .value("eReference", BimApi::BrxIfcExportOptions::EModelViewDefType::eReference)
        .value("eDesignTransfer", BimApi::BrxIfcExportOptions::EModelViewDefType::eDesignTransfer)
        .export_values()
        ;

#if defined(_BRXTARGET) && (_BRXTARGET >= 250)
    enum_<BimApi::BrxIfcExportOptions::EOptionFlags>("IfcExportOptionFlags")
        .value("eBaseQuantities", BimApi::BrxIfcExportOptions::EOptionFlags::eBaseQuantities)
        .value("eIncludeFrozenHidden", BimApi::BrxIfcExportOptions::EOptionFlags::eIncludeFrozenHidden)
        .value("eExplodeXrefs", BimApi::BrxIfcExportOptions::EOptionFlags::eExplodeXrefs)
        .value("eAggregateMultiPly", BimApi::BrxIfcExportOptions::EOptionFlags::eAggregateMultiPly)
        .value("eMergeGuidForBlocks", BimApi::BrxIfcExportOptions::EOptionFlags::eMergeGuidForBlocks)
        .value("eMergeGuidForXrefs", BimApi::BrxIfcExportOptions::EOptionFlags::eMergeGuidForXrefs)
        .value("eTesselateBSplines", BimApi::BrxIfcExportOptions::EOptionFlags::eTesselateBSplines)
        .value("eSweptSolidsAsBRep", BimApi::BrxIfcExportOptions::EOptionFlags::eSweptSolidsAsBRep)
        .value("eProfileCenterOfGravity", BimApi::BrxIfcExportOptions::EOptionFlags::eProfileCenterOfGravity)
        .export_values()
        ;
#endif
}

void initPyBrxBimModule()
{
    PyImport_AppendInittab(PyBrxBimNamespace, &PyInit_PyBrxBim);
}

#endif//BRXAPP
