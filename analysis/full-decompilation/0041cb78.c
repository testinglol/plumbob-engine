
undefined4 __thiscall
FUN_0041cb78(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

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
    iVar2 = (**(code **)*param_3)();
    if ((iVar2 != 0) && (iVar2 = FUN_0041bb41(param_2,param_3), iVar2 != 0)) {
      uVar3 = FUN_0041d2e1(iVar2,param_4,param_2);
      FUN_004659fc(uVar3);
      return *(undefined4 *)(iVar2 + 8);
    }
    FUN_004659fc(0xffffff9d);
  }
  return 0;
}

