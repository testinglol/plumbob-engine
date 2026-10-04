
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00597c54(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int *piVar8;
  int iVar9;
  bool bVar10;
  char cVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int *extraout_ECX;
  int iVar18;
  int unaff_EBP;
  float10 fVar19;
  float10 extraout_ST0;
  
  FUN_00634c24();
  iVar14 = *(int *)(unaff_EBP + 8);
  iVar12 = (extraout_ECX[3] - extraout_ECX[2]) / 0xc;
  extraout_ECX[7] = extraout_ECX[6];
  extraout_ECX[6] = iVar14;
  *(int *)(unaff_EBP + 8) = iVar14 - extraout_ECX[7];
  *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x34) = iVar12;
  if ((iVar12 == 0) || (extraout_ECX[0xe] == 0)) goto LAB_0059862d;
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(extraout_ECX[1] + 0x2c);
  uVar13 = __ftol();
  bVar10 = _DAT_0067343c < ABS((float)extraout_ECX[9]);
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar13;
  if (bVar10) {
    fVar4 = *(float *)(unaff_EBP + -0x1c) / (float)extraout_ECX[8];
  }
  else {
    fVar4 = 0.0;
  }
  *(float *)(unaff_EBP + 8) = fVar4;
  fVar4 = (float)_DAT_006669e8;
  if ((float)extraout_ECX[9] < fVar4) {
    *(float *)(unaff_EBP + 8) = -*(float *)(unaff_EBP + 8);
  }
  fVar5 = *(float *)(unaff_EBP + 8) + (float)extraout_ECX[10];
  extraout_ECX[10] = (int)fVar5;
  if (ABS(*(float *)(unaff_EBP + -0x1c)) <= _DAT_0067343c) goto LAB_00597e44;
  fVar3 = (float)extraout_ECX[9];
  *(double *)(unaff_EBP + -0x3c) = (double)fVar5;
  if (fVar4 <= fVar3) {
    if ((float)_DAT_00667280 <= fVar5) goto LAB_00597d30;
LAB_00597d7a:
    extraout_ECX[0xf] = 0;
  }
  else {
    if (fVar4 < fVar5) goto LAB_00597d7a;
LAB_00597d30:
    iVar12 = extraout_ECX[0x10];
    extraout_ECX[0xf] = 1;
    if (iVar12 == 0) {
      extraout_ECX[8] = 0x4cbebc20;
      extraout_ECX[9] = 0;
LAB_00597e23:
      if (fVar4 <= fVar5) {
        if (fVar5 <= (float)_DAT_00667280) goto LAB_00597e44;
        fVar5 = 1.0;
      }
      else {
        fVar5 = 0.0;
      }
LAB_00597e3d:
      extraout_ECX[10] = (int)fVar5;
    }
    else if (iVar12 == 1) {
      fVar19 = (float10)FUN_006369f9(*(undefined8 *)(unaff_EBP + -0x3c));
      *(float *)(unaff_EBP + 8) = (float)((float10)(float)extraout_ECX[10] - fVar19);
      fVar4 = (float)_DAT_006669e8;
      if (((float)extraout_ECX[10] < fVar4) || ((float)_DAT_00667280 < (float)extraout_ECX[10])) {
        extraout_ECX[10] = *(int *)(unaff_EBP + 8);
      }
    }
    else if (iVar12 == 2) {
      extraout_ECX[9] = (int)-(float)extraout_ECX[9];
      fVar19 = (float10)FUN_006369f9(*(undefined8 *)(unaff_EBP + -0x3c));
      *(float *)(unaff_EBP + 8) = (float)((float10)(float)extraout_ECX[10] - fVar19);
      fVar4 = (float)_DAT_006669e8;
      if (((float)extraout_ECX[10] < fVar4) || ((float)_DAT_00667280 < (float)extraout_ECX[10])) {
        fVar5 = (float)_DAT_00667280 - *(float *)(unaff_EBP + 8);
        goto LAB_00597e3d;
      }
    }
    else if (iVar12 == 3) {
      extraout_ECX[0x11] = 1;
      extraout_ECX[9] = 0;
      extraout_ECX[0x12] = iVar14;
      extraout_ECX[0x14] = extraout_ECX[0xb];
      extraout_ECX[8] = 0;
      extraout_ECX[0x15] = 0;
      goto LAB_00597e23;
    }
  }
LAB_00597e44:
  if (extraout_ECX[0x11] != 0) {
    *(int *)(unaff_EBP + 8) = extraout_ECX[6] - extraout_ECX[0x12];
    *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
    iVar14 = extraout_ECX[0x13];
    *(float *)(unaff_EBP + -0x30) = (float)iVar14;
    fVar5 = *(float *)(unaff_EBP + 8) / (float)iVar14;
    if (fVar5 <= (float)_DAT_00667280) {
      if (fVar5 < fVar4) {
        fVar5 = 0.0;
      }
    }
    else {
      fVar5 = 1.0;
    }
    if (*(float *)(unaff_EBP + 8) <= *(float *)(unaff_EBP + -0x30)) {
      extraout_ECX[0xb] =
           (int)(((float)extraout_ECX[0x15] - (float)extraout_ECX[0x14]) * fVar5 +
                (float)extraout_ECX[0x14]);
    }
    else {
      extraout_ECX[0x11] = 0;
      extraout_ECX[0xb] = extraout_ECX[0x15];
    }
  }
  iVar14 = __ftol();
  extraout_ECX[0xc] = iVar14;
  if (extraout_ST0 < (float10)(float)extraout_ECX[0xb]) {
    iVar14 = extraout_ECX[0xe];
    fVar4 = (float)extraout_ECX[10];
    *(float *)(unaff_EBP + -0x14) = (float)iVar14 * fVar4;
    FUN_006369f9((double)((float)iVar14 * fVar4));
    uVar15 = __ftol();
    iVar14 = extraout_ECX[0xe];
    iVar12 = extraout_ECX[0x18];
    *(int *)(unaff_EBP + 8) = iVar14;
    *(uint *)(unaff_EBP + -0x18) = uVar15;
    if (iVar12 != 0) {
      iVar12 = extraout_ECX[0x18] + 1;
      uVar15 = ((int)uVar15 / iVar12) * iVar12;
      *(uint *)(unaff_EBP + -0x18) = uVar15;
      *(int *)(unaff_EBP + 8) = iVar14 / iVar12;
      if (iVar12 * (iVar14 / iVar12) < iVar14) {
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      }
    }
    if ((int)uVar15 < 0) {
      uVar15 = 0;
LAB_00597f20:
      *(uint *)(unaff_EBP + -0x18) = uVar15;
    }
    else if (iVar14 <= (int)uVar15) {
      uVar15 = iVar14 - 1;
      goto LAB_00597f20;
    }
    *(undefined4 *)(unaff_EBP + -0x28) = 1;
    fVar4 = (float)extraout_ECX[8] / (float)*(int *)(unaff_EBP + 8);
    if (fVar4 + fVar4 <= *(float *)(unaff_EBP + -0x1c)) {
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
    }
    *(uint *)(unaff_EBP + -0x1c) = uVar15;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0x3f800000;
    if (*(int *)(unaff_EBP + -0x28) != 0) {
      iVar12 = extraout_ECX[0x18];
      uVar16 = iVar12 + 1 + uVar15;
      *(uint *)(unaff_EBP + -0x1c) = uVar16;
      if (iVar14 <= (int)uVar16) {
        uVar16 = -(uint)(extraout_ECX[0x10] != 1) & uVar15;
        *(uint *)(unaff_EBP + -0x1c) = uVar16;
      }
      if (iVar12 == 0) {
        *(float *)(unaff_EBP + -0x20) =
             *(float *)(unaff_EBP + -0x14) - (float)*(int *)(unaff_EBP + -0x18);
      }
      else {
        if ((int)uVar15 < (int)uVar16) {
          *(uint *)(unaff_EBP + 8) = uVar16 - uVar15;
          iVar14 = *(int *)(unaff_EBP + 8);
        }
        else {
          *(uint *)(unaff_EBP + 8) = iVar14 - uVar15;
          iVar14 = *(int *)(unaff_EBP + 8);
        }
        *(float *)(unaff_EBP + -0x20) =
             (*(float *)(unaff_EBP + -0x14) - (float)*(int *)(unaff_EBP + -0x18)) / (float)iVar14;
      }
      *(float *)(unaff_EBP + -0x24) = (float)_DAT_00667280 - *(float *)(unaff_EBP + -0x20);
    }
    iVar14 = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    if (0 < *(int *)(unaff_EBP + -0x34)) {
      do {
        iVar12 = *(int *)(extraout_ECX[2] + iVar14 * 0xc);
        iVar14 = extraout_ECX[2] + iVar14 * 0xc;
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar12 + 0x74);
        if (*(int *)(iVar12 + 0x68) <= extraout_ECX[5]) {
          piVar8 = *(int **)(iVar14 + 8);
          *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar14 + 4);
          if ((piVar8 != (int *)0x0) &&
             (iVar14 = *(int *)(*piVar8 + 8) - *(int *)(*piVar8 + 4) >> 3,
             *(int *)(unaff_EBP + 8) = iVar14, iVar14 != 0)) {
            if ((float)_DAT_006669e8 <= (float)extraout_ECX[9]) {
              if (extraout_ECX[0xc] < extraout_ECX[0xd]) {
                while ((iVar14 = piVar8[1], -1 < iVar14 &&
                       (iVar18 = *piVar8, iVar14 < *(int *)(iVar18 + 8) - *(int *)(iVar18 + 4) >> 3)
                       )) {
                  iVar9 = *(int *)(*(int *)(iVar18 + 4) + iVar14 * 8);
                  iVar14 = *(int *)(*(int *)(iVar18 + 4) + iVar14 * 8 + 4);
                  if ((-1 < iVar9) &&
                     (((iVar9 <= *(int *)(unaff_EBP + -0x2c) &&
                       ((*(int *)(iVar14 + 8) - *(int *)(iVar14 + 4) & 0xfffffff8U) != 0)) &&
                      (DAT_006f7640 != (code *)0x0)))) {
                    (*DAT_006f7640)(DAT_006f7644,extraout_ECX,iVar12,
                                    *(undefined4 *)(unaff_EBP + -0x10));
                  }
                  FUN_005947ca();
                }
                if ((piVar8[1] < 0) ||
                   (*(int *)(*piVar8 + 8) - *(int *)(*piVar8 + 4) >> 3 <= piVar8[1])) {
                  FUN_005947da();
                }
              }
              do {
                iVar14 = piVar8[1];
                if ((iVar14 < 0) ||
                   (iVar18 = *piVar8, *(int *)(iVar18 + 8) - *(int *)(iVar18 + 4) >> 3 <= iVar14))
                goto LAB_00598212;
                iVar9 = *(int *)(iVar14 * 8 + *(int *)(iVar18 + 4));
                if ((-1 < iVar9) && (iVar9 <= *(int *)(unaff_EBP + -0x2c))) {
                  if (extraout_ECX[0xc] < iVar9) goto LAB_00598212;
                  iVar14 = *(int *)(*(int *)(iVar18 + 4) + 4 + iVar14 * 8);
                  if (((*(int *)(iVar14 + 8) - *(int *)(iVar14 + 4) & 0xfffffff8U) != 0) &&
                     (DAT_006f7640 != (code *)0x0)) {
                    (*DAT_006f7640)(DAT_006f7644,extraout_ECX,iVar12,
                                    *(undefined4 *)(unaff_EBP + -0x10),iVar14,extraout_ECX[10]);
                  }
                }
                FUN_005947ca();
              } while( true );
            }
            if (extraout_ECX[0xd] < extraout_ECX[0xc]) {
              while( true ) {
                FUN_005947d2();
                iVar14 = piVar8[1];
                if ((iVar14 < 0) ||
                   (iVar18 = *piVar8, *(int *)(iVar18 + 8) - *(int *)(iVar18 + 4) >> 3 <= iVar14))
                break;
                iVar9 = *(int *)(*(int *)(iVar18 + 4) + iVar14 * 8);
                iVar14 = *(int *)(*(int *)(iVar18 + 4) + iVar14 * 8 + 4);
                if ((((-1 < iVar9) && (iVar9 <= *(int *)(unaff_EBP + -0x2c))) &&
                    ((*(int *)(iVar14 + 8) - *(int *)(iVar14 + 4) & 0xfffffff8U) != 0)) &&
                   (DAT_006f7640 != (code *)0x0)) {
                  (*DAT_006f7640)(DAT_006f7644,extraout_ECX,iVar12,
                                  *(undefined4 *)(unaff_EBP + -0x10));
                }
              }
              if ((piVar8[1] < 0) ||
                 (*(int *)(*piVar8 + 8) - *(int *)(*piVar8 + 4) >> 3 <= piVar8[1])) {
                FUN_005947e3();
              }
            }
            do {
              iVar14 = piVar8[1];
              if ((iVar14 < 0) ||
                 (iVar18 = *piVar8, *(int *)(iVar18 + 8) - *(int *)(iVar18 + 4) >> 3 <= iVar14))
              break;
              iVar9 = *(int *)(iVar14 * 8 + *(int *)(iVar18 + 4));
              if ((-1 < iVar9) && (iVar9 <= *(int *)(unaff_EBP + -0x2c))) {
                if (iVar9 < extraout_ECX[0xc]) break;
                iVar14 = *(int *)(*(int *)(iVar18 + 4) + 4 + iVar14 * 8);
                if (((*(int *)(iVar14 + 8) - *(int *)(iVar14 + 4) & 0xfffffff8U) != 0) &&
                   (DAT_006f7640 != (code *)0x0)) {
                  (*DAT_006f7640)(DAT_006f7644,extraout_ECX,iVar12,
                                  *(undefined4 *)(unaff_EBP + -0x10));
                }
              }
              FUN_005947d2();
            } while( true );
          }
LAB_00598212:
          if (*(int *)(unaff_EBP + 0xc) != 0) {
            *(undefined1 *)(unaff_EBP + 0xb) = 0;
            if (*(int *)(unaff_EBP + -0x28) == 0) {
              iVar14 = *(int *)(unaff_EBP + -0x10);
              if ((*(int *)(iVar14 + 0x1c) != 0) &&
                 ((*(int *)(unaff_EBP + -0x14) != 0 || (extraout_ECX[0x1e] != -1)))) {
                puVar2 = (undefined4 *)
                         (*(int *)(*(int *)(iVar14 + 0x10) + 0x60) +
                         (*(int *)(iVar14 + 0x24) + *(int *)(unaff_EBP + -0x18)) * 0xc);
                fVar4 = (float)puVar2[2];
                fVar5 = (float)extraout_ECX[0xb];
                *(undefined4 *)(unaff_EBP + -0x4c) = *puVar2;
                fVar3 = (float)_DAT_00667280;
                *(undefined4 *)(unaff_EBP + -0x48) = puVar2[1];
                pfVar1 = (float *)(extraout_ECX + 0xb);
                if ((fVar3 <= fVar5) ||
                   ((*(int *)(iVar12 + 0x74) == 0 ||
                    ((*(int *)(unaff_EBP + -0x14) == 0 && (extraout_ECX[0x1e] == 0)))))) {
                  *(undefined4 *)(iVar12 + 0x30) = *(undefined4 *)(unaff_EBP + -0x4c);
                  *(undefined4 *)(iVar12 + 0x34) = *(undefined4 *)(unaff_EBP + -0x48);
                }
                else {
                  fVar5 = *pfVar1;
                  fVar3 = (float)_DAT_00667280;
                  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(iVar12 + 0x30);
                  uVar13 = *(undefined4 *)(iVar12 + 0x34);
                  *(float *)(unaff_EBP + 8) = fVar3 - fVar5;
                  fVar5 = *(float *)(iVar12 + 0x38);
                  fVar3 = *pfVar1;
                  *(undefined4 *)(unaff_EBP + -100) = uVar13;
                  fVar4 = fVar4 * fVar3 + fVar5 * *(float *)(unaff_EBP + 8);
                  fVar5 = *(float *)(unaff_EBP + -100);
                  fVar3 = *(float *)(unaff_EBP + 8);
                  fVar6 = *(float *)(unaff_EBP + -0x48);
                  fVar7 = *pfVar1;
                  *(float *)(iVar12 + 0x30) =
                       *(float *)(unaff_EBP + -0x68) * *(float *)(unaff_EBP + 8) +
                       *(float *)(unaff_EBP + -0x4c) * *pfVar1;
                  *(float *)(iVar12 + 0x34) = fVar6 * fVar7 + fVar5 * fVar3;
                }
                *(float *)(iVar12 + 0x38) = fVar4;
                *(int *)(iVar12 + 0x130) = *(int *)(iVar12 + 0x130) + 1;
                *(int *)(iVar12 + 0x150) = *(int *)(iVar12 + 0x150) + 1;
                *(undefined1 *)(unaff_EBP + 0xb) = 1;
              }
              if ((*(int *)(iVar14 + 0x20) != 0) &&
                 ((*(int *)(unaff_EBP + -0x14) != 0 || (extraout_ECX[0x1f] != -1)))) {
                FUN_005c4870();
                fVar4 = (float)extraout_ECX[0xb];
                fVar5 = (float)_DAT_00667280;
                *(undefined4 *)(unaff_EBP + -4) = 2;
                if ((fVar5 <= fVar4) ||
                   ((*(int *)(iVar12 + 0x74) == 0 ||
                    ((*(int *)(unaff_EBP + -0x14) == 0 && (extraout_ECX[0x1f] == 0)))))) {
                  FUN_0058669c();
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
                else if ((_DAT_00666a4c < (float)extraout_ECX[0xb]) &&
                        (cVar11 = FUN_00593f39(), cVar11 != '\0')) {
                  FUN_005c4830();
                  *(undefined1 *)(unaff_EBP + -4) = 3;
                  FUN_005939a0(iVar12 + 0x3c,unaff_EBP + -0xbc);
                  FUN_0058669c();
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                  *(undefined1 *)(unaff_EBP + -4) = 2;
                  FUN_005c4890();
                }
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                goto LAB_005985fc;
              }
            }
            else {
              iVar14 = *(int *)(unaff_EBP + -0x10);
              if ((*(int *)(iVar14 + 0x1c) != 0) &&
                 ((*(int *)(unaff_EBP + -0x14) != 0 || (extraout_ECX[0x1e] != -1)))) {
                iVar18 = *(int *)(iVar14 + 0x24);
                iVar9 = *(int *)(*(int *)(iVar14 + 0x10) + 0x60);
                iVar17 = *(int *)(unaff_EBP + -0x18) + iVar18;
                iVar14 = iVar9 + iVar17 * 0xc;
                *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(iVar9 + iVar17 * 0xc);
                fVar4 = *(float *)(iVar14 + 8);
                *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(iVar14 + 4);
                iVar18 = iVar18 + *(int *)(unaff_EBP + -0x1c);
                puVar2 = (undefined4 *)(iVar9 + iVar18 * 0xc);
                fVar4 = *(float *)(iVar9 + 8 + iVar18 * 0xc) * *(float *)(unaff_EBP + -0x20) +
                        fVar4 * *(float *)(unaff_EBP + -0x24);
                *(undefined4 *)(unaff_EBP + -0x80) = *puVar2;
                *(undefined4 *)(unaff_EBP + -0x7c) = puVar2[1];
                pfVar1 = (float *)(extraout_ECX + 0xb);
                fVar5 = *(float *)(unaff_EBP + -0x7c) * *(float *)(unaff_EBP + -0x20) +
                        *(float *)(unaff_EBP + -0x70) * *(float *)(unaff_EBP + -0x24);
                *(float *)(unaff_EBP + -0x40) = fVar5;
                fVar3 = *(float *)(unaff_EBP + -0x74) * *(float *)(unaff_EBP + -0x24) +
                        *(float *)(unaff_EBP + -0x80) * *(float *)(unaff_EBP + -0x20);
                *(float *)(unaff_EBP + -0x38) = fVar3;
                if ((*pfVar1 < (float)_DAT_00667280) && (*(int *)(unaff_EBP + -0x14) != 0)) {
                  fVar5 = *pfVar1;
                  fVar3 = (float)_DAT_00667280;
                  *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(iVar12 + 0x30);
                  uVar13 = *(undefined4 *)(iVar12 + 0x34);
                  *(float *)(unaff_EBP + 8) = fVar3 - fVar5;
                  fVar5 = *(float *)(iVar12 + 0x38);
                  fVar3 = *pfVar1;
                  *(undefined4 *)(unaff_EBP + -0x88) = uVar13;
                  fVar4 = fVar5 * *(float *)(unaff_EBP + 8) + fVar4 * fVar3;
                  fVar5 = *(float *)(unaff_EBP + -0x88) * *(float *)(unaff_EBP + 8) +
                          *(float *)(unaff_EBP + -0x40) * *pfVar1;
                  fVar3 = *(float *)(unaff_EBP + -0x38) * *pfVar1 +
                          *(float *)(unaff_EBP + -0x8c) * *(float *)(unaff_EBP + 8);
                }
                *(float *)(iVar12 + 0x30) = fVar3;
                iVar14 = *(int *)(unaff_EBP + -0x10);
                *(undefined1 *)(unaff_EBP + 0xb) = 1;
                *(float *)(iVar12 + 0x34) = fVar5;
                *(float *)(iVar12 + 0x38) = fVar4;
                *(int *)(iVar12 + 0x130) = *(int *)(iVar12 + 0x130) + 1;
                *(int *)(iVar12 + 0x150) = *(int *)(iVar12 + 0x150) + 1;
              }
              if ((*(int *)(iVar14 + 0x20) != 0) &&
                 ((*(int *)(unaff_EBP + -0x14) != 0 || (extraout_ECX[0x1f] != -1)))) {
                *(int *)(unaff_EBP + -0x10) =
                     (*(int *)(*(int *)(unaff_EBP + -0x10) + 0x28) + *(int *)(unaff_EBP + -0x1c)) *
                     0x10 + *(int *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x10) + 0x68);
                FUN_005c4870();
                fVar4 = _DAT_00666a4c;
                *(undefined4 *)(unaff_EBP + -4) = 0;
                if ((fVar4 < *(float *)(unaff_EBP + -0x24)) &&
                   (cVar11 = FUN_00593f39(), cVar11 != '\0')) {
                  FUN_005939a0(*(undefined4 *)(unaff_EBP + -0x10),unaff_EBP + -0x5c);
                }
                if ((((float)_DAT_00667280 <= (float)extraout_ECX[0xb]) ||
                    (*(int *)(iVar12 + 0x74) == 0)) ||
                   ((*(int *)(unaff_EBP + -0x14) == 0 && (extraout_ECX[0x1f] == 0)))) {
                  FUN_0058669c();
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                }
                else if ((_DAT_00666a4c < (float)extraout_ECX[0xb]) &&
                        (cVar11 = FUN_00593f39(), cVar11 != '\0')) {
                  FUN_005c4830();
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  FUN_005939a0(iVar12 + 0x3c,unaff_EBP + -0xac);
                  FUN_0058669c();
                  *(undefined1 *)(unaff_EBP + -4) = 0;
                  *(undefined1 *)(unaff_EBP + 0xb) = 1;
                  FUN_005c4890();
                }
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_005985fc:
                FUN_005c4890();
              }
            }
            if (*(char *)(unaff_EBP + 0xb) != '\0') {
              *(int *)(*extraout_ECX + 0xa4) = *(int *)(*extraout_ECX + 0xa4) + 1;
              *(int *)(*extraout_ECX + 0xb4) = *(int *)(*extraout_ECX + 0xb4) + 1;
            }
          }
        }
        iVar14 = *(int *)(unaff_EBP + -0x30) + 1;
        *(int *)(unaff_EBP + -0x30) = iVar14;
      } while (iVar14 < *(int *)(unaff_EBP + -0x34));
    }
  }
  extraout_ECX[0xd] = extraout_ECX[0xc];
LAB_0059862d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

