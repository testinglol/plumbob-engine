
undefined4 FUN_004d96a1(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00416780();
  FUN_00416618(unaff_EBP + -0x50);
  iVar3 = *(int *)(unaff_EBP + 0xc);
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,*(undefined4 *)(iVar3 + 0x11c));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,*(undefined4 *)(iVar3 + 0x110));
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  iVar3 = FUN_0060b848();
  if (iVar3 != 0) {
    FUN_0060b848();
  }
  uVar2 = FUN_004096c2();
  FUN_005d4bbf(uVar2);
  if ((*(char *)(DAT_006e486c + 100) == '\x01') || (*(char *)(DAT_006e486c + 100) == '\x02')) {
    uVar2 = FUN_004096c2();
    uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_005d499c(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    uVar2 = FUN_004096c2();
    *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
    uVar2 = __ftol();
    uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 3;
    FUN_005d499c(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_005b8770();
  uVar2 = FUN_00401f77();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_00401f6f();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  cVar1 = FUN_004cfc50();
  puVar4 = &DAT_006c8398;
  if (cVar1 == '\0') {
    puVar4 = &DAT_006c0d8c;
  }
  uVar2 = FUN_005b870f(puVar4);
  *(undefined4 *)(unaff_EBP + -4) = 6;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_004167a5();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_00416847();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 8;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_00416890();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 9;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_004168ca();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 10;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_0060b844();
  uVar2 = FUN_004d6554(unaff_EBP + -0x18,uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xb;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_004d6c5c(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xc;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar2 = FUN_004d6856(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xd;
  FUN_005d499c(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

