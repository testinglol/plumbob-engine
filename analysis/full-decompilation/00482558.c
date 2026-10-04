
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00482558(void)

{
  short sVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  BOOL BVar8;
  int *piVar9;
  int *extraout_ECX;
  undefined4 uVar10;
  int iVar11;
  undefined2 extraout_var;
  undefined4 uVar12;
  undefined2 extraout_var_00;
  int iVar13;
  undefined1 uVar14;
  int *piVar15;
  int unaff_EBP;
  undefined4 *puVar16;
  bool bVar17;
  float10 fVar18;
  undefined *puVar19;
  undefined *puVar20;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  iVar4 = extraout_ECX[0x13];
  *(int **)(unaff_EBP + -0x20) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0xf) = 1;
  iVar4 = FUN_006359f2(iVar4,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
  if ((iVar4 != 0) &&
     (((*(byte *)(iVar4 + 0x634) & 1) == 1 || ((*(byte *)(iVar4 + 0x614) & 1) == 1)))) {
    *(undefined1 *)(unaff_EBP + -0xe) = 1;
  }
  iVar4 = extraout_ECX[0x13];
  if (*(short *)(iVar4 + 0x6c) != 0) {
    *(undefined1 *)(unaff_EBP + -0xf) = 0;
  }
  piVar15 = DAT_006e486c;
  if ((extraout_ECX[1] - *extraout_ECX & 0xfffffff0U) == 0) {
    if (extraout_ECX[0x22] == 1) {
      extraout_ECX[0x22] = 7;
    }
  }
  else {
    sVar1 = *(short *)(iVar4 + 0x84);
    uVar10 = CONCAT22((short)((uint)iVar4 >> 0x10),sVar1);
    *(undefined4 *)(unaff_EBP + -0x28) = uVar10;
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*piVar15 + 0x14);
    if ((*(char *)(unaff_EBP + -0xe) != '\0') || (sVar1 == *(short *)(extraout_ECX[0x12] + 0x84))) {
      iVar4 = FUN_004670a4(uVar10);
      *(int *)(unaff_EBP + -0x1c) = iVar4;
      if (iVar4 != 0) {
        iVar4 = FUN_00468838();
        if (iVar4 == 1) {
          cVar3 = FUN_00468851();
          if (cVar3 == '\0') goto LAB_0048264b;
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
        else {
LAB_0048264b:
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
        }
        *(int *)(unaff_EBP + -0x60) = extraout_ECX[0x1c];
        *(int *)(unaff_EBP + -0x5c) = extraout_ECX[0x1b];
        iVar4 = extraout_ECX[0x13];
        *(undefined4 *)(unaff_EBP + -200) = *(undefined4 *)(iVar4 + 0x108);
        *(undefined4 *)(unaff_EBP + -0xcc) = *(undefined4 *)(iVar4 + 0x10c);
        *(undefined4 *)(unaff_EBP + -0xc0) = *(undefined4 *)(iVar4 + 0x100);
        *(undefined4 *)(unaff_EBP + -0xc4) = *(undefined4 *)(iVar4 + 0x104);
        if ((*(char *)(unaff_EBP + -0xf) == '\0') ||
           (*(undefined4 *)(unaff_EBP + -0x30) = 3, *(char *)(unaff_EBP + -0xd) == '\0')) {
          *(undefined4 *)(unaff_EBP + -0x30) = 0;
        }
        *(int *)(unaff_EBP + -0x14) = DAT_006c296c - (DAT_006c296c >> 0x1f);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) >> 1;
        if ((DAT_006e5604 & 1) == 0) {
          DAT_006e5604 = DAT_006e5604 | 1;
          DAT_006e55f8 = 0;
          DAT_006e55fc = 0;
          _DAT_006e5600 = 0;
          FUN_00635543(&LAB_0048322e);
        }
        FUN_00468acc(DAT_006e55f8,DAT_006e55fc);
        piVar15 = extraout_ECX;
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          for (iVar4 = *(int *)(*(int *)(unaff_EBP + -0x2c) + 0x30); iVar4 != 0;
              iVar4 = *(int *)(iVar4 + 0xe0)) {
            if ((iVar4 != piVar15[0x13]) &&
               (*(short *)(iVar4 + 0x84) == *(short *)(unaff_EBP + -0x28))) {
              cVar3 = FUN_00481947(iVar4);
              if (cVar3 == '\0') {
                iVar5 = (-(uint)(*(short *)(iVar4 + 0x5e) != 0) & 0x8000000b) + 0x7fffffff;
                *(int *)(unaff_EBP + -0x24) = iVar5;
                FUN_00469648(*(undefined4 *)(iVar4 + 0x10c),*(undefined4 *)(iVar4 + 0x108),
                             *(undefined4 *)(iVar4 + 0x104),*(undefined4 *)(iVar4 + 0x100),iVar5);
                if (*(short *)(*(int *)(iVar4 + 0x118) + 0x12) == 8) {
                  uVar6 = FUN_00435a73();
                  *(uint *)(unaff_EBP + -0x2c) = uVar6;
                  if ((uVar6 & 1) != 0) {
                    iVar5 = *(int *)(iVar4 + 0x108);
                    *(undefined4 *)(unaff_EBP + -0x24) = 10000;
                    puVar7 = (undefined4 *)
                             FUN_00469648(*(undefined4 *)(iVar4 + 0x10c),iVar5,
                                          *(undefined4 *)(iVar4 + 0x104),iVar5 + 1,10000);
                    iVar5 = *(int *)(unaff_EBP + -0x14);
                    puVar16 = (undefined4 *)(unaff_EBP + -0x58);
                    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *puVar16 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    InflateRect((LPRECT)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x14),iVar5);
                    piVar15 = *(int **)(unaff_EBP + -0x20);
                  }
                  if ((*(byte *)(unaff_EBP + -0x2c) & 4) != 0) {
                    iVar5 = *(int *)(iVar4 + 0x104);
                    *(undefined4 *)(unaff_EBP + -0x24) = 10000;
                    puVar7 = (undefined4 *)
                             FUN_00469648(iVar5 + -1,*(undefined4 *)(iVar4 + 0x108),iVar5,
                                          *(undefined4 *)(iVar4 + 0x100),10000);
                    iVar5 = *(int *)(unaff_EBP + -0x14);
                    puVar16 = (undefined4 *)(unaff_EBP + -0x58);
                    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *puVar16 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    InflateRect((LPRECT)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x14),iVar5);
                    piVar15 = *(int **)(unaff_EBP + -0x20);
                  }
                  if ((*(byte *)(unaff_EBP + -0x2c) & 0x10) != 0) {
                    iVar5 = *(int *)(iVar4 + 0x100);
                    uVar10 = *(undefined4 *)(iVar4 + 0x104);
                    *(undefined4 *)(unaff_EBP + -0x24) = 10000;
                    puVar7 = (undefined4 *)
                             FUN_00469648(*(undefined4 *)(iVar4 + 0x10c),iVar5 + -1,uVar10,iVar5,
                                          10000);
                    iVar5 = *(int *)(unaff_EBP + -0x14);
                    puVar16 = (undefined4 *)(unaff_EBP + -0x58);
                    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *puVar16 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    InflateRect((LPRECT)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x14),iVar5);
                    piVar15 = *(int **)(unaff_EBP + -0x20);
                  }
                  if ((*(byte *)(unaff_EBP + -0x2c) & 0x40) != 0) {
                    iVar5 = *(int *)(iVar4 + 0x10c);
                    *(undefined4 *)(unaff_EBP + -0x24) = 10000;
                    puVar7 = (undefined4 *)
                             FUN_00469648(iVar5,*(undefined4 *)(iVar4 + 0x108),iVar5 + 1,
                                          *(undefined4 *)(iVar4 + 0x100),10000);
                    iVar5 = *(int *)(unaff_EBP + -0x14);
                    puVar16 = (undefined4 *)(unaff_EBP + -0x58);
                    for (iVar11 = 5; iVar11 != 0; iVar11 = iVar11 + -1) {
                      *puVar16 = *puVar7;
                      puVar7 = puVar7 + 1;
                      puVar16 = puVar16 + 1;
                    }
                    InflateRect((LPRECT)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x14),iVar5);
                    piVar15 = *(int **)(unaff_EBP + -0x20);
                  }
                }
                BVar8 = IntersectRect((LPRECT)(unaff_EBP + -0x19c),(RECT *)(unaff_EBP + -0x58),
                                      (RECT *)(unaff_EBP + -0xcc));
                if (BVar8 == 0) {
                  if (((*(short *)(*(int *)(iVar4 + 0x118) + 0x12) == 2) ||
                      (*(int *)(unaff_EBP + -0x24) == 0x7fffffff)) ||
                     (7 < *(int *)(unaff_EBP + -0x24))) {
                    InflateRect((LPRECT)(unaff_EBP + -0x58),*(int *)(unaff_EBP + -0x14),
                                *(int *)(unaff_EBP + -0x14));
                  }
                  FUN_0046ad0a(unaff_EBP + -0x58);
                }
              }
            }
          }
        }
        *(undefined4 *)(unaff_EBP + -0xa8) = 0;
        *(undefined4 *)(unaff_EBP + -0xa0) = 0;
        *(undefined4 *)(unaff_EBP + -0x80) = 0x40;
        *(undefined4 *)(unaff_EBP + -0xbc) = 0;
        *(undefined4 *)(unaff_EBP + -0xb8) = 0;
        *(undefined4 *)(unaff_EBP + -0xb4) = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined4 **)(unaff_EBP + -0xa4) = &DAT_006e55f8;
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          if ((*(char *)(unaff_EBP + -0xf) == '\0') && (*(char *)(unaff_EBP + -0xd) != '\0')) {
            FUN_00481a0d(*(undefined4 *)(unaff_EBP + -0x28),unaff_EBP + -0xbc,0);
            iVar4 = unaff_EBP + -0xbc;
          }
          else {
            iVar4 = FUN_00467a3c();
          }
          *(int *)(unaff_EBP + -0xa0) = iVar4;
        }
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x30);
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x6c) = 0;
        *(int *)(unaff_EBP + -0xa8) = unaff_EBP + -0x44;
        *(undefined4 *)(unaff_EBP + -0x68) = 0;
        *(undefined4 *)(unaff_EBP + -100) = 0;
        iVar4 = piVar15[1];
        iVar5 = *piVar15;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        if (0 < (int)(iVar4 - iVar5 & 0xfffffff0U)) {
          do {
            piVar9 = (int *)(*(int *)(unaff_EBP + -0x38) * 0x10 + iVar5);
            if (0 < piVar9[2]) {
              FUN_00469648(piVar9[1],*piVar9,piVar9[1] + 1,*piVar9 + 1,
                           (piVar15[0x15] - piVar9[2]) * 0x10);
              FUN_0046ad0a(unaff_EBP + -0x58);
              FUN_0042eab4(unaff_EBP + -0x38);
            }
            iVar4 = piVar15[1];
            iVar5 = *piVar15;
            *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x38) + 1;
          } while (*(int *)(unaff_EBP + -0x38) < iVar4 - iVar5 >> 4);
        }
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          fVar18 = (float10)FUN_004681e5();
          if (fVar18 <= (float10)_DAT_00667ac8) {
            iVar4 = FUN_004681ec();
            if (99 < iVar4) goto LAB_00482a47;
          }
          *(undefined1 *)(unaff_EBP + -0x84) = 0;
        }
        else {
LAB_00482a47:
          *(undefined1 *)(unaff_EBP + -0x84) = 1;
          *(undefined4 *)(unaff_EBP + -0x80) = 0x80;
        }
        *(undefined1 *)(unaff_EBP + -0x8b) = 0;
        *(undefined1 *)(unaff_EBP + -0x94) = 0;
        bVar17 = DAT_006e5606 != 0;
        *(undefined4 *)(unaff_EBP + -0x9c) = *(undefined4 *)(unaff_EBP + -0x60);
        *(undefined4 *)(unaff_EBP + -0x98) = *(undefined4 *)(unaff_EBP + -0x5c);
        *(undefined1 *)(unaff_EBP + -0x8c) = 1;
        *(undefined1 *)(unaff_EBP + -0x78) = 1;
        if (bVar17) {
          FUN_00632b81(1);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_0046f824(unaff_EBP + -0x2f0,0,0x104);
          *(undefined ***)(unaff_EBP + -0x2fc) = &PTR_FUN_006664e8;
          FUN_0046f847(&DAT_006c5bc4,0xffffffff);
          FUN_0046f847(*(undefined4 *)(*(int *)(piVar15[0x13] + 0x11c) + 0x18),0xffffffff);
          FUN_0046f847(&DAT_006c5bbc,0xffffffff);
          FUN_00632c55(*(undefined4 *)(unaff_EBP + -0x2f8),2,DAT_00689070);
          if (*(int *)(unaff_EBP + -0x184 + *(int *)(*(int *)(unaff_EBP + -0x18c) + 4)) == 0) {
            FUN_0046aa90(-(uint)(unaff_EBP != 0x18c) & unaff_EBP - 0x180U);
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_00632c42();
          FUN_00632b08();
        }
        if (DAT_006e560c != 0) {
          cVar3 = FUN_004831e1(*(undefined4 *)(unaff_EBP + -0xa4),unaff_EBP + -0x60);
          if (cVar3 == '\0') {
            FUN_004831e1(*(undefined4 *)(unaff_EBP + -0xa0),unaff_EBP + -0x60);
          }
        }
        FUN_00483064();
        iVar4 = *(int *)(unaff_EBP + -0x40);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar5 = FUN_004681ec();
        iVar4 = iVar5 * ((iVar4 - *(int *)(unaff_EBP + -0x44)) / 0x14) + 0x32;
        if (1000 < iVar4) {
          iVar4 = 1000;
        }
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        iVar5 = FUN_004681ec();
        if ((iVar5 < 0x101) || (*(char *)(unaff_EBP + -0x84) == '\0')) {
LAB_00482c58:
          FUN_0046a9d1(unaff_EBP + -0xa8);
          while ((*(int *)(unaff_EBP + -0x100) != 0 && (*(int *)(unaff_EBP + -0xfc) <= iVar4))) {
            FUN_00483023();
          }
          if (*(int *)(unaff_EBP + -0xd4) == -1) {
            FUN_0048189f();
          }
          else {
            piVar15[0x14] = *(int *)(*(int *)(unaff_EBP + -0x6c) + *(int *)(unaff_EBP + -0xd4) * 4);
          }
          iVar4 = 0;
          iVar5 = *(int *)(unaff_EBP + -0x108) - *(int *)(unaff_EBP + -0x10c) >> 3;
          if (0 < iVar5) {
            do {
              *(undefined4 *)(unaff_EBP + -0x34) = 0;
              *(undefined4 *)(unaff_EBP + -0x30) = 0;
              *(undefined4 *)(unaff_EBP + -0x30) =
                   *(undefined4 *)(*(int *)(unaff_EBP + -0x10c) + iVar4 * 8);
              *(undefined4 *)(unaff_EBP + -0x34) =
                   *(undefined4 *)(*(int *)(unaff_EBP + -0x10c) + iVar4 * 8 + 4);
              FUN_0045f7c5(unaff_EBP + -0x34);
              iVar4 = iVar4 + 1;
            } while (iVar4 < iVar5);
          }
          if (iVar5 == 0) {
            *(undefined4 *)(*(int *)(unaff_EBP + -0x20) + 0x88) = 3;
            goto LAB_00482fd8;
          }
          if (DAT_006e5608 == 0) {
            piVar15 = *(int **)(unaff_EBP + 8);
          }
          else {
            FUN_00632b81(1);
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_0046f824(unaff_EBP + -0x2f0,0,0x104);
            *(undefined ***)(unaff_EBP + -0x2fc) = &PTR_FUN_006664e8;
            FUN_0046f847(s___AllRoutes_txt_006c5bac,0xffffffff);
            FUN_00632c55(*(undefined4 *)(unaff_EBP + -0x2f8),8,DAT_00689070);
            if (*(int *)(unaff_EBP + -0x184 + *(int *)(*(int *)(unaff_EBP + -0x18c) + 4)) == 0) {
              iVar4 = *(int *)(unaff_EBP + -0x20);
              puVar20 = &DAT_006c08dc;
              iVar5 = *(int *)(iVar4 + 0x4c);
              uVar12 = CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0xf0));
              puVar19 = &DAT_006c3d7c;
              uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x11c) + 0x18);
              FUN_006323d0(s_From__006c5ba4);
              FUN_006323d0(uVar10);
              FUN_006323d0(puVar19);
              FUN_006330c7(uVar12);
              FUN_006323d0(puVar20);
              iVar4 = *(int *)(iVar4 + 0x48);
              puVar20 = &DAT_006c08dc;
              uVar12 = CONCAT22(extraout_var_00,*(undefined2 *)(iVar4 + 0xf0));
              puVar19 = &DAT_006c3d7c;
              uVar10 = *(undefined4 *)(*(int *)(iVar4 + 0x11c) + 0x18);
              FUN_006323d0(&DAT_006c5b9c);
              FUN_006323d0(uVar10);
              FUN_006323d0(puVar19);
              FUN_006330c7(uVar12);
              FUN_006323d0(puVar20);
              piVar15 = *(int **)(unaff_EBP + 8);
              FUN_004830d6(-(uint)(unaff_EBP != 0x18c) & unaff_EBP - 0x180U,piVar15);
            }
            else {
              piVar15 = *(int **)(unaff_EBP + 8);
            }
            *(undefined1 *)(unaff_EBP + -4) = 4;
            FUN_00632c42();
            FUN_00632b08();
          }
          if (DAT_006e560c != 0) {
            iVar4 = piVar15[1];
            iVar5 = *piVar15;
            *(undefined4 *)(unaff_EBP + -0x1c) = 0;
            if (iVar4 - iVar5 >> 3 != 1) {
              do {
                iVar13 = *(int *)(unaff_EBP + -0x1c) * 8;
                iVar4 = *(int *)(iVar13 + 8 + iVar5);
                iVar11 = *(int *)(iVar13 + 0xc + iVar5);
                *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar13 + iVar5);
                iVar5 = *(int *)(iVar13 + 4 + iVar5);
                *(int *)(unaff_EBP + -0x14) = iVar5;
                iVar5 = iVar5 - iVar11;
                if (iVar5 < 0) {
                  iVar5 = -iVar5;
                }
                *(int *)(unaff_EBP + 8) = iVar5 + 1;
                iVar5 = *(int *)(unaff_EBP + -0x18) - iVar4;
                *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
                if (iVar5 < 0) {
                  iVar5 = -iVar5;
                }
                *(int *)(unaff_EBP + -0x30) = iVar5 + 1;
                if (*(float *)(unaff_EBP + 8) <= (float)*(int *)(unaff_EBP + -0x30)) {
                  *(float *)(unaff_EBP + -0x30) = 1.0 / (float)*(int *)(unaff_EBP + -0x30);
                }
                else {
                  *(float *)(unaff_EBP + -0x30) = 1.0 / *(float *)(unaff_EBP + 8);
                }
                FUN_00422055(0xffffffff,0xffffffff);
                *(int *)(unaff_EBP + -0x28) = iVar11 - *(int *)(unaff_EBP + -0x14);
                *(undefined4 *)(unaff_EBP + 8) = 0;
                iVar5 = *(int *)(unaff_EBP + -0x28);
                *(int *)(unaff_EBP + -0x28) = iVar4 - *(int *)(unaff_EBP + -0x18);
                *(float *)(unaff_EBP + -0x2c) = (float)iVar5;
                *(float *)(unaff_EBP + -0x20) = (float)*(int *)(unaff_EBP + -0x14);
                *(float *)(unaff_EBP + -0x28) = (float)*(int *)(unaff_EBP + -0x28);
                *(float *)(unaff_EBP + -0x24) = (float)*(int *)(unaff_EBP + -0x18);
                do {
                  iVar4 = __ftol();
                  iVar5 = __ftol();
                  if ((iVar4 != *(int *)(unaff_EBP + -0x70)) ||
                     (iVar5 != *(int *)(unaff_EBP + -0x74))) {
                    *(int *)(unaff_EBP + -0x74) = iVar5;
                    *(int *)(unaff_EBP + -0xac) = iVar5;
                    *(int *)(unaff_EBP + -0x70) = iVar4;
                    *(int *)(unaff_EBP + -0xb0) = iVar4;
                    cVar3 = FUN_004831e1(*(undefined4 *)(unaff_EBP + -0xa4),unaff_EBP + -0xb0);
                    if (cVar3 == '\0') {
                      FUN_004831e1(*(undefined4 *)(unaff_EBP + -0xa0),unaff_EBP + -0xb0);
                    }
                  }
                  fVar2 = *(float *)(unaff_EBP + 8) + *(float *)(unaff_EBP + -0x30);
                  *(float *)(unaff_EBP + 8) = fVar2;
                } while (fVar2 < _DAT_00666748);
                iVar4 = piVar15[1];
                iVar5 = *piVar15;
                *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
              } while (*(uint *)(unaff_EBP + -0x1c) < (iVar4 - iVar5 >> 3) - 1U);
            }
          }
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_00483238();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0048c4c9();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_0040f6e0();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          uVar14 = 1;
        }
        else {
          *(undefined1 *)(unaff_EBP + -0x84) = 0;
          FUN_0046a9d1(unaff_EBP + -0xa8);
          while ((*(int *)(unaff_EBP + -0x100) != 0 && (*(int *)(unaff_EBP + -0xfc) <= iVar4))) {
            FUN_00483023();
          }
          if ((*(int *)(unaff_EBP + -0x108) - *(int *)(unaff_EBP + -0x10c) & 0xfffffff8U) == 0) {
            *(undefined1 *)(unaff_EBP + -0xd) = 1;
          }
          *(undefined1 *)(unaff_EBP + -0x84) = 1;
          FUN_0048309c();
          if (*(char *)(unaff_EBP + -0xd) == '\0') goto LAB_00482c58;
          piVar15[0x22] = 3;
LAB_00482fd8:
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_00483238();
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0048c4c9();
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_0040f6e0();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          uVar14 = 0;
        }
        FUN_0040f6e0();
        goto LAB_00483012;
      }
    }
    FUN_0048189f();
  }
  uVar14 = 0;
LAB_00483012:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar14;
}

