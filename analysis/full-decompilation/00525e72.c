
void __fastcall FUN_00525e72(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x174))(1,0);
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x58))(1,0x80);
    }
    (**(code **)(*param_1 + 0x90))(0x20,0);
    (**(code **)(*param_1 + 0x90))(4,0);
    (**(code **)(*param_1 + 0x90))(0x10000,1);
    piVar2 = (int *)FUN_005e7743();
    iVar3 = (**(code **)(*piVar2 + 0x10))(5);
    param_1[0x45] = iVar3;
    uVar4 = FUN_005e74ca(3);
    FUN_005dde6d(uVar4);
    if (param_1[0x3c] != 0) {
      (**(code **)(*param_1 + 0x20))(param_1[0x3c]);
    }
    FUN_005a5631(0x1380,param_1 + 0x46,4);
  }
  FUN_005dbf32();
  return;
}

