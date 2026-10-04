
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00589043(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(float *)(extraout_ECX + 0x80) < _DAT_0066657c) ||
     (*(float *)(extraout_ECX + 0x84) < _DAT_0066657c)) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = __ftol();
    iVar2 = __ftol();
    uVar3 = *(undefined4 *)(*(int *)(extraout_ECX + 0x138) + 0x110);
    *(char *)(unaff_EBP + -0x10) = (char)(iVar1 >> 4);
    *(char *)(unaff_EBP + -0xf) = (char)(iVar2 >> 4);
    *(char *)(unaff_EBP + -0xe) = (char)uVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar3 = FUN_005890dc(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x10);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

