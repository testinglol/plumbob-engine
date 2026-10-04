
undefined1 FUN_00403d7c(void)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  short *psVar3;
  char cVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  undefined1 uVar10;
  int unaff_EBP;
  int iVar11;
  
  FUN_00634c24();
  iVar11 = 0;
  FUN_0046f824(unaff_EBP + -0x7e8,0,0x104);
  *(undefined ***)(unaff_EBP + -0x7f4) = &PTR_FUN_006664e8;
  uVar6 = FUN_0041532c(0x42,&DAT_006c0c5c,unaff_EBP + -0x7f4);
  FUN_004ee9ce(uVar6);
  FUN_00404c3d();
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar7 = FUN_0046f71c(unaff_EBP + -0x7f4,0);
  if (iVar7 == 0) {
    FUN_00405584(unaff_EBP + -0x7f4);
    uVar6 = FUN_0041532c(0x42,s_Careers_006c0c54,unaff_EBP + -0x904);
    FUN_004ee9ce(uVar6);
    FUN_0046f847(&DAT_006c0a7c,0xffffffff);
    cVar4 = FUN_00403700(unaff_EBP + -0x904);
    if (cVar4 == '\0') {
      sVar5 = FUN_004069f8(0x43415252);
      *(int *)(unaff_EBP + -0x20) = (int)sVar5;
      *(undefined4 *)(unaff_EBP + -0x1c) = 1;
      if (0 < sVar5) {
        do {
          iVar7 = FUN_00406b44(0x43415252,*(undefined4 *)(unaff_EBP + -0x1c),FUN_00465037);
          if (iVar7 == 0) {
LAB_00404029:
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_0046b2e6();
            uVar10 = 0;
            goto LAB_004043a9;
          }
          FUN_00406ca0(iVar7,unaff_EBP + -0x28);
          FUN_00465a06(iVar7);
          pvVar8 = operator_new(0x74);
          *(void **)(unaff_EBP + -0x14) = pvVar8;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          if (pvVar8 == (void *)0x0) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_00403586();
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          uVar1 = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
          FUN_00405ee1(uVar6,0x43415252);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          iVar7 = FUN_00464f5b(unaff_EBP + -0x34,unaff_EBP + -0x6e4,uVar1,0);
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00465055();
          if (iVar7 != 0) goto LAB_00404029;
          **(int **)(unaff_EBP + -0x10) = (int)*(short *)(unaff_EBP + -0x28);
          FUN_004055b8(unaff_EBP + -0x10);
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
        } while (*(int *)(unaff_EBP + -0x1c) <= *(int *)(unaff_EBP + -0x20));
      }
    }
    FUN_00470383(unaff_EBP + -0x6e4,0x1000,0);
    FUN_00470383(unaff_EBP + -0x6e4,0x1001,0);
    iVar7 = DAT_006e486c;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0xb;
    sVar5 = *(short *)(iVar7 + 0x66);
    if (0 < sVar5) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x10;
    }
    if (0x1f < sVar5) {
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 5;
    }
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    if (0 < *(int *)(unaff_EBP + -0x1c)) {
      do {
        if (iVar11 != 10) {
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0xa0) = &PTR_FUN_0066643c;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0x158) = &PTR_FUN_0066643c;
          iVar7 = DAT_006de7f8;
          *(undefined1 *)(unaff_EBP + -4) = 4;
          puVar2 = *(undefined2 **)(iVar7 + iVar11 * 4);
          iVar9 = FUN_00470383(unaff_EBP + -0x6e4,CONCAT22((short)((uint)puVar2 >> 0x10),*puVar2),0)
          ;
          iVar7 = DAT_006de7f8;
          if (iVar9 == 0) {
            *(undefined1 *)(unaff_EBP + -0x15) = 0;
            psVar3 = *(short **)(iVar7 + iVar11 * 4);
            iVar7 = FUN_00470383(unaff_EBP + -0x6e4,
                                 CONCAT22((short)((uint)psVar3 >> 0x10),*psVar3 + 1000),0);
            if (iVar7 != 0) {
              *(undefined1 *)(unaff_EBP + -0x15) = 1;
            }
            uVar6 = FUN_004705f2(1,0xffffffff);
            *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
            FUN_0046f824(unaff_EBP + -0xe0,0,0x40);
            *(undefined ***)(unaff_EBP + -0xec) = &PTR_FUN_0066651c;
            FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
            FUN_0046f8e4(unaff_EBP + -0xec);
            *(int *)(unaff_EBP + -0x10) = DAT_006de7f8 + iVar11 * 4;
            uVar6 = FUN_004705f2(2,0xffffffff);
            FUN_005d4bbf(uVar6);
            *(int *)(unaff_EBP + -0x10) = DAT_006de7f8 + iVar11 * 4;
            uVar6 = FUN_004705f2(3,0xffffffff);
            FUN_005d4bbf(uVar6);
            *(undefined4 *)(unaff_EBP + -0x10) = 0;
            *(undefined4 *)(unaff_EBP + -0x20) = 0x18;
            *(undefined4 *)(unaff_EBP + -0x24) = 4;
            do {
              uVar6 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x24),0xffffffff);
              *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
              FUN_0046f824(unaff_EBP + -0x408,0,0x80);
              *(undefined ***)(unaff_EBP + -0x414) = &PTR_FUN_00666554;
              FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
              FUN_0046f8e4(unaff_EBP + -0x414);
              uVar6 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x20),0xffffffff);
              *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
              FUN_0046f824(unaff_EBP + -0x494,0,0x80);
              *(undefined ***)(unaff_EBP + -0x4a0) = &PTR_FUN_00666554;
              FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
              FUN_0046f8e4(unaff_EBP + -0x4a0);
              if (*(char *)(unaff_EBP + -0x15) == '\0') {
                uVar6 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x24),0xffffffff);
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                FUN_0046f824(unaff_EBP + -0x264,0,0x80);
                *(undefined ***)(unaff_EBP + -0x270) = &PTR_FUN_00666554;
                FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
                FUN_0046f8e4(unaff_EBP + -0x270);
                uVar6 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x20),0xffffffff);
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                FUN_0046f824(unaff_EBP + -0x2f0,0,0x80);
                *(undefined ***)(unaff_EBP + -0x2fc) = &PTR_FUN_00666554;
                FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
                iVar11 = unaff_EBP + -0x2fc;
              }
              else {
                uVar6 = FUN_004705f2(*(int *)(unaff_EBP + -0x24) + 1000,0xffffffff);
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                FUN_0046f824(unaff_EBP + -0x37c,0,0x80);
                *(undefined ***)(unaff_EBP + -0x388) = &PTR_FUN_00666554;
                FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
                FUN_0046f8e4(unaff_EBP + -0x388);
                uVar6 = FUN_004705f2(*(int *)(unaff_EBP + -0x20) + 1000,0xffffffff);
                *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
                FUN_0046f824(unaff_EBP + -0x1d8,0,0x80);
                *(undefined ***)(unaff_EBP + -0x1e4) = &PTR_FUN_00666554;
                FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
                iVar11 = unaff_EBP + -0x1e4;
              }
              FUN_0046f8e4(iVar11);
              uVar6 = FUN_004705f2(*(int *)(unaff_EBP + -0x24) + 1,0xffffffff);
              FUN_005d4bbf(uVar6);
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x3c0;
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
              *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 2;
            } while (*(int *)(unaff_EBP + -0x20) + -0x18 < 10);
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_00470467();
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_00470467();
            iVar11 = *(int *)(unaff_EBP + -0x28);
          }
          else {
            *(undefined1 *)(unaff_EBP + -4) = 3;
            FUN_00470467();
            *(undefined1 *)(unaff_EBP + -4) = 0;
            FUN_00470467();
          }
        }
        iVar11 = iVar11 + 1;
        *(int *)(unaff_EBP + -0x28) = iVar11;
      } while (iVar11 < *(int *)(unaff_EBP + -0x1c));
    }
    uVar10 = 1;
  }
  else {
    uVar10 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
LAB_004043a9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar10;
}

