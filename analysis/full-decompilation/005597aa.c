
void FUN_005597aa(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  char *pcVar4;
  size_t sVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  undefined4 extraout_ECX;
  int iVar11;
  int unaff_EBP;
  undefined4 uVar12;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  FUN_005b870f(s__family_006c28b4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b870f(&DAT_006c28ac);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined1 *)(unaff_EBP + -0x19) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004f2baf(unaff_EBP + -0x70);
  pcVar4 = (char *)FUN_0041532c(0x58);
  sVar5 = _strlen(pcVar4);
  FUN_00412d8a(pcVar4,pcVar4 + sVar5);
  FUN_005d8277(unaff_EBP + -0x70,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar6 = FUN_005d4956(s___FAM_006c28a4);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d8ab4(uVar6,1);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  FUN_0054dee4();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  cVar2 = FUN_00559739(unaff_EBP + -0x1a4,unaff_EBP + -0x88,unaff_EBP + -100);
  do {
    if (cVar2 == '\0') {
      bVar3 = FUN_0055a430();
      *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | bVar3;
      bVar3 = FUN_0055ac3e();
      *(byte *)(unaff_EBP + -0xd) = *(byte *)(unaff_EBP + -0xd) | bVar3;
      if (*(char *)(unaff_EBP + -0x19) != '\0') {
        FUN_004fc1e5();
      }
      if (*(char *)(unaff_EBP + -0xd) != '\0') {
        FUN_004f5aa0(1);
      }
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
      return;
    }
    uVar6 = FUN_004096c2();
    FUN_0046f824(unaff_EBP + -0x664,0,0x104);
    *(undefined ***)(unaff_EBP + -0x670) = &PTR_FUN_006664e8;
    FUN_0046f847(uVar6,0xffffffff);
    FUN_004e2e34();
    *(undefined1 *)(unaff_EBP + -4) = 7;
    cVar2 = FUN_004e2b6b(unaff_EBP + -0x670,unaff_EBP + -0x488,1);
    if (cVar2 == '\0') {
LAB_0055a360:
      FUN_005d82fa();
    }
    else {
      piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
      piVar7 = (int *)(**(code **)(*piVar7 + 0x58))(0);
      uVar6 = (**(code **)(*piVar7 + 0x78))((int)*(char *)(DAT_006e486c + 100));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
      iVar8 = (**(code **)(*piVar7 + 0x78))((int)*(char *)(unaff_EBP + -0x2f8));
      if ((*(char *)(unaff_EBP + -0x378) == '\0') || (*(int *)(unaff_EBP + -0x360) == 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((*(int *)(unaff_EBP + -0x14) == iVar8) || (bVar1)) {
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        if (*(char *)(unaff_EBP + -0x378) != '\0') {
          *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x330);
        }
        *(undefined4 *)(unaff_EBP + -0x18) = 1;
        if ((*(char *)(unaff_EBP + -0x378) == '\0') || (*(int *)(unaff_EBP + -0x360) == 0)) {
          pvVar9 = operator_new(0x148);
          *(void **)(unaff_EBP + -0x14) = pvVar9;
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          if (pvVar9 == (void *)0x0) {
            iVar8 = 0;
          }
          else {
            iVar8 = FUN_00523434();
          }
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8680();
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          uVar6 = FUN_004705f2(1,0xffffffff);
          FUN_005d4bbf(uVar6);
          iVar10 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x3c),0,
                                *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c));
          if (iVar10 != -1) {
            FUN_00455790(iVar10,*(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c),
                         unaff_EBP + -0x34c);
          }
          uVar6 = FUN_004096c2();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0x12;
          FUN_00523be3(unaff_EBP + -0x128);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_005d4bbf(&DAT_006de560);
          if (*(int *)(unaff_EBP + -0x20) == 0) {
            pcVar4 = (char *)FUN_004705f2(2,0xffffffff);
            *(char **)(unaff_EBP + -0x18) = pcVar4;
            sVar5 = _strlen(pcVar4);
            FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),sVar5 + *(int *)(unaff_EBP + -0x18));
          }
          else {
            iVar10 = FUN_0055c216(*(undefined4 *)(unaff_EBP + -0x20));
            *(int *)(unaff_EBP + -0x14) = iVar10;
            if (iVar10 != 0) {
              FUN_0046f824(unaff_EBP + -0x154,0,0x20);
              *(undefined ***)(unaff_EBP + -0x160) = &PTR_FUN_006666e4;
              FUN_0046fa40(*(undefined4 *)(unaff_EBP + -0x20));
              if (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x24) == -1) {
                if (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x18) == 0) {
                  pcVar4 = (char *)FUN_004705f2(4,0xffffffff);
                  *(char **)(unaff_EBP + -0x14) = pcVar4;
                  sVar5 = _strlen(pcVar4);
                  iVar10 = sVar5 + *(int *)(unaff_EBP + -0x14);
                  uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
                }
                else {
                  pcVar4 = (char *)FUN_004705f2(5,0xffffffff);
                  *(char **)(unaff_EBP + -0x14) = pcVar4;
                  sVar5 = _strlen(pcVar4);
                  iVar10 = sVar5 + *(int *)(unaff_EBP + -0x14);
                  uVar6 = *(undefined4 *)(unaff_EBP + -0x14);
                }
                FUN_00412d8a(uVar6,iVar10);
              }
              else {
                pcVar4 = (char *)FUN_004705f2(3,0xffffffff);
                *(char **)(unaff_EBP + -0x18) = pcVar4;
                sVar5 = _strlen(pcVar4);
                FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x18),sVar5 + *(int *)(unaff_EBP + -0x18))
                ;
                iVar10 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x3c),0,
                                      *(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c));
                if (iVar10 != -1) {
                  FUN_00455790(iVar10,*(int *)(unaff_EBP + -0x38) - *(int *)(unaff_EBP + -0x3c),
                               *(int *)(unaff_EBP + -0x14) + 0x28);
                }
              }
              iVar10 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x4c),0,
                                    *(int *)(unaff_EBP + -0x48) - *(int *)(unaff_EBP + -0x4c));
              if (iVar10 != -1) {
                FUN_00455800(iVar10,*(int *)(unaff_EBP + -0x48) - *(int *)(unaff_EBP + -0x4c),
                             *(undefined4 *)(unaff_EBP + -0x15c));
              }
            }
          }
          uVar6 = FUN_004096c2();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0x13;
          FUN_00523be3(unaff_EBP + -0xe8);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          uVar6 = FUN_004705f2(7,0xffffffff);
          FUN_005d4bbf(uVar6);
          uVar6 = FUN_004096c2();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0x14;
          FUN_0052386b(unaff_EBP + -0xc4,1);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_00523afc(1,0xd);
          uVar6 = FUN_004705f2(8,0xffffffff);
          FUN_005d4bbf(uVar6);
          uVar6 = FUN_004096c2();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0x15;
          FUN_0052386b(unaff_EBP + -0x104,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          FUN_00523afc(0,0x1b);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x4f4) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x16;
          uVar6 = FUN_0041532c(9,unaff_EBP + -0x4f4,0);
          cVar2 = FUN_004fff98(0x90,uVar6);
          if (cVar2 != '\0') {
            uVar6 = FUN_004705f2(5,0xffffffff);
            FUN_005d4956(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            FUN_0052386b(unaff_EBP + -0x11c,2);
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            FUN_005b8770();
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_00470467();
          (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
                    (unaff_EBP + -0x58,unaff_EBP + -0x54,unaff_EBP + -0x50);
          uVar6 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x58),*(undefined4 *)(unaff_EBP + -0x54)
                               ,*(undefined4 *)(unaff_EBP + -0x50));
          *(undefined4 *)(iVar8 + 100) = uVar6;
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x374);
          if (*(int *)(unaff_EBP + -0x374) != 0) {
            pvVar9 = operator_new(100);
            *(void **)(unaff_EBP + -0x18) = pvVar9;
            *(undefined1 *)(unaff_EBP + -4) = 0x18;
            if (pvVar9 == (void *)0x0) {
              *(undefined4 *)(unaff_EBP + -0x18) = 0;
            }
            else {
              uVar6 = FUN_005dfb13();
              *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
            }
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0xb8))(*(undefined4 *)(unaff_EBP + -0x14));
            if (*(int *)(unaff_EBP + -0x18) != 0) {
              FUN_00523b25(*(undefined4 *)(unaff_EBP + -0x18),0);
            }
          }
          uVar6 = FUN_004705f2(9,0xffffffff);
          FUN_005d4bbf(uVar6);
          uVar6 = FUN_004096c2();
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_00523771(unaff_EBP + -0x7c);
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          FUN_005b8770();
          if (*(char *)(unaff_EBP + -0x378) != '\0') {
            (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x19c))
                      (*(undefined4 *)(unaff_EBP + -0x330));
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            iVar10 = *(int *)(*(int *)(unaff_EBP + -0x24) + 0x148);
            iVar11 = *(int *)(iVar10 + 8);
            *(int *)(unaff_EBP + -0x40) = iVar11;
            while (iVar11 != iVar10) {
              if (*(int *)(*(int *)(iVar11 + 0x14) + 0x1d8) == *(int *)(unaff_EBP + -0x330)) {
                *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar11 + 0x14);
                break;
              }
              FUN_0041674f();
              iVar10 = *(int *)(*(int *)(unaff_EBP + -0x24) + 0x148);
              iVar11 = *(int *)(unaff_EBP + -0x40);
            }
            FUN_00523724(2,*(int *)(unaff_EBP + -0x14) + 0xc);
          }
          uVar6 = FUN_004f6c41(iVar8,1,0);
          *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
          if (*(char *)(unaff_EBP + -0x378) != '\0') {
            (**(code **)(**(int **)(unaff_EBP + -0x24) + 0x19c))(0);
          }
          FUN_005da4c7(iVar8);
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_005b8770();
          if (*(int *)(unaff_EBP + -0x18) == 0) goto LAB_0055a360;
        }
        iVar8 = FUN_00425ddf(*(undefined4 *)(unaff_EBP + -0x20));
        if ((iVar8 == 0) ||
           (iVar8 = FUN_00425ddf(*(undefined4 *)(unaff_EBP + -0x20)), *(int *)(iVar8 + 0x13c) == 0))
        {
          if (*(int *)(unaff_EBP + -0x18) == 1) {
            uVar6 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + -0x20));
            FUN_0042ba55(*(undefined4 *)(unaff_EBP + -0x20),1);
            cVar2 = FUN_004e2d6b(unaff_EBP + -0x488,unaff_EBP + -0xec);
            if (cVar2 == '\0') {
              FUN_0042ba55(*(undefined4 *)(unaff_EBP + -0x20),uVar6);
              FUN_004f6994(s_Couldn_t_import_the_family_006cdd88,s_Error_006cbdc4,0,0);
            }
            else {
              *(undefined1 *)(unaff_EBP + -0x19) = 1;
              if (*(int *)(unaff_EBP + -0x20) != 0) {
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
              }
            }
          }
          else if (*(int *)(unaff_EBP + -0x18) == 2) {
            FUN_005d4956(s_Confirm_File_Delete_006cda9c);
            *(undefined1 *)(unaff_EBP + -4) = 0x1d;
            FUN_005d4956(s_Are_you_sure_you_want_to_delete_t_006cda70);
            *(undefined1 *)(unaff_EBP + -4) = 0x1e;
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x27c) = &PTR_FUN_0066643c;
            *(undefined1 *)(unaff_EBP + -4) = 0x1f;
            uVar6 = FUN_0041532c(9,unaff_EBP + -0x27c,0);
            cVar2 = FUN_004fff98(0x9a,uVar6);
            if (cVar2 != '\0') {
              uVar6 = FUN_004705f2(0x12,0xffffffff);
              FUN_005d4bbf(uVar6);
              uVar6 = FUN_004705f2(0x13,0xffffffff);
              FUN_005d4bbf(uVar6);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0x1e;
            FUN_00470467();
            iVar8 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                              (unaff_EBP + -0x94,unaff_EBP + -0xa0,2,0);
            if (iVar8 == 4) {
              uVar6 = *(undefined4 *)(unaff_EBP + -0x484);
              FUN_005b8e25(uVar6);
              FUN_005b9796(uVar6);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0x1d;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 7;
            FUN_005b8770();
          }
        }
        else {
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x2e8) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_005d4956(&DAT_006de560);
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          FUN_005d4956(&DAT_006de560);
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          uVar6 = FUN_0041532c(9,unaff_EBP + -0x2e8,0);
          cVar2 = FUN_004fff98(0x83,uVar6);
          if (cVar2 != '\0') {
            uVar6 = FUN_004705f2(0x16,0xffffffff);
            FUN_005d4bbf(uVar6);
            uVar6 = FUN_004705f2(0x17,0xffffffff);
            FUN_005d4bbf(uVar6);
          }
          (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                    (unaff_EBP + -0xac,unaff_EBP + -0xb8,0,0);
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 7;
          FUN_00470467();
        }
        goto LAB_0055a360;
      }
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x210) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar6 = FUN_0041532c(9,unaff_EBP + -0x210,0);
      cVar2 = FUN_004fff98(0x9a,uVar6);
      if (cVar2 != '\0') {
        pvVar9 = operator_new(0x148);
        *(void **)(unaff_EBP + -0x14) = pvVar9;
        *(undefined1 *)(unaff_EBP + -4) = 9;
        if (pvVar9 == (void *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar8 = FUN_00523434();
        }
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (iVar8 != 0) {
          uVar6 = FUN_004705f2(0x14,0xffffffff);
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          FUN_00523be3(unaff_EBP + -0xd0);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          uVar6 = FUN_004705f2(0x15,0xffffffff);
          FUN_005d4956(uVar6);
          *(undefined1 *)(unaff_EBP + -4) = 0xb;
          FUN_00523be3(unaff_EBP + -0xdc);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_005b8770();
          uVar12 = 1;
          uVar6 = FUN_005e50fa(1,1);
          FUN_0052386b(uVar6,uVar12);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x560) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar6 = FUN_0041532c(9,unaff_EBP + -0x560,0);
          cVar2 = FUN_004fff98(0x90,uVar6);
          if (cVar2 != '\0') {
            uVar6 = FUN_004705f2(5,0xffffffff);
            FUN_005d4956(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            FUN_0052386b(unaff_EBP + -0x134,2);
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            FUN_005b8770();
          }
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_00470467();
          iVar10 = FUN_004f6c41(iVar8,1,0);
          if (iVar10 == 2) {
            uVar6 = FUN_004705f2(0x12,0xffffffff);
            FUN_005d4956(uVar6);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            uVar6 = FUN_004705f2(0x13,0xffffffff);
            FUN_005d4956(uVar6);
            piVar7 = (int *)(DAT_006f2a08 + 0x48);
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            iVar10 = (**(code **)(*piVar7 + 0x2c))(unaff_EBP + -0x110,unaff_EBP + -0xf8,2,0);
            if (iVar10 == 4) {
              uVar6 = *(undefined4 *)(unaff_EBP + -0x484);
              FUN_005b8e25(uVar6);
              FUN_005b9796(uVar6);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 8;
            FUN_005b8770();
          }
          FUN_005da4c7(iVar8);
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_00470467();
    }
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_004e2e81();
    cVar2 = FUN_00559739(unaff_EBP + -0x1a4,unaff_EBP + -0x88,unaff_EBP + -100);
  } while( true );
}

