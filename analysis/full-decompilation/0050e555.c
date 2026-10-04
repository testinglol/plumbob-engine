
undefined4 * FUN_0050e555(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  bool bVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined2 *)(extraout_ECX + 0x66) = 0;
  extraout_ECX[0x65] = uVar2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_0066b73c;
  bVar3 = DAT_006f3660 == 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (bVar3) {
    FUN_005a5631(0x256,&DAT_006f3660,4);
  }
  puVar1 = (undefined4 *)FUN_0043acf5(uVar2);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_005d5156(extraout_ECX + 0x67,s_Unknown_Item___d_006cc8c8,*(undefined4 *)(unaff_EBP + 0xc));
    FUN_005d4bbf(&DAT_006de560);
    extraout_ECX[0x6e] = 0;
  }
  else {
    thunk_FUN_00457ea7();
    uVar2 = FUN_004096c2();
    FUN_005d4bbf(uVar2);
    FUN_0045754a();
    uVar2 = FUN_004096c2();
    FUN_005d4bbf(uVar2);
    FUN_005a55f6(*puVar1,(int)*(short *)(puVar1[0x18] + 0x52),extraout_ECX + 0x6e,4);
  }
  if (extraout_ECX[0x6e] == 0) {
    extraout_ECX[0x6e] = DAT_006f3660;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x6d] = *(undefined4 *)(unaff_EBP + 8);
  return extraout_ECX;
}

