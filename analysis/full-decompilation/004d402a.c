
void FUN_004d402a(void)

{
  int *piVar1;
  char cVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar1 = *(int **)(*(int *)(DAT_006f2a08 + 0x84) + 0x1168);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x8c))(1);
    if (cVar2 != '\0') {
      FUN_005b870f(*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004d5e20(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

