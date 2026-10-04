
undefined4 FUN_0047c8fb(void)

{
  size_t sVar1;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar1 = _strlen(&DAT_006de560);
  FUN_00401a3c(&DAT_006de560,&DAT_006de560 + sVar1);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_004311b4(1,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401729();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

