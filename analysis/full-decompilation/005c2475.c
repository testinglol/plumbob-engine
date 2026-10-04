
int * FUN_005c2475(void)

{
  undefined4 uVar1;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *extraout_ECX = (int)&DAT_00673350;
    extraout_ECX[3] = (int)&DAT_00673348;
    FUN_00632a8e();
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  FUN_00632b81(0);
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_00673344;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

