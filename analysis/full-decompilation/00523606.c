
void __fastcall FUN_00523606(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*param_1 + 0x174))(1,0);
    FUN_004e609e();
    cVar1 = FUN_004e6133();
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x58))(1,0x80);
    }
    (**(code **)(*param_1 + 0x90))(4,1);
    piVar2 = (int *)FUN_005e7743();
    iVar3 = (**(code **)(*piVar2 + 0x10))(5);
    param_1[0x45] = iVar3;
    uVar4 = FUN_005e74ca(0);
    FUN_005dde6d(uVar4);
    if (param_1[0x3a] != 0) {
      (**(code **)(*param_1 + 0x20))(param_1[0x3a]);
    }
    local_8 = (int *)0x0;
    FUN_005a5631(0x1380,&local_8,4);
    FUN_005a5e48(local_8);
  }
  FUN_005dbf32();
  return;
}

