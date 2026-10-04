
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ab7b0(undefined4 *param_1,undefined1 *param_2,byte param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  float fVar9;
  undefined *puVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  float *pfVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  uint uVar19;
  int *piVar20;
  int *piVar21;
  int local_98;
  undefined1 *local_94;
  undefined1 *local_90;
  int local_8c;
  int local_88;
  int local_84;
  int *local_7c;
  int local_78 [30];
  
  local_88 = param_4;
  local_8c = param_4;
  DAT_006fd038 = PTR_DAT_006d2128 + DAT_006d2134;
  iVar14 = 0;
  DAT_006fd03c = PTR_DAT_006d2128 + DAT_006d2134 * 2;
  DAT_006fd040 = PTR_DAT_006d2128 + DAT_006d2134 * 3;
  DAT_006fd034 = PTR_DAT_006d2128;
  local_94 = param_2;
  piVar15 = (int *)&DAT_006fd034;
  if (DAT_006fd058 == 1) {
    puVar17 = (undefined4 *)*param_1;
    puVar18 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar18 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar18 = puVar18 + 1;
    }
    puVar17 = (undefined4 *)param_1[1];
    puVar18 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar18 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar18 = puVar18 + 1;
    }
    puVar17 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar13 = 10;
  }
  else {
    puVar17 = (undefined4 *)*param_1;
    puVar18 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar18 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar18 = puVar18 + 1;
    }
    puVar17 = (undefined4 *)param_1[1];
    puVar18 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar18 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar18 = puVar18 + 1;
    }
    puVar17 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar13 = 8;
  }
  puVar18 = (undefined4 *)param_1[2];
  for (; iVar13 != 0; iVar13 = iVar13 + -1) {
    *puVar17 = *puVar18;
    puVar18 = puVar18 + 1;
    puVar17 = puVar17 + 1;
  }
  if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
    *(float *)(DAT_006fd034 + 0x18) =
         *(float *)(DAT_006fd034 + 0xc) * *(float *)(DAT_006fd034 + 0x18);
    *(float *)(DAT_006fd034 + 0x1c) =
         *(float *)(DAT_006fd034 + 0xc) * *(float *)(DAT_006fd034 + 0x1c);
    *(float *)(DAT_006fd038 + 0x18) =
         *(float *)(DAT_006fd038 + 0xc) * *(float *)(DAT_006fd038 + 0x18);
    *(float *)(DAT_006fd038 + 0x1c) =
         *(float *)(DAT_006fd038 + 0xc) * *(float *)(DAT_006fd038 + 0x1c);
    *(float *)(DAT_006fd03c + 0x18) =
         *(float *)(DAT_006fd03c + 0xc) * *(float *)(DAT_006fd03c + 0x18);
    *(float *)(DAT_006fd03c + 0x1c) =
         *(float *)(DAT_006fd03c + 0xc) * *(float *)(DAT_006fd03c + 0x1c);
    if (DAT_006fd058 == 1) {
      *(float *)(DAT_006fd034 + 0x20) =
           *(float *)(DAT_006fd034 + 0xc) * *(float *)(DAT_006fd034 + 0x20);
      *(float *)(DAT_006fd034 + 0x24) =
           *(float *)(DAT_006fd034 + 0xc) * *(float *)(DAT_006fd034 + 0x24);
      *(float *)(DAT_006fd038 + 0x20) =
           *(float *)(DAT_006fd038 + 0xc) * *(float *)(DAT_006fd038 + 0x20);
      *(float *)(DAT_006fd038 + 0x24) =
           *(float *)(DAT_006fd038 + 0xc) * *(float *)(DAT_006fd038 + 0x24);
      *(float *)(DAT_006fd03c + 0x20) =
           *(float *)(DAT_006fd03c + 0xc) * *(float *)(DAT_006fd03c + 0x20);
      *(float *)(DAT_006fd03c + 0x24) =
           *(float *)(DAT_006fd03c + 0xc) * *(float *)(DAT_006fd03c + 0x24);
    }
  }
  if (param_4 == 4) {
    puVar18 = (undefined4 *)param_1[3];
    puVar17 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 3);
    for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar17 = *puVar18;
      puVar18 = puVar18 + 1;
      puVar17 = puVar17 + 1;
    }
    if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
      *(float *)(DAT_006fd040 + 0x18) =
           *(float *)(DAT_006fd040 + 0xc) * *(float *)(DAT_006fd040 + 0x18);
      *(float *)(DAT_006fd040 + 0x1c) =
           *(float *)(DAT_006fd040 + 0xc) * *(float *)(DAT_006fd040 + 0x1c);
      if (DAT_006fd058 == 1) {
        *(float *)(DAT_006fd040 + 0x20) =
             *(float *)(DAT_006fd040 + 0xc) * *(float *)(DAT_006fd040 + 0x20);
        *(float *)(DAT_006fd040 + 0x24) =
             *(float *)(DAT_006fd040 + 0xc) * *(float *)(DAT_006fd040 + 0x24);
      }
    }
  }
  puVar10 = PTR_DAT_006d211c;
  local_7c = (int *)PTR_DAT_006d211c;
  local_90 = &DAT_006fcfb0;
  if ((param_3 & 3) != 0) {
    piVar21 = (int *)PTR_DAT_006d211c;
    if ((param_3 & 1) != 0) {
      iVar14 = 0;
      local_98 = 0;
      iVar13 = param_4 + -1;
      do {
        if ((param_2[iVar13] & 1) == 0) {
          *(undefined **)(puVar10 + iVar14 * 4) = (&DAT_006fd034)[iVar13];
          (&DAT_006fcfb0)[iVar14] = param_2[iVar13];
          iVar14 = iVar14 + 1;
        }
        if (((param_2[local_98] ^ param_2[iVar13]) & 1) != 0) {
          pfVar7 = (float *)(&DAT_006fd034)[local_98];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          pfVar8 = (float *)(&DAT_006fd034)[iVar13];
          local_94 = (undefined1 *)((pfVar8[3] - DAT_00703f14) / (pfVar8[3] - pfVar7[3]));
          fVar1 = pfVar8[1];
          fVar2 = pfVar7[1];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar16 = *pfVar8 - (*pfVar8 - *pfVar7) * (float)local_94;
          pfVar16[1] = *(float *)((int)(&DAT_006fd034)[iVar13] + 4) -
                       (fVar1 - fVar2) * (float)local_94;
          if ((DAT_006fd06c & DAT_006d2120) == 0x10000) {
            if (0x3f800000 < (int)local_94) {
              local_94 = (undefined1 *)0x3f800000;
            }
            if ((int)local_94 < 0) {
              local_94 = (undefined1 *)0x0;
            }
          }
          pfVar16[6] = *(float *)((int)(&DAT_006fd034)[iVar13] + 0x18) -
                       (fVar3 - fVar4) * (float)local_94;
          pfVar16[7] = *(float *)((int)(&DAT_006fd034)[iVar13] + 0x1c) -
                       (fVar5 - fVar6) * (float)local_94;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)((int)(&DAT_006fd034)[iVar13] + 0x24);
            fVar2 = *(float *)((int)(&DAT_006fd034)[local_98] + 0x24);
            fVar3 = *(float *)((int)(&DAT_006fd034)[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x20) =
                 fVar3 - (fVar3 - *(float *)((int)(&DAT_006fd034)[local_98] + 0x20)) *
                         (float)local_94;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x24) =
                 *(float *)((int)(&DAT_006fd034)[iVar13] + 0x24) - (fVar1 - fVar2) * (float)local_94
            ;
          }
          uVar19 = *(uint *)((int)(&DAT_006fd034)[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)((int)(&DAT_006fd034)[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar13 = __ftol();
          DAT_006f77bc = uVar19 - iVar13;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          pfVar16[2] = 0.0;
          pfVar16[3] = DAT_00703f14;
          (&DAT_006fcfb0)[iVar14] = 1;
          if (DAT_006fd060 <= pfVar16[1]) {
            if (DAT_006d213c < pfVar16[1]) {
              (&DAT_006fcfb0)[iVar14] = 9;
            }
          }
          else {
            (&DAT_006fcfb0)[iVar14] = 5;
          }
          if (DAT_006fd05c <= *pfVar16) {
            if (DAT_006d2138 < *pfVar16) {
              bVar11 = (&DAT_006fcfb0)[iVar14] | 0x20;
              goto LAB_005abc72;
            }
          }
          else {
            bVar11 = (&DAT_006fcfb0)[iVar14] | 0x10;
LAB_005abc72:
            (&DAT_006fcfb0)[iVar14] = bVar11;
          }
          *(undefined **)(puVar10 + iVar14 * 4) = PTR_DAT_006d2128 + DAT_006d2134 * local_8c;
          iVar14 = iVar14 + 1;
          local_8c = local_8c + 1;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      if (iVar14 < 3) {
        return 0xffffffff;
      }
      piVar21 = (int *)(puVar10 + iVar14 * 4);
      local_90 = &DAT_006fcfb0 + iVar14;
      local_94 = &DAT_006fcfb0;
      piVar15 = (int *)PTR_DAT_006d211c;
      local_88 = iVar14;
    }
    local_7c = piVar21;
    if ((param_3 & 2) != 0) {
      iVar14 = 0;
      local_98 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_94[iVar13] & 2) == 0) {
          piVar21[iVar14] = piVar15[iVar13];
          local_90[iVar14] = local_94[iVar13];
          iVar14 = iVar14 + 1;
        }
        if (((local_94[local_98] ^ local_94[iVar13]) & 2) != 0) {
          pfVar7 = (float *)piVar15[iVar13];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          pfVar8 = (float *)piVar15[local_98];
          fVar9 = (pfVar7[3] - DAT_00703f20) / (pfVar7[3] - pfVar8[3]);
          fVar1 = pfVar7[1];
          fVar2 = pfVar8[1];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar16 = *pfVar7 - (*pfVar7 - *pfVar8) * fVar9;
          pfVar16[1] = *(float *)(piVar15[iVar13] + 4) - (fVar1 - fVar2) * fVar9;
          pfVar16[6] = *(float *)(piVar15[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar16[7] = *(float *)(piVar15[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar15[iVar13] + 0x24);
            fVar2 = *(float *)(piVar15[local_98] + 0x24);
            fVar3 = *(float *)(piVar15[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar15[local_98] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x24) =
                 *(float *)(piVar15[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar19 = *(uint *)(piVar15[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)(piVar15[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar13 = __ftol();
          DAT_006f77bc = uVar19 - iVar13;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          pfVar16[2] = 1.0;
          pfVar16[3] = DAT_00703f20;
          local_90[iVar14] = 1;
          if (DAT_006fd060 <= pfVar16[1]) {
            if (DAT_006d213c < pfVar16[1]) {
              local_90[iVar14] = 9;
            }
          }
          else {
            local_90[iVar14] = 5;
          }
          if (DAT_006fd05c <= *pfVar16) {
            if (DAT_006d2138 < *pfVar16) {
              bVar11 = local_90[iVar14] | 0x20;
              goto LAB_005abef4;
            }
          }
          else {
            bVar11 = local_90[iVar14] | 0x10;
LAB_005abef4:
            local_90[iVar14] = bVar11;
          }
          piVar21[iVar14] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          iVar14 = iVar14 + 1;
          local_8c = local_8c + 1;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      if (iVar14 < 3) {
        return 0xffffffff;
      }
      local_7c = piVar21 + iVar14;
      local_94 = local_90;
      piVar15 = piVar21;
      local_90 = local_90 + iVar14;
      local_88 = iVar14;
    }
    param_3 = local_94[iVar14 + -1];
    iVar14 = iVar14 + -1;
    do {
      iVar13 = iVar14 + -1;
      iVar14 = iVar14 + -1;
      param_3 = param_3 | local_94[iVar13];
    } while (0 < iVar14);
  }
  if ((param_3 & 0xc) != 0) {
    if ((param_3 & 8) != 0) {
      iVar14 = 0;
      local_98 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_94[iVar13] & 8) == 0) {
          local_7c[iVar14] = piVar15[iVar13];
          local_90[iVar14] = local_94[iVar13];
          iVar14 = iVar14 + 1;
        }
        if (((local_94[local_98] ^ local_94[iVar13]) & 8) != 0) {
          pfVar7 = (float *)piVar15[local_98];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          pfVar8 = (float *)piVar15[iVar13];
          fVar9 = (pfVar8[1] - DAT_006d213c) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar16 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar9;
          pfVar16[3] = *(float *)(piVar15[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar16[6] = *(float *)(piVar15[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar16[7] = *(float *)(piVar15[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar16[2] = *(float *)(piVar15[iVar13] + 8) -
                         (*(float *)(piVar15[iVar13] + 8) - *(float *)(piVar15[local_98] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar15[iVar13] + 0x24);
            fVar2 = *(float *)(piVar15[local_98] + 0x24);
            fVar3 = *(float *)(piVar15[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar15[local_98] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x24) =
                 *(float *)(piVar15[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar19 = *(uint *)(piVar15[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)(piVar15[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar12 = __ftol();
          DAT_006f77bc = uVar19 - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          pfVar16[1] = DAT_006d213c;
          bVar11 = local_94[iVar13] & 0xcb;
          local_90[iVar14] = bVar11 | 8;
          if (DAT_006fd05c <= *pfVar16) {
            if (DAT_006d2138 < *pfVar16) {
              bVar11 = bVar11 | 0x28;
              goto LAB_005ac186;
            }
          }
          else {
            bVar11 = bVar11 | 0x18;
LAB_005ac186:
            local_90[iVar14] = bVar11;
          }
          local_7c[iVar14] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          iVar14 = iVar14 + 1;
          local_8c = local_8c + 1;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      if (iVar14 < 3) {
        return 0xffffffff;
      }
      local_94 = local_90;
      piVar15 = local_7c;
      local_90 = local_90 + iVar14;
      local_88 = iVar14;
      local_7c = local_7c + iVar14;
    }
    if ((param_3 & 4) != 0) {
      iVar14 = 0;
      local_98 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_94[iVar13] & 4) == 0) {
          local_7c[iVar14] = piVar15[iVar13];
          local_90[iVar14] = local_94[iVar13];
          iVar14 = iVar14 + 1;
        }
        if (((local_94[local_98] ^ local_94[iVar13]) & 4) != 0) {
          pfVar7 = (float *)piVar15[local_98];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          pfVar8 = (float *)piVar15[iVar13];
          fVar9 = (pfVar8[1] - DAT_006fd060) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar16 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar9;
          pfVar16[3] = *(float *)(piVar15[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar16[6] = *(float *)(piVar15[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar16[7] = *(float *)(piVar15[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar16[2] = *(float *)(piVar15[iVar13] + 8) -
                         (*(float *)(piVar15[iVar13] + 8) - *(float *)(piVar15[local_98] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar15[iVar13] + 0x24);
            fVar2 = *(float *)(piVar15[local_98] + 0x24);
            fVar3 = *(float *)(piVar15[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar15[local_98] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x24) =
                 *(float *)(piVar15[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar19 = *(uint *)(piVar15[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)(piVar15[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar12 = __ftol();
          DAT_006f77bc = uVar19 - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          pfVar16[1] = DAT_006fd060;
          bVar11 = local_94[iVar13] & 199;
          local_90[iVar14] = bVar11 | 4;
          if (DAT_006fd05c <= *pfVar16) {
            if (DAT_006d2138 < *pfVar16) {
              bVar11 = bVar11 | 0x24;
              goto LAB_005ac407;
            }
          }
          else {
            bVar11 = bVar11 | 0x14;
LAB_005ac407:
            local_90[iVar14] = bVar11;
          }
          local_7c[iVar14] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          iVar14 = iVar14 + 1;
          local_8c = local_8c + 1;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      if (iVar14 < 3) {
        return 0xffffffff;
      }
      local_94 = local_90;
      piVar15 = local_7c;
      local_90 = local_90 + iVar14;
      local_88 = iVar14;
      local_7c = local_7c + iVar14;
    }
    param_3 = local_94[iVar14 + -1];
    iVar14 = iVar14 + -1;
    do {
      iVar13 = iVar14 + -1;
      iVar14 = iVar14 + -1;
      param_3 = param_3 | local_94[iVar13];
    } while (0 < iVar14);
  }
  if ((param_3 & 0x30) != 0) {
    iVar14 = local_8c;
    if ((param_3 & 0x10) != 0) {
      iVar12 = 0;
      local_84 = 0;
      local_98 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_94[iVar13] & 0x10) == 0) {
          local_7c[iVar12] = piVar15[iVar13];
          local_90[iVar12] = local_94[iVar13];
          iVar12 = iVar12 + 1;
          iVar14 = local_8c;
          local_84 = iVar12;
        }
        if (((local_94[local_98] ^ local_94[iVar13]) & 0x10) != 0) {
          pfVar7 = (float *)piVar15[iVar13];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14);
          pfVar8 = (float *)piVar15[local_98];
          fVar9 = (*pfVar7 - DAT_006fd05c) / (*pfVar7 - *pfVar8);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          pfVar16[1] = pfVar7[1] - (pfVar7[1] - pfVar8[1]) * fVar9;
          pfVar16[3] = *(float *)(piVar15[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar16[6] = *(float *)(piVar15[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar16[7] = *(float *)(piVar15[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar16[2] = *(float *)(piVar15[iVar13] + 8) -
                         (*(float *)(piVar15[iVar13] + 8) - *(float *)(piVar15[local_98] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar15[iVar13] + 0x24);
            fVar2 = *(float *)(piVar15[local_98] + 0x24);
            fVar3 = *(float *)(piVar15[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar15[local_98] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14 + 0x24) =
                 *(float *)(piVar15[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar19 = *(uint *)(piVar15[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)(piVar15[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar14 = __ftol();
          DAT_006f77bc = uVar19 - iVar14;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          *pfVar16 = DAT_006fd05c;
          local_90[local_84] = local_94[iVar13] & 0xdf | 0x10;
          local_7c[local_84] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          iVar12 = local_84 + 1;
          iVar14 = local_8c + 1;
          local_8c = iVar14;
          local_84 = iVar12;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      if (iVar12 < 3) {
        return 0xffffffff;
      }
      local_94 = local_90;
      piVar15 = local_7c;
      local_90 = local_90 + iVar12;
      local_88 = iVar12;
      local_7c = local_7c + iVar12;
    }
    if ((param_3 & 0x20) != 0) {
      iVar12 = 0;
      local_84 = 0;
      local_98 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_94[iVar13] & 0x20) == 0) {
          local_7c[iVar12] = piVar15[iVar13];
          local_90[iVar12] = local_94[iVar13];
          iVar12 = iVar12 + 1;
          iVar14 = local_8c;
          local_84 = iVar12;
        }
        if (((local_94[local_98] ^ local_94[iVar13]) & 0x20) != 0) {
          pfVar7 = (float *)piVar15[iVar13];
          pfVar16 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14);
          pfVar8 = (float *)piVar15[local_98];
          fVar9 = (*pfVar7 - DAT_006d2138) / (*pfVar7 - *pfVar8);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          pfVar16[1] = pfVar7[1] - (pfVar7[1] - pfVar8[1]) * fVar9;
          pfVar16[3] = *(float *)(piVar15[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar16[6] = *(float *)(piVar15[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar16[7] = *(float *)(piVar15[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar16[2] = *(float *)(piVar15[iVar13] + 8) -
                         (*(float *)(piVar15[iVar13] + 8) - *(float *)(piVar15[local_98] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar15[iVar13] + 0x24);
            fVar2 = *(float *)(piVar15[local_98] + 0x24);
            fVar3 = *(float *)(piVar15[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar15[local_98] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * iVar14 + 0x24) =
                 *(float *)(piVar15[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar19 = *(uint *)(piVar15[iVar13] + 0x10) & 0xff;
          DAT_006f9730 = *(uint *)(piVar15[local_98] + 0x10) & 0xff;
          _DAT_006f77cc = (float)(int)(uVar19 - DAT_006f9730);
          DAT_006f77bc = uVar19;
          iVar14 = __ftol();
          DAT_006f77bc = uVar19 - iVar14;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c + 0x10) =
               ((DAT_006f77bc | 0xffffff00) << 8 | DAT_006f77bc) << 8 | DAT_006f77bc;
          *pfVar16 = DAT_006d2138;
          local_90[local_84] = local_94[iVar13] & 0xef | 0x20;
          local_7c[local_84] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_8c);
          iVar12 = local_84 + 1;
          iVar14 = local_8c + 1;
          local_8c = iVar14;
          local_84 = iVar12;
        }
        local_88 = local_88 + -1;
        iVar13 = local_98;
        local_98 = local_98 + 1;
      } while (0 < local_88);
      piVar15 = local_7c;
      local_88 = iVar12;
      if (iVar12 < 3) {
        return 0xffffffff;
      }
    }
  }
  iVar14 = 0;
  if (0 < local_88) {
    do {
      iVar13 = piVar15[iVar14];
      fVar1 = _DAT_00672294 / *(float *)(iVar13 + 0xc);
      if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
        *(float *)(iVar13 + 0x18) = fVar1 * *(float *)(iVar13 + 0x18);
        *(float *)(piVar15[iVar14] + 0x1c) = fVar1 * *(float *)(piVar15[iVar14] + 0x1c);
      }
      if ((DAT_006d2124 & DAT_006fd06c) == 1) {
        *(float *)(piVar15[iVar14] + 8) = (fVar1 - _DAT_006fd064) * _DAT_006fd068;
      }
      if (DAT_006fd058 == 1) {
        *(float *)(piVar15[iVar14] + 0x20) = fVar1 * *(float *)(piVar15[iVar14] + 0x20);
        *(float *)(piVar15[iVar14] + 0x24) = fVar1 * *(float *)(piVar15[iVar14] + 0x24);
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < local_88);
  }
  iVar13 = 0;
  iVar14 = (local_88 + -2) * 3;
  piVar21 = piVar15;
  if (0 < iVar14) {
    do {
      piVar20 = piVar21 + 1;
      if (DAT_006fd058 == 1) {
        local_78[iVar13] = (*piVar15 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar13 + 1] = (*piVar20 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar13 + 2] = (piVar21[2] - (int)PTR_DAT_006d2128) / 0x28;
      }
      else {
        local_78[iVar13] = *piVar15 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar13 + 1] = *piVar20 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar13 + 2] = piVar21[2] - (int)PTR_DAT_006d2128 >> 5;
      }
      iVar13 = iVar13 + 3;
      piVar21 = piVar20;
    } while (iVar13 < iVar14);
  }
  FUN_005b3260(local_88 + -2,PTR_DAT_006d2128,local_78);
  return 0;
}

