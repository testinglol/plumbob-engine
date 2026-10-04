
int __thiscall FUN_00608a37(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00608ca3(param_2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0xc);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x2c) + *(int *)(param_1 + 0x18);
  }
  return iVar1;
}

