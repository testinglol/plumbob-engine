
void FUN_005e692b(void)

{
  void *pvVar1;
  int *piVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x4c) == 0) {
    pvVar1 = operator_new(0x130);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_00606b34(extraout_ECX,*(undefined4 *)(unaff_EBP + 8));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x4c) = piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))();
      (**(code **)(**(int **)(extraout_ECX + 0x4c) + 0x98))();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

