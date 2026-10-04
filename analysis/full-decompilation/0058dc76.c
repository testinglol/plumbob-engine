
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058dc76(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  char cVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  int *extraout_ECX;
  int iVar16;
  uint uVar17;
  int unaff_EBP;
  int *piVar18;
  undefined4 uVar19;
  float10 fVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  
  FUN_00634c24();
  iVar12 = (**(code **)(*extraout_ECX + 0x34))();
  iVar15 = *extraout_ECX;
  *(int *)(unaff_EBP + -0x60) = iVar12;
  uVar13 = (**(code **)(iVar15 + 0x38))();
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar13;
  *(undefined1 *)(unaff_EBP + -0x1f) = DAT_006f6d20;
  iVar15 = extraout_ECX[0x4e];
  *(undefined1 *)(unaff_EBP + -0x1d) = 0;
  sVar5 = *(short *)(iVar15 + 0x6c);
  *(int *)(unaff_EBP + -0x24) = (int)*(short *)(iVar15 + 0x60c);
  extraout_ECX[0x2d] = iVar12;
  iVar15 = extraout_ECX[4];
  *(int *)(unaff_EBP + -0x34) = (int)sVar5;
  *(undefined1 *)(unaff_EBP + -0x1e) = 1;
  if ((iVar15 != 0) && (ABS(*(float *)(iVar15 + 0x2c)) <= _DAT_0067343c)) {
    FUN_005a0903();
    extraout_ECX[4] = 0;
  }
  FUN_005903a7();
  (**(code **)(*extraout_ECX + 0x58))();
  fVar20 = (float10)FUN_00588fd4();
  extraout_ECX[0x8b] = (int)(float)fVar20;
  pfVar1 = (float *)(extraout_ECX + 0x8a);
  if ((((float10)*pfVar1 < fVar20 - (float10)_DAT_006d07c0) ||
      (fVar20 + (float10)_DAT_006d07c0 < (float10)*pfVar1)) && ((float10)*pfVar1 < fVar20)) {
    fVar20 = (float10)_DAT_006d07c0 + (float10)*pfVar1;
  }
  *pfVar1 = (float)fVar20;
  cVar11 = FUN_00422665();
  if (cVar11 != '\0') {
LAB_0058f68c:
    puVar14 = (undefined4 *)(**(code **)(*extraout_ECX + 0x5c))();
    *(undefined4 *)(unaff_EBP + -0xa8) = *puVar14;
    *(undefined4 *)(unaff_EBP + -0xa4) = puVar14[1];
    *(undefined4 *)(unaff_EBP + -0xa0) = puVar14[2];
    *(undefined4 *)(unaff_EBP + -0x9c) = puVar14[3];
    if ((*(char *)(unaff_EBP + 8) == '\0') ||
       (cVar11 = (**(code **)(*extraout_ECX + 0x6c))(), cVar11 != '\0')) {
      extraout_ECX[0x1e] = 0;
      FUN_005a0d7d(extraout_ECX + 0xe,*(undefined4 *)(unaff_EBP + -0x60),1);
      *(undefined1 *)((int)extraout_ECX + 0x109) = 1;
    }
    else {
      uVar13 = *(undefined4 *)(unaff_EBP + -0x60);
      extraout_ECX[0x1e] = 0;
      FUN_005a0e85(extraout_ECX + 0xe,uVar13);
      *(undefined1 *)((int)extraout_ECX + 0x109) = 0;
    }
    if ((((*(char *)(unaff_EBP + -0x1f) == '\x01') && (extraout_ECX[3] != 0)) &&
        (extraout_ECX[0x62] == 1)) && (DAT_006f6b74 != extraout_ECX[0x4e])) {
      iVar15 = FUN_0046d8a7();
      iVar12 = FUN_004425e2();
      if ((iVar15 <= iVar12) &&
         ((iVar15 = extraout_ECX[100], iVar15 == 6 || ((7 < iVar15 && (iVar15 < 0xb)))))) {
        if (extraout_ECX[10] == 0) {
          extraout_ECX[9] = 0;
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          FUN_00595f4e();
          puVar14 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x104,unaff_EBP + -0x44);
          *(undefined4 *)(unaff_EBP + -0x44) = *puVar14;
          *(undefined4 *)(unaff_EBP + -0x40) = puVar14[1];
          *(undefined4 *)(unaff_EBP + -0x3c) = puVar14[2];
          *(undefined4 *)(unaff_EBP + -0x44) = 0;
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          piVar18 = (int *)FUN_005c3840(unaff_EBP + -0xf8,unaff_EBP + -0x44,extraout_ECX + 0xe);
          iVar15 = *piVar18;
          iVar12 = extraout_ECX[9];
          *(int *)(unaff_EBP + -0x44) = iVar15;
          iVar16 = piVar18[1];
          *(int *)(unaff_EBP + -0x40) = iVar16;
          *(int *)(unaff_EBP + -0x3c) = piVar18[2];
          if (iVar12 == 0) {
            extraout_ECX[6] = iVar15;
            extraout_ECX[7] = iVar16;
            extraout_ECX[8] = *(int *)(unaff_EBP + -0x3c);
            extraout_ECX[9] = 1;
          }
          else {
            FUN_0049b849(unaff_EBP + -0x8c,extraout_ECX + 6);
            fVar2 = _DAT_00666a54 / _DAT_00671ed4;
            *(float *)(unaff_EBP + -0x4c) = fVar2 * *(float *)(unaff_EBP + -0x84);
            fVar2 = fVar2 * *(float *)(unaff_EBP + -0x8c);
            fVar3 = *(float *)(unaff_EBP + -0x4c) * *(float *)(unaff_EBP + -0x4c) + fVar2 * fVar2;
            if ((fVar3 <= _DAT_0067201c) && (_DAT_00672018 < fVar3)) {
              extraout_ECX[0x20] = (int)(*(float *)(unaff_EBP + -0x4c) + (float)extraout_ECX[0x20]);
              extraout_ECX[0x21] = (int)(fVar2 + (float)extraout_ECX[0x21]);
              (**(code **)(*extraout_ECX + 0x60))();
            }
          }
        }
      }
    }
    FUN_004341a6();
    if ((*(char *)((int)extraout_ECX + 0x109) == '\0') && (*(char *)(unaff_EBP + 8) != '\0')) {
      *(undefined1 *)(unaff_EBP + -0x1e) = 0;
    }
    if (extraout_ECX[0x95] != (int)*(short *)(extraout_ECX[0x4e] + 0x5c8)) {
      *(undefined1 *)(unaff_EBP + -0x1e) = 1;
    }
    FUN_0058fafa();
    FUN_005992ca(extraout_ECX[0x2d],*(undefined1 *)(unaff_EBP + -0x1e),0);
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da();
    FUN_005a1444();
    FUN_0059076c();
    FUN_005904d6();
    FUN_00590b2b();
    (**(code **)(*extraout_ECX + 0x6c))();
    iVar15 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if ((*(int *)(iVar15 + 0x134) - *(int *)(iVar15 + 0x130)) / 0x24 + -1 < 2) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar15 + 0x130) + 0x48;
    }
    if (iVar12 != 0) {
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar12 + 0x20);
    }
    if ((*(int *)(iVar15 + 0x134) - *(int *)(iVar15 + 0x130)) / 0x24 + -1 < 2) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar15 + 0x130) + 0x48;
    }
    if (iVar12 == 0) {
      piVar18 = (int *)0x0;
    }
    else {
      uVar17 = (uint)*(short *)(iVar12 + 0x10);
      iVar15 = *(int *)(iVar15 + 0xdc);
      piVar18 = (int *)0x0;
      if ((0 < (int)uVar17) &&
         (uVar17 < (*(int *)(iVar15 + 0x1c) - *(int *)(iVar15 + 0x18) >> 2) + 1U)) {
        piVar18 = *(int **)(*(int *)(iVar15 + 0x18) + -4 + uVar17 * 4);
      }
    }
    if ((piVar18 != (int *)0x0) &&
       (piVar18 = (int *)(**(code **)(*piVar18 + 0x2c))(), *(int *)(unaff_EBP + 8) != 0)) {
      FUN_005c35b0();
      iVar15 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar15 = (**(code **)(iVar15 + 0xac))();
      if (iVar15 != 0) {
        FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
        *(undefined1 *)(unaff_EBP + -4) = 1;
        iVar15 = FUN_005990f7(unaff_EBP + -0x98);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        if (iVar15 != 0) {
          *(undefined4 *)(unaff_EBP + -0xac) = 0;
          *(undefined4 *)(unaff_EBP + -0xbc) = *(undefined4 *)(iVar15 + 0x4c);
          *(undefined4 *)(unaff_EBP + -0xac) = 0;
          uVar13 = *(undefined4 *)(iVar15 + 0x50);
          *(undefined4 *)(unaff_EBP + -0xac) = 0;
          *(undefined4 *)(unaff_EBP + -0xb8) = uVar13;
          *(undefined4 *)(unaff_EBP + -0xb4) = *(undefined4 *)(iVar15 + 0x54);
          uVar13 = (**(code **)(*extraout_ECX + 0xb0))();
          FUN_00462c01(uVar13);
        }
      }
      (**(code **)(*piVar18 + 0xac))();
      (**(code **)(*piVar18 + 100))(1);
      (**(code **)(*piVar18 + 0xb8))(unaff_EBP + -0xec);
      FUN_0045d283(3);
      iVar15 = __ftol();
      piVar18[0x40] = iVar15;
      (**(code **)(*piVar18 + 0x50))(0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005c4890();
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
code_r0x0058dd6b:
  uVar17 = extraout_ECX[100];
  *(undefined4 *)(unaff_EBP + -0x30) = 1;
  if (uVar17 < 0xd) {
    do {
      bVar7 = true;
      switch(*(undefined4 *)(&DAT_0058faa6 + uVar17 * 4)) {
      case 0x58dd84:
        if ((((float)extraout_ECX[0x20] == _DAT_00671edc) ||
            ((float)extraout_ECX[0x21] == _DAT_00671edc)) ||
           ((float)extraout_ECX[0x22] == _DAT_00671edc)) {
          (**(code **)(*extraout_ECX + 0x60))();
        }
        else {
          bVar6 = (float)extraout_ECX[0x73] < (float)_DAT_006669e8;
          while (bVar6) {
            fVar2 = (float)extraout_ECX[0x73] + (float)_DAT_0066f3c0;
            extraout_ECX[0x73] = (int)fVar2;
            bVar6 = fVar2 < (float)_DAT_006669e8;
          }
          bVar6 = (float)extraout_ECX[0x73] < (float)_DAT_0066f3c0;
          while (!bVar6) {
            fVar2 = (float)extraout_ECX[0x73];
            fVar3 = (float)_DAT_0066f3c0;
            extraout_ECX[0x73] = (int)(fVar2 - fVar3);
            bVar6 = fVar2 - fVar3 < (float)_DAT_0066f3c0;
          }
          bVar6 = (float)extraout_ECX[0x22] < (float)_DAT_006669e8;
          while (bVar6) {
            fVar2 = (float)extraout_ECX[0x22] + (float)_DAT_0066f3c0;
            extraout_ECX[0x22] = (int)fVar2;
            bVar6 = fVar2 < (float)_DAT_006669e8;
          }
          bVar6 = (float)extraout_ECX[0x22] < (float)_DAT_0066f3c0;
          while (fVar2 = _DAT_0067343c, !bVar6) {
            fVar2 = (float)extraout_ECX[0x22];
            fVar3 = (float)_DAT_0066f3c0;
            extraout_ECX[0x22] = (int)(fVar2 - fVar3);
            bVar6 = fVar2 - fVar3 < (float)_DAT_0066f3c0;
          }
          fVar8 = (float)extraout_ECX[0x73] - (float)extraout_ECX[0x22];
          bVar6 = ABS(fVar8) <= _DAT_0067343c;
          fVar3 = (float)extraout_ECX[0x71];
          fVar4 = (float)extraout_ECX[0x20];
          *(float *)(unaff_EBP + -0x10) = fVar3 - fVar4;
          if ((fVar2 < ABS(fVar3 - fVar4)) ||
             (fVar2 < ABS((float)extraout_ECX[0x72] - (float)extraout_ECX[0x21]))) {
            bVar7 = false;
          }
          if ((bVar6) && (bVar7)) {
            iVar15 = extraout_ECX[0x62];
            if (iVar15 != 0) {
              if (((iVar15 != -1) && (iVar15 != 2)) && (iVar15 != 3)) {
                extraout_ECX[100] = 9;
                break;
              }
              extraout_ECX[0x62] = 2;
            }
            goto code_r0x0058f11b;
          }
          fVar2 = (float)extraout_ECX[0x72];
          fVar3 = (float)extraout_ECX[0x21];
          *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x10);
          *(float *)(unaff_EBP + -0x10) = fVar2 - fVar3;
          if (bVar7) {
            fVar2 = 0.0;
          }
          else {
            fVar2 = SQRT(*(float *)(unaff_EBP + -0x4c) * *(float *)(unaff_EBP + -0x4c) +
                         *(float *)(unaff_EBP + -0x10) * *(float *)(unaff_EBP + -0x10));
          }
          *(float *)(unaff_EBP + -0x18) = fVar2;
          if (bVar6) {
            fVar8 = 0.0;
          }
          else {
            for (; _DAT_00668318 <= fVar8; fVar8 = fVar8 - _DAT_0066c7bc) {
            }
            for (; fVar8 < _DAT_00672024; fVar8 = fVar8 + _DAT_0066c7bc) {
            }
          }
          fVar2 = fRam006d0794 * _DAT_00666a48;
          *(float *)(unaff_EBP + -0x58) = fRam006d0788;
          *(float *)(unaff_EBP + -0x70) = fRam006d07bc;
          fVar2 = fVar2 / (float)extraout_ECX[0x8a];
          if (1 < *(short *)(extraout_ECX[0x4e] + 0x60e)) {
            fVar2 = (fRam006d0794 * _DAT_00667278) / (float)extraout_ECX[0x8a];
            *(float *)(unaff_EBP + -0x58) = fRam006d0788 * _UNK_006693ec;
            *(float *)(unaff_EBP + -0x70) = fRam006d07bc * _DAT_0066d72c;
          }
          if ((fVar2 <= fVar8) || (fVar8 <= -fVar2)) {
code_r0x0058f4f2:
            uVar13 = 5;
            if (-fRam006d07a4 <= fVar8) {
              if (fVar8 <= fRam006d07a4) {
                if (fVar8 < -fRam006d079c) {
                  if (fRam006d079c < fVar8) goto code_r0x0058f605;
                  if (fVar8 <= fRam006d07a0) {
                    if (fVar8 < -fRam006d07a0) {
                      if (-fRam006d07a0 <= fVar8) goto code_r0x0058f552;
                      extraout_ECX[0x7d] = -0x40000000;
                      uVar13 = 7;
                    }
                    else {
                      extraout_ECX[0x7d] = -0x40800000;
                      uVar13 = 9;
                    }
                    goto code_r0x0058f55d;
                  }
code_r0x0058f625:
                  extraout_ECX[0x7d] = 0x40000000;
                  uVar13 = 6;
                }
                else {
                  if (fRam006d079c < fVar8) {
code_r0x0058f605:
                    if (fRam006d07a0 < fVar8) goto code_r0x0058f625;
                    uVar13 = 8;
                    iVar15 = 0x3f800000;
                  }
                  else {
code_r0x0058f552:
                    uVar13 = 10;
                    iVar15 = 0;
                  }
                  extraout_ECX[0x7d] = iVar15;
                }
              }
              else {
                extraout_ECX[0x7d] = 0x40800000;
                uVar13 = 4;
              }
            }
            else {
              extraout_ECX[0x7d] = -0x3f800000;
            }
code_r0x0058f55d:
            extraout_ECX[0x7c] = (int)fVar8;
            extraout_ECX[0x79] = extraout_ECX[0x73];
            DAT_006f6d1c = 2;
            extraout_ECX[0x77] = extraout_ECX[0x71];
            extraout_ECX[0x78] = extraout_ECX[0x72];
            extraout_ECX[0x76] = extraout_ECX[0x22];
            extraout_ECX[0x73] =
                 (int)(((float)extraout_ECX[0x7c] - (float)extraout_ECX[0x7d]) +
                      (float)extraout_ECX[0x22]);
            extraout_ECX[0x74] = extraout_ECX[0x20];
            extraout_ECX[0x75] = extraout_ECX[0x21];
            (**(code **)(*extraout_ECX + 0xf8))(uVar13);
            FUN_0059863e();
            FUN_00598687();
            extraout_ECX[100] = 4;
          }
          else {
            if (*(float *)(unaff_EBP + -0x18) < *(float *)(unaff_EBP + -0x70)) {
              extraout_ECX[0x20] = extraout_ECX[0x71];
              extraout_ECX[0x21] = extraout_ECX[0x72];
              (**(code **)(*extraout_ECX + 0xd0))();
              DAT_006f6d14 = 4;
              FUN_005920ac();
              break;
            }
            if (*(float *)(unaff_EBP + -0x58) <= *(float *)(unaff_EBP + -0x18))
            goto code_r0x0058f4f2;
            fVar20 = (float10)fpatan((float10)*(float *)(unaff_EBP + -0x10),
                                     (float10)*(float *)(unaff_EBP + -0x4c));
            *(float *)(unaff_EBP + -0x5c) = (float)fVar20;
            fVar20 = fVar20 / ((float10)_DAT_00671ed8 + (float10)_DAT_00671ed8) +
                     (float10)_DAT_00667278;
            *(float *)(unaff_EBP + -0x58) = (float)fVar20;
            fVar20 = (float10)FUN_006369f9((double)fVar20);
            FUN_006369f9((double)(((float10)*(float *)(unaff_EBP + -0x58) - fVar20) *
                                 (float10)_DAT_0066c7bc));
            uVar13 = __ftol();
            uVar19 = 0xffffffff;
            switch(uVar13) {
            case 0:
              uVar19 = 0xf;
              break;
            case 1:
              uVar19 = 0xd;
              break;
            case 2:
              uVar19 = 0xb;
              break;
            case 3:
              uVar19 = 0xc;
              break;
            case 4:
              uVar19 = 0xe;
              break;
            case 5:
              uVar19 = 0x10;
              break;
            case 6:
              uVar19 = 0x12;
              break;
            case 7:
              uVar19 = 0x11;
            }
            iVar15 = *extraout_ECX;
            *(undefined4 *)(unaff_EBP + -0x28) = 0;
            *(undefined4 *)(unaff_EBP + -0x24) = 0;
            *(undefined4 *)(unaff_EBP + -0x6c) = 0;
            (**(code **)(iVar15 + 0x124))(uVar19,unaff_EBP + -0x28,unaff_EBP + -0x24);
            (**(code **)(*extraout_ECX + 0xd0))(extraout_ECX[0x73]);
            DAT_006f6d14 = 5;
            FUN_005920ac();
            fVar20 = (float10)fcos((float10)*(float *)(unaff_EBP + -0x5c));
            extraout_ECX[0x79] = extraout_ECX[0x73];
            DAT_006f6d1c = 5;
            extraout_ECX[0x77] = extraout_ECX[0x71];
            extraout_ECX[0x78] = extraout_ECX[0x72];
            extraout_ECX[0x76] = extraout_ECX[0x22];
            extraout_ECX[0x74] = extraout_ECX[0x20];
            extraout_ECX[0x75] = extraout_ECX[0x21];
            fVar22 = (float10)fsin((float10)*(float *)(unaff_EBP + -0x5c));
            extraout_ECX[0x71] =
                 (int)(float)((float10)(float)extraout_ECX[0x71] -
                             (fVar20 * (float10)*(float *)(unaff_EBP + -0x28) +
                             fVar22 * (float10)*(float *)(unaff_EBP + -0x24)));
            extraout_ECX[0x72] =
                 (int)(float)((float10)(float)extraout_ECX[0x72] -
                             (fVar22 * (float10)*(float *)(unaff_EBP + -0x28) +
                             fVar20 * (float10)*(float *)(unaff_EBP + -0x24)));
            fVar3 = fRam006d07b8;
            fVar2 = fRam006d07b8;
            if ((float)_DAT_00668348 <= *(float *)(unaff_EBP + -0x18)) {
              if ((float)_DAT_00667280 <= *(float *)(unaff_EBP + -0x18)) {
                fVar2 = 1.0;
                goto code_r0x0058f481;
              }
              fVar2 = *(float *)(unaff_EBP + -0x18) /
                      SQRT(*(float *)(unaff_EBP + -0x28) * *(float *)(unaff_EBP + -0x28) +
                           *(float *)(unaff_EBP + -0x24) * *(float *)(unaff_EBP + -0x24));
              *(float *)(unaff_EBP + -0x1c) = fVar2;
            }
            else {
code_r0x0058f481:
              *(float *)(unaff_EBP + -0x1c) = fVar2;
            }
            if (fVar2 < fVar3) {
              *(float *)(unaff_EBP + -0x1c) = fVar3;
            }
            (**(code **)(*extraout_ECX + 0xf8))(uVar19,0);
            FUN_0059863e();
            *(undefined4 *)(extraout_ECX[3] + 0x2c) = *(undefined4 *)(unaff_EBP + -0x1c);
            extraout_ECX[100] = 5;
          }
        }
        goto LAB_0058f68c;
      case 0x58e049:
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        extraout_ECX[10] = 0;
        extraout_ECX[9] = 0;
        iVar15 = extraout_ECX[3];
        fVar2 = *(float *)(iVar15 + 0x28);
        bVar7 = fVar2 < _DAT_00666748;
        *(float *)(unaff_EBP + -0x14) = fVar2;
        if (bVar7) {
          iVar15 = *extraout_ECX;
          *(float *)(unaff_EBP + -0x10) = 1.0 - fVar2;
          (**(code **)(iVar15 + 0xd0))();
          DAT_006f6d14 = 0x10;
          FUN_005920ac();
          extraout_ECX[0x20] =
               (int)(*(float *)(unaff_EBP + -0x14) * (float)extraout_ECX[0x71] +
                    *(float *)(unaff_EBP + -0x10) * (float)extraout_ECX[0x74]);
          fVar3 = *(float *)(unaff_EBP + -0x10) * (float)extraout_ECX[0x75];
          fVar2 = *(float *)(unaff_EBP + -0x14);
          goto code_r0x0058f1a3;
        }
        *(undefined4 *)(iVar15 + 0x78) = 0xffffffff;
        *(undefined4 *)(extraout_ECX[3] + 0x7c) = 0xffffffff;
        extraout_ECX[0x68] = 1;
code_r0x0058e0b6:
        (**(code **)(*extraout_ECX + 0xfc))();
        extraout_ECX[100] = 3;
        (**(code **)(*extraout_ECX + 0xd0))();
        DAT_006f6d14 = 9;
        FUN_005920ac();
        extraout_ECX[0x73] = extraout_ECX[0x22];
        DAT_006f6d18 = 9;
        extraout_ECX[0x20] = extraout_ECX[0x77];
        extraout_ECX[0x71] = extraout_ECX[0x77];
        extraout_ECX[0x21] = extraout_ECX[0x78];
        extraout_ECX[0x72] = extraout_ECX[0x78];
        break;
      case 0x58e088:
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        extraout_ECX[10] = 0;
        extraout_ECX[9] = 0;
        fVar2 = *(float *)(extraout_ECX[3] + 0x28);
        if (_DAT_00666748 <= fVar2) {
          *(undefined4 *)(extraout_ECX[3] + 0x2c) = 0;
          goto code_r0x0058e0b6;
        }
        *(float *)(unaff_EBP + -0x14) = fVar2;
        iVar15 = *extraout_ECX;
        *(float *)(unaff_EBP + -0x10) = 1.0 - fVar2;
        (**(code **)(iVar15 + 0xd0))();
        DAT_006f6d14 = 0xf;
        FUN_005920ac();
        extraout_ECX[0x20] =
             (int)(*(float *)(unaff_EBP + -0x14) * (float)extraout_ECX[0x71] +
                  *(float *)(unaff_EBP + -0x10) * (float)extraout_ECX[0x74]);
        fVar3 = *(float *)(unaff_EBP + -0x10) * (float)extraout_ECX[0x75];
        fVar2 = *(float *)(unaff_EBP + -0x14);
code_r0x0058f1a3:
        extraout_ECX[0x21] = (int)(fVar2 * (float)extraout_ECX[0x72] + fVar3);
        goto code_r0x0058f0e5;
      case 0x58e129:
        if (extraout_ECX[0x26] != 0x13) {
          (**(code **)(*extraout_ECX + 0xf8))(0x13);
          fVar20 = (float10)FUN_00588fd4();
          extraout_ECX[0x8a] = (int)(float)fVar20;
          extraout_ECX[0x8b] = (int)(float)fVar20;
          FUN_0059863e();
          fVar21 = (float10)*(float *)(*(int *)(extraout_ECX[3] + 4) + 0x30) *
                   (float10)_DAT_00668390 * (float10)_DAT_00666a54;
          fVar20 = (float10)_DAT_00666cbc;
          fVar22 = (float10)_DAT_00667430;
          fVar23 = (float10)DAT_00673438;
          extraout_ECX[0x75] = extraout_ECX[0x21];
          fVar20 = ((float10)(float)extraout_ECX[0x22] + fVar20) * fVar22 * fVar23 *
                   (float10)_DAT_0066742c;
          fVar22 = (float10)fcos(fVar20);
          *(float *)(unaff_EBP + -0x14) = (float)fVar22;
          fVar20 = (float10)fsin(fVar20);
          extraout_ECX[0x74] = extraout_ECX[0x20];
          extraout_ECX[0x71] =
               (int)(float)((float10)*(float *)(unaff_EBP + -0x14) * fVar21 +
                           (float10)(float)extraout_ECX[0x20]);
          extraout_ECX[0x72] = (int)(float)(fVar20 * fVar21 + (float10)(float)extraout_ECX[0x75]);
        }
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        *(int *)(unaff_EBP + -0x78) = extraout_ECX[0x8a];
        FUN_0059863e();
        fVar2 = *(float *)(extraout_ECX[3] + 0x28);
        if (fVar2 < _UNK_00672020) goto code_r0x0058f223;
        (**(code **)(*extraout_ECX + 0xfc))();
        extraout_ECX[0x20] = extraout_ECX[0x71];
        extraout_ECX[0x21] = extraout_ECX[0x72];
        extraout_ECX[0x73] = extraout_ECX[0x22];
        DAT_006f6d18 = 10;
        extraout_ECX[100] = 9;
code_r0x0058e4a2:
        extraout_ECX[0x67] = 1;
        extraout_ECX[0xa4] = 1;
        break;
      case 0x58e255:
        iVar15 = extraout_ECX[3];
        if ((iVar15 == 0) || (*(int *)(iVar15 + 0x3c) != 0)) {
          fVar2 = 1.0;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0x3f800000;
        }
        else {
          fVar2 = *(float *)(iVar15 + 0x28);
          *(float *)(unaff_EBP + -0x1c) = fVar2;
          if (*(float *)(iVar15 + 0x24) < (float)_DAT_006669e8) {
            fVar2 = 1.0 - fVar2;
            *(float *)(unaff_EBP + -0x1c) = fVar2;
          }
        }
        bVar7 = _DAT_00666748 <= fVar2;
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        extraout_ECX[10] = 0;
        extraout_ECX[9] = 0;
        if ((bVar7) || (ABS(*(float *)(extraout_ECX[3] + 0x24)) <= _DAT_0067343c)) {
          *(undefined4 *)(extraout_ECX[3] + 0x78) = 0xffffffff;
          *(undefined4 *)(extraout_ECX[3] + 0x7c) = 0xffffffff;
          extraout_ECX[0x68] = 1;
          (**(code **)(*extraout_ECX + 0xfc))();
          extraout_ECX[100] = 3;
          (**(code **)(*extraout_ECX + 0xd0))();
          DAT_006f6d14 = 0xb;
          FUN_005920ac();
          extraout_ECX[0x73] = extraout_ECX[0x22];
          iVar15 = extraout_ECX[0xa2];
          DAT_006f6d18 = 0xb;
          extraout_ECX[0x20] = extraout_ECX[0x77];
          extraout_ECX[0x71] = extraout_ECX[0x77];
          extraout_ECX[0x21] = extraout_ECX[0x78];
          extraout_ECX[0x72] = extraout_ECX[0x78];
          if (iVar15 == 1) {
            extraout_ECX[0x62] = -1;
          }
          else if (iVar15 == 2) {
            extraout_ECX[0x62] = 2;
          }
          else if (iVar15 == 3) {
            extraout_ECX[0x62] = 3;
          }
          break;
        }
        *(float *)(unaff_EBP + -0x14) = 1.0 - fVar2;
        for (fVar2 = (float)extraout_ECX[0x73] - (float)extraout_ECX[0x76]; _DAT_00668318 <= fVar2;
            fVar2 = fVar2 - _DAT_0066c7bc) {
        }
        for (; fVar2 < _DAT_00672024; fVar2 = fVar2 + _DAT_0066c7bc) {
        }
        (**(code **)(*extraout_ECX + 0xd0))();
        DAT_006f6d14 = 0xb;
        FUN_005920ac();
        extraout_ECX[0x20] =
             (int)(*(float *)(unaff_EBP + -0x1c) * (float)extraout_ECX[0x71] +
                  *(float *)(unaff_EBP + -0x14) * (float)extraout_ECX[0x74]);
        extraout_ECX[0x21] =
             (int)(*(float *)(unaff_EBP + -0x1c) * (float)extraout_ECX[0x72] +
                  *(float *)(unaff_EBP + -0x14) * (float)extraout_ECX[0x75]);
        goto code_r0x0058f308;
      case 0x58e37b:
        if (extraout_ECX[0x26] != 0x16) {
          (**(code **)(*extraout_ECX + 0xf8))(0x16);
          fVar20 = (float10)FUN_00588fd4();
          extraout_ECX[0x8a] = (int)(float)fVar20;
          extraout_ECX[0x8b] = (int)(float)fVar20;
          FUN_0059863e();
          fVar21 = (float10)*(float *)(*(int *)(extraout_ECX[3] + 4) + 0x30) *
                   (float10)_DAT_00668390 * (float10)_DAT_00666a54;
          fVar20 = (float10)_DAT_00666cbc;
          fVar22 = (float10)_DAT_00667430;
          fVar23 = (float10)DAT_00673438;
          extraout_ECX[0x75] = extraout_ECX[0x21];
          fVar20 = ((float10)(float)extraout_ECX[0x22] + fVar20) * fVar22 * fVar23 *
                   (float10)_DAT_0066742c;
          fVar22 = (float10)fcos(fVar20);
          *(float *)(unaff_EBP + -0x14) = (float)fVar22;
          fVar20 = (float10)fsin(fVar20);
          extraout_ECX[0x74] = extraout_ECX[0x20];
          extraout_ECX[0x71] =
               (int)(float)((float10)*(float *)(unaff_EBP + -0x14) * fVar21 +
                           (float10)(float)extraout_ECX[0x20]);
          extraout_ECX[0x72] = (int)(float)(fVar20 * fVar21 + (float10)(float)extraout_ECX[0x75]);
        }
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        *(int *)(unaff_EBP + -0x80) = extraout_ECX[0x8a];
        FUN_0059863e();
        fVar2 = *(float *)(extraout_ECX[3] + 0x28);
        if (_UNK_00672020 <= fVar2) {
          (**(code **)(*extraout_ECX + 0xfc))();
          extraout_ECX[0x20] = extraout_ECX[0x71];
          extraout_ECX[0x21] = extraout_ECX[0x72];
          extraout_ECX[0x73] = extraout_ECX[0x22];
          DAT_006f6d18 = 0xc;
          extraout_ECX[100] = 10;
          goto code_r0x0058e4a2;
        }
code_r0x0058f223:
        extraout_ECX[0x20] =
             (int)(fVar2 * (float)extraout_ECX[0x71] + (1.0 - fVar2) * (float)extraout_ECX[0x74]);
        extraout_ECX[0x21] =
             (int)(fVar2 * (float)extraout_ECX[0x72] + (1.0 - fVar2) * (float)extraout_ECX[0x75]);
        goto code_r0x0058f308;
      case 0x58e4b3:
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        extraout_ECX[10] = 0;
        extraout_ECX[9] = 0;
        if ((extraout_ECX[3] != 0) && (*(int *)(extraout_ECX[3] + 0x68) == 0))
        goto code_r0x0058f0e5;
        extraout_ECX[100] = 3;
        break;
      case 0x58e4e4:
        piVar18 = (int *)extraout_ECX[0x61];
        iVar15 = extraout_ECX[0x4e];
        iVar12 = piVar18[1];
        iVar16 = *piVar18;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        sVar5 = *(short *)(iVar15 + 0x5c);
        iVar15 = iVar12 - iVar16 >> 3;
        *(int *)(unaff_EBP + -100) = iVar15;
        *(int *)(unaff_EBP + -0x68) = (int)sVar5;
        *(int *)(unaff_EBP + -0x50) = iVar15 + -2;
        while( true ) {
          iVar15 = extraout_ECX[0x60];
          iVar12 = *piVar18;
          iVar16 = iVar15 * 8;
          fVar4 = (float)*(int *)(iVar16 + 4 + iVar12);
          fVar8 = (float)*(int *)(iVar16 + iVar12);
          fVar2 = fVar8;
          fVar3 = fVar4;
          if (iVar15 != 0) {
            fVar2 = (float)*(int *)(iVar16 + -8 + iVar12);
            fVar3 = (float)*(int *)(iVar16 + -4 + iVar12);
          }
          *(float *)(unaff_EBP + -0x2c) =
               SQRT((fVar4 - fVar3) * (fVar4 - fVar3) + (fVar8 - fVar2) * (fVar8 - fVar2));
          fVar9 = fVar4 - (float)extraout_ECX[0x20];
          *(float *)(unaff_EBP + -0x10) = fVar9;
          fVar10 = fVar8 - (float)extraout_ECX[0x21];
          *(float *)(unaff_EBP + -0x30) = fVar10;
          *(float *)(unaff_EBP + -0x18) = SQRT(fVar9 * fVar9 + fVar10 * fVar10);
          if (iVar15 == *(int *)(unaff_EBP + -0x50)) break;
          if ((extraout_ECX[3] == 0) || (*(int *)(extraout_ECX[3] + 0x68) != 0)) {
            extraout_ECX[100] = 10 - (uint)(*(int *)(unaff_EBP + -0x34) != 1);
          }
          if (_DAT_0067343c < ABS(*(float *)(unaff_EBP + -0x2c))) {
            fVar9 = fRam006d0780 / *(float *)(unaff_EBP + -0x2c);
          }
          else {
            fVar9 = 1.0;
          }
          *(float *)(unaff_EBP + -0x30) = fVar9;
          fVar3 = fVar3 - fVar4;
          fVar2 = fVar2 - fVar8;
          *(float *)(unaff_EBP + -0x1c) = (float)extraout_ECX[0x20] - fVar4;
          *(float *)(unaff_EBP + -0x14) = (float)extraout_ECX[0x21] - fVar8;
          fVar4 = fVar3 * fVar3 + fVar2 * fVar2;
          *(float *)(unaff_EBP + -0x10) = fVar4;
          if (fVar4 <= _DAT_0066657c) {
            extraout_ECX[0x7b] = 0;
          }
          else {
            extraout_ECX[0x7b] =
                 (int)(_DAT_00666748 -
                      (*(float *)(unaff_EBP + -0x1c) * fVar3 + *(float *)(unaff_EBP + -0x14) * fVar2
                      ) / *(float *)(unaff_EBP + -0x10));
          }
          if (_DAT_0066657c <= (float)extraout_ECX[0x7b]) {
            if ((float)extraout_ECX[0x7b] <= _DAT_00666748) goto code_r0x0058e716;
            fVar2 = 1.0;
          }
          else {
            fVar2 = 0.0;
          }
          while( true ) {
            extraout_ECX[0x7b] = (int)fVar2;
code_r0x0058e716:
            if ((*(float *)(unaff_EBP + -0x2c) <= (float)_DAT_006669e8) ||
               ((float)_DAT_00667280 <= (float)extraout_ECX[0x7b])) break;
            uVar13 = __ftol();
            *(undefined4 *)(unaff_EBP + -0x3c) = uVar13;
            uVar13 = __ftol();
            *(undefined4 *)(unaff_EBP + -0x40) = uVar13;
            *(float *)(unaff_EBP + -0x48) =
                 (float)*(int *)(unaff_EBP + -0x3c) - (float)extraout_ECX[0x20];
            *(float *)(unaff_EBP + -0x38) =
                 (float)*(int *)(unaff_EBP + -0x40) - (float)extraout_ECX[0x21];
            if (*(int *)(unaff_EBP + -0x34) == 0) {
              fVar2 = (float)extraout_ECX[0x80];
            }
            else {
              fVar2 = (float)extraout_ECX[0x7f];
            }
            fVar2 = fVar2 * _DAT_00666578;
            fVar3 = *(float *)(unaff_EBP + -0x48) * *(float *)(unaff_EBP + -0x48) +
                    *(float *)(unaff_EBP + -0x38) * *(float *)(unaff_EBP + -0x38);
            *(float *)(unaff_EBP + -0x18) = fVar3;
            if (fVar2 * fVar2 <= fVar3) goto code_r0x0058eb35;
            fVar2 = *(float *)(unaff_EBP + -0x30) + (float)extraout_ECX[0x7b];
          }
          extraout_ECX[0x7b] = 0;
          extraout_ECX[0x60] = iVar15 + 1;
        }
        iVar15 = *piVar18;
        *(float *)(unaff_EBP + -0x2c) =
             (float)*(int *)(*(int *)(unaff_EBP + -100) * 8 + -0xc + iVar15);
        *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(iVar15 + *(int *)(unaff_EBP + -0x50) * 8);
        fVar22 = (float10)(**(code **)(*extraout_ECX + 0x98))();
        fVar20 = (float10)_DAT_0066c7bc;
        fVar23 = (float10)_DAT_00671ed8 + (float10)_DAT_00671ed8;
        *(float *)(unaff_EBP + -100) = (float)fVar23;
        for (fVar20 = (fVar22 * fVar20) / fVar23 + (float10)_DAT_0066740c;
            fVar20 < (float10)_DAT_006669e8; fVar20 = fVar20 + (float10)_DAT_0066f3c0) {
        }
        for (; (float10)_DAT_0066f3c0 <= fVar20; fVar20 = fVar20 - (float10)_DAT_0066f3c0) {
        }
        if (*(int *)(unaff_EBP + -0x68) == 0) {
          iVar15 = extraout_ECX[0x70];
          if (iVar15 == 0) {
            iVar15 = extraout_ECX[3];
            if (iVar15 == 0) {
              fVar2 = 0.0;
            }
            else {
              fVar2 = *(float *)(iVar15 + 0x28);
            }
            *(float *)(unaff_EBP + -0x50) = fVar2;
            if ((fVar2 < (float)extraout_ECX[0x5d]) ||
               ((float)extraout_ECX[0x5c] <= *(float *)(unaff_EBP + -0x50))) {
              *(int *)(unaff_EBP + -0x28) = extraout_ECX[0x5e];
              *(undefined4 *)(unaff_EBP + -0x14) = 1;
            }
            else {
              iVar12 = extraout_ECX[0x5f];
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
              *(int *)(unaff_EBP + -0x28) = iVar12;
            }
            if ((*(int *)(unaff_EBP + -0x24) == 0) && (*(int *)(unaff_EBP + -0x34) == 1)) {
              *(float *)(unaff_EBP + -0x28) =
                   *(float *)(unaff_EBP + -0x28) + *(float *)(unaff_EBP + -0x28);
            }
            if (*(float *)(unaff_EBP + -0x18) <= *(float *)(unaff_EBP + -0x28)) {
              if (*(int *)(unaff_EBP + -0x24) != 0) {
                extraout_ECX[0xa2] = 1;
                goto code_r0x0058e940;
              }
              extraout_ECX[0xa2] = 1;
              if (((iVar15 == 0) || (*(int *)(iVar15 + 0x68) != 0)) ||
                 (iVar15 = (**(code **)(*extraout_ECX + 0x108))(), iVar15 != 0)) {
                iVar15 = extraout_ECX[3];
                iVar12 = __ftol();
                if (iVar12 < iRam006d07ac) {
                  iVar12 = iRam006d07ac;
                }
                iVar16 = *(int *)(unaff_EBP + -0x60);
                extraout_ECX[0x70] = iVar12 + iVar16;
                if (iVar15 != 0) {
                  *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(iVar15 + 0x2c);
                  func_0x00597a46(iVar16,iVar12,*(undefined4 *)(unaff_EBP + -0x7c));
                }
              }
            }
          }
          else {
            if ((0 < iVar15) &&
               (((*(int *)(unaff_EBP + -0x34) == 1 || (*(float *)(unaff_EBP + -0x18) < fRam006d07b0)
                 ) || (iVar15 <= *(int *)(unaff_EBP + -0x60))))) {
              extraout_ECX[0x70] = -1;
              extraout_ECX[0xa3] = 0;
              extraout_ECX[0xa4] = 0;
            }
            if (extraout_ECX[0x70] < 0) {
              iVar15 = *(int *)(unaff_EBP + -0x2c);
              extraout_ECX[0x62] = -1;
              extraout_ECX[0x71] = iVar15;
              extraout_ECX[0x20] = iVar15;
              iVar15 = *(int *)(unaff_EBP + -0x1c);
              extraout_ECX[0x70] = 0;
              extraout_ECX[0xa3] = 0;
              extraout_ECX[0x72] = iVar15;
              extraout_ECX[0x21] = iVar15;
              extraout_ECX[0x73] = (int)(float)fVar20;
              extraout_ECX[100] = 3;
              extraout_ECX[0xa4] = 0;
              extraout_ECX[0x7b] = 0x3f800000;
              (**(code **)(*extraout_ECX + 0xfc))();
              break;
            }
          }
code_r0x0058eb0e:
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x10);
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x30);
          *(float *)(unaff_EBP + -0x18) =
               *(float *)(unaff_EBP + -0x10) * *(float *)(unaff_EBP + -0x10) +
               *(float *)(unaff_EBP + -0x30) * *(float *)(unaff_EBP + -0x30);
code_r0x0058eb35:
          if (ABS(*(float *)(unaff_EBP + -0x18)) <= _DAT_0067343c) goto LAB_0058f68c;
          fVar22 = (float10)(**(code **)(*extraout_ECX + 0x98))();
          fVar20 = (float10)_DAT_0066c7bc;
          fVar23 = (float10)_DAT_00671ed8 + (float10)_DAT_00671ed8;
          *(float *)(unaff_EBP + -0x68) = (float)fVar23;
          fVar22 = (fVar22 * fVar20) / fVar23 + (float10)_DAT_0066740c;
          fVar20 = (float10)_DAT_006669e8;
          *(float *)(unaff_EBP + -0x10) = (float)fVar22;
          if (fVar22 < fVar20) {
            do {
              fVar22 = fVar22 + (float10)_DAT_0066f3c0;
            } while (fVar22 < (float10)_DAT_006669e8);
            *(float *)(unaff_EBP + -0x10) = (float)fVar22;
          }
          if ((float10)_DAT_0066f3c0 <= fVar22) {
            do {
              fVar22 = fVar22 - (float10)_DAT_0066f3c0;
            } while ((float10)_DAT_0066f3c0 <= fVar22);
            *(float *)(unaff_EBP + -0x10) = (float)fVar22;
          }
          for (fVar22 = fVar22 - (float10)(float)extraout_ECX[0x22];
              (float10)_DAT_00668318 <= fVar22; fVar22 = fVar22 - (float10)_DAT_0066c7bc) {
          }
          for (; fVar22 < (float10)_DAT_00672024; fVar22 = fVar22 + (float10)_DAT_0066c7bc) {
          }
          fVar20 = (float10)fRam006d078c;
          pfVar1 = (float *)(extraout_ECX + 0x8a);
          if ((float)extraout_ECX[0x8a] < (float)_DAT_00667280) {
            fVar20 = fVar20 / (float10)*pfVar1;
          }
          sVar5 = *(short *)(extraout_ECX[0x4e] + 0x60e);
          if (1 < sVar5) {
            fVar20 = (float10)_DAT_00667454;
          }
          if ((fVar20 <= fVar22) || (fVar22 <= -fVar20)) {
            extraout_ECX[0x71] = extraout_ECX[0x20];
            extraout_ECX[0x72] = extraout_ECX[0x21];
            extraout_ECX[0x73] = *(int *)(unaff_EBP + -0x10);
            extraout_ECX[100] = 3;
            extraout_ECX[0x67] = 0;
          }
          else {
            bVar7 = false;
            *(undefined4 *)(unaff_EBP + -0x54) = uRam006d0790;
            if (1 < sVar5) {
              *(undefined4 *)(unaff_EBP + -0x54) = 0x3d6978d5;
            }
            if (*pfVar1 < (float)_DAT_00667280) {
              *(float *)(unaff_EBP + -0x54) = *(float *)(unaff_EBP + -0x54) / *pfVar1;
            }
            *(float *)(unaff_EBP + -0x14) = -*(float *)(unaff_EBP + -0x54);
            if ((fVar22 < (float10)*(float *)(unaff_EBP + -0x14)) ||
               ((float10)*(float *)(unaff_EBP + -0x54) < fVar22)) {
              bVar7 = true;
            }
            (**(code **)(*extraout_ECX + 0xd0))();
            DAT_006f6d14 = 3;
            FUN_005920ac();
            if (*(int *)(unaff_EBP + -0x34) == 1) {
              fVar2 = (float)extraout_ECX[0x81];
            }
            else {
              fVar2 = (float)extraout_ECX[0x7e];
            }
            if (((((extraout_ECX[0xa3] != 0) || (extraout_ECX[0x67] != 0)) ||
                 (extraout_ECX[0x26] == 0x15)) || (extraout_ECX[0x26] == 0x14)) ||
               ((*(int *)(unaff_EBP + -0x24) == 0 &&
                ((bVar7 || (*(float *)(unaff_EBP + -0x18) <= fVar2 * fVar2)))))) {
              extraout_ECX[0x67] = 1;
              if ((extraout_ECX[100] == 10) && (*(int *)(unaff_EBP + -0x34) == 0)) {
                extraout_ECX[100] = 9;
              }
              uVar13 = 0;
              if (extraout_ECX[100] == 9) {
                uVar13 = 0x14;
              }
              else if (extraout_ECX[100] == 10) {
                uVar13 = 0x15;
              }
              iVar15 = extraout_ECX[3];
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
              if ((iVar15 != 0) && (*(int *)(*(int *)(iVar15 + 4) + 0x34) != 0)) {
                *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar15 + 0x28);
              }
              (**(code **)(*extraout_ECX + 0xf8))(uVar13);
              FUN_0059863e();
              fVar2 = *(float *)(unaff_EBP + -0x38);
              *(undefined4 *)(extraout_ECX[3] + 0x28) = *(undefined4 *)(unaff_EBP + -0x14);
code_r0x0058edf0:
              extraout_ECX[0xa4] = 1;
              iVar15 = *(int *)(extraout_ECX[3] + 4);
              fVar3 = *(float *)(extraout_ECX[3] + 0x24);
              fVar4 = *(float *)(iVar15 + 0x2c);
              *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(iVar15 + 0x30);
              fVar3 = (*(float *)(unaff_EBP + -0x74) * _DAT_00668390 * _DAT_00666a54) /
                      ((fVar4 / fVar3) / (float)*(int *)(unaff_EBP + -0x6c));
              if (ABS(*(float *)(unaff_EBP + -0x18)) <= _DAT_0067343c) {
                *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
              }
              fVar4 = (fVar3 * *(float *)(unaff_EBP + -0x48)) / SQRT(*(float *)(unaff_EBP + -0x18));
              *(float *)(unaff_EBP + -0x38) = (fVar3 * fVar2) / SQRT(*(float *)(unaff_EBP + -0x18));
              extraout_ECX[0xa6] = *(int *)(unaff_EBP + -0x38);
              *(float *)(unaff_EBP + -0x14) = fVar4 + (float)extraout_ECX[0x20];
              *(float *)(unaff_EBP + -0x10) =
                   *(float *)(unaff_EBP + -0x38) + (float)extraout_ECX[0x21];
              extraout_ECX[0xa5] = (int)fVar4;
              uVar13 = __ftol();
              *(undefined4 *)(unaff_EBP + -0x3c) = uVar13;
              uVar13 = __ftol();
              iVar15 = extraout_ECX[0x60];
              *(undefined4 *)(unaff_EBP + -0x40) = uVar13;
              FUN_0048329c(unaff_EBP + -0x40,iVar15);
              iVar15 = ((int *)extraout_ECX[0x4e])[0x44];
              cVar11 = (**(code **)(*(int *)extraout_ECX[0x4e] + 0x54))(unaff_EBP + -0x40,iVar15,0);
              if (cVar11 != '\0') {
                (**(code **)(*(int *)extraout_ECX[0x4e] + 0x88))(unaff_EBP + -0x40,iVar15);
                extraout_ECX[0x20] = *(int *)(unaff_EBP + -0x14);
                extraout_ECX[0x21] = *(int *)(unaff_EBP + -0x10);
                if (((extraout_ECX[0xa1] == 0) || (extraout_ECX[0x62] != 1)) ||
                   ((extraout_ECX[3] != 0 && (*(int *)(extraout_ECX[3] + 0x68) == 0)))) {
                  if (*(char *)(unaff_EBP + -0x1d) != '\0') {
                    iVar15 = extraout_ECX[0x20];
                    *(undefined1 *)(unaff_EBP + -0x1d) = 0;
                    extraout_ECX[0x71] = iVar15;
                    extraout_ECX[0x72] = extraout_ECX[0x21];
                    extraout_ECX[0x73] = extraout_ECX[0x22];
                    DAT_006f6d18 = 0xe;
                    break;
                  }
                  goto LAB_0058f68c;
                }
                if (*(int *)(unaff_EBP + -0x24) != 0) {
                  extraout_ECX[0xa2] = 3;
                  extraout_ECX[0x74] = extraout_ECX[0x20];
                  iVar15 = *(int *)(unaff_EBP + -0x10);
                  extraout_ECX[0x77] = extraout_ECX[0x20];
                  extraout_ECX[0x75] = iVar15;
                  extraout_ECX[0x71] = extraout_ECX[0x20];
                  extraout_ECX[0x76] = extraout_ECX[0x22];
                  extraout_ECX[0x78] = extraout_ECX[0x21];
                  extraout_ECX[0x72] = extraout_ECX[0x21];
                  extraout_ECX[0x79] = extraout_ECX[0x22];
                  extraout_ECX[0x73] = extraout_ECX[0x22];
                  goto code_r0x0058ef92;
                }
              }
              extraout_ECX[0x62] = 3;
              goto LAB_0058f68c;
            }
            extraout_ECX[100] = (-(uint)(*(int *)(unaff_EBP + -0x34) != 1) & 0xfffffffb) + 0xb;
            extraout_ECX[10] = 0;
            extraout_ECX[9] = 0;
          }
        }
        else {
          fVar2 = fRam006d07b0;
          if (*(int *)(unaff_EBP + -0x34) == 1) {
            fVar2 = fRam006d07b4;
          }
          fVar2 = fVar2 * _DAT_00668654;
          if (*(float *)(unaff_EBP + -0x18) <= (float)extraout_ECX[0x80]) {
            *(undefined1 *)(unaff_EBP + -0x1f) = 0;
          }
          if ((extraout_ECX[0xa2] == 0) && (fVar2 <= *(float *)(unaff_EBP + -0x18))) {
            extraout_ECX[100] = 10 - (uint)(*(int *)(unaff_EBP + -0x34) != 1);
            *(undefined1 *)(unaff_EBP + -0x1f) = DAT_006f6d20;
            goto code_r0x0058eb0e;
          }
          if (*(int *)(unaff_EBP + -0x24) == 0) {
            extraout_ECX[0x71] = extraout_ECX[0x20];
            extraout_ECX[0xa2] = 1;
            extraout_ECX[0x72] = extraout_ECX[0x21];
            DAT_006f6d18 = 0xd;
            extraout_ECX[0x62] = -1;
            extraout_ECX[100] = 3;
            extraout_ECX[0xa3] = 1;
            extraout_ECX[0x7b] = 0x3f800000;
            if (extraout_ECX[3] == 0) break;
            fVar2 = (float)extraout_ECX[0xa6];
            iVar15 = extraout_ECX[0xa5];
            *(undefined1 *)(unaff_EBP + -0x1d) = 1;
            *(int *)(unaff_EBP + -0x48) = iVar15;
            *(float *)(unaff_EBP + -0x18) =
                 *(float *)(unaff_EBP + -0x48) * *(float *)(unaff_EBP + -0x48) + fVar2 * fVar2;
            goto code_r0x0058edf0;
          }
          extraout_ECX[0xa2] = 1;
code_r0x0058e940:
          iVar15 = *(int *)(unaff_EBP + -0x2c);
          extraout_ECX[0x74] = extraout_ECX[0x20];
          extraout_ECX[0x77] = iVar15;
          extraout_ECX[0x75] = extraout_ECX[0x21];
          extraout_ECX[0x71] = iVar15;
          iVar15 = *(int *)(unaff_EBP + -0x1c);
          extraout_ECX[0x76] = extraout_ECX[0x22];
          extraout_ECX[0x78] = iVar15;
          extraout_ECX[0x72] = iVar15;
          extraout_ECX[0x79] = (int)(float)fVar20;
          extraout_ECX[0x73] = (int)(float)fVar20;
code_r0x0058ef92:
          if (extraout_ECX[0xa4] == 0) {
            iVar15 = extraout_ECX[0xa2];
            extraout_ECX[100] = 3;
            if (iVar15 == 1) {
              extraout_ECX[0x62] = -1;
            }
            else if (iVar15 == 2) {
              extraout_ECX[0x62] = 2;
            }
            else if (iVar15 == 3) {
              extraout_ECX[0x62] = 3;
            }
            iVar15 = extraout_ECX[0x20];
            extraout_ECX[0x74] = iVar15;
            extraout_ECX[0x77] = iVar15;
            extraout_ECX[0x71] = iVar15;
            iVar15 = extraout_ECX[0x21];
            extraout_ECX[0x75] = iVar15;
            extraout_ECX[0x78] = iVar15;
            extraout_ECX[0x72] = iVar15;
            iVar15 = extraout_ECX[0x22];
            extraout_ECX[0x76] = iVar15;
            extraout_ECX[0x79] = iVar15;
            extraout_ECX[0x73] = iVar15;
          }
          else {
            extraout_ECX[100] = 7;
            extraout_ECX[0x7b] = 0x3f800000;
            extraout_ECX[0x26] = 0x13;
            iVar15 = (**(code **)(*extraout_ECX + 0xf4))();
            if (iVar15 != 0) {
              (**(code **)(*extraout_ECX + 0x100))(extraout_ECX + 3);
            }
          }
        }
        break;
      case 0x58f0ad:
        goto code_r0x0058f0ad;
      case 0x58f0ef:
        if ((extraout_ECX[3] != 0) && (*(short *)(extraout_ECX[0x4e] + 0x628) == 0)) {
code_r0x0058f103:
          (**(code **)(*extraout_ECX + 0xfc))();
          extraout_ECX[0x66] = -1;
          (**(code **)(*extraout_ECX + 0x58))();
        }
        goto code_r0x0058f11b;
      case 0x58f132:
        if (extraout_ECX[3] != 0) goto code_r0x0058f103;
code_r0x0058f11b:
        extraout_ECX[10] = 0;
        extraout_ECX[9] = 0;
        extraout_ECX[0x67] = 0;
        extraout_ECX[0xa4] = 0;
        goto code_r0x0058f308;
      case 0x58f2fc:
        extraout_ECX[0x67] = 1;
        extraout_ECX[0xa4] = 1;
        goto code_r0x0058f308;
      }
      uVar17 = extraout_ECX[100];
      *(undefined4 *)(unaff_EBP + -0x30) = 1;
      if (0xc < uVar17) break;
    } while( true );
  }
  goto LAB_0058f68c;
code_r0x0058f0ad:
  if ((char)extraout_ECX[0xa7] != '\0') {
    if ((float)_DAT_006669e8 <= *(float *)(extraout_ECX[3] + 0x24)) {
      *(int *)(unaff_EBP + -0x5c) = extraout_ECX[0x8a];
    }
    else {
      *(float *)(unaff_EBP + -0x5c) = -(float)extraout_ECX[0x8a];
    }
code_r0x0058f0e5:
    FUN_0059863e();
  }
code_r0x0058f308:
  if (*(int *)(unaff_EBP + -0x30) != 0) goto LAB_0058f68c;
  goto code_r0x0058dd6b;
}

