
void FUN_004fb014(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int **)(extraout_ECX + 0x108) == (int *)0x0) {
    pvVar1 = operator_new(0x174);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00511fa0();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x108) = iVar2;
    if (iVar2 != 0) {
      (**(code **)(**(int **)(extraout_ECX + 0x80) + 0x20))(iVar2);
      FUN_004cb21d(((*(int *)(*(int *)(extraout_ECX + 0x80) + 0x84) -
                    *(int *)(*(int *)(extraout_ECX + 0x108) + 0x84)) -
                   *(int *)(*(int *)(extraout_ECX + 0x80) + 0x7c)) + -0x20 +
                   *(int *)(*(int *)(extraout_ECX + 0x108) + 0x7c),0x20);
      (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x44))();
      (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x90))(0x10,1);
    }
  }
  else {
    (**(code **)(**(int **)(extraout_ECX + 0x108) + 0xa8))(1,0,0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

