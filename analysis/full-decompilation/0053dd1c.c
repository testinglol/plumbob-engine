
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053dd1c(void)

{
  undefined1 uVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  char cVar6;
  char cVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  int iVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  char *pcVar15;
  int iVar16;
  undefined2 *puVar17;
  byte bVar18;
  char cVar19;
  byte bVar20;
  int extraout_ECX;
  int iVar21;
  int iVar22;
  char cVar23;
  undefined2 uVar24;
  int unaff_EBP;
  byte *pbVar25;
  bool bVar26;
  float10 fVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  
  FUN_00634c24();
  iVar9 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  uVar8 = DAT_006f0ba8;
  piVar2 = *(int **)(iVar9 + 4);
  *(int **)(unaff_EBP + -0x70) = piVar2;
  *(undefined4 *)(unaff_EBP + -0x90) = uVar8;
  uVar8 = FUN_0053c16a();
  *(undefined4 *)(unaff_EBP + -0x48) = uVar8;
  uVar8 = (**(code **)(*piVar2 + 0x24))();
  *(undefined4 *)(unaff_EBP + -0xd0) = uVar8;
  *(undefined4 *)(unaff_EBP + -0xa0) = 0x3f800000;
  *(undefined4 *)(unaff_EBP + -0xa8) = 0x3f800000;
  iVar9 = FUN_004670a4();
  *(undefined1 *)(unaff_EBP + -0x2c) = 0;
  bVar20 = 0;
  *(undefined1 *)(unaff_EBP + -0x2a) = 0;
  *(undefined1 *)(unaff_EBP + -0x29) = 0;
  *(undefined1 *)(unaff_EBP + -0x2b) = 0;
  if (iVar9 != 0) {
    fVar27 = (float10)FUN_004689a1();
    *(float *)(unaff_EBP + -0xa8) = (float)fVar27;
  }
  iVar9 = *(int *)(unaff_EBP + 0xc);
  if (*(char *)(extraout_ECX + 0x48) == '\0') {
    uVar8 = (**(code **)(**(int **)(unaff_EBP + -0x70) + 0x14))();
    *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
    if (*(int *)(extraout_ECX + 0x28 + *(int *)(extraout_ECX + 0x18) * 4) != 0) {
      fVar27 = (float10)FUN_004689a1();
      *(float *)(unaff_EBP + -0xa0) = (float)fVar27;
    }
  }
  else {
    FUN_004b463f(3);
    FUN_0053f472(unaff_EBP + -0xd8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    puVar10 = (undefined4 *)FUN_00434d3d();
    *(undefined4 *)(iVar9 + 0x50) = *puVar10;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(iVar9 + 0x54) = puVar10[1];
    uVar8 = *(undefined4 *)(extraout_ECX + 0x54);
    uVar13 = *(undefined4 *)(extraout_ECX + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar8;
    iVar12 = *(int *)(extraout_ECX + 0x50);
    *(undefined4 *)(iVar9 + 0x10) = uVar13;
    *(int *)(iVar9 + 0x14) = (4 << ((byte)uVar8 & 0x1f)) + iVar12;
    FUN_004b4bbd();
  }
  *(undefined4 *)(unaff_EBP + -0x58) = 8;
  bVar18 = (byte)*(undefined4 *)(unaff_EBP + -0x24);
  *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) << (bVar18 & 0x1f);
  *(int *)(unaff_EBP + -0xd4) = 4 << (bVar18 & 0x1f);
  *(undefined1 *)(unaff_EBP + -0x44) = *(undefined1 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x43) = *(undefined1 *)(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -0x42) = *(undefined1 *)(extraout_ECX + 6);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0053f472(unaff_EBP + -0x1c);
  pbVar25 = *(byte **)(extraout_ECX + 0x30);
  *(undefined1 *)(unaff_EBP + -0x31) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(byte **)(unaff_EBP + -0x60) = pbVar25;
  do {
    if (pbVar25 == *(byte **)(extraout_ECX + 0x34)) {
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if (*(char *)(*(int *)(unaff_EBP + -0x70) + 0x50) == '\0') {
LAB_0053dec6:
      if (pbVar25 == *(byte **)(extraout_ECX + 0x30)) {
        *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) | 1;
        *(undefined1 *)(unaff_EBP + -0xb0) = 0;
        *(undefined1 *)(unaff_EBP + -0xaf) = 0;
        *(undefined2 *)(unaff_EBP + -0xae) = 0;
        *(undefined2 *)(unaff_EBP + -0xac) = 0;
        pbVar11 = (byte *)(unaff_EBP + -0xb0);
      }
      else {
        pbVar11 = pbVar25 + -6;
      }
      *(byte **)(unaff_EBP + -0x30) = pbVar11;
      if ((*(byte *)(unaff_EBP + -0x7c) & 1) != 0) {
        *(uint *)(unaff_EBP + -0x7c) = *(uint *)(unaff_EBP + -0x7c) & 0xfffffffe;
      }
      if (*(char *)(extraout_ECX + 0x48) == '\0') {
        FUN_004b3e97(unaff_EBP + -0x68);
        *(undefined1 **)(unaff_EBP + -100) = &stack0xfffffe8c;
        puVar10 = (undefined4 *)FUN_004796d9();
        *(undefined4 *)(unaff_EBP + -0x2c) = *puVar10;
        bVar20 = *(byte *)(unaff_EBP + -0x2b);
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(extraout_ECX + 0x4c);
        *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(extraout_ECX + 0x50);
      }
      iVar9 = *(int *)(extraout_ECX + 0x10);
      *(byte *)(unaff_EBP + -0x1d) = bVar20;
      *(byte *)(unaff_EBP + -0x25) = bVar20;
      if (iVar9 == 1) {
        bVar18 = *(byte *)(unaff_EBP + -0x2c);
        puVar14 = (undefined1 *)(unaff_EBP + -0x2c);
LAB_0053dfad:
        if (bVar20 <= bVar18) {
          puVar14 = (undefined1 *)(unaff_EBP + -0x2b);
        }
        uVar1 = *puVar14;
        *(byte *)(unaff_EBP + -0x25) = bVar20;
        *(undefined1 *)(unaff_EBP + -0x1d) = uVar1;
      }
      else {
        if (iVar9 == 3) {
          bVar18 = *(byte *)(unaff_EBP + -0x2a);
          puVar14 = (undefined1 *)(unaff_EBP + -0x2a);
          goto LAB_0053dfad;
        }
        if (iVar9 == 5) {
          puVar14 = (undefined1 *)(unaff_EBP + -0x29);
          if (bVar20 <= *(byte *)(unaff_EBP + -0x29)) {
            puVar14 = (undefined1 *)(unaff_EBP + -0x2b);
          }
          *(undefined1 *)(unaff_EBP + -0x1d) = *puVar14;
        }
        else if (iVar9 == 6) {
          puVar14 = (undefined1 *)(unaff_EBP + -0x2a);
          if (*(byte *)(unaff_EBP + -0x2c) <= *(byte *)(unaff_EBP + -0x2a)) {
            puVar14 = (undefined1 *)(unaff_EBP + -0x2c);
          }
          uVar1 = *puVar14;
          *(byte *)(unaff_EBP + -0x25) = *(byte *)(unaff_EBP + -0x2c);
          *(undefined1 *)(unaff_EBP + -0x1d) = uVar1;
        }
      }
      bVar20 = pbVar25[1];
      *(undefined4 *)(unaff_EBP + -0x78) = 1;
      if ((bVar20 == 0xff) || (cVar6 = FUN_0053cedf(), cVar6 != '\0')) {
        if ((*(char *)(*(int *)(unaff_EBP + -0x30) + 1) != -1) &&
           (cVar6 = FUN_0053cedf(), cVar6 == '\0')) {
          bVar20 = **(byte **)(unaff_EBP + -0x30);
          goto LAB_0053dfd9;
        }
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
      }
      else {
        bVar20 = *pbVar25;
LAB_0053dfd9:
        *(byte *)(unaff_EBP + -0xd) = bVar20 & 1;
      }
      *(undefined1 *)(unaff_EBP + -0x16) = 0;
      *(undefined1 *)(unaff_EBP + -0x14) = 0;
      *(undefined1 *)(unaff_EBP + -0x3a) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      *(int *)(unaff_EBP + -0x94) = 3 << ((char)*(undefined4 *)(unaff_EBP + -0x24) - 1U & 0x1f);
      cVar6 = FUN_0053cedf();
      cVar6 = -(cVar6 != '\0');
      cVar7 = FUN_0053cedf();
      *(char *)(unaff_EBP + -0x15) = '\x01' - (cVar7 != '\0');
      iVar9 = *(int *)(extraout_ECX + 0x34);
      *(undefined1 *)(unaff_EBP + -0x39) = 1;
      if (pbVar25 == (byte *)(iVar9 + -6)) {
        *(undefined1 *)(unaff_EBP + -0x32) = 1;
      }
      else {
        cVar7 = FUN_0053cedf();
        bVar20 = pbVar25[6];
        *(char *)(unaff_EBP + -0x32) = '\x01' - (cVar7 != '\0');
        *(byte *)(unaff_EBP + -0x39) = bVar20 & 1;
      }
      if ((((pbVar25 != (byte *)(*(int *)(extraout_ECX + 0x34) + -6)) &&
           (*(char *)(unaff_EBP + -0x15) == '\0')) && (*(char *)(unaff_EBP + -0x32) != '\0')) &&
         (*(undefined1 *)(unaff_EBP + -0x3a) = 1, *(char *)(unaff_EBP + -0x39) != '\0')) {
        *(undefined1 *)(unaff_EBP + -0x3a) = 0;
      }
      if (((*(char *)(extraout_ECX + 4) != *(char *)(unaff_EBP + -0x44)) ||
          (*(char *)(extraout_ECX + 5) != *(char *)(unaff_EBP + -0x43))) ||
         (*(char *)(extraout_ECX + 6) != *(char *)(unaff_EBP + -0x42))) {
        iVar9 = *(int *)(unaff_EBP + -0x48);
        cVar7 = *(char *)(unaff_EBP + -0xd);
        *(char *)(unaff_EBP + -0x1e) = cVar7;
        if (iVar9 == 1) {
LAB_0053e246:
          *(undefined1 *)(unaff_EBP + -0x14) = 5;
          if (cVar7 == '\0') {
            pbVar11 = *(byte **)(unaff_EBP + -0x30);
            bVar20 = pbVar11[1];
            if (((bVar20 == 3) || (bVar20 == 5)) ||
               ((bVar20 == 6 || ((bVar20 == 0xf || (bVar20 == 0x17)))))) {
              bVar26 = (*pbVar11 & 1) == 0;
LAB_0053e2fe:
              if (!bVar26) {
                *(undefined1 *)(unaff_EBP + -0x16) = 1;
              }
            }
          }
          else {
            bVar20 = pbVar25[1];
            if ((((bVar20 == 3) || (bVar20 == 5)) || (bVar20 == 6)) ||
               ((bVar20 == 0xf || (bVar20 == 0x17)))) {
              pbVar11 = *(byte **)(unaff_EBP + -0x30);
              *(undefined1 *)(unaff_EBP + -0x14) = 1;
              bVar18 = pbVar11[1];
              if ((((bVar18 != 3) && ((bVar18 != 5 && (bVar18 != 6)))) && (bVar18 != 0xf)) &&
                 (bVar18 != 0x17)) {
                *(undefined1 *)(unaff_EBP + -0x16) = 1;
              }
            }
            else {
              pbVar11 = *(byte **)(unaff_EBP + -0x30);
            }
            bVar18 = pbVar11[1];
            if ((((bVar18 == 3) || (bVar18 == 5)) || (bVar18 == 6)) ||
               ((bVar18 == 0xf || (bVar18 == 0x17)))) {
              if ((*pbVar25 & 4) == 0) {
                *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfe;
              }
              if (((bVar20 != 3) && (bVar20 != 5)) && ((bVar20 != 6 && (bVar20 != 0xf)))) {
                bVar26 = bVar20 == 0x17;
                goto LAB_0053e2fe;
              }
            }
          }
          if ((char)(cVar6 + '\x01') == *(char *)(unaff_EBP + -0x15)) {
            if (cVar6 == -1) {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfa;
            }
          }
          else {
            if (*(char *)(unaff_EBP + -0x15) == '\0') {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfb;
            }
            else {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfe;
            }
            *(undefined1 *)(unaff_EBP + -0x16) = 1;
          }
          if ((*pbVar25 & 4) != 0) {
            *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfb;
          }
          if ((*pbVar11 & 2) != 0) {
            *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfe;
          }
        }
        else if (iVar9 == 2) {
LAB_0053e14a:
          *(undefined1 *)(unaff_EBP + -0x14) = 10;
          if (cVar7 == '\0') {
            pbVar11 = *(byte **)(unaff_EBP + -0x30);
            bVar20 = pbVar11[1];
            if ((((bVar20 == 3) || (bVar20 == 5)) || (bVar20 == 6)) ||
               ((bVar20 == 0xf || (bVar20 == 0x17)))) {
              bVar26 = (*pbVar11 & 1) == 0;
LAB_0053e202:
              if (!bVar26) {
                *(undefined1 *)(unaff_EBP + -0x16) = 1;
              }
            }
          }
          else {
            bVar20 = pbVar25[1];
            if (((bVar20 == 3) || (bVar20 == 5)) ||
               ((bVar20 == 6 || ((bVar20 == 0xf || (bVar20 == 0x17)))))) {
              pbVar11 = *(byte **)(unaff_EBP + -0x30);
              *(undefined1 *)(unaff_EBP + -0x14) = 2;
              bVar18 = pbVar11[1];
              if (((bVar18 != 3) && (((bVar18 != 5 && (bVar18 != 6)) && (bVar18 != 0xf)))) &&
                 (bVar18 != 0x17)) {
                *(undefined1 *)(unaff_EBP + -0x16) = 1;
              }
            }
            else {
              pbVar11 = *(byte **)(unaff_EBP + -0x30);
            }
            bVar18 = pbVar11[1];
            if (((bVar18 == 3) || (bVar18 == 5)) ||
               ((bVar18 == 6 || ((bVar18 == 0xf || (bVar18 == 0x17)))))) {
              if ((*pbVar25 & 2) == 0) {
                *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfd;
              }
              if ((((bVar20 != 3) && (bVar20 != 5)) && (bVar20 != 6)) && (bVar20 != 0xf)) {
                bVar26 = bVar20 == 0x17;
                goto LAB_0053e202;
              }
            }
          }
          if ((char)(cVar6 + '\x01') == *(char *)(unaff_EBP + -0x15)) {
            if (cVar6 == -1) {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xf5;
            }
          }
          else {
            if (*(char *)(unaff_EBP + -0x15) == '\0') {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xf7;
            }
            else {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfd;
            }
            *(undefined1 *)(unaff_EBP + -0x16) = 1;
          }
          if ((*pbVar25 & 2) != 0) {
            *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xf7;
          }
          if ((*pbVar11 & 4) != 0) {
            *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xfd;
          }
        }
        else {
          if (iVar9 == 4) goto LAB_0053e246;
          if (iVar9 == 8) goto LAB_0053e14a;
          if (iVar9 == 0x10) {
            bVar20 = *pbVar25;
            *(undefined1 *)(unaff_EBP + -0x14) = 0xa0;
            if ((bVar20 & 6) != 0) {
              *(undefined1 *)(unaff_EBP + -0x14) = 0x20;
            }
            if ((**(byte **)(unaff_EBP + -0x30) & 6) != 0) {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xdf;
            }
            if (*(char *)(unaff_EBP + -0x15) == '\0') {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0x7f;
            }
            if (cVar6 == -1) {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xdf;
            }
          }
          else if (iVar9 == 0x20) {
            bVar20 = *pbVar25;
            *(undefined1 *)(unaff_EBP + -0x14) = 0x50;
            if ((bVar20 & 6) != 0) {
              *(undefined1 *)(unaff_EBP + -0x14) = 0x10;
            }
            if (*(char *)(unaff_EBP + -0x15) == '\0') {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xbf;
            }
            if (cVar6 == -1) {
              *(byte *)(unaff_EBP + -0x14) = *(byte *)(unaff_EBP + -0x14) & 0xef;
            }
          }
        }
        bVar20 = *pbVar25;
        if ((bVar20 & 6) != 0) {
          iVar9 = *(int *)(extraout_ECX + 0x10);
          if (iVar9 == 1) {
            bVar20 = bVar20 & 4;
          }
          else {
            if ((iVar9 != 3) && (iVar9 != 6)) goto LAB_0053e35d;
            bVar20 = bVar20 & 2;
          }
          if (bVar20 != 0) {
            *(undefined1 *)(unaff_EBP + -0x1e) = 0;
          }
        }
LAB_0053e35d:
        if (*(char *)(unaff_EBP + -0x14) != '\0') {
          cVar6 = *(char *)(unaff_EBP + -0x1c);
          iVar9 = *(int *)(unaff_EBP + -0x80);
          *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x68);
          cVar7 = *(char *)(unaff_EBP + -0x1b);
          *(char *)(unaff_EBP + -0x98) = cVar6;
          *(char *)(unaff_EBP + -0x97) = cVar7;
          *(undefined1 *)(unaff_EBP + -0x96) = *(undefined1 *)(unaff_EBP + -0x1a);
          cVar19 = *(char *)(extraout_ECX + 0x48);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          if (cVar19 == '\0') {
            FUN_00434ffd();
            cVar7 = *(char *)(unaff_EBP + -0x1b);
            cVar6 = *(char *)(unaff_EBP + -0x1c);
          }
          *(uint *)(unaff_EBP + -0x50) = (uint)*(byte *)(unaff_EBP + -0x25);
          *(int *)(unaff_EBP + -0x40) =
               *(int *)(unaff_EBP + -0x40) + (-1 - *(int *)(unaff_EBP + -0x58));
          iVar9 = iVar9 - ((uint)*(byte *)(unaff_EBP + -0x25) <<
                          ((char)*(undefined4 *)(unaff_EBP + -0x24) + 1U & 0x1f));
          if (*(int *)(unaff_EBP + -0x48) == 0x10) {
            *(char *)(unaff_EBP + -0x5c) = cVar6;
            *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x58);
            *(char *)(unaff_EBP + -0x5b) = cVar7;
            *(undefined1 *)(unaff_EBP + -0x5a) = *(undefined1 *)(unaff_EBP + -0x1a);
            iVar12 = *(int *)(extraout_ECX + 0x10);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            cVar19 = DAT_006e481f;
            cVar23 = DAT_006e4820;
            if ((iVar12 == 6) || (cVar19 = DAT_006e4825, cVar23 = DAT_006e4826, iVar12 == 7)) {
              *(char *)(unaff_EBP + -0x5c) = cVar19 + cVar6;
              *(char *)(unaff_EBP + -0x5b) = cVar7 + cVar23;
            }
            if (*(char *)(extraout_ECX + 0x48) == '\0') {
              FUN_00434ffd();
            }
            uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
            iVar12 = (int)*(char *)(unaff_EBP + -0x42);
            uVar13 = FUN_00434d3d(unaff_EBP + -0x118);
            FUN_004b469d(uVar13,iVar12);
            FUN_004b97eb(uVar13,iVar12);
            *(undefined1 *)(unaff_EBP + -4) = 4;
          }
          else {
            iVar12 = (int)*(char *)(unaff_EBP + -0x42);
            uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
            iVar9 = iVar9 - *(int *)(unaff_EBP + -0xd4);
            uVar13 = FUN_00434d3d(unaff_EBP + -0x120);
            FUN_004b469d(uVar13,iVar12);
            FUN_004b97eb(uVar13,iVar12);
          }
          FUN_004b4722();
          if (*(char *)(unaff_EBP + -0x1e) == '\0') {
            iVar21 = *(int *)(unaff_EBP + -0x24) + 0xfff;
            iVar9 = iVar9 - *(int *)(*(int *)(unaff_EBP + -0xd0) +
                                    (0x1e - *(int *)(unaff_EBP + -0x24)) * 4);
            uVar35 = 0;
            uVar13 = *(undefined4 *)(unaff_EBP + -0x40);
            iVar22 = (byte)(&DAT_006cd440)[*(byte *)(unaff_EBP + -0x14)] - 1;
            iVar12 = unaff_EBP + -0x1c;
            iVar16 = unaff_EBP + -0x160;
            FUN_004c656a(iVar16,iVar12,iVar21,iVar22,uVar13,iVar9,0,uVar8);
            FUN_004c89b6(iVar16,iVar12,iVar21,iVar22,uVar13,iVar9,uVar35,uVar8);
          }
          else {
            if (*(int *)(unaff_EBP + -0x48) == 0x20) {
              iVar12 = *(int *)(unaff_EBP + -0x24);
              iVar9 = iVar9 - (2 >> (3U - (char)iVar12 & 0x1f));
            }
            else {
              iVar12 = *(int *)(unaff_EBP + -0x24);
            }
            iVar9 = iVar9 - *(int *)(*(int *)(unaff_EBP + -0xd0) + (0x21 - iVar12) * 4);
            uVar13 = 0;
            uVar8 = *(undefined4 *)(unaff_EBP + -0x40);
            iVar21 = (byte)(&DAT_006cd440)[*(byte *)(unaff_EBP + -0x14)] - 1;
            iVar16 = iVar12 + 0x17ff;
            iVar12 = iVar12 + 0x13ff;
            iVar22 = unaff_EBP + -0x140;
            FUN_004c656a(iVar22,iVar12,iVar16,iVar21,uVar8,iVar9,0);
            FUN_004c8c8c(iVar22,iVar12,iVar16,iVar21,uVar8,iVar9,uVar13);
          }
          pbVar25 = *(byte **)(unaff_EBP + -0x60);
          *(undefined1 *)(unaff_EBP + -4) = 3;
        }
        if ((*(char *)(unaff_EBP + -0x16) != '\0') && (*(char *)(unaff_EBP + -0x14) != '\0')) {
          *(undefined1 *)(unaff_EBP + -0x4c) = *(undefined1 *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -0x4b) = *(undefined1 *)(unaff_EBP + -0x1b);
          *(undefined1 *)(unaff_EBP + -0x4a) = *(undefined1 *)(unaff_EBP + -0x1a);
          *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + -0xd);
          bVar20 = pbVar25[1];
          if ((bVar20 == 3) ||
             ((((bVar20 == 5 || (bVar20 == 6)) || (bVar20 == 0xf)) || (bVar20 == 0x17)))) {
            pbVar25 = *(byte **)(unaff_EBP + -0x30);
            if ((*pbVar25 & 1) == 0) {
              *(undefined1 *)(unaff_EBP + -0x1e) = 0;
            }
          }
          else {
            pbVar25 = *(byte **)(unaff_EBP + -0x30);
          }
          *(undefined1 *)(unaff_EBP + -0x36) = 0;
          cVar6 = *(char *)(unaff_EBP + -0x14);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          uVar5 = DAT_006e4823;
          uVar4 = DAT_006e4822;
          uVar3 = DAT_006e481d;
          uVar1 = DAT_006e481c;
          if (cVar6 == '\x01') {
            *(undefined1 *)(unaff_EBP + -0x36) = 0;
            *(undefined1 *)(unaff_EBP + -0x38) = uVar4;
            *(undefined1 *)(unaff_EBP + -0x37) = uVar5;
            bVar26 = false;
            *(undefined4 *)(unaff_EBP + -0x6c) = 2;
LAB_0053e677:
            iVar9 = *(int *)(extraout_ECX + 0x18);
LAB_0053e67a:
            uVar24 = *(undefined2 *)(pbVar25 + iVar9 * 2 + 2);
          }
          else {
            if (cVar6 == '\x02') {
              *(undefined1 *)(unaff_EBP + -0x36) = 0;
              *(undefined1 *)(unaff_EBP + -0x38) = uVar1;
              *(undefined1 *)(unaff_EBP + -0x37) = uVar3;
              bVar26 = true;
              *(undefined4 *)(unaff_EBP + -0x6c) = 1;
              goto LAB_0053e677;
            }
            if (cVar6 == '\x04') {
              *(undefined1 *)(unaff_EBP + -0x36) = 0;
              *(undefined1 *)(unaff_EBP + -0x38) = uVar1;
              *(undefined1 *)(unaff_EBP + -0x37) = uVar3;
              bVar26 = true;
              *(undefined4 *)(unaff_EBP + -0x6c) = 1;
LAB_0053e631:
              iVar9 = *(int *)(extraout_ECX + 0x18);
              pbVar25 = *(byte **)(unaff_EBP + -0x60);
              goto LAB_0053e67a;
            }
            if (cVar6 == '\b') {
              *(undefined1 *)(unaff_EBP + -0x36) = 0;
              *(undefined1 *)(unaff_EBP + -0x38) = uVar4;
              *(undefined1 *)(unaff_EBP + -0x37) = uVar5;
              bVar26 = false;
              *(undefined4 *)(unaff_EBP + -0x6c) = 2;
              goto LAB_0053e631;
            }
            bVar26 = true;
            uVar24 = 0;
          }
          *(undefined4 *)(unaff_EBP + -0xec) = _DAT_006f0bc0;
          *(undefined4 *)(unaff_EBP + -0xe8) = _DAT_006f0bc4;
          iVar9 = *(int *)(unaff_EBP + -0x68);
          if (bVar26) {
            iVar12 = iVar9 + -1;
            iVar9 = *(int *)(unaff_EBP + -0x94) + -1 + iVar9;
          }
          else {
            iVar12 = iVar9 - *(int *)(unaff_EBP + -0x94);
          }
          if (DAT_006f0bc2 < iVar12) {
            _DAT_006f0bc0 = CONCAT22((short)iVar12,DAT_006f0bc0);
          }
          if (iVar9 < DAT_006f0bc6) {
            _DAT_006f0bc4 = CONCAT22((short)iVar9,DAT_006f0bc4);
          }
          *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(unaff_EBP + -0x6c);
          FUN_00492d2c();
          FUN_004ac357(unaff_EBP + -0xfc);
          puVar14 = (undefined1 *)FUN_0046185f();
          cVar6 = *(char *)(extraout_ECX + 0x48);
          *(undefined1 *)(unaff_EBP + -0x4c) = *puVar14;
          *(undefined1 *)(unaff_EBP + -0x4b) = puVar14[1];
          *(undefined1 *)(unaff_EBP + -0x4a) = puVar14[2];
          if (cVar6 == '\0') {
            FUN_004b3e97(unaff_EBP + -0xcc);
            iVar9 = *(int *)(unaff_EBP + -200);
            iVar12 = *(int *)(unaff_EBP + -0xcc);
          }
          else {
            iVar12 = ((int)*(char *)(unaff_EBP + -0x38) - (int)*(char *)(unaff_EBP + -0x37)) *
                     *(int *)(unaff_EBP + -0x58) + *(int *)(unaff_EBP + -0x68);
            iVar9 = ((int)*(char *)(unaff_EBP + -0x37) + (int)*(char *)(unaff_EBP + -0x38)) *
                    *(int *)(unaff_EBP + -0xd4) + *(int *)(unaff_EBP + -0x80);
            *(int *)(unaff_EBP + -0xcc) = iVar12;
            *(int *)(unaff_EBP + -200) = iVar9;
          }
          *(undefined4 *)(unaff_EBP + -0x74) = 0;
          if (*(int *)(unaff_EBP + -0x6c) == 2) {
            *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x58);
          }
          OffsetRect((LPRECT)(unaff_EBP + -0xfc),iVar12,
                     iVar9 - ((uint)*(byte *)(unaff_EBP + -0x25) <<
                             ((char)*(undefined4 *)(unaff_EBP + -0x24) + 1U & 0x1f)));
          if (-1 < (int)(((int)DAT_006f0bc6 - *(int *)(unaff_EBP + -0xfc)) - 1U |
                         (*(int *)(unaff_EBP + -0xf4) - (int)DAT_006f0bc2) - 1U |
                         (*(int *)(unaff_EBP + -0xf0) - (int)DAT_006f0bc0) - 1U |
                        ((int)DAT_006f0bc4 - *(int *)(unaff_EBP + -0xf8)) - 1U)) {
            FUN_004a156c(uVar24,*(undefined4 *)(unaff_EBP + -0x24));
            *(uint *)(unaff_EBP + -0x50) =
                 ((*(char *)(unaff_EBP + -0x1e) != '\0') - 0x1fe) +
                 *(int *)(unaff_EBP + -0x24) * 0x200;
            iVar9 = *(int *)(unaff_EBP + -0x6c);
            if (iVar9 == 1) {
              iVar9 = 1;
            }
            else if (iVar9 == 2) {
              iVar9 = 2;
            }
            else if (iVar9 == 0x10) {
              iVar9 = 3;
            }
            else if (iVar9 == 0x20) {
              iVar9 = 4;
            }
            else {
              iVar9 = -1;
            }
            *(undefined1 *)(unaff_EBP + -0x84) = *(undefined1 *)(unaff_EBP + -0x4c);
            *(undefined1 *)(unaff_EBP + -0x83) = *(undefined1 *)(unaff_EBP + -0x4b);
            *(undefined1 *)(unaff_EBP + -0x82) = *(undefined1 *)(unaff_EBP + -0x4a);
            cVar6 = *(char *)(extraout_ECX + 0x48);
            *(undefined1 *)(unaff_EBP + -4) = 8;
            if (cVar6 == '\0') {
              FUN_00434ffd();
            }
            uVar8 = *(undefined4 *)(unaff_EBP + 0xc);
            iVar12 = (int)*(char *)(unaff_EBP + -0x1a);
            uVar13 = FUN_00434d3d(unaff_EBP + -0x130);
            FUN_004b469d(uVar13,iVar12);
            FUN_004b97eb(uVar13,iVar12);
            FUN_004b4722();
            *(undefined1 **)(unaff_EBP + -100) = &stack0xfffffe88;
            FUN_00461b74(unaff_EBP + -0x4c);
            FUN_004aef32(unaff_EBP + -0x108);
            iVar9 = iVar9 + -1;
            uVar13 = *(undefined4 *)(unaff_EBP + -0x6c);
            iVar12 = unaff_EBP + -0x150;
            *(undefined1 *)(unaff_EBP + -4) = 9;
            uVar35 = *(undefined4 *)(unaff_EBP + -0x74);
            uVar33 = 0;
            uVar32 = *(undefined4 *)(unaff_EBP + -0xf8);
            uVar31 = *(undefined4 *)(unaff_EBP + -0xfc);
            uVar30 = *(undefined4 *)(unaff_EBP + -0x100);
            uVar29 = *(undefined4 *)(unaff_EBP + -0xe4);
            uVar34 = *(undefined4 *)(unaff_EBP + -0x50);
            uVar28 = 0;
            FUN_004c656a(iVar12,0,uVar34,uVar29,uVar30,iVar9,uVar31,uVar32,0,uVar8,uVar35,uVar13);
            FUN_004c7b37(iVar12,uVar28,uVar34,uVar29,uVar30,iVar9,uVar31,uVar32,uVar33,uVar8,uVar35,
                         uVar13);
          }
          _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xec);
          pbVar25 = *(byte **)(unaff_EBP + -0x60);
          _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xe8);
          *(undefined1 *)(unaff_EBP + -4) = 3;
        }
      }
      if (*(int *)(unaff_EBP + -0x48) == 0x20) {
        if (pbVar25 == (byte *)(*(int *)(extraout_ECX + 0x34) + -6)) {
          pcVar15 = (char *)FUN_0053ef6b();
          if (((*pcVar15 == '\x10') || (*(char *)(unaff_EBP + -0x15) == '\0')) ||
             ((*(char *)(unaff_EBP + -0xd) != '\0' ||
              (pbVar25 == (byte *)(*(int *)(extraout_ECX + 0x34) + -6))))) goto LAB_0053e9b5;
        }
        else if (((*(char *)(unaff_EBP + -0xd) != '\0') || (*(char *)(unaff_EBP + -0x39) != '\0'))
                || ((pbVar25 == (byte *)(*(int *)(extraout_ECX + 0x34) + -6) ||
                    ((*(char *)(unaff_EBP + -0x15) == '\0' || (*(char *)(unaff_EBP + -0x32) == '\0')
                     ))))) goto LAB_0053e9b5;
      }
      else {
LAB_0053e9b5:
        iVar9 = *(int *)(unaff_EBP + -0x48);
        if (iVar9 == 1) {
          *(undefined4 *)(unaff_EBP + -0x88) = 1;
        }
        else if (iVar9 == 2) {
          *(undefined4 *)(unaff_EBP + -0x88) = 2;
        }
        else if (iVar9 == 0x10) {
          *(undefined4 *)(unaff_EBP + -0x88) = 3;
        }
        else {
          if (iVar9 != 0x20) goto LAB_0053ef30;
          *(undefined4 *)(unaff_EBP + -0x88) = 4;
        }
        *(int *)(unaff_EBP + -0x50) = iVar9;
        FUN_00492d2c();
        FUN_004ac357(unaff_EBP + -0xc0);
        *(undefined4 *)(unaff_EBP + -0xc4) = 0;
        if (iVar9 == 2) {
          *(undefined4 *)(unaff_EBP + -0xc4) = *(undefined4 *)(unaff_EBP + -0x58);
        }
        cVar6 = (char)*(undefined4 *)(unaff_EBP + -0x24);
        bVar20 = cVar6 + 1;
        if (iVar9 == 0x20) {
          iVar16 = ((4 >> (3U - cVar6 & 0x1f)) -
                   ((uint)*(byte *)(unaff_EBP + -0x1d) << (bVar20 & 0x1f))) +
                   *(int *)(unaff_EBP + -0x58) + *(int *)(unaff_EBP + -0x80);
          iVar12 = *(int *)(unaff_EBP + -0x68) + -1;
        }
        else {
          iVar16 = *(int *)(unaff_EBP + -0x80) -
                   ((uint)*(byte *)(unaff_EBP + -0x1d) << (bVar20 & 0x1f));
          iVar12 = *(int *)(unaff_EBP + -0x68);
        }
        OffsetRect((LPRECT)(unaff_EBP + -0xc0),iVar12,iVar16);
        piVar2 = *(int **)(unaff_EBP + 8);
        if (-1 < (int)((*(int *)(unaff_EBP + -0xb4) - piVar2[1]) - 1U |
                       (piVar2[3] - *(int *)(unaff_EBP + -0xbc)) - 1U |
                       (piVar2[2] - *(int *)(unaff_EBP + -0xc0)) - 1U |
                      (*(int *)(unaff_EBP + -0xb8) - *piVar2) - 1U)) {
          *(undefined1 *)(unaff_EBP + -0x8c) = *(undefined1 *)(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -0x8b) = *(undefined1 *)(unaff_EBP + -0x1b);
          *(undefined1 *)(unaff_EBP + -0x8a) = *(undefined1 *)(unaff_EBP + -0x1a);
          cVar6 = *(char *)(extraout_ECX + 0x48);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          if (cVar6 == '\0') {
            FUN_00434ffd();
          }
          iVar12 = (int)*(char *)(extraout_ECX + 6);
          uVar8 = FUN_00434d3d(unaff_EBP + -0x128);
          FUN_004b469d(uVar8,iVar12);
          FUN_004b97eb(uVar8,iVar12);
          bVar20 = *pbVar25;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          *(undefined4 *)(unaff_EBP + -0x30) = 1;
          if ((bVar20 & 0xe) != 0) {
            *(undefined4 *)(unaff_EBP + -0x30) = 2;
          }
          bVar20 = pbVar25[1];
          if ((((bVar20 == 0xff) || (bVar20 == 2)) || (bVar20 == 0xc)) ||
             ((bVar20 == 0xd || (bVar20 == 0xe)))) {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          if ((*(char *)(unaff_EBP + -0xd) != '\0') &&
             ((((bVar20 == 3 || (bVar20 == 5)) ||
               ((bVar20 == 6 || ((bVar20 == 0xf || (bVar20 == 0x17)))))) &&
              (cVar6 = FUN_0053d7ae(), cVar6 == '\0')))) {
            *(undefined4 *)(unaff_EBP + -0x30) = 0;
          }
          if (((*(int *)(unaff_EBP + -0x30) == 2) && (*(char *)(unaff_EBP + -0xd) != '\0')) &&
             (iVar12 = FUN_00401f6f(), iVar12 != 0)) {
            bVar20 = pbVar25[1];
            if ((bVar20 == 0x16) && ((*pbVar25 & 6) == 0)) {
              *(undefined4 *)(unaff_EBP + -0x30) = 1;
            }
            else if ((((bVar20 == 3) || ((bVar20 == 5 || (bVar20 == 6)))) || (bVar20 == 0xf)) ||
                    (bVar20 == 0x17)) {
              *(undefined4 *)(unaff_EBP + -0x30) = 0;
            }
          }
          *(undefined4 *)(unaff_EBP + -0x40) = 0;
          if (0 < *(int *)(unaff_EBP + -0x30)) {
            do {
              *(undefined4 *)(unaff_EBP + -0x74) = 0;
              *(undefined4 *)(unaff_EBP + -0x50) = 0;
              FUN_004b4722();
              if (*(int *)(unaff_EBP + -0x40) == 0) {
                bVar20 = *pbVar25;
                if ((((bVar20 & 6) == 0) || (bVar18 = pbVar25[1], bVar18 == 3)) ||
                   ((bVar18 == 5 || (((bVar18 == 6 || (bVar18 == 0xf)) || (bVar18 == 0x17)))))) {
                  *(undefined1 *)(unaff_EBP + -0x31) = 0;
                }
                else {
                  *(undefined1 *)(unaff_EBP + -0x31) = 1;
                  *(uint *)(unaff_EBP + -0x78) = ((bVar20 & 2) != 0) + 7;
                }
                iVar9 = *(int *)(unaff_EBP + -0x60);
                FUN_004a156c(*(undefined2 *)(iVar9 + 2 + *(int *)(extraout_ECX + 0x18) * 2),
                             *(undefined4 *)(unaff_EBP + -0x24));
                iVar12 = *(int *)(unaff_EBP + -0x104);
                if (*(char *)(unaff_EBP + -0x31) == '\0') {
                  cVar6 = *(char *)(iVar9 + 1);
                  if ((*(char *)(unaff_EBP + -0xd) != '\0') && (cVar6 == '\x16')) {
                    cVar6 = '\x01';
                  }
                  iVar9 = FUN_0053d6da(cVar6,unaff_EBP + -0x74,unaff_EBP + -0x1c,
                                       *(undefined4 *)(unaff_EBP + -0x48));
                }
                else {
                  iVar9 = (*(int *)(unaff_EBP + -0x24) * 0x100 + *(int *)(unaff_EBP + -0x78)) * 2 +
                          -0x200;
                }
LAB_0053edb0:
                *(undefined4 *)(unaff_EBP + -0xe0) = _DAT_006f0bc0;
                *(undefined4 *)(unaff_EBP + -0xdc) = _DAT_006f0bc4;
                if (*(char *)(unaff_EBP + -0x3a) != '\0') {
                  iVar16 = *(int *)(unaff_EBP + -0x48);
                  if (iVar16 == 1) {
LAB_0053ee12:
                    iVar16 = (int)DAT_006f0bc2;
                    iVar22 = *(int *)(unaff_EBP + -0xc0) + *(int *)(unaff_EBP + -0x94);
                    *(int *)(unaff_EBP + -100) = iVar16;
                    *(int *)(unaff_EBP + -0x9c) = iVar22;
                    puVar17 = (undefined2 *)(unaff_EBP + -100);
                    if (iVar16 <= iVar22) {
                      puVar17 = (undefined2 *)(unaff_EBP + -0x9c);
                    }
                    _DAT_006f0bc0 = CONCAT22(*puVar17,DAT_006f0bc0);
                  }
                  else {
                    if (iVar16 != 2) {
                      if (iVar16 == 4) goto LAB_0053ee12;
                      if (iVar16 != 8) goto LAB_0053ee46;
                    }
                    iVar22 = (int)DAT_006f0bc6;
                    iVar16 = *(int *)(unaff_EBP + -0xb8) - *(int *)(unaff_EBP + -0x94);
                    *(int *)(unaff_EBP + -0x9c) = iVar22;
                    *(int *)(unaff_EBP + -100) = iVar16;
                    puVar17 = (undefined2 *)(unaff_EBP + -0x9c);
                    if (iVar16 <= iVar22) {
                      puVar17 = (undefined2 *)(unaff_EBP + -100);
                    }
                    _DAT_006f0bc4 = CONCAT22(*puVar17,DAT_006f0bc4);
                  }
                }
LAB_0053ee46:
                *(undefined1 *)(unaff_EBP + -0x51) = 0x7f;
                *(undefined1 *)(unaff_EBP + -0x52) = 0x7f;
                *(undefined1 *)(unaff_EBP + -0x53) = 0x7f;
                *(undefined1 *)(unaff_EBP + -0x54) = 0x7f;
                *(undefined1 *)(unaff_EBP + -4) = 0xb;
                cVar6 = FUN_004b462b();
                if ((cVar6 != '\0') && (*(int *)(unaff_EBP + -0x40) != 1)) {
                  *(undefined1 **)(unaff_EBP + -100) = &stack0xfffffe8c;
                  puVar14 = (undefined1 *)FUN_004aef32();
                  if ((undefined1 *)(unaff_EBP + -0x54) != puVar14) {
                    *(undefined1 *)(unaff_EBP + -0x54) = *puVar14;
                    *(undefined1 *)(unaff_EBP + -0x53) = puVar14[1];
                    *(undefined1 *)(unaff_EBP + -0x52) = puVar14[2];
                    *(undefined1 *)(unaff_EBP + -0x51) = puVar14[3];
                  }
                }
                uVar8 = *(undefined4 *)(unaff_EBP + -0x48);
                iVar22 = *(int *)(unaff_EBP + -0x88) + -1;
                uVar13 = *(undefined4 *)(unaff_EBP + -0xc4);
                uVar35 = *(undefined4 *)(unaff_EBP + 0xc);
                uVar34 = 0;
                uVar32 = *(undefined4 *)(unaff_EBP + -0xbc);
                uVar31 = *(undefined4 *)(unaff_EBP + -0xc0);
                uVar30 = *(undefined4 *)(unaff_EBP + -0x50);
                iVar16 = unaff_EBP + -0x170;
                uVar29 = *(undefined4 *)(unaff_EBP + -0x74);
                FUN_004c656a(iVar16,uVar29,iVar9,uVar30,iVar12,iVar22,uVar31,uVar32,0,uVar35,uVar13,
                             uVar8);
                FUN_004c7b37(iVar16,uVar29,iVar9,uVar30,iVar12,iVar22,uVar31,uVar32,uVar34,uVar35,
                             uVar13,uVar8);
                _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0xe0);
                pbVar25 = *(byte **)(unaff_EBP + -0x60);
                iVar9 = *(int *)(unaff_EBP + -0x48);
                _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0xdc);
                *(undefined1 *)(unaff_EBP + -4) = 3;
              }
              else {
                if (*(char *)(unaff_EBP + -0x31) != '\0') {
                  if (iVar9 == 0x20) {
                    iVar9 = *(int *)(unaff_EBP + -0x24);
LAB_0053ed2c:
                    iVar12 = iVar9 * 0x100 + 0x5fc;
                    iVar9 = iVar9 * 0x200 + -0x1ee;
                  }
                  else {
                    iVar9 = *(int *)(unaff_EBP + -0x24);
                    if (*(int *)(unaff_EBP + -0x78) == 7) goto LAB_0053ed2c;
                    iVar12 = iVar9 * 0x100 + 0x5fd;
                    iVar9 = iVar9 * 0x200 + -0x1ec;
                  }
                  FUN_004b4722();
LAB_0053ed6f:
                  if (((*(int *)(unaff_EBP + -0x40) == 1) && (*(int *)(unaff_EBP + -0x48) == 0x20))
                     && ((*(int *)(unaff_EBP + -0x78) == 7 || (*(int *)(unaff_EBP + -0x78) == 8))))
                  {
                    OffsetRect((LPRECT)(unaff_EBP + -0xc0),0,
                               -((0x5c >> (3U - (char)*(undefined4 *)(unaff_EBP + -0x24) & 0x1f)) +
                                (*(int *)(unaff_EBP + -0x24) == 3) + 1));
                  }
                  goto LAB_0053edb0;
                }
                if (((*(char *)(unaff_EBP + -0xd) == '\0') || (pbVar25[1] != 0x16)) ||
                   (cVar6 = FUN_0053d7ae(), cVar6 != '\0')) {
                  iVar12 = *(int *)(unaff_EBP + -0x24) * 0x100 + 0x5fe;
                  iVar9 = FUN_0053d6da(*(undefined1 *)(*(int *)(unaff_EBP + -0x60) + 1),
                                       unaff_EBP + -0x74,unaff_EBP + -0x1c,
                                       *(undefined4 *)(unaff_EBP + -0x48));
                  goto LAB_0053ed6f;
                }
              }
              *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
            } while (*(int *)(unaff_EBP + -0x40) < *(int *)(unaff_EBP + -0x30));
          }
        }
      }
LAB_0053ef30:
      bVar20 = *(byte *)(unaff_EBP + -0x2b);
      *(undefined1 *)(unaff_EBP + -4) = 2;
    }
    else {
      *(undefined1 **)(unaff_EBP + -100) = &stack0xfffffe8c;
      iVar9 = FUN_00488924();
      if (iVar9 != 0) goto LAB_0053dec6;
    }
    pbVar25 = pbVar25 + 6;
    *(char *)(unaff_EBP + -0x1c) = *(char *)(unaff_EBP + -0x1c) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0x1b) = *(char *)(unaff_EBP + -0x1b) + *(char *)(extraout_ECX + 0xb);
    *(char *)(unaff_EBP + -0x44) = *(char *)(unaff_EBP + -0x44) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0x43) = *(char *)(unaff_EBP + -0x43) + *(char *)(extraout_ECX + 0xb);
    *(byte **)(unaff_EBP + -0x60) = pbVar25;
  } while( true );
}

