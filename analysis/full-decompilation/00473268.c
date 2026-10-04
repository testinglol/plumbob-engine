
int __fastcall FUN_00473268(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xfa8);
  iVar2 = *(int *)(param_1 + 0xfac);
  if (iVar2 < iVar1) {
    return iVar1 - iVar2;
  }
  if (iVar1 == iVar2) {
    if (*(int *)(param_1 + 0xfb0) != 0) {
      return *(int *)(param_1 + 0xfa4);
    }
    return 0;
  }
  return (*(int *)(param_1 + 0xfa4) - iVar2) + iVar1;
}

