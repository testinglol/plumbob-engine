
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00432a70(void)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  float fVar4;
  undefined4 *puVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined2 extraout_var;
  float *pfVar12;
  int unaff_EBP;
  int iVar13;
  int iVar14;
  float fVar15;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = DAT_006e54dc;
  iVar8 = *(int *)(extraout_ECX + 0x118);
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  *(bool *)(unaff_EBP + -0xd) = *(short *)(iVar8 + 0x12) == 2;
  if (**(char **)(unaff_EBP + 8) == '\0') {
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      *(undefined4 *)(unaff_EBP + -0x74) = 0;
      *(undefined4 *)(unaff_EBP + -0x70) = 0;
      FUN_004328f3(unaff_EBP + -0x78);
      FUN_00432984();
      iVar8 = FUN_004328d2(0);
      if (iVar8 != 0) {
        FUN_00432984();
        iVar8 = unaff_EBP + -0x78;
LAB_004330e0:
        FUN_004327d9(iVar8);
      }
    }
  }
  else {
    if (*(char *)(unaff_EBP + 0xc) == '\0') {
      iVar8 = *(int *)(unaff_EBP + 8);
      piVar1 = (int *)(iVar8 + 4);
      uVar9 = FUN_00433116(piVar1,1);
      cVar6 = FUN_00433136(uVar9);
      if (cVar6 == '\0') {
        iVar10 = *(int *)(iVar8 + 0x14);
        if ((iVar10 < 1) || (3 < iVar10)) {
          DAT_006e4a7c = 2;
        }
        else {
          iVar13 = *(int *)(iVar8 + 8);
          *(char *)(unaff_EBP + -0x16) = (char)iVar10;
          *(char *)(unaff_EBP + -0x18) = (char)(iVar13 >> 4);
          *(char *)(unaff_EBP + -0x17) = (char)(*piVar1 >> 4);
          iVar13 = *(int *)(unaff_EBP + -0x20);
          *(undefined4 *)(unaff_EBP + -4) = 0;
          uVar3 = *(ushort *)(iVar13 + 0x9e);
          *(uint *)(unaff_EBP + -0x14) = CONCAT22(extraout_var,uVar3);
          if (((char)iVar10 < '\x02') || ((uVar3 & 0x1000) == 0)) {
            if ((*(char *)(unaff_EBP + -0xd) != '\0') ||
               ((sVar7 = FUN_004770d1(*piVar1,*(undefined4 *)(iVar8 + 8),iVar10,
                                      (int)*(short *)(iVar13 + 0x4c),(int)*(short *)(iVar13 + 100)),
                sVar7 != 0 || (*(int *)(iVar8 + 0xc) != 0)))) {
              if (((*(byte *)(unaff_EBP + -0x13) & 2) == 0) &&
                 ((1 < *(int *)(iVar8 + 0x14) &&
                  (iVar10 = FUN_00433166(unaff_EBP + -0x18), iVar10 == 0)))) {
                iVar10 = FUN_004a696f();
                DAT_006e4a7c = (-(uint)(iVar10 != *(int *)(iVar8 + 0x14)) & 0x17) + 0x12;
              }
              else {
                cVar6 = FUN_004790bc(unaff_EBP + -0x18);
                puVar5 = DAT_006e486c;
                if (cVar6 == '\0') {
                  if ((*(byte *)(unaff_EBP + -0x13) & 0x20) == 0) goto LAB_00432c58;
                  DAT_006e4a7c = 0x2f;
                }
                else if ((*(byte *)(unaff_EBP + -0x14) & 4) == 0) {
                  *(undefined1 *)(unaff_EBP + -0xe) = 0;
                  FUN_0043f371(*puVar5,unaff_EBP + -0x18,0);
                  if (*(int *)(unaff_EBP + -0x38) != 0) {
                    do {
                      if ((*(ushort *)(*(int *)(unaff_EBP + -0x38) + 0x5a) & 0x1000) != 0) {
                        *(undefined1 *)(unaff_EBP + -0xe) = 1;
                      }
                      FUN_0043f3b9();
                    } while (*(int *)(unaff_EBP + -0x38) != 0);
                    if (*(char *)(unaff_EBP + -0xe) != '\0') goto LAB_00432c58;
                  }
LAB_00432c34:
                  DAT_006e4a7c = 0x1d;
                }
                else {
LAB_00432c58:
                  iVar14 = (int)*(char *)(unaff_EBP + -0x17);
                  iVar13 = *(char *)(unaff_EBP + -0x18) * 4;
                  iVar10 = FUN_004790b4();
                  bVar2 = *(byte *)(*(int *)(*(int *)(iVar10 + 0x10) + iVar13) + iVar14);
                  *(byte *)(unaff_EBP + -0x30) = bVar2;
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  if (*(char *)(unaff_EBP + -0x16) == '\x01') {
                    if (((*(byte *)(unaff_EBP + -0x13) & 8) == 0) && (bVar2 < 0x10))
                    goto LAB_00432c34;
                    if (((*(byte *)(unaff_EBP + -0x13) & 0x10) != 0) && (0xf < bVar2)) {
                      DAT_006e4a7c = 0x1e;
                      goto LAB_00433073;
                    }
                  }
                  iVar10 = extraout_ECX_00;
                  if (((*(byte *)(unaff_EBP + -0x13) & 1) == 0) &&
                     (iVar10 = *(int *)(unaff_EBP + 8), *(int *)(iVar10 + 0xc) == 0)) {
                    iVar10 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x1c) + 0x14)
                                                       + 0xc) + iVar13) + iVar14 * 4);
                    *(int *)(unaff_EBP + -0x24) = iVar10;
                    cVar6 = (char)iVar10;
                    if ((cVar6 != *(char *)(unaff_EBP + -0x22)) ||
                       ((cVar6 != (char)((uint)iVar10 >> 8) ||
                        (cVar6 != *(char *)(unaff_EBP + -0x21))))) {
                      DAT_006e4a7c = 0x11;
                      goto LAB_00433073;
                    }
                  }
                  if ((((*(byte *)(unaff_EBP + -0x14) & 1) == 0) &&
                      (iVar10 = *(int *)(unaff_EBP + 8), *(int *)(iVar10 + 0xc) == 0)) &&
                     ((iVar10 = *(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x1c) + 0x20 +
                                                          *(char *)(unaff_EBP + -0x16) * 4) + 0xc) +
                                        iVar13), *(short *)(iVar10 + iVar14 * 2) != 0 ||
                      ((*(char *)(unaff_EBP + -0x16) == '\x01' && (bVar2 == 0x10)))))) {
                    iVar8 = FUN_004a696f();
                    DAT_006e4a7c = (-(uint)(iVar8 != *(int *)(*(int *)(unaff_EBP + 8) + 0x14)) &
                                   0x17) + 0x13;
                  }
                  else {
                    if ((((*(byte *)(unaff_EBP + -0x14) & 2) == 0) &&
                        (*(int *)(*(int *)(unaff_EBP + 8) + 0xc) == 0)) &&
                       (*(int *)(*(int *)(unaff_EBP + 8) + 0x14) == 1)) {
                      iVar10 = *(int *)(unaff_EBP + -0x1c);
                      if (*(short *)(*(int *)(*(int *)(*(int *)(iVar10 + 0x20 +
                                                               *(char *)(unaff_EBP + -0x16) * 4) +
                                                      0xc) + iVar13) + iVar14 * 2) == 0) {
                        DAT_006e4a7c = 0x14;
                        goto LAB_00433073;
                      }
                    }
                    sVar7 = *(short *)(*(int *)(unaff_EBP + -0x20) + 0x86);
                    if ((sVar7 == 0) || (*(int *)(*(int *)(unaff_EBP + 8) + 0xc) != 0)) {
LAB_00432de1:
                      iVar8 = *(int *)(unaff_EBP + -0x20);
                      *(undefined2 *)(unaff_EBP + -0x2c) = *(undefined2 *)(iVar8 + 0x52);
                      iVar13 = *(int *)(unaff_EBP + 8);
                      iVar14 = *(int *)(iVar13 + 0xc);
                      if (iVar14 == 0) {
                        cVar6 = FUN_004338a5(piVar1,*(undefined4 *)(iVar13 + 0x14));
                        if (cVar6 != '\0') {
                          fVar15 = 1.4013e-45;
LAB_00433052:
                          if ((*(short *)(unaff_EBP + -0x2c) != 0) &&
                             (((int)*(short *)(unaff_EBP + -0x2c) &
                              1 << (SUB41(fVar15,0) - 1U & 0x1f)) != 0)) {
                            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                            goto LAB_0043307b;
                          }
LAB_00433069:
                          DAT_006e4a7c = 0x18;
                        }
                      }
                      else {
                        uVar3 = *(ushort *)(iVar8 + 0x5a);
                        *(uint *)(unaff_EBP + -0x14) = CONCAT22((short)((uint)iVar10 >> 0x10),uVar3)
                        ;
                        if (((uVar3 & 4) == 0) && ((*(ushort *)(iVar14 + 0x5a) & 4) == 0)) {
                          iVar10 = *(int *)(iVar13 + 0x10);
                          if ((iVar10 < 0) ||
                             ((*(int *)(iVar14 + 0x134) - *(int *)(iVar14 + 0x130)) / 0x24 + -1 <=
                              iVar10)) {
                            pfVar12 = (float *)0x0;
                          }
                          else {
                            pfVar12 = (float *)(*(int *)(iVar14 + 0x130) + (iVar10 * 9 + 9) * 4);
                          }
                          *(float **)(unaff_EBP + -0x24) = pfVar12;
                          if (pfVar12 == (float *)0x0) {
LAB_00432e6c:
                            DAT_006e4a7c = 0xd;
                          }
                          else if ((*(short *)(pfVar12 + 4) == 0) ||
                                  (*(short *)(pfVar12 + 4) == *(short *)(iVar8 + 0xf0))) {
                            iVar8 = *(int *)(iVar14 + 0x134);
                            fVar15 = pfVar12[5];
                            iVar10 = *(int *)(iVar14 + 0x130);
                            *(float *)(unaff_EBP + -0x28) = fVar15;
                            fVar4 = _DAT_0066657c;
                            iVar8 = (iVar8 - iVar10) / 0x24;
                            if ((*(char *)(unaff_EBP + -0xd) == '\0') &&
                               (((*(uint *)(unaff_EBP + -0x14) >> 0xd & 1) == 0 &&
                                (*(short *)(DAT_006e486c[7] + 0x36) == 2)))) {
                              if (_DAT_0066657c == *pfVar12) {
                                if (_DAT_0066657c == pfVar12[1]) goto LAB_00432f06;
                              }
                              if (1 < iVar8 + -1) {
                                DAT_006e4a7c = 3;
                                goto LAB_00433073;
                              }
                            }
LAB_00432f06:
                            if ((*(short *)(*(int *)(iVar14 + 0x118) + 0x12) == 2) &&
                               (*(short *)(DAT_006e486c[7] + 0x36) != 0)) goto LAB_00432e6c;
                            iVar8 = iVar8 + -2;
                            if (-1 < iVar8) {
                              *(int *)(unaff_EBP + -0x1c) = (iVar8 * 9 + 9) * 4;
                              if (iVar8 < 0) goto LAB_00432f5f;
                              do {
                                if (iVar8 < (*(int *)(iVar14 + 0x134) - *(int *)(iVar14 + 0x130)) /
                                            0x24 + -1) {
                                  pfVar12 = (float *)(*(int *)(unaff_EBP + -0x1c) +
                                                     *(int *)(iVar14 + 0x130));
                                }
                                else {
LAB_00432f5f:
                                  pfVar12 = (float *)0x0;
                                }
                                if (((pfVar12[5] == *(float *)(unaff_EBP + -0x28)) &&
                                    (sVar7 = *(short *)(pfVar12 + 4), sVar7 != 0)) &&
                                   (sVar7 != *(short *)(*(int *)(unaff_EBP + -0x20) + 0xf0))) {
                                  if (((fVar4 == *pfVar12) && (fVar4 == pfVar12[1])) &&
                                     (*(char *)(unaff_EBP + -0xd) == '\0')) {
                                    uVar11 = (uint)sVar7;
                                    iVar10 = *(int *)(*(int *)(unaff_EBP + -0x20) + 0xdc);
                                    iVar13 = 0;
                                    if ((0 < (int)uVar11) &&
                                       (uVar11 < (*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18)
                                                 >> 2) + 1U)) {
                                      iVar13 = *(int *)(*(int *)(iVar10 + 0x18) + -4 + uVar11 * 4);
                                    }
                                    if ((*(ushort *)(iVar13 + 0x5a) & 0x2000) == 0)
                                    goto LAB_00432e8d;
                                  }
                                  if ((((fVar4 == **(float **)(unaff_EBP + -0x24)) &&
                                       (fVar4 == (*(float **)(unaff_EBP + -0x24))[1])) &&
                                      (*(char *)(unaff_EBP + -0xd) == '\0')) &&
                                     ((*(uint *)(unaff_EBP + -0x14) >> 0xd & 1) == 0))
                                  goto LAB_00432e8d;
                                }
                                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -0x24;
                                iVar8 = iVar8 + -1;
                              } while (-1 < iVar8);
                              fVar15 = *(float *)(unaff_EBP + -0x28);
                            }
                            if (*(short *)(*(int *)(unaff_EBP + -0x20) + 0x80) <=
                                *(short *)(iVar14 + 0x82)) {
                              while (iVar14 != 0) {
                                if (iVar14 == *(int *)(unaff_EBP + -0x20)) goto LAB_00432e8d;
                                *(undefined4 *)(unaff_EBP + -0x74) = 0;
                                *(undefined4 *)(unaff_EBP + -0x70) = 0;
                                FUN_00432664(unaff_EBP + -0x78);
                                iVar14 = *(int *)(unaff_EBP + -0x6c);
                              }
                              if (fVar15 != 0.0) goto LAB_00433052;
                              goto LAB_00433069;
                            }
                            DAT_006e4a7c = 0xe;
                          }
                          else {
LAB_00432e8d:
                            DAT_006e4a7c = 0xb;
                          }
                        }
                        else {
                          DAT_006e4a7c = 0xc;
                        }
                      }
                    }
                    else {
                      iVar10 = (int)(char)(*piVar1 >> 4);
                      uVar11 = (*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x1c) +
                                                                     0x30 + (char)*(undefined4 *)
                                                                                   (*(int *)(
                                                  unaff_EBP + 8) + 0x14) * 4) + 0xc) +
                                                  (char)(*(int *)(iVar8 + 8) >> 4) * 4) + iVar10) &
                               4) >> 2;
                      if (sVar7 == 1) {
                        if (uVar11 != 0) goto LAB_00432de1;
                        DAT_006e4a7c = 9;
                      }
                      else {
                        if ((sVar7 != 2) || (uVar11 == 0)) goto LAB_00432de1;
                        DAT_006e4a7c = 10;
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            DAT_006e4a7c = 0x1f;
          }
        }
      }
      else {
        DAT_006e4a7c = 1;
      }
LAB_00433073:
      uVar9 = 0;
      goto LAB_004330e7;
    }
LAB_0043307b:
    FUN_00432771(*(undefined4 *)(unaff_EBP + 8));
    iVar8 = *(int *)(unaff_EBP + -0x20);
    iVar10 = FUN_004329f3(unaff_EBP + -0x60);
    if ((*(char *)(unaff_EBP + 0xc) != '\0') && (iVar10 != iVar8)) {
      if (iVar10 != 0) {
        FUN_00432984();
      }
      FUN_004327d9(unaff_EBP + -0x60);
      if (iVar10 != 0) {
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x5c);
        *(int *)(unaff_EBP + -0x3c) = iVar8;
        *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x58);
        uVar9 = *(undefined4 *)(iVar8 + 0x110);
        *(undefined1 *)(unaff_EBP + -0x48) = 1;
        *(undefined4 *)(unaff_EBP + -0x34) = uVar9;
        iVar8 = unaff_EBP + -0x48;
        goto LAB_004330e0;
      }
    }
  }
  uVar9 = 1;
LAB_004330e7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar9;
}

