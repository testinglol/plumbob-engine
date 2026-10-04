
undefined4 * FUN_005e5e61(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x28) = extraout_ECX;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_00674344;
  FUN_006358b0(unaff_EBP + -0x128,uVar2);
  iVar1 = FUN_0063864b(unaff_EBP + -0x128,&DAT_006c3d7c);
  if (iVar1 != 0) {
    FUN_005d4956(iVar1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_004054fa(unaff_EBP + -0x18);
    FUN_005d4d37();
    FUN_004054fa(unaff_EBP + -0x18);
    while( true ) {
      iVar1 = FUN_0063864b(0,&DAT_006c3d7c);
      if (iVar1 == 0) break;
      FUN_005d4956(iVar1);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_004054fa(unaff_EBP + -0x24);
      uVar2 = FUN_005d4d37();
      FUN_004054fa(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_005b8770();
    }
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
  }
  FUN_005d4bbf(s_Unknown_006c7cd4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 10) = 1;
  return extraout_ECX;
}

