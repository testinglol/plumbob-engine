
void FUN_00405376(void)

{
  void *pvVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  if (DAT_006de804 == 0) {
    uVar2 = extraout_ECX;
    pvVar1 = operator_new(0x6c);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_006de804 = 0;
    }
    else {
      DAT_006de804 = FUN_004053c4(uVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00404e49();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

