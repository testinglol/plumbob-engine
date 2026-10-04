
undefined4 * FUN_00587d5c(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_00584822();
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x53] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(extraout_ECX + 0x54) = 0;
  FUN_005c4830();
  extraout_ECX[0x59] = 0;
  extraout_ECX[0x5a] = 0;
  extraout_ECX[0x5b] = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[0x5e] = 0;
  extraout_ECX[0x5f] = 0;
  extraout_ECX[0x60] = 0xffffffff;
  extraout_ECX[0x61] = 0;
  extraout_ECX[0x62] = 0;
  extraout_ECX[99] = 0;
  extraout_ECX[100] = 3;
  extraout_ECX[0x65] = 3;
  extraout_ECX[0x66] = 0xffffffff;
  extraout_ECX[0x67] = 0;
  extraout_ECX[0x68] = 0;
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6c] = 0xffffffff;
  extraout_ECX[0x6d] = 0xffffffff;
  extraout_ECX[0x6e] = 0xffffffff;
  extraout_ECX[0x6f] = 0xffffffff;
  extraout_ECX[0x70] = 0;
  extraout_ECX[0x71] = 0;
  extraout_ECX[0x72] = 0;
  extraout_ECX[0x73] = 0;
  extraout_ECX[0x74] = 0;
  extraout_ECX[0x75] = 0;
  extraout_ECX[0x76] = 0;
  extraout_ECX[0x77] = 0;
  extraout_ECX[0x78] = 0;
  extraout_ECX[0x79] = 0;
  extraout_ECX[0x7a] = 0;
  extraout_ECX[0x7b] = 0;
  extraout_ECX[0x7c] = 0;
  extraout_ECX[0x7d] = 0;
  extraout_ECX[0x7e] = 0;
  extraout_ECX[0x7f] = 0;
  extraout_ECX[0x80] = 0;
  extraout_ECX[0x93] = 0;
  extraout_ECX[0x81] = 0;
  extraout_ECX[0x94] = 0;
  extraout_ECX[0x95] = 0;
  extraout_ECX[0x82] = 0;
  extraout_ECX[0x96] = 0;
  extraout_ECX[0x83] = 0;
  extraout_ECX[0x84] = 0;
  extraout_ECX[0x85] = 0;
  extraout_ECX[0x86] = 0;
  extraout_ECX[0x8a] = 0x3f800000;
  extraout_ECX[0x8b] = 0x3f800000;
  extraout_ECX[0x97] = 0;
  extraout_ECX[0x98] = 0;
  extraout_ECX[0x99] = 0;
  extraout_ECX[0x9a] = 0;
  extraout_ECX[0x9b] = 0;
  extraout_ECX[0x9c] = 0;
  extraout_ECX[0x9d] = 0;
  extraout_ECX[0x9e] = 0;
  extraout_ECX[0x9f] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  extraout_ECX[0xa5] = 0;
  extraout_ECX[0xa0] = 0;
  extraout_ECX[0xa1] = 0;
  extraout_ECX[0xa6] = 0;
  extraout_ECX[0xa2] = 0;
  extraout_ECX[0xa3] = 0;
  extraout_ECX[0xa4] = 0;
  *(undefined1 *)(extraout_ECX + 0xa7) = 0;
  *extraout_ECX = &PTR_LAB_00671ee4;
  uVar1 = FUN_0058567b();
  extraout_ECX[0x2d] = uVar1;
  extraout_ECX[0x8c] = 0;
  extraout_ECX[0x8d] = 0;
  extraout_ECX[0x8e] = 0;
  extraout_ECX[0x8f] = 0;
  extraout_ECX[0x90] = 0;
  extraout_ECX[0x91] = 0x7149f2ca;
  extraout_ECX[0x92] = 0;
  pvVar2 = operator_new(0x1c);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0058364c();
  }
  *(undefined1 *)(unaff_EBP + -4) = 4;
  extraout_ECX[0x96] = uVar1;
  while ((uint)((int)(extraout_ECX[0x9b] - extraout_ECX[0x9a]) >> 2) < 2) {
    pvVar2 = operator_new(0x1c);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0058364c();
    }
    *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005873ba(unaff_EBP + -0x10);
  }
  while ((uint)((int)(extraout_ECX[0x98] - extraout_ECX[0x97]) >> 2) < 2) {
    pvVar2 = operator_new(0x1c);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0058364c();
    }
    *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005873ba(unaff_EBP + -0x10);
  }
  FUN_0047342b(0x3c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

