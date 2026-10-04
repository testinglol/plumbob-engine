
void FUN_0057ab07(void)

{
  int iVar1;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = unaff_EBX;
  (**(code **)(**(int **)(iVar1 + 0x10) + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

