
void FUN_00608fed(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0;
  if (0 < DAT_006d98b8) {
    piVar3 = &DAT_006ff3f8;
    do {
      iVar1 = *piVar3;
      if (iVar1 != 0) {
        FUN_006089fb();
        FUN_006321f0(iVar1);
      }
      *piVar3 = 0;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < DAT_006d98b8);
  }
  DAT_006d98b8 = 0;
  return;
}

