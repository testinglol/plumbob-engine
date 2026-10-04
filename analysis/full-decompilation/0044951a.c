
void Catch_0044951a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x24);
  while (*(int *)(unaff_EBP + -0x74) != *(int *)(unaff_EBP + -0x1c)) {
    *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + 4;
  }
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_0040189d(*(undefined4 *)(unaff_EBP + -0x24),*(int *)(unaff_EBP + -0x18) << 2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

