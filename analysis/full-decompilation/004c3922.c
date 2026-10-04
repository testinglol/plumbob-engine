
void FUN_004c3922(int *param_1,int *param_2,short param_3,int param_4,int param_5,int *param_6,
                 int *param_7)

{
  int iVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  
  iVar1 = (**(code **)(*param_1 + 0xcc))();
  uVar2 = (**(code **)(*param_1 + 0xd0))();
  psVar4 = (short *)(iVar1 + ((param_4 + param_2[1]) * (uVar2 >> 1) + *param_2) * 2);
  iVar1 = param_2[2] - *param_2;
  param_1 = (int *)(((param_2[3] - param_2[1]) - param_4) - param_5);
  *param_6 = iVar1;
  *param_7 = iVar1;
  if (0 < (int)param_1) {
    do {
      param_4 = 0;
      psVar3 = psVar4;
      if (0 < iVar1) {
        do {
          if (*psVar3 != param_3) break;
          param_4 = param_4 + 1;
          psVar3 = psVar3 + 1;
        } while (param_4 < iVar1);
      }
      if (param_4 < *param_6) {
        *param_6 = param_4;
      }
      iVar5 = iVar1 + -1;
      if (*param_6 <= iVar5) {
        psVar3 = psVar4 + iVar5;
        do {
          if (*psVar3 != param_3) break;
          iVar5 = iVar5 + -1;
          psVar3 = psVar3 + -1;
        } while (*param_6 <= iVar5);
      }
      iVar5 = (iVar1 - iVar5) + -1;
      if (iVar5 < *param_7) {
        *param_7 = iVar5;
      }
      param_1 = (int *)((int)param_1 + -1);
      psVar4 = psVar4 + (uVar2 >> 1);
    } while (param_1 != (int *)0x0);
  }
  return;
}

