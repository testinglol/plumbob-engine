
void FUN_004d2f91(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x11a8) == 0) {
    pvVar1 = operator_new(0x160);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004c22a3();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0x11a8) = uVar2;
  }
  if (*(int *)(extraout_ECX + 0x11a8) != 0) {
    FUN_005d499c(*(undefined4 *)(unaff_EBP + 8));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

