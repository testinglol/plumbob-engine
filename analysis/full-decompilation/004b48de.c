
undefined4 * FUN_004b48de(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  extraout_ECX[1] = 0;
  *(undefined4 **)(unaff_EBP + -0x1c) = extraout_ECX;
  extraout_ECX[2] = 0;
  extraout_ECX[3] = 0;
  FUN_00422055(0xffffffff,0xffffffff);
  extraout_ECX[7] = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  extraout_ECX[8] = 0x3f800000;
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX + 9;
  FUN_0054821c(5,unaff_EBP + -0xd);
  uVar3 = extraout_ECX[9];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_005fd5b4(uVar3,5,unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + 8));
  extraout_ECX[10] = uVar3;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX + 0xc;
  FUN_005e6b22(5,unaff_EBP + -0xe);
  uVar3 = extraout_ECX[0xc];
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar3 = FUN_004b5043(uVar3,5,unaff_EBP + -0x2c,*(undefined4 *)(unaff_EBP + 8));
  extraout_ECX[0xd] = uVar3;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX + 0xf;
  FUN_005e6b22(5,unaff_EBP + -0xd);
  uVar3 = extraout_ECX[0xf];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  uVar3 = FUN_004b5043(uVar3,5,unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 8));
  extraout_ECX[0x10] = uVar3;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 **)(unaff_EBP + -0x20) = extraout_ECX + 0x12;
  FUN_0054821c(5,unaff_EBP + -0xe);
  uVar3 = extraout_ECX[0x12];
  *(undefined1 *)(unaff_EBP + -4) = 6;
  uVar3 = FUN_004b5070(uVar3,5,unaff_EBP + -0x18);
  extraout_ECX[0x13] = uVar3;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *extraout_ECX = &PTR_FUN_006687b0;
  iVar4 = FUN_004a69aa();
  iVar5 = FUN_005ceef6(*(undefined4 *)(unaff_EBP + 8));
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar5 = *(int *)(iVar4 + 0x78);
    if (*(int *)(iVar4 + 0x7c) - iVar5 >> 2 != 0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      do {
        if (*(int *)(unaff_EBP + 8) < 0x3c) {
          piVar1 = *(int **)(iVar5 + *(int *)(unaff_EBP + -0x14) * 4);
          *(int **)(extraout_ECX[9] + *(int *)(unaff_EBP + -0x14) * 4) = piVar1;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))();
            piVar6 = (int *)(*(int *)(unaff_EBP + 8) + extraout_ECX[0xc]);
            *piVar6 = piVar1[0x1e];
            piVar6[1] = piVar1[0x1f];
            piVar6[2] = piVar1[0x20];
            piVar6 = (int *)(*(int *)(unaff_EBP + 8) + extraout_ECX[0xf]);
            *piVar6 = piVar1[0x21];
            piVar6[1] = piVar1[0x22];
            piVar6[2] = piVar1[0x23];
            *(int *)(extraout_ECX[0x12] + *(int *)(unaff_EBP + -0x14) * 4) = piVar1[8];
          }
        }
        iVar5 = *(int *)(iVar4 + 0x78);
        iVar2 = *(int *)(iVar4 + 0x7c);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0xc;
      } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar2 - iVar5 >> 2));
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

