
void __thiscall FUN_0040f46e(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_0040f703(iVar1,param_2);
  }
  else {
    FUN_0040feca();
    *(int *)(param_1 + 4) = iVar1 + 0x98;
  }
  return;
}

