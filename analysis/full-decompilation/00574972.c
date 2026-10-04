
void FUN_00574972(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(undefined1 *)(extraout_ECX + 0xd) = 1;
  FUN_0057d65a();
  FUN_00574acc();
  (**(code **)(*(int *)(DAT_006f6a78 + 0x128) + 4))();
  FUN_0057584f(DAT_006f6a78 + 0x2c);
  iVar2 = DAT_006f6a78;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  (**(code **)(*(int *)(iVar2 + 0x128) + 8))();
  puVar3 = *(undefined4 **)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x20);
  while( true ) {
    *(undefined4 **)(unaff_EBP + -0x14) = puVar3;
    if (puVar3 == *(undefined4 **)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_0048c4c9();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    piVar1 = (int *)*puVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    if ((((iVar2 != 0x605) && (iVar2 != 0x203)) && (iVar2 != 0xaa7)) &&
       ((iVar2 != 0xaad && (iVar2 != 0xab3)))) break;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(*(int *)*puVar3 + 0x58))();
  FUN_00574a2b();
  return;
}

