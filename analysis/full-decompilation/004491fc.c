
void Catch_004491fc(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0xa4) = *(undefined4 *)(unaff_EBP + -0x2c);
  while (*(int *)(unaff_EBP + -0xa4) != *(int *)(unaff_EBP + -0x24)) {
    *(int *)(unaff_EBP + -0xa4) = *(int *)(unaff_EBP + -0xa4) + 4;
  }
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x2c),*(int *)(unaff_EBP + -0x20) << 2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

