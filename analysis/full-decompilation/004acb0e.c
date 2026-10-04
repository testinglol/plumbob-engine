
void FUN_004acb0e(short *param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar12 = param_2 + param_4;
  local_10 = 0;
  local_c = 0;
  iVar10 = param_2 - param_4;
  iVar9 = param_3 - param_4;
  param_3 = param_3 + param_4;
  iVar3 = param_1[1] - iVar10;
  if (0 < iVar3) {
    iVar10 = iVar10 + iVar3;
    local_10 = iVar3;
  }
  iVar3 = *param_1 - iVar9;
  if (0 < iVar3) {
    iVar9 = iVar9 + iVar3;
    local_c = iVar3;
  }
  param_2 = iVar12;
  if (0 < iVar12 - param_1[3]) {
    param_2 = iVar12 - (iVar12 - param_1[3]);
  }
  if (0 < param_3 - param_1[2]) {
    param_3 = param_3 - (param_3 - param_1[2]);
  }
  local_20 = param_2 - iVar10;
  local_24 = param_3 - iVar9;
  if ((0 < local_20) && (0 < local_24)) {
    cVar1 = FUN_004b466e();
    if ((cVar1 != '\0') &&
       ((local_3c = param_2, local_44 = iVar10, local_40 = iVar9, local_38 = param_3,
        *(int *)(local_1c + 0x68) != 0 && (DAT_006e4870 == '\0')))) {
      FUN_005cf0fa(&local_44);
    }
    cVar1 = FUN_004b466e();
    if ((cVar1 != '\0') && (cVar1 = FUN_004b465e(), cVar1 != '\0')) {
      local_14 = param_4 * param_4;
      puVar11 = (undefined2 *)(DAT_006f0bbc * iVar9 + iVar10 * 2 + DAT_006f0bcc);
      iVar12 = DAT_006f0bd4 * iVar9 + iVar10 * 2 + DAT_006f0bd0;
      param_1 = (short *)0x0;
      local_18 = param_4 - param_4 / 3;
      local_18 = local_18 * local_18;
      local_1c = *(int *)(DAT_006e486c + 0x34);
      if (0 < local_24) {
        do {
          param_3 = 0;
          local_28 = ((int)param_1 - param_4) + local_c;
          local_28 = local_28 * local_28;
          if (0 < local_20) {
            local_8 = iVar12 - (int)puVar11;
            puVar7 = puVar11;
            do {
              if ((param_5 < *(ushort *)(local_8 + (int)puVar7)) &&
                 (iVar3 = local_10 + (param_3 - param_4), iVar3 = iVar3 * iVar3 + local_28,
                 iVar3 < local_14)) {
                if (local_1c == 1) {
                  local_34 = FUN_00438f76(*puVar7);
                }
                else if (local_1c == 2) {
                  local_34 = FUN_00438f9b(*puVar7);
                }
                else if (local_1c == 3) {
                  local_34 = FUN_004a45de(*puVar7);
                }
                else {
                  local_34 = 0xffff00;
                }
                uVar4 = local_34 >> 0x10 & 0xff;
                local_30 = local_34 >> 8 & 0xff;
                local_34 = local_34 & 0xff;
                iVar3 = iVar3 - local_18;
                uVar5 = (local_34 + local_30 + uVar4) / 6 + 8;
                uVar6 = uVar5;
                uVar8 = uVar5;
                if (0 < iVar3) {
                  iVar3 = (iVar3 * 0x100) / (local_14 - local_18);
                  if (iVar3 < 0) {
                    iVar3 = 0;
                  }
                  if (0xff < iVar3) {
                    iVar3 = 0xff;
                  }
                  iVar9 = (0xff - iVar3) * uVar5;
                  uVar5 = (int)(iVar3 * local_34 + iVar9) >> 8;
                  uVar6 = (int)(iVar3 * uVar4 + iVar9) >> 8;
                  uVar8 = (int)(iVar3 * local_30 + iVar9) >> 8;
                }
                uVar5 = (uVar6 << 8 | uVar8) << 8 | uVar5;
                if (local_1c == 1) {
                  uVar2 = FUN_0049f1f4(uVar5);
                }
                else if (local_1c == 2) {
                  uVar2 = FUN_0049f21b(uVar5);
                }
                else {
                  if (local_1c != 3) goto LAB_004acd8a;
                  uVar2 = FUN_004a4558(uVar5);
                }
                *puVar7 = uVar2;
              }
LAB_004acd8a:
              param_3 = param_3 + 1;
              puVar7 = puVar7 + 1;
            } while (param_3 < local_20);
          }
          puVar11 = puVar11 + (DAT_006f0bbc >> 1);
          param_1 = (short *)((int)param_1 + 1);
          iVar12 = iVar12 + (DAT_006f0bd4 >> 1) * 2;
        } while ((int)param_1 < local_24);
      }
    }
  }
  return;
}

