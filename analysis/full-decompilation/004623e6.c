
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004623e6(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  undefined4 *extraout_ECX;
  int iVar13;
  int unaff_EBP;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST0;
  
  FUN_00634c24();
  uVar6 = FUN_004b46a0();
  iVar7 = extraout_ECX[5];
  *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
  if (iVar7 == -1) {
    piVar1 = (int *)*extraout_ECX;
    *(int **)(unaff_EBP + -0x10) = piVar1;
    iVar7 = (**(code **)(*piVar1 + 0x208))();
    iVar8 = (**(code **)(*piVar1 + 0x1f8))();
    piVar1 = (int *)*extraout_ECX;
    extraout_ECX[5] = iVar7 + iVar8;
    iVar7 = (**(code **)(*piVar1 + 0x20c))();
    iVar8 = (**(code **)(*piVar1 + 0x1fc))();
    extraout_ECX[0xc] = 0;
    extraout_ECX[6] = iVar8 + iVar7;
    extraout_ECX[10] = extraout_ECX[5];
    extraout_ECX[0xb] = iVar8 + iVar7;
  }
  piVar1 = (int *)extraout_ECX[1];
  *(int **)(unaff_EBP + -0x3c) = piVar1;
  iVar7 = (**(code **)(*piVar1 + 0x208))();
  iVar8 = (**(code **)(*piVar1 + 0x1f8))();
  piVar1 = (int *)extraout_ECX[1];
  extraout_ECX[0xd] = iVar7 + iVar8;
  iVar7 = (**(code **)(*piVar1 + 0x20c))();
  iVar8 = (**(code **)(*piVar1 + 0x1fc))();
  extraout_ECX[0xe] = iVar7 + iVar8;
  extraout_ECX[0xf] = DAT_006c46f8;
  uVar9 = (**(code **)(*(int *)*extraout_ECX + 0x1b0))();
  piVar1 = (int *)*extraout_ECX;
  *(uint *)(unaff_EBP + -0x18) = uVar9;
  iVar7 = (**(code **)(*piVar1 + 0x1bc))();
  if (extraout_ECX[0x11] != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
    uVar9 = *(uint *)(unaff_EBP + -0x18);
  }
  if ((int)uVar9 < 0) goto LAB_0046250a;
  if (iVar7 < 0) goto LAB_004624fc;
  if (iVar7 < 2) {
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    goto LAB_0046250a;
  }
  if (iVar7 == 2) {
    iVar7 = uVar9 << 2;
LAB_004624eb:
    *(int *)(unaff_EBP + -0x18) = iVar7;
  }
  else {
    if (2 < iVar7) {
      if (iVar7 < 5) {
        iVar7 = uVar9 * 2;
        goto LAB_004624eb;
      }
      if (iVar7 < 8) goto LAB_0046250a;
    }
LAB_004624fc:
    if (7 < (int)uVar9) {
      *(uint *)(unaff_EBP + -0x18) = (uVar9 & 1) << 2;
    }
  }
LAB_0046250a:
  fVar14 = (float10)(**(code **)(*(int *)*extraout_ECX + 0x1cc))();
  piVar1 = (int *)*extraout_ECX;
  *(float *)(unaff_EBP + -0x1c) = (float)fVar14;
  fVar15 = (float10)(**(code **)(*piVar1 + 0x1c8))();
  fVar14 = (float10)_DAT_00667460;
  fVar16 = (float10)fsin((float10)*(float *)(unaff_EBP + -0x1c));
  *(float *)(unaff_EBP + -0x38) = (float)-(fVar16 * SQRT(fVar15 * fVar14));
  fVar16 = (float10)fcos((float10)*(float *)(unaff_EBP + -0x1c));
  *(float *)(unaff_EBP + -0x30) = (float)(fVar16 * SQRT(fVar15 * fVar14));
  uVar6 = FUN_004b0b98();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
  iVar8 = FUN_004b0b8a();
  iVar7 = extraout_ECX[0x11];
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar8;
  *(float *)(unaff_EBP + -0x5c) = (float)*(int *)(unaff_EBP + -0x20) * _DAT_00666578;
  if (iVar7 != 0) {
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
  }
  iVar7 = (**(code **)(*(int *)extraout_ECX[2] + 0xac))();
  iVar12 = *(int *)(iVar7 + 4);
  *(int *)(unaff_EBP + -0x2c) = iVar12;
  FUN_005b870f(&DAT_006c4518);
  iVar7 = *(int *)(iVar12 + 0x8c);
  iVar13 = 0;
  iVar8 = *(int *)(iVar12 + 0x88);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  iVar7 = iVar7 - iVar8 >> 2;
  *(int *)(unaff_EBP + -0x3c) = iVar7;
  if (0 < iVar7) {
    do {
      iVar7 = *(int *)(*(int *)(iVar12 + 0x88) + iVar13 * 4);
      *(int *)(unaff_EBP + -0x34) = iVar7;
      if ((*(int *)(*(int *)(iVar7 + 4) + 0x14) == 0) &&
         (iVar8 = (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 8)) / 0xc, 0 < iVar8)) {
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(int *)(unaff_EBP + -0x40) = iVar8;
        do {
          cVar4 = FUN_004317d5(*(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + *(int *)(iVar7 + 8)),
                               unaff_EBP + -0x94);
          if (cVar4 == '\0') goto LAB_00462b42;
          iVar8 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 8 + *(int *)(iVar7 + 8));
          if (iVar8 == 0) goto LAB_00462b3f;
          FUN_005c36c0(*(int *)(iVar8 + 0xc) + 0x18);
          piVar1 = *(int **)(iVar8 + 0xc);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          puVar10 = (undefined4 *)(**(code **)(*piVar1 + 0x18))();
          *(undefined4 *)(unaff_EBP + -0x88) = *puVar10;
          *(undefined4 *)(unaff_EBP + -0x84) = puVar10[1];
          *(undefined4 *)(unaff_EBP + -0x80) = puVar10[2];
          *(undefined4 *)(unaff_EBP + -0x7c) = puVar10[3];
          *(undefined4 *)(unaff_EBP + -0x78) = puVar10[4];
          *(undefined4 *)(unaff_EBP + -0x74) = puVar10[5];
          uVar6 = _DAT_0066745c;
          *(undefined4 *)(unaff_EBP + -0xac) = _DAT_0066745c;
          *(undefined4 *)(unaff_EBP + -0xa8) = uVar6;
          *(undefined4 *)(unaff_EBP + -0xa4) = uVar6;
          uVar6 = _DAT_00667458;
          *(undefined4 *)(unaff_EBP + -0x54) = _DAT_00667458;
          *(undefined4 *)(unaff_EBP + -0x58) = uVar6;
          *(undefined4 *)(unaff_EBP + -0x60) = uVar6;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          uVar6 = FUN_00462bc9(unaff_EBP + -0x60,unaff_EBP + -0x58,unaff_EBP + -0x54);
          FUN_00462be8(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_00599c09(1);
          uVar6 = _DAT_00667454;
          if (*(int *)(unaff_EBP + -0x18) != -1) {
            uVar6 = 0x3f800000;
          }
          *(undefined4 *)(unaff_EBP + -100) = uVar6;
          *(undefined4 *)(unaff_EBP + -0x68) = uVar6;
          *(undefined4 *)(unaff_EBP + -0x6c) = uVar6;
          *(undefined4 *)(unaff_EBP + -0x70) = uVar6;
          uVar6 = FUN_005cee4b();
          *(undefined4 *)(unaff_EBP + -0x50) = uVar6;
          FUN_005cedcb(unaff_EBP + -0x70);
          iVar12 = DAT_006e486c;
          *(undefined4 *)(unaff_EBP + -0x10) = 0xe;
          bVar5 = (**(code **)(**(int **)(iVar12 + 4) + 0x14))();
          iVar11 = DAT_006e5490 - extraout_ECX[0x12];
          iVar13 = extraout_ECX[4];
          *(int *)(unaff_EBP + -0x24) = 1 << (bVar5 & 0x1f);
          iVar12 = *(int *)(unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x24) = iVar11;
          fVar14 = (float10)_DAT_00667450 / (float10)iVar12;
          if (((iVar13 != 0) && (1 < DAT_006c46f0)) && (iVar11 < DAT_006c46f0)) {
            uVar6 = __ftol();
            *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
            fVar14 = extraout_ST0;
          }
          fVar15 = (float10)_DAT_006c46fc;
          *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x5c);
          iVar13 = DAT_006e486c;
          *(float *)(unaff_EBP + -0x24) = (float)(fVar14 * fVar15);
          iVar12 = extraout_ECX[6];
          *(float *)(unaff_EBP + -0x4c) = (float)(int)extraout_ECX[5];
          *(float *)(unaff_EBP + -0x48) = (float)iVar12 + (float)*(int *)(unaff_EBP + -0x10);
          iVar12 = (**(code **)(**(int **)(iVar13 + 4) + 0x10))();
          FUN_005c36c0(iVar12 + 0xa8);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          puVar10 = (undefined4 *)
                    FUN_005c3840(unaff_EBP + -0x108,unaff_EBP + -0x4c,unaff_EBP + -0x14c);
          *(undefined4 *)(unaff_EBP + -0x4c) = *puVar10;
          *(undefined4 *)(unaff_EBP + -0x48) = puVar10[1];
          *(undefined4 *)(unaff_EBP + -0x44) = puVar10[2];
          FUN_00462eea(unaff_EBP + -0xf0,unaff_EBP + -0x24);
          fVar2 = _DAT_006c4700 * _DAT_00667448;
          iVar13 = *(int *)(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          iVar12 = extraout_ECX[0x14];
          extraout_ECX[0x17] = fVar2;
          extraout_ECX[0x18] = _DAT_006c4700 * _DAT_00667448 + *(float *)(unaff_EBP + -0x38);
          *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x30) + (float)extraout_ECX[0x17];
          extraout_ECX[0x17] = *(undefined4 *)(unaff_EBP + -0x10);
          if (iVar13 != iVar12) {
            extraout_ECX[0x14] = iVar13;
            extraout_ECX[0x13] = DAT_006e5490;
            extraout_ECX[0x1b] = extraout_ECX[0x18];
            extraout_ECX[0x1c] = *(undefined4 *)(unaff_EBP + -0x10);
            extraout_ECX[0x10] = DAT_006e5490 - extraout_ECX[0x13];
          }
          fVar2 = _DAT_00666a44;
          switch(iVar13) {
          case 0:
            fVar2 = *(float *)(unaff_EBP + -0x10) + _DAT_00666a40;
            goto code_r0x0046288d;
          case 1:
            fVar3 = *(float *)(unaff_EBP + -0x10) + _DAT_00666a44;
            goto code_r0x00462862;
          case 2:
            fVar2 = (float)extraout_ECX[0x18] - _DAT_00666a40;
            goto code_r0x004628b3;
          case 3:
            fVar3 = *(float *)(unaff_EBP + -0x10) - _DAT_00666a44;
code_r0x00462862:
            extraout_ECX[0x17] = fVar3;
            fVar2 = (float)extraout_ECX[0x18] - fVar2;
code_r0x004628a5:
            extraout_ECX[0x18] = fVar2;
            break;
          case 4:
            fVar2 = *(float *)(unaff_EBP + -0x10) - _DAT_00666a40;
code_r0x0046288d:
            extraout_ECX[0x17] = fVar2;
            break;
          case 5:
            extraout_ECX[0x17] = *(float *)(unaff_EBP + -0x10) - _DAT_00666a44;
            fVar2 = (float)extraout_ECX[0x18] + fVar2;
            goto code_r0x004628a5;
          case 6:
            fVar2 = (float)extraout_ECX[0x18] + _DAT_00666a40;
code_r0x004628b3:
            extraout_ECX[0x18] = fVar2;
            break;
          case 7:
            extraout_ECX[0x18] = (float)extraout_ECX[0x18] + _DAT_00666a44;
            extraout_ECX[0x17] = *(float *)(unaff_EBP + -0x10) + fVar2;
          }
          iVar12 = DAT_006c46f4;
          if (extraout_ECX[0x13] != 0) {
            iVar11 = DAT_006e5490 - extraout_ECX[0x13];
            *(int *)(unaff_EBP + -0x10) = iVar11;
            if (iVar11 < iVar12) {
              fVar2 = SQRT(((float)*(int *)(unaff_EBP + -0x10) / (float)DAT_006c46f4) *
                           _DAT_00667444 + _DAT_00666a38);
              extraout_ECX[0x18] =
                   fVar2 * (float)extraout_ECX[0x18] + (1.0 - fVar2) * (float)extraout_ECX[0x1b];
              extraout_ECX[0x17] =
                   fVar2 * (float)extraout_ECX[0x17] + (1.0 - fVar2) * (float)extraout_ECX[0x1c];
            }
            else if (iVar11 < iVar12 * 2) {
              if (iVar13 == -1) {
                piVar1 = (int *)*extraout_ECX;
                *(int **)(unaff_EBP + -0x10) = piVar1;
                fVar14 = (float10)(**(code **)(*piVar1 + 0x1c8))();
                iVar7 = *piVar1;
                *(float *)(unaff_EBP + -0x14) = (float)fVar14;
                uVar6 = (**(code **)(iVar7 + 0x1d0))();
                *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
                if ((float)*(int *)(unaff_EBP + -0x10) <= *(float *)(unaff_EBP + -0x14)) {
                  extraout_ECX[0x16] = 0xbe19999a;
                }
                else {
                  extraout_ECX[0x16] = 0;
                }
                iVar7 = *(int *)(unaff_EBP + -0x34);
              }
            }
            else {
              extraout_ECX[0x13] = 0;
            }
          }
          uVar6 = (**(code **)(**(int **)(DAT_006e486c + 4) + 0x18))();
          *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
          *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + -0x14);
          *(float *)(unaff_EBP + -0x14) = DAT_00673438 * _DAT_00667370 + (float)extraout_ECX[0x17];
          uVar6 = FUN_005c38c0(unaff_EBP + -0x25c,1,unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_00462c01(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005c4890();
          *(float *)(unaff_EBP + -0x14) = DAT_00673438 * _DAT_00666578;
          uVar6 = FUN_005c38c0(unaff_EBP + -0x1d4,2,unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_00462c01(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005c4890();
          *(float *)(unaff_EBP + -0x14) =
               (*(float *)(unaff_EBP + -0x10) - _DAT_00666578) * DAT_00673438 * _DAT_00667440 +
               (float)extraout_ECX[0x18];
          uVar6 = FUN_005c38c0(unaff_EBP + -0x218,1,unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_00462c01(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005c4890();
          uVar6 = FUN_00462f96(unaff_EBP + -0x2a0,unaff_EBP + -0x4c);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_00462c01(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_005c4890();
          FUN_00463023(unaff_EBP + -0xf0);
          FUN_00599c53(0);
          FUN_00463049(iVar8 + 0x1c);
          cVar4 = FUN_004b465e();
          if ((cVar4 != '\0') && (cVar4 = FUN_004b4665(), cVar4 != '\0')) {
            FUN_005cf6fc(*(undefined4 *)(unaff_EBP + -0x28),1);
          }
          FUN_00463023(unaff_EBP + -400);
          FUN_00463049(unaff_EBP + -0x88);
          FUN_00599c53(0);
          FUN_005cee2f(*(undefined4 *)(unaff_EBP + -0x50));
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_005c4890();
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_005c4890();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005c4890();
LAB_00462b3f:
          iVar12 = *(int *)(unaff_EBP + -0x2c);
LAB_00462b42:
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0xc;
          piVar1 = (int *)(unaff_EBP + -0x40);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      iVar13 = *(int *)(unaff_EBP + -0x20) + 1;
      *(int *)(unaff_EBP + -0x20) = iVar13;
    } while (iVar13 < *(int *)(unaff_EBP + -0x3c));
  }
  if ((extraout_ECX[0x11] != 0) && ((uint)extraout_ECX[0x11] < DAT_006e5490)) {
    extraout_ECX[0x11] = 0;
  }
  fVar2 = (float)extraout_ECX[0x16] * _DAT_00666a48;
  fVar3 = (float)extraout_ECX[0x15] * _DAT_0066743c;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[0x15] = fVar3 + fVar2;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

