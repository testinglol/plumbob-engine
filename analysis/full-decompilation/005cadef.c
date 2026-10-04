
undefined4 FUN_005cadef(void)

{
  int yBottom;
  DWORD DVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  yBottom = *(int *)(extraout_ECX + 0x4c);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined1 *)(extraout_ECX + 0x44c) = 1;
  SetRect((LPRECT)(unaff_EBP + -0x2c),0,0,*(int *)(extraout_ECX + 0x48),yBottom);
  FUN_004a891e();
  FUN_004a891e();
  FUN_005cddcf(unaff_EBP + -0x2c);
  FUN_005c8c6c();
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) / 2;
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) / 2;
  DVar1 = timeGetTime();
  *(DWORD *)(unaff_EBP + -0x18) = DVar1 + 0xfa;
  while( true ) {
    DVar1 = timeGetTime();
    if (*(uint *)(unaff_EBP + -0x18) <= DVar1) break;
    FUN_004a891e();
    FUN_004a891e();
    FUN_005cddcf(unaff_EBP + -0x2c);
    FUN_005c8c6c();
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
  }
  *(undefined1 *)(extraout_ECX + 0x44c) = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x14);
}

