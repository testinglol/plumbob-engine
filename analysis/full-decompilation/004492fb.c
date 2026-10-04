
void FUN_004492fb(void)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff38;
  *(undefined4 *)(unaff_EBP + -0xb0) = extraout_ECX;
  if (*(int *)(*(int *)(unaff_EBP + -0xb0) + 4) != *(int *)(*(int *)(unaff_EBP + -0xb0) + 8)) {
    *(int *)(unaff_EBP + -0x30) = *(int *)(*(int *)(unaff_EBP + -0xb0) + 4) + -4;
    *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x2c);
    if (*(int *)(unaff_EBP + -0x28) == 0) {
      *(undefined4 *)(unaff_EBP + -0xb4) = 0;
    }
    else {
      **(undefined4 **)(unaff_EBP + -0x28) = **(undefined4 **)(unaff_EBP + -0x30);
      *(undefined4 *)(unaff_EBP + -0xb4) = *(undefined4 *)(unaff_EBP + -0x28);
    }
    *(int *)(*(int *)(unaff_EBP + -0xb0) + 4) = *(int *)(*(int *)(unaff_EBP + -0xb0) + 4) + 4;
    *(undefined4 *)(unaff_EBP + -0x14) = **(undefined4 **)(unaff_EBP + 0xc);
    *(int *)(unaff_EBP + -0x50) = *(int *)(*(int *)(unaff_EBP + -0xb0) + 4) + -4;
    *(int *)(unaff_EBP + -0x4c) = *(int *)(*(int *)(unaff_EBP + -0xb0) + 4) + -8;
    *(undefined1 *)(unaff_EBP + -0x34) = *(undefined1 *)(unaff_EBP + -0x38);
    *(undefined1 *)(unaff_EBP + -0x48) = *(undefined1 *)(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x50);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x4c);
    *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + 8) >> 2;
    while (0 < *(int *)(unaff_EBP + -0x3c)) {
      *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) + -4;
      *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + -4;
      **(undefined4 **)(unaff_EBP + -0x44) = **(undefined4 **)(unaff_EBP + -0x40);
      *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + -1;
    }
    **(undefined4 **)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x14);
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return;
  }
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
  *(undefined4 *)(unaff_EBP + -0x58) = **(undefined4 **)(unaff_EBP + -0xb0);
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x58) >> 2;
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    *(undefined4 *)(unaff_EBP + -0xb8) = 1;
  }
  else {
    *(int *)(unaff_EBP + -0xb8) = *(int *)(unaff_EBP + -0x20) << 1;
  }
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0xb8);
  if (*(int *)(unaff_EBP + -0x18) == 0) {
    *(undefined4 *)(unaff_EBP + -0xbc) = 0;
  }
  else {
    uVar1 = FUN_00401742(*(int *)(unaff_EBP + -0x18) << 2);
    *(undefined4 *)(unaff_EBP + -0xbc) = uVar1;
  }
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0xbc);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x60) = **(undefined4 **)(unaff_EBP + -0xb0);
  uVar1 = FUN_0044a514(*(undefined4 *)(unaff_EBP + -0x60),*(undefined4 *)(unaff_EBP + 8),
                       *(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x5c));
  *(undefined4 *)(unaff_EBP + -0xc0) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0xc0);
  *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x1c);
  if (*(int *)(unaff_EBP + -100) == 0) {
    *(undefined4 *)(unaff_EBP + -0xc4) = 0;
  }
  else {
    **(undefined4 **)(unaff_EBP + -100) = **(undefined4 **)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -0xc4) = *(undefined4 *)(unaff_EBP + -100);
  }
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
  uVar1 = FUN_0044a514(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x6c),
                       *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x68));
  *(undefined4 *)(unaff_EBP + -200) = uVar1;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -200);
  FUN_00449555();
  return;
}

