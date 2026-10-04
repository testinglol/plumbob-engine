
undefined4 __thiscall
FUN_004199b7(int *param_1,undefined4 param_2,short param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
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
    iVar2 = FUN_00418d64(param_2,(int)param_3,param_4,param_5);
    if (iVar2 != 0) {
      uVar3 = FUN_0041a23d(iVar2,param_5,param_2);
      FUN_004659fc(uVar3);
      return *(undefined4 *)(iVar2 + 0xc);
    }
    cVar1 = (**(code **)(*param_1 + 0x28))();
    if (cVar1 == '\0') {
      uVar3 = 0xffffffcf;
    }
    else {
      uVar3 = 0xffffff9e;
    }
    FUN_004659fc(uVar3);
  }
  return 0;
}

