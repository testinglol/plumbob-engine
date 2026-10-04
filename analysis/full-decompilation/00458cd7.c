
void __thiscall FUN_00458cd7(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_00458d03(iVar1,param_2);
  }
  else {
    FUN_00458ec6();
    *(int *)(param_1 + 4) = iVar1 + 0x44;
  }
  return;
}

