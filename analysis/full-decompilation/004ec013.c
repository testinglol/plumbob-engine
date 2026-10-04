
uint FUN_004ec013(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar5;
  int *piVar6;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x18) = extraout_ECX;
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    (**(code **)(*extraout_ECX + 0xc))();
  }
  iVar1 = *(int *)(unaff_EBP + 8);
  extraout_ECX[0x6f] = iVar1;
  if (DAT_006f38b0 == 0) {
    FUN_004ec3fc(iVar1,extraout_ECX + 0x6c);
  }
  else if (DAT_006f38b0 == 1) {
    FUN_004ec325(iVar1,extraout_ECX + 0x6c);
  }
  else {
    if (DAT_006f38b0 - 2U != 0) {
      uVar4 = DAT_006f38b0 - 2U & 0xffffff00;
      goto LAB_004ec176;
    }
    FUN_004ec4d3(iVar1,extraout_ECX + 0x6c);
  }
  piVar6 = extraout_ECX + 0x6c;
  iVar1 = extraout_ECX[0x6d];
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  uVar4 = 0;
  if (iVar1 - *piVar6 >> 2 != 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0xfffffe6c;
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) - (int)extraout_ECX;
    piVar5 = extraout_ECX + 0x65;
    do {
      if ((int *)*piVar5 != (int *)0x0) {
        (**(code **)(*(int *)*piVar5 + 0x94))();
        FUN_005c1719();
        iVar1 = *piVar6;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar3 = FUN_004ec25d(*(undefined4 *)((int)piVar5 + iVar1 + *(int *)(unaff_EBP + 8)));
        *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
        FUN_004ec5aa(uVar3,unaff_EBP + -0x10);
        iVar1 = *(int *)*piVar5;
        uVar3 = FUN_004096c2(1,1);
        (**(code **)(iVar1 + 0x19c))(uVar3);
        FUN_004ec1a7(*(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0x1ac));
        FUN_004ec186(0x2d);
        FUN_004ec5f0(unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + -0x1c));
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005dd9c8(unaff_EBP + -0x28);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005a5e09();
      }
      iVar1 = extraout_ECX[0x6d];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      piVar5 = piVar5 + 1;
      uVar4 = iVar1 - *piVar6 >> 2;
    } while (*(uint *)(unaff_EBP + -0x14) < uVar4);
  }
  uVar4 = CONCAT31((int3)(uVar4 >> 8),1);
LAB_004ec176:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

