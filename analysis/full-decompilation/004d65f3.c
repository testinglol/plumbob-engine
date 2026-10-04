
undefined1 FUN_004d65f3(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_004706f0();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xf0) = &PTR_FUN_0066643c;
  uVar3 = 1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x84,1);
  cVar1 = FUN_00500045(0x9e,uVar2);
  if (cVar1 != '\0') {
    uVar2 = FUN_00471509(1,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(2,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(3,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(4,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(5,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(6,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(7,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(8,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(9,1);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(10,1);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(0xb,1);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(0xc,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_00471509(0xd,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_0041532c(9,unaff_EBP + -0xf0,0);
    cVar1 = FUN_004fff98(0x9a,uVar2);
    if (cVar1 != '\0') {
      uVar2 = FUN_004705f2(0x11,0xffffffff);
      FUN_005d4bbf(uVar2);
      goto LAB_004d67dc;
    }
  }
  uVar3 = 0;
LAB_004d67dc:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004712d0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

