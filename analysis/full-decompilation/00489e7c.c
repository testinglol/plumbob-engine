
void Catch_00489e7c(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x18)) {
    do {
      FUN_00488302(iVar2);
      iVar2 = iVar2 + 0x3c;
    } while (iVar2 != *(int *)(unaff_EBP + -0x18));
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x14) * 0x3c);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

