
void FUN_0057d2cc(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  do {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    if (*(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + -0x1c)) {
      iVar1 = *(int *)(unaff_ESI + 0x104);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(iVar1 + 8))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
  } while ((int *)**(int **)(unaff_EBP + -0x14) == (int *)0x0);
  iVar1 = *(int *)**(int **)(unaff_EBP + -0x14);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar1 + 0x1c))();
  FUN_0057d2cc();
  return;
}

