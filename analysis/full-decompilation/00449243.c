
void FUN_00449243(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0xbc) = **(undefined4 **)(unaff_EBP + -0xd8);
  while (*(int *)(unaff_EBP + -0xbc) != *(int *)(*(int *)(unaff_EBP + -0xd8) + 4)) {
    *(int *)(unaff_EBP + -0xbc) = *(int *)(unaff_EBP + -0xbc) + 4;
  }
  *(int *)(unaff_EBP + -0xd4) =
       *(int *)(*(int *)(unaff_EBP + -0xd8) + 8) - **(int **)(unaff_EBP + -0xd8) >> 2;
  *(undefined4 *)(unaff_EBP + -0xd0) = **(undefined4 **)(unaff_EBP + -0xd8);
  if (*(int *)(unaff_EBP + -0xd4) != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0xd0),*(int *)(unaff_EBP + -0xd4) << 2);
  }
  **(undefined4 **)(unaff_EBP + -0xd8) = *(undefined4 *)(unaff_EBP + -0x2c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xd8) + 4) = *(undefined4 *)(unaff_EBP + -0x24);
  *(int *)(*(int *)(unaff_EBP + -0xd8) + 8) =
       *(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_EBP + -0x20) * 4;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

