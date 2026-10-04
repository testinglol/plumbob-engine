
int __fastcall FUN_004cc9df(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_005dd99d();
  iVar1 = *(int *)(param_1 + 0x194);
  if ((iVar1 != 0) && (iVar2 != 0)) {
    iVar3 = FUN_0046d9e5();
    FUN_005e879b(iVar3 < *(int *)(iVar1 + 0x1c));
  }
  return iVar2;
}

