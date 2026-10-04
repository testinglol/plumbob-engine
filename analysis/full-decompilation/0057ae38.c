
void FUN_0057ae38(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(**(int **)(iVar1 + 0x10) + 8))();
  InterlockedDecrement(&DAT_006f29fc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

