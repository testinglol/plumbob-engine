
undefined4 * FUN_004a1e80(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0046f824(extraout_ECX + 4,0,0x100);
  extraout_ECX[1] = &PTR_FUN_00666524;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x46] = 0;
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0046f824(unaff_EBP + -0x224,0,0x104);
  *(undefined ***)(unaff_EBP + -0x230) = &PTR_FUN_006664e8;
  FUN_0046f824(unaff_EBP + -0x114,0,0x104);
  *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_006664e8;
  (**(code **)(*(int *)**(undefined4 **)(unaff_EBP + 0xc) + 0x24))(unaff_EBP + -0x120);
  FUN_0041218d(unaff_EBP + -0x120,unaff_EBP + -0x230);
  FUN_0046f8e4(unaff_EBP + -0x230);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

