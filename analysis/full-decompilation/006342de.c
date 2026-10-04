
int * FUN_006342de(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    *extraout_ECX = (int)&DAT_0068917c;
    extraout_ECX[3] = (int)&DAT_00689174;
    FUN_00632a8e();
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  FUN_00632776(*(undefined4 *)(unaff_EBP + 8),0);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_006324ac(*(undefined4 *)(unaff_EBP + 8),0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_00689170;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

