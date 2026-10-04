
undefined4 * FUN_005fd983(void)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005d58d8(0xffd23940);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x12] = &PTR_LAB_00676900;
  FUN_00580cd2(unaff_EBP + -0xe,unaff_EBP + -0xd);
  extraout_ECX[0x16] = 1;
  extraout_ECX[0x18] = 0;
  *(undefined1 *)(extraout_ECX + 0x1a) = 0;
  extraout_ECX[0x19] = 1;
  extraout_ECX[0x17] = &PTR_FUN_00676868;
  iVar1 = extraout_ECX[0x17];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_LAB_00676850;
  extraout_ECX[1] = &PTR_LAB_00676844;
  extraout_ECX[2] = &PTR_FUN_0067682c;
  extraout_ECX[4] = &PTR_LAB_00676824;
  extraout_ECX[0x12] = &PTR_LAB_00676794;
  (**(code **)(iVar1 + 0x90))(1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

