
code * Catch_00442855(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x80) + 0x18;
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 4);
  *(undefined4 *)(unaff_EBP + -0x50) = **(undefined4 **)(unaff_EBP + -0x7c);
  FUN_00448aa5(*(undefined4 *)(unaff_EBP + -0x50),*(undefined4 *)(unaff_EBP + -0x4c));
  *(undefined4 *)(*(int *)(unaff_EBP + -0x80) + 0x30) = 0;
  return FUN_0044288a;
}

