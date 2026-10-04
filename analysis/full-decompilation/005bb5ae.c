
void Catch_005bb5ae(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  uint uVar4;
  
  iVar3 = *(int *)(unaff_EBP + -0x30);
  uVar4 = 0;
  if (*(int *)(unaff_EBP + -0x2c) - iVar3 >> 2 != 0) {
    do {
      while (puVar1 = *(undefined4 **)(iVar3 + uVar4 * 4), puVar1 != (undefined4 *)0x0) {
        uVar2 = *puVar1;
        FUN_005bbdc8(puVar1);
        *(undefined4 *)(*(int *)(unaff_EBP + -0x30) + uVar4 * 4) = uVar2;
        iVar3 = *(int *)(unaff_EBP + -0x30);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(unaff_EBP + -0x2c) - iVar3 >> 2));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

