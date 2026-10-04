
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00483572(void)

{
  float *pfVar1;
  ushort uVar2;
  undefined1 uVar3;
  char cVar4;
  short sVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  int *extraout_ECX;
  int iVar11;
  int iVar12;
  int *piVar13;
  int unaff_EBP;
  undefined2 uVar14;
  undefined4 uVar15;
  bool bVar16;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x80) = extraout_ECX;
  FUN_004819f6();
  iVar7 = extraout_ECX[0x12];
  uVar8 = extraout_ECX[10];
  pfVar1 = (float *)(extraout_ECX + 3);
  *(int *)(unaff_EBP + -0xa4) = iVar7;
  *(int *)(unaff_EBP + -0x40) = (int)*(short *)(iVar7 + 0x4c);
  if ((uVar8 >> 9 & 1) != 0) {
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
  }
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar7 + 0xf4);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar7 + 0xf8);
  if ((uVar8 >> 0x10 & 1) != 0) {
    puVar6 = (undefined4 *)FUN_00407200(unaff_EBP + -0x60,iVar7);
    *(undefined4 *)(unaff_EBP + -0x34) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x30) = puVar6[1];
  }
  piVar13 = extraout_ECX;
  if ((char)extraout_ECX[10] == '\0') {
    iVar7 = extraout_ECX[4];
    *(undefined4 *)(unaff_EBP + -0x68) = 0;
    *(undefined4 *)(unaff_EBP + -100) = 0;
    FUN_00483ea9(unaff_EBP + -0x34,*pfVar1,iVar7,*(undefined4 *)(unaff_EBP + -0x40),
                 unaff_EBP + -0x68);
    uVar15 = 0xffffffff;
    if (((*(uint *)(unaff_EBP + -0x30) != *(uint *)(unaff_EBP + -100)) ||
        (*(uint *)(unaff_EBP + -0x34) != *(uint *)(unaff_EBP + -0x68))) &&
       ((((*(uint *)(unaff_EBP + -100) ^ *(uint *)(unaff_EBP + -0x30)) & 0xfffffff0) != 0 ||
        (((*(uint *)(unaff_EBP + -0x68) ^ *(uint *)(unaff_EBP + -0x34)) & 0xfffffff0) != 0)))) {
      uVar15 = FUN_00452129(unaff_EBP + -0x68);
    }
    FUN_00483fc1(extraout_ECX[0x13],*(undefined4 *)(unaff_EBP + -0x40),0,pfVar1);
    *(undefined1 *)(unaff_EBP + -0x24) = 0;
    *(undefined1 *)(unaff_EBP + -0x23) = 0;
    *(undefined1 *)(unaff_EBP + -0x22) = 0;
    *(undefined1 *)(unaff_EBP + -0x21) = 0;
    *(undefined1 *)(unaff_EBP + -0x20) = 0;
    *(undefined1 *)(unaff_EBP + -0x1f) = 0;
    *(undefined1 *)(unaff_EBP + -0x1e) = 0;
    iVar7 = FUN_00481593(unaff_EBP + -0x68,uVar15);
    if (iVar7 == 0) {
      *(undefined1 *)(unaff_EBP + -0x22) = 1;
LAB_004836c7:
      if (iVar7 == 6) {
        *(undefined4 *)(unaff_EBP + -0x60) = 100;
        *(undefined2 *)(unaff_EBP + -0x5c) = 0;
        FUN_0048404e(unaff_EBP + -0x68);
        if (extraout_ECX[0x15] < *(int *)(unaff_EBP + -0x60)) {
          extraout_ECX[0x15] = *(int *)(unaff_EBP + -0x60);
        }
        goto LAB_00483e78;
      }
    }
    else if (iVar7 == 1) {
      *(undefined1 *)(unaff_EBP + -0x21) = 1;
    }
    else if ((iVar7 == 2) || (iVar7 == 3)) {
      *(undefined1 *)(unaff_EBP + -0x1f) = 1;
    }
    else if (iVar7 == 4) {
      *(undefined1 *)(unaff_EBP + -0x1e) = 1;
    }
    else {
      if (iVar7 != 5) goto LAB_004836c7;
      *(undefined1 *)(unaff_EBP + -0x20) = 1;
    }
  }
  else {
    iVar7 = extraout_ECX[0xc];
    iVar12 = extraout_ECX[0xd];
    iVar11 = extraout_ECX[0xe];
    *(int *)(unaff_EBP + -200) = iVar7;
    *(int *)(unaff_EBP + -0xa8) = iVar12;
    *(int *)(unaff_EBP + -0xc0) = iVar11;
    if ((((((iVar7 < 1) || (0x200 < iVar7)) || (iVar12 < 1)) ||
         ((0x200 < iVar12 || (iVar12 < iVar7)))) || (iVar11 < iVar7)) || (iVar12 < iVar11))
    goto LAB_00483e78;
    *(int *)(unaff_EBP + -0x2c) = extraout_ECX[8] * 10;
    if (*(char *)(unaff_EBP + 8) == '\0') {
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    }
    iVar11 = extraout_ECX[7];
    if (extraout_ECX[7] < extraout_ECX[9]) {
      iVar11 = extraout_ECX[9];
    }
    *(int *)(unaff_EBP + -0xc4) = iVar12 * *(int *)(unaff_EBP + -0xa8);
    bVar10 = *(byte *)((int)extraout_ECX + 0x29);
    *(int *)(unaff_EBP + -0xcc) = iVar11 * 10;
    *(int *)(unaff_EBP + -0xb8) = iVar7 * iVar7;
    *(undefined4 *)(unaff_EBP + -0x90) = 0;
    *(undefined4 *)(unaff_EBP + -0x8c) = 0;
    *(undefined4 *)(unaff_EBP + -0x88) = 0;
    *(undefined4 *)(unaff_EBP + -0x70) = 0;
    if ((bVar10 & 8) == 0) {
      uVar15 = FUN_00435a8f(*(int *)(unaff_EBP + -0xa4) + 0xfc,*(undefined4 *)(unaff_EBP + -0x40));
      *(undefined4 *)(unaff_EBP + -0x70) = uVar15;
    }
    *(undefined4 *)(unaff_EBP + -0x78) = 0;
    if (*(int *)(unaff_EBP + -0x70) != 0) {
      iVar7 = 0;
      *(undefined4 *)(unaff_EBP + 8) = 0;
      do {
        bVar10 = (byte)iVar7;
        uVar8 = 1 << (bVar10 & 0x1f);
        *(uint *)(unaff_EBP + -0x54) = uVar8;
        if ((*(uint *)(unaff_EBP + -0x70) & uVar8) != 0) {
          *(uint *)(unaff_EBP + -0x78) =
               *(uint *)(unaff_EBP + -0x78) |
               1 << (bVar10 - 1 & 7) | 1 << (bVar10 + 1 & 7) | *(uint *)(unaff_EBP + -0x54);
        }
        iVar7 = *(int *)(unaff_EBP + 8) + 1;
        *(int *)(unaff_EBP + 8) = iVar7;
      } while (iVar7 < 8);
    }
    *(int *)(unaff_EBP + -0x48) = extraout_ECX[0x11];
    if (*(int *)(unaff_EBP + -0x2c) != 0) {
      *(undefined4 *)(unaff_EBP + -0x48) = 0x10;
    }
    *(float *)(unaff_EBP + -0xa0) = _DAT_00666a54 / (float)*(int *)(unaff_EBP + -0x48);
    if ((*(int *)(unaff_EBP + -0x2c) < 1) || (iVar11 * 10 != 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    *(undefined1 *)(unaff_EBP + -0x1b) = 0;
    *(undefined1 *)(unaff_EBP + -0x1a) = 0;
    *(undefined1 *)(unaff_EBP + -0x19) = 0;
    *(undefined1 *)(unaff_EBP + -0x18) = 0;
    *(undefined1 *)(unaff_EBP + -0x17) = 0;
    *(undefined1 *)(unaff_EBP + -0x16) = 0;
    *(undefined1 *)(unaff_EBP + -0x1c) = uVar3;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    do {
      uVar9 = 1 << ((byte)*(undefined4 *)(unaff_EBP + -0x28) & 0x1f);
      uVar8 = extraout_ECX[10];
      *(uint *)(unaff_EBP + -0xb4) = uVar9;
      if ((uVar8 & uVar9) != 0) {
        if ((*(uint *)(unaff_EBP + -0x70) & uVar9) == 0) {
          iVar7 = (*(int *)(unaff_EBP + -0x40) + *(int *)(unaff_EBP + -0x28)) % 8;
          *(int *)(unaff_EBP + -0x4c) = iVar7;
          *(int *)(unaff_EBP + 8) = -*(int *)(unaff_EBP + -0xa8);
          *(int *)(unaff_EBP + -0xbc) = (iVar7 + 4) % 8;
          uVar15 = __ftol();
          *(undefined4 *)(unaff_EBP + -0x74) = uVar15;
          *(int *)(unaff_EBP + 8) = -*(int *)(unaff_EBP + -200);
          iVar7 = __ftol();
          if (0 < *(int *)(unaff_EBP + -0x2c)) {
            *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + -1;
            iVar7 = iVar7 + 1;
            if (-1 < iVar7) {
              iVar7 = -1;
            }
          }
          FUN_00483fc1(piVar13[0x13],*(undefined4 *)(unaff_EBP + -0x40),
                       *(undefined4 *)(unaff_EBP + -0x4c),pfVar1);
          *(undefined1 *)(unaff_EBP + 0xb) = 0;
          *(int *)(unaff_EBP + -0x38) = iVar7;
          if (*(int *)(unaff_EBP + -0x74) <= iVar7) {
            *(int *)(unaff_EBP + -0x6c) = -iVar7;
            iVar12 = -*(int *)(unaff_EBP + -0x48);
            *(int *)(unaff_EBP + -0x50) = iVar7 * *(int *)(unaff_EBP + -0x48);
            *(int *)(unaff_EBP + -0x24) = iVar12;
            do {
              if (*(char *)(unaff_EBP + 0xb) != '\0') break;
              *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x6c);
              if ((extraout_ECX[10] & 1 << ((byte)((*(int *)(unaff_EBP + -0x28) + 2) % 8) & 0x1f))
                  == 0) {
                iVar7 = *(int *)(unaff_EBP + -0x58);
              }
              else {
                iVar7 = *(int *)(unaff_EBP + -0x6c) + -1;
                *(int *)(unaff_EBP + -0x58) = iVar7;
              }
              if (*(int *)(unaff_EBP + -0x38) <= iVar7) {
                *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x50);
                *(int *)(unaff_EBP + -0x54) = (iVar7 - *(int *)(unaff_EBP + -0x38)) + 1;
                *(float *)(unaff_EBP + -0xac) = (float)*(int *)(unaff_EBP + -0x50);
                do {
                  *(undefined4 *)(unaff_EBP + -0x60) = 0;
                  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
                  *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + -0x7c);
                  FUN_00483ea9(unaff_EBP + -0x34,*(float *)(unaff_EBP + -0x10) + *pfVar1,
                               *(float *)(unaff_EBP + -0xac) + (float)extraout_ECX[4],
                               *(undefined4 *)(unaff_EBP + -0x4c),unaff_EBP + -0x90);
                  *(undefined4 *)(unaff_EBP + -0x44) = 0xffffffff;
                  *(undefined4 *)(unaff_EBP + -0xd0) = *(undefined4 *)(unaff_EBP + -0x10);
                  do {
                    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
                    uVar15 = __ftol();
                    *(undefined4 *)(unaff_EBP + -0x10) = uVar15;
                    uVar15 = __ftol();
                    *(undefined4 *)(unaff_EBP + -0x14) = uVar15;
                    uVar8 = *(uint *)(unaff_EBP + -0x44);
                    if ((uVar8 == 0xffffffff) || (uVar8 == 8)) {
                      if (*(int *)(unaff_EBP + -0xcc) < *(int *)(unaff_EBP + -0x2c)) {
                        bVar16 = uVar8 == 8;
                      }
                      else {
                        bVar16 = uVar8 == 0xffffffff;
                      }
                      iVar7 = 0;
                      if (bVar16) {
                        iVar7 = *(int *)(unaff_EBP + -0xcc);
                      }
                      uVar14 = (undefined2)*(undefined4 *)(unaff_EBP + -0x3c);
                      *(int *)(unaff_EBP + -0xb0) =
                           1 << ((byte)*(undefined4 *)(unaff_EBP + -0x28) & 0x1f);
LAB_00483be3:
                      if (iVar7 != 0) {
                        *(int *)(unaff_EBP + -0x3c) =
                             *(int *)(unaff_EBP + -0x14) * *(int *)(unaff_EBP + -0x14) +
                             *(int *)(unaff_EBP + -0x10) * *(int *)(unaff_EBP + -0x10);
                        if (((float10)*(int *)(unaff_EBP + -0x3c) <=
                             (float10)*(int *)(unaff_EBP + -0xc4)) &&
                           ((float10)*(int *)(unaff_EBP + -0xb8) <=
                            (float10)*(int *)(unaff_EBP + -0x3c))) {
                          iVar12 = __ftol();
                          iVar12 = iVar12 - *(int *)(unaff_EBP + -0xc0);
                          *(int *)(unaff_EBP + -0x3c) = iVar12;
                          if (iVar12 < 0) {
                            *(int *)(unaff_EBP + -0x3c) = -iVar12;
                          }
                          iVar12 = __ftol();
                          uVar8 = extraout_ECX[10];
                          *(int *)(unaff_EBP + -0x88) = (iVar7 - iVar12) + 100;
                          if ((uVar8 >> 0xd & 1) != 0) {
                            uVar8 = FUN_0046f556();
                            *(uint *)(unaff_EBP + -0x88) =
                                 *(int *)(unaff_EBP + -0x88) + -10 + uVar8 % 0x14;
                          }
                          if ((*(uint *)(unaff_EBP + -0x78) & *(uint *)(unaff_EBP + -0xb4)) == 0) {
                            *(int *)(unaff_EBP + -0x88) = *(int *)(unaff_EBP + -0x88) + 0x19;
                          }
                          FUN_00483ea9(unaff_EBP + -0x34,(float)*(int *)(unaff_EBP + -0x10),
                                       (float)*(int *)(unaff_EBP + -0x14),
                                       *(undefined4 *)(unaff_EBP + -0x4c),unaff_EBP + -0x60);
                          iVar7 = *(int *)(unaff_EBP + -0x80);
                          if ((*(int *)(unaff_EBP + -0x5c) == *(int *)(iVar7 + 0x70)) &&
                             (*(int *)(unaff_EBP + -0x60) == *(int *)(iVar7 + 0x6c))) {
                            *(int *)(unaff_EBP + -0x88) = *(int *)(unaff_EBP + -0x88) + 0x14;
                          }
                          iVar12 = FUN_00481593(unaff_EBP + -0x90,*(undefined4 *)(unaff_EBP + -0x4c)
                                               );
                          if (iVar12 == 0) {
                            *(undefined1 *)(unaff_EBP + -0x1a) = 1;
                          }
                          else if (iVar12 == 1) {
                            *(undefined1 *)(unaff_EBP + -0x19) = 1;
                          }
                          else if ((iVar12 == 2) || (iVar12 == 3)) {
                            *(undefined1 *)(unaff_EBP + -0x17) = 1;
                          }
                          else if (iVar12 == 4) {
                            *(undefined1 *)(unaff_EBP + -0x16) = 1;
                          }
                          else if (iVar12 == 5) {
                            *(undefined1 *)(unaff_EBP + -0x18) = 1;
                          }
                          if (((iVar12 != 0) && (iVar12 != 1)) && (iVar12 != 2)) {
                            if (iVar12 == 3) {
                              *(undefined1 *)(unaff_EBP + 0xb) = 1;
                            }
                            else if ((iVar12 != 4) && (iVar12 != 5)) {
                              *(undefined2 *)(unaff_EBP + -0x82) =
                                   *(undefined2 *)(unaff_EBP + -0xb0);
                              *(undefined2 *)(unaff_EBP + -0x84) = uVar14;
                              FUN_0048404e(unaff_EBP + -0x90);
                              if (*(int *)(iVar7 + 0x54) < *(int *)(unaff_EBP + -0x88)) {
                                *(int *)(iVar7 + 0x54) = *(int *)(unaff_EBP + -0x88);
                              }
                              break;
                            }
                          }
                        }
                      }
                    }
                    else if (*(int *)(unaff_EBP + -0x2c) != 0) {
                      switch(uVar8 & 7) {
                      case 1:
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x10;
                      case 0:
                        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + -0x10;
                        break;
                      case 3:
                        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x10;
                      case 2:
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x10;
                        break;
                      case 5:
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -0x10;
                      case 4:
                        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x10;
                        break;
                      case 7:
                        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + -0x10;
                      case 6:
                        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + -0x10;
                      }
                      iVar7 = *(int *)(unaff_EBP + -0x38);
                      iVar12 = *(int *)(unaff_EBP + -0x14) >> 4;
                      iVar11 = *(int *)(unaff_EBP + -0x10) >> 4;
                      if (iVar12 == iVar7) {
                        if ((iVar7 <= iVar11) && (iVar11 <= *(int *)(unaff_EBP + -0x58))) {
LAB_00483a7d:
                          FUN_00483ea9(unaff_EBP + -0x34,(float)*(int *)(unaff_EBP + -0x10),
                                       (float)*(int *)(unaff_EBP + -0x14),
                                       *(undefined4 *)(unaff_EBP + -0x4c),unaff_EBP + -0x60);
                          cVar4 = FUN_00422665(unaff_EBP + -0x60);
                          if ((cVar4 == '\0') &&
                             (iVar12 = FUN_004324fc(unaff_EBP + -0x60,
                                                    *(undefined4 *)
                                                     (*(int *)(unaff_EBP + -0xa4) + 0x110)),
                             iVar12 != 0)) {
                            FUN_00457da4();
                            sVar5 = FUN_004561a0(0x1a);
                            if ((sVar5 != 0) &&
                               ((((int)*(short *)(iVar12 + 0x4c) == *(int *)(unaff_EBP + -0xbc) &&
                                 (uVar2 = *(ushort *)(*(int *)(iVar12 + 0x118) + 0x84),
                                 iVar7 = 1 << ((byte)*(undefined4 *)(unaff_EBP + -0x44) & 0x1f),
                                 *(int *)(unaff_EBP + -0xb0) = iVar7, (uVar2 & (ushort)iVar7) != 0))
                                && (iVar7 = FUN_00636bef(0), iVar7 < 2)))) {
                              iVar7 = (*(int *)(iVar12 + 0x134) - *(int *)(iVar12 + 0x130)) / 0x24;
                              if (iVar7 == 1 || iVar7 + -1 < 0) {
                                iVar7 = 0;
                              }
                              else {
                                iVar7 = *(int *)(iVar12 + 0x130) + 0x24;
                              }
                              if (iVar7 == 0) {
                                iVar7 = 0;
                              }
                              else {
                                uVar8 = (uint)*(short *)(iVar7 + 0x10);
                                iVar11 = *(int *)(iVar12 + 0xdc);
                                iVar7 = 0;
                                if ((0 < (int)uVar8) &&
                                   (uVar8 < (*(int *)(iVar11 + 0x1c) - *(int *)(iVar11 + 0x18) >> 2)
                                            + 1U)) {
                                  iVar7 = *(int *)(*(int *)(iVar11 + 0x18) + -4 + uVar8 * 4);
                                }
                              }
                              if ((iVar7 == 0) ||
                                 (iVar7 == *(int *)(*(int *)(unaff_EBP + -0x80) + 0x4c))) {
                                iVar7 = *(int *)(unaff_EBP + -0x2c);
                                uVar14 = *(undefined2 *)(iVar12 + 0xf0);
                                goto LAB_00483be3;
                              }
                              *(undefined1 *)(unaff_EBP + -0x1b) = 1;
                              *(undefined2 *)(*(int *)(unaff_EBP + -0x80) + 0x8c) =
                                   *(undefined2 *)(iVar7 + 0xf0);
                            }
                          }
                        }
                      }
                      else if ((iVar12 <= iVar7) ||
                              ((iVar7 < iVar11 && (iVar11 < *(int *)(unaff_EBP + -0x58)))))
                      goto LAB_00483a7d;
                    }
                    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + 1;
                  } while (*(int *)(unaff_EBP + -0x44) < 9);
                  *(int *)(unaff_EBP + -0x7c) =
                       *(int *)(unaff_EBP + -0x7c) + *(int *)(unaff_EBP + -0x48);
                  piVar13 = (int *)(unaff_EBP + -0x54);
                  *piVar13 = *piVar13 + -1;
                } while (*piVar13 != 0);
                piVar13 = *(int **)(unaff_EBP + -0x80);
                iVar12 = *(int *)(unaff_EBP + -0x24);
              }
              *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + -1;
              *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x6c) + 1;
              *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + iVar12;
            } while (*(int *)(unaff_EBP + -0x74) <= *(int *)(unaff_EBP + -0x38));
          }
        }
        else {
          *(undefined1 *)(unaff_EBP + -0x17) = 1;
        }
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
    } while (*(int *)(unaff_EBP + -0x28) < 8);
    if ((uint)piVar13[0x26] < (uint)(piVar13[1] - *piVar13 >> 4)) {
      FUN_00460a05(piVar13);
      iVar7 = piVar13[1];
      iVar12 = *piVar13;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004b4015(iVar12,iVar7);
      for (iVar7 = *(int *)(unaff_EBP + -0x9c); iVar7 != *(int *)(unaff_EBP + -0x98);
          iVar7 = iVar7 + 0x10) {
        if (*(short *)(iVar7 + 0xc) != 0) {
          FUN_0048404e(iVar7);
          *(undefined4 *)(iVar7 + 8) = 0;
        }
      }
      for (iVar7 = piVar13[1] - *piVar13 >> 4; iVar7 < piVar13[0x26]; iVar7 = iVar7 + 1) {
        iVar12 = *(int *)(unaff_EBP + -0x98);
        iVar11 = *(int *)(unaff_EBP + -0x9c);
        uVar8 = FUN_0046f556();
        for (iVar12 = (uVar8 % (uint)(iVar12 - iVar11 >> 4)) * 0x10 + *(int *)(unaff_EBP + -0x9c);
            iVar12 != *(int *)(unaff_EBP + -0x98); iVar12 = iVar12 + 0x10) {
          if (*(int *)(iVar12 + 8) != 0) {
            FUN_0048404e(iVar12);
            *(undefined4 *)(iVar12 + 8) = 0;
            break;
          }
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005db425();
    }
    if ((piVar13[1] - *piVar13 & 0xfffffff0U) != 0) goto LAB_00483e78;
  }
  iVar7 = FUN_00484015();
  piVar13[0x22] = iVar7;
LAB_00483e78:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

