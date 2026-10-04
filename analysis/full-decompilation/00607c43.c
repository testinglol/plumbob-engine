
undefined4 FUN_00607c43(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  if ((char)extraout_ECX[2] == '\0') {
    uVar2 = FUN_005d4956(s_Times_New_Roman_006d9540);
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar1 + 0x18))(0,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = FUN_005d4956(s_Comic_Sans_MS_006d9530);
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(iVar1 + 0x18))(1,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = FUN_005d4956(s_Courier_New_006d9524);
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    (**(code **)(iVar1 + 0x18))(2,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = FUN_005d4956(s_Lucida_Console_006d9514);
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    (**(code **)(iVar1 + 0x18))(3,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    uVar2 = FUN_005d4956(s_VN_Wingdings_006d9505 + 3);
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    (**(code **)(iVar1 + 0x18))(4,uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    *(undefined1 *)(extraout_ECX + 2) = 1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return 1;
}

