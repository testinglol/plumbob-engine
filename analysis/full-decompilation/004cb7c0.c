
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_004cb7c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = __ftol();
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar2 < -iVar1) {
    return -iVar1;
  }
  if (iVar1 < iVar2) {
    iVar2 = iVar1;
  }
  return iVar2;
}

