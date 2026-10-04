
void __thiscall FUN_00468aa0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_00468f04(iVar1,param_2);
  }
  else {
    FUN_0046952b();
    *(int *)(param_1 + 4) = iVar1 + 0xc;
  }
  return;
}

