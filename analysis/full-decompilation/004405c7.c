
void FUN_004405c7(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x80) = extraout_ECX;
  if (*(char *)(*(int *)(unaff_EBP + -0x80) + 0x10) == '\0') {
    *(undefined4 *)(*(int *)(unaff_EBP + -0x80) + 0x14) = *(undefined4 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x50) = *(int *)(unaff_EBP + -0x80) + 0x18;
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(*(int *)(unaff_EBP + -0x50) + 4);
    *(undefined4 *)(unaff_EBP + -0x24) = **(undefined4 **)(unaff_EBP + -0x50);
    FUN_00448aa5(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20));
    *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x80) + 0x24;
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + 4);
    *(undefined4 *)(unaff_EBP + -0x58) = **(undefined4 **)(unaff_EBP + -0x7c);
    FUN_004071be(*(undefined4 *)(unaff_EBP + -0x58),*(undefined4 *)(unaff_EBP + -0x54));
    *(undefined1 *)(*(int *)(unaff_EBP + -0x80) + 0x10) = 1;
    *(undefined4 *)(unaff_EBP + -0x10) =
         *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x80) + 0x14) + 0x2c);
    FUN_0046e3d5(*(undefined4 *)(unaff_EBP + -0x10),0);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0046e3ed(100,0,*(int *)(unaff_EBP + -0x80) + 0x9c,0);
    *(undefined1 *)(*(int *)(unaff_EBP + -0x80) + 0x11) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0046e52f();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

