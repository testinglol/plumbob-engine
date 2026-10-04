
void FUN_0049f8e5(ushort *param_1,undefined4 *param_2,ushort *param_3,int param_4,int param_5,
                 int *param_6,int *param_7)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  uint uVar12;
  ushort *puVar13;
  int local_30;
  int local_20;
  undefined4 *local_1c;
  undefined4 *local_14;
  int local_10;
  ushort *local_c;
  undefined4 *local_8;
  
  puVar3 = *(undefined4 **)param_1;
  iVar4 = *(int *)(param_1 + 2);
  local_c = (ushort *)*param_2;
  uVar1 = param_3[1];
  iVar5 = param_7[1];
  iVar6 = param_7[3];
  puVar7 = param_2;
  puVar11 = param_3 + 8;
  local_8 = puVar3;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            uVar2 = *puVar11;
            uVar12 = uVar2 & 0x1fff;
            uVar9 = uVar2 & 0xe000;
            puVar13 = puVar11 + 1;
            if ((uVar2 & 0xe000) != 0) break;
            param_1 = local_c;
            local_c = local_c + param_2[1];
            if (local_8 < (undefined4 *)((int)puVar3 + iVar5 * iVar4 * 2)) {
              puVar13 = (ushort *)((int)puVar11 + uVar12);
            }
            else {
              if ((undefined4 *)((int)puVar3 + ((uint)uVar1 - iVar6) * iVar4 * 2) <= local_8) {
                return;
              }
              local_1c = (undefined4 *)((int)local_8 + *param_7 * 2);
              local_14 = (undefined4 *)((int)local_8 + ((uint)*param_3 - param_7[2]) * 2);
            }
            local_30 = *param_6 + param_5;
            param_6 = param_6 + 1;
            puVar7 = local_8;
            puVar11 = puVar13;
            local_8 = (undefined4 *)((int)local_8 + iVar4 * 2);
          }
          puVar11 = puVar13;
          if (uVar9 != 0x6000) break;
          puVar7 = (undefined4 *)((int)puVar7 + uVar12 * 2);
          param_1 = param_1 + uVar12;
        }
        if (uVar9 != 0x8000) break;
        if ((uVar2 & 0x1fff) != 0) {
          do {
            param_1 = local_c;
            puVar8 = (undefined4 *)((int)local_8 + iVar4 * 2);
            local_c = local_c + param_2[1];
            uVar12 = uVar12 - 1;
            puVar7 = local_8;
            local_8 = puVar8;
          } while (uVar12 != 0);
        }
      }
      if (uVar9 == 0xa000) {
        return;
      }
    } while (uVar9 != 0xc000);
    local_20 = 0;
    if ((puVar7 < local_1c) || (local_14 <= (undefined4 *)((int)puVar7 + uVar12 * 2))) {
      iVar10 = uVar12 * 2;
      puVar8 = (undefined4 *)(iVar10 + (int)puVar7);
      if ((local_1c < puVar8) && (puVar7 < local_14)) {
        if (local_14 < puVar8) {
          local_20 = (iVar10 - (int)local_14) + (int)puVar7 >> 1;
          uVar12 = uVar12 - local_20;
        }
        if (puVar7 < local_1c) {
          iVar10 = (int)local_1c - (int)puVar7 >> 1;
          uVar12 = uVar12 - iVar10;
          param_1 = param_1 + iVar10;
          puVar7 = (undefined4 *)((int)puVar7 + iVar10 * 2);
          puVar13 = (ushort *)((int)puVar13 + iVar10);
        }
        goto LAB_0049f9c0;
      }
      uVar9 = (int)puVar13 + uVar12;
LAB_0049fa19:
      param_1 = (ushort *)((int)param_1 + iVar10);
    }
    else {
LAB_0049f9c0:
      local_10 = 0;
      if (0 < (int)uVar12) {
        puVar11 = param_1;
        do {
          if (local_30 <= (int)(uint)*puVar11) {
            *puVar11 = (ushort)local_30;
            *(undefined2 *)(((int)puVar7 - (int)param_1) + (int)puVar11) =
                 *(undefined2 *)(param_4 + (uint)*(byte *)(local_10 + (int)puVar13) * 2);
          }
          local_10 = local_10 + 1;
          puVar11 = puVar11 + 1;
        } while (local_10 < (int)uVar12);
      }
      uVar9 = (int)puVar13 + uVar12;
      param_1 = param_1 + uVar12;
      puVar8 = (undefined4 *)((int)puVar7 + uVar12 * 2);
      if (local_20 != 0) {
        uVar9 = uVar9 + local_20;
        iVar10 = local_20 * 2;
        puVar8 = (undefined4 *)((int)puVar8 + iVar10);
        goto LAB_0049fa19;
      }
    }
    puVar7 = puVar8;
    puVar11 = (ushort *)(uVar9 + (uVar9 & 1));
  } while( true );
}

