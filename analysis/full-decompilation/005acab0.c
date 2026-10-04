
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005acab0(undefined4 *param_1,undefined1 *param_2,byte param_3,int param_4)

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
  uint uVar15;
  int iVar16;
  int *piVar17;
  float *pfVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  int *piVar21;
  uint uVar22;
  int *piVar23;
  int local_9c;
  undefined1 *local_98;
  int local_94;
  int local_8c;
  int *local_88;
  int local_84;
  undefined1 *local_80;
  int local_78 [30];
  
  local_8c = param_4;
  local_84 = param_4;
  DAT_006f973c = PTR_DAT_006d2128 + DAT_006d2134;
  iVar16 = 0;
  DAT_006f9740 = PTR_DAT_006d2128 + DAT_006d2134 * 2;
  DAT_006f9744 = PTR_DAT_006d2128 + DAT_006d2134 * 3;
  DAT_006f9738 = PTR_DAT_006d2128;
  local_80 = param_2;
  piVar17 = (int *)&DAT_006f9738;
  if (DAT_006fd058 == 1) {
    puVar19 = (undefined4 *)*param_1;
    puVar20 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)param_1[1];
    puVar20 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar14 = 10;
  }
  else {
    puVar19 = (undefined4 *)*param_1;
    puVar20 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)param_1[1];
    puVar20 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar14 = 8;
  }
  puVar20 = (undefined4 *)param_1[2];
  for (; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar19 = *puVar20;
    puVar20 = puVar20 + 1;
    puVar19 = puVar19 + 1;
  }
  if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
    *(float *)(DAT_006f9738 + 0x18) =
         *(float *)(DAT_006f9738 + 0xc) * *(float *)(DAT_006f9738 + 0x18);
    *(float *)(DAT_006f9738 + 0x1c) =
         *(float *)(DAT_006f9738 + 0xc) * *(float *)(DAT_006f9738 + 0x1c);
    *(float *)(DAT_006f973c + 0x18) =
         *(float *)(DAT_006f973c + 0xc) * *(float *)(DAT_006f973c + 0x18);
    *(float *)(DAT_006f973c + 0x1c) =
         *(float *)(DAT_006f973c + 0xc) * *(float *)(DAT_006f973c + 0x1c);
    *(float *)(DAT_006f9740 + 0x18) =
         *(float *)(DAT_006f9740 + 0xc) * *(float *)(DAT_006f9740 + 0x18);
    *(float *)(DAT_006f9740 + 0x1c) =
         *(float *)(DAT_006f9740 + 0xc) * *(float *)(DAT_006f9740 + 0x1c);
    if (DAT_006fd058 == 1) {
      *(float *)(DAT_006f9738 + 0x20) =
           *(float *)(DAT_006f9738 + 0xc) * *(float *)(DAT_006f9738 + 0x20);
      *(float *)(DAT_006f9738 + 0x24) =
           *(float *)(DAT_006f9738 + 0xc) * *(float *)(DAT_006f9738 + 0x24);
      *(float *)(DAT_006f973c + 0x20) =
           *(float *)(DAT_006f973c + 0xc) * *(float *)(DAT_006f973c + 0x20);
      *(float *)(DAT_006f973c + 0x24) =
           *(float *)(DAT_006f973c + 0xc) * *(float *)(DAT_006f973c + 0x24);
      *(float *)(DAT_006f9740 + 0x20) =
           *(float *)(DAT_006f9740 + 0xc) * *(float *)(DAT_006f9740 + 0x20);
      *(float *)(DAT_006f9740 + 0x24) =
           *(float *)(DAT_006f9740 + 0xc) * *(float *)(DAT_006f9740 + 0x24);
    }
  }
  if (param_4 == 4) {
    puVar20 = (undefined4 *)param_1[3];
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 3);
    for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar19 = *puVar20;
      puVar20 = puVar20 + 1;
      puVar19 = puVar19 + 1;
    }
    if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
      *(float *)(DAT_006f9744 + 0x18) =
           *(float *)(DAT_006f9744 + 0xc) * *(float *)(DAT_006f9744 + 0x18);
      *(float *)(DAT_006f9744 + 0x1c) =
           *(float *)(DAT_006f9744 + 0xc) * *(float *)(DAT_006f9744 + 0x1c);
      if (DAT_006fd058 == 1) {
        *(float *)(DAT_006f9744 + 0x20) =
             *(float *)(DAT_006f9744 + 0xc) * *(float *)(DAT_006f9744 + 0x20);
        *(float *)(DAT_006f9744 + 0x24) =
             *(float *)(DAT_006f9744 + 0xc) * *(float *)(DAT_006f9744 + 0x24);
      }
    }
  }
  puVar10 = PTR_DAT_006d211c;
  local_88 = (int *)PTR_DAT_006d211c;
  local_98 = &DAT_006fcfb0;
  if ((param_3 & 3) != 0) {
    piVar23 = (int *)PTR_DAT_006d211c;
    if ((param_3 & 1) != 0) {
      iVar16 = 0;
      local_94 = 0;
      iVar14 = param_4 + -1;
      do {
        if ((param_2[iVar14] & 1) == 0) {
          *(undefined **)(puVar10 + iVar16 * 4) = (&DAT_006f9738)[iVar14];
          (&DAT_006fcfb0)[iVar16] = param_2[iVar14];
          iVar16 = iVar16 + 1;
        }
        if (((param_2[local_94] ^ param_2[iVar14]) & 1) != 0) {
          pfVar7 = (float *)(&DAT_006f9738)[iVar14];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)(&DAT_006f9738)[local_94];
          local_98 = (undefined1 *)((pfVar7[3] - DAT_00703f14) / (pfVar7[3] - pfVar8[3]));
          fVar1 = pfVar7[1];
          fVar2 = pfVar8[1];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar18 = *pfVar7 - (*pfVar7 - *pfVar8) * (float)local_98;
          pfVar18[1] = *(float *)((int)(&DAT_006f9738)[iVar14] + 4) -
                       (fVar1 - fVar2) * (float)local_98;
          if ((DAT_006fd06c & DAT_006d2120) == 0x10000) {
            if (0x3f800000 < (int)local_98) {
              local_98 = (undefined1 *)0x3f800000;
            }
            if ((int)local_98 < 0) {
              local_98 = (undefined1 *)0x0;
            }
          }
          pfVar18[6] = *(float *)((int)(&DAT_006f9738)[iVar14] + 0x18) -
                       (fVar3 - fVar4) * (float)local_98;
          pfVar18[7] = *(float *)((int)(&DAT_006f9738)[iVar14] + 0x1c) -
                       (fVar5 - fVar6) * (float)local_98;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)((int)(&DAT_006f9738)[iVar14] + 0x24);
            fVar2 = *(float *)((int)(&DAT_006f9738)[local_94] + 0x24);
            fVar3 = *(float *)((int)(&DAT_006f9738)[iVar14] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)((int)(&DAT_006f9738)[local_94] + 0x20)) *
                         (float)local_98;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)((int)(&DAT_006f9738)[iVar14] + 0x24) - (fVar1 - fVar2) * (float)local_98
            ;
          }
          uVar22 = *(uint *)((int)(&DAT_006f9738)[iVar14] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)((int)(&DAT_006f9738)[iVar14] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)((int)(&DAT_006f9738)[iVar14] + 0x12);
          uVar15 = (uint)*(byte *)((int)(&DAT_006f9738)[iVar14] + 0x13);
          iVar14 = (int)(&DAT_006f9738)[local_94];
          DAT_006f9730 = *(uint *)(iVar14 + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(iVar14 + 0x11);
          DAT_006f9748 = (uint)*(byte *)(iVar14 + 0x12);
          _DAT_006f972c = (uint)*(byte *)(iVar14 + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(uVar22 - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          DAT_006f77bc = uVar22;
          iVar14 = __ftol();
          DAT_006f77b8 = uVar15 - iVar14;
          iVar12 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar12;
          iVar12 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar12;
          iVar12 = __ftol();
          DAT_006f77bc = uVar22 - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar14) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar18[2] = 0.0;
          pfVar18[3] = DAT_00703f14;
          (&DAT_006fcfb0)[iVar16] = 1;
          if (DAT_006fd060 <= pfVar18[1]) {
            if (DAT_006d213c < pfVar18[1]) {
              (&DAT_006fcfb0)[iVar16] = 9;
            }
          }
          else {
            (&DAT_006fcfb0)[iVar16] = 5;
          }
          if (DAT_006fd05c <= *pfVar18) {
            if (DAT_006d2138 < *pfVar18) {
              bVar11 = (&DAT_006fcfb0)[iVar16] | 0x20;
              goto LAB_005ad081;
            }
          }
          else {
            bVar11 = (&DAT_006fcfb0)[iVar16] | 0x10;
LAB_005ad081:
            (&DAT_006fcfb0)[iVar16] = bVar11;
          }
          *(undefined **)(puVar10 + iVar16 * 4) = PTR_DAT_006d2128 + DAT_006d2134 * local_84;
          iVar16 = iVar16 + 1;
          local_84 = local_84 + 1;
        }
        local_8c = local_8c + -1;
        iVar14 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar16 < 3) {
        return 0xffffffff;
      }
      piVar23 = (int *)(puVar10 + iVar16 * 4);
      local_98 = &DAT_006fcfb0 + iVar16;
      local_80 = &DAT_006fcfb0;
      piVar17 = (int *)PTR_DAT_006d211c;
      local_8c = iVar16;
    }
    local_88 = piVar23;
    if ((param_3 & 2) != 0) {
      iVar16 = 0;
      local_94 = 0;
      iVar14 = local_8c + -1;
      do {
        if ((local_80[iVar14] & 2) == 0) {
          piVar23[iVar16] = piVar17[iVar14];
          local_98[iVar16] = local_80[iVar14];
          iVar16 = iVar16 + 1;
        }
        if (((local_80[local_94] ^ local_80[iVar14]) & 2) != 0) {
          pfVar7 = (float *)piVar17[iVar14];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)piVar17[local_94];
          fVar9 = (pfVar7[3] - DAT_00703f20) / (pfVar7[3] - pfVar8[3]);
          fVar1 = pfVar7[1];
          fVar2 = pfVar8[1];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar18 = *pfVar7 - (*pfVar7 - *pfVar8) * fVar9;
          pfVar18[1] = *(float *)(piVar17[iVar14] + 4) - (fVar1 - fVar2) * fVar9;
          pfVar18[6] = *(float *)(piVar17[iVar14] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar18[7] = *(float *)(piVar17[iVar14] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar17[iVar14] + 0x24);
            fVar2 = *(float *)(piVar17[local_94] + 0x24);
            fVar3 = *(float *)(piVar17[iVar14] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar17[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)(piVar17[iVar14] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          DAT_006f77bc = *(uint *)(piVar17[iVar14] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar17[iVar14] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar17[iVar14] + 0x12);
          uVar15 = (uint)*(byte *)(piVar17[iVar14] + 0x13);
          DAT_006f9730 = *(uint *)(piVar17[local_94] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar17[local_94] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar17[local_94] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar17[local_94] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          iVar14 = __ftol();
          DAT_006f77b8 = uVar15 - iVar14;
          iVar12 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar12;
          iVar12 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar12;
          iVar12 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar14) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar18[2] = 1.0;
          pfVar18[3] = DAT_00703f20;
          local_98[iVar16] = 1;
          if (DAT_006fd060 <= pfVar18[1]) {
            if (DAT_006d213c < pfVar18[1]) {
              local_98[iVar16] = 9;
            }
          }
          else {
            local_98[iVar16] = 5;
          }
          if (DAT_006fd05c <= *pfVar18) {
            if (DAT_006d2138 < *pfVar18) {
              bVar11 = local_98[iVar16] | 0x20;
              goto LAB_005ad422;
            }
          }
          else {
            bVar11 = local_98[iVar16] | 0x10;
LAB_005ad422:
            local_98[iVar16] = bVar11;
          }
          piVar23[iVar16] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          iVar16 = iVar16 + 1;
          local_84 = local_84 + 1;
        }
        local_8c = local_8c + -1;
        iVar14 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar16 < 3) {
        return 0xffffffff;
      }
      local_88 = piVar23 + iVar16;
      local_80 = local_98;
      piVar17 = piVar23;
      local_98 = local_98 + iVar16;
      local_8c = iVar16;
    }
    param_3 = local_80[iVar16 + -1];
    iVar16 = iVar16 + -1;
    do {
      iVar14 = iVar16 + -1;
      iVar16 = iVar16 + -1;
      param_3 = param_3 | local_80[iVar14];
    } while (0 < iVar16);
  }
  if ((param_3 & 0xc) != 0) {
    if ((param_3 & 8) != 0) {
      iVar16 = 0;
      local_94 = 0;
      iVar14 = local_8c + -1;
      do {
        if ((local_80[iVar14] & 8) == 0) {
          local_88[iVar16] = piVar17[iVar14];
          local_98[iVar16] = local_80[iVar14];
          iVar16 = iVar16 + 1;
        }
        if (((local_80[local_94] ^ local_80[iVar14]) & 8) != 0) {
          pfVar7 = (float *)piVar17[local_94];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)piVar17[iVar14];
          fVar9 = (pfVar8[1] - DAT_006d213c) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar18 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar9;
          pfVar18[3] = *(float *)(piVar17[iVar14] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar18[6] = *(float *)(piVar17[iVar14] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar18[7] = *(float *)(piVar17[iVar14] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar18[2] = *(float *)(piVar17[iVar14] + 8) -
                         (*(float *)(piVar17[iVar14] + 8) - *(float *)(piVar17[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar17[iVar14] + 0x24);
            fVar2 = *(float *)(piVar17[local_94] + 0x24);
            fVar3 = *(float *)(piVar17[iVar14] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar17[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)(piVar17[iVar14] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          DAT_006f77bc = *(uint *)(piVar17[iVar14] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar17[iVar14] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar17[iVar14] + 0x12);
          uVar15 = (uint)*(byte *)(piVar17[iVar14] + 0x13);
          DAT_006f9730 = *(uint *)(piVar17[local_94] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar17[local_94] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar17[local_94] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar17[local_94] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          iVar12 = __ftol();
          DAT_006f77b8 = uVar15 - iVar12;
          iVar13 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar13;
          iVar13 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar13;
          iVar13 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar13;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar12) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar18[1] = DAT_006d213c;
          bVar11 = local_80[iVar14] & 0xcb;
          local_98[iVar16] = bVar11 | 8;
          if (DAT_006fd05c <= *pfVar18) {
            if (DAT_006d2138 < *pfVar18) {
              bVar11 = bVar11 | 0x28;
              goto LAB_005ad7cc;
            }
          }
          else {
            bVar11 = bVar11 | 0x18;
LAB_005ad7cc:
            local_98[iVar16] = bVar11;
          }
          local_88[iVar16] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          iVar16 = iVar16 + 1;
          local_84 = local_84 + 1;
        }
        local_8c = local_8c + -1;
        iVar14 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar16 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar17 = local_88;
      local_98 = local_98 + iVar16;
      local_8c = iVar16;
      local_88 = local_88 + iVar16;
    }
    if ((param_3 & 4) != 0) {
      iVar16 = 0;
      local_94 = 0;
      iVar14 = local_8c + -1;
      do {
        if ((local_80[iVar14] & 4) == 0) {
          local_88[iVar16] = piVar17[iVar14];
          local_98[iVar16] = local_80[iVar14];
          iVar16 = iVar16 + 1;
        }
        if (((local_80[local_94] ^ local_80[iVar14]) & 4) != 0) {
          pfVar7 = (float *)piVar17[local_94];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)piVar17[iVar14];
          fVar9 = (pfVar8[1] - DAT_006fd060) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar18 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar9;
          pfVar18[3] = *(float *)(piVar17[iVar14] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar18[6] = *(float *)(piVar17[iVar14] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar18[7] = *(float *)(piVar17[iVar14] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar18[2] = *(float *)(piVar17[iVar14] + 8) -
                         (*(float *)(piVar17[iVar14] + 8) - *(float *)(piVar17[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar17[iVar14] + 0x24);
            fVar2 = *(float *)(piVar17[local_94] + 0x24);
            fVar3 = *(float *)(piVar17[iVar14] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar17[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)(piVar17[iVar14] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          DAT_006f77bc = *(uint *)(piVar17[iVar14] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar17[iVar14] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar17[iVar14] + 0x12);
          uVar15 = (uint)*(byte *)(piVar17[iVar14] + 0x13);
          DAT_006f9730 = *(uint *)(piVar17[local_94] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar17[local_94] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar17[local_94] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar17[local_94] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          iVar12 = __ftol();
          DAT_006f77b8 = uVar15 - iVar12;
          iVar13 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar13;
          iVar13 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar13;
          iVar13 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar13;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar12) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar18[1] = DAT_006fd060;
          bVar11 = local_80[iVar14] & 199;
          local_98[iVar16] = bVar11 | 4;
          if (DAT_006fd05c <= *pfVar18) {
            if (DAT_006d2138 < *pfVar18) {
              bVar11 = bVar11 | 0x24;
              goto LAB_005adb61;
            }
          }
          else {
            bVar11 = bVar11 | 0x14;
LAB_005adb61:
            local_98[iVar16] = bVar11;
          }
          local_88[iVar16] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          iVar16 = iVar16 + 1;
          local_84 = local_84 + 1;
        }
        local_8c = local_8c + -1;
        iVar14 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar16 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar17 = local_88;
      local_98 = local_98 + iVar16;
      local_8c = iVar16;
      local_88 = local_88 + iVar16;
    }
    param_3 = local_80[iVar16 + -1];
    iVar16 = iVar16 + -1;
    do {
      iVar14 = iVar16 + -1;
      iVar16 = iVar16 + -1;
      param_3 = param_3 | local_80[iVar14];
    } while (0 < iVar16);
  }
  if ((param_3 & 0x30) != 0) {
    if ((param_3 & 0x10) != 0) {
      iVar14 = 0;
      local_9c = 0;
      local_94 = 0;
      iVar16 = local_8c + -1;
      do {
        if ((local_80[iVar16] & 0x10) == 0) {
          local_88[iVar14] = piVar17[iVar16];
          local_98[iVar14] = local_80[iVar16];
          iVar14 = iVar14 + 1;
          local_9c = iVar14;
        }
        if (((local_80[local_94] ^ local_80[iVar16]) & 0x10) != 0) {
          pfVar7 = (float *)piVar17[local_94];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)piVar17[iVar16];
          fVar9 = (*pfVar8 - DAT_006fd05c) / (*pfVar8 - *pfVar7);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          pfVar18[1] = pfVar8[1] - (pfVar8[1] - pfVar7[1]) * fVar9;
          pfVar18[3] = *(float *)(piVar17[iVar16] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar18[6] = *(float *)(piVar17[iVar16] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar18[7] = *(float *)(piVar17[iVar16] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar18[2] = *(float *)(piVar17[iVar16] + 8) -
                         (*(float *)(piVar17[iVar16] + 8) - *(float *)(piVar17[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar17[iVar16] + 0x24);
            fVar2 = *(float *)(piVar17[local_94] + 0x24);
            fVar3 = *(float *)(piVar17[iVar16] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar17[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)(piVar17[iVar16] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar22 = *(uint *)(piVar17[iVar16] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar17[iVar16] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar17[iVar16] + 0x12);
          uVar15 = (uint)*(byte *)(piVar17[iVar16] + 0x13);
          DAT_006f9730 = *(uint *)(piVar17[local_94] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar17[local_94] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar17[local_94] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar17[local_94] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(uVar22 - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          DAT_006f77bc = uVar22;
          iVar14 = __ftol();
          DAT_006f77b8 = uVar15 - iVar14;
          iVar12 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar12;
          iVar12 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar12;
          iVar12 = __ftol();
          DAT_006f77bc = uVar22 - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar14) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          *pfVar18 = DAT_006fd05c;
          local_98[local_9c] = local_80[iVar16] & 0xdf | 0x10;
          local_88[local_9c] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          iVar14 = local_9c + 1;
          local_84 = local_84 + 1;
          local_9c = iVar14;
        }
        local_8c = local_8c + -1;
        iVar16 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar14 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar17 = local_88;
      local_98 = local_98 + iVar14;
      local_8c = iVar14;
      local_88 = local_88 + iVar14;
    }
    if ((param_3 & 0x20) != 0) {
      iVar14 = 0;
      local_9c = 0;
      local_94 = 0;
      iVar16 = local_8c + -1;
      do {
        if ((local_80[iVar16] & 0x20) == 0) {
          local_88[iVar14] = piVar17[iVar16];
          local_98[iVar14] = local_80[iVar16];
          iVar14 = iVar14 + 1;
          local_9c = iVar14;
        }
        if (((local_80[local_94] ^ local_80[iVar16]) & 0x20) != 0) {
          pfVar7 = (float *)piVar17[local_94];
          pfVar18 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          pfVar8 = (float *)piVar17[iVar16];
          fVar9 = (*pfVar8 - DAT_006d2138) / (*pfVar8 - *pfVar7);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          pfVar18[1] = pfVar8[1] - (pfVar8[1] - pfVar7[1]) * fVar9;
          pfVar18[3] = *(float *)(piVar17[iVar16] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar18[6] = *(float *)(piVar17[iVar16] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar18[7] = *(float *)(piVar17[iVar16] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar18[2] = *(float *)(piVar17[iVar16] + 8) -
                         (*(float *)(piVar17[iVar16] + 8) - *(float *)(piVar17[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar17[iVar16] + 0x24);
            fVar2 = *(float *)(piVar17[local_94] + 0x24);
            fVar3 = *(float *)(piVar17[iVar16] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar17[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x24) =
                 *(float *)(piVar17[iVar16] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          uVar22 = *(uint *)(piVar17[iVar16] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar17[iVar16] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar17[iVar16] + 0x12);
          uVar15 = (uint)*(byte *)(piVar17[iVar16] + 0x13);
          DAT_006f9730 = *(uint *)(piVar17[local_94] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar17[local_94] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar17[local_94] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar17[local_94] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar15 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(uVar22 - DAT_006f9730);
          DAT_006f77b8 = uVar15;
          DAT_006f77bc = uVar22;
          iVar14 = __ftol();
          DAT_006f77b8 = uVar15 - iVar14;
          iVar12 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar12;
          iVar12 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar12;
          iVar12 = __ftol();
          DAT_006f77bc = uVar22 - iVar12;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * local_84 + 0x10) =
               (((uVar15 - iVar14) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          *pfVar18 = DAT_006d2138;
          local_98[local_9c] = local_80[iVar16] & 0xef | 0x20;
          local_88[local_9c] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * local_84);
          iVar14 = local_9c + 1;
          local_84 = local_84 + 1;
          local_9c = iVar14;
        }
        local_8c = local_8c + -1;
        iVar16 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      piVar17 = local_88;
      local_8c = iVar14;
      if (iVar14 < 3) {
        return 0xffffffff;
      }
    }
  }
  iVar16 = 0;
  if (0 < local_8c) {
    do {
      iVar14 = piVar17[iVar16];
      fVar1 = _DAT_00672294 / *(float *)(iVar14 + 0xc);
      if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
        *(float *)(iVar14 + 0x18) = fVar1 * *(float *)(iVar14 + 0x18);
        *(float *)(piVar17[iVar16] + 0x1c) = fVar1 * *(float *)(piVar17[iVar16] + 0x1c);
      }
      if ((DAT_006d2124 & DAT_006fd06c) == 1) {
        *(float *)(piVar17[iVar16] + 8) = (fVar1 - _DAT_006fd064) * _DAT_006fd068;
      }
      if (DAT_006fd058 == 1) {
        *(float *)(piVar17[iVar16] + 0x20) = fVar1 * *(float *)(piVar17[iVar16] + 0x20);
        *(float *)(piVar17[iVar16] + 0x24) = fVar1 * *(float *)(piVar17[iVar16] + 0x24);
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < local_8c);
  }
  iVar14 = 0;
  iVar16 = (local_8c + -2) * 3;
  piVar23 = piVar17;
  if (0 < iVar16) {
    do {
      piVar21 = piVar23 + 1;
      if (DAT_006fd058 == 1) {
        local_78[iVar14] = (*piVar17 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar14 + 1] = (*piVar21 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar14 + 2] = (piVar23[2] - (int)PTR_DAT_006d2128) / 0x28;
      }
      else {
        local_78[iVar14] = *piVar17 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar14 + 1] = *piVar21 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar14 + 2] = piVar23[2] - (int)PTR_DAT_006d2128 >> 5;
      }
      iVar14 = iVar14 + 3;
      piVar23 = piVar21;
    } while (iVar14 < iVar16);
  }
  FUN_005b3260(local_8c + -2,PTR_DAT_006d2128,local_78);
  return 0;
}

