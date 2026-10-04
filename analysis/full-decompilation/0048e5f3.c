
void Catch_0048e5f3(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x14)) {
    do {
      FUN_0048ea4e(iVar2);
      iVar2 = iVar2 + 0x28;
    } while (iVar2 != *(int *)(unaff_EBP + -0x14));
  }
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x18) * 0x28);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

