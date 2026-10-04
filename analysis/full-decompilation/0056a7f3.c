
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0056a7f3(void)

{
  char cVar1;
  char *pcVar2;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int *piVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004f2baf(unaff_EBP + -0x5c);
  pcVar2 = (char *)FUN_0041532c(0x58);
  sVar3 = _strlen(pcVar2);
  FUN_00412d8a(pcVar2,pcVar2 + sVar3);
  FUN_005d8277(unaff_EBP + -0x5c,0,0,0);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar4 = FUN_005d4956("*.vil");
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d8ab4(uVar4,1);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  FUN_0054dee4();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  cVar1 = FUN_0056a782(unaff_EBP + -0x1c0,unaff_EBP + -0xa4,unaff_EBP + -0x50);
  if (cVar1 != '\0') {
    do {
      uVar4 = FUN_004096c2();
      FUN_0046f824(unaff_EBP + -0x54c,0,0x104);
      *(undefined ***)(unaff_EBP + -0x558) = &PTR_FUN_006664e8;
      FUN_0046f847(uVar4,0xffffffff);
      FUN_00418fea();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x298) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005d48d9();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      iVar5 = FUN_004190d3(unaff_EBP + -0x558,0);
      if (iVar5 == 0) {
        iVar5 = FUN_00470383(unaff_EBP + -0x150,2000,1);
        if (iVar5 == 0) {
          uVar4 = FUN_004705f2(1,0xffffffff);
          FUN_005d4bbf(uVar4);
          uVar4 = FUN_004705f2(2,0xffffffff);
          FUN_005d4bbf(uVar4);
          uVar4 = FUN_004705f2(3,0xffffffff);
          FUN_005d4bbf(uVar4);
        }
        FUN_004195ba();
      }
      uVar4 = FUN_004096c2();
      uVar4 = FUN_00635f62(uVar4);
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar4;
      pvVar6 = operator_new(0x148);
      *(void **)(unaff_EBP + -0x10) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 10;
      if (pvVar6 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00523434();
      }
      *(undefined1 *)(unaff_EBP + -4) = 9;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      FUN_00401aae(8);
      *(undefined1 *)(unaff_EBP + -4) = 0xb;
      FUN_00401a79();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      *(char **)(unaff_EBP + -0x10) = *(char **)(unaff_EBP + -0x74);
      sVar3 = _strlen(*(char **)(unaff_EBP + -0x74));
      FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar3 + *(int *)(unaff_EBP + -0x10));
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 0xd;
      FUN_00523be3(unaff_EBP + -200);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      *(char **)(unaff_EBP + -0x10) = *(char **)(unaff_EBP + -0x44);
      sVar3 = _strlen(*(char **)(unaff_EBP + -0x44));
      FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar3 + *(int *)(unaff_EBP + -0x10));
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 0xe;
      FUN_00523be3(unaff_EBP + -0xd4);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      pcVar2 = (char *)FUN_004705f2(7,0xffffffff);
      *(char **)(unaff_EBP + -0x10) = pcVar2;
      sVar3 = _strlen(pcVar2);
      FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar3 + *(int *)(unaff_EBP + -0x10));
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 0xf;
      FUN_0052386b(unaff_EBP + -0xf8,1);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      FUN_00523afc(1,0xd);
      pcVar2 = (char *)FUN_004705f2(8,0xffffffff);
      *(char **)(unaff_EBP + -0x10) = pcVar2;
      sVar3 = _strlen(pcVar2);
      FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar3 + *(int *)(unaff_EBP + -0x10));
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 0x10;
      FUN_0052386b(unaff_EBP + -0xec,0);
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_005b8770();
      FUN_00523afc(0,0x1b);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x448) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0x11;
      uVar4 = FUN_0041532c(9,unaff_EBP + -0x448,0);
      cVar1 = FUN_004fff98(0x90,uVar4);
      if (cVar1 != '\0') {
        uVar4 = FUN_004705f2(5,0xffffffff);
        FUN_005d4956(uVar4);
        *(undefined1 *)(unaff_EBP + -4) = 0x12;
        FUN_0052386b(unaff_EBP + -0xe0,2);
        *(undefined1 *)(unaff_EBP + -4) = 0x11;
        FUN_005b8770();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_00470467();
      (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x1c))
                (unaff_EBP + -0x30,unaff_EBP + -0x34,unaff_EBP + -0x38);
      uVar4 = FUN_005dd5e1(*(undefined4 *)(unaff_EBP + -0x30),*(undefined4 *)(unaff_EBP + -0x34),
                           *(undefined4 *)(unaff_EBP + -0x38));
      *(undefined4 *)(iVar5 + 100) = uVar4;
      FUN_00418fea();
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_004190d3(unaff_EBP + -0x558,0);
      FUN_005a55f6(unaff_EBP + -0x124,0x200,unaff_EBP + -0x2c,4);
      FUN_004195ba();
      if (*(int **)(unaff_EBP + -0x2c) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_EBP + -0x2c) + 0x68))(DAT_006f2a64);
        FUN_00523b25(*(undefined4 *)(unaff_EBP + -0x2c),0);
      }
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x3dc) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      uVar4 = FUN_0041532c(9,unaff_EBP + -0x3dc,0);
      cVar1 = FUN_004fff98(0xa9,uVar4);
      if (cVar1 != '\0') {
        pcVar2 = (char *)FUN_004705f2(4,0xffffffff);
        *(char **)(unaff_EBP + -0x10) = pcVar2;
        sVar3 = _strlen(pcVar2);
        FUN_00431779(*(undefined4 *)(unaff_EBP + -0x10),sVar3 + *(int *)(unaff_EBP + -0x10));
      }
      FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x28));
      *(undefined1 *)(unaff_EBP + -4) = 0x15;
      FUN_00523771(unaff_EBP + -0x68);
      *(undefined1 *)(unaff_EBP + -4) = 0x14;
      FUN_005b8770();
      FUN_0056badf(*(undefined4 *)(unaff_EBP + -0x1c));
      iVar7 = *(int *)(unaff_EBP + -0x1c) + -0x27;
      switch(*(int *)(unaff_EBP + -0x1c)) {
      case 0x28:
        iVar7 = 3;
        break;
      case 0x29:
        iVar7 = 2;
        break;
      case 0x2a:
        iVar7 = 1;
        break;
      case 0x2b:
        iVar7 = 7;
        break;
      case 0x2c:
        iVar7 = 6;
        break;
      case 0x2d:
        iVar7 = 5;
        break;
      case 0x2e:
        iVar7 = 4;
        break;
      case 0x2f:
        iVar7 = 9;
        break;
      case 0x30:
        iVar7 = 8;
        break;
      case 0x31:
        iVar7 = 10;
      }
      FUN_00523724(2,*(int *)(*(int *)(unaff_EBP + -0x18) + 0x150 + iVar7 * 4) + 0xc);
      uVar4 = FUN_004f6c41(iVar5,1,0);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      FUN_005da4c7(iVar5);
      *(undefined1 *)(unaff_EBP + -4) = 0x13;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      FUN_0041905d();
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_00401729();
      if (*(int *)(unaff_EBP + -0x10) != 0) {
        FUN_00425e2d();
        puVar8 = (undefined4 *)FUN_00425e2d();
        for (piVar9 = (int *)*puVar8; iVar5 = FUN_00425e2d(), piVar9 != *(int **)(iVar5 + 4);
            piVar9 = piVar9 + 1) {
          if (*(int *)(*piVar9 + 0x13c) == *(int *)(unaff_EBP + -0x1c)) {
            FUN_0046fca5();
            *(undefined ***)(unaff_EBP + -0x304) = &PTR_FUN_0066643c;
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            FUN_005d4956(&DAT_006de560);
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            FUN_005d4956(&DAT_006de560);
            *(undefined1 *)(unaff_EBP + -4) = 0x18;
            uVar4 = FUN_0041532c(9,unaff_EBP + -0x304,0);
            cVar1 = FUN_004fff98(0x83,uVar4);
            if (cVar1 != '\0') {
              uVar4 = FUN_004705f2(0x16,0xffffffff);
              FUN_005d4bbf(uVar4);
              uVar4 = FUN_004705f2(0x17,0xffffffff);
              FUN_005d4bbf(uVar4);
            }
            (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                      (unaff_EBP + -0xbc,unaff_EBP + -0x80,0,0);
            *(undefined1 *)(unaff_EBP + -4) = 0x17;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 0x16;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_00470467();
            goto LAB_0056b1a2;
          }
        }
        if (*(int *)(unaff_EBP + -0x10) == 1) {
          *(undefined1 *)(unaff_EBP + -0x11) = 1;
          FUN_00418fea();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0046f824(unaff_EBP + -0x65c,0,0x104);
          *(undefined ***)(unaff_EBP + -0x668) = &PTR_FUN_006664e8;
          FUN_00425691(*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0x668);
          FUN_0041c785(unaff_EBP + -0x668);
          uVar4 = *(undefined4 *)(unaff_EBP + -0x664);
          uVar10 = *(undefined4 *)(unaff_EBP + -0x554);
          FUN_005b8e25(uVar10,uVar4);
          FUN_005b9976(uVar10,uVar4);
          FUN_0041c785(unaff_EBP + -0x558);
          FUN_0046f824(unaff_EBP + -0x76c,0,0x104);
          *(undefined ***)(unaff_EBP + -0x778) = &PTR_FUN_006664e8;
          FUN_00425531(unaff_EBP + -0x778);
          FUN_0046f847(s_Houses_VIDesc_iff_006c26a8,0xffffffff);
          FUN_0046f5cd();
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          iVar5 = FUN_0046f71c(unaff_EBP + -0x778,1);
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x22c) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x1b;
          if (iVar5 == 0) {
            iVar5 = FUN_00470383(unaff_EBP + -0x9bc,*(int *)(unaff_EBP + -0x1c) + 2000,1);
            if (iVar5 == 0) {
              uVar10 = 0xffffffff;
              uVar4 = FUN_004096c2(0xffffffff);
              FUN_004704a5(1,uVar4,uVar10);
              uVar10 = 0xffffffff;
              uVar4 = FUN_004096c2(0xffffffff);
              FUN_004704a5(2,uVar4,uVar10);
              FUN_0046fd72();
            }
            FUN_0046b7ee();
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x1a;
          FUN_00470467();
          *(undefined1 *)(unaff_EBP + -4) = 0x19;
          FUN_0046b2e6();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_0041905d();
        }
        else if (*(int *)(unaff_EBP + -0x10) == 2) {
          FUN_005d4956(s_Confirm_File_Delete_006cda9c);
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          FUN_005d4956(s_Are_you_sure_you_want_to_delete_t_006cda70);
          *(undefined1 *)(unaff_EBP + -4) = 0x1d;
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x370) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 0x1e;
          uVar4 = FUN_0041532c(9,unaff_EBP + -0x370,0);
          cVar1 = FUN_004fff98(0x9a,uVar4);
          if (cVar1 != '\0') {
            uVar4 = FUN_004705f2(0x12,0xffffffff);
            FUN_005d4bbf(uVar4);
            uVar4 = FUN_004705f2(0x13,0xffffffff);
            FUN_005d4bbf(uVar4);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x1d;
          FUN_00470467();
          iVar5 = (**(code **)(*(int *)(DAT_006f2a08 + 0x48) + 0x2c))
                            (unaff_EBP + -0x98,unaff_EBP + -0xb0,2,0);
          if (iVar5 == 4) {
            uVar4 = *(undefined4 *)(unaff_EBP + -0x554);
            FUN_005b8e25(uVar4);
            FUN_005b9796(uVar4);
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x1c;
          FUN_005b8770();
          *(undefined1 *)(unaff_EBP + -4) = 9;
          FUN_005b8770();
        }
      }
LAB_0056b1a2:
      FUN_005d82fa();
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0041905d();
      cVar1 = FUN_0056a782(unaff_EBP + -0x1c0,unaff_EBP + -0xa4,unaff_EBP + -0x50);
    } while (cVar1 != '\0');
    if (*(char *)(unaff_EBP + -0x11) != '\0') {
      FUN_004f5b34(1);
    }
  }
  FUN_0056b9c4();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042ecc0();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042a889();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

