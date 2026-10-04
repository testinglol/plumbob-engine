
void FUN_0044a482(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x14);
    if (*(int *)(unaff_EBP + -0x18) == 0) {
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
    }
    else {
      **(undefined4 **)(unaff_EBP + -0x18) = **(undefined4 **)(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x18);
    }
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
  }
  FUN_0044a505();
  return;
}

