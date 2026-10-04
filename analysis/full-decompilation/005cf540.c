
void Catch_005cf540(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x18)) {
    do {
      FUN_005c4890();
      iVar2 = iVar2 + 0x44;
    } while (iVar2 != *(int *)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x14) * 0x44);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

