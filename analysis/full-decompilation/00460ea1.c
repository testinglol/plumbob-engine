
void Catch_00460ea1(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x18)) {
    do {
      FUN_0045fae5();
      iVar2 = iVar2 + 0x9c;
    } while (iVar2 != *(int *)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EBP + -0x1c) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x1c) * 0x9c);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

