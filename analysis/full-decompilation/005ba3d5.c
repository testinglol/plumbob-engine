
void FUN_005ba3d5(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  iVar1 = FUN_005d49d6();
  do {
    iVar4 = iVar1;
    iVar1 = iVar4 + -1;
    if (iVar1 < 1) break;
    iVar2 = FUN_004096c2();
  } while (*(char *)(iVar2 + iVar1) != '\\');
  if (iVar1 == 0) {
    FUN_005d4bbf(&DAT_006de560);
  }
  else {
    uVar3 = FUN_005b87aa(unaff_EBP + -0x18,iVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005d499c(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

