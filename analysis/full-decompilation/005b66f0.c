
void FUN_005b66f0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_006fd648;
  do {
    if (*piVar1 == param_1) {
      return;
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x6fd748);
  iVar2 = 0;
  do {
    if ((&DAT_006fd648)[iVar2] == 0) {
      (&DAT_006fd648)[iVar2] = param_1;
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x40);
  return;
}

