#### 定义几何结构的可视化特性
```
G4VisAttributes* simpleAlSVisAtt_Ellipse= new G4VisAttributes(G4Colour::White());//颜色：白色
simpleAlSVisAtt_Ellipse->SetVisibility(true);
simpleAlSVisAtt_Ellipse->SetForceSolid(true);//实体，设置为false的时候，显示为线框
EPLPhantom->SetVisAttributes(simpleAlSVisAtt_Ellipse);//将可视化特性与逻辑体关联起来
```

## sensitive
#### using G4MultiFunctionalDetect
```
G4MultiFunctionalDetector* xxx = new G4MultiFunctionalDetector("Detector_name");
G4VPrimitiveScorer* primitive;
primitive = new G4PSEnergyDeposit("eDep",0);//记录探测器沉积能量
xxx->RegisterPrimitive(primitive);

G4SDManager* SDManager= G4SDManager::GetSDMpointer();
SDManager->AddNewDetector(det);//向探测器的管理器注册
SetSensitiveDetector(xxx);//也可以用世界LogVolume ->SetSensiveDetector(xxx);

## save as ntuple


G4AnalysisManager用于构建root软件分析管理对象，analysisManager-\textgreater SetVerboseLevel(1)表示显示精度的级别,后面几行用于创建元组，建立root管理的表头。然后在beginOfRunAction定义了需要输出的文件，在EndOfRunAction方法中，将需要的数据存储到文件中，并关闭了root等文件， G4AnalysisManager* analysisManager = G4AnalysisManager::Instance()用于找到分析管理对象指针，用于进一步操作。
```
 G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
	  G4cout << "Using " << analysisManager->GetType() << G4endl;
	  // Create directories
	  analysisManager->SetVerboseLevel(1);
	  // Creating ntuple
	  analysisManager->CreateNtuple("Vertex", "Vertex Info");
	  analysisManager->CreateNtupleDColumn(0,"x");
	  analysisManager->CreateNtupleDColumn(0,"y");
	  analysisManager->CreateNtupleDColumn(0,"z");
	  analysisManager->CreateNtupleDColumn(0,"Theta");
	  analysisManager->CreateNtupleDColumn(0,"p");
	  analysisManager->CreateNtupleDColumn(0,"E");
	  analysisManager->FinishNtuple(0);
	  ```
### EventAction

事件是一个包含所有被模拟事件的输入输出信息的类的实例，通俗的来讲，一个粒子从入射到相关所有的反应结束，即为一个事件，事件用于统计一个粒子入射后的相关反应情况，可以统计初级粒子属性，或者通过step中传递过来的参数，累加一个事件中总的能量变化等功能。在本代码中主要是在事件结束后完成了初级粒子相关信息的统计，主要涉及到统计中Ntuple的使用，其中前三行代码分别获得分析管理类，粒子顶点，初级粒子对象指针，方便调用其方法，然后通过FillNtupleDColumn方法将数据填充到Ntuple中，第一参数0表示添加到元表的第一行中，第二个参数表示添加Ntuple对应的列中，第三个参数表示输入相应的值，这部分具体可以查看生成的root文件，可以很明了的看到相应的区别，这里统计了初级粒子的X、Y、Z轴坐标，散射角度、总的动量和动能。

```
	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();	
	G4PrimaryVertex* gpVertex = event->GetPrimaryVertex();
	G4PrimaryParticle* gpParticle = gpVertex->GetPrimary();
	G4ThreeVector pd =  gpParticle->GetMomentumDirection();
	G4double theta = acos(pd.getY()/pd.getR());
	// fill ntuple
	analysisManager->FillNtupleDColumn(0, 0, gpVertex->GetX0()/mm);
	analysisManager->FillNtupleDColumn(0, 1, gpVertex->GetY0()/mm);
	analysisManager->FillNtupleDColumn(0, 2, gpVertex->GetZ0()/mm);
	analysisManager->FillNtupleDColumn(0, 3, theta);
	analysisManager->FillNtupleDColumn(0, 4, gpParticle->GetTotalMomentum()/MeV);
	analysisManager->FillNtupleDColumn(0, 5, gpParticle->GetKineticEnergy()/MeV);
	analysisManager->AddNtupleRow(0);

```

### StepAction
step是Geant4}中最小的仿真单位，Geant4以step作为基本单位，统计每个step开始和结束的相关信息，获得相应的数据，再决定下一步如何仿真，可以统计每个step之前和之后所在的逻辑体，能量，动量，粒子质量等相关信息。用户可以从G4UserSteppingAction中派生出用户自定义行为，实现需要的功能，G4UserSteppingAction中包含虚函数UserSteppingAction，用户可以在该函数中定义自己需要实现的功能。
如下代码表示获得当前step开始点和结束点的物理体、当前step的轨迹对象指针(track是比step稍微打一点的仿真单位，多个step构成一个track)、总能量、动能、位置、粒子名称、动量方向。

```
 G4VPhysicalVolume* pre_volume
	    = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
	  G4VPhysicalVolume* post_volume
	    = step->GetPostStepPoint()->GetTouchableHandle()->GetVolume();
	  G4Track* track = step->GetTrack();
	  // energy deposit
	  G4double edep = step->GetTotalEnergyDeposit();
	  G4ThreeVector p = step->GetPreStepPoint()->GetPosition();
	  G4double e=step->GetPreStepPoint()->GetKineticEnergy();
	  G4String name = step->GetTrack()->GetDefinition()->GetParticleName();
	  G4double x=p.getX();
	  G4double y=p.getY();
	  G4double z=p.getZ();
	  G4ThreeVector pd = step->GetPreStepPoint()->GetMomentumDirection();
	  G4double theta = acos(pd.getY()/pd.getR())
	  ```

```