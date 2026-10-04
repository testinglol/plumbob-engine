
void __thiscall FUN_0048e3ce(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_0048e46a(iVar1,param_2);
  }
  else {
    FUN_0048e8be();
    *(int *)(param_1 + 4) = iVar1 + 0x28;
  }
  return;
}

