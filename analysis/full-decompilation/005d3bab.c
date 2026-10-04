
void FUN_005d3bab(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0067360c;
  puVar1 = (undefined4 *)extraout_ECX[0x18];
  puVar3 = (undefined4 *)extraout_ECX[0x17];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar1;
  if (puVar3 != puVar1) {
    do {
      (**(code **)(*(int *)*puVar3 + 8))();
      puVar3 = puVar3 + 1;
    } while (puVar3 != *(undefined4 **)(unaff_EBP + -0x10));
  }
  uVar2 = extraout_ECX[0x17];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005cf6ee();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

