
void Catch_006047d2(void)

{
  int unaff_EBP;
  int iVar1;
  
  for (iVar1 = *(int *)(unaff_EBP + 0x10); iVar1 != *(int *)(unaff_EBP + -0x14);
      iVar1 = iVar1 + 0x1c) {
    FUN_006041f7();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

