
undefined4 * FUN_005b8d26(void)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *extraout_ECX;
  uint uVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  uVar2 = *(uint *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  FUN_00401aae(uVar2 + 1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar4 = (undefined4 *)*extraout_ECX;
  *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
  if (uVar2 != 0) {
    uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = uVar1;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    puVar4 = (undefined4 *)(*(int *)(unaff_EBP + -0x10) + uVar2);
  }
  extraout_ECX[1] = puVar4;
  FUN_00401a79();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

