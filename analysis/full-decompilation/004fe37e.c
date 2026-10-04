
undefined1 FUN_004fe37e(void)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  int unaff_EBP;
  int iVar8;
  undefined **ppuVar9;
  ushort *puVar10;
  int *piVar11;
  
  FUN_00634c24();
  if (*(int *)(DAT_006f2a08 + 0xb0) != 0) {
    iVar4 = FUN_004ce4a9();
    *(int *)(unaff_EBP + -0x10) = iVar4;
    if (iVar4 != 0) {
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = 0;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b870f(s_catalog_name_006cc234);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_004d5f61(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      FUN_005b870f(s_edith_name_006cc228);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004d5f61(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      iVar4 = _strcmp(PTR_s_function_seating_006ca0ec,&DAT_006de560);
      if (iVar4 != 0) {
        ppuVar9 = &PTR_s_function_seating_006ca0ec;
        do {
          FUN_005b870f(*ppuVar9);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_004d5f61(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          ppuVar9 = ppuVar9 + 1;
          iVar4 = _strcmp(*ppuVar9,&DAT_006de560);
        } while (iVar4 != 0);
      }
      iVar4 = _strcmp(PTR_s_subsort_1_006ca124,&DAT_006de560);
      if (iVar4 != 0) {
        ppuVar9 = &PTR_s_subsort_1_006ca124;
        do {
          FUN_005b870f(*ppuVar9);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          FUN_004d5f61(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          ppuVar9 = ppuVar9 + 1;
          iVar4 = _strcmp(*ppuVar9,&DAT_006de560);
        } while (iVar4 != 0);
      }
      iVar4 = _strcmp(PTR_s_room_familyroom_dining_006ca15c,&DAT_006de560);
      if (iVar4 != 0) {
        ppuVar9 = &PTR_s_room_familyroom_dining_006ca15c;
        do {
          FUN_005b870f(*ppuVar9);
          *(undefined1 *)(unaff_EBP + -4) = 6;
          FUN_004d5f61(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          ppuVar9 = ppuVar9 + 1;
          iVar4 = _strcmp(*ppuVar9,&DAT_006de560);
        } while (iVar4 != 0);
      }
      iVar4 = _strcmp(PTR_s_downtown_dining_006ca190,&DAT_006de560);
      if (iVar4 != 0) {
        ppuVar9 = &PTR_s_downtown_dining_006ca190;
        do {
          FUN_005b870f(*ppuVar9);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_004d5f61(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          ppuVar9 = ppuVar9 + 1;
          iVar4 = _strcmp(*ppuVar9,&DAT_006de560);
        } while (iVar4 != 0);
      }
      iVar4 = _strcmp(PTR_s_vacation_1_006ca1c8,&DAT_006de560);
      if (iVar4 != 0) {
        ppuVar9 = &PTR_s_vacation_1_006ca1c8;
        do {
          FUN_005b870f(*ppuVar9);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_004d5f61(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005b8770();
          ppuVar9 = ppuVar9 + 1;
          iVar4 = _strcmp(*ppuVar9,&DAT_006de560);
        } while (iVar4 != 0);
      }
      piVar5 = *(int **)(*(int *)(unaff_EBP + -0x10) + 4);
      piVar11 = *(int **)(*(int *)(unaff_EBP + -0x10) + 8);
      *(int **)(unaff_EBP + -0x10) = piVar5;
      *(int **)(unaff_EBP + -0x38) = piVar11;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 9;
      if (piVar5 != piVar11) {
        while( true ) {
          iVar4 = *piVar5;
          FUN_005ed3c4();
          iVar4 = *(int *)(iVar4 + 0x28);
          if ((((iVar4 != 0) && (cVar3 = FUN_0045773e(), cVar3 == '\0')) &&
              (iVar2 = *(int *)(iVar4 + 0x60), iVar2 != 0)) &&
             ((*(short *)(iVar2 + 0x14) != 0 && (*(short *)(iVar2 + 0x16) == -1)))) {
            uVar6 = FUN_004096c2();
            FUN_005b870f(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_004d5f61(unaff_EBP + -0x1c);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b8770();
            if (*(int *)(iVar4 + 0x18) == 0) {
              FUN_004fea2d();
            }
            else {
              FUN_005b870f(*(int *)(iVar4 + 0x18));
              *(undefined1 *)(unaff_EBP + -4) = 0xb;
              FUN_004d5f61(unaff_EBP + -0x78);
              *(undefined1 *)(unaff_EBP + -4) = 9;
              FUN_005b8770();
            }
            uVar1 = *(ushort *)(iVar2 + 0x50);
            *(undefined2 *)(unaff_EBP + -0x50) = *(undefined2 *)(iVar2 + 0xbc);
            *(undefined2 *)(unaff_EBP + -0x54) = *(undefined2 *)(iVar2 + 0x4e);
            *(undefined2 *)(unaff_EBP + -0x4c) = *(undefined2 *)(iVar2 + 0xbe);
            *(undefined2 *)(unaff_EBP + -0x3c) = *(undefined2 *)(iVar2 + 0xc2);
            if (DAT_006ca110 != 0) {
              puVar10 = (ushort *)&DAT_006ca110;
              do {
                if ((*puVar10 & uVar1) == 0) {
                  FUN_004fea2d();
                }
                else {
                  FUN_005b870f(&DAT_006c6f28);
                  *(undefined1 *)(unaff_EBP + -4) = 0xc;
                  FUN_004d5f61(unaff_EBP + -0x60);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                puVar10 = puVar10 + 1;
              } while (*puVar10 != 0);
            }
            if (DAT_006ca148 != 0) {
              puVar10 = (ushort *)&DAT_006ca148;
              do {
                if ((*puVar10 & (ushort)*(undefined4 *)(unaff_EBP + -0x50)) == 0) {
                  FUN_004fea2d();
                }
                else {
                  FUN_005b870f(&DAT_006c6f28);
                  *(undefined1 *)(unaff_EBP + -4) = 0xd;
                  FUN_004d5f61(unaff_EBP + -0x90);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                puVar10 = puVar10 + 1;
              } while (*puVar10 != 0);
            }
            if (DAT_006ca17c != 0) {
              puVar10 = (ushort *)&DAT_006ca17c;
              do {
                if ((*puVar10 & (ushort)*(undefined4 *)(unaff_EBP + -0x54)) == 0) {
                  FUN_004fea2d();
                }
                else {
                  FUN_005b870f(&DAT_006c6f28);
                  *(undefined1 *)(unaff_EBP + -4) = 0xe;
                  FUN_004d5f61(unaff_EBP + -0x6c);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                puVar10 = puVar10 + 1;
              } while (*puVar10 != 0);
            }
            if (DAT_006ca1b4 != 0) {
              puVar10 = (ushort *)&DAT_006ca1b4;
              do {
                if ((*puVar10 & (ushort)*(undefined4 *)(unaff_EBP + -0x4c)) == 0) {
                  FUN_004fea2d();
                }
                else {
                  FUN_005b870f(&DAT_006c6f28);
                  *(undefined1 *)(unaff_EBP + -4) = 0xf;
                  FUN_004d5f61(unaff_EBP + -0x84);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                puVar10 = puVar10 + 1;
              } while (*puVar10 != 0);
            }
            if (DAT_006ca1ec != 0) {
              puVar10 = (ushort *)&DAT_006ca1ec;
              do {
                if ((*puVar10 & *(ushort *)(unaff_EBP + -0x3c)) == 0) {
                  FUN_004fea2d();
                }
                else {
                  FUN_005b870f(&DAT_006c6f28);
                  *(undefined1 *)(unaff_EBP + -4) = 0x10;
                  FUN_004d5f61(unaff_EBP + -0x9c);
                  *(undefined1 *)(unaff_EBP + -4) = 9;
                  FUN_005b8770();
                }
                puVar10 = puVar10 + 1;
              } while (*puVar10 != 0);
            }
            FUN_004feac6(unaff_EBP + -0x28);
            FUN_004d5f89(*(undefined4 *)(unaff_EBP + -0x28),*(undefined4 *)(unaff_EBP + -0x24));
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
          if (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EBP + -0x38)) break;
          piVar5 = *(int **)(unaff_EBP + -0x10);
        }
      }
      uVar7 = 0;
      if ((*(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x48)) / 0xc != 0) {
        iVar4 = FUN_00635845(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4),&DAT_006c0a78);
        *(int *)(unaff_EBP + 8) = iVar4;
        if (iVar4 == 0) {
          uVar7 = 0;
        }
        else {
          iVar2 = *(int *)(unaff_EBP + -0x30);
          iVar8 = *(int *)(unaff_EBP + -0x34);
          if ((iVar2 - iVar8) / 0xc != 0) {
            for (; iVar8 != iVar2; iVar8 = iVar8 + 0xc) {
              uVar6 = FUN_004096c2();
              FUN_006357d8(iVar4,&DAT_006c8db4,uVar6);
            }
          }
          FUN_006357d8(iVar4,&DAT_006c08dc);
          piVar11 = *(int **)(unaff_EBP + -0x48);
          piVar5 = *(int **)(unaff_EBP + -0x44);
          if (((int)piVar5 - (int)piVar11) / 0xc != 0) {
            *(int **)(unaff_EBP + -0x3c) = piVar5;
            if (piVar11 != piVar5) {
              do {
                iVar4 = *piVar11;
                iVar2 = piVar11[1];
                *(int *)(unaff_EBP + -0x38) = iVar2;
                if (iVar4 != iVar2) {
                  do {
                    uVar6 = FUN_004096c2();
                    FUN_006357d8(*(undefined4 *)(unaff_EBP + 8),&DAT_006c8db4,uVar6);
                    iVar4 = iVar4 + 0xc;
                  } while (iVar4 != *(int *)(unaff_EBP + -0x38));
                }
                FUN_006357d8(*(undefined4 *)(unaff_EBP + 8),&DAT_006c08dc);
                piVar11 = piVar11 + 3;
              } while (piVar11 != *(int **)(unaff_EBP + -0x3c));
            }
            FUN_006357d8(*(undefined4 *)(unaff_EBP + 8),&DAT_006c08dc);
          }
          FUN_0063558d(*(undefined4 *)(unaff_EBP + 8));
          uVar7 = 1;
        }
      }
      FUN_004feaee(*(undefined4 *)(unaff_EBP + -0x48),*(undefined4 *)(unaff_EBP + -0x44));
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004d5e80();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_004d5e80();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004fea7e();
      goto LAB_004fe9d5;
    }
  }
  uVar7 = 0;
LAB_004fe9d5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

