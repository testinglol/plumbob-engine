
undefined4 __thiscall FUN_005f7a3c(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int *piVar4;
  int *piVar5;
  short *psVar6;
  
  if (*param_1 != 0) {
    psVar3 = (short *)(param_3 + (int)param_2);
    for (psVar6 = param_2; psVar6 < psVar3; psVar6 = psVar6 + 1) {
      param_1[0x25] = param_1[0x25] + 4;
      if (param_1 + 0x22 < (int *)param_1[0x25]) {
        param_1[0x25] = (int)(param_1 + 0x13);
      }
      param_2 = (short *)0x0;
      param_2._0_2_ = 0;
      piVar5 = param_1 + 3;
      *(int *)param_1[0x25] = (int)*psVar6;
      param_3 = param_1[0x23];
      piVar4 = (int *)param_1[0x25];
      if (0 < param_3) {
        iVar2 = param_3 + 2;
        do {
          iVar1 = *piVar4;
          piVar4 = piVar4 + -1;
          param_2 = (short *)((int)param_2 + (iVar1 * *piVar5 >> 0xc));
          if (piVar4 < param_1 + 0x13) {
            piVar4 = param_1 + 0x22;
          }
          piVar5 = piVar5 + 1;
          if (param_1 + iVar2 < piVar5) {
            piVar5 = param_1 + 3;
          }
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      *psVar6 = (short)param_2;
    }
  }
  return 1;
}

