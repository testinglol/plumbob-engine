
void __thiscall FUN_00417da0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (cVar1 == '\0') {
      iVar4 = -0x2d;
    }
    else {
      iVar2 = FUN_00418360(param_1[6],param_2,&local_8,0);
      if (iVar2 == 0) {
        iVar4 = -99;
      }
      else {
        iVar4 = FUN_00417fc5(iVar2);
        if (iVar4 == 0) {
          FUN_00418296(param_1[6],iVar2);
          return;
        }
      }
    }
    FUN_004659fc(iVar4);
  }
  return;
}

