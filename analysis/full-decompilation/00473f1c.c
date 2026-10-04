
void Catch_00473f1c(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  iVar2 = iVar1;
  if (iVar1 != *(int *)(unaff_EBP + 0xc)) {
    do {
      FUN_00473f56(0);
      iVar2 = iVar2 + 0x30;
    } while (iVar2 != *(int *)(unaff_EBP + 0xc));
  }
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    FUN_0040189d(iVar1,*(int *)(unaff_EBP + -0x18) * 0x30);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

