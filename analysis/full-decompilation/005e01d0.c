
uint FUN_005e01d0(undefined2 *param_1,int param_2,int param_3,undefined4 param_4,undefined2 param_5,
                 uint param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined2 *puVar9;
  int *extraout_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  int aiStack_80068 [131073];
  int local_64;
  undefined2 *local_58;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_3c;
  undefined2 *local_38;
  int local_30;
  undefined2 *local_2c;
  int local_28;
  undefined2 *local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  FUN_00636080();
  iVar5 = (param_2 - (int)param_1) + param_3;
  iVar18 = (param_3 - (int)param_1) / 2;
  iVar1 = iVar18 + param_2;
  iVar3 = extraout_ECX[8];
  puVar4 = (undefined2 *)extraout_ECX[7];
  if ((((-1 < (int)param_1) && ((int)param_1 < (int)puVar4)) && (-1 < param_3)) &&
     (((param_3 < (int)puVar4 && (-1 < param_2)) &&
      ((param_2 < iVar3 && ((-1 < iVar5 && (iVar5 < iVar3)))))))) {
    uVar6 = (**(code **)(*extraout_ECX + 0x88))();
    return uVar6;
  }
  puVar7 = puVar4;
  if ((uint)(param_3 - (int)param_1) >> 1 <= param_6) {
    puVar7 = (undefined2 *)(**(code **)(*extraout_ECX + 0x8c))();
  }
  if (((((((param_6 == 0) || (0x1000 < (int)param_1)) ||
         (puVar7 = (undefined2 *)0xfffff000, (int)param_1 < -0x1000)) ||
        ((0x1000 < param_2 || (param_2 < -0x1000)))) || (0x1000 < param_3)) ||
      ((param_3 < -0x1000 || (0x1000 < iVar5)))) ||
     ((iVar5 < -0x1000 || (puVar7 = param_1, param_3 < (int)param_1)))) {
    return (uint)puVar7 & 0xffffff00;
  }
  uVar6 = (**(code **)(*extraout_ECX + 0xd0))();
  uVar6 = uVar6 >> 1;
  iVar8 = (**(code **)(*extraout_ECX + 0xcc))();
  iVar5 = iVar8 + (iVar3 + -1) * uVar6 * 2;
  iVar2 = iVar8 + (uVar6 * iVar1 + 1) * 2;
  local_50 = 1 - iVar18;
  puVar7 = (undefined2 *)(iVar18 - param_6);
  local_30 = 1 - (int)puVar7;
  local_4c = 3;
  local_2c = (undefined2 *)0x3;
  local_48 = iVar18 * -2 + 5;
  local_28 = (int)puVar7 * -2 + 5;
  iVar16 = 0;
  local_38 = (undefined2 *)(iVar18 * uVar6);
  local_18 = (int)puVar7 * uVar6;
  local_20 = 0;
  local_3c = 0;
  local_1c = 0;
  if ((((-1 < iVar18 + 5) && (iVar18 + 5 < (int)puVar4)) && (-1 < iVar1)) && (iVar1 < iVar3)) {
    *(undefined2 *)(iVar18 * 2 + iVar2) = param_5;
  }
  if (((-1 < 5 - iVar18) && (5 - iVar18 < (int)puVar4)) && ((-1 < iVar1 && (iVar1 < iVar3)))) {
    *(undefined2 *)(iVar2 + iVar18 * -2) = param_5;
  }
  if (((5 < (int)puVar4) && (-1 < iVar1 - iVar18)) && (iVar1 - iVar18 < iVar3)) {
    *(undefined2 *)(iVar2 + (int)local_38 * -2) = param_5;
  }
  local_58 = puVar4;
  if (((5 < (int)puVar4) && (local_58 = (undefined2 *)(iVar1 + iVar18), -1 < (int)local_58)) &&
     ((int)local_58 < iVar3)) {
    *(undefined2 *)(iVar2 + (int)local_38 * 2) = param_5;
    local_58 = local_38;
  }
  if (param_6 == 1) {
    local_44 = iVar18;
    if (0 < iVar18) {
      do {
        iVar5 = iVar16 + 1;
        local_3c = local_3c + uVar6;
        if (local_50 < 0) {
          iVar17 = local_48 + 2;
          iVar8 = local_4c;
        }
        else {
          iVar18 = iVar18 + -1;
          local_38 = (undefined2 *)((int)local_38 - uVar6);
          iVar17 = local_48 + 4;
          local_44 = iVar18;
          iVar8 = local_48;
        }
        local_48 = iVar17;
        local_4c = local_4c + 2;
        local_50 = local_50 + iVar8;
        iVar8 = -iVar5;
        local_58 = (undefined2 *)(iVar8 + 5);
        if ((((-1 < (int)local_58) && ((int)local_58 < (int)puVar4)) && (-1 < iVar1 - iVar18)) &&
           (iVar1 - iVar18 < iVar3)) {
          *(undefined2 *)(iVar2 + ((int)local_38 + iVar5) * -2) = param_5;
          iVar18 = local_44;
        }
        iVar16 = iVar16 + 6;
        if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
           ((-1 < iVar1 - iVar18 && (iVar1 - iVar18 < iVar3)))) {
          *(undefined2 *)(iVar2 + (iVar5 - (int)local_38) * 2) = param_5;
        }
        iVar17 = iVar18 + 5;
        if (-1 < iVar17) {
          if (((iVar17 < (int)puVar4) && (iVar18 = local_44, -1 < iVar1 + iVar8)) &&
             (iVar1 + iVar8 < iVar3)) {
            *(undefined2 *)(iVar2 + (local_44 - local_3c) * 2) = param_5;
          }
          if ((((-1 < iVar17) && (iVar17 < (int)puVar4)) && (-1 < iVar1 + iVar5)) &&
             (iVar1 + iVar5 < iVar3)) {
            *(undefined2 *)(iVar2 + (local_3c + iVar18) * 2) = param_5;
          }
        }
        if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
           ((-1 < iVar1 + iVar18 && (iVar1 + iVar18 < iVar3)))) {
          *(undefined2 *)(iVar2 + ((int)local_38 + iVar5) * 2) = param_5;
        }
        if (((-1 < (int)local_58) && ((int)local_58 < (int)puVar4)) &&
           ((local_58 = (undefined2 *)(iVar1 + iVar18), -1 < (int)local_58 &&
            ((int)local_58 < iVar3)))) {
          local_58 = (undefined2 *)((int)local_38 - iVar5);
          *(undefined2 *)(iVar2 + (int)local_58 * 2) = param_5;
        }
        iVar16 = 5 - iVar18;
        if ((((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
            (local_58 = (undefined2 *)(iVar1 + iVar5), -1 < (int)local_58)) &&
           ((int)local_58 < iVar3)) {
          local_58 = (undefined2 *)(local_3c - iVar18);
          *(undefined2 *)(iVar2 + (int)local_58 * 2) = param_5;
        }
        if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
           ((local_58 = (undefined2 *)(iVar1 + iVar8), -1 < (int)local_58 && ((int)local_58 < iVar3)
            ))) {
          local_58 = (undefined2 *)((local_3c + iVar18) * 2);
          *(undefined2 *)(iVar2 + (local_3c + iVar18) * -2) = param_5;
        }
        iVar16 = iVar5;
      } while (iVar5 < iVar18);
    }
    goto LAB_005e1770;
  }
  iVar17 = iVar18;
  if ((int)puVar7 < iVar18) {
    do {
      iVar19 = iVar16 + 1;
      iVar18 = iVar17;
      if (iVar17 <= iVar19) break;
      local_3c = local_3c + uVar6;
      if (local_50 < 0) {
        local_50 = local_50 + local_4c;
        local_48 = local_48 + 2;
      }
      else {
        local_38 = (undefined2 *)((int)local_38 - uVar6);
        local_50 = local_50 + local_48;
        local_48 = local_48 + 4;
        iVar18 = iVar17 + -1;
        iVar10 = -iVar19;
        iVar12 = iVar10 + 5;
        if (((iVar12 < 0) || ((int)puVar4 <= iVar12)) ||
           ((iVar15 = iVar1 - iVar18, iVar15 < 0 || (iVar3 <= iVar15)))) {
          if (((-1 < iVar16 + 6) && (iVar16 + 6 < (int)puVar4)) &&
             ((-1 < iVar1 - iVar18 && (iVar1 - iVar18 < iVar3)))) {
            iVar15 = (int)local_38 + 5;
            goto LAB_005e06e7;
          }
        }
        else {
          if ((((iVar16 + 6 < 0) || ((int)puVar4 <= iVar16 + 6)) || (iVar15 < 0)) ||
             (iVar3 <= iVar15)) {
            iVar15 = (int)local_38 + iVar19;
            iVar11 = (int)puVar4 + (-5 - (int)local_38);
          }
          else {
            iVar15 = (int)local_38 + iVar19;
LAB_005e06e7:
            iVar11 = iVar19 - (int)local_38;
          }
          puVar20 = (undefined4 *)(iVar2 + iVar15 * -2);
          puVar21 = (undefined4 *)(iVar2 + iVar11 * 2);
          if (puVar20 <= puVar21) {
            uVar13 = (int)puVar21 + (2 - (int)puVar20);
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *puVar20 = CONCAT22(param_5,param_5);
              puVar20 = puVar20 + 1;
            }
            for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined2 *)puVar20 = param_5;
              puVar20 = (undefined4 *)((int)puVar20 + 2);
            }
          }
        }
        iVar17 = iVar17 + 4;
        if (-1 < iVar17) {
          if (((iVar17 < (int)puVar4) && (-1 < iVar10 + iVar1)) && (iVar10 + iVar1 < iVar3)) {
            if ((iVar1 + iVar19 < 0) || (iVar3 <= iVar1 + iVar19)) {
              for (puVar9 = (undefined2 *)(iVar2 + (iVar18 - local_3c) * 2);
                  puVar9 <= (undefined2 *)(iVar5 + iVar17 * 2); puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
            else {
              for (puVar9 = (undefined2 *)(iVar2 + (iVar18 - local_3c) * 2);
                  puVar9 <= (undefined2 *)(iVar2 + (local_3c + iVar18) * 2); puVar9 = puVar9 + uVar6
                  ) {
                *puVar9 = param_5;
              }
            }
          }
          else if (((-1 < iVar17) && (iVar17 < (int)puVar4)) &&
                  ((-1 < iVar1 + iVar19 && (iVar1 + iVar19 < iVar3)))) {
            for (puVar9 = (undefined2 *)(iVar8 + iVar17 * 2);
                puVar9 <= (undefined2 *)(iVar2 + (local_3c + iVar18) * 2); puVar9 = puVar9 + uVar6)
            {
              *puVar9 = param_5;
            }
          }
        }
        if ((((iVar16 + 6 < 0) || ((int)puVar4 <= iVar16 + 6)) || (iVar1 + iVar18 < 0)) ||
           (iVar3 <= iVar1 + iVar18)) {
          if (((-1 < iVar12) && (iVar12 < (int)puVar4)) &&
             ((-1 < iVar1 + iVar18 && (iVar1 + iVar18 < iVar3)))) {
            for (puVar9 = (undefined2 *)(iVar2 + (((int)local_38 - 5U) + (int)puVar4) * 2);
                (undefined2 *)(iVar2 + ((int)local_38 - iVar19) * 2) <= puVar9; puVar9 = puVar9 + -1
                ) {
              *puVar9 = param_5;
            }
          }
        }
        else if ((iVar12 < 0) || ((int)puVar4 <= iVar12)) {
          for (puVar9 = (undefined2 *)(iVar2 + ((int)local_38 + iVar19) * 2);
              (undefined2 *)(iVar2 + ((int)local_38 - 5U) * 2) <= puVar9; puVar9 = puVar9 + -1) {
            *puVar9 = param_5;
          }
        }
        else {
          for (puVar9 = (undefined2 *)(iVar2 + ((int)local_38 + iVar19) * 2);
              (undefined2 *)(iVar2 + ((int)local_38 - iVar19) * 2) <= puVar9; puVar9 = puVar9 + -1)
          {
            *puVar9 = param_5;
          }
        }
        iVar16 = 5 - iVar18;
        if ((((iVar16 < 0) || ((int)puVar4 <= iVar16)) || (iVar19 + iVar1 < 0)) ||
           (iVar3 <= iVar19 + iVar1)) {
          if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
             ((-1 < iVar10 + iVar1 && (iVar10 + iVar1 < iVar3)))) {
            for (puVar9 = (undefined2 *)(iVar5 + iVar16 * 2);
                (undefined2 *)(iVar2 + (local_3c + iVar18) * -2) <= puVar9; puVar9 = puVar9 + -uVar6
                ) {
              *puVar9 = param_5;
            }
          }
        }
        else if (((iVar16 < 0) || ((int)puVar4 <= iVar16)) ||
                ((iVar10 + iVar1 < 0 || (iVar3 <= iVar10 + iVar1)))) {
          for (puVar9 = (undefined2 *)(iVar2 + (local_3c - iVar18) * 2);
              (undefined2 *)(iVar8 + iVar16 * 2) <= puVar9; puVar9 = puVar9 + -uVar6) {
            *puVar9 = param_5;
          }
        }
        else {
          for (puVar9 = (undefined2 *)(iVar2 + (local_3c - iVar18) * 2);
              (undefined2 *)(iVar2 + (local_3c + iVar18) * -2) <= puVar9; puVar9 = puVar9 + -uVar6)
          {
            *puVar9 = param_5;
          }
        }
      }
      local_4c = local_4c + 2;
      iVar17 = iVar18;
      iVar16 = iVar19;
    } while ((int)puVar7 < iVar18);
    if (iVar18 <= (int)puVar7) goto LAB_005e0bdf;
    local_3c = local_3c + uVar6;
    iVar18 = iVar16 + 1;
    while (local_24 = puVar7, (int)puVar7 < iVar18) {
      local_3c = local_3c - uVar6;
      iVar17 = iVar18 + -1;
      iVar19 = -iVar17;
      iVar16 = iVar19 + 5;
      if ((((iVar16 < 0) || ((int)puVar4 <= iVar16)) || (iVar10 = iVar1 + iVar19, iVar10 < 0)) ||
         (iVar3 <= iVar10)) {
        if (((-1 < iVar18 + 4) && (iVar18 + 4 < (int)puVar4)) &&
           ((-1 < iVar1 + iVar19 && (iVar1 + iVar19 < iVar3)))) {
          iVar10 = local_3c + 5;
          goto LAB_005e0976;
        }
      }
      else {
        if (((iVar18 + 4 < 0) || ((int)puVar4 <= iVar18 + 4)) || ((iVar10 < 0 || (iVar3 <= iVar10)))
           ) {
          iVar10 = local_3c + iVar17;
          iVar12 = (int)puVar4 + (-5 - local_3c);
        }
        else {
          iVar10 = local_3c + iVar17;
LAB_005e0976:
          iVar12 = iVar17 - local_3c;
        }
        puVar20 = (undefined4 *)(iVar2 + iVar10 * -2);
        puVar21 = (undefined4 *)(iVar2 + iVar12 * 2);
        if (puVar20 <= puVar21) {
          uVar13 = (int)puVar21 + (2 - (int)puVar20);
          for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar20 = CONCAT22(param_5,param_5);
            puVar20 = puVar20 + 1;
          }
          for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
            *(undefined2 *)puVar20 = param_5;
            puVar20 = (undefined4 *)((int)puVar20 + 2);
          }
        }
      }
      iVar10 = iVar18 + 4;
      if (-1 < iVar10) {
        if (((iVar10 < (int)puVar4) && (-1 < iVar19 + iVar1)) && (iVar19 + iVar1 < iVar3)) {
          if ((iVar17 + iVar1 < 0) || (iVar3 <= iVar17 + iVar1)) {
            for (puVar9 = (undefined2 *)(iVar2 + (iVar17 - local_3c) * 2);
                puVar9 <= (undefined2 *)(iVar5 + iVar10 * 2); puVar9 = puVar9 + uVar6) {
              *puVar9 = param_5;
            }
          }
          else {
            for (puVar9 = (undefined2 *)(iVar2 + (iVar17 - local_3c) * 2);
                puVar9 <= (undefined2 *)(iVar2 + (local_3c + iVar17) * 2); puVar9 = puVar9 + uVar6)
            {
              *puVar9 = param_5;
            }
          }
        }
        else if (((-1 < iVar10) && (iVar10 < (int)puVar4)) &&
                ((-1 < iVar1 + iVar17 && (iVar1 + iVar17 < iVar3)))) {
          for (puVar9 = (undefined2 *)(iVar8 + iVar10 * 2);
              puVar9 <= (undefined2 *)(iVar2 + (local_3c + iVar17) * 2); puVar9 = puVar9 + uVar6) {
            *puVar9 = param_5;
          }
        }
      }
      if ((((iVar18 + 4 < 0) || ((int)puVar4 <= iVar18 + 4)) || (iVar1 + iVar17 < 0)) ||
         (iVar3 <= iVar1 + iVar17)) {
        if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
           ((-1 < iVar1 + iVar17 && (iVar1 + iVar17 < iVar3)))) {
          for (puVar9 = (undefined2 *)(iVar2 + (local_3c + -5 + (int)puVar4) * 2);
              (undefined2 *)(iVar2 + (local_3c - iVar17) * 2) <= puVar9; puVar9 = puVar9 + -1) {
            *puVar9 = param_5;
          }
        }
      }
      else if ((iVar16 < 0) || ((int)puVar4 <= iVar16)) {
        for (puVar9 = (undefined2 *)(iVar2 + (local_3c + iVar17) * 2);
            (undefined2 *)(iVar2 + (local_3c + -5) * 2) <= puVar9; puVar9 = puVar9 + -1) {
          *puVar9 = param_5;
        }
      }
      else {
        for (puVar9 = (undefined2 *)(iVar2 + (local_3c + iVar17) * 2);
            (undefined2 *)(iVar2 + (local_3c - iVar17) * 2) <= puVar9; puVar9 = puVar9 + -1) {
          *puVar9 = param_5;
        }
      }
      iVar18 = iVar17;
      if (-1 < iVar16) {
        if (((iVar16 < (int)puVar4) && (-1 < iVar1 + iVar17)) && (iVar1 + iVar17 < iVar3)) {
          if (((iVar16 < 0) || ((int)puVar4 <= iVar16)) ||
             ((iVar19 + iVar1 < 0 || (iVar3 <= iVar19 + iVar1)))) {
            for (puVar9 = (undefined2 *)(iVar2 + (local_3c - iVar17) * 2);
                (undefined2 *)(iVar8 + iVar16 * 2) <= puVar9; puVar9 = puVar9 + -uVar6) {
              *puVar9 = param_5;
            }
          }
          else {
            for (puVar9 = (undefined2 *)(iVar2 + (local_3c - iVar17) * 2);
                (undefined2 *)(iVar2 + (local_3c + iVar17) * -2) <= puVar9; puVar9 = puVar9 + -uVar6
                ) {
              *puVar9 = param_5;
            }
          }
        }
        else if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
                ((-1 < iVar19 + iVar1 && (iVar19 + iVar1 < iVar3)))) {
          for (puVar9 = (undefined2 *)(iVar5 + iVar16 * 2);
              (undefined2 *)(iVar2 + (local_3c + iVar17) * -2) <= puVar9; puVar9 = puVar9 + -uVar6)
          {
            *puVar9 = param_5;
          }
        }
      }
    }
  }
  else {
LAB_005e0bdf:
    iVar17 = iVar16 + 1;
    if (iVar16 + 1 < iVar18) {
      do {
        iVar16 = iVar17;
        local_3c = local_3c + uVar6;
        if (local_50 < 0) {
          iVar19 = local_48 + 2;
          iVar17 = local_4c;
        }
        else {
          iVar18 = iVar18 + -1;
          aiStack_80068[iVar18 * 2] = iVar16;
          aiStack_80068[iVar18 * 2 + 1] = local_3c;
          iVar19 = local_48 + 4;
          iVar17 = local_48;
        }
        local_48 = iVar19;
        local_4c = local_4c + 2;
        local_50 = local_50 + iVar17;
        iVar17 = iVar16 + 1;
      } while (iVar16 + 1 < iVar18);
    }
    while (local_24 = puVar7, iVar16 + 1 < (int)puVar7) {
      iVar18 = local_20 + 1;
      local_1c = local_1c + uVar6;
      if (local_30 < 0) {
        local_30 = local_30 + (int)local_2c;
        local_28 = local_28 + 2;
      }
      else {
        local_30 = local_30 + local_28;
        local_28 = local_28 + 4;
        local_24 = (undefined2 *)((int)puVar7 - 1);
        local_18 = local_18 - uVar6;
        iVar19 = aiStack_80068[(int)local_24 * 2];
        iVar10 = aiStack_80068[(int)local_24 * 2 + 1];
        iVar17 = 5 - iVar19;
        if ((((iVar17 < 0) || ((int)puVar4 <= iVar17)) || (iVar1 - (int)local_24 < 0)) ||
           (iVar3 <= iVar1 - (int)local_24)) {
          local_58 = (undefined2 *)(5 - iVar18);
          if (((-1 < (int)local_58) && ((int)local_58 < (int)puVar4)) &&
             ((-1 < iVar1 - (int)local_24 && (iVar1 - (int)local_24 < iVar3)))) {
            iVar12 = 5;
            goto LAB_005e0cf7;
          }
        }
        else {
          local_58 = (undefined2 *)(5 - iVar18);
          iVar12 = iVar19;
          if (((int)local_58 < 0) || ((int)puVar4 <= (int)local_58)) {
            iVar15 = ((int)puVar4 + (-5 - local_18)) * 2;
          }
          else {
LAB_005e0cf7:
            iVar15 = (iVar18 + local_18) * -2;
          }
          puVar21 = (undefined4 *)(iVar2 + (iVar12 + local_18) * -2);
          if (puVar21 <= (undefined4 *)(iVar2 + iVar15)) {
            uVar13 = iVar2 + iVar15 + (2 - (int)puVar21);
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *puVar21 = CONCAT22(param_5,param_5);
              puVar21 = puVar21 + 1;
            }
            for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined2 *)puVar21 = param_5;
              puVar21 = (undefined4 *)((int)puVar21 + 2);
            }
          }
        }
        local_20 = local_20 + 6;
        if ((((local_20 < 0) || ((int)puVar4 <= local_20)) || (iVar1 - (int)local_24 < 0)) ||
           (iVar3 <= iVar1 - (int)local_24)) {
          if (((-1 < iVar19 + 5) && (iVar19 + 5 < (int)puVar4)) &&
             ((-1 < iVar1 - (int)local_24 && (iVar1 - (int)local_24 < iVar3)))) {
            iVar12 = (local_18 + 5) * -2;
            goto LAB_005e0d9f;
          }
        }
        else {
          if ((iVar19 + 5 < 0) || ((int)puVar4 <= iVar19 + 5)) {
            iVar15 = (int)puVar4 + (-5 - local_18);
            iVar12 = (iVar18 - local_18) * 2;
          }
          else {
            iVar12 = (iVar18 - local_18) * 2;
LAB_005e0d9f:
            iVar15 = iVar19 - local_18;
          }
          puVar20 = (undefined4 *)(iVar2 + iVar15 * 2);
          puVar21 = (undefined4 *)(iVar2 + iVar12);
          if (puVar21 <= puVar20) {
            uVar13 = (int)puVar20 + (2 - (int)puVar21);
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *puVar21 = CONCAT22(param_5,param_5);
              puVar21 = puVar21 + 1;
            }
            for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined2 *)puVar21 = param_5;
              puVar21 = (undefined4 *)((int)puVar21 + 2);
            }
          }
        }
        local_64 = iVar19 + 5;
        puVar7 = puVar7 + 2;
        if (-1 < (int)puVar7) {
          if ((((int)puVar7 < (int)puVar4) && (-1 < iVar1 - iVar19)) && (iVar1 - iVar19 < iVar3)) {
            if ((iVar1 - iVar18 < 0) || (iVar3 <= iVar1 - iVar18)) {
              for (puVar9 = (undefined2 *)(iVar2 + ((int)local_24 - iVar10) * 2);
                  puVar9 <= (undefined2 *)(iVar5 + (int)puVar7 * 2); puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
            else {
              for (puVar9 = (undefined2 *)(iVar2 + ((int)local_24 - iVar10) * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)local_24 - local_1c) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          else {
            if ((int)puVar7 < 0) goto LAB_005e0f2d;
            if ((((int)puVar7 < (int)puVar4) && (-1 < iVar1 - iVar18)) && (iVar1 - iVar18 < iVar3))
            {
              for (puVar9 = (undefined2 *)(iVar8 + (int)puVar7 * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)local_24 - local_1c) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          if (-1 < (int)puVar7) {
            if ((((int)puVar7 < (int)puVar4) && (-1 < iVar18 + iVar1)) && (iVar18 + iVar1 < iVar3))
            {
              if ((iVar19 + iVar1 < 0) || (iVar3 <= iVar19 + iVar1)) {
                for (puVar9 = (undefined2 *)(iVar2 + (local_1c + (int)local_24) * 2);
                    puVar9 <= (undefined2 *)(iVar5 + (int)puVar7 * 2); puVar9 = puVar9 + uVar6) {
                  *puVar9 = param_5;
                }
              }
              else {
                for (puVar7 = (undefined2 *)(iVar2 + (local_1c + (int)local_24) * 2);
                    puVar7 <= (undefined2 *)(iVar2 + (iVar10 + (int)local_24) * 2);
                    puVar7 = puVar7 + uVar6) {
                  *puVar7 = param_5;
                }
              }
            }
            else if (((-1 < (int)puVar7) && ((int)puVar7 < (int)puVar4)) &&
                    ((-1 < iVar1 + iVar19 && (iVar1 + iVar19 < iVar3)))) {
              for (puVar7 = (undefined2 *)(iVar8 + (int)puVar7 * 2);
                  puVar7 <= (undefined2 *)(iVar2 + (iVar10 + (int)local_24) * 2);
                  puVar7 = puVar7 + uVar6) {
                *puVar7 = param_5;
              }
            }
          }
        }
LAB_005e0f2d:
        if ((((local_64 < 0) || ((int)puVar4 <= local_64)) || (iVar1 + (int)local_24 < 0)) ||
           (iVar3 <= iVar1 + (int)local_24)) {
          if (((-1 < local_20) && (local_20 < (int)puVar4)) &&
             ((-1 < iVar1 + (int)local_24 && (iVar1 + (int)local_24 < iVar3)))) {
            for (puVar7 = (undefined2 *)(iVar2 + (local_18 + -5) * 2);
                (undefined2 *)(iVar2 + (iVar18 + local_18) * 2) <= puVar7; puVar7 = puVar7 + -1) {
              *puVar7 = param_5;
            }
          }
        }
        else if ((local_20 < 0) || ((int)puVar4 <= local_20)) {
          for (puVar7 = (undefined2 *)(iVar2 + (iVar19 + local_18) * 2);
              (undefined2 *)(iVar2 + (local_18 + -5) * 2) <= puVar7; puVar7 = puVar7 + -1) {
            *puVar7 = param_5;
          }
        }
        else {
          for (puVar7 = (undefined2 *)(iVar2 + (iVar19 + local_18) * 2);
              (undefined2 *)(iVar2 + (iVar18 + local_18) * 2) <= puVar7; puVar7 = puVar7 + -1) {
            *puVar7 = param_5;
          }
        }
        if (((((int)local_58 < 0) || ((int)puVar4 <= (int)local_58)) || ((int)local_24 + iVar1 < 0))
           || (iVar3 <= (int)local_24 + iVar1)) {
          if (((-1 < iVar17) && (iVar17 < (int)puVar4)) &&
             ((-1 < (int)local_24 + iVar1 && ((int)local_24 + iVar1 < iVar3)))) {
            for (puVar7 = (undefined2 *)(iVar2 + (local_18 + -5 + (int)puVar4) * 2);
                (undefined2 *)(iVar2 + (local_18 - iVar19) * 2) <= puVar7; puVar7 = puVar7 + -1) {
              *puVar7 = param_5;
            }
          }
        }
        else if ((iVar17 < 0) || ((int)puVar4 <= iVar17)) {
          for (puVar7 = (undefined2 *)(iVar2 + (local_18 - iVar18) * 2);
              (undefined2 *)(iVar2 + (local_18 + -5) * 2) <= puVar7; puVar7 = puVar7 + -1) {
            *puVar7 = param_5;
          }
        }
        else {
          for (puVar7 = (undefined2 *)(iVar2 + (local_18 - iVar18) * 2);
              (undefined2 *)(iVar2 + (local_18 - iVar19) * 2) <= puVar7; puVar7 = puVar7 + -1) {
            *puVar7 = param_5;
          }
        }
        iVar17 = 5 - (int)local_24;
        if ((((iVar17 < 0) || ((int)puVar4 <= iVar17)) || (iVar19 + iVar1 < 0)) ||
           (iVar3 <= iVar19 + iVar1)) {
          if (iVar17 < 0) goto LAB_005e11d7;
          if (((iVar17 < (int)puVar4) && (-1 < iVar18 + iVar1)) && (iVar18 + iVar1 < iVar3)) {
            for (puVar7 = (undefined2 *)(iVar5 + iVar17 * 2);
                (undefined2 *)(iVar2 + (local_1c - (int)local_24) * 2) <= puVar7;
                puVar7 = puVar7 + -uVar6) {
              *puVar7 = param_5;
            }
          }
        }
        else if ((iVar18 + iVar1 < 0) || (iVar3 <= iVar18 + iVar1)) {
          for (puVar7 = (undefined2 *)(iVar2 + (iVar10 - (int)local_24) * 2);
              (undefined2 *)(iVar8 + iVar17 * 2) <= puVar7; puVar7 = puVar7 + -uVar6) {
            *puVar7 = param_5;
          }
        }
        else {
          for (puVar7 = (undefined2 *)(iVar2 + (iVar10 - (int)local_24) * 2);
              (undefined2 *)(iVar2 + (local_1c - (int)local_24) * 2) <= puVar7;
              puVar7 = puVar7 + -uVar6) {
            *puVar7 = param_5;
          }
        }
        if (-1 < iVar17) {
          if (((iVar17 < (int)puVar4) && (-1 < iVar1 - iVar18)) && (iVar1 - iVar18 < iVar3)) {
            if ((iVar1 - iVar19 < 0) || (iVar3 <= iVar1 - iVar19)) {
              for (puVar7 = (undefined2 *)(iVar2 + (local_1c + (int)local_24) * -2);
                  (undefined2 *)(iVar8 + iVar17 * 2) <= puVar7; puVar7 = puVar7 + -uVar6) {
                *puVar7 = param_5;
              }
            }
            else {
              for (puVar7 = (undefined2 *)(iVar2 + (local_1c + (int)local_24) * -2);
                  (undefined2 *)(iVar2 + (iVar10 + (int)local_24) * -2) <= puVar7;
                  puVar7 = puVar7 + -uVar6) {
                *puVar7 = param_5;
              }
            }
          }
          else if (((-1 < iVar17) && (iVar17 < (int)puVar4)) &&
                  ((-1 < iVar1 - iVar19 && (iVar1 - iVar19 < iVar3)))) {
            for (puVar7 = (undefined2 *)(iVar5 + iVar17 * 2);
                (undefined2 *)(iVar2 + (iVar10 + (int)local_24) * -2) <= puVar7;
                puVar7 = puVar7 + -uVar6) {
              *puVar7 = param_5;
            }
          }
        }
      }
LAB_005e11d7:
      local_2c = local_2c + 1;
      puVar7 = local_24;
      local_20 = iVar18;
    }
  }
  local_58 = local_24;
  if (local_20 <= (int)local_24) {
    do {
      iVar18 = local_20 + 1;
      local_1c = local_1c + uVar6;
      if (local_30 < 0) {
        local_30 = local_30 + (int)local_2c;
        local_28 = local_28 + 2;
        local_58 = local_2c;
      }
      else {
        local_30 = local_30 + local_28;
        local_28 = local_28 + 4;
        puVar7 = (undefined2 *)((int)local_24 - 1);
        local_18 = local_18 - uVar6;
        iVar16 = 5 - (int)puVar7;
        if ((((iVar16 < 0) || ((int)puVar4 <= iVar16)) || (iVar1 - (int)puVar7 < 0)) ||
           (iVar3 <= iVar1 - (int)puVar7)) {
          local_58 = (undefined2 *)(5 - iVar18);
          if (((-1 < (int)local_58) && ((int)local_58 < (int)puVar4)) &&
             ((-1 < iVar1 - (int)puVar7 && (iVar1 - (int)puVar7 < iVar3)))) {
            puVar9 = (undefined2 *)0x5;
            goto LAB_005e1291;
          }
        }
        else {
          local_58 = (undefined2 *)(5 - iVar18);
          puVar9 = puVar7;
          if (((int)local_58 < 0) || ((int)puVar4 <= (int)local_58)) {
            iVar17 = ((int)puVar4 + (-5 - local_18)) * 2;
          }
          else {
LAB_005e1291:
            iVar17 = (iVar18 + local_18) * -2;
          }
          puVar21 = (undefined4 *)(iVar2 + ((int)puVar9 + local_18) * -2);
          if (puVar21 <= (undefined4 *)(iVar2 + iVar17)) {
            uVar13 = iVar2 + iVar17 + (2 - (int)puVar21);
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *puVar21 = CONCAT22(param_5,param_5);
              puVar21 = puVar21 + 1;
            }
            for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined2 *)puVar21 = param_5;
              puVar21 = (undefined4 *)((int)puVar21 + 2);
            }
          }
        }
        local_20 = local_20 + 6;
        if ((((local_20 < 0) || ((int)puVar4 <= local_20)) || (iVar1 - (int)puVar7 < 0)) ||
           (iVar3 <= iVar1 - (int)puVar7)) {
          if (-1 < (int)(local_24 + 2)) {
            if ((((int)(local_24 + 2) < (int)puVar4) && (-1 < iVar1 - (int)puVar7)) &&
               (iVar1 - (int)puVar7 < iVar3)) {
              iVar17 = (local_18 + 5) * -2;
              iVar19 = (int)puVar7 - local_18;
              goto LAB_005e1343;
            }
            goto LAB_005e1369;
          }
LAB_005e1525:
          if (((-1 < local_20) && (local_20 < (int)puVar4)) &&
             ((-1 < iVar1 + (int)puVar7 && (iVar1 + (int)puVar7 < iVar3)))) {
            for (puVar9 = (undefined2 *)(iVar2 + (local_18 + -5) * 2);
                (undefined2 *)(iVar2 + (iVar18 + local_18) * 2) <= puVar9; puVar9 = puVar9 + -1) {
              *puVar9 = param_5;
            }
          }
        }
        else {
          if (((int)(local_24 + 2) < 0) || ((int)puVar4 <= (int)(local_24 + 2))) {
            iVar19 = (int)puVar4 + (-5 - local_18);
          }
          else {
            iVar19 = (int)puVar7 - local_18;
          }
          iVar17 = (iVar18 - local_18) * 2;
LAB_005e1343:
          puVar21 = (undefined4 *)(iVar2 + iVar17);
          puVar20 = (undefined4 *)(iVar2 + iVar19 * 2);
          if (puVar21 <= puVar20) {
            uVar13 = (int)puVar20 + (2 - (int)puVar21);
            for (uVar14 = uVar13 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
              *puVar21 = CONCAT22(param_5,param_5);
              puVar21 = puVar21 + 1;
            }
            for (uVar13 = (uint)((uVar13 >> 1 & 1) != 0); uVar13 != 0; uVar13 = uVar13 - 1) {
              *(undefined2 *)puVar21 = param_5;
              puVar21 = (undefined4 *)((int)puVar21 + 2);
            }
          }
LAB_005e1369:
          local_24 = local_24 + 2;
          if ((int)local_24 < 0) goto LAB_005e1525;
          if ((((int)local_24 < (int)puVar4) && (-1 < iVar1 - (int)puVar7)) &&
             (iVar1 - (int)puVar7 < iVar3)) {
            if ((iVar1 - iVar18 < 0) || (iVar3 <= iVar1 - iVar18)) {
              for (puVar9 = (undefined2 *)(iVar2 + ((int)puVar7 - local_18) * 2);
                  puVar9 <= (undefined2 *)(iVar5 + (int)local_24 * 2); puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
            else {
              for (puVar9 = (undefined2 *)(iVar2 + ((int)puVar7 - local_18) * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)puVar7 - local_1c) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          else {
            if ((int)local_24 < 0) goto LAB_005e1525;
            if ((((int)local_24 < (int)puVar4) && (-1 < iVar1 - iVar18)) && (iVar1 - iVar18 < iVar3)
               ) {
              for (puVar9 = (undefined2 *)(iVar8 + (int)local_24 * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)puVar7 - local_1c) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          if ((int)local_24 < 0) goto LAB_005e1525;
          if ((((int)local_24 < (int)puVar4) && (-1 < iVar18 + iVar1)) && (iVar18 + iVar1 < iVar3))
          {
            if (((int)puVar7 + iVar1 < 0) || (iVar3 <= (int)puVar7 + iVar1)) {
              for (puVar9 = (undefined2 *)(iVar2 + (local_1c + (int)puVar7) * 2);
                  puVar9 <= (undefined2 *)(iVar5 + (int)local_24 * 2); puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
            else {
              for (puVar9 = (undefined2 *)(iVar2 + (local_1c + (int)puVar7) * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)puVar7 + local_18) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          else {
            if ((int)local_24 < 0) goto LAB_005e1525;
            if ((((int)local_24 < (int)puVar4) && (-1 < (int)puVar7 + iVar1)) &&
               ((int)puVar7 + iVar1 < iVar3)) {
              for (puVar9 = (undefined2 *)(iVar8 + (int)local_24 * 2);
                  puVar9 <= (undefined2 *)(iVar2 + ((int)puVar7 + local_18) * 2);
                  puVar9 = puVar9 + uVar6) {
                *puVar9 = param_5;
              }
            }
          }
          if (((((int)local_24 < 0) || ((int)puVar4 <= (int)local_24)) || (iVar1 + (int)puVar7 < 0))
             || (iVar3 <= iVar1 + (int)puVar7)) goto LAB_005e1525;
          if ((local_20 < 0) || ((int)puVar4 <= local_20)) {
            for (puVar9 = (undefined2 *)(iVar2 + (local_18 + (int)puVar7) * 2);
                (undefined2 *)(iVar2 + (local_18 + -5 + (int)puVar4) * 2) <= puVar9;
                puVar9 = puVar9 + -1) {
              *puVar9 = param_5;
            }
          }
          else {
            for (puVar9 = (undefined2 *)(iVar2 + (local_18 + (int)puVar7) * 2);
                (undefined2 *)(iVar2 + (iVar18 + local_18) * 2) <= puVar9; puVar9 = puVar9 + -1) {
              *puVar9 = param_5;
            }
          }
        }
        if (((((int)local_58 < 0) || ((int)puVar4 <= (int)local_58)) ||
            (local_58 = (undefined2 *)(iVar1 + (int)puVar7), (int)local_58 < 0)) ||
           (iVar3 <= (int)local_58)) {
          if (((-1 < iVar16) && (local_58 = puVar4, iVar16 < (int)puVar4)) &&
             ((local_58 = (undefined2 *)(iVar1 + (int)puVar7), -1 < (int)local_58 &&
              ((int)local_58 < iVar3)))) {
            for (local_58 = (undefined2 *)(iVar2 + (local_18 + -5) * 2);
                (undefined2 *)(iVar2 + (local_18 - (int)puVar7) * 2) <= local_58;
                local_58 = local_58 + -1) {
              *local_58 = param_5;
            }
          }
        }
        else if ((iVar16 < 0) || ((int)puVar4 <= iVar16)) {
          for (local_58 = (undefined2 *)(iVar2 + (local_18 - iVar18) * 2);
              (undefined2 *)(iVar2 + (local_18 + -5 + (int)puVar4) * 2) <= local_58;
              local_58 = local_58 + -1) {
            *local_58 = param_5;
          }
        }
        else {
          for (local_58 = (undefined2 *)(iVar2 + (local_18 - iVar18) * 2);
              (undefined2 *)(iVar2 + (local_18 - (int)puVar7) * 2) <= local_58;
              local_58 = local_58 + -1) {
            *local_58 = param_5;
          }
        }
        if (-1 < iVar16) {
          if (((iVar16 < (int)puVar4) &&
              (local_58 = (undefined2 *)(iVar1 + (int)puVar7), -1 < (int)local_58)) &&
             ((int)local_58 < iVar3)) {
            if ((iVar18 + iVar1 < 0) || (iVar3 <= iVar18 + iVar1)) {
              for (local_58 = (undefined2 *)(iVar2 + (local_18 - (int)puVar7) * 2);
                  (undefined2 *)(iVar8 + iVar16 * 2) <= local_58; local_58 = local_58 + -uVar6) {
                *local_58 = param_5;
              }
            }
            else {
              for (local_58 = (undefined2 *)(iVar2 + (local_18 - (int)puVar7) * 2);
                  (undefined2 *)(iVar2 + (local_1c - (int)puVar7) * 2) <= local_58;
                  local_58 = local_58 + -uVar6) {
                *local_58 = param_5;
              }
            }
          }
          else if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
                  ((local_58 = (undefined2 *)(iVar18 + iVar1), -1 < (int)local_58 &&
                   ((int)local_58 < iVar3)))) {
            for (local_58 = (undefined2 *)(iVar5 + iVar16 * 2);
                (undefined2 *)(iVar2 + (local_1c - (int)puVar7) * 2) <= local_58;
                local_58 = local_58 + -uVar6) {
              *local_58 = param_5;
            }
          }
        }
        local_24 = puVar7;
        if (-1 < iVar16) {
          if (((iVar16 < (int)puVar4) &&
              (local_58 = (undefined2 *)(iVar1 - iVar18), -1 < (int)local_58)) &&
             ((int)local_58 < iVar3)) {
            if ((iVar1 - (int)puVar7 < 0) || (iVar3 <= iVar1 - (int)puVar7)) {
              for (local_58 = (undefined2 *)(iVar2 + (local_1c + (int)puVar7) * -2);
                  (undefined2 *)(iVar8 + iVar16 * 2) <= local_58; local_58 = local_58 + -uVar6) {
                *local_58 = param_5;
              }
            }
            else {
              for (local_58 = (undefined2 *)(iVar2 + (local_1c + (int)puVar7) * -2);
                  (undefined2 *)(iVar2 + (local_18 + (int)puVar7) * -2) <= local_58;
                  local_58 = local_58 + -uVar6) {
                *local_58 = param_5;
              }
            }
          }
          else if (((-1 < iVar16) && (iVar16 < (int)puVar4)) &&
                  ((local_58 = (undefined2 *)(iVar1 - (int)puVar7), -1 < (int)local_58 &&
                   ((int)local_58 < iVar3)))) {
            local_58 = (undefined2 *)(iVar2 + (local_18 + (int)puVar7) * -2);
            for (puVar7 = (undefined2 *)(iVar5 + iVar16 * 2); local_58 <= puVar7;
                puVar7 = puVar7 + -uVar6) {
              *puVar7 = param_5;
            }
          }
        }
      }
      local_2c = local_2c + 1;
      local_20 = iVar18;
    } while (iVar18 <= (int)local_24);
  }
LAB_005e1770:
  return CONCAT31((int3)((uint)local_58 >> 8),1);
}

