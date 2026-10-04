
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611430(int *param_1,int *param_2,code *param_3,double param_4,int param_5,int param_6)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  float10 fVar17;
  float10 fVar18;
  int local_88;
  int local_84;
  int iStack_7c;
  int local_68;
  int local_60;
  int local_5c;
  double local_48;
  double local_40;
  undefined8 local_38;
  double dStack_30;
  double dStack_28;
  double dStack_20;
  double local_18;
  double local_10;
  
  local_60 = param_6;
  if ((param_5 != 0) && (param_6 == 0)) {
    local_60 = FUN_006122d0();
  }
  iVar12 = *param_1;
  iVar7 = *(int *)(iVar12 + 0x14);
  iVar16 = *param_2;
  iVar13 = *(int *)(iVar16 + 0x10);
  piVar6 = (int *)FUN_00612090();
  iVar12 = *(int *)(iVar12 + 0x10);
  dVar2 = (double)iVar13 / (double)iVar12;
  iVar16 = *(int *)(iVar16 + 0x14);
  dVar3 = (double)iVar16 / (double)iVar7;
  iVar7 = FUN_005a9320();
  DAT_00703fd8 = iVar7;
  if (_DAT_00667280 <= dVar2) {
    local_84 = 0;
    if (0 < iVar13) {
      __ftol();
      do {
        *(undefined4 *)(iVar7 + local_84 * 8) = 0;
        uVar8 = FUN_005a9320();
        dVar4 = (double)local_84 / dVar2;
        *(undefined4 *)(DAT_00703fd8 + 4 + local_84 * 8) = uVar8;
        FUN_00636ac8(dVar4 - param_4);
        fVar17 = (float10)FUN_006369f9(dVar4 + param_4);
        iVar9 = __ftol();
        dVar5 = (double)iVar9;
        iVar7 = DAT_00703fd8;
        if (dVar5 <= (double)fVar17) {
          local_68 = -iVar9;
          do {
            fVar18 = (float10)(*param_3)(dVar4 - dVar5);
            iVar7 = DAT_00703fd8;
            iVar14 = local_68;
            if ((-1 < iVar9) && (iVar14 = iVar9, iVar12 <= iVar9)) {
              iVar14 = (iVar12 * 2 - iVar9) + -1;
            }
            iVar11 = *(int *)(DAT_00703fd8 + local_84 * 8);
            *(int *)(DAT_00703fd8 + local_84 * 8) = iVar11 + 1;
            piVar10 = (int *)(iVar11 * 0x10 + *(int *)(iVar7 + 4 + local_84 * 8));
            iVar9 = iVar9 + 1;
            *piVar10 = iVar14;
            *(double *)(piVar10 + 2) = (double)fVar18;
            dVar5 = (double)iVar9;
            local_68 = local_68 + -1;
          } while (dVar5 <= (double)fVar17);
        }
        local_84 = local_84 + 1;
      } while (local_84 < iVar13);
    }
  }
  else {
    local_48 = (double)(iVar12 + -1);
    if (param_4 / dVar2 < local_48) {
      local_48 = param_4 / dVar2;
    }
    local_84 = 0;
    if (0 < iVar13) {
      __ftol();
      do {
        *(undefined4 *)(iVar7 + local_84 * 8) = 0;
        uVar8 = FUN_005a9320();
        dVar4 = (double)local_84 / dVar2;
        *(undefined4 *)(DAT_00703fd8 + 4 + local_84 * 8) = uVar8;
        FUN_00636ac8(dVar4 - local_48);
        fVar17 = (float10)FUN_006369f9(dVar4 + local_48);
        iVar9 = __ftol();
        dVar5 = (double)iVar9;
        iVar7 = DAT_00703fd8;
        if (dVar5 <= (double)fVar17) {
          iVar14 = -iVar9;
          do {
            fVar18 = (float10)(*param_3)((dVar4 - dVar5) / (local_48 / param_4));
            iVar7 = DAT_00703fd8;
            iVar11 = iVar14;
            if ((-1 < iVar9) && (iVar11 = iVar9, iVar12 <= iVar9)) {
              iVar11 = (iVar12 * 2 - iVar9) + -1;
            }
            iVar1 = *(int *)(DAT_00703fd8 + local_84 * 8);
            *(int *)(DAT_00703fd8 + local_84 * 8) = iVar1 + 1;
            piVar10 = (int *)(iVar1 * 0x10 + *(int *)(iVar7 + 4 + local_84 * 8));
            iVar9 = iVar9 + 1;
            *piVar10 = iVar11;
            *(double *)(piVar10 + 2) = (double)(fVar18 / (float10)(local_48 / param_4));
            dVar5 = (double)iVar9;
            iVar14 = iVar14 + -1;
          } while (dVar5 <= (double)fVar17);
        }
        local_84 = local_84 + 1;
      } while (local_84 < iVar13);
    }
  }
  iVar7 = FUN_005a9320();
  iVar12 = *piVar6;
  iStack_7c = 0;
  if (0 < *(int *)(iVar12 + 0x14)) {
    do {
      FUN_00612210();
      local_84 = 0;
      if (0 < *(int *)(iVar12 + 0x10)) {
        local_5c = 0;
        do {
          dStack_30 = 0.0;
          dStack_28 = 0.0;
          dStack_20 = 0.0;
          local_18 = 0.0;
          local_40 = 0.0;
          local_88 = 0;
          if (0 < *(int *)(local_5c + DAT_00703fd8)) {
            iVar12 = *(int *)(*param_1 + 0x10);
            iVar14 = 0;
            iVar9 = DAT_00703fd8;
            do {
              iVar11 = *(int *)(local_5c + 4 + iVar9);
              local_38 = (double)CONCAT44(*(undefined4 *)(iVar11 + 0xc + iVar14),
                                          *(undefined4 *)(iVar11 + 8 + iVar14));
              uVar15 = DAT_006ff438;
              if (*(int *)(iVar11 + iVar14) < iVar12) {
                uVar15 = *(uint *)(iVar7 + *(int *)(*(int *)(local_5c + 4 + iVar9) + iVar14) * 4);
              }
              if ((param_5 == 0) ||
                 (iVar11 = FUN_00612380(uVar15,local_60), iVar9 = DAT_00703fd8, iVar11 == 0)) {
                dStack_30 = (double)(uVar15 >> 0x18) * local_38 + dStack_30;
                dStack_28 = (double)(uVar15 >> 0x10 & 0xff) * local_38 + dStack_28;
                dStack_20 = (double)(uVar15 >> 8 & 0xff) * local_38 + dStack_20;
                local_18 = (double)(uVar15 & 0xff) * local_38 + local_18;
                local_40 = local_38 + local_40;
              }
              local_88 = local_88 + 1;
              iVar14 = iVar14 + 0x10;
            } while (local_88 < *(int *)(local_5c + iVar9));
          }
          if ((param_5 == 0) || (_DAT_00668710 <= local_40)) {
            FUN_006121c0(dStack_30 / local_40,0);
            FUN_006121c0(dStack_28 / local_40,0);
            FUN_006121c0(dStack_20 / local_40,0);
            FUN_006121c0(local_18 / local_40,0);
          }
          FUN_00612290(piVar6,local_84);
          local_84 = local_84 + 1;
          local_5c = local_5c + 8;
        } while (local_84 < *(int *)(*piVar6 + 0x10));
      }
      iVar12 = *piVar6;
      iStack_7c = iStack_7c + 1;
    } while (iStack_7c < *(int *)(iVar12 + 0x14));
  }
  FUN_005a9340();
  iVar12 = *piVar6;
  iVar7 = *(int *)(iVar12 + 0x10);
  iVar9 = 0;
  if (0 < iVar7) {
    do {
      FUN_005a9340();
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar7);
  }
  FUN_005a9340();
  iVar7 = FUN_005a9320();
  DAT_00703fd8 = iVar7;
  if (_DAT_00667280 <= dVar3) {
    local_84 = 0;
    if (0 < iVar16) {
      __ftol();
      do {
        *(undefined4 *)(iVar7 + local_84 * 8) = 0;
        uVar8 = FUN_005a9320();
        dVar2 = (double)local_84 / dVar3;
        *(undefined4 *)(DAT_00703fd8 + 4 + local_84 * 8) = uVar8;
        FUN_00636ac8(dVar2 - param_4);
        fVar17 = (float10)FUN_006369f9(dVar2 + param_4);
        iVar9 = __ftol();
        dVar4 = (double)iVar9;
        iVar7 = DAT_00703fd8;
        if (dVar4 <= (double)fVar17) {
          local_68 = -iVar9;
          do {
            fVar18 = (float10)(*param_3)(dVar2 - dVar4);
            iVar7 = DAT_00703fd8;
            iVar14 = local_68;
            if ((-1 < iVar9) && (iVar14 = iVar9, *(int *)(iVar12 + 0x14) <= iVar9)) {
              iVar14 = (*(int *)(iVar12 + 0x14) * 2 - iVar9) + -1;
            }
            iVar11 = *(int *)(DAT_00703fd8 + local_84 * 8);
            *(int *)(DAT_00703fd8 + local_84 * 8) = iVar11 + 1;
            piVar6 = (int *)(iVar11 * 0x10 + *(int *)(iVar7 + 4 + local_84 * 8));
            iVar9 = iVar9 + 1;
            *piVar6 = iVar14;
            *(double *)(piVar6 + 2) = (double)fVar18;
            dVar4 = (double)iVar9;
            local_68 = local_68 + -1;
          } while (dVar4 <= (double)fVar17);
        }
        local_84 = local_84 + 1;
      } while (local_84 < iVar16);
    }
  }
  else {
    local_48 = (double)(*(int *)(*param_1 + 0x14) + -1);
    if (param_4 / dVar3 < local_48) {
      local_48 = param_4 / dVar3;
    }
    local_84 = 0;
    if (0 < iVar16) {
      __ftol();
      do {
        *(undefined4 *)(iVar7 + local_84 * 8) = 0;
        uVar8 = FUN_005a9320();
        dVar2 = (double)local_84 / dVar3;
        *(undefined4 *)(DAT_00703fd8 + 4 + local_84 * 8) = uVar8;
        FUN_00636ac8(dVar2 - local_48);
        fVar17 = (float10)FUN_006369f9(dVar2 + local_48);
        iVar9 = __ftol();
        dVar4 = (double)iVar9;
        iVar7 = DAT_00703fd8;
        if (dVar4 <= (double)fVar17) {
          iVar14 = -iVar9;
          do {
            fVar18 = (float10)(*param_3)((dVar2 - dVar4) / (local_48 / param_4));
            iVar7 = DAT_00703fd8;
            iVar11 = iVar14;
            if ((-1 < iVar9) && (iVar11 = iVar9, *(int *)(iVar12 + 0x14) <= iVar9)) {
              iVar11 = (*(int *)(iVar12 + 0x14) * 2 - iVar9) + -1;
            }
            iVar1 = *(int *)(DAT_00703fd8 + local_84 * 8);
            *(int *)(DAT_00703fd8 + local_84 * 8) = iVar1 + 1;
            piVar6 = (int *)(iVar1 * 0x10 + *(int *)(iVar7 + 4 + local_84 * 8));
            iVar9 = iVar9 + 1;
            *piVar6 = iVar11;
            *(double *)(piVar6 + 2) = (double)(fVar18 / (float10)(local_48 / param_4));
            dVar4 = (double)iVar9;
            iVar14 = iVar14 + -1;
          } while (dVar4 <= (double)fVar17);
        }
        local_84 = local_84 + 1;
      } while (local_84 < iVar16);
    }
  }
  iVar12 = FUN_005a9320();
  iStack_7c = 0;
  if (0 < iVar13) {
    do {
      FUN_00612250();
      iVar7 = 0;
      if (0 < iVar16) {
        do {
          local_10 = 0.0;
          local_18 = 0.0;
          dStack_20 = 0.0;
          dStack_28 = 0.0;
          local_40 = 0.0;
          local_88 = 0;
          if (0 < *(int *)(DAT_00703fd8 + iVar7 * 8)) {
            iVar16 = 0;
            do {
              iVar13 = *(int *)(DAT_00703fd8 + 4 + iVar7 * 8);
              uVar15 = *(uint *)(iVar12 + *(int *)(iVar13 + iVar16) * 4);
              dVar2 = *(double *)(iVar13 + iVar16 + 8);
              if ((param_5 == 0) || (iVar13 = FUN_00612380(uVar15,local_60), iVar13 == 0)) {
                local_10 = (double)(uVar15 >> 0x18) * dVar2 + local_10;
                local_18 = (double)(uVar15 >> 0x10 & 0xff) * dVar2 + local_18;
                dStack_20 = (double)(uVar15 >> 8 & 0xff) * dVar2 + dStack_20;
                dStack_28 = (double)(uVar15 & 0xff) * dVar2 + dStack_28;
                local_40 = dVar2 + local_40;
              }
              local_88 = local_88 + 1;
              iVar16 = iVar16 + 0x10;
            } while (local_88 < *(int *)(DAT_00703fd8 + iVar7 * 8));
          }
          if ((param_5 == 0) || (_DAT_00668710 <= local_40)) {
            FUN_006121c0(local_10 / local_40,0);
            FUN_006121c0(local_18 / local_40,0);
            FUN_006121c0(dStack_20 / local_40,0);
            FUN_006121c0(dStack_28 / local_40,0);
          }
          FUN_00612290(param_2,iStack_7c);
          iVar16 = *(int *)(*param_2 + 0x14);
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar16);
      }
      iStack_7c = iStack_7c + 1;
    } while (iStack_7c < *(int *)(*param_2 + 0x10));
  }
  FUN_005a9340();
  iVar12 = *(int *)(*param_2 + 0x14);
  iVar7 = 0;
  if (0 < iVar12) {
    do {
      FUN_005a9340();
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar12);
  }
  FUN_005a9340();
  FUN_006121a0();
  return;
}

