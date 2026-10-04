
void FUN_0049fd89(int *param_1,ushort *param_2,int param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  int iVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  ushort *puVar12;
  int *piVar13;
  int local_24;
  int local_14;
  ushort *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)*param_1;
  iVar4 = param_1[1];
  piVar1 = (int *)((int)local_8 + param_5[1] * iVar4 * 2);
  piVar2 = (int *)((int)local_8 + ((uint)param_2[1] - param_5[3]) * iVar4 * 2);
  piVar13 = local_8;
  piVar9 = param_4;
  puVar12 = param_2 + 8;
  do {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            piVar8 = piVar13;
            uVar3 = *puVar12;
            uVar11 = uVar3 & 0x1fff;
            uVar6 = uVar3 & 0xe000;
            local_10 = puVar12 + 1;
            if ((uVar3 & 0xe000) != 0) break;
            local_8 = (int *)((int)piVar8 + iVar4 * 2);
            if (piVar8 < piVar1) {
              local_10 = (ushort *)((int)puVar12 + uVar11);
            }
            else {
              if (piVar2 <= piVar8) {
                return;
              }
              local_c = (int *)((int)piVar8 + *param_5 * 2);
              param_1 = (int *)((int)piVar8 + ((uint)*param_2 - param_5[2]) * 2);
            }
            local_24 = *param_4 + param_3;
            param_4 = param_4 + 1;
            piVar13 = local_8;
            piVar9 = piVar8;
            puVar12 = local_10;
          }
          piVar13 = piVar8;
          puVar12 = local_10;
          if (uVar6 != 0x6000) break;
          piVar9 = (int *)((int)piVar9 + uVar11 * 2);
        }
        if (uVar6 != 0x8000) break;
        if ((uVar3 & 0x1fff) != 0) {
          do {
            piVar9 = piVar8;
            local_8 = (int *)((int)piVar9 + iVar4 * 2);
            uVar11 = uVar11 - 1;
            piVar13 = local_8;
            piVar8 = local_8;
          } while (uVar11 != 0);
        }
      }
      if (uVar6 == 0xa000) {
        return;
      }
    } while (uVar6 != 0xc000);
    local_14 = 0;
    if ((piVar9 < local_c) || (param_1 <= (int *)((int)piVar9 + uVar11 * 2))) {
      piVar10 = (int *)(uVar11 * 2 + (int)piVar9);
      if ((local_c < piVar10) && (piVar9 < param_1)) {
        if (param_1 < piVar10) {
          local_14 = (int)((uVar11 * 2 - (int)param_1) + (int)piVar9) >> 1;
          uVar11 = uVar11 - local_14;
        }
        if (piVar9 < local_c) {
          iVar7 = (int)local_c - (int)piVar9 >> 1;
          uVar11 = uVar11 - iVar7;
          local_10 = (ushort *)((int)local_10 + iVar7);
          piVar9 = (int *)((int)piVar9 + iVar7 * 2);
        }
        goto LAB_0049fe54;
      }
      uVar6 = (int)local_10 + uVar11;
    }
    else {
LAB_0049fe54:
      if (0 < (int)uVar11) {
        uVar5 = (undefined2)local_24;
        piVar13 = piVar9;
        for (uVar6 = uVar11 >> 1; uVar6 != 0; uVar6 = uVar6 - 1) {
          *piVar13 = CONCAT22(uVar5,uVar5);
          piVar13 = piVar13 + 1;
        }
        for (uVar6 = (uint)((uVar11 & 1) != 0); piVar8 = local_8, uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined2 *)piVar13 = uVar5;
          piVar13 = (int *)((int)piVar13 + 2);
        }
      }
      uVar6 = (int)local_10 + uVar11;
      piVar10 = (int *)((int)piVar9 + uVar11 * 2);
      if (local_14 != 0) {
        uVar6 = uVar6 + local_14;
        piVar10 = (int *)((int)piVar10 + local_14 * 2);
      }
    }
    piVar13 = piVar8;
    piVar9 = piVar10;
    puVar12 = (ushort *)(uVar6 + (uVar6 & 1));
  } while( true );
}

