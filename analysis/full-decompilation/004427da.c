
void FUN_004427da(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffff80;
  *(undefined4 *)(unaff_EBP + -0x80) = extraout_ECX;
  *(undefined1 *)(*(int *)(unaff_EBP + -0x80) + 0x11) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00445fc4();
  while (*(int *)(*(int *)(unaff_EBP + -0x80) + 0x30) != 0) {
    *(undefined2 *)(unaff_EBP + -0x14) =
         *(undefined2 *)(*(int *)(*(int *)(unaff_EBP + -0x80) + 0x30) + 0xf0);
    FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x14));
  }
  *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x80) + 0x18;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 4);
  *(undefined4 *)(unaff_EBP + -0x1c) = **(undefined4 **)(unaff_EBP + -0x48);
  FUN_00448aa5(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
  FUN_0044288a();
  return;
}

