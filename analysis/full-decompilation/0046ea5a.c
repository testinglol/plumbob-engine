
void FUN_0046ea5a(void)

{
  int *extraout_ECX;
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  puVar2 = (undefined4 *)*extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (puVar2 != (undefined4 *)extraout_ECX[1]) {
    do {
      for (puVar1 = (undefined4 *)*puVar2; puVar1 != (undefined4 *)puVar2[1]; puVar1 = puVar1 + 1) {
        FUN_006321f0(*puVar1);
      }
      FUN_004071be(*puVar2,puVar2[1]);
      puVar2 = puVar2 + 3;
    } while (puVar2 != (undefined4 *)extraout_ECX[1]);
  }
  FUN_0046ef93(*extraout_ECX,extraout_ECX[1]);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046eefc();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

