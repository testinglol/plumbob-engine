
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479f0c(void)

{
  short *psVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  byte bVar6;
  short sVar7;
  undefined2 uVar8;
  int iVar9;
  undefined1 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int extraout_ECX;
  byte *pbVar16;
  uint uVar17;
  int unaff_EBP;
  short sVar18;
  ushort uVar19;
  bool bVar20;
  undefined4 uVar21;
  
  FUN_00634c24();
  uVar2 = *(undefined4 *)(extraout_ECX + 0x10);
  *(int *)(unaff_EBP + -0x38) = extraout_ECX;
  bVar6 = DAT_006e54d4 & 1;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -100) = uVar2;
  if (bVar6 == 0) {
    DAT_006e54d4 = DAT_006e54d4 | 1;
    DAT_006e54c8 = 0;
    DAT_006e54cc = 0;
    _DAT_006e54d0 = 0;
    FUN_00635543(&LAB_0047b16e);
  }
  if ((DAT_006e54d4 & 2) == 0) {
    DAT_006e54d4 = DAT_006e54d4 | 2;
    DAT_006e54b8 = 0;
    DAT_006e54bc = 0;
    _DAT_006e54c0 = 0;
    FUN_00635543(&LAB_0047b164);
  }
  iVar14 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(*DAT_006e486c + 0x24);
  if (iVar14 == 0) {
    *(undefined4 *)(unaff_EBP + -0xb4) = 2;
    iVar14 = 1;
    iVar9 = 0;
  }
  else {
    *(int *)(unaff_EBP + -0xb4) = iVar14;
    iVar9 = iVar14;
  }
  FUN_0046742a(iVar9);
  *(int *)(unaff_EBP + -0x18) = iVar14;
  if (iVar14 <= *(int *)(unaff_EBP + -0xb4)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      iVar14 = *(int *)(unaff_EBP + -0x38);
      if (*(int *)(unaff_EBP + -0x18) == 2) {
        *(undefined1 *)(iVar14 + 0x80) = 0;
        *(undefined1 *)(iVar14 + 0x81) = 0;
      }
      FUN_0047d08e(DAT_006e54c8,DAT_006e54cc);
      iVar9 = *(int *)(unaff_EBP + -0x18);
      iVar13 = *(int *)(iVar14 + 0x28 + iVar9 * 4);
      uVar2 = *(undefined4 *)(iVar14 + 0x30 + iVar9 * 4);
      uVar21 = *(undefined4 *)(iVar14 + 0x40 + iVar9 * 4);
      *(undefined4 *)(unaff_EBP + -0xbc) = *(undefined4 *)(iVar14 + 0x20 + iVar9 * 4);
      *(int *)(unaff_EBP + -0x48) = iVar13;
      *(undefined4 *)(unaff_EBP + -0x34) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x60) = uVar21;
      FUN_0047c718(0xffff);
      *(undefined1 *)(unaff_EBP + -0x1e) = 0x28;
      FUN_0047ca8d(unaff_EBP + -0x1e);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < *(int *)(unaff_EBP + -100)) {
        do {
          *(undefined4 *)(unaff_EBP + -0x50) = 0;
          do {
            *(undefined1 *)(unaff_EBP + -0x28) = *(undefined1 *)(unaff_EBP + -0x10);
            *(undefined1 *)(unaff_EBP + -0x27) = *(undefined1 *)(unaff_EBP + -0x50);
            *(undefined1 *)(unaff_EBP + -0x26) = *(undefined1 *)(unaff_EBP + -0x18);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            sVar7 = FUN_004325af(unaff_EBP + -0x28);
            if ((*(int *)(unaff_EBP + -0x18) == 2) && (*(char *)(iVar14 + 0x80) == '\0')) {
              if (sVar7 == 0) {
                iVar9 = *(char *)(unaff_EBP + -0x28) * 4;
                if ((*(short *)(*(int *)(*(int *)(*(int *)(iVar14 + 0x20 +
                                                          *(char *)(unaff_EBP + -0x26) * 4) + 0xc) +
                                        iVar9) + *(char *)(unaff_EBP + -0x27) * 2) == 0) &&
                   (*(char *)(*(int *)(*(int *)(*(int *)(iVar14 + 0x40 +
                                                        *(char *)(unaff_EBP + -0x26) * 4) + 0xc) +
                                      iVar9) + *(char *)(unaff_EBP + -0x27) * 0xe) == '\0'))
                goto LAB_0047a0b7;
              }
              *(undefined1 *)(iVar14 + 0x80) = 1;
            }
LAB_0047a0b7:
            puVar10 = (undefined1 *)FUN_00479dca(unaff_EBP + -0xb5,unaff_EBP + -0x28);
            uVar2 = *(undefined4 *)(unaff_EBP + -0x10);
            *(undefined1 *)
             (*(int *)(*(int *)(*(int *)(iVar14 + 0x48 + *(char *)(unaff_EBP + -0x26) * 4) + 0xc) +
                      *(char *)(unaff_EBP + -0x28) * 4) + (int)*(char *)(unaff_EBP + -0x27)) =
                 *puVar10;
            piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x118,uVar2);
            iVar9 = *piVar11;
            *(undefined1 *)(unaff_EBP + -4) = 1;
            iVar12 = *(int *)(unaff_EBP + -0x50) * 2;
            if (*(ushort *)(iVar9 + iVar12) < 0xfffd) {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x134,*(undefined4 *)(unaff_EBP + -0x10));
              bVar20 = false;
              if (*(short *)(*piVar11 + iVar12) == -5) goto LAB_0047a12b;
            }
            else {
LAB_0047a12b:
              bVar20 = true;
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
            if (bVar20) {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xe8,*(undefined4 *)(unaff_EBP + -0x10));
              if (*(short *)(iVar12 + *piVar11) == -5) {
                *(undefined1 *)(unaff_EBP + -0x7c) = *(undefined1 *)(unaff_EBP + -0x10);
                *(undefined1 *)(unaff_EBP + -0x7b) = *(undefined1 *)(unaff_EBP + -0x50);
                *(undefined1 *)(unaff_EBP + -0x7a) = *(undefined1 *)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 2;
                FUN_004673b8(unaff_EBP + -0x7c,unaff_EBP + -0xcc,unaff_EBP + -0xae,unaff_EBP + -0xf0
                             ,unaff_EBP + -0x128);
                *(undefined1 *)(unaff_EBP + -4) = 0;
                if (*(short *)(unaff_EBP + -0xae) != -1) goto LAB_0047a7b7;
              }
              iVar9 = *(char *)(unaff_EBP + -0x28) * 4;
              *(bool *)(unaff_EBP + -0x1d) =
                   *(short *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0xbc) + 0xc) + iVar9) +
                             *(char *)(unaff_EBP + -0x27) * 2) != 0;
              if ((*(char *)(unaff_EBP + -0x26) == '\x01') && (*(int *)(iVar14 + 0x60) != 0)) {
                *(bool *)(unaff_EBP + -0x1e) =
                     *(byte *)(*(int *)(*(int *)(*(int *)(iVar14 + 0x60) + 0x10) + iVar9) +
                              (int)*(char *)(unaff_EBP + -0x27)) < 0x10;
              }
              else {
                *(undefined1 *)(unaff_EBP + -0x1e) = 0;
              }
              iVar12 = DAT_006e54bc;
              iVar9 = DAT_006e54b8;
              uVar15 = *(uint *)(unaff_EBP + -0x40);
              *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 1;
              *(uint *)(unaff_EBP + -0x2c) = (*(int *)(unaff_EBP + -0x18) + 0x3f) * 0x400 | uVar15;
              FUN_0047d08e(iVar9,iVar12);
              FUN_0047c34d(unaff_EBP + -0x28);
              while (iVar9 = DAT_006e54cc, (DAT_006e54cc - DAT_006e54c8) / 3 != 0) {
                *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(DAT_006e54cc + -3);
                *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(iVar9 + -2);
                *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(iVar9 + -1);
                *(undefined1 *)(unaff_EBP + -4) = 3;
                FUN_0047c375();
                iVar9 = *(int *)(*(int *)(unaff_EBP + -0x60) + 0xc);
                *(undefined1 *)(unaff_EBP + -0x1c) = 1;
                iVar12 = *(char *)(unaff_EBP + -0x14) * 4;
                *(undefined1 *)(unaff_EBP + -0x1b) = 1;
                *(undefined1 *)(unaff_EBP + -0x1a) = 1;
                iVar9 = *(int *)(iVar9 + iVar12);
                *(undefined1 *)(unaff_EBP + -0x19) = 1;
                pbVar16 = (byte *)(iVar9 + *(char *)(unaff_EBP + -0x13) * 0xe);
                uVar2 = *(undefined4 *)(unaff_EBP + -0x2c);
                psVar1 = (short *)(*(int *)(*(int *)(iVar13 + 0xc) + iVar12) +
                                  *(char *)(unaff_EBP + -0x13) * 2);
                sVar7 = *psVar1;
                sVar18 = (short)uVar2;
                if (sVar7 != sVar18) {
                  if (sVar7 == -4) {
                    *psVar1 = sVar18;
                  }
                  else if (sVar7 == -1) {
                    if ((*pbVar16 & 0x10) == 0x10) {
                      *(undefined1 *)(unaff_EBP + -0x19) = 0;
                      *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                      *psVar1 = -2;
                    }
                    else if ((*pbVar16 & 0x20) == 0x20) {
                      *(undefined1 *)(unaff_EBP + -0x1a) = 0;
                      *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                      *psVar1 = -3;
                    }
                    else {
                      *psVar1 = -4;
                    }
                    FUN_0047c34d(unaff_EBP + -0x14);
                    FUN_0047c34d(unaff_EBP + -0x14);
                  }
                  else {
                    if (sVar7 == -2) {
                      if ((*pbVar16 & 0x10) == 0x10) {
                        *(undefined1 *)(unaff_EBP + -0x19) = 0;
                        *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                        uVar21 = 4;
                      }
                      else {
                        if ((*pbVar16 & 0x20) != 0x20) goto LAB_0047a429;
                        *(undefined1 *)(unaff_EBP + -0x1c) = 0;
                        *(undefined1 *)(unaff_EBP + -0x19) = 0;
                        uVar21 = 1;
                      }
                    }
                    else if (sVar7 == -3) {
                      if ((*pbVar16 & 0x10) == 0x10) {
                        *(undefined1 *)(unaff_EBP + -0x1a) = 0;
                        *(undefined1 *)(unaff_EBP + -0x1c) = 0;
                        uVar21 = 2;
                      }
                      else {
                        *(undefined1 *)(unaff_EBP + -0x1a) = 0;
                        *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                        uVar21 = 3;
                      }
                    }
                    else {
                      if (sVar7 != -5) goto LAB_0047a429;
                      FUN_004673b8(unaff_EBP + -0x14,unaff_EBP + -0xca,unaff_EBP + -0x66,
                                   unaff_EBP + -0xe0,unaff_EBP + -200);
                      if (*(short *)(unaff_EBP + -0x66) == sVar18) goto LAB_0047a775;
                      if (*(short *)(unaff_EBP + -0x66) == -1) {
                        FUN_0047c34d(unaff_EBP + -0x14);
                      }
                      iVar9 = *(int *)(unaff_EBP + -200);
                      if (iVar9 == 1) {
                        *(undefined1 *)(unaff_EBP + -0x1c) = 0;
LAB_0047a414:
                        *(undefined1 *)(unaff_EBP + -0x19) = 0;
                      }
                      else if (iVar9 == 2) {
                        *(undefined1 *)(unaff_EBP + -0x1a) = 0;
                        *(undefined1 *)(unaff_EBP + -0x1c) = 0;
                      }
                      else if (iVar9 == 3) {
                        *(undefined1 *)(unaff_EBP + -0x1a) = 0;
                        *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                      }
                      else if (iVar9 == 4) {
                        *(undefined1 *)(unaff_EBP + -0x1b) = 0;
                        goto LAB_0047a414;
                      }
                      uVar21 = *(undefined4 *)(unaff_EBP + -200);
                    }
                    cVar3 = FUN_004671f5(unaff_EBP + -0x14,uVar2,uVar21);
                    iVar9 = *(int *)(*(int *)(iVar13 + 0xc) + *(char *)(unaff_EBP + -0x14) * 4);
                    if (cVar3 == '\0') {
                      *(short *)(iVar9 + *(char *)(unaff_EBP + -0x13) * 2) = sVar18;
                    }
                    else {
                      *(undefined2 *)(iVar9 + *(char *)(unaff_EBP + -0x13) * 2) = 0xfffb;
                    }
                  }
LAB_0047a429:
                  if ((((*(char *)(unaff_EBP + -0x14) < '\x01') ||
                       (iVar9 = *(int *)(iVar14 + 0x10) + -1, iVar9 <= *(char *)(unaff_EBP + -0x14))
                       ) || (*(char *)(unaff_EBP + -0x13) < '\x01')) ||
                     (iVar9 <= *(char *)(unaff_EBP + -0x13))) {
                    bVar20 = true;
                  }
                  else {
                    bVar20 = false;
                  }
                  *(undefined4 *)(unaff_EBP + -0xdc) = 8;
                  *(bool *)(unaff_EBP + -0x59) = !bVar20;
                  *(undefined4 *)(unaff_EBP + -0x30) = 0;
                  *(undefined4 *)(unaff_EBP + -0xd8) = 2;
                  *(undefined4 *)(unaff_EBP + -0xd4) = 4;
                  *(undefined4 *)(unaff_EBP + -0xd0) = 1;
                  *(int *)(unaff_EBP + -0x44) = unaff_EBP + -0xdc;
                  *(undefined1 **)(unaff_EBP + -0x3c) = &DAT_006e481c;
                  do {
                    if (*(char *)(unaff_EBP + -0x1c + *(int *)(unaff_EBP + -0x30)) != '\0') {
                      FUN_00461b74(*(undefined4 *)(unaff_EBP + -0x3c));
                      *(undefined1 *)(unaff_EBP + -0xc2) = 0;
                      *(undefined1 *)(unaff_EBP + -4) = 4;
                      FUN_0046185f(unaff_EBP + -0x4c,unaff_EBP + -0xc4);
                      uVar2 = *(undefined4 *)(unaff_EBP + -0x4c);
                      uVar8 = (undefined2)uVar2;
                      *(undefined1 *)(unaff_EBP + -4) = 6;
                      cVar3 = (char)uVar2;
                      cVar4 = (char)((uint)uVar2 >> 8);
                      if ((*(char *)(unaff_EBP + -0x59) != '\0') ||
                         (((-1 < cVar3 && ((int)cVar3 < *(int *)(iVar14 + 0x10))) &&
                          ((-1 < cVar4 && ((int)cVar4 < *(int *)(iVar14 + 0x10))))))) {
                        uVar19 = *(ushort *)
                                  (*(int *)(*(int *)(iVar13 + 0xc) + cVar3 * 4) + cVar4 * 2);
                        if (0xfffa < uVar19) {
                          if (uVar19 == 0xfffb) {
                            FUN_004673b8(unaff_EBP + -0x4c,unaff_EBP + -0x56,unaff_EBP + -0x58,
                                         unaff_EBP + -0x98,unaff_EBP + -0xa8);
                            uVar8 = (undefined2)*(undefined4 *)(unaff_EBP + -0x4c);
                          }
                          cVar3 = (char)uVar8;
                          cVar4 = (char)((ushort)uVar8 >> 8);
                          if (*(int *)(unaff_EBP + -0x18) != 1) {
                            if ((*(short *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0xbc) + 0xc) +
                                                    cVar3 * 4) + cVar4 * 2) != 0) !=
                                (bool)*(char *)(unaff_EBP + -0x1d)) {
                              iVar13 = *(int *)(unaff_EBP + -0x48);
                              *(undefined1 *)(unaff_EBP + -4) = 3;
                              goto LAB_0047a75d;
                            }
                            iVar13 = *(int *)(unaff_EBP + -0x48);
                          }
                          if ((*(char *)(unaff_EBP + -0x4a) == '\x01') &&
                             (*(int *)(iVar14 + 0x60) != 0)) {
                            bVar20 = *(byte *)(*(int *)(*(int *)(*(int *)(iVar14 + 0x60) + 0x10) +
                                                       cVar3 * 4) + (int)cVar4) < 0x10;
                            iVar13 = *(int *)(unaff_EBP + -0x48);
                          }
                          else {
                            bVar20 = false;
                          }
                          if (bVar20 == (bool)*(char *)(unaff_EBP + -0x1e)) {
                            *(int *)(unaff_EBP + -0xc0) = (int)cVar3;
                            bVar6 = *(byte *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x60) + 0xc) +
                                                      *(int *)(unaff_EBP + -0xc0) * 4) + cVar4 * 0xe
                                             );
                            if ((**(byte **)(unaff_EBP + -0x44) & bVar6) == 0) {
                              if ((bVar6 & 0x30) == 0) {
LAB_0047a71e:
                                uVar19 = 0xfffc;
                              }
                              else if ((bVar6 & 0x10) == 0x10) {
                                iVar9 = *(int *)(unaff_EBP + -0x30);
                                if (iVar9 == 0) {
LAB_0047a63e:
                                  if (uVar19 != 0xffff) {
                                    if (uVar19 != 0xfffe) {
                                      if (uVar19 == 0xfffb) {
                                        if ((*(int *)(unaff_EBP + -0x98) != 2) ||
                                           (*(short *)(unaff_EBP + -0x56) != -1)) {
                                          bVar20 = *(int *)(unaff_EBP + -0xa8) == 2;
                                          goto LAB_0047a714;
                                        }
                                        goto LAB_0047a723;
                                      }
                                      goto LAB_0047a759;
                                    }
                                    goto LAB_0047a71e;
                                  }
LAB_0047a648:
                                  uVar19 = 0xfffd;
                                }
                                else {
                                  if (iVar9 != 1) {
                                    if (iVar9 == 2) goto LAB_0047a63e;
                                    if (iVar9 != 3) goto LAB_0047a723;
                                  }
                                  if (uVar19 == 0xffff) {
LAB_0047a6e9:
                                    uVar19 = 0xfffe;
                                  }
                                  else {
                                    if (uVar19 == 0xfffd) goto LAB_0047a71e;
                                    if (uVar19 != 0xfffb) goto LAB_0047a759;
                                    if ((*(int *)(unaff_EBP + -0x98) != 4) ||
                                       (*(short *)(unaff_EBP + -0x56) != -1)) {
                                      bVar20 = *(int *)(unaff_EBP + -0xa8) == 4;
LAB_0047a714:
                                      if ((!bVar20) || (*(short *)(unaff_EBP + -0x58) != -1))
                                      goto LAB_0047a759;
                                    }
                                  }
                                }
                              }
                              else {
                                puVar10 = *(undefined1 **)(unaff_EBP + -0x3c);
                                if (puVar10 == &DAT_006e481c) {
LAB_0047a6df:
                                  if (uVar19 == 0xffff) goto LAB_0047a6e9;
                                  if (uVar19 == 0xfffd) goto LAB_0047a71e;
                                  if (uVar19 != 0xfffb) goto LAB_0047a759;
                                  if ((*(int *)(unaff_EBP + -0x98) != 1) ||
                                     (*(short *)(unaff_EBP + -0x56) != -1)) {
                                    bVar20 = *(int *)(unaff_EBP + -0xa8) == 1;
                                    goto LAB_0047a714;
                                  }
                                }
                                else if (0x6e481c < (int)puVar10) {
                                  if ((int)puVar10 < 0x6e4823) {
                                    if (uVar19 != 0xffff) {
                                      if (uVar19 == 0xfffe) goto LAB_0047a71e;
                                      if (uVar19 != 0xfffb) goto LAB_0047a759;
                                      if ((*(int *)(unaff_EBP + -0x98) == 3) &&
                                         (*(short *)(unaff_EBP + -0x56) == -1)) goto LAB_0047a723;
                                      bVar20 = *(int *)(unaff_EBP + -0xa8) == 3;
                                      goto LAB_0047a714;
                                    }
                                    goto LAB_0047a648;
                                  }
                                  if (puVar10 == &DAT_006e4825) goto LAB_0047a6df;
                                }
                              }
LAB_0047a723:
                              FUN_0047c34d(unaff_EBP + -0x4c);
                              *(ushort *)
                               (*(int *)(*(int *)(*(int *)(iVar14 + 0x28 +
                                                          *(char *)(unaff_EBP + -0x4a) * 4) + 0xc) +
                                        *(char *)(unaff_EBP + -0x4c) * 4) +
                               *(char *)(unaff_EBP + -0x4b) * 2) = uVar19;
                              FUN_0047c34d(unaff_EBP + -0x4c);
                            }
                          }
                        }
                      }
LAB_0047a759:
                      *(undefined1 *)(unaff_EBP + -4) = 3;
                    }
LAB_0047a75d:
                    *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + 3;
                    *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
                    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + 4;
                  } while (*(int *)(unaff_EBP + -0x3c) < 0x6e4828);
                }
LAB_0047a775:
                *(undefined1 *)(unaff_EBP + -4) = 0;
              }
              if ((DAT_006e54bc - DAT_006e54b8) / 3 == 0) {
                *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + 0xffff;
              }
              else {
                iVar9 = FUN_004670ce(*(undefined4 *)(unaff_EBP + -0x2c));
                if (iVar9 != 0) {
                  FUN_004682c2(&DAT_006e54b8);
                }
              }
            }
LAB_0047a7b7:
            *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x50) + 1;
          } while (*(int *)(unaff_EBP + -0x50) < *(int *)(unaff_EBP + -100));
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -100));
      }
      *(undefined1 *)(unaff_EBP + -0x70) = 0;
      *(undefined1 *)(unaff_EBP + -0x6f) = 0;
      *(undefined1 *)(unaff_EBP + -0x6e) = *(undefined1 *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 7;
      FUN_0047c34d(unaff_EBP + -0x70);
      iVar9 = DAT_006e54cc;
      iVar13 = DAT_006e54cc - DAT_006e54c8;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      while (iVar13 / 3 != 0) {
        *(undefined1 *)(unaff_EBP + -0x6c) = *(undefined1 *)(iVar9 + -3);
        *(undefined1 *)(unaff_EBP + -0x6b) = *(undefined1 *)(iVar9 + -2);
        *(undefined1 *)(unaff_EBP + -0x6a) = *(undefined1 *)(iVar9 + -1);
        *(undefined4 *)(unaff_EBP + -4) = 8;
        FUN_0047c375();
        *(int *)(unaff_EBP + -0x10) = (int)*(char *)(unaff_EBP + -0x6c);
        cVar3 = *(char *)(unaff_EBP + -0x6b);
        iVar9 = (int)cVar3;
        piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xf8,(int)*(char *)(unaff_EBP + -0x6c));
        bVar6 = *(byte *)(*piVar11 + iVar9);
        *(uint *)(unaff_EBP + -0x3c) = (uint)bVar6;
        if ((bVar6 & 2) == 0) {
          *(uint *)(unaff_EBP + -0x3c) = *(uint *)(unaff_EBP + -0x3c) | 6;
          FUN_00479737(unaff_EBP + -0x164,unaff_EBP + -0x6c);
          *(undefined1 *)(unaff_EBP + -4) = 9;
          cVar4 = FUN_0047b107();
          if (cVar4 == '\0') {
            if (0 < *(int *)(unaff_EBP + -0x10)) {
              iVar14 = *(int *)(unaff_EBP + -0x10) + -1;
              *(int *)(unaff_EBP + -0x2c) = iVar14;
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x130,iVar14);
              bVar6 = (byte)~*(byte *)(*piVar11 + iVar9) >> 1 & 1;
              *(byte *)(unaff_EBP + -0x1d) = bVar6;
              if ((bVar6 != 0) && (cVar4 = FUN_004351e4(1), cVar4 == '\0')) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x110,*(undefined4 *)(unaff_EBP + -0x2c))
                ;
                pbVar16 = (byte *)(iVar9 * 0xe + *piVar11);
                if ((((*pbVar16 & 0x30) == 0) ||
                    (((sVar7 = *(short *)(pbVar16 + 4), sVar7 == 2 || (sVar7 == 0xc)) ||
                     (sVar7 == 0xd)))) || (sVar7 == 0xe)) {
                  bVar20 = false;
                }
                else {
                  bVar20 = true;
                }
                if (!bVar20) {
                  *(char *)(unaff_EBP + -0x77) = cVar3;
                  *(undefined1 *)(unaff_EBP + -0x78) = *(undefined1 *)(unaff_EBP + -0x2c);
                  *(undefined1 *)(unaff_EBP + -0x76) = *(undefined1 *)(unaff_EBP + -0x18);
                  *(undefined1 *)(unaff_EBP + -4) = 0xe;
                  FUN_0047c34d(unaff_EBP + -0x78);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                }
              }
            }
            iVar14 = *(int *)(unaff_EBP + -100) + -1;
            if (*(int *)(unaff_EBP + -0x10) < iVar14) {
              iVar13 = *(int *)(unaff_EBP + -0x10) + 1;
              *(int *)(unaff_EBP + -0x2c) = iVar13;
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xe4,iVar13);
              bVar6 = (byte)~*(byte *)(iVar9 + *piVar11) >> 1 & 1;
              *(byte *)(unaff_EBP + -0x1d) = bVar6;
              if ((bVar6 != 0) && (cVar4 = FUN_004351e4(4), cVar4 == '\0')) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xec,*(undefined4 *)(unaff_EBP + -0x2c));
                pbVar16 = (byte *)(iVar9 * 0xe + *piVar11);
                if ((((*pbVar16 & 0x30) == 0) ||
                    ((sVar7 = *(short *)(pbVar16 + 4), sVar7 == 2 || (sVar7 == 0xc)))) ||
                   ((sVar7 == 0xd || (sVar7 == 0xe)))) {
                  bVar20 = false;
                }
                else {
                  bVar20 = true;
                }
                if (!bVar20) {
                  *(char *)(unaff_EBP + -0x87) = cVar3;
                  *(undefined1 *)(unaff_EBP + -0x88) = *(undefined1 *)(unaff_EBP + -0x2c);
                  *(undefined1 *)(unaff_EBP + -0x86) = *(undefined1 *)(unaff_EBP + -0x18);
                  *(undefined1 *)(unaff_EBP + -4) = 0xf;
                  FUN_0047c34d(unaff_EBP + -0x88);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                }
              }
            }
            if (0 < iVar9) {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xf4,*(undefined4 *)(unaff_EBP + -0x10));
              bVar6 = (byte)~*(byte *)(iVar9 + -1 + *piVar11) >> 1 & 1;
              *(byte *)(unaff_EBP + -0x1d) = bVar6;
              if ((bVar6 != 0) && (cVar4 = FUN_004351e4(2), cVar4 == '\0')) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0xfc,*(undefined4 *)(unaff_EBP + -0x10));
                pbVar16 = (byte *)((iVar9 + -1) * 0xe + *piVar11);
                if ((((*pbVar16 & 0x30) == 0) ||
                    (((sVar7 = *(short *)(pbVar16 + 4), sVar7 == 2 || (sVar7 == 0xc)) ||
                     (sVar7 == 0xd)))) || (sVar7 == 0xe)) {
                  bVar20 = false;
                }
                else {
                  bVar20 = true;
                }
                if (!bVar20) {
                  *(undefined1 *)(unaff_EBP + -0x90) = *(undefined1 *)(unaff_EBP + -0x10);
                  *(char *)(unaff_EBP + -0x8f) = cVar3 + -1;
                  *(undefined1 *)(unaff_EBP + -0x8e) = *(undefined1 *)(unaff_EBP + -0x18);
                  *(undefined1 *)(unaff_EBP + -4) = 0x10;
                  FUN_0047c34d(unaff_EBP + -0x90);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                }
              }
            }
            if (iVar9 < iVar14) {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x104,*(undefined4 *)(unaff_EBP + -0x10));
              bVar6 = (byte)~*(byte *)(iVar9 + 1 + *piVar11) >> 1 & 1;
              *(byte *)(unaff_EBP + -0x1d) = bVar6;
              if ((bVar6 != 0) && (cVar4 = FUN_004351e4(8), cVar4 == '\0')) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x10c,*(undefined4 *)(unaff_EBP + -0x10))
                ;
                pbVar16 = (byte *)((iVar9 + 1) * 0xe + *piVar11);
                if (((((*pbVar16 & 0x30) == 0) ||
                     ((sVar7 = *(short *)(pbVar16 + 4), sVar7 == 2 || (sVar7 == 0xc)))) ||
                    (sVar7 == 0xd)) || (sVar7 == 0xe)) {
                  bVar20 = false;
                }
                else {
                  bVar20 = true;
                }
                if (bVar20) goto LAB_0047ad8e;
                *(undefined1 *)(unaff_EBP + -0x74) = *(undefined1 *)(unaff_EBP + -0x10);
                *(char *)(unaff_EBP + -0x73) = cVar3 + '\x01';
                *(undefined1 *)(unaff_EBP + -0x72) = *(undefined1 *)(unaff_EBP + -0x18);
                iVar14 = unaff_EBP + -0x74;
                *(undefined1 *)(unaff_EBP + -4) = 0x11;
                goto LAB_0047ad85;
              }
            }
          }
          else {
            uVar15 = iVar9 + 1;
            bVar20 = ((byte)*(undefined4 *)(unaff_EBP + -0x164) & 0x10) == 0x10;
            if (!bVar20) {
              uVar15 = iVar9 - 1;
            }
            uVar17 = *(uint *)(unaff_EBP + -0x10);
            *(uint *)(unaff_EBP + -0x40) = uVar15;
            *(uint *)(unaff_EBP + -0x2c) = uVar17 + 1;
            *(uint *)(unaff_EBP + -0x50) = uVar17 - 1;
            iVar13 = iVar9 + -1;
            if (!bVar20) {
              iVar13 = iVar9 + 1;
            }
            *(int *)(unaff_EBP + -0x48) = iVar13;
            *(uint *)(unaff_EBP + -0x3c) =
                 *(uint *)(unaff_EBP + -0x3c) | (-(uint)bVar20 & 0xffffffc0) + 0x80;
            if ((int)((*(int *)(iVar14 + 0x10) - uVar15) - 1 | uVar15) < 0) {
              *(undefined4 *)(unaff_EBP + -0x44) = 2;
            }
            else {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x138,*(undefined4 *)(unaff_EBP + -0x10));
              iVar13 = *piVar11;
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 1;
              uVar17 = *(uint *)(unaff_EBP + -0x10);
              *(uint *)(unaff_EBP + -0x44) = *(byte *)(*(int *)(unaff_EBP + -0x40) + iVar13) & 2;
            }
            if ((*(byte *)(unaff_EBP + -0x24) & 1) != 0) {
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffe;
            }
            if ((int)((*(int *)(iVar14 + 0x10) - uVar17) - 1 | uVar17) < 0) {
              bVar6 = 2;
            }
            else {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x100,*(undefined4 *)(unaff_EBP + -0x2c));
              iVar14 = *piVar11;
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 2;
              uVar17 = *(uint *)(unaff_EBP + -0x10);
              bVar6 = *(byte *)(iVar9 + iVar14) & 2;
            }
            if ((*(byte *)(unaff_EBP + -0x24) & 2) != 0) {
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffd;
            }
            iVar14 = *(int *)(unaff_EBP + -0x38);
            if ((int)((*(int *)(iVar14 + 0x10) - uVar17) - 1 | uVar17) < 0) {
              *(undefined4 *)(unaff_EBP + -0x30) = 2;
            }
            else {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x120,*(undefined4 *)(unaff_EBP + -0x50));
              iVar13 = *piVar11;
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 4;
              *(uint *)(unaff_EBP + -0x30) = *(byte *)(iVar9 + iVar13) & 2;
            }
            if ((*(byte *)(unaff_EBP + -0x24) & 4) != 0) {
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffffb;
            }
            if ((int)((*(int *)(iVar14 + 0x10) - *(int *)(unaff_EBP + -0x40)) - 1U |
                     *(uint *)(unaff_EBP + -0x40)) < 0) {
              bVar5 = 2;
            }
            else {
              piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x108,*(undefined4 *)(unaff_EBP + -0x10));
              iVar14 = *piVar11;
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) | 8;
              bVar5 = *(byte *)(iVar14 + *(int *)(unaff_EBP + -0x48)) & 2;
            }
            if ((*(byte *)(unaff_EBP + -0x24) & 8) != 0) {
              *(uint *)(unaff_EBP + -0x24) = *(uint *)(unaff_EBP + -0x24) & 0xfffffff7;
            }
            if (*(int *)(unaff_EBP + -0x44) == 0) {
LAB_0047aa0e:
              if (bVar6 != 0) goto LAB_0047aa12;
            }
            else {
              if (bVar6 == 0) {
                *(char *)(unaff_EBP + -0x7f) = cVar3;
                *(undefined1 *)(unaff_EBP + -0x80) = *(undefined1 *)(unaff_EBP + -0x2c);
                *(undefined1 *)(unaff_EBP + -0x7e) = *(undefined1 *)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 10;
                FUN_0047c34d(unaff_EBP + -0x80);
                *(undefined1 *)(unaff_EBP + -4) = 9;
                goto LAB_0047aa0e;
              }
LAB_0047aa12:
              if (*(int *)(unaff_EBP + -0x44) == 0) {
                *(undefined1 *)(unaff_EBP + -0x84) = *(undefined1 *)(unaff_EBP + -0x10);
                *(undefined1 *)(unaff_EBP + -0x83) = *(undefined1 *)(unaff_EBP + -0x40);
                *(undefined1 *)(unaff_EBP + -0x82) = *(undefined1 *)(unaff_EBP + -0x18);
                *(undefined1 *)(unaff_EBP + -4) = 0xb;
                FUN_0047c34d(unaff_EBP + -0x84);
                *(undefined1 *)(unaff_EBP + -4) = 9;
              }
            }
            if (*(int *)(unaff_EBP + -0x30) == 0) {
LAB_0047aa8a:
              if (bVar5 == 0) goto LAB_0047ad8e;
            }
            else if (bVar5 == 0) {
              *(undefined1 *)(unaff_EBP + -0x8c) = *(undefined1 *)(unaff_EBP + -0x10);
              *(undefined1 *)(unaff_EBP + -0x8b) = *(undefined1 *)(unaff_EBP + -0x48);
              *(undefined1 *)(unaff_EBP + -0x8a) = *(undefined1 *)(unaff_EBP + -0x18);
              *(undefined1 *)(unaff_EBP + -4) = 0xc;
              FUN_0047c34d(unaff_EBP + -0x8c);
              *(undefined1 *)(unaff_EBP + -4) = 9;
              goto LAB_0047aa8a;
            }
            if (*(int *)(unaff_EBP + -0x30) == 0) {
              *(char *)(unaff_EBP + -0x93) = cVar3;
              *(undefined1 *)(unaff_EBP + -0x94) = *(undefined1 *)(unaff_EBP + -0x50);
              *(undefined1 *)(unaff_EBP + -0x92) = *(undefined1 *)(unaff_EBP + -0x18);
              iVar14 = unaff_EBP + -0x94;
              *(undefined1 *)(unaff_EBP + -4) = 0xd;
LAB_0047ad85:
              FUN_0047c34d(iVar14);
              *(undefined1 *)(unaff_EBP + -4) = 9;
            }
          }
LAB_0047ad8e:
          piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x114,*(undefined4 *)(unaff_EBP + -0x10));
          iVar13 = *piVar11;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          iVar14 = *(int *)(unaff_EBP + -0x38);
          *(undefined1 *)(iVar13 + iVar9) = *(undefined1 *)(unaff_EBP + -0x3c);
        }
        else {
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
        iVar9 = DAT_006e54cc;
        iVar13 = DAT_006e54cc - DAT_006e54c8;
      }
      iVar9 = 1;
      if (*(int *)(unaff_EBP + -0x18) != 1) {
        iVar9 = *(int *)(unaff_EBP + -0x18) + -1;
      }
      *(int *)(unaff_EBP + -0x2c) = iVar9;
      *(undefined4 *)(unaff_EBP + -0xc0) = *(undefined4 *)(iVar14 + 0x30 + iVar9 * 4);
      iVar9 = *(int *)(unaff_EBP + -100) + -1;
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      if (1 < iVar9) {
        do {
          iVar13 = 1;
          if (1 < iVar9) {
            *(undefined1 *)(unaff_EBP + -0xa2) = *(undefined1 *)(unaff_EBP + -0x2c);
            *(int *)(unaff_EBP + -0x48) = (int)*(char *)(unaff_EBP + -0x10) << 2;
LAB_0047ae18:
            cVar4 = (char)iVar13;
            *(char *)(unaff_EBP + -0xa3) = cVar4;
            *(undefined1 *)(unaff_EBP + -0xa4) = *(undefined1 *)(unaff_EBP + -0x10);
            iVar9 = *(int *)(iVar14 + 0x14);
            *(undefined4 *)(unaff_EBP + -4) = 0x12;
            uVar2 = *(undefined4 *)
                     (*(int *)(*(int *)(iVar9 + 0xc) + *(int *)(unaff_EBP + -0x48)) + cVar4 * 4);
            cVar3 = (char)((uint)uVar2 >> 8);
            *(undefined4 *)(unaff_EBP + -0x44) = uVar2;
            if (((cVar3 == (char)uVar2) && (cVar3 == *(char *)(unaff_EBP + -0x42))) &&
               (cVar3 == *(char *)(unaff_EBP + -0x41))) {
              if (*(int *)(unaff_EBP + -0x18) == 1) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x11c,*(undefined4 *)(unaff_EBP + -0x10))
                ;
                *(byte *)(*piVar11 + iVar13) = *(byte *)(*piVar11 + iVar13) | 1;
                *(char *)(unaff_EBP + -0x9b) = cVar4;
                *(undefined1 *)(unaff_EBP + -0x9a) = 1;
                *(undefined1 *)(unaff_EBP + -0x9c) = *(undefined1 *)(unaff_EBP + -0x10);
                iVar9 = DAT_006e54d8;
                *(undefined1 *)(unaff_EBP + -4) = 0x13;
                FUN_00434ffd(*(undefined4 *)(iVar9 + 0x84));
                FUN_00476b8f(unaff_EBP + -0x9c);
                goto LAB_0047aeb2;
              }
              iVar14 = *(int *)(*(int *)(unaff_EBP + -0xc0) + 0xc);
              bVar6 = *(byte *)(*(int *)(iVar14 + *(int *)(unaff_EBP + -0x48)) + (int)cVar4);
              if (((bVar6 & 4) == 0) || ((bVar6 & 8) != 0)) {
                piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -300,*(undefined4 *)(unaff_EBP + -0x10));
                *(byte *)(*piVar11 + iVar13) = *(byte *)(*piVar11 + iVar13) | 1;
                if (*(int *)(unaff_EBP + -0x18) == 2) {
                  *(undefined1 *)(*(int *)(unaff_EBP + -0x38) + 0x81) = 1;
                }
                *(char *)(unaff_EBP + -0x9f) = cVar4;
                *(undefined1 *)(unaff_EBP + -0xa0) = *(undefined1 *)(unaff_EBP + -0x10);
                *(undefined1 *)(unaff_EBP + -0x9e) = *(undefined1 *)(unaff_EBP + -0x18);
                iVar14 = DAT_006e54d8;
                *(undefined1 *)(unaff_EBP + -4) = 0x14;
                FUN_00434ffd(*(undefined4 *)(iVar14 + 0x84));
                iVar14 = unaff_EBP + -0xa0;
LAB_0047b090:
                FUN_00476b8f(iVar14);
              }
              else {
                iVar9 = 0;
                if (0 < DAT_006c4ebc) {
                  *(undefined4 *)(unaff_EBP + -0x30) =
                       *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0x10);
                  do {
                    uVar15 = (&DAT_00667944)[iVar9] + *(int *)(unaff_EBP + -0x10);
                    if (((-1 < (int)((*(int *)(unaff_EBP + -0x30) - uVar15) - 1 | uVar15)) &&
                        (uVar17 = (&DAT_00667954)[iVar9] + iVar13,
                        -1 < (int)((*(int *)(unaff_EBP + -0x30) - uVar17) - 1 | uVar17))) &&
                       (*(short *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0xbc) + 0xc) +
                                           (char)uVar15 * 4) + (char)uVar17 * 2) != 0)) {
                      iVar9 = 0;
                      if (0 < DAT_006c4ec0) goto LAB_0047afd1;
                      break;
                    }
                    iVar9 = iVar9 + 1;
                  } while (iVar9 < DAT_006c4ebc);
                }
              }
              goto LAB_0047b097;
            }
LAB_0047aeb2:
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            goto LAB_0047aeb6;
          }
LAB_0047aec6:
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) < iVar9);
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    } while (*(int *)(unaff_EBP + -0x18) <= *(int *)(unaff_EBP + -0xb4));
  }
  iVar14 = *(int *)(unaff_EBP + -0x38);
  FUN_005407ce(*(undefined4 *)(unaff_EBP + 8));
  DAT_006e5780 = 0;
  FUN_0040766a(0xf0,*(undefined4 *)(unaff_EBP + 8));
  if (*(int *)(iVar14 + 0x5c) != 0) {
    FUN_0056ea87(2,0);
  }
  if (*(int *)(iVar14 + 0x58) != 0) {
    FUN_0056ea87(1,*(undefined4 *)(iVar14 + 0x5c));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
LAB_0047afd1:
  do {
    uVar15 = (&DAT_00667964)[iVar9] + *(int *)(unaff_EBP + -0x10);
    if ((-1 < (int)((*(int *)(unaff_EBP + -0x30) - uVar15) - 1 | uVar15)) &&
       (uVar17 = (&DAT_006679c4)[iVar9] + iVar13,
       -1 < (int)((*(int *)(unaff_EBP + -0x30) - uVar17) - 1 | uVar17))) {
      *(char *)(unaff_EBP + -0xa4) = (char)uVar15;
      *(char *)(unaff_EBP + -0xa3) = (char)uVar17;
      bVar6 = *(byte *)(*(int *)(iVar14 + (char)uVar15 * 4) + (int)(char)uVar17);
      if (((bVar6 & 4) == 0) || (((bVar6 & 8) != 0 && ((&DAT_00667a24)[iVar9] != 0)))) {
        piVar11 = (int *)FUN_0047c7b7(unaff_EBP + -0x124,*(undefined4 *)(unaff_EBP + -0x10));
        *(byte *)(*piVar11 + iVar13) = *(byte *)(*piVar11 + iVar13) | 1;
        if (*(int *)(unaff_EBP + -0x18) == 2) {
          *(undefined1 *)(*(int *)(unaff_EBP + -0x38) + 0x81) = 1;
        }
        *(char *)(unaff_EBP + -0xab) = cVar4;
        *(undefined1 *)(unaff_EBP + -0xac) = *(undefined1 *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -0xaa) = *(undefined1 *)(unaff_EBP + -0x18);
        iVar14 = DAT_006e54d8;
        *(undefined1 *)(unaff_EBP + -4) = 0x15;
        FUN_00434ffd(*(undefined4 *)(iVar14 + 0x84));
        iVar14 = unaff_EBP + -0xac;
        goto LAB_0047b090;
      }
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < DAT_006c4ec0);
LAB_0047b097:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar14 = *(int *)(unaff_EBP + -0x38);
LAB_0047aeb6:
  iVar13 = iVar13 + 1;
  iVar9 = *(int *)(unaff_EBP + -100) + -1;
  if (iVar9 <= iVar13) goto LAB_0047aec6;
  goto LAB_0047ae18;
}

