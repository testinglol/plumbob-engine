
int * FUN_0063a50e(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  for (piVar3 = DAT_00703b44; (piVar3 < DAT_00703b44 + DAT_00703b40 * 2 && (*piVar3 != param_1));
      piVar3 = piVar3 + 2) {
  }
  if (DAT_00703b44 + DAT_00703b40 * 2 <= piVar3) {
    if ((param_1 == 0) &&
       (piVar2 = (int *)FUN_00640b6e(DAT_00703b44,DAT_00703b40 * 8 + 8), iVar1 = DAT_00703b40,
       piVar2 != (int *)0x0)) {
      DAT_00703b40 = DAT_00703b40 + 1;
      piVar3 = piVar2 + iVar1 * 2;
      DAT_00703b44 = piVar2;
    }
    else {
      piVar3 = (int *)0x0;
    }
  }
  return piVar3;
}

