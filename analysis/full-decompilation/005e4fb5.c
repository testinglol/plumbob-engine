
void __thiscall FUN_005e4fb5(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = FUN_005e3596();
    if (iVar1 != 0) {
      FUN_005e357a();
    }
  }
  if (param_1[0x37] != 0) {
    iVar1 = FUN_005e3596();
    if (iVar1 != 0) {
      FUN_005e3581();
    }
    param_1[0x37] = 0;
  }
  param_1[0x37] = param_2;
  if (param_2 != 0) {
    param_1[0x4d] = *(int *)(param_2 + 0x14);
    param_1[0x4e] = *(int *)(param_2 + 0x18);
    param_1[0x4f] = *(int *)(param_2 + 0x1c);
    param_1[0x50] = *(int *)(param_2 + 0x20);
  }
  param_1[0x4b] = param_3;
  param_1[0x4c] = param_4;
  (**(code **)(*param_1 + 0x168))();
  return;
}

