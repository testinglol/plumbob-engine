
void FUN_00474121(void)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x1f0);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  iVar2 = *(int *)(extraout_ECX + 0x1f8) - iVar1;
  if (iVar2 != 0) {
    FUN_0040189d(iVar1,iVar2);
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00470467();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

