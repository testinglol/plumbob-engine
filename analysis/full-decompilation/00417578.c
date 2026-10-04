
undefined4 __thiscall
FUN_00417578(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
    iVar2 = FUN_00418326(param_1[6],param_2,param_3,param_4);
    if (iVar2 != 0) {
      uVar3 = FUN_00417f1a(iVar2,param_4);
      FUN_004659fc(uVar3);
      return *(undefined4 *)(iVar2 + 0x10);
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

