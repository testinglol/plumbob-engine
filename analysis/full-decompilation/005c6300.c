
void __thiscall FUN_005c6300(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != *(int *)(param_1 + 8)) {
    FUN_005c7090(iVar1,param_2);
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 8;
    return;
  }
  FUN_005c6670(iVar1,param_2);
  return;
}

