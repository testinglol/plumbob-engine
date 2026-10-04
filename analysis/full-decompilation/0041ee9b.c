
undefined4 * FUN_0041ee9b(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *extraout_ECX;
  int iVar5;
  int *piVar6;
  int unaff_EBP;
  float10 fVar7;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0041edc1(iVar4 + 0xa48);
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x10] = extraout_ECX[0x10] & 0xfffffff9;
  *extraout_ECX = 1;
  extraout_ECX[1] = uVar2;
  extraout_ECX[7] = 0x32;
  if (*(short *)(*(int *)(extraout_ECX[2] + 0x118) + 0x14) != 0) {
    uVar2 = FUN_0043532b();
    extraout_ECX[2] = uVar2;
  }
  if ((extraout_ECX[2] != 0) && (iVar3 = FUN_00457e1c(), iVar3 != 0)) {
    piVar6 = *(int **)(iVar3 + 0x10);
    if ((piVar6 != (int *)0x0) &&
       (iVar5 = *(int *)(iVar3 + 4), *(undefined4 *)(unaff_EBP + 0xc) = 0, 0 < iVar5)) {
      iVar4 = *(int *)(iVar4 + 0xa58);
      do {
        iVar5 = *piVar6;
        if (*(int *)(iVar5 + 0x18) == iVar4) goto LAB_0041ef3f;
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
        piVar6 = piVar6 + 1;
      } while (*(int *)(unaff_EBP + 0xc) < *(int *)(iVar3 + 4));
    }
    iVar5 = 0;
LAB_0041ef3f:
    if (iVar5 != 0) {
      piVar6 = *(int **)(iVar3 + 0x10);
      iVar4 = *(int *)(iVar5 + 0x20);
      if (piVar6 != (int *)0x0) {
        iVar3 = *(int *)(iVar3 + 4);
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        if (0 < iVar3) {
          do {
            iVar5 = *piVar6;
            if (*(int *)(iVar5 + 0x18) == iVar4) goto LAB_0041ef6b;
            *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
            piVar6 = piVar6 + 1;
          } while (*(int *)(unaff_EBP + 0xc) < iVar3);
        }
      }
      iVar5 = 0;
LAB_0041ef6b:
      if ((iVar5 != 0) && (iVar4 != -1)) {
        extraout_ECX[4] = iVar4;
        goto LAB_0041ef7c;
      }
    }
  }
  extraout_ECX[2] = 0;
LAB_0041ef7c:
  *(undefined2 *)(extraout_ECX + 5) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x16) = 0;
  *(undefined2 *)(extraout_ECX + 6) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x1a) = 0;
  extraout_ECX[0xf] = 0;
  iVar4 = FUN_0041f101();
  if (iVar4 == 0) {
    extraout_ECX[9] = 0;
    *(undefined2 *)(extraout_ECX + 8) = 0;
    FUN_005d4bbf(&DAT_006c107c);
    extraout_ECX[0x10] = extraout_ECX[0x10] & 0xfffffffe;
  }
  else {
    *(undefined2 *)(extraout_ECX + 8) = *(undefined2 *)(iVar4 + 2);
    fVar7 = (float10)FUN_0047603d(CONCAT31((int3)((uint)extraout_ECX[1] >> 8),
                                           *(short *)(extraout_ECX[1] + 0x5cc) != 0));
    extraout_ECX[9] = (float)fVar7;
    FUN_005d499c(iVar4 + 0x24);
    uVar1 = *(uint *)(iVar4 + 0x14);
    extraout_ECX[0x10] = extraout_ECX[0x10] & 0xfffffffe;
    if ((uVar1 & 0x100) != 0) {
      extraout_ECX[0x10] = extraout_ECX[0x10] | 1;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

