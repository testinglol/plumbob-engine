
int __thiscall FUN_005cf6fc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_005ce996(param_1 + 6);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x14))(param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = FUN_005cea2a();
    }
    else {
      FUN_005cea2a();
    }
  }
  return iVar1;
}

