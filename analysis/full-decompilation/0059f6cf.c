
undefined4 FUN_0059f6cf(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar8;
  undefined4 uVar9;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_005c1033();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c22bb();
  FUN_005c1940(unaff_EBP + -0x78,*(undefined4 *)(unaff_EBP + 8),&DAT_006f765c);
  FUN_005c11b1();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar3 = FUN_005c1171(unaff_EBP + -0x50);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c11bb(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042004f();
  uVar3 = FUN_005c1186(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar2 = FUN_005c11f5(uVar3);
  *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042004f();
  cVar1 = *(char *)(unaff_EBP + -0xd);
  do {
    if (cVar1 == '\0') {
      if (*(char *)(unaff_EBP + 0xc) != '\0') {
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
        *(undefined1 *)(unaff_EBP + -4) = 0xc;
        FUN_00580a92(unaff_EBP + -0x24);
        while (iVar4 = *(int *)(unaff_EBP + -0x24), iVar4 != 0) {
          if (*(char *)(iVar4 + 0x30) == '\0') {
            FUN_005a3698();
          }
          *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar4 + 0x34);
          FUN_005a1eac(unaff_EBP + 8);
          FUN_0058757c();
        }
        FUN_00580a92(unaff_EBP + -0x5c);
        while (iVar4 = *(int *)(unaff_EBP + -0x5c), iVar4 != 0) {
          if (*(char *)(iVar4 + 0x30) == '\0') {
            FUN_005a3762();
          }
          *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar4 + 0x34);
          FUN_005a1ed3(unaff_EBP + 8);
          FUN_0040fe8a();
        }
        FUN_00580a92(unaff_EBP + -0x50);
        while (iVar4 = *(int *)(unaff_EBP + -0x50), iVar4 != 0) {
          if (*(char *)(iVar4 + 0x30) == '\0') {
            FUN_005a385a();
          }
          *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar4 + 0x34);
          FUN_005a1efa(unaff_EBP + 8);
          FUN_0058757c();
        }
        FUN_0059fee5(*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x10),
                     unaff_EBP + -0x3c,unaff_EBP + -0x48,unaff_EBP + -0x30);
        *(undefined1 *)(unaff_EBP + -4) = 0xb;
        FUN_0048c4c9();
        *(undefined1 *)(unaff_EBP + -4) = 10;
        FUN_0048c4c9();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0048c4c9();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005c1070();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return 0;
    }
    FUN_005c1209();
    FUN_004ceb79();
    iVar4 = FUN_004096c2();
    iVar5 = FUN_004096c2();
    if (iVar4 == iVar5) {
      uVar3 = FUN_00401f77();
      FUN_00476033(1);
      FUN_005c32ce();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005c1d4c(unaff_EBP + -0xb8,unaff_EBP + -0x18);
      FUN_00476033(uVar3);
      FUN_005c1209();
      uVar3 = FUN_00401f77();
      FUN_00635858(unaff_EBP + -0x4b8,s__s_cmx_006d1db8,uVar3);
      FUN_005b870f(unaff_EBP + -0x4b8);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005c1209();
      uVar3 = FUN_004096c2();
      FUN_005b870f(uVar3);
      uVar8 = 0;
      uVar3 = *(undefined4 *)(unaff_EBP + 0x14);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      uVar7 = *(undefined4 *)(unaff_EBP + 0xc);
      uVar9 = *(undefined4 *)(unaff_EBP + 8);
      uVar6 = FUN_00401f73(uVar9,uVar7,uVar3,0);
      FUN_0059e5d1(unaff_EBP + -0x3c,unaff_EBP + -0x48,uVar6,uVar9,uVar7,uVar3,uVar8);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
LAB_0059f94a:
      FUN_005c3314();
    }
    else {
      iVar5 = FUN_004096c2();
      if (iVar4 == iVar5) {
        FUN_005c32ce();
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_0047354f(1);
        FUN_005c1d4c(unaff_EBP + -0x98,unaff_EBP + -0x18);
        FUN_005c1209();
        uVar3 = FUN_00401f77();
        FUN_00635858(unaff_EBP + -0x4b8,s__s_bcf_006d1db0,uVar3);
        FUN_005b870f(unaff_EBP + -0x4b8);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005c1209();
        uVar3 = FUN_004096c2();
        FUN_005b870f(uVar3);
        uVar9 = 0;
        uVar3 = *(undefined4 *)(unaff_EBP + 8);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        uVar7 = FUN_00401f73(uVar3,0);
        FUN_0059ef12(unaff_EBP + -0x30,unaff_EBP + -0x54,uVar7,uVar3,uVar9);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 1;
        goto LAB_0059f94a;
      }
    }
    FUN_005c11ce();
    uVar3 = FUN_005c1186(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar2 = FUN_005c11f5(uVar3);
    *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    cVar1 = *(char *)(unaff_EBP + -0xd);
  } while( true );
}

