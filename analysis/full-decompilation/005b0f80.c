
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b0f80(undefined4 *param_1,undefined1 *param_2,byte param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  int *piVar9;
  float fVar10;
  undefined *puVar11;
  byte bVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int *piVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  int *piVar21;
  uint uVar22;
  uint uVar23;
  undefined1 *local_98;
  int local_90;
  int local_8c;
  int local_88;
  int *local_84;
  undefined1 *local_80;
  int local_78 [30];
  
  DAT_006fb374 = PTR_DAT_006d2128 + DAT_006d2134;
  iVar13 = 0;
  DAT_006fb378 = PTR_DAT_006d2128 + DAT_006d2134 * 2;
  DAT_006fb37c = PTR_DAT_006d2128 + DAT_006d2134 * 3;
  DAT_006fb370 = PTR_DAT_006d2128;
  local_80 = param_2;
  piVar18 = (int *)&DAT_006fb370;
  local_88 = param_4;
  if (DAT_006fd058 == 1) {
    puVar19 = (undefined4 *)*param_1;
    puVar20 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar17 = 10; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)param_1[1];
    puVar20 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar17 = 10; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar17 = 10;
  }
  else {
    puVar19 = (undefined4 *)*param_1;
    puVar20 = (undefined4 *)PTR_DAT_006d2128;
    for (iVar17 = 8; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)param_1[1];
    puVar20 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134);
    for (iVar17 = 8; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar20 = *puVar19;
      puVar19 = puVar19 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 2);
    iVar17 = 8;
  }
  puVar20 = (undefined4 *)param_1[2];
  for (; iVar17 != 0; iVar17 = iVar17 + -1) {
    *puVar19 = *puVar20;
    puVar20 = puVar20 + 1;
    puVar19 = puVar19 + 1;
  }
  if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
    *(float *)(DAT_006fb370 + 0x18) =
         *(float *)(DAT_006fb370 + 0xc) * *(float *)(DAT_006fb370 + 0x18);
    *(float *)(DAT_006fb370 + 0x1c) =
         *(float *)(DAT_006fb370 + 0xc) * *(float *)(DAT_006fb370 + 0x1c);
    *(float *)(DAT_006fb374 + 0x18) =
         *(float *)(DAT_006fb374 + 0xc) * *(float *)(DAT_006fb374 + 0x18);
    *(float *)(DAT_006fb374 + 0x1c) =
         *(float *)(DAT_006fb374 + 0xc) * *(float *)(DAT_006fb374 + 0x1c);
    *(float *)(DAT_006fb378 + 0x18) =
         *(float *)(DAT_006fb378 + 0xc) * *(float *)(DAT_006fb378 + 0x18);
    *(float *)(DAT_006fb378 + 0x1c) =
         *(float *)(DAT_006fb378 + 0xc) * *(float *)(DAT_006fb378 + 0x1c);
    if (DAT_006fd058 == 1) {
      *(float *)(DAT_006fb370 + 0x20) =
           *(float *)(DAT_006fb370 + 0xc) * *(float *)(DAT_006fb370 + 0x20);
      *(float *)(DAT_006fb370 + 0x24) =
           *(float *)(DAT_006fb370 + 0xc) * *(float *)(DAT_006fb370 + 0x24);
      *(float *)(DAT_006fb374 + 0x20) =
           *(float *)(DAT_006fb374 + 0xc) * *(float *)(DAT_006fb374 + 0x20);
      *(float *)(DAT_006fb374 + 0x24) =
           *(float *)(DAT_006fb374 + 0xc) * *(float *)(DAT_006fb374 + 0x24);
      *(float *)(DAT_006fb378 + 0x20) =
           *(float *)(DAT_006fb378 + 0xc) * *(float *)(DAT_006fb378 + 0x20);
      *(float *)(DAT_006fb378 + 0x24) =
           *(float *)(DAT_006fb378 + 0xc) * *(float *)(DAT_006fb378 + 0x24);
    }
  }
  if (param_4 == 4) {
    puVar20 = (undefined4 *)param_1[3];
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * 3);
    for (iVar17 = 8; iVar17 != 0; iVar17 = iVar17 + -1) {
      *puVar19 = *puVar20;
      puVar20 = puVar20 + 1;
      puVar19 = puVar19 + 1;
    }
    if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
      *(float *)(DAT_006fb37c + 0x18) =
           *(float *)(DAT_006fb37c + 0xc) * *(float *)(DAT_006fb37c + 0x18);
      *(float *)(DAT_006fb37c + 0x1c) =
           *(float *)(DAT_006fb37c + 0xc) * *(float *)(DAT_006fb37c + 0x1c);
      if (DAT_006fd058 == 1) {
        *(float *)(DAT_006fb37c + 0x20) =
             *(float *)(DAT_006fb37c + 0xc) * *(float *)(DAT_006fb37c + 0x20);
        *(float *)(DAT_006fb37c + 0x24) =
             *(float *)(DAT_006fb37c + 0xc) * *(float *)(DAT_006fb37c + 0x24);
      }
    }
  }
  puVar11 = PTR_DAT_006d211c;
  local_98 = &DAT_006fcfb0;
  local_84 = (int *)PTR_DAT_006d211c;
  if ((param_3 & 3) != 0) {
    if ((param_3 & 1) != 0) {
      iVar13 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar17 = param_4 + -1;
      do {
        if ((param_2[iVar17] & 1) == 0) {
          *(undefined **)(puVar11 + iVar13 * 4) = (&DAT_006fb370)[iVar17];
          (&DAT_006fcfb0)[iVar13] = param_2[iVar17];
          iVar13 = iVar13 + 1;
          local_8c = iVar13;
        }
        if (((param_2[local_90] ^ param_2[iVar17]) & 1) != 0) {
          pfVar7 = (float *)(&DAT_006fb370)[local_90];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)(&DAT_006fb370)[iVar17];
          local_98 = (undefined1 *)((pfVar8[3] - DAT_00703f14) / (pfVar8[3] - pfVar7[3]));
          fVar1 = pfVar8[1];
          fVar2 = pfVar7[1];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar14 = *pfVar8 - (*pfVar8 - *pfVar7) * (float)local_98;
          pfVar14[1] = *(float *)((int)(&DAT_006fb370)[iVar17] + 4) -
                       (fVar1 - fVar2) * (float)local_98;
          if ((DAT_006fd06c & DAT_006d2120) == 0x10000) {
            if (0x3f800000 < (int)local_98) {
              local_98 = (undefined1 *)0x3f800000;
            }
            if ((int)local_98 < 0) {
              local_98 = (undefined1 *)0x0;
            }
          }
          pfVar14[6] = *(float *)((int)(&DAT_006fb370)[iVar17] + 0x18) -
                       (fVar3 - fVar4) * (float)local_98;
          pfVar14[7] = *(float *)((int)(&DAT_006fb370)[iVar17] + 0x1c) -
                       (fVar5 - fVar6) * (float)local_98;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)((int)(&DAT_006fb370)[iVar17] + 0x24);
            fVar2 = *(float *)((int)(&DAT_006fb370)[local_90] + 0x24);
            fVar3 = *(float *)((int)(&DAT_006fb370)[iVar17] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)((int)(&DAT_006fb370)[local_90] + 0x20)) *
                         (float)local_98;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)((int)(&DAT_006fb370)[iVar17] + 0x24) - (fVar1 - fVar2) * (float)local_98
            ;
          }
          uVar22 = *(uint *)((int)(&DAT_006fb370)[iVar17] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x12);
          uVar16 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x13);
          iVar13 = (int)(&DAT_006fb370)[local_90];
          DAT_006f9730 = *(uint *)(iVar13 + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(iVar13 + 0x11);
          DAT_006f9748 = (uint)*(byte *)(iVar13 + 0x12);
          _DAT_006f972c = (uint)*(byte *)(iVar13 + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(uVar22 - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          DAT_006f77bc = uVar22;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               uVar22 - iVar15;
          uVar23 = *(uint *)((int)(&DAT_006fb370)[iVar17] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x16);
          uVar16 = (uint)*(byte *)((int)(&DAT_006fb370)[iVar17] + 0x17);
          iVar13 = (int)(&DAT_006fb370)[local_90];
          DAT_006f9730 = *(uint *)(iVar13 + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(iVar13 + 0x15);
          DAT_006f9748 = (uint)*(byte *)(iVar13 + 0x16);
          _DAT_006f972c = (uint)*(byte *)(iVar13 + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(uVar23 - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          DAT_006f77bc = uVar23;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar17 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar17;
          iVar17 = __ftol();
          uVar22 = DAT_006f77c0 - iVar17;
          DAT_006f77c0 = uVar22;
          iVar17 = __ftol();
          DAT_006f77bc = uVar23 - iVar17;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | uVar22) << 8 | DAT_006f77bc;
          pfVar14[2] = 0.0;
          pfVar14[3] = DAT_00703f14;
          (&DAT_006fcfb0)[local_8c] = 1;
          if (DAT_006fd060 <= pfVar14[1]) {
            if (DAT_006d213c < pfVar14[1]) {
              (&DAT_006fcfb0)[local_8c] = 9;
            }
          }
          else {
            (&DAT_006fcfb0)[local_8c] = 5;
          }
          if (DAT_006fd05c <= *pfVar14) {
            if (DAT_006d2138 < *pfVar14) {
              bVar12 = (&DAT_006fcfb0)[local_8c] | 0x20;
              goto LAB_005b16f5;
            }
          }
          else {
            bVar12 = (&DAT_006fcfb0)[local_8c] | 0x10;
LAB_005b16f5:
            (&DAT_006fcfb0)[local_8c] = bVar12;
          }
          *(undefined **)(puVar11 + local_8c * 4) = PTR_DAT_006d2128 + DAT_006d2134 * param_4;
          iVar13 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar13;
        }
        local_88 = local_88 + -1;
        iVar17 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      if (iVar13 < 3) {
        return 0xffffffff;
      }
      local_84 = (int *)(puVar11 + iVar13 * 4);
      local_80 = &DAT_006fcfb0;
      local_98 = &DAT_006fcfb0 + iVar13;
      piVar18 = (int *)PTR_DAT_006d211c;
      local_88 = iVar13;
    }
    if ((param_3 & 2) != 0) {
      iVar13 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar17 = local_88 + -1;
      do {
        if ((local_80[iVar17] & 2) == 0) {
          local_84[iVar13] = piVar18[iVar17];
          local_98[iVar13] = local_80[iVar17];
          iVar13 = iVar13 + 1;
          local_8c = iVar13;
        }
        if (((local_80[local_90] ^ local_80[iVar17]) & 2) != 0) {
          pfVar7 = (float *)piVar18[local_90];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar18[iVar17];
          fVar10 = (pfVar8[3] - DAT_00703f20) / (pfVar8[3] - pfVar7[3]);
          fVar1 = pfVar8[1];
          fVar2 = pfVar7[1];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar14 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar10;
          pfVar14[1] = *(float *)(piVar18[iVar17] + 4) - (fVar1 - fVar2) * fVar10;
          pfVar14[6] = *(float *)(piVar18[iVar17] + 0x18) - (fVar3 - fVar4) * fVar10;
          pfVar14[7] = *(float *)(piVar18[iVar17] + 0x1c) - (fVar5 - fVar6) * fVar10;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar18[iVar17] + 0x24);
            fVar2 = *(float *)(piVar18[local_90] + 0x24);
            fVar3 = *(float *)(piVar18[iVar17] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar18[local_90] + 0x20)) * fVar10;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar18[iVar17] + 0x24) - (fVar1 - fVar2) * fVar10;
          }
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x12);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x13);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               DAT_006f77bc - iVar15;
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x16);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x17);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x15);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x16);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar17 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar17;
          iVar17 = __ftol();
          uVar22 = DAT_006f77c0 - iVar17;
          DAT_006f77c0 = uVar22;
          iVar17 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar17;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | uVar22) << 8 | DAT_006f77bc;
          pfVar14[2] = 1.0;
          pfVar14[3] = DAT_00703f20;
          local_98[local_8c] = 1;
          if (DAT_006fd060 <= pfVar14[1]) {
            if (DAT_006d213c < pfVar14[1]) {
              local_98[local_8c] = 9;
            }
          }
          else {
            local_98[local_8c] = 5;
          }
          if (DAT_006fd05c <= *pfVar14) {
            if (DAT_006d2138 < *pfVar14) {
              bVar12 = local_98[local_8c] | 0x20;
              goto LAB_005b1c1b;
            }
          }
          else {
            bVar12 = local_98[local_8c] | 0x10;
LAB_005b1c1b:
            local_98[local_8c] = bVar12;
          }
          local_84[local_8c] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar13 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar13;
        }
        local_88 = local_88 + -1;
        iVar17 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      if (iVar13 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar18 = local_84;
      local_98 = local_98 + iVar13;
      local_88 = iVar13;
      local_84 = local_84 + iVar13;
    }
    param_3 = local_80[iVar13 + -1];
    iVar13 = iVar13 + -1;
    do {
      param_3 = param_3 | local_80[iVar13 + -1];
      iVar13 = iVar13 + -1;
    } while (0 < iVar13);
  }
  if ((param_3 & 0xc) != 0) {
    if ((param_3 & 8) != 0) {
      iVar13 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar17 = local_88 + -1;
      do {
        if ((local_80[iVar17] & 8) == 0) {
          local_84[iVar13] = piVar18[iVar17];
          local_98[iVar13] = local_80[iVar17];
          iVar13 = iVar13 + 1;
          local_8c = iVar13;
        }
        if (((local_80[local_90] ^ local_80[iVar17]) & 8) != 0) {
          pfVar7 = (float *)piVar18[local_90];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar18[iVar17];
          fVar10 = (pfVar8[1] - DAT_006d213c) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar14 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar10;
          pfVar14[3] = *(float *)(piVar18[iVar17] + 0xc) - (fVar1 - fVar2) * fVar10;
          pfVar14[6] = *(float *)(piVar18[iVar17] + 0x18) - (fVar3 - fVar4) * fVar10;
          pfVar14[7] = *(float *)(piVar18[iVar17] + 0x1c) - (fVar5 - fVar6) * fVar10;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar14[2] = *(float *)(piVar18[iVar17] + 8) -
                         (*(float *)(piVar18[iVar17] + 8) - *(float *)(piVar18[local_90] + 8)) *
                         fVar10;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar18[iVar17] + 0x24);
            fVar2 = *(float *)(piVar18[local_90] + 0x24);
            fVar3 = *(float *)(piVar18[iVar17] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar18[local_90] + 0x20)) * fVar10;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar18[iVar17] + 0x24) - (fVar1 - fVar2) * fVar10;
          }
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x12);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x13);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               DAT_006f77bc - iVar15;
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x16);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x17);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x15);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x16);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar15;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar14[1] = DAT_006d213c;
          bVar12 = local_80[iVar17] & 0xcb;
          local_98[local_8c] = bVar12 | 8;
          if (DAT_006fd05c <= *pfVar14) {
            if (DAT_006d2138 < *pfVar14) {
              bVar12 = bVar12 | 0x28;
              goto LAB_005b2149;
            }
          }
          else {
            bVar12 = bVar12 | 0x18;
LAB_005b2149:
            local_98[local_8c] = bVar12;
          }
          local_84[local_8c] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar13 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar13;
        }
        local_88 = local_88 + -1;
        iVar17 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      if (iVar13 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar18 = local_84;
      local_98 = local_98 + iVar13;
      local_88 = iVar13;
      local_84 = local_84 + iVar13;
    }
    if ((param_3 & 4) != 0) {
      iVar13 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar17 = local_88 + -1;
      do {
        if ((local_80[iVar17] & 4) == 0) {
          local_84[iVar13] = piVar18[iVar17];
          local_98[iVar13] = local_80[iVar17];
          iVar13 = iVar13 + 1;
          local_8c = iVar13;
        }
        if (((local_80[local_90] ^ local_80[iVar17]) & 4) != 0) {
          pfVar7 = (float *)piVar18[local_90];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar18[iVar17];
          fVar10 = (pfVar8[1] - DAT_006fd060) / (pfVar8[1] - pfVar7[1]);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar14 = *pfVar8 - (*pfVar8 - *pfVar7) * fVar10;
          pfVar14[3] = *(float *)(piVar18[iVar17] + 0xc) - (fVar1 - fVar2) * fVar10;
          pfVar14[6] = *(float *)(piVar18[iVar17] + 0x18) - (fVar3 - fVar4) * fVar10;
          pfVar14[7] = *(float *)(piVar18[iVar17] + 0x1c) - (fVar5 - fVar6) * fVar10;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar14[2] = *(float *)(piVar18[iVar17] + 8) -
                         (*(float *)(piVar18[iVar17] + 8) - *(float *)(piVar18[local_90] + 8)) *
                         fVar10;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar18[iVar17] + 0x24);
            fVar2 = *(float *)(piVar18[local_90] + 0x24);
            fVar3 = *(float *)(piVar18[iVar17] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar18[local_90] + 0x20)) * fVar10;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar18[iVar17] + 0x24) - (fVar1 - fVar2) * fVar10;
          }
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x12);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x13);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               DAT_006f77bc - iVar15;
          DAT_006f77bc = *(uint *)(piVar18[iVar17] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar17] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar17] + 0x16);
          uVar16 = (uint)*(byte *)(piVar18[iVar17] + 0x17);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x15);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x16);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar13 = __ftol();
          DAT_006f77b8 = uVar16 - iVar13;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar15;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar13) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          pfVar14[1] = DAT_006fd060;
          bVar12 = local_80[iVar17] & 199;
          local_98[local_8c] = bVar12 | 4;
          if (DAT_006fd05c <= *pfVar14) {
            if (DAT_006d2138 < *pfVar14) {
              bVar12 = bVar12 | 0x24;
              goto LAB_005b265d;
            }
          }
          else {
            bVar12 = bVar12 | 0x14;
LAB_005b265d:
            local_98[local_8c] = bVar12;
          }
          local_84[local_8c] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar13 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar13;
        }
        local_88 = local_88 + -1;
        iVar17 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      if (iVar13 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar18 = local_84;
      local_98 = local_98 + iVar13;
      local_88 = iVar13;
      local_84 = local_84 + iVar13;
    }
    param_3 = local_80[iVar13 + -1];
    iVar13 = iVar13 + -1;
    do {
      param_3 = param_3 | local_80[iVar13 + -1];
      iVar13 = iVar13 + -1;
    } while (0 < iVar13);
  }
  if ((param_3 & 0x30) != 0) {
    if ((param_3 & 0x10) != 0) {
      iVar17 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_80[iVar13] & 0x10) == 0) {
          local_84[iVar17] = piVar18[iVar13];
          local_98[iVar17] = local_80[iVar13];
          iVar17 = iVar17 + 1;
          local_8c = iVar17;
        }
        if (((local_80[local_90] ^ local_80[iVar13]) & 0x10) != 0) {
          pfVar7 = (float *)piVar18[iVar13];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar18[local_90];
          fVar10 = (*pfVar7 - DAT_006fd05c) / (*pfVar7 - *pfVar8);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          pfVar14[1] = pfVar7[1] - (pfVar7[1] - pfVar8[1]) * fVar10;
          pfVar14[3] = *(float *)(piVar18[iVar13] + 0xc) - (fVar1 - fVar2) * fVar10;
          pfVar14[6] = *(float *)(piVar18[iVar13] + 0x18) - (fVar3 - fVar4) * fVar10;
          pfVar14[7] = *(float *)(piVar18[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar10;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar14[2] = *(float *)(piVar18[iVar13] + 8) -
                         (*(float *)(piVar18[iVar13] + 8) - *(float *)(piVar18[local_90] + 8)) *
                         fVar10;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar18[iVar13] + 0x24);
            fVar2 = *(float *)(piVar18[local_90] + 0x24);
            fVar3 = *(float *)(piVar18[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar18[local_90] + 0x20)) * fVar10;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar18[iVar13] + 0x24) - (fVar1 - fVar2) * fVar10;
          }
          DAT_006f77bc = *(uint *)(piVar18[iVar13] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar13] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar13] + 0x12);
          uVar16 = (uint)*(byte *)(piVar18[iVar13] + 0x13);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar17 = __ftol();
          DAT_006f77b8 = uVar16 - iVar17;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar17) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               DAT_006f77bc - iVar15;
          DAT_006f77bc = *(uint *)(piVar18[iVar13] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar13] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar13] + 0x16);
          uVar16 = (uint)*(byte *)(piVar18[iVar13] + 0x17);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x15);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x16);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar17 = __ftol();
          DAT_006f77b8 = uVar16 - iVar17;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar15;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar17) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          *pfVar14 = DAT_006fd05c;
          puVar11 = PTR_DAT_006d2128;
          local_98[local_8c] = local_80[iVar13] & 0xdf | 0x10;
          local_84[local_8c] = (int)(puVar11 + DAT_006d2134 * param_4);
          iVar17 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar17;
        }
        local_88 = local_88 + -1;
        iVar13 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      if (iVar17 < 3) {
        return 0xffffffff;
      }
      local_80 = local_98;
      piVar18 = local_84;
      local_98 = local_98 + iVar17;
      local_88 = iVar17;
      local_84 = local_84 + iVar17;
    }
    if ((param_3 & 0x20) != 0) {
      iVar17 = 0;
      local_8c = 0;
      local_90 = 0;
      iVar13 = local_88 + -1;
      do {
        if ((local_80[iVar13] & 0x20) == 0) {
          local_84[iVar17] = piVar18[iVar13];
          local_98[iVar17] = local_80[iVar13];
          iVar17 = iVar17 + 1;
          local_8c = iVar17;
        }
        if (((local_80[local_90] ^ local_80[iVar13]) & 0x20) != 0) {
          pfVar7 = (float *)piVar18[local_90];
          pfVar14 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar18[iVar13];
          fVar10 = (*pfVar8 - DAT_006d2138) / (*pfVar8 - *pfVar7);
          fVar1 = pfVar8[3];
          fVar2 = pfVar7[3];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          pfVar14[1] = pfVar8[1] - (pfVar8[1] - pfVar7[1]) * fVar10;
          pfVar14[3] = *(float *)(piVar18[iVar13] + 0xc) - (fVar1 - fVar2) * fVar10;
          pfVar14[6] = *(float *)(piVar18[iVar13] + 0x18) - (fVar3 - fVar4) * fVar10;
          pfVar14[7] = *(float *)(piVar18[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar10;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar14[2] = *(float *)(piVar18[iVar13] + 8) -
                         (*(float *)(piVar18[iVar13] + 8) - *(float *)(piVar18[local_90] + 8)) *
                         fVar10;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar18[iVar13] + 0x24);
            fVar2 = *(float *)(piVar18[local_90] + 0x24);
            fVar3 = *(float *)(piVar18[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar18[local_90] + 0x20)) * fVar10;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar18[iVar13] + 0x24) - (fVar1 - fVar2) * fVar10;
          }
          DAT_006f77bc = *(uint *)(piVar18[iVar13] + 0x10) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar13] + 0x11);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar13] + 0x12);
          uVar16 = (uint)*(byte *)(piVar18[iVar13] + 0x13);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x10) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x11);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x12);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x13);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar17 = __ftol();
          DAT_006f77b8 = uVar16 - iVar17;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               (((uVar16 - iVar17) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 |
               DAT_006f77bc - iVar15;
          DAT_006f77bc = *(uint *)(piVar18[iVar13] + 0x14) & 0xff;
          DAT_006f77c0 = (uint)*(byte *)(piVar18[iVar13] + 0x15);
          DAT_006f77c4 = (uint)*(byte *)(piVar18[iVar13] + 0x16);
          uVar16 = (uint)*(byte *)(piVar18[iVar13] + 0x17);
          DAT_006f9730 = *(uint *)(piVar18[local_90] + 0x14) & 0xff;
          DAT_006f9734 = (uint)*(byte *)(piVar18[local_90] + 0x15);
          DAT_006f9748 = (uint)*(byte *)(piVar18[local_90] + 0x16);
          _DAT_006f972c = (uint)*(byte *)(piVar18[local_90] + 0x17);
          _DAT_006f77c8 = (float)(int)(uVar16 - _DAT_006f972c);
          _DAT_006f9728 = (float)(int)(DAT_006f77c4 - DAT_006f9748);
          _DAT_006f77d0 = (float)(int)(DAT_006f77c0 - DAT_006f9734);
          _DAT_006f77cc = (float)(int)(DAT_006f77bc - DAT_006f9730);
          DAT_006f77b8 = uVar16;
          iVar17 = __ftol();
          DAT_006f77b8 = uVar16 - iVar17;
          iVar15 = __ftol();
          DAT_006f77c4 = DAT_006f77c4 - iVar15;
          iVar15 = __ftol();
          DAT_006f77c0 = DAT_006f77c0 - iVar15;
          iVar15 = __ftol();
          DAT_006f77bc = DAT_006f77bc - iVar15;
          *(uint *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x14) =
               (((uVar16 - iVar17) * 0x100 | DAT_006f77c4) << 8 | DAT_006f77c0) << 8 | DAT_006f77bc;
          *pfVar14 = DAT_006d2138;
          puVar11 = PTR_DAT_006d2128;
          local_98[local_8c] = local_80[iVar13] & 0xef | 0x20;
          local_84[local_8c] = (int)(puVar11 + DAT_006d2134 * param_4);
          iVar17 = local_8c + 1;
          param_4 = param_4 + 1;
          local_8c = iVar17;
        }
        local_88 = local_88 + -1;
        iVar13 = local_90;
        local_90 = local_90 + 1;
      } while (0 < local_88);
      piVar18 = local_84;
      local_88 = iVar17;
      if (iVar17 < 3) {
        return 0xffffffff;
      }
    }
  }
  iVar13 = 0;
  if (0 < local_88) {
    do {
      iVar17 = piVar18[iVar13];
      fVar1 = _DAT_00672294 / *(float *)(iVar17 + 0xc);
      if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
        *(float *)(iVar17 + 0x18) = fVar1 * *(float *)(iVar17 + 0x18);
        *(float *)(piVar18[iVar13] + 0x1c) = fVar1 * *(float *)(piVar18[iVar13] + 0x1c);
      }
      if ((DAT_006d2124 & DAT_006fd06c) == 1) {
        *(float *)(piVar18[iVar13] + 8) = (fVar1 - _DAT_006fd064) * _DAT_006fd068;
      }
      if (DAT_006fd058 == 1) {
        *(float *)(piVar18[iVar13] + 0x20) = fVar1 * *(float *)(piVar18[iVar13] + 0x20);
        *(float *)(piVar18[iVar13] + 0x24) = fVar1 * *(float *)(piVar18[iVar13] + 0x24);
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < local_88);
  }
  iVar17 = 0;
  iVar13 = (local_88 + -2) * 3;
  piVar9 = piVar18;
  if (0 < iVar13) {
    do {
      piVar21 = piVar9 + 1;
      if (DAT_006fd058 == 1) {
        local_78[iVar17] = (*piVar18 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar17 + 1] = (*piVar21 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar17 + 2] = (piVar9[2] - (int)PTR_DAT_006d2128) / 0x28;
      }
      else {
        local_78[iVar17] = *piVar18 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar17 + 1] = *piVar21 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar17 + 2] = piVar9[2] - (int)PTR_DAT_006d2128 >> 5;
      }
      iVar17 = iVar17 + 3;
      piVar9 = piVar21;
    } while (iVar17 < iVar13);
  }
  FUN_005b3260(local_88 + -2,PTR_DAT_006d2128,local_78);
  return 0;
}

