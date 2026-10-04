
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004e7902(void)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  void *pvVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int unaff_EBP;
  int iVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 extraout_ST1;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  iVar7 = *piVar1;
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 200;
  *(undefined4 *)(unaff_EBP + -0x14) = 200;
  (**(code **)(iVar7 + 0x8c))();
  FUN_0058a17c(1);
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004e8249(piVar1,unaff_EBP + -0x48);
  if ((*(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48) & 0xfffffffcU) == 0) {
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar4 = 0;
  }
  else {
    if (DAT_006f2618 == (undefined4 *)0x0) {
      pvVar6 = operator_new(100);
      *(void **)(unaff_EBP + 8) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar6 == (void *)0x0) {
        DAT_006f2618 = (undefined4 *)0x0;
      }
      else {
        DAT_006f2618 = (undefined4 *)FUN_005dfb13();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      cVar3 = FUN_004e8001(DAT_006f2618);
      *(char *)(unaff_EBP + 0xb) = cVar3;
      if (cVar3 == '\0') {
        if (DAT_006f2618 != (undefined4 *)0x0) {
          (**(code **)*DAT_006f2618)(1);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        uVar4 = *(undefined1 *)(unaff_EBP + 0xb);
        DAT_006f2618 = (undefined4 *)0x0;
        goto LAB_004e7fe8;
      }
    }
    puVar10 = DAT_006f2618;
    *(undefined4 **)(unaff_EBP + -0x3c) = DAT_006f2618;
    *(undefined4 *)(unaff_EBP + -100) = 0;
    *(undefined4 *)(unaff_EBP + -0x60) = 0;
    *(undefined4 *)(unaff_EBP + -0x5c) = 200;
    *(undefined4 *)(unaff_EBP + -0x58) = 200;
    cVar3 = FUN_004e804d(puVar10,unaff_EBP + -100);
    uVar4 = 0;
    if (cVar3 != '\0') {
      cVar3 = FUN_004e80ef(*(undefined4 *)(unaff_EBP + 0x20),unaff_EBP + -0x20);
      if (cVar3 == '\0') {
        uVar4 = FUN_004e8163(*(undefined4 *)(unaff_EBP + -0x3c),unaff_EBP + -100);
      }
      else {
        cVar3 = FUN_004e8127(unaff_EBP + -0x20);
        *(char *)(unaff_EBP + 0xb) = cVar3;
        if (cVar3 != '\0') {
          FUN_004b4533(*(undefined4 *)(DAT_006e486c + 4));
          iVar7 = FUN_004b4714();
          uVar8 = (**(code **)(**(int **)(unaff_EBP + -0x174) + 0x18))();
          *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
          *(undefined4 *)(unaff_EBP + -0x6c) = 0x46fffe00;
          *(float *)(unaff_EBP + -0x68) = (float)*(int *)(unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x1c);
          fVar2 = (float)*(int *)(unaff_EBP + -0x24) * _DAT_00666578;
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x20);
          *(float *)(unaff_EBP + -0x74) =
               (float)*(int *)(unaff_EBP + -0x24) * _DAT_00666578 +
               (float)*(int *)(unaff_EBP + -0x20);
          *(float *)(unaff_EBP + -0x70) = fVar2 + (float)*(int *)(unaff_EBP + -0x1c);
          FUN_005c3840(unaff_EBP + -0xd4,unaff_EBP + -0x74,iVar7 + 0xa8);
          bVar5 = (**(code **)(**(int **)(unaff_EBP + -0x174) + 0x14))();
          *(int *)(unaff_EBP + -0x24) = 1 << (bVar5 & 0x1f);
          *(float *)(unaff_EBP + -0x24) = _DAT_00667660 / (float)*(int *)(unaff_EBP + -0x24);
          FUN_00462eea(unaff_EBP + -0x118,unaff_EBP + -0x24);
          fVar2 = DAT_00673438 * _DAT_00667370;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          *(float *)(unaff_EBP + 0xc) = fVar2 + *(float *)(unaff_EBP + 0xc);
          uVar8 = FUN_005c38c0(unaff_EBP + -200,1,unaff_EBP + 0xc);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_00462c01(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005c4890();
          *(float *)(unaff_EBP + 0xc) = DAT_00673438 * _DAT_00666578;
          uVar8 = FUN_005c38c0(unaff_EBP + -200,2,unaff_EBP + 0xc);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_00462c01(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005c4890();
          *(float *)(unaff_EBP + 0xc) =
               (*(float *)(unaff_EBP + -0x68) - _DAT_00666578) * DAT_00673438 * _DAT_00667440 +
               *(float *)(unaff_EBP + 0x10);
          uVar8 = FUN_005c38c0(unaff_EBP + -200,1,unaff_EBP + 0xc);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_00462c01(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005c4890();
          uVar8 = FUN_00462f96(unaff_EBP + -200,unaff_EBP + -0xd4);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_00462c01(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_005c4890();
          uVar8 = FUN_004b46a0();
          *(undefined4 *)(unaff_EBP + -0x78) = 0x3f800000;
          *(undefined4 *)(unaff_EBP + -0x7c) = 0x3f800000;
          *(undefined4 *)(unaff_EBP + -0x80) = 0x3f800000;
          *(undefined4 *)(unaff_EBP + -0x84) = 0x3f800000;
          uVar9 = FUN_005cee4b();
          *(undefined4 *)(unaff_EBP + 0x10) = uVar9;
          FUN_005cedcb(unaff_EBP + -0x84);
          FUN_005cfd9c(unaff_EBP + -0x28,0);
          if (*(int *)(unaff_EBP + -0x28) != 0) {
            iVar7 = FUN_004b4714();
            fVar2 = DAT_00673438;
            *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar7 + 0x184);
            fVar2 = fVar2 * _DAT_00669424;
            *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar7 + 0x188);
            *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar7 + 0x18c);
            *(float *)(unaff_EBP + 0xc) = fVar2;
            uVar9 = FUN_005c38c0(unaff_EBP + -200,1,unaff_EBP + 0xc);
            *(undefined1 *)(unaff_EBP + -4) = 7;
            puVar10 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x34,unaff_EBP + -0x54,uVar9);
            *(undefined4 *)(unaff_EBP + -0x54) = *puVar10;
            *(undefined4 *)(unaff_EBP + -0x50) = puVar10[1];
            *(undefined4 *)(unaff_EBP + -0x4c) = puVar10[2];
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005c4890();
            FUN_005d0a7c(unaff_EBP + -0x54);
            FUN_005ceca4(*(undefined4 *)(unaff_EBP + -0x28));
          }
          iVar7 = FUN_005ce621(1);
          if (iVar7 == 0) {
            uVar12 = 0;
            if (*(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48) >> 2 != 0) {
              do {
                FUN_005c36c0(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x48) + uVar12 * 4) + 0xc) +
                             0x18);
                *(undefined1 *)(unaff_EBP + -4) = 8;
                FUN_00599c09(1);
                FUN_00463023(unaff_EBP + -0x118);
                uVar9 = FUN_005d14e3();
                *(undefined4 *)(unaff_EBP + 8) = uVar9;
                FUN_005d14ea(0);
                iVar7 = FUN_005cf6fc(uVar8,1);
                if (iVar7 != 0) {
                  *(undefined1 *)(unaff_EBP + -0xd) = 0;
                }
                FUN_005d14ea(*(undefined4 *)(unaff_EBP + 8));
                FUN_00463023(unaff_EBP + -200);
                FUN_00599c09(0);
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_005c4890();
                uVar12 = uVar12 + 1;
              } while (uVar12 < (uint)(*(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48) >>
                                      2));
            }
            iVar7 = FUN_005ce67e();
            *(bool *)(unaff_EBP + 0xb) = iVar7 == 0;
            if (*(char *)(unaff_EBP + 0xb) == '\0') {
              *(undefined1 *)(unaff_EBP + -0xd) = 0;
            }
          }
          if (*(int *)(unaff_EBP + -0x28) != 0) {
            FUN_005ced0e(*(undefined4 *)(unaff_EBP + -0x28));
            (**(code **)(**(int **)(unaff_EBP + -0x28) + 4))();
          }
          FUN_005cee2f(*(undefined4 *)(unaff_EBP + 0x10));
          puVar10 = *(undefined4 **)(unaff_EBP + 0x28);
          if (puVar10 == (undefined4 *)0x0) {
            cVar3 = FUN_004c3766(*(undefined4 *)(DAT_006e486c + 0x3c),unaff_EBP + -0x20,
                                 *(undefined4 *)(unaff_EBP + 0x20),unaff_EBP + -0x38);
            if (cVar3 == '\0') {
              *(undefined4 *)(unaff_EBP + -0x38) = 0;
              *(undefined4 *)(unaff_EBP + -0x34) = 0;
              *(undefined4 *)(unaff_EBP + -0x30) = 0;
              *(undefined4 *)(unaff_EBP + -0x2c) = 0;
            }
            else {
              piVar1 = *(int **)(unaff_EBP + 0x1c);
              if (*piVar1 <= *(int *)(unaff_EBP + -0x38)) {
                *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) - *piVar1;
              }
              if (piVar1[2] <= *(int *)(unaff_EBP + -0x30)) {
                *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) - piVar1[2];
              }
              if (piVar1[1] <= *(int *)(unaff_EBP + -0x34)) {
                *(int *)(unaff_EBP + -0x34) = *(int *)(unaff_EBP + -0x34) - piVar1[1];
              }
              if (piVar1[3] <= *(int *)(unaff_EBP + -0x2c)) {
                *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) - piVar1[3];
              }
            }
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + *(int *)(unaff_EBP + -0x38);
            iVar7 = *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x30);
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x34);
            iVar13 = *(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x2c);
            *(int *)(unaff_EBP + -0x18) = iVar7;
          }
          else {
            iVar7 = puVar10[2];
            iVar13 = puVar10[3];
            *(undefined4 *)(unaff_EBP + -0x20) = *puVar10;
            uVar8 = puVar10[1];
            *(int *)(unaff_EBP + -0x18) = iVar7;
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar8;
          }
          fVar14 = (float10)*(int *)(unaff_EBP + 0x14);
          fVar15 = (float10)*(int *)(unaff_EBP + 0x18);
          *(int *)(unaff_EBP + -0x14) = iVar13;
          fVar16 = fVar14 / fVar15;
          *(int *)(unaff_EBP + 0x20) = iVar7 - *(int *)(unaff_EBP + -0x20);
          *(int *)(unaff_EBP + 0xc) = iVar13 - *(int *)(unaff_EBP + -0x1c);
          *(float *)(unaff_EBP + 0x20) = (float)*(int *)(unaff_EBP + 0x20);
          fVar17 = (float10)*(float *)(unaff_EBP + 0x20) / (float10)*(int *)(unaff_EBP + 0xc);
          if (fVar17 <= fVar16) {
            if (fVar17 < fVar16) {
              fVar14 = fVar15;
              iVar11 = __ftol();
              fVar15 = fVar16;
              if (200 < iVar11) {
                iVar11 = 200;
              }
              iVar11 = (iVar11 - iVar7) + *(int *)(unaff_EBP + -0x20);
              while (((1 < iVar11 && (0 < *(int *)(unaff_EBP + -0x20))) && (iVar7 < 200))) {
                *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + -1;
                iVar7 = iVar7 + 1;
                *(int *)(unaff_EBP + -0x18) = iVar7;
                iVar11 = iVar11 + -2;
              }
              while ((0 < iVar11 && (iVar7 < 200))) {
                iVar7 = iVar7 + 1;
                iVar11 = iVar11 + -1;
                *(int *)(unaff_EBP + -0x18) = iVar7;
              }
            }
          }
          else {
            fVar14 = fVar15;
            iVar11 = __ftol();
            if (200 < iVar11) {
              iVar11 = 200;
            }
            iVar11 = (iVar11 - iVar13) + *(int *)(unaff_EBP + -0x1c);
            while (((1 < iVar11 && (0 < *(int *)(unaff_EBP + -0x1c))) && (iVar13 < 200))) {
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -1;
              iVar13 = iVar13 + 1;
              *(int *)(unaff_EBP + -0x14) = iVar13;
              iVar11 = iVar11 + -2;
            }
            while ((fVar15 = extraout_ST1, 0 < iVar11 && (iVar13 < 200))) {
              iVar13 = iVar13 + 1;
              iVar11 = iVar11 + -1;
              *(int *)(unaff_EBP + -0x14) = iVar13;
            }
          }
          iVar11 = DAT_006e486c;
          uVar8 = 0;
          if (*(char *)(unaff_EBP + 0xb) != '\0') {
            *(int *)(unaff_EBP + 0x20) = iVar13 - *(int *)(unaff_EBP + -0x1c);
            uVar8 = *(undefined4 *)(iVar11 + 0x3c);
            iVar13 = *(int *)(unaff_EBP + 0x20);
            *(int *)(unaff_EBP + 0x20) = iVar7 - *(int *)(unaff_EBP + -0x20);
            uVar8 = FUN_004ba98d((float)(fVar14 / (float10)*(int *)(unaff_EBP + 0x20)),
                                 (float)(fVar15 / (float10)iVar13),uVar8,unaff_EBP + -0x20,0);
          }
          cVar3 = FUN_004e8163(*(undefined4 *)(unaff_EBP + -0x3c),unaff_EBP + -100);
          if (cVar3 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          cVar3 = FUN_004e81a4(*(undefined4 *)(unaff_EBP + -0x3c),unaff_EBP + -100);
          if (cVar3 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          FUN_005a5e48(uVar8);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_005c4890();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          uVar4 = *(undefined1 *)(unaff_EBP + -0xd);
          goto LAB_004e7fe8;
        }
        uVar4 = FUN_004e81a4(*(undefined4 *)(unaff_EBP + -0x3c),unaff_EBP + -100);
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
LAB_004e7fe8:
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

