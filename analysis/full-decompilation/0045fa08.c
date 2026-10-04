
void __thiscall FUN_0045fa08(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_00460259(iVar1,param_2);
  }
  else {
    FUN_00461114();
    *(int *)(param_1 + 4) = iVar1 + 0x9c;
  }
  return;
}

