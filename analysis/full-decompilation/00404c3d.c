
void FUN_00404c3d(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_006de7f8;
  if (DAT_006de7f8 != DAT_006de7fc) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_00404c85();
        FUN_006321f0(iVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != DAT_006de7fc);
  }
  FUN_0052ea87(DAT_006de7f8,DAT_006de7fc);
  return;
}

