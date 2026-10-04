
undefined4 FUN_0060858c(void)

{
  void *pvVar1;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  FUN_006358b0(&DAT_006ff1b8,*(undefined4 *)(unaff_EBP + 8));
  DAT_006ff2e4 = *(int *)(unaff_EBP + 0xc);
  if (DAT_006ff2e4 == 0xf) {
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_006ff2bc = 0;
    }
    else {
      DAT_006ff2bc = FUN_00608775(0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      DAT_006ff2c0 = 0;
    }
    else {
      DAT_006ff2c0 = FUN_00608775(1);
    }
    DAT_006d95ec = 2;
    goto LAB_006086f5;
  }
  if (DAT_006ff2e4 == 0x11) {
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    if (pvVar1 != (void *)0x0) {
      uVar2 = 3;
      goto LAB_00608695;
    }
LAB_0060864a:
    DAT_006ff2bc = 0;
  }
  else {
    if (DAT_006ff2e4 == 0x12) {
      pvVar1 = operator_new(0x34);
      *(void **)(unaff_EBP + 8) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 5;
      if (pvVar1 == (void *)0x0) goto LAB_0060864a;
      uVar2 = 2;
    }
    else {
      if (DAT_006ff2e4 != 0x13) {
        if (DAT_006ff2e4 == 0x14) {
          pvVar1 = operator_new(0x34);
          *(void **)(unaff_EBP + 8) = pvVar1;
          *(undefined4 *)(unaff_EBP + -4) = 2;
          if (pvVar1 == (void *)0x0) {
            DAT_006ff2bc = 0;
          }
          else {
            DAT_006ff2bc = FUN_00608775(5);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          pvVar1 = operator_new(0x34);
          *(void **)(unaff_EBP + 8) = pvVar1;
          *(undefined4 *)(unaff_EBP + -4) = 3;
          if (pvVar1 == (void *)0x0) {
            DAT_006ff2c0 = 0;
          }
          else {
            DAT_006ff2c0 = FUN_00608775(6);
          }
          DAT_006d95ec = 2;
        }
        goto LAB_006086f5;
      }
      pvVar1 = operator_new(0x34);
      *(void **)(unaff_EBP + 8) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 6;
      if (pvVar1 == (void *)0x0) goto LAB_0060864a;
      uVar2 = 4;
    }
LAB_00608695:
    DAT_006ff2bc = FUN_00608775(uVar2);
  }
  DAT_006d95ec = 1;
LAB_006086f5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

