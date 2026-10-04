
void FUN_0049fac2(undefined4 *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6,int *param_7)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  uint uVar13;
  undefined4 *puVar14;
  int local_30;
  uint local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  ushort *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)*param_2;
  puVar3 = (undefined4 *)*param_1;
  iVar4 = param_1[1];
  uVar1 = param_3[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  puVar10 = param_2;
  puVar12 = param_3 + 8;
  puVar14 = puVar3;
  local_18 = puVar3;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar2 = *puVar12;
            uVar13 = uVar2 & 0x1fff;
            uVar8 = uVar2 & 0xe000;
            local_c = puVar12 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            param_1 = local_8;
            local_18 = (undefined4 *)((int)puVar14 + iVar4 * 2);
            local_8 = (undefined4 *)((int)local_8 + param_2[1] * 2);
            if (puVar14 < (undefined4 *)((int)puVar3 + iVar5 * iVar4 * 2)) {
              local_c = (ushort *)((int)puVar12 + uVar13);
            }
            else {
              if ((undefined4 *)((int)puVar3 + ((uint)uVar1 - iVar6) * iVar4 * 2) <= puVar14) {
                return;
              }
              local_1c = (undefined4 *)((int)puVar14 + *param_7 * 2);
              local_10 = (undefined4 *)((int)puVar14 + ((uint)*param_3 - param_7[2]) * 2);
            }
            local_30 = *param_6 + param_5;
            param_6 = param_6 + 1;
            puVar10 = puVar14;
            puVar12 = local_c;
            puVar14 = local_18;
          }
          puVar12 = local_c;
          if (uVar8 != 0x6000) break;
          param_1 = (undefined4 *)((int)param_1 + uVar13 * 2);
          puVar10 = (undefined4 *)((int)puVar10 + uVar13 * 2);
        }
        if (uVar8 != 0x8000) break;
        if ((uVar2 & 0x1fff) != 0) {
          local_20 = uVar13;
          do {
            puVar10 = puVar14;
            param_1 = local_8;
            local_8 = (undefined4 *)((int)local_8 + param_2[1] * 2);
            puVar14 = (undefined4 *)((int)puVar10 + iVar4 * 2);
            local_20 = local_20 - 1;
            local_18 = puVar14;
          } while (local_20 != 0);
        }
      }
      if (uVar8 == 0xa000) {
        return;
      }
    } while (uVar8 != 0xc000);
    local_20 = 0;
    if ((puVar10 < local_1c) || (local_10 <= (undefined4 *)((int)puVar10 + uVar13 * 2))) {
      iVar9 = uVar13 * 2;
      puVar11 = (undefined4 *)(iVar9 + (int)puVar10);
      if ((local_1c < puVar11) && (puVar10 < local_10)) {
        if (local_10 < puVar11) {
          local_20 = (iVar9 - (int)local_10) + (int)puVar10 >> 1;
          uVar13 = uVar13 - local_20;
        }
        if (puVar10 < local_1c) {
          iVar9 = (int)local_1c - (int)puVar10 >> 1;
          uVar13 = uVar13 - iVar9;
          param_1 = (undefined4 *)((int)param_1 + iVar9 * 2);
          puVar10 = (undefined4 *)((int)puVar10 + iVar9 * 2);
          local_c = (ushort *)((int)local_c + iVar9);
        }
        goto LAB_0049fbaa;
      }
      uVar8 = (int)local_c + uVar13;
      param_1 = (undefined4 *)((int)param_1 + iVar9);
    }
    else {
LAB_0049fbaa:
      puVar12 = local_c;
      if (0 < (int)uVar13) {
        uVar7 = (undefined2)local_30;
        puVar11 = param_1;
        for (uVar8 = uVar13 >> 1; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar11 = CONCAT22(uVar7,uVar7);
          puVar11 = puVar11 + 1;
        }
        for (uVar8 = (uint)((uVar13 & 1) != 0); puVar14 = local_18, uVar8 != 0; uVar8 = uVar8 - 1) {
          *(undefined2 *)puVar11 = uVar7;
          puVar11 = (undefined4 *)((int)puVar11 + 2);
        }
      }
      local_c = (ushort *)0x0;
      local_14 = puVar10;
      if (0 < (int)uVar13) {
        do {
          iVar9 = (int)local_c + 1;
          *(undefined2 *)local_14 =
               *(undefined2 *)(param_4 + (uint)*(byte *)((int)local_c + (int)puVar12) * 2);
          local_14 = (undefined4 *)((int)local_14 + 2);
          local_c = (ushort *)iVar9;
        } while (iVar9 < (int)uVar13);
      }
      uVar8 = (int)puVar12 + uVar13;
      param_1 = (undefined4 *)((int)param_1 + uVar13 * 2);
      puVar11 = (undefined4 *)((int)puVar10 + uVar13 * 2);
      if (local_20 != 0) {
        uVar8 = uVar8 + local_20;
        puVar11 = (undefined4 *)((int)puVar11 + local_20 * 2);
        param_1 = (undefined4 *)((int)param_1 + local_20 * 2);
      }
    }
    puVar10 = puVar11;
    puVar12 = (ushort *)(uVar8 + (uVar8 & 1));
  } while( true );
}

