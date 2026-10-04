
void FUN_004094f4(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*extraout_ECX != 0) {
    if (*(char *)(unaff_EBP + 8) == '\0') {
      FUN_00470636(extraout_ECX + 3);
    }
    else {
      FUN_0040a5ea();
      iVar1 = FUN_00587b1c(extraout_ECX + 3);
      if (iVar1 != 0) {
        iVar1 = ((undefined4 *)*extraout_ECX)[0x18];
        FUN_00587bed(*(undefined4 *)*extraout_ECX,
                     CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x26)));
      }
    }
    extraout_ECX[2] = 0;
    uVar2 = FUN_00587670();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00470636(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
    *extraout_ECX = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

