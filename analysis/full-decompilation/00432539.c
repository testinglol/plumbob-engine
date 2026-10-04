
undefined4 FUN_00432539(void)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int extraout_ECX;
  uint uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = (*(int **)(unaff_EBP + 8))[1];
  *(char *)(unaff_EBP + 9) = (char)(**(int **)(unaff_EBP + 8) >> 4);
  *(char *)(unaff_EBP + 8) = (char)(iVar1 >> 4);
  *(undefined1 *)(unaff_EBP + 10) = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar2 = FUN_004325af(unaff_EBP + 8);
  if (sVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(extraout_ECX + 0xdc);
    uVar4 = (uint)sVar2;
    uVar3 = 0;
    if ((0 < (int)uVar4) && (uVar4 < (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x18) >> 2) + 1U)) {
      uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x18) + -4 + uVar4 * 4);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

