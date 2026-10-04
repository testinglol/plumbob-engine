
void FUN_00449555(void)

{
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4);
  *(undefined4 *)(unaff_EBP + -0x8c) = **(undefined4 **)(unaff_EBP + -0xb0);
  *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(unaff_EBP + -0x8c);
  while (*(int *)(unaff_EBP + -0x94) != *(int *)(unaff_EBP + -0x88)) {
    *(int *)(unaff_EBP + -0x94) = *(int *)(unaff_EBP + -0x94) + 4;
  }
  *(int *)(unaff_EBP + -0xac) =
       *(int *)(*(int *)(unaff_EBP + -0xb0) + 8) - **(int **)(unaff_EBP + -0xb0) >> 2;
  *(undefined4 *)(unaff_EBP + -0xa8) = **(undefined4 **)(unaff_EBP + -0xb0);
  if (*(int *)(unaff_EBP + -0xac) != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0xa8),*(int *)(unaff_EBP + -0xac) << 2);
  }
  **(undefined4 **)(unaff_EBP + -0xb0) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(*(int *)(unaff_EBP + -0xb0) + 4) = *(undefined4 *)(unaff_EBP + -0x1c);
  *(int *)(*(int *)(unaff_EBP + -0xb0) + 8) =
       *(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x18) * 4;
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

