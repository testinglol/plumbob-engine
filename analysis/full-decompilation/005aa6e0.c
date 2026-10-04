
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005aa6e0(undefined4 *param_1,undefined1 *param_2,byte param_3,int param_4)

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
  undefined1 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  float *pfVar19;
  int *piVar20;
  int *piVar21;
  int local_94;
  int *local_90;
  int local_8c;
  undefined1 *local_88;
  undefined1 *local_84;
  int local_80;
  int local_78 [30];
  
  DAT_006f971c = PTR_DAT_006d2128 + DAT_006d2134;
  iVar15 = 0;
  DAT_006f9720 = PTR_DAT_006d2128 + DAT_006d2134 * 2;
  DAT_006f9724 = PTR_DAT_006d2128 + DAT_006d2134 * 3;
  DAT_006f9718 = PTR_DAT_006d2128;
  local_88 = param_2;
  piVar16 = (int *)&DAT_006f9718;
  local_8c = param_4;
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
    *(float *)(DAT_006f9718 + 0x18) =
         *(float *)(DAT_006f9718 + 0xc) * *(float *)(DAT_006f9718 + 0x18);
    *(float *)(DAT_006f9718 + 0x1c) =
         *(float *)(DAT_006f9718 + 0xc) * *(float *)(DAT_006f9718 + 0x1c);
    *(float *)(DAT_006f971c + 0x18) =
         *(float *)(DAT_006f971c + 0xc) * *(float *)(DAT_006f971c + 0x18);
    *(float *)(DAT_006f971c + 0x1c) =
         *(float *)(DAT_006f971c + 0xc) * *(float *)(DAT_006f971c + 0x1c);
    *(float *)(DAT_006f9720 + 0x18) =
         *(float *)(DAT_006f9720 + 0xc) * *(float *)(DAT_006f9720 + 0x18);
    *(float *)(DAT_006f9720 + 0x1c) =
         *(float *)(DAT_006f9720 + 0xc) * *(float *)(DAT_006f9720 + 0x1c);
    if (DAT_006fd058 == 1) {
      *(float *)(DAT_006f9718 + 0x20) =
           *(float *)(DAT_006f9718 + 0xc) * *(float *)(DAT_006f9718 + 0x20);
      *(float *)(DAT_006f9718 + 0x24) =
           *(float *)(DAT_006f9718 + 0xc) * *(float *)(DAT_006f9718 + 0x24);
      *(float *)(DAT_006f971c + 0x20) =
           *(float *)(DAT_006f971c + 0xc) * *(float *)(DAT_006f971c + 0x20);
      *(float *)(DAT_006f971c + 0x24) =
           *(float *)(DAT_006f971c + 0xc) * *(float *)(DAT_006f971c + 0x24);
      *(float *)(DAT_006f9720 + 0x20) =
           *(float *)(DAT_006f9720 + 0xc) * *(float *)(DAT_006f9720 + 0x20);
      *(float *)(DAT_006f9720 + 0x24) =
           *(float *)(DAT_006f9720 + 0xc) * *(float *)(DAT_006f9720 + 0x24);
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
      *(float *)(DAT_006f9724 + 0x18) =
           *(float *)(DAT_006f9724 + 0xc) * *(float *)(DAT_006f9724 + 0x18);
      *(float *)(DAT_006f9724 + 0x1c) =
           *(float *)(DAT_006f9724 + 0xc) * *(float *)(DAT_006f9724 + 0x1c);
      if (DAT_006fd058 == 1) {
        *(float *)(DAT_006f9724 + 0x20) =
             *(float *)(DAT_006f9724 + 0xc) * *(float *)(DAT_006f9724 + 0x20);
        *(float *)(DAT_006f9724 + 0x24) =
             *(float *)(DAT_006f9724 + 0xc) * *(float *)(DAT_006f9724 + 0x24);
      }
    }
  }
  puVar10 = PTR_DAT_006d211c;
  local_90 = (int *)PTR_DAT_006d211c;
  local_84 = &DAT_006fcfb0;
  if ((param_3 & 3) != 0) {
    piVar21 = (int *)PTR_DAT_006d211c;
    if ((param_3 & 1) != 0) {
      iVar15 = 0;
      local_94 = 0;
      iVar13 = param_4 + -1;
      do {
        if ((param_2[iVar13] & 1) == 0) {
          *(undefined **)(puVar10 + iVar15 * 4) = (&DAT_006f9718)[iVar13];
          (&DAT_006fcfb0)[iVar15] = param_2[iVar13];
          iVar15 = iVar15 + 1;
        }
        if (((param_2[local_94] ^ param_2[iVar13]) & 1) != 0) {
          pfVar7 = (float *)(&DAT_006f9718)[local_94];
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)(&DAT_006f9718)[iVar13];
          local_90 = (int *)((pfVar8[3] - DAT_00703f14) / (pfVar8[3] - pfVar7[3]));
          fVar1 = pfVar8[1];
          fVar2 = pfVar7[1];
          fVar3 = pfVar8[6];
          fVar4 = pfVar7[6];
          fVar5 = pfVar8[7];
          fVar6 = pfVar7[7];
          *pfVar19 = *pfVar8 - (*pfVar8 - *pfVar7) * (float)local_90;
          pfVar19[1] = *(float *)((int)(&DAT_006f9718)[iVar13] + 4) -
                       (fVar1 - fVar2) * (float)local_90;
          if ((DAT_006fd06c & DAT_006d2120) == 0x10000) {
            if (0x3f800000 < (int)local_90) {
              local_90 = (int *)0x3f800000;
            }
            if ((int)local_90 < 0) {
              local_90 = (int *)0x0;
            }
          }
          pfVar19[6] = *(float *)((int)(&DAT_006f9718)[iVar13] + 0x18) -
                       (fVar3 - fVar4) * (float)local_90;
          pfVar19[7] = *(float *)((int)(&DAT_006f9718)[iVar13] + 0x1c) -
                       (fVar5 - fVar6) * (float)local_90;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)((int)(&DAT_006f9718)[iVar13] + 0x24);
            fVar2 = *(float *)((int)(&DAT_006f9718)[local_94] + 0x24);
            fVar3 = *(float *)((int)(&DAT_006f9718)[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)((int)(&DAT_006f9718)[local_94] + 0x20)) *
                         (float)local_90;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)((int)(&DAT_006f9718)[iVar13] + 0x24) - (fVar1 - fVar2) * (float)local_90
            ;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)((int)(&DAT_006f9718)[iVar13] + 0x10);
          pfVar19[2] = 0.0;
          pfVar19[3] = DAT_00703f14;
          (&DAT_006fcfb0)[iVar15] = 1;
          if (DAT_006fd060 <= pfVar19[1]) {
            if (DAT_006d213c < pfVar19[1]) {
              (&DAT_006fcfb0)[iVar15] = 9;
            }
          }
          else {
            (&DAT_006fcfb0)[iVar15] = 5;
          }
          if (DAT_006fd05c <= *pfVar19) {
            if (DAT_006d2138 < *pfVar19) {
              bVar11 = (&DAT_006fcfb0)[iVar15] | 0x20;
              goto LAB_005aab5f;
            }
          }
          else {
            bVar11 = (&DAT_006fcfb0)[iVar15] | 0x10;
LAB_005aab5f:
            (&DAT_006fcfb0)[iVar15] = bVar11;
          }
          *(undefined **)(puVar10 + iVar15 * 4) = PTR_DAT_006d2128 + DAT_006d2134 * param_4;
          iVar15 = iVar15 + 1;
          param_4 = param_4 + 1;
        }
        local_8c = local_8c + -1;
        iVar13 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar15 < 3) {
        return 0xffffffff;
      }
      local_84 = &DAT_006fcfb0 + iVar15;
      piVar21 = (int *)(puVar10 + iVar15 * 4);
      local_88 = &DAT_006fcfb0;
      piVar16 = (int *)PTR_DAT_006d211c;
      local_8c = iVar15;
    }
    local_90 = piVar21;
    if ((param_3 & 2) != 0) {
      iVar15 = 0;
      local_94 = 0;
      local_80 = local_8c + -1;
      do {
        if ((local_88[local_80] & 2) == 0) {
          piVar21[iVar15] = piVar16[local_80];
          local_84[iVar15] = local_88[local_80];
          iVar15 = iVar15 + 1;
        }
        if (((local_88[local_94] ^ local_88[local_80]) & 2) != 0) {
          pfVar7 = (float *)piVar16[local_80];
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar8 = (float *)piVar16[local_94];
          fVar9 = (pfVar7[3] - DAT_00703f20) / (pfVar7[3] - pfVar8[3]);
          fVar1 = pfVar7[1];
          fVar2 = pfVar8[1];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar19 = *pfVar7 - (*pfVar7 - *pfVar8) * fVar9;
          pfVar19[1] = *(float *)(piVar16[local_80] + 4) - (fVar1 - fVar2) * fVar9;
          pfVar19[6] = *(float *)(piVar16[local_80] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar19[7] = *(float *)(piVar16[local_80] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar16[local_80] + 0x24);
            fVar2 = *(float *)(piVar16[local_94] + 0x24);
            fVar3 = *(float *)(piVar16[local_80] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar16[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar16[local_80] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)(piVar16[local_80] + 0x10);
          pfVar19[2] = 1.0;
          pfVar19[3] = DAT_00703f20;
          local_84[iVar15] = 1;
          if (DAT_006fd060 <= pfVar19[1]) {
            if (DAT_006d213c < pfVar19[1]) {
              local_84[iVar15] = 9;
            }
          }
          else {
            local_84[iVar15] = 5;
          }
          if (DAT_006fd05c <= *pfVar19) {
            if (DAT_006d2138 < *pfVar19) {
              bVar11 = local_84[iVar15] | 0x20;
              goto LAB_005aad83;
            }
          }
          else {
            bVar11 = local_84[iVar15] | 0x10;
LAB_005aad83:
            local_84[iVar15] = bVar11;
          }
          piVar21[iVar15] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar15 = iVar15 + 1;
          param_4 = param_4 + 1;
        }
        local_8c = local_8c + -1;
        local_80 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar15 < 3) {
        return 0xffffffff;
      }
      local_90 = piVar21 + iVar15;
      local_88 = local_84;
      piVar16 = piVar21;
      local_8c = iVar15;
      local_84 = local_84 + iVar15;
    }
    param_3 = local_88[iVar15 + -1];
    iVar15 = iVar15 + -1;
    do {
      param_3 = param_3 | local_88[iVar15 + -1];
      iVar15 = iVar15 + -1;
    } while (0 < iVar15);
  }
  puVar12 = local_88;
  if ((param_3 & 0xc) != 0) {
    if ((param_3 & 8) != 0) {
      iVar15 = 0;
      local_94 = 0;
      iVar13 = local_8c + -1;
      do {
        if ((local_88[iVar13] & 8) == 0) {
          local_90[iVar15] = piVar16[iVar13];
          local_84[iVar15] = local_88[iVar13];
          iVar15 = iVar15 + 1;
        }
        if (((local_88[local_94] ^ local_88[iVar13]) & 8) != 0) {
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar7 = (float *)piVar16[iVar13];
          pfVar8 = (float *)piVar16[local_94];
          fVar9 = (pfVar7[1] - DAT_006d213c) / (pfVar7[1] - pfVar8[1]);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar19 = *pfVar7 - (*pfVar7 - *pfVar8) * fVar9;
          pfVar19[3] = *(float *)(piVar16[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar19[6] = *(float *)(piVar16[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar19[7] = *(float *)(piVar16[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar19[2] = *(float *)(piVar16[iVar13] + 8) -
                         (*(float *)(piVar16[iVar13] + 8) - *(float *)(piVar16[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar16[iVar13] + 0x24);
            fVar2 = *(float *)(piVar16[local_94] + 0x24);
            fVar3 = *(float *)(piVar16[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar16[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar16[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)(piVar16[iVar13] + 0x10);
          pfVar19[1] = DAT_006d213c;
          bVar11 = local_88[iVar13] & 0xcb;
          local_84[iVar15] = bVar11 | 8;
          if (DAT_006fd05c <= *pfVar19) {
            if (DAT_006d2138 < *pfVar19) {
              bVar11 = bVar11 | 0x28;
              goto LAB_005aafbc;
            }
          }
          else {
            bVar11 = bVar11 | 0x18;
LAB_005aafbc:
            local_84[iVar15] = bVar11;
          }
          local_90[iVar15] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar15 = iVar15 + 1;
          param_4 = param_4 + 1;
        }
        local_8c = local_8c + -1;
        iVar13 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar15 < 3) {
        return 0xffffffff;
      }
      local_88 = local_84;
      piVar16 = local_90;
      local_90 = local_90 + iVar15;
      local_8c = iVar15;
      local_84 = local_84 + iVar15;
    }
    if ((param_3 & 4) != 0) {
      iVar15 = 0;
      local_94 = 0;
      iVar13 = local_8c + -1;
      do {
        if ((local_88[iVar13] & 4) == 0) {
          local_90[iVar15] = piVar16[iVar13];
          local_84[iVar15] = local_88[iVar13];
          iVar15 = iVar15 + 1;
        }
        if (((local_88[local_94] ^ local_88[iVar13]) & 4) != 0) {
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar7 = (float *)piVar16[iVar13];
          pfVar8 = (float *)piVar16[local_94];
          fVar9 = (pfVar7[1] - DAT_006fd060) / (pfVar7[1] - pfVar8[1]);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          *pfVar19 = *pfVar7 - (*pfVar7 - *pfVar8) * fVar9;
          pfVar19[3] = *(float *)(piVar16[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar19[6] = *(float *)(piVar16[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar19[7] = *(float *)(piVar16[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar19[2] = *(float *)(piVar16[iVar13] + 8) -
                         (*(float *)(piVar16[iVar13] + 8) - *(float *)(piVar16[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar16[iVar13] + 0x24);
            fVar2 = *(float *)(piVar16[local_94] + 0x24);
            fVar3 = *(float *)(piVar16[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar16[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar16[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)(piVar16[iVar13] + 0x10);
          pfVar19[1] = DAT_006fd060;
          bVar11 = local_88[iVar13] & 199;
          local_84[iVar15] = bVar11 | 4;
          if (DAT_006fd05c <= *pfVar19) {
            if (DAT_006d2138 < *pfVar19) {
              bVar11 = bVar11 | 0x24;
              goto LAB_005ab1d9;
            }
          }
          else {
            bVar11 = bVar11 | 0x14;
LAB_005ab1d9:
            local_84[iVar15] = bVar11;
          }
          local_90[iVar15] = (int)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          iVar15 = iVar15 + 1;
          param_4 = param_4 + 1;
        }
        local_8c = local_8c + -1;
        iVar13 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar15 < 3) {
        return 0xffffffff;
      }
      local_88 = local_84;
      piVar16 = local_90;
      local_90 = local_90 + iVar15;
      local_8c = iVar15;
      local_84 = local_84 + iVar15;
    }
    param_3 = local_88[iVar15 + -1];
    iVar15 = iVar15 + -1;
    do {
      param_3 = param_3 | local_88[iVar15 + -1];
      iVar15 = iVar15 + -1;
      puVar12 = local_88;
    } while (0 < iVar15);
  }
  iVar15 = local_8c;
  if ((param_3 & 0x30) != 0) {
    if ((param_3 & 0x10) != 0) {
      iVar13 = 0;
      local_88 = (undefined1 *)0x0;
      local_94 = 0;
      iVar15 = local_8c + -1;
      do {
        if ((puVar12[iVar15] & 0x10) == 0) {
          local_90[iVar13] = piVar16[iVar15];
          local_84[(int)local_88] = puVar12[iVar15];
          iVar13 = (int)local_88 + 1;
          local_88 = (undefined1 *)iVar13;
        }
        if (((puVar12[local_94] ^ puVar12[iVar15]) & 0x10) != 0) {
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar7 = (float *)piVar16[iVar15];
          pfVar8 = (float *)piVar16[local_94];
          fVar9 = (*pfVar7 - DAT_006fd05c) / (*pfVar7 - *pfVar8);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          pfVar19[1] = pfVar7[1] - (pfVar7[1] - pfVar8[1]) * fVar9;
          pfVar19[3] = *(float *)(piVar16[iVar15] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar19[6] = *(float *)(piVar16[iVar15] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar19[7] = *(float *)(piVar16[iVar15] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar19[2] = *(float *)(piVar16[iVar15] + 8) -
                         (*(float *)(piVar16[iVar15] + 8) - *(float *)(piVar16[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar16[iVar15] + 0x24);
            fVar2 = *(float *)(piVar16[local_94] + 0x24);
            fVar3 = *(float *)(piVar16[iVar15] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar16[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar16[iVar15] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)(piVar16[iVar15] + 0x10);
          *pfVar19 = DAT_006fd05c;
          puVar10 = PTR_DAT_006d2128;
          local_84[(int)local_88] = puVar12[iVar15] & 0xdf | 0x10;
          local_90[(int)local_88] = (int)(puVar10 + DAT_006d2134 * param_4);
          iVar13 = (int)local_88 + 1;
          param_4 = param_4 + 1;
          local_88 = (undefined1 *)iVar13;
        }
        local_8c = local_8c + -1;
        iVar15 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      if (iVar13 < 3) {
        return 0xffffffff;
      }
      puVar12 = local_84;
      piVar16 = local_90;
      local_90 = local_90 + iVar13;
      local_8c = iVar13;
      local_84 = local_84 + iVar13;
    }
    iVar15 = local_8c;
    if ((param_3 & 0x20) != 0) {
      iVar15 = 0;
      local_88 = (undefined1 *)0x0;
      local_94 = 0;
      iVar13 = local_8c + -1;
      do {
        if ((puVar12[iVar13] & 0x20) == 0) {
          local_90[iVar15] = piVar16[iVar13];
          local_84[(int)local_88] = puVar12[iVar13];
          iVar15 = (int)local_88 + 1;
          local_88 = (undefined1 *)iVar15;
        }
        if (((puVar12[local_94] ^ puVar12[iVar13]) & 0x20) != 0) {
          pfVar19 = (float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4);
          pfVar7 = (float *)piVar16[iVar13];
          pfVar8 = (float *)piVar16[local_94];
          fVar9 = (*pfVar7 - DAT_006d2138) / (*pfVar7 - *pfVar8);
          fVar1 = pfVar7[3];
          fVar2 = pfVar8[3];
          fVar3 = pfVar7[6];
          fVar4 = pfVar8[6];
          fVar5 = pfVar7[7];
          fVar6 = pfVar8[7];
          pfVar19[1] = pfVar7[1] - (pfVar7[1] - pfVar8[1]) * fVar9;
          pfVar19[3] = *(float *)(piVar16[iVar13] + 0xc) - (fVar1 - fVar2) * fVar9;
          pfVar19[6] = *(float *)(piVar16[iVar13] + 0x18) - (fVar3 - fVar4) * fVar9;
          pfVar19[7] = *(float *)(piVar16[iVar13] + 0x1c) - (fVar5 - fVar6) * fVar9;
          if ((DAT_006d2124 & DAT_006fd06c) == 0) {
            pfVar19[2] = *(float *)(piVar16[iVar13] + 8) -
                         (*(float *)(piVar16[iVar13] + 8) - *(float *)(piVar16[local_94] + 8)) *
                         fVar9;
          }
          if (DAT_006fd058 == 1) {
            fVar1 = *(float *)(piVar16[iVar13] + 0x24);
            fVar2 = *(float *)(piVar16[local_94] + 0x24);
            fVar3 = *(float *)(piVar16[iVar13] + 0x20);
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x20) =
                 fVar3 - (fVar3 - *(float *)(piVar16[local_94] + 0x20)) * fVar9;
            *(float *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x24) =
                 *(float *)(piVar16[iVar13] + 0x24) - (fVar1 - fVar2) * fVar9;
          }
          *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
               *(undefined4 *)(piVar16[iVar13] + 0x10);
          *pfVar19 = DAT_006d2138;
          puVar10 = PTR_DAT_006d2128;
          local_84[(int)local_88] = puVar12[iVar13] & 0xef | 0x20;
          local_90[(int)local_88] = (int)(puVar10 + DAT_006d2134 * param_4);
          iVar15 = (int)local_88 + 1;
          param_4 = param_4 + 1;
          local_88 = (undefined1 *)iVar15;
        }
        local_8c = local_8c + -1;
        iVar13 = local_94;
        local_94 = local_94 + 1;
      } while (0 < local_8c);
      piVar16 = local_90;
      if (iVar15 < 3) {
        return 0xffffffff;
      }
    }
  }
  iVar13 = 0;
  if (0 < iVar15) {
    do {
      iVar14 = piVar16[iVar13];
      fVar1 = _DAT_00672294 / *(float *)(iVar14 + 0xc);
      if ((DAT_006fd06c & DAT_006d2120) != 0x10000) {
        *(float *)(iVar14 + 0x18) = fVar1 * *(float *)(iVar14 + 0x18);
        *(float *)(piVar16[iVar13] + 0x1c) = fVar1 * *(float *)(piVar16[iVar13] + 0x1c);
      }
      if ((DAT_006d2124 & DAT_006fd06c) == 1) {
        *(float *)(piVar16[iVar13] + 8) = (fVar1 - _DAT_006fd064) * _DAT_006fd068;
      }
      if (DAT_006fd058 == 1) {
        *(float *)(piVar16[iVar13] + 0x20) = fVar1 * *(float *)(piVar16[iVar13] + 0x20);
        *(float *)(piVar16[iVar13] + 0x24) = fVar1 * *(float *)(piVar16[iVar13] + 0x24);
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar15);
  }
  iVar14 = 0;
  iVar13 = (iVar15 + -2) * 3;
  piVar21 = piVar16;
  if (0 < iVar13) {
    do {
      piVar20 = piVar21 + 1;
      if (DAT_006fd058 == 1) {
        local_78[iVar14] = (*piVar16 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar14 + 1] = (*piVar20 - (int)PTR_DAT_006d2128) / 0x28;
        local_78[iVar14 + 2] = (piVar21[2] - (int)PTR_DAT_006d2128) / 0x28;
      }
      else {
        local_78[iVar14] = *piVar16 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar14 + 1] = *piVar20 - (int)PTR_DAT_006d2128 >> 5;
        local_78[iVar14 + 2] = piVar21[2] - (int)PTR_DAT_006d2128 >> 5;
      }
      iVar14 = iVar14 + 3;
      piVar21 = piVar20;
    } while (iVar14 < iVar13);
  }
  FUN_005b3260(iVar15 + -2,PTR_DAT_006d2128,local_78);
  return 0;
}

