
void __thiscall FUN_005c64a0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != *(int *)(param_1 + 8)) {
    FUN_005c70b0(iVar1,param_2);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 0x10;
    return;
  }
  FUN_005c6980(iVar1,param_2);
  return;
}

