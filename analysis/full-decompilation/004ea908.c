
int FUN_004ea908(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = FUN_004ea79e(param_1);
  if (iVar1 != 0) {
    uVar3 = (int)*(short *)(iVar1 + 0x72) + 1;
    if (*(short *)(iVar1 + 0x70) != 0) {
      iVar1 = FUN_00404ccb((int)*(short *)(iVar1 + 0x70));
      if (iVar1 != 0) {
        piVar2 = (int *)FUN_005ed3c4();
        if (-1 < (int)uVar3) {
          if (uVar3 < (uint)((piVar2[1] - *piVar2) / 0x3c0)) {
            return uVar3 * 0x3c0 + *piVar2;
          }
        }
      }
    }
  }
  return 0;
}

