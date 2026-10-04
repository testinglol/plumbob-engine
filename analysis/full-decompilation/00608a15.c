
int __thiscall FUN_00608a15(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00608ca3(param_2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 8);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x14);
  }
  return iVar1;
}

