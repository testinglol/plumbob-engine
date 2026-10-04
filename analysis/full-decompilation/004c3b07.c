
void __thiscall FUN_004c3b07(int param_1,int param_2,int param_3,byte *param_4,byte param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_1c;
  int local_18;
  
  bVar1 = param_5 + 1;
  iVar5 = param_3 - ((uint)*param_4 << (bVar1 & 0x1f));
  iVar7 = 8 << (param_5 & 0x1f);
  iVar6 = param_3 - (param_4[1] + 2 << (bVar1 & 0x1f));
  iVar4 = iVar7 + param_2;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar7 != 0) {
    local_1c = iVar5 * 0x10000;
    local_18 = ((iVar6 - iVar5) * 0x10000) / iVar7;
  }
  iVar5 = iVar4;
  if (((*(byte *)(param_1 + 8) & 1) != 0) && (iVar5 = param_2, param_2 < iVar4)) {
    do {
      iVar3 = local_1c >> 0x10;
      if ((((DAT_006f0bc2 <= iVar5) && (iVar5 < DAT_006f0bc6)) && (DAT_006f0bc0 <= iVar3)) &&
         (iVar3 < DAT_006f0bc4)) {
        *(undefined2 *)(DAT_006f0bcc + DAT_006f0bbc * iVar3 + iVar5 * 2) = 0;
      }
      iVar5 = iVar5 + iVar2;
      local_1c = local_1c + local_18 * iVar2;
    } while (iVar5 < iVar4);
  }
  param_2 = (0x10 << (param_5 & 0x1f)) + param_2;
  if (iVar7 != 0) {
    local_1c = iVar6 * 0x10000;
    local_18 = (int)(((param_3 - ((uint)param_4[2] << (bVar1 & 0x1f))) - iVar6) * 0x10000) / iVar7;
  }
  if (((*(byte *)(param_1 + 8) & 2) != 0) && (iVar5 < param_2)) {
    do {
      iVar4 = local_1c >> 0x10;
      if (((DAT_006f0bc2 <= iVar5) && (iVar5 < DAT_006f0bc6)) &&
         ((DAT_006f0bc0 <= iVar4 && (iVar4 < DAT_006f0bc4)))) {
        *(undefined2 *)(DAT_006f0bcc + DAT_006f0bbc * iVar4 + iVar5 * 2) = 0;
      }
      iVar5 = iVar5 + iVar2;
      local_1c = local_1c + local_18 * iVar2;
    } while (iVar5 < param_2);
  }
  return;
}

