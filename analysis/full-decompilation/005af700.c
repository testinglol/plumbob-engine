
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005af700(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float fVar9;
  undefined *puVar10;
  undefined *puVar11;
  byte bVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  int iVar16;
  undefined4 *puVar17;
  int *piVar18;
  undefined4 *puVar19;
  int iVar20;
  int local_2c [11];
  
  DAT_006fd024 = PTR_DAT_006d2128;
  DAT_006fd028 = PTR_DAT_006d2128;
  DAT_006fd02c = PTR_DAT_006d2128;
  DAT_006fd030 = PTR_DAT_006d2128;
  puVar17 = (undefined4 *)*param_1;
  puVar19 = (undefined4 *)PTR_DAT_006d2128;
  for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar19 = *puVar17;
    puVar17 = puVar17 + 1;
    puVar19 = puVar19 + 1;
  }
  puVar17 = (undefined4 *)param_1[1];
  puVar19 = (undefined4 *)(PTR_DAT_006d2128 + 0x20);
  for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar19 = *puVar17;
    puVar17 = puVar17 + 1;
    puVar19 = puVar19 + 1;
  }
  local_2c[0] = param_4;
  puVar17 = (undefined4 *)param_1[2];
  puVar19 = (undefined4 *)(PTR_DAT_006d2128 + 0x40);
  for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar19 = *puVar17;
    puVar17 = puVar17 + 1;
    puVar19 = puVar19 + 1;
  }
  *(float *)(DAT_006fd024 + 0x18) = *(float *)(DAT_006fd024 + 0xc) * *(float *)(DAT_006fd024 + 0x18)
  ;
  *(float *)(DAT_006fd024 + 0x1c) = *(float *)(DAT_006fd024 + 0xc) * *(float *)(DAT_006fd024 + 0x1c)
  ;
  *(float *)(DAT_006fd028 + 0x18) = *(float *)(DAT_006fd028 + 0xc) * *(float *)(DAT_006fd028 + 0x18)
  ;
  *(float *)(DAT_006fd028 + 0x1c) = *(float *)(DAT_006fd028 + 0xc) * *(float *)(DAT_006fd028 + 0x1c)
  ;
  *(float *)(DAT_006fd02c + 0x18) = *(float *)(DAT_006fd02c + 0xc) * *(float *)(DAT_006fd02c + 0x18)
  ;
  *(float *)(DAT_006fd02c + 0x1c) = *(float *)(DAT_006fd02c + 0xc) * *(float *)(DAT_006fd02c + 0x1c)
  ;
  if (param_4 == 4) {
    puVar17 = (undefined4 *)param_1[3];
    puVar19 = (undefined4 *)(PTR_DAT_006d2128 + 0x60);
    for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar19 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar19 = puVar19 + 1;
    }
    *(float *)(DAT_006fd030 + 0x18) =
         *(float *)(DAT_006fd030 + 0xc) * *(float *)(DAT_006fd030 + 0x18);
    *(float *)(DAT_006fd030 + 0x1c) =
         *(float *)(DAT_006fd030 + 0xc) * *(float *)(DAT_006fd030 + 0x1c);
  }
  puVar10 = PTR_DAT_006d211c;
  iVar20 = 0;
  iVar16 = param_4 << 5;
  iVar14 = param_4 + -1;
  iVar13 = 0;
  do {
    if ((*(byte *)(iVar14 + param_2) & 1) == 0) {
      *(undefined **)(puVar10 + iVar20 * 4) = (&DAT_006fd024)[iVar14];
      (&DAT_006fcfb0)[iVar20] = *(undefined1 *)(iVar14 + param_2);
      iVar20 = iVar20 + 1;
    }
    if (((*(byte *)(param_2 + iVar13) ^ *(byte *)(iVar14 + param_2)) & 1) != 0) {
      pfVar15 = (float *)(&DAT_006fd024)[iVar14];
      pfVar8 = (float *)(&DAT_006fd024)[iVar13];
      fVar9 = (pfVar15[3] - DAT_00703f14) / (pfVar15[3] - pfVar8[3]);
      fVar2 = pfVar15[1];
      fVar3 = pfVar8[1];
      fVar4 = pfVar15[6];
      fVar5 = pfVar8[6];
      fVar6 = pfVar15[7];
      fVar7 = pfVar8[7];
      *(float *)(PTR_DAT_006d2128 + iVar16) = *pfVar15 - (*pfVar15 - *pfVar8) * fVar9;
      *(float *)(PTR_DAT_006d2128 + iVar16 + 4) =
           *(float *)((int)(&DAT_006fd024)[iVar14] + 4) - (fVar2 - fVar3) * fVar9;
      *(float *)(PTR_DAT_006d2128 + iVar16 + 0x18) =
           *(float *)((int)(&DAT_006fd024)[iVar14] + 0x18) - (fVar4 - fVar5) * fVar9;
      *(float *)(PTR_DAT_006d2128 + iVar16 + 0x1c) =
           *(float *)((int)(&DAT_006fd024)[iVar14] + 0x1c) - (fVar6 - fVar7) * fVar9;
      *(undefined4 *)(PTR_DAT_006d2128 + DAT_006d2134 * param_4 + 0x10) =
           *(undefined4 *)((int)(&DAT_006fd024)[iVar14] + 0x10);
      *(undefined4 *)(PTR_DAT_006d2128 + iVar16 + 8) = 0;
      *(float *)(PTR_DAT_006d2128 + iVar16 + 0xc) = DAT_00703f14;
      puVar11 = PTR_DAT_006d2128;
      (&DAT_006fcfb0)[iVar20] = 1;
      pfVar15 = (float *)(puVar11 + iVar16);
      if (DAT_006fd060 <= pfVar15[1]) {
        if (DAT_006d213c < pfVar15[1]) {
          (&DAT_006fcfb0)[iVar20] = 9;
        }
      }
      else {
        (&DAT_006fcfb0)[iVar20] = 5;
      }
      if (DAT_006fd05c <= *pfVar15) {
        if (DAT_006d2138 < *pfVar15) {
          bVar12 = (&DAT_006fcfb0)[iVar20] | 0x20;
          goto LAB_005af981;
        }
      }
      else {
        bVar12 = (&DAT_006fcfb0)[iVar20] | 0x10;
LAB_005af981:
        (&DAT_006fcfb0)[iVar20] = bVar12;
      }
      iVar20 = iVar20 + 1;
      param_4 = param_4 + 1;
      iVar16 = iVar16 + 0x20;
      *(float **)(puVar10 + iVar20 * 4 + -4) = pfVar15;
    }
    puVar11 = PTR_DAT_006d211c;
    local_2c[0] = local_2c[0] + -1;
    iVar14 = iVar13;
    iVar13 = iVar13 + 1;
    if (local_2c[0] < 1) {
      if (2 < iVar20) {
        bVar12 = (&DAT_006fcfaf)[iVar20];
        iVar14 = iVar20 + -1;
        do {
          pbVar1 = &DAT_006fcfaf + iVar14;
          iVar14 = iVar14 + -1;
          bVar12 = bVar12 & *pbVar1;
        } while (0 < iVar14);
        if (bVar12 == 0) {
          iVar14 = 0;
          if (0 < iVar20) {
            do {
              iVar13 = *(int *)(puVar11 + iVar14 * 4);
              fVar2 = _DAT_00672294 / *(float *)(iVar13 + 0xc);
              *(float *)(iVar13 + 0x18) = fVar2 * *(float *)(iVar13 + 0x18);
              *(float *)(*(int *)(puVar11 + iVar14 * 4) + 0x1c) =
                   fVar2 * *(float *)(*(int *)(puVar11 + iVar14 * 4) + 0x1c);
              local_2c[iVar14 + 1] = *(int *)(puVar11 + iVar14 * 4) - (int)PTR_DAT_006d2128 >> 5;
              iVar14 = iVar14 + 1;
            } while (iVar14 < iVar20);
          }
          iVar14 = (iVar20 + -2) * 3;
          if (0 < iVar14) {
            iVar13 = 0;
            piVar18 = (int *)(puVar11 + 4);
            do {
              iVar16 = iVar13 + 3;
              local_2c[iVar13 + 1] = *(int *)puVar11 - (int)PTR_DAT_006d2128 >> 5;
              local_2c[iVar13 + 2] = *piVar18 - (int)PTR_DAT_006d2128 >> 5;
              local_2c[iVar16] = piVar18[1] - (int)PTR_DAT_006d2128 >> 5;
              iVar13 = iVar16;
              piVar18 = piVar18 + 1;
            } while (iVar16 < iVar14);
          }
          FUN_005b3260(iVar20 + -2,PTR_DAT_006d2128,local_2c + 1);
        }
        return 0;
      }
      return 0xffffffff;
    }
  } while( true );
}

