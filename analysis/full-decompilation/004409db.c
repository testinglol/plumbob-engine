
undefined4 FUN_004409db(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x3c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x60);
  if (*(short *)(*(int *)(unaff_EBP + -0x10) + 0x14) == 0) {
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x60);
    *(int *)(unaff_EBP + -0x40) = (int)*(short *)(*(int *)(unaff_EBP + -0x34) + 0x12);
    if (*(int *)(unaff_EBP + -0x40) == 2) {
      pvVar1 = operator_new(0xc14);
      *(void **)(unaff_EBP + -0x20) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      if (*(int *)(unaff_EBP + -0x20) == 0) {
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
      }
      else {
        uVar2 = FUN_00459493(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x3c));
        *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x48);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar2 = *(undefined4 *)(unaff_EBP + -0x1c);
    }
    else if ((*(int *)(unaff_EBP + -0x40) < 8) || (9 < *(int *)(unaff_EBP + -0x40))) {
      pvVar1 = operator_new(0x18c);
      *(void **)(unaff_EBP + -0x18) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (*(int *)(unaff_EBP + -0x18) == 0) {
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
      }
      else {
        uVar2 = FUN_0043194c(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x3c));
        *(undefined4 *)(unaff_EBP + -0x44) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x44);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x60);
    *(int *)(unaff_EBP + -0x4c) = (int)*(short *)(*(int *)(unaff_EBP + -0x38) + 0x12);
    if (*(int *)(unaff_EBP + -0x4c) == 8) {
      pvVar1 = operator_new(0x1b8);
      *(void **)(unaff_EBP + -0x28) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (*(int *)(unaff_EBP + -0x28) == 0) {
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
      }
      else {
        uVar2 = FUN_004631a6(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                             *(undefined4 *)(unaff_EBP + -0x3c));
        *(undefined4 *)(unaff_EBP + -0x50) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar2 = *(undefined4 *)(unaff_EBP + -0x24);
    }
    else {
      pvVar1 = operator_new(0x1ac);
      *(void **)(unaff_EBP + -0x30) = pvVar1;
      *(undefined4 *)(unaff_EBP + -4) = 3;
      if (*(int *)(unaff_EBP + -0x30) == 0) {
        *(undefined4 *)(unaff_EBP + -0x54) = 0;
      }
      else {
        uVar2 = FUN_004227e6(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                             *(undefined4 *)(unaff_EBP + -0x3c));
        *(undefined4 *)(unaff_EBP + -0x54) = uVar2;
      }
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(unaff_EBP + -0x54);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar2 = *(undefined4 *)(unaff_EBP + -0x2c);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

