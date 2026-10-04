
int FUN_004ea85e(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = FUN_004ea79e(param_1);
  if (iVar1 != 0) {
    iVar4 = (int)*(short *)(iVar1 + 0x70);
    uVar3 = (uint)*(short *)(iVar1 + 0x72);
    iVar1 = FUN_004eaa44(param_1);
    if (iVar1 == 1) {
      iVar4 = -1;
      uVar3 = 0;
    }
    if ((((iVar4 != 0) && (iVar1 = FUN_00404ccb(iVar4), iVar1 != 0)) &&
        (piVar2 = (int *)FUN_005ed3c4(), -1 < (int)uVar3)) &&
       (uVar3 < (uint)((piVar2[1] - *piVar2) / 0x3c0))) {
      return uVar3 * 0x3c0 + *piVar2;
    }
  }
  return 0;
}

