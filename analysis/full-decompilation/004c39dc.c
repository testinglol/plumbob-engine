
void __thiscall FUN_004c39dc(int param_1,int param_2,int param_3,byte *param_4,byte param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_18;
  int local_14;
  
  pbVar3 = param_4;
  bVar1 = param_5 + 1;
  iVar6 = param_3 - ((uint)*param_4 << (bVar1 & 0x1f));
  iVar7 = param_3 - (param_4[1] + 2 << (bVar1 & 0x1f));
  iVar8 = 8 << (param_5 & 0x1f);
  iVar2 = *(int *)(param_1 + 4);
  iVar4 = param_2 + iVar8;
  iVar5 = local_18;
  if (iVar8 != 0) {
    local_14 = ((iVar7 - iVar6) * 0x10000) / iVar8;
    iVar5 = iVar6 * 0x10000;
  }
  param_4 = (byte *)iVar4;
  if (((*(byte *)(param_1 + 8) & 1) != 0) && (param_4 = (byte *)param_2, param_2 < iVar4)) {
    local_14 = local_14 * iVar2;
    do {
      iVar6 = iVar5 >> 0x10;
      iVar5 = iVar5 + local_14;
      *(undefined2 *)(DAT_006f0bcc + iVar6 * DAT_006f0bbc + (int)param_4 * 2) = 0;
      param_4 = (byte *)((int)param_4 + iVar2);
    } while ((int)param_4 < iVar4);
  }
  param_2 = (0x10 << (param_5 & 0x1f)) + param_2;
  if (iVar8 != 0) {
    local_18 = iVar7 * 0x10000;
    local_14 = (int)(((param_3 - ((uint)pbVar3[2] << (bVar1 & 0x1f))) - iVar7) * 0x10000) / iVar8;
  }
  if (((*(byte *)(param_1 + 8) & 2) != 0) && ((int)param_4 < param_2)) {
    do {
      iVar5 = local_18 >> 0x10;
      local_18 = local_18 + local_14 * iVar2;
      *(undefined2 *)(DAT_006f0bcc + iVar5 * DAT_006f0bbc + (int)param_4 * 2) = 0;
      param_4 = (byte *)((int)param_4 + iVar2);
    } while ((int)param_4 < param_2);
  }
  return;
}

