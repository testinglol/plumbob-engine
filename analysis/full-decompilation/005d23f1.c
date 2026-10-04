
void FUN_005d23f1(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673580;
  puVar2 = (undefined4 *)extraout_ECX[2];
  puVar4 = (undefined4 *)extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar4 != puVar2) {
    puVar4 = puVar4 + 0x41;
    do {
      (**(code **)(*(int *)*puVar4 + 8))();
      puVar1 = puVar4 + 1;
      puVar4 = puVar4 + 0x42;
    } while (puVar1 != puVar2);
  }
  uVar3 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  FUN_005d2584();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

