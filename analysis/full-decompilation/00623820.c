
int * FUN_00623820(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *local_1c;
  int local_18;
  int local_10;
  
  iVar1 = (param_1 * param_1) / (param_2 * param_2);
  piVar2 = (int *)FUN_005a9320(iVar1 * 0x2c);
  if (piVar2 != (int *)0x0) {
    uVar3 = 0x4321;
    local_10 = 0xb;
    piVar5 = piVar2;
    do {
      local_18 = 0;
      local_1c = piVar5;
      if (0 < param_1) {
        do {
          iVar6 = 0;
          do {
            uVar4 = uVar3 * 0x41c64e6d + 0x3039;
            uVar3 = uVar4 * 0x41c64e6d + 0x3039;
            *local_1c = (((int)((longlong)(ulonglong)(uVar3 & 0x7fff) % (longlong)(param_4 + 1)) -
                         (param_4 >> 1)) + local_18) * param_3 +
                        ((int)((longlong)(ulonglong)(uVar4 & 0x7fff) % (longlong)(param_4 + 1)) -
                        (param_4 >> 1)) + iVar6;
            local_1c = local_1c + 1;
            iVar6 = iVar6 + param_2;
          } while (iVar6 < param_1);
          local_18 = local_18 + param_2;
        } while (local_18 < param_1);
      }
      piVar5 = piVar5 + iVar1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    return piVar2;
  }
  return (int *)0x0;
}

