
void FUN_004c3818(int *param_1,int *param_2,short param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  bool bVar12;
  int local_10;
  int local_c;
  
  piVar4 = param_4;
  piVar3 = param_2;
  piVar2 = param_1;
  iVar5 = (**(code **)(*param_1 + 0xcc))();
  uVar6 = (**(code **)(*param_1 + 0xd0))();
  local_10 = 0;
  uVar6 = uVar6 >> 1;
  param_1 = (int *)(iVar5 + (param_2[1] * uVar6 + *param_2) * 2);
  iVar11 = param_2[3] - param_2[1];
  iVar5 = param_2[2];
  iVar1 = *param_2;
  iVar9 = iVar5 - iVar1;
  *param_4 = 0;
  *param_5 = 0;
  if (0 < iVar11) {
    do {
      local_c = 0;
      param_2 = (int *)0x0;
      psVar8 = (short *)param_1;
      if (0 < iVar9) {
        do {
          if (*psVar8 != param_3) break;
          local_c = local_c + 1;
          param_2 = (int *)((int)param_2 + 1);
          psVar8 = psVar8 + 1;
        } while ((int)param_2 < iVar9);
      }
      if (local_c != iVar9) break;
      *param_4 = *param_4 + 1;
      local_10 = local_10 + 1;
      param_1 = (int *)((int)param_1 + uVar6 * 2);
    } while (local_10 < iVar11);
  }
  if (*param_4 != iVar11) {
    iVar7 = (**(code **)(*piVar2 + 0xcc))();
    psVar8 = (short *)(iVar7 + ((piVar3[1] + -1 + iVar11) * uVar6 + *piVar3) * 2);
    while (iVar11 = iVar11 + -1, *piVar4 <= iVar11) {
      iVar7 = 0;
      bVar12 = iVar5 == iVar1;
      param_4 = (int *)0x0;
      psVar10 = psVar8;
      if (0 < iVar9) {
        do {
          if (*psVar10 != param_3) break;
          iVar7 = iVar7 + 1;
          param_4 = (int *)((int)param_4 + 1);
          psVar10 = psVar10 + 1;
        } while ((int)param_4 < iVar9);
        bVar12 = iVar7 == iVar9;
      }
      if (!bVar12) {
        return;
      }
      *param_5 = *param_5 + 1;
      psVar8 = psVar8 + -uVar6;
    }
  }
  return;
}

