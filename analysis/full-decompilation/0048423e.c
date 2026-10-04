
char FUN_0048423e(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_00634c24();
  if (DAT_006e56c0 == '\0') {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar2 = FUN_0041532c(9,unaff_EBP + -0x78,0);
    cVar1 = FUN_004fff98(0xa4,uVar2);
    if (cVar1 != '\0') {
      iVar3 = 0;
      puVar5 = &DAT_006e5630;
      do {
        iVar3 = iVar3 + 1;
        iVar4 = FUN_004705f2(iVar3,0xffffffff);
        if (iVar4 != 0) {
          FUN_005d4bbf(iVar4);
        }
        puVar5 = puVar5 + 3;
      } while ((int)puVar5 < 0x6e56c0);
    }
    uVar2 = FUN_0041532c(9,unaff_EBP + -0x78,0);
    cVar1 = FUN_004fff98(0x9a,uVar2);
    if (cVar1 != '\0') {
      uVar2 = FUN_004705f2(7,0xffffffff);
      FUN_005d4bbf(uVar2);
      uVar2 = FUN_004705f2(8,0xffffffff);
      FUN_005d4bbf(uVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    DAT_006e56c0 = '\x01';
    FUN_00470467();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return DAT_006e56c0;
}

