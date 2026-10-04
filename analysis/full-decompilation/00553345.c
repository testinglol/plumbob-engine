
undefined1 FUN_00553345(void)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  size_t sVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  int *piVar11;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  FUN_005b870f(s__family_006c28b4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b870f(&DAT_006c28ac);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004f2baf(unaff_EBP + -0x58);
  pcVar3 = (char *)FUN_0041532c(0x58);
  sVar4 = _strlen(pcVar3);
  FUN_00412d8a(pcVar3,pcVar3 + sVar4);
  FUN_005d8277(unaff_EBP + -0x58,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar5 = FUN_005d4956(s___mtf_006cdda4);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d8ab4(uVar5,1);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  FUN_0054dee4();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  cVar2 = FUN_005532d4(unaff_EBP + -0x19c,unaff_EBP + -0x94,unaff_EBP + -100);
  do {
    if (cVar2 == '\0') {
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0042ecc0();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0042a889();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return *(undefined1 *)(unaff_EBP + -0x11);
    }
    uVar5 = FUN_004096c2();
    FUN_0046f824(unaff_EBP + -0x65c,0,0x104);
    *(undefined ***)(unaff_EBP + -0x668) = &PTR_FUN_006664e8;
    FUN_0046f847(uVar5,0xffffffff);
    FUN_004e2e34();
    *(undefined1 *)(unaff_EBP + -4) = 7;
    cVar2 = FUN_004e2b6b(unaff_EBP + -0x668,unaff_EBP + -0x480,1);
    if (cVar2 == '\0') {
LAB_00553ebf:
      FUN_005d82fa();
    }
    else {
      piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
      piVar6 = (int *)(**(code **)(*piVar6 + 0x58))(0);
      iVar7 = (**(code **)(*piVar6 + 0x78))((int)*(char *)(DAT_006e486c + 100));
      iVar8 = (**(code **)(*piVar6 + 0x78))((int)*(char *)(unaff_EBP + -0x2f0));
      if ((*(char *)(unaff_EBP + -0x370) == '\0') || (*(int *)(unaff_EBP + -0x358) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((iVar7 == iVar8) || (bVar1)) {
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        if (*(char *)(unaff_EBP + -0x370) != '\0') {
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x328);
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 1;
        if ((*(char *)(unaff_EBP + -0x370) == '\0') || (*(int *)(unaff_EBP + -0x358) == 0)) {
          pvVar9 = operator_new(0x148);
          *(void **)(unaff_EBP + -0x10) = pvVar9;
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          if (pvVar9 == (void *)0x0) {
            iVar7 = 0;
          }
          else {
            iVar7 = FUN_00523434();
          }
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8680();
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          uVar5 = FUN_004705f2(1,0xffffffff);
          FUN_005d4bbf(uVar5);
          iVar8 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x34),0,
                               *(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34));
          if (iVar8 != -1) {
            FUN_00455790(iVar8,*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34),
                         unaff_EBP + -0x344);
          }
          uVar5 = FUN_004096c2();
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0x12;
          FUN_00523be3(unaff_EBP + -0x120);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_005d4bbf(&DAT_006de560);
          if (*(int *)(unaff_EBP + -0x28) == 0) {
            pcVar3 = (char *)FUN_004705f2(2,0xffffffff);
            sVar4 = _strlen(pcVar3);
            FUN_00412d8a(pcVar3,pcVar3 + sVar4);
          }
          else {
            iVar8 = *(int *)(unaff_EBP + -0x28) + -0x5a;
            if ((iVar8 < 0) || (8 < iVar8)) {
              iVar8 = 0;
            }
            else {
              iVar8 = *(int *)(*(int *)(unaff_EBP + -0x24) + 0x14c + iVar8 * 4) + 0x194;
            }
            if (iVar8 != 0) {
              FUN_0046f824(unaff_EBP + -0x14c,0,0x20);
              *(undefined ***)(unaff_EBP + -0x158) = &PTR_FUN_006666e4;
              FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x28));
              if (*(int *)(iVar8 + 0x24) == -1) {
                if (*(int *)(iVar8 + 0x18) == 0) {
                  uVar5 = 4;
                }
                else {
                  uVar5 = 5;
                }
                pcVar3 = (char *)FUN_004705f2(uVar5,0xffffffff);
                sVar4 = _strlen(pcVar3);
                FUN_00412d8a(pcVar3,pcVar3 + sVar4);
              }
              else {
                pcVar3 = (char *)FUN_004705f2(3,0xffffffff);
                *(char **)(unaff_EBP + -0x10) = pcVar3;
                sVar4 = _strlen(pcVar3);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar4 + *(int *)(unaff_EBP + -0x10))
                ;
                iVar10 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x34),0,
                                      *(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34));
                if (iVar10 != -1) {
                  FUN_00455790(iVar10,*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x34),
                               iVar8 + 0x28);
                }
              }
              iVar8 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x40),0,
                                   *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x40));
              if (iVar8 != -1) {
                FUN_00455800(iVar8,*(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x40),
                             *(undefined4 *)(unaff_EBP + -0x154));
              }
            }
          }
          uVar5 = FUN_004096c2();
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0x13;
          FUN_00523be3(unaff_EBP + -0xe0);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          uVar5 = FUN_004705f2(7,0xffffffff);
          FUN_005d4bbf(uVar5);
          uVar5 = FUN_004096c2();
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0x14;
          FUN_0052386b(unaff_EBP + -0xec,1);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_00523afc(1,0xd);
          uVar5 = FUN_004705f2(8,0xffffffff);
          FUN_005d4bbf(uVar5);
          uVar5 = FUN_004096c2();
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0x15;
          FUN_0052386b(unaff_EBP + -0x104,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_00523afc(0,0x1b);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x4ec) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x16;
          uVar5 = FUN_0041532c(9,unaff_EBP + -0x4ec,0);
          cVar2 = FUN_004fff98(0x90,uVar5);
          if (cVar2 != '\0') {
            uVar5 = FUN_004705f2(5,0xffffffff);
            FUN_005d4956(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            FUN_0052386b(unaff_EBP + -0xc4,2);
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            FUN_005b8770();
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_00470467();
          (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
                    (unaff_EBP + -0x4c,unaff_EBP + -0x48,unaff_EBP + -0x44);
          piVar6 = *(int **)(unaff_EBP + -0x24);
          uVar5 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x4c),*(undefined4 *)(unaff_EBP + -0x48)
                               ,*(undefined4 *)(unaff_EBP + -0x44));
          *(undefined4 *)(iVar7 + 100) = uVar5;
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x36c);
          if (*(int *)(unaff_EBP + -0x36c) != 0) {
            pvVar9 = operator_new(100);
            *(void **)(unaff_EBP + -0x114) = pvVar9;
            *(undefined1 *)(unaff_EBP + -4) = 0x18;
            if (pvVar9 == (void *)0x0) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = (int *)FUN_005dfb13();
            }
            iVar8 = *piVar6;
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            (**(code **)(iVar8 + 0xb8))(*(undefined4 *)(unaff_EBP + -0x10));
            if (piVar6 != (int *)0x0) {
              FUN_00523b25(piVar6,0);
            }
            piVar6 = *(int **)(unaff_EBP + -0x24);
          }
          uVar5 = FUN_004705f2(9,0xffffffff);
          FUN_005d4bbf(uVar5);
          uVar5 = FUN_004096c2();
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_00523771(unaff_EBP + -0x70);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          if (*(char *)(unaff_EBP + -0x370) != '\0') {
            (**(code **)(*piVar6 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x328));
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            iVar8 = 0;
            piVar11 = piVar6 + 0x53;
            do {
              if ((*piVar11 != 0) && (*(int *)(*piVar11 + 0x1d8) == *(int *)(unaff_EBP + -0x328))) {
                iVar8 = piVar6[iVar8 + 0x53];
                goto LAB_00553be0;
              }
              iVar8 = iVar8 + 1;
              piVar11 = piVar11 + 1;
            } while (iVar8 < 9);
            iVar8 = *(int *)(unaff_EBP + -0x10);
LAB_00553be0:
            FUN_00523724(2,iVar8 + 0xc);
          }
          uVar5 = FUN_004f6c41(iVar7,1,0);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          if (*(char *)(unaff_EBP + -0x370) != '\0') {
            (**(code **)(*piVar6 + 0x19c))(0);
          }
          FUN_005da4c7(iVar7);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8770();
          if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_00553ebf;
        }
        iVar7 = *(int *)(unaff_EBP + -0x28);
        iVar8 = FUN_00425ddf(iVar7);
        if ((iVar8 == 0) || (iVar8 = FUN_00425ddf(iVar7), *(int *)(iVar8 + 0x13c) == 0)) {
          if (*(int *)(unaff_EBP + -0x10) == 1) {
            uVar5 = FUN_0042ba25(iVar7);
            FUN_0042ba55(iVar7,1);
            cVar2 = FUN_004e2d6b(unaff_EBP + -0x480,unaff_EBP + -200);
            if (cVar2 == '\0') {
              FUN_0042ba55(iVar7,uVar5);
              FUN_004f6994(s_Couldn_t_import_the_family_006cdd88,s_Error_006cbdc4,0,0);
            }
            else if (iVar7 != 0) {
              *(undefined1 *)(unaff_EBP + -0x11) = 1;
            }
          }
          else if (*(int *)(unaff_EBP + -0x10) == 2) {
            FUN_005d4956(s_Confirm_File_Delete_006cda9c);
            *(undefined1 *)(unaff_EBP + -4) = 0x1d;
            FUN_005d4956(s_Are_you_sure_you_want_to_delete_t_006cda70);
            *(undefined1 *)(unaff_EBP + -4) = 0x1e;
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x274) = &PTR_FUN_0066643c;
            *(undefined1 *)(unaff_EBP + -4) = 0x1f;
            uVar5 = FUN_0041532c(9,unaff_EBP + -0x274,0);
            cVar2 = FUN_004fff98(0x9a,uVar5);
            if (cVar2 != '\0') {
              uVar5 = FUN_004705f2(0x12,0xffffffff);
              FUN_005d4bbf(uVar5);
              uVar5 = FUN_004705f2(0x13,0xffffffff);
              FUN_005d4bbf(uVar5);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0x1e;
            FUN_00470467();
            iVar7 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                              (unaff_EBP + -0x7c,unaff_EBP + -0x88,2,0);
            if (iVar7 == 4) {
              uVar5 = *(undefined4 *)(unaff_EBP + -0x47c);
              FUN_005b8e25(uVar5);
              FUN_005b9796(uVar5);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0x1d;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005b8770();
          }
        }
        else {
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x2e0) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_005d4956(&DAT_006de560);
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          FUN_005d4956(&DAT_006de560);
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          uVar5 = FUN_0041532c(9,unaff_EBP + -0x2e0,0);
          cVar2 = FUN_004fff98(0x83,uVar5);
          if (cVar2 != '\0') {
            uVar5 = FUN_004705f2(0x16,0xffffffff);
            FUN_005d4bbf(uVar5);
            uVar5 = FUN_004705f2(0x17,0xffffffff);
            FUN_005d4bbf(uVar5);
          }
          (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                    (unaff_EBP + -0xa0,unaff_EBP + -0xac,0,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_00470467();
        }
        goto LAB_00553ebf;
      }
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x208) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar5 = FUN_0041532c(9,unaff_EBP + -0x208,0);
      cVar2 = FUN_004fff98(0x9a,uVar5);
      if (cVar2 != '\0') {
        pvVar9 = operator_new(0x148);
        *(void **)(unaff_EBP + -0x10) = pvVar9;
        *(undefined1 *)(unaff_EBP + -4) = 9;
        if (pvVar9 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_00523434();
        }
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (iVar7 != 0) {
          uVar5 = FUN_004705f2(0x14,0xffffffff);
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_00523be3(unaff_EBP + -0xb8);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          uVar5 = FUN_004705f2(0x15,0xffffffff);
          FUN_005d4956(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_00523be3(unaff_EBP + -0xd4);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          uVar12 = 1;
          uVar5 = FUN_005e50fa(1,1);
          FUN_0052386b(uVar5,uVar12);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x558) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar5 = FUN_0041532c(9,unaff_EBP + -0x558,0);
          cVar2 = FUN_004fff98(0x90,uVar5);
          if (cVar2 != '\0') {
            uVar5 = FUN_004705f2(5,0xffffffff);
            FUN_005d4956(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_0052386b(unaff_EBP + -300,2);
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            FUN_005b8770();
          }
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_00470467();
          iVar8 = FUN_004f6c41(iVar7,1,0);
          if (iVar8 == 2) {
            uVar5 = FUN_004705f2(0x12,0xffffffff);
            FUN_005d4956(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            uVar5 = FUN_004705f2(0x13,0xffffffff);
            FUN_005d4956(uVar5);
            piVar6 = (int *)(DAT_006f2a08 + 0x48);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            iVar8 = (**(code **)(*piVar6 + 0x2c))(unaff_EBP + -0x110,unaff_EBP + -0xf8,2,0);
            if (iVar8 == 4) {
              uVar5 = *(undefined4 *)(unaff_EBP + -0x47c);
              FUN_005b8e25(uVar5);
              FUN_005b9796(uVar5);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_005b8770();
          }
          FUN_005da4c7(iVar7);
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_00470467();
    }
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004e2e81();
    cVar2 = FUN_005532d4(unaff_EBP + -0x19c,unaff_EBP + -0x94,unaff_EBP + -100);
  } while( true );
}

