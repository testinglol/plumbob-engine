
void FUN_0041944d(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005bc436();
  FUN_005bc44e(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_005bc676();
  *(int *)(extraout_ECX + 0x20) = *(int *)(extraout_ECX + 0x20) + iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042004f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

