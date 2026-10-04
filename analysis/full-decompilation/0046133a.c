
void Catch_0046133a(void)

{
  int unaff_EBP;
  int iVar1;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  if (iVar1 != *(int *)(unaff_EBP + -0x14)) {
    do {
      FUN_00461371(0);
      iVar1 = iVar1 + 0x9c;
    } while (iVar1 != *(int *)(unaff_EBP + -0x14));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

