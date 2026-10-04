
void Catch_004e1752(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x18)) {
    do {
      FUN_004e12df();
      iVar2 = iVar2 + 0x20;
    } while (iVar2 != *(int *)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x14) << 5);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

