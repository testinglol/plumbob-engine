
int FUN_004e98c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_0045741b();
    for (piVar2 = DAT_006f2648; piVar2 != DAT_006f264c; piVar2 = piVar2 + 0x11) {
      if (*piVar2 == iVar1) {
        return ((int)piVar2 - (int)DAT_006f2648) / 0x44;
      }
    }
  }
  return -1;
}

