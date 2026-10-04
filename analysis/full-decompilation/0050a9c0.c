
void __thiscall FUN_0050a9c0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_0053ad22(param_2);
  if (*(int *)(param_1 + 0xe8) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 0) {
      FUN_00501214(param_2);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0xe8) + 0x19c))();
    }
  }
  if (*(int *)(param_1 + 0xe0) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 1) {
      FUN_005072f5(param_2);
    }
    else {
      FUN_005072e5();
    }
  }
  if (*(int *)(param_1 + 0xe4) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 2) {
      FUN_0051ceee(param_2);
      if ((*(byte *)(*(int *)(param_1 + 0xfc) + 0xc) & 2) != 0) {
        (**(code **)(**(int **)(param_1 + 0xe4) + 0x168))();
      }
    }
  }
  if (*(int *)(param_1 + 0xec) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 3) {
      FUN_005172e4(param_2);
    }
  }
  if (*(int *)(param_1 + 0xf4) != 0) {
    iVar1 = FUN_00401f6f();
    if (iVar1 == 4) {
      FUN_00504189(param_2);
    }
  }
  return;
}

