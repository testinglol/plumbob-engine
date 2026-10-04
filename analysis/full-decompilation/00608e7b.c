
undefined4 FUN_00608e7b(void)

{
  void *pvVar1;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  FUN_006358b0(&DAT_006ff2f4,*(undefined4 *)(unaff_EBP + 8));
  DAT_006ff420 = *(int *)(unaff_EBP + 0xc);
  if (DAT_006ff420 == 0xf) {
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      DAT_006ff3f8 = 0;
    }
    else {
      DAT_006ff3f8 = FUN_00609062(0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      DAT_006ff3fc = 0;
    }
    else {
      DAT_006ff3fc = FUN_00609062(1);
    }
    DAT_006d98b8 = 2;
    goto LAB_00608fde;
  }
  if (DAT_006ff420 == 0x11) {
    pvVar1 = operator_new(0x34);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = 3;
      goto LAB_00608f7e;
    }
LAB_00608f37:
    DAT_006ff3f8 = 0;
  }
  else {
    if (DAT_006ff420 == 0x12) {
      pvVar1 = operator_new(0x34);
      *(void **)(unaff_EBP + 8) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (pvVar1 == (void *)0x0) goto LAB_00608f37;
      uVar2 = 2;
    }
    else {
      if (DAT_006ff420 != 0x13) {
        if (DAT_006ff420 == 0x14) {
          pvVar1 = operator_new(0x34);
          *(void **)(unaff_EBP + 8) = pvVar1;
          *(undefined4 *)(unaff_EBP + -4) = 5;
          if (pvVar1 == (void *)0x0) {
            DAT_006ff3f8 = 0;
          }
          else {
            DAT_006ff3f8 = FUN_00609062(5);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          pvVar1 = operator_new(0x34);
          *(void **)(unaff_EBP + 8) = pvVar1;
          *(undefined4 *)(unaff_EBP + -4) = 6;
          if (pvVar1 == (void *)0x0) {
            DAT_006ff3fc = 0;
          }
          else {
            DAT_006ff3fc = FUN_00609062(6);
          }
          DAT_006d98b8 = 2;
        }
        goto LAB_00608fde;
      }
      pvVar1 = operator_new(0x34);
      *(void **)(unaff_EBP + 8) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar1 == (void *)0x0) goto LAB_00608f37;
      uVar2 = 4;
    }
LAB_00608f7e:
    DAT_006ff3f8 = FUN_00609062(uVar2);
  }
  DAT_006d98b8 = 1;
LAB_00608fde:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 0;
}

