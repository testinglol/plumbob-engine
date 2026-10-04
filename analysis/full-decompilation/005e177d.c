
uint FUN_005e177d(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  int *extraout_ECX;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  undefined2 uVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int aiStack_104c [1024];
  int local_4c;
  uint local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int iStack_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int iVar17;
  int iVar18;
  
  FUN_00636080();
  iVar14 = (param_2 - param_1) + param_3;
  uVar2 = extraout_ECX[7];
  if (((((param_1 < 0) || ((int)uVar2 <= param_1)) || (param_3 < 0)) ||
      (((int)uVar2 <= param_3 || (param_2 < 0)))) ||
     ((extraout_ECX[8] <= param_2 || ((iVar14 < 0 || (extraout_ECX[8] <= iVar14)))))) {
    local_14 = param_6;
    local_18 = param_5;
    local_20 = param_3;
    iStack_24 = param_2;
    local_28 = param_1;
    local_2c = 0x5e1f1d;
    local_1c = iVar14;
    uVar2 = (**(code **)(*extraout_ECX + 0x84))();
    return uVar2;
  }
  if (param_6 == 0) {
LAB_005e1eff:
    return uVar2 & 0xffffff00;
  }
  local_48 = param_3 - param_1;
  if (local_48 >> 1 <= param_6) {
    local_14 = param_5;
    local_1c = param_3;
    local_20 = param_2;
    iStack_24 = param_1;
    local_28 = 0x5e1813;
    local_18 = iVar14;
    uVar2 = (**(code **)(*extraout_ECX + 0x8c))();
  }
  if (((((0x1000 < param_1) || (uVar2 = 0xfffff000, param_1 < -0x1000)) || (0x1000 < param_2)) ||
      (((param_2 < -0x1000 || (0x1000 < param_3)) ||
       ((param_3 < -0x1000 || ((0x1000 < iVar14 || (iVar14 < -0x1000)))))))) || (param_3 < param_1))
  goto LAB_005e1eff;
  local_14 = 0x5e1877;
  uVar2 = (**(code **)(*extraout_ECX + 0xd0))();
  uVar2 = uVar2 >> 1;
  iVar15 = (int)local_48 / 2;
  local_14 = 0x5e1890;
  iVar14 = (**(code **)(*extraout_ECX + 0xcc))();
  local_20 = 0;
  iVar14 = iVar14 + ((iVar15 + param_2) * uVar2 + (param_1 + param_3) / 2) * 2;
  iVar8 = iVar15 - param_6;
  local_40 = 1 - iVar8;
  local_1c = 3;
  local_3c = 3;
  local_18 = iVar15 * -2 + 5;
  local_14 = 5;
  iVar3 = iVar8 * -2 + 5;
  local_28 = iVar8 * uVar2;
  iVar17 = 0;
  local_30 = 0;
  iVar18 = 0;
  local_2c = 0;
  local_34 = iVar15 * uVar2;
  uVar13 = (undefined2)param_5;
  *(undefined2 *)(local_34 * 2 + iVar14) = uVar13;
  *(undefined2 *)(iVar14 + local_34 * -2) = uVar13;
  *(undefined2 *)(iVar14 + iVar15 * -2) = uVar13;
  *(undefined2 *)(iVar15 * 2 + iVar14) = uVar13;
  if (param_6 == 1) {
    if (0 < iVar15) {
      do {
        iVar17 = iVar17 + 1;
        iVar18 = iVar18 + uVar2;
        if (local_20 < 0) {
          iVar8 = local_18 + 2;
          iVar3 = local_1c;
        }
        else {
          local_14 = local_14 + -1;
          local_34 = local_34 - uVar2;
          iVar8 = local_18 + 4;
          iVar3 = local_18;
        }
        local_18 = iVar8;
        local_1c = local_1c + 2;
        local_20 = local_20 + iVar3;
        *(undefined2 *)(iVar14 + (iVar17 + local_34) * -2) = uVar13;
        *(undefined2 *)(iVar14 + (iVar17 - local_34) * 2) = uVar13;
        *(undefined2 *)(iVar14 + (local_14 - iVar18) * 2) = uVar13;
        *(undefined2 *)((iVar18 + local_14) * 2 + iVar14) = uVar13;
        *(undefined2 *)((iVar17 + local_34) * 2 + iVar14) = uVar13;
        *(undefined2 *)(iVar14 + (local_34 - iVar17) * 2) = uVar13;
        *(undefined2 *)(iVar14 + (iVar18 - local_14) * 2) = uVar13;
        *(undefined2 *)(iVar14 + (iVar18 + local_14) * -2) = uVar13;
      } while (iVar17 < (int)local_14);
    }
    goto LAB_005e19c3;
  }
  iVar17 = 0;
  if (iVar8 < iVar15) {
    do {
      iVar15 = iVar17 + 1;
      if ((int)local_14 <= iVar15) break;
      iVar18 = iVar18 + uVar2;
      if (local_20 < 0) {
        iVar1 = local_18 + 2;
        iVar17 = local_1c;
      }
      else {
        local_34 = local_34 - uVar2;
        local_14 = local_14 + -1;
        puVar16 = (undefined4 *)(iVar14 + (local_34 + iVar15) * -2);
        puVar6 = (undefined4 *)(iVar14 + (iVar15 - local_34) * 2);
        if (puVar16 < puVar6) {
          uVar9 = (int)puVar6 + (1 - (int)puVar16);
          for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar16 = CONCAT22(uVar13,uVar13);
            puVar16 = puVar16 + 1;
          }
          for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined2 *)puVar16 = uVar13;
            puVar16 = (undefined4 *)((int)puVar16 + 2);
          }
        }
        for (puVar11 = (undefined2 *)((local_34 + iVar15) * 2 + iVar14);
            (undefined2 *)(iVar14 + (local_34 - iVar15) * 2) < puVar11; puVar11 = puVar11 + -1) {
          *puVar11 = uVar13;
        }
        for (puVar11 = (undefined2 *)(iVar14 + (iVar18 - local_14) * 2);
            (undefined2 *)(iVar14 + (local_14 + iVar18) * -2) < puVar11; puVar11 = puVar11 + -uVar2)
        {
          *puVar11 = uVar13;
        }
        for (puVar11 = (undefined2 *)(iVar14 + (local_14 - iVar18) * 2); iVar1 = local_18 + 4,
            iVar17 = local_18, puVar11 < (undefined2 *)((local_14 + iVar18) * 2 + iVar14);
            puVar11 = puVar11 + uVar2) {
          *puVar11 = uVar13;
        }
      }
      local_18 = iVar1;
      local_20 = local_20 + iVar17;
      local_1c = local_1c + 2;
      iVar17 = iVar15;
    } while (iVar8 < (int)local_14);
    if ((int)local_14 <= iVar8) goto LAB_005e1b94;
    iVar18 = iVar18 + uVar2;
    iVar17 = iVar17 + 1;
    while (local_38 = iVar3, local_34 = iVar8, iVar8 < iVar17) {
      iVar18 = iVar18 - uVar2;
      iVar17 = iVar17 + -1;
      puVar16 = (undefined4 *)(iVar14 + (iVar18 + iVar17) * -2);
      puVar6 = (undefined4 *)(iVar14 + (iVar17 - iVar18) * 2);
      if (puVar16 < puVar6) {
        uVar9 = (int)puVar6 + (1 - (int)puVar16);
        puVar12 = puVar16;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar12 = CONCAT22(uVar13,uVar13);
          puVar12 = puVar12 + 1;
        }
        for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined2 *)puVar12 = uVar13;
          puVar12 = (undefined4 *)((int)puVar12 + 2);
        }
      }
      puVar12 = (undefined4 *)(iVar14 + (iVar18 - iVar17) * 2);
      puVar4 = (undefined4 *)((iVar18 + iVar17) * 2 + iVar14);
      for (puVar5 = puVar4; puVar12 < puVar5; puVar5 = (undefined4 *)((int)puVar5 - 2)) {
        *(undefined2 *)puVar5 = uVar13;
      }
      for (; puVar16 < puVar12; puVar12 = (undefined4 *)((int)puVar12 + uVar2 * -2)) {
        *(undefined2 *)puVar12 = uVar13;
      }
      if (puVar6 < puVar4) {
        do {
          *(undefined2 *)puVar6 = uVar13;
          puVar6 = (undefined4 *)((int)puVar6 + uVar2 * 2);
        } while (puVar6 < puVar4);
      }
    }
  }
  else {
LAB_005e1b94:
    while (iVar15 = iVar17 + 1, iVar15 < (int)local_14) {
      iVar18 = iVar18 + uVar2;
      iVar17 = iVar15;
      if (local_20 < 0) {
        local_20 = local_20 + local_1c;
        local_1c = local_1c + 2;
        local_18 = local_18 + 2;
      }
      else {
        local_20 = local_20 + local_18;
        local_1c = local_1c + 2;
        local_18 = local_18 + 4;
        local_14 = local_14 + -1;
        aiStack_104c[local_14 * 2] = iVar15;
        aiStack_104c[local_14 * 2 + 1] = iVar18;
      }
    }
    local_4c = iVar17 + 1;
    local_34 = iVar8;
    while (local_38 = iVar3, iVar17 + 1 < local_34) {
      local_30 = local_30 + 1;
      local_2c = local_2c + uVar2;
      if (local_40 < 0) {
        local_38 = iVar3 + 2;
        iVar3 = local_3c;
      }
      else {
        local_38 = iVar3 + 4;
        local_34 = local_34 + -1;
        local_28 = local_28 - uVar2;
      }
      local_3c = local_3c + 2;
      local_40 = local_40 + iVar3;
      iVar18 = aiStack_104c[local_34 * 2];
      iVar8 = aiStack_104c[local_34 * 2 + 1];
      puVar6 = (undefined4 *)(iVar14 + (iVar18 + local_28) * -2);
      puVar16 = (undefined4 *)(iVar14 + (local_28 + local_30) * -2);
      if (puVar6 < puVar16) {
        uVar9 = (int)puVar16 + (1 - (int)puVar6);
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar6 = CONCAT22(uVar13,uVar13);
          puVar6 = puVar6 + 1;
        }
        for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined2 *)puVar6 = uVar13;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        }
      }
      puVar6 = (undefined4 *)(iVar14 + (local_30 - local_28) * 2);
      puVar16 = (undefined4 *)(iVar14 + (iVar18 - local_28) * 2);
      if (puVar6 < puVar16) {
        uVar9 = (int)puVar16 + (1 - (int)puVar6);
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar6 = CONCAT22(uVar13,uVar13);
          puVar6 = puVar6 + 1;
        }
        for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined2 *)puVar6 = uVar13;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        }
      }
      for (puVar11 = (undefined2 *)(iVar14 + (local_34 - iVar8) * 2);
          puVar11 < (undefined2 *)(iVar14 + (local_34 - local_2c) * 2); puVar11 = puVar11 + uVar2) {
        *puVar11 = uVar13;
      }
      for (puVar11 = (undefined2 *)((local_2c + local_34) * 2 + iVar14);
          puVar11 < (undefined2 *)((iVar8 + local_34) * 2 + iVar14); puVar11 = puVar11 + uVar2) {
        *puVar11 = uVar13;
      }
      for (puVar11 = (undefined2 *)((iVar18 + local_28) * 2 + iVar14);
          (undefined2 *)((local_28 + local_30) * 2 + iVar14) < puVar11; puVar11 = puVar11 + -1) {
        *puVar11 = uVar13;
      }
      for (puVar11 = (undefined2 *)(iVar14 + (local_28 - local_30) * 2);
          (undefined2 *)(iVar14 + (local_28 - iVar18) * 2) < puVar11; puVar11 = puVar11 + -1) {
        *puVar11 = uVar13;
      }
      for (puVar11 = (undefined2 *)(iVar14 + (iVar8 - local_34) * 2);
          (undefined2 *)(iVar14 + (local_2c - local_34) * 2) < puVar11; puVar11 = puVar11 + -uVar2)
      {
        *puVar11 = uVar13;
      }
      for (puVar11 = (undefined2 *)(iVar14 + (local_2c + local_34) * -2); iVar3 = local_38,
          (undefined2 *)(iVar14 + (iVar8 + local_34) * -2) < puVar11; puVar11 = puVar11 + -uVar2) {
        *puVar11 = uVar13;
      }
    }
  }
  while (local_30 <= local_34) {
    local_30 = local_30 + 1;
    local_2c = local_2c + uVar2;
    if (local_40 < 0) {
      local_40 = local_40 + local_3c;
      local_3c = local_3c + 2;
      local_38 = local_38 + 2;
    }
    else {
      local_3c = local_3c + 2;
      local_40 = local_40 + local_38;
      local_38 = local_38 + 4;
      local_34 = local_34 + -1;
      local_28 = local_28 - uVar2;
      puVar16 = (undefined4 *)(iVar14 + (local_34 + local_28) * -2);
      puVar6 = (undefined4 *)(iVar14 + (local_28 + local_30) * -2);
      if (puVar16 <= puVar6) {
        uVar9 = (int)puVar6 + (2 - (int)puVar16);
        puVar6 = puVar16;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar6 = CONCAT22(uVar13,uVar13);
          puVar6 = puVar6 + 1;
        }
        for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined2 *)puVar6 = uVar13;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        }
      }
      puVar6 = (undefined4 *)(iVar14 + (local_30 - local_28) * 2);
      puVar12 = (undefined4 *)(iVar14 + (local_34 - local_28) * 2);
      if (puVar6 < puVar12) {
        uVar9 = (int)puVar12 + (1 - (int)puVar6);
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *puVar6 = CONCAT22(uVar13,uVar13);
          puVar6 = puVar6 + 1;
        }
        for (uVar9 = (uint)((uVar9 >> 1 & 1) != 0); uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined2 *)puVar6 = uVar13;
          puVar6 = (undefined4 *)((int)puVar6 + 2);
        }
      }
      for (; puVar12 <= (undefined4 *)(iVar14 + (local_34 - local_2c) * 2);
          puVar12 = (undefined4 *)((int)puVar12 + uVar2 * 2)) {
        *(undefined2 *)puVar12 = uVar13;
      }
      puVar7 = (undefined2 *)((local_34 + local_28) * 2 + iVar14);
      for (puVar11 = (undefined2 *)((local_2c + local_34) * 2 + iVar14); puVar11 < puVar7;
          puVar11 = puVar11 + uVar2) {
        *puVar11 = uVar13;
      }
      for (; (undefined2 *)((local_28 + local_30) * 2 + iVar14) <= puVar7; puVar7 = puVar7 + -1) {
        *puVar7 = uVar13;
      }
      puVar7 = (undefined2 *)(iVar14 + (local_28 - local_34) * 2);
      for (puVar11 = (undefined2 *)(iVar14 + (local_28 - local_30) * 2); puVar7 < puVar11;
          puVar11 = puVar11 + -1) {
        *puVar11 = uVar13;
      }
      for (; (undefined2 *)(iVar14 + (local_2c - local_34) * 2) <= puVar7; puVar7 = puVar7 + -uVar2)
      {
        *puVar7 = uVar13;
      }
      for (puVar6 = (undefined4 *)(iVar14 + (local_2c + local_34) * -2); puVar16 <= puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + uVar2 * -2)) {
        *(undefined2 *)puVar6 = uVar13;
      }
    }
  }
LAB_005e19c3:
  return CONCAT31((int3)((uint)local_34 >> 8),1);
}

