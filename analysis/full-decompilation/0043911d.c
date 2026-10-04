
void __thiscall FUN_0043911d(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == *(int *)(param_1 + 8)) {
    FUN_004391f0(iVar1,param_2);
  }
  else {
    FUN_00439520();
    *(int *)(param_1 + 4) = iVar1 + 0x10;
  }
  return;
}

