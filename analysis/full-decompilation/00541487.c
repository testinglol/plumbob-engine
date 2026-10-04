
void Catch_00541487(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x1c);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + -0x14)) {
    do {
      FUN_005421b6(iVar2);
      iVar2 = iVar2 + 4;
    } while (iVar2 != *(int *)(unaff_EBP + -0x14));
  }
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x18) << 2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

