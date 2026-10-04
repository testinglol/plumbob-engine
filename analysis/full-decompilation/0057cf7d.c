
void FUN_0057cf7d(void)

{
  int unaff_EBP;
  int *unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  do {
    unaff_ESI = unaff_ESI + 1;
    *(int **)(unaff_EBP + -0x14) = unaff_ESI;
    if (unaff_ESI == *(int **)(unaff_EBP + -0x1c)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
  } while (*unaff_ESI == 0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0057fa52();
  FUN_0057cf7d();
  return;
}

