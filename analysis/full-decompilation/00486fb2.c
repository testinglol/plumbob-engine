
void FUN_00486fb2(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x114,0,0x104);
  *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(9,unaff_EBP + -0x120);
  uVar1 = FUN_0041532c(0,uVar1);
  FUN_004ee9ce(uVar1);
  iVar2 = FUN_0046f71c(unaff_EBP + -0x120,0);
  if (iVar2 == 0) {
    puVar3 = operator_new(0x6c);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      FUN_0046fca5();
      *puVar3 = &PTR_FUN_0066643c;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    DAT_006e576c = puVar3;
    FUN_00470383(unaff_EBP + -0x364,0x89,0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

