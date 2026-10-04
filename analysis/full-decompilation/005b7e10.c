
uint FUN_005b7e10(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (DAT_006fd8e8 != DAT_00703f80) {
    DAT_006fd8e8 = DAT_00703f80;
    piVar3 = &DAT_006fd7e8;
    do {
      iVar2 = DAT_00703f80;
      if ((((code *)piVar3[-2] != (code *)0x0) && (*piVar3 <= DAT_00703f80)) && (piVar3[1] == 0)) {
        piVar3[1] = 1;
        uVar1 = (*(code *)piVar3[-2])(param_1,iVar2 - *piVar3);
        uVar4 = uVar4 | uVar1;
        iVar2 = DAT_00703f80 + piVar3[-1];
        piVar3[1] = 0;
        *piVar3 = iVar2;
      }
      piVar3 = piVar3 + 4;
    } while ((int)piVar3 < 0x6fd8e8);
  }
  return uVar4;
}

