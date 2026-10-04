
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0056cd4f(void)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0047352a();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x65] = 0xffffffff;
  fVar2 = DAT_00673438 * _DAT_00666578;
  extraout_ECX[0x80] = uVar1;
  *(float *)(unaff_EBP + 8) = fVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *extraout_ECX = &PTR_FUN_00671158;
  iVar3 = FUN_005c38c0(unaff_EBP + -0x54,1,unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00462f2f(iVar3);
  extraout_ECX[0x76] = *(undefined4 *)(iVar3 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  extraout_ECX[0x77] = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

