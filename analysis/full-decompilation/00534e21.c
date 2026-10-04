
void FUN_00534e21(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    iVar1 = *(int *)(unaff_EBP + 0xc);
    FUN_005b86bd(iVar1);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_00533d58(iVar1 + 0x10);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

