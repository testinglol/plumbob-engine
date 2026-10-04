
void FUN_005d4045(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar3;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = *(undefined4 **)(extraout_ECX + 8);
  for (puVar3 = *(undefined4 **)(extraout_ECX + 4); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    (**(code **)(*(int *)*puVar3 + 8))();
  }
  uVar2 = *(undefined4 *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

