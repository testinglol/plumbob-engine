
int * FUN_00548250(void)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int *extraout_ECX;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  
  FUN_00634c24();
  uVar6 = *(uint *)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if ((uVar6 == 0xffffffff) || (-uVar6 - 2 < (uint)(extraout_ECX[1] - *extraout_ECX))) {
    FUN_004018ec();
  }
  uVar3 = extraout_ECX[1] - *extraout_ECX;
  if ((extraout_ECX[2] - *extraout_ECX) - 1U < uVar3 + uVar6) {
    *(uint *)(unaff_EBP + -0x14) = uVar3;
    piVar4 = (int *)(unaff_EBP + 8);
    if (uVar6 <= uVar3) {
      piVar4 = (int *)(unaff_EBP + -0x14);
    }
    FUN_00401674(uVar3 + *piVar4);
  }
  if (uVar6 != 0) {
    uVar3 = uVar6 - 1;
    if (uVar3 != 0) {
      uVar1 = *(undefined1 *)(unaff_EBP + 0xc);
      uVar6 = *(uint *)(unaff_EBP + 8);
      puVar7 = (undefined4 *)(extraout_ECX[1] + 1);
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
        puVar7 = puVar7 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar7 = uVar1;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
    }
    iVar2 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00401651(iVar2 + uVar6);
    *(undefined1 *)extraout_ECX[1] = *(undefined1 *)(unaff_EBP + 0xc);
    extraout_ECX[1] = extraout_ECX[1] + uVar6;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

