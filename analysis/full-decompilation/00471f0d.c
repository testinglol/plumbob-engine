
void Catch_00471f0d(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + 0xc)) {
    do {
      FUN_004717d5();
      iVar2 = iVar2 + 0xc;
    } while (iVar2 != *(int *)(unaff_EBP + 0xc));
  }
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x18) * 0xc);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

