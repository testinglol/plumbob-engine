
undefined4 * FUN_004c22a3(void)

{
  int iVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined1 *)((int)extraout_ECX + 10) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xd) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046f824(extraout_ECX + 0x10,0,0x104);
  extraout_ECX[0xd] = &PTR_FUN_006664e8;
  FUN_005d48d9();
  *extraout_ECX = &PTR_FUN_00668838;
  extraout_ECX[1] = 0;
  *(undefined1 *)(extraout_ECX + 2) = 0;
  *(undefined1 *)((int)extraout_ECX + 9) = 0;
  *(undefined1 *)((int)extraout_ECX + 10) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xb) = 0;
  *(undefined1 *)(extraout_ECX + 3) = *(undefined1 *)((int)extraout_ECX + 9);
  *(undefined1 *)((int)extraout_ECX + 0xd) = *(undefined1 *)((int)extraout_ECX + 10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x53] = 0;
  FUN_004c2425();
  uVar2 = FUN_004c27b6();
  *(undefined1 *)(extraout_ECX + 0x54) = uVar2;
  *(undefined1 *)((int)extraout_ECX + 0x151) = uVar2;
  FUN_005d4bbf(s_SimPly_SimSational__006c75b4);
  iVar1 = DAT_006f0a70;
  DAT_006f0a70 = DAT_006f0a70 + 1;
  if (iVar1 == 0) {
    piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
    DAT_006f0a6c = (int *)(**(code **)(*piVar3 + 0x10))(1,0xb,0x10,0);
    if (DAT_006f0a6c != (int *)0x0) {
      (**(code **)(*DAT_006f0a6c + 0x20))(DAT_006f2a44);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

