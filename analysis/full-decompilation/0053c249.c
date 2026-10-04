
void FUN_0053c249(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  int iVar2;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar1 = *(int *)(extraout_ECX + 0x18);
  *(undefined4 *)(unaff_EBP + -4) = 7;
  iVar2 = extraout_ECX;
  if (iVar1 != 0) {
    FUN_0053c286();
  }
  if (*(int *)(extraout_ECX + 0x1c) != 0) {
    FUN_0053c286(iVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

