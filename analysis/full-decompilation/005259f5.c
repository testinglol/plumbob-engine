
void __thiscall
FUN_005259f5(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  
  FUN_005dda18(param_2,param_3,param_4,param_5);
  if ((param_1[0x21] != param_1[0x1f]) && (param_1[0x22] != param_1[0x20])) {
    iVar1 = (**(code **)(*param_1 + 0x184))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x184))();
      if (*(int *)(iVar1 + 0x5c) == 0) {
        (**(code **)(*param_1 + 0x184))();
        FUN_005df69e();
      }
    }
  }
  return;
}

