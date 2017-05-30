GeneratePrimaries(G4Event*)  purely function

在这个函数里面要加入

```
    fGun->GeneratePrimaryVertex(anEvent);
    fGPS->GeneratePrimaryVertex(anEvent);
```
GeneratePrimaryVertex() 

vertex //顶点

在构建函数可以初始化其他的参量， 初始化位置是没有用的
