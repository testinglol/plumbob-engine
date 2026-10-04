
void FUN_0057ceb6(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  FUN_00580a92(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  while (*(int *)(unaff_EBP + -0x18) != *(int *)(unaff_EBP + -0x20)) {
    piVar1 = *(int **)(*(int *)(unaff_EBP + -0x18) + 8);
    if (piVar1 != (int *)0x0) {
      iVar2 = *piVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(iVar2 + 0x38))();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    FUN_00576e56();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

