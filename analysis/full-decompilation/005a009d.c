
undefined4 FUN_005a009d(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005c1033();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c22bb();
  FUN_005c1940(unaff_EBP + -0x44,*(undefined4 *)(unaff_EBP + 8),&DAT_006f7650);
  FUN_005c11b1();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_005c1171(unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c11bb(uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0042004f();
  uVar2 = FUN_005c1186(unaff_EBP + -0x1c);
  while( true ) {
    *(undefined1 *)(unaff_EBP + -4) = 3;
    cVar1 = FUN_005c11f5(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    if (cVar1 == '\0') break;
    FUN_005c1209();
    FUN_004ceb79();
    iVar3 = FUN_004096c2();
    iVar4 = FUN_004096c2();
    if (iVar3 == iVar4) {
      FUN_005c32ce();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0047354f(1);
      FUN_005c1d4c(unaff_EBP + -100,unaff_EBP + -0x14);
      FUN_005c1209();
      uVar2 = FUN_004096c2();
      FUN_005b870f(uVar2);
      uVar2 = *(undefined4 *)(unaff_EBP + 8);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      uVar5 = FUN_00401f73(uVar2);
      FUN_0059fad3(unaff_EBP + -0x28,uVar5,uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005c3314();
    }
    FUN_005c11ce();
    uVar2 = FUN_005c1186(unaff_EBP + -0x1c);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c1070();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

