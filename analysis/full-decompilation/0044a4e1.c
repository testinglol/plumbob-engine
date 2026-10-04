
void Catch_0044a4e1(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 8);
  while (*(int *)(unaff_EBP + -0x20) != *(int *)(unaff_EBP + -0x14)) {
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

