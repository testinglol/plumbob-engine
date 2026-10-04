
int * FUN_004e978e(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char local_24 [12];
  undefined4 local_18;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = FUN_004e8d71(param_1);
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    iVar2 = FUN_0043acf5(iVar2);
    piVar3 = (int *)0x0;
    if (iVar2 != 0) {
      uVar4 = FUN_00440b6d(iVar2);
      if ((short)uVar4 != 0) {
        uVar5 = FUN_00407498((int)(short)uVar4);
        piVar3 = (int *)FUN_006359f2(uVar5,0,&cXObject::RTTI_Type_Descriptor,
                                     &cXPerson::RTTI_Type_Descriptor,0);
        if (piVar3 != (int *)0x0) {
          FUN_00434876();
          local_c = 0;
          local_8 = 0;
          cVar1 = FUN_00434895(local_24,&local_c);
          if (cVar1 == '\0') {
            FUN_0044127f(uVar4);
            piVar3 = (int *)0x0;
          }
          else {
            if (local_24[0] == '\0') {
              local_18 = 1;
            }
            (**(code **)(*piVar3 + 0x88))(&local_c,local_18,0,0);
          }
        }
      }
    }
  }
  return piVar3;
}

