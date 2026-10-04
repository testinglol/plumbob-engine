
undefined1 FUN_004404c9(void)

{
  undefined1 uVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8) + 0xfc;
  *(undefined1 *)(unaff_EBP + -0x14) = **(undefined1 **)(unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(*(int *)(unaff_EBP + -0x1c) + 1);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(*(int *)(unaff_EBP + -0x1c) + 2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + 0xc) + 0xfc;
  *(undefined1 *)(unaff_EBP + -0x10) = **(undefined1 **)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -0xf) = *(undefined1 *)(*(int *)(unaff_EBP + -0x20) + 1);
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(*(int *)(unaff_EBP + -0x20) + 2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x2c) = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(*(int *)(unaff_EBP + -0x2c) + 0x84);
  FUN_00434ffd(*(undefined4 *)(unaff_EBP + -0x24));
  *(undefined4 *)(unaff_EBP + -0x38) = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0x84);
  FUN_00434ffd(*(undefined4 *)(unaff_EBP + -0x30));
  uVar1 = FUN_0044058c(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -0x18) = uVar1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x18);
}

