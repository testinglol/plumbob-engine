
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004728e9(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  char local_5;
  
  local_20 = 0;
  if ((param_1[1] - *param_1) / 0x14 != 0) {
    local_14 = param_1;
    local_18 = (**(code **)*param_2)();
    if ((DAT_006e546c & 1) == 0) {
      DAT_006e546c = DAT_006e546c | 1;
      DAT_006e5460 = 0;
      DAT_006e5464 = 0;
      _DAT_006e5468 = 0;
      FUN_00635543(&LAB_00472b13);
    }
    FUN_00472c1a(DAT_006e5460,DAT_006e5464);
    local_24 = 0xffffffff;
    local_2c = 0;
    local_28 = 0;
    FUN_00472bb6(&local_2c);
    local_20 = 0;
    iVar7 = DAT_006e5464 - DAT_006e5460;
    iVar8 = DAT_006e5460;
    iVar2 = local_38;
    iVar5 = local_34;
    piVar6 = local_14;
    while (iVar7 = iVar7 / 0xc, iVar7 != 0) {
      iVar3 = iVar8 + -0xc + iVar7 * 0xc;
      piVar1 = (int *)(*param_1 + *(int *)(iVar8 + -0xc + iVar7 * 0xc) * 0x14);
      iVar10 = piVar1[2];
      local_14 = piVar6;
      local_38 = iVar2;
      if ((iVar10 < 0) || (1 < iVar10)) {
        local_34 = *(int *)(iVar3 + 4);
        iVar10 = iVar10 + -2;
        if (iVar10 <= local_18 - local_34) goto LAB_00472a34;
joined_r0x00472a4c:
        while (local_34 = iVar5, param_1 = piVar6, iVar7 != 0) {
          local_1c = DAT_006e5464;
          if (iVar7 == 1) {
            FUN_00472c1a(iVar8,DAT_006e5464);
          }
          else {
            puVar4 = (undefined4 *)(iVar8 + -0xc + iVar7 * 0xc);
            iVar2 = *piVar6 + *(int *)(iVar8 + (iVar7 * 3 + -6) * 4) * 0x14;
            if ((*(int *)(iVar8 + -4 + iVar7 * 0xc) == 0) &&
               (*(int *)(iVar2 + 0xc) != *(int *)(iVar2 + 0x10))) {
              puVar4[2] = puVar4[2] + 1;
              *puVar4 = *(undefined4 *)(iVar2 + 0xc + puVar4[2] * 4);
              iVar8 = DAT_006e5460;
              break;
            }
            FUN_00472be0(puVar4);
          }
          iVar8 = DAT_006e5460;
          iVar5 = local_34;
          iVar7 = (DAT_006e5464 - DAT_006e5460) / 0xc;
        }
      }
      else {
        local_34 = *(int *)(iVar3 + 4);
        local_10 = local_34;
        for (local_c = 0; (local_10 < local_18 && (local_c < piVar1[1])); local_c = local_c + 1) {
          local_5 = *(char *)(param_2[1] + local_10);
          if (('@' < local_5) && (local_5 < '[')) {
            local_5 = local_5 + ' ';
          }
          cVar9 = *(char *)(piVar6[3] + *piVar1 + local_c);
          if (('@' < cVar9) && (cVar9 < '[')) {
            cVar9 = cVar9 + ' ';
          }
          if (local_5 != cVar9) break;
          local_10 = local_10 + 1;
        }
        if (local_c != piVar1[1]) goto joined_r0x00472a4c;
        iVar10 = local_10 - local_34;
LAB_00472a34:
        if (iVar10 < 0) goto joined_r0x00472a4c;
        local_38 = piVar1[3];
        local_34 = local_34 + iVar10;
        if (local_38 == -1) {
          local_38 = iVar2;
          if (local_20 < local_34) {
            local_20 = local_34;
          }
          goto joined_r0x00472a4c;
        }
        local_30 = 0;
        local_1c = DAT_006e5464;
        FUN_00472bb6(&local_38);
        iVar8 = DAT_006e5460;
        param_1 = local_14;
      }
      iVar2 = local_38;
      iVar5 = local_34;
      piVar6 = local_14;
      iVar7 = DAT_006e5464 - iVar8;
    }
  }
  return local_20;
}

