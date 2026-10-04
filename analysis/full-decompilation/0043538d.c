
undefined4 __fastcall FUN_0043538d(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int local_8;
  
  DAT_006e4a7c = 0;
  DAT_006e4a80 = 0;
  if (DAT_006e4a84 != 0) {
    DAT_006e4a7c = 0;
    DAT_006e4a80 = 0;
    return 1;
  }
  if ((*(byte *)(param_1 + 0xa0) & 2) == 0) {
    DAT_006e4a7c = 0x25;
  }
  else {
    if ((*(short *)(param_1 + 0xc6) < 1) && ((*(byte *)(param_1 + 0x5a) & 0x20) == 0)) {
      iVar6 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -2;
      if (-1 < iVar6) {
        local_8 = (iVar6 * 9 + 9) * 4;
        if (iVar6 < 0) goto LAB_00435434;
        do {
          if (iVar6 < (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1) {
            iVar3 = local_8 + *(int *)(param_1 + 0x130);
          }
          else {
LAB_00435434:
            iVar3 = 0;
          }
          if (iVar3 == 0) {
            piVar5 = (int *)0x0;
          }
          else {
            uVar4 = (uint)*(short *)(iVar3 + 0x10);
            iVar3 = *(int *)(param_1 + 0xdc);
            piVar5 = (int *)0x0;
            if ((0 < (int)uVar4) &&
               (uVar4 < (*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x18) >> 2) + 1U)) {
              piVar5 = *(int **)(*(int *)(iVar3 + 0x18) + -4 + uVar4 * 4);
            }
          }
          if ((piVar5 != (int *)0x0) && (cVar2 = (**(code **)(*piVar5 + 0x68))(), cVar2 == '\0')) {
            return 0;
          }
          iVar6 = iVar6 + -1;
          local_8 = local_8 + -0x24;
        } while (-1 < iVar6);
      }
      cVar2 = *(char *)(param_1 + 0xfc);
      cVar1 = *(char *)(param_1 + 0xfd);
      if (-1 < cVar2) {
        if (((((int)cVar2 < *(int *)(DAT_006e54dc + 0x10)) && (-1 < cVar1)) &&
            ((int)cVar1 < *(int *)(DAT_006e54dc + 0x10))) &&
           ((DAT_006e4a84 == 0 &&
            ((~*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc) + cVar2 * 4) +
                        (int)cVar1) & 0x20) == 0)))) {
          DAT_006e4a7c = 0x27;
          return 0;
        }
      }
      return 1;
    }
    DAT_006e4a7c = 0x26;
  }
  DAT_006e4a80 = 0;
  return 0;
}

