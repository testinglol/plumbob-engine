
void Catch_005c6b60(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x18) != 0) {
    uVar2 = *(int *)(unaff_EBP + -0x18) * 0x10;
    if (uVar2 < 0x81) {
      FUN_004017b8();
      puVar1 = *(undefined4 **)(unaff_EBP + -0x14);
      *puVar1 = *(undefined4 *)(&DAT_006de560 + (uVar2 + 7 >> 3) * 4);
      *(undefined4 **)(&DAT_006de560 + (uVar2 + 7 >> 3) * 4) = puVar1;
      DAT_006de5a4 = 0;
    }
    else {
      FUN_00634ecc(*(undefined4 *)(unaff_EBP + -0x14));
    }
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

