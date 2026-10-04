
void Catch_005c14c0(void)

{
  int unaff_EBP;
  int iVar1;
  
  for (iVar1 = *(int *)(unaff_EBP + 0x10); iVar1 != *(int *)(unaff_EBP + -0x14);
      iVar1 = iVar1 + 0x20) {
    FUN_005c15c8();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

