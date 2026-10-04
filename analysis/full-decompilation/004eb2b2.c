
void __thiscall FUN_004eb2b2(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_004eb374(iVar1,param_2);
  }
  else {
    FUN_004eb8be();
    *(int *)(param_1 + 4) = iVar1 + 0x44;
  }
  return;
}

