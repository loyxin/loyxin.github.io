---
layout: post
title:  "geant4 Detector"
categories: geant4
tags:  geant4 模拟
author: loyxin
mathjax: true
---

* content
{:toc}

## DetectorConstruction.cc

- Method Construct()
    - Define materials
    - Define solids and volumes of the geometry
    - Build the tree hierarchy of volumes
    - Define visualization attributes
    - Return the world physical volume!
- Method ConstructSDAndField()
    - Assign magnetic field to volumes / regions
    - Define sensitive detectors and assing them to volumes

### 材料的定义

```cpp
// use nist
G4NistManager* manager = G4NistManager::Instance();
G4Material* H2O = manager->FindOrBuildMaterial("G4_WATER");

// user define
a = 14.01*g/mole;
G4Element* elN = new G4Element(name="Nitrogen",symbol="N", z= 7., a);
a = 16.00*g/mole;
G4Element* elO = new G4Element(name="Oxygen",symbol="O", z= 8., a);
density = 1.290*mg/cm3;
G4Material* Air = new G4Material(name="Air", density, ncomponents=2);
Air->AddElement(elN, 70.0*perCent);
Air->AddElement(elO, 30.0*perCent);
```
### Geometry


构建过程为，构建 Solid->logicalVolume->PVPlacement, 可以查找相应的 api

比如长1m X 1m X 1m 的长方体空气材料放在原点处
```cpp
G4NistManager* manager = G4NistManager::Instance();
G4Material* Air = manager->FindOrBuildMaterial("G4_Air");

G4double x = 1.*m, y = 1.*m, z = 1.*m;

G4Box* box = new G4Box("test",x,y,z);

G4LogicalVolume* logical = new G4LogicalVolume(box,Air,"logtest");

new G4PVPlacement(0,//no rotation
                    0,// no transportation
                    logical,// logical volume point
                    "boxtest",//name
                    NULL,//MotherLogical
                    false,//For future use. Can be set to false
                    0,//Integer which identifies this placement
                    false//check for overlaps 
```

介绍 logical volumes 和 Physical Volumes

```cpp
//logical volumes
    G4LogicalVolume( G4VSolid*             pSolid,
                     G4Material*           pMaterial,
                     const G4String&       Name,
                     G4FieldManager*       pFieldMgr=0,
                     G4VSensitiveDetector* pSDetector=0,
                     G4UserLimits*         pULimits=0,
                     G4bool                Optimise=true )
```
前三个不说了， pFieldMgr 是注册磁场， pSDetector 是注册敏感探测器， pULimits 是设置阈值的， Optimise 是优化，暂时不知道

```cpp
//physical volumes
    G4PVPlacement(       G4RotationMatrix*  pRot,
                   const G4ThreeVector&     tlate,
                         G4LogicalVolume*   pCurrentLogical,
                   const G4String&          pName,
                         G4LogicalVolume*   pMotherLogical,
                         G4bool             pMany,
                         G4int              pCopyNo,
                         G4bool             pSurfChk=false )
```

 pRot	| Rotation with respect to its mother volume 
tlate	| Translation with respect to its mother volume
pCurrentLogical	| The associated Logical Volume
pName	| String identifier for this placement
pMotherLogical	| The associated mother volume
pMany	| For future use. Can be set to false
pCopyNo	| Integer which identifies this placement
pSurfChk	| if true activates check for overlaps with existing volumes


### EM Fields
#### 均匀场

```cpp
// 某个 Volume
G4ThreeVector field(0,1.*tesla,0);
G44UniformMagField* magField = new G4UniformMagField(field);
G4FieldManager* fieldMgr =
G4TransportationManager::GetTransportationManager()
->GetFieldManager();
fieldMgr->SetDetectorField(magField);
fieldMgr->CreateChordFinder(magField);

// 全部区域加场
G4GlobalMagFieldMessenger* fMagFieldMessenger =
new G4GlobalMagFieldMessenger(field)
```

#### 非均匀场
创建一个继承 `G4MagneticField`新的类来实现$\vec{B}=f(\vec{x},t)$
```cpp
// MyField 继承 G4MagneticField 新的类
MyField* myField = new MyField();
G4FieldManager* fieldMgr =
G4TransportationManager::GetTransportationManager()
->GetFieldManager();
fieldMgr->SetDetectorField(myField);
fieldMgr->CreateChordFinder(myField);
```

也可以在 `logicalVolume` 下用相应的方法设置场

```cpp
MyField* myField = new MyField();
G4FieldManager* localFieldMgr =
new G4FieldManager(myField);
G4bool allLocal = true;
logicVolWithField//you volume
->SetFieldManager(localFieldMgr, allLocal);
```

敏感探测器在[敏感探测器章节]({{ site.url }}/2017/09/11/geant4-敏感探测器/)介绍