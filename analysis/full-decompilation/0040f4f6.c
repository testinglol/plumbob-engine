
void __thiscall FUN_0040f4f6(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_0040f88d(iVar1,param_2);
  }
  else {
    FUN_0040fef7();
    *(int *)(param_1 + 4) = iVar1 + 0x4c;
  }
  return;
}

