
undefined4 FUN_004d6809(void)

{
  undefined4 uVar1;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  iVar2 = *(int *)(unaff_EBP + 0xc);
  if (0 < iVar2) {
    do {
      uVar1 = FUN_005b870f(&DAT_006de560);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004d5f61(uVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

