
void FUN_00564372(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar4;
  
  FUN_00634c24();
  FUN_005dae65(extraout_ECX);
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  cVar1 = *(char *)(extraout_ECX + 0x159);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (cVar1 == '\0') {
    uVar3 = 0xe;
    uVar4 = 0xf;
  }
  else {
    uVar3 = 0x13;
    uVar4 = 0x14;
  }
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x90,0);
  cVar1 = FUN_004fff98(0x80,uVar2);
  if (cVar1 != '\0') {
    uVar3 = FUN_004705f2(uVar3,0xffffffff);
    FUN_005d4bbf(uVar3);
    uVar3 = FUN_004705f2(uVar4,0xffffffff);
    FUN_005d4bbf(uVar3);
    FUN_004f6994(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x18),0,0);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00470467();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

