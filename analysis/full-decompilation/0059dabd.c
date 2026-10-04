
int FUN_0059dabd(void)

{
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  iVar1 = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    thunk_FUN_005847fc();
    FUN_005b870f(*(undefined4 *)(unaff_EBP + 0xc));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar1 = FUN_005a026f(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    if (iVar1 == 0) {
      FUN_004f725b(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}

