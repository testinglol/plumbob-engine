
undefined1 FUN_0042da84(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int extraout_ECX;
  uint uVar5;
  undefined1 uVar6;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  FUN_005b8680();
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b89af();
  FUN_005b870f(&DAT_006de560);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  cVar1 = FUN_005d49dc(unaff_EBP + -0x24);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  if (cVar1 != '\0') {
LAB_0042dada:
    uVar6 = 0;
    goto LAB_0042db74;
  }
  uVar5 = 0;
  if (*(int *)(extraout_ECX + 0x158) - *(int *)(extraout_ECX + 0x154) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(*(int *)(extraout_ECX + 0x154) + uVar5 * 4) + 0x10c) ==
          *(int *)(unaff_EBP + 0xc)) {
        iVar2 = *(int *)(*(int *)(extraout_ECX + 0x154) + uVar5 * 4);
        if (((iVar2 != 0) &&
            (iVar2 = *(int *)(iVar2 + 0x130) - *(int *)(iVar2 + 300) >> 2, iVar2 != 0)) &&
           (0 < iVar2)) goto LAB_0042db3e;
        break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(*(int *)(extraout_ECX + 0x158) - *(int *)(extraout_ECX + 0x154) >> 2));
  }
  goto LAB_0042db72;
  while (iVar7 = iVar7 + 1, iVar7 < iVar2) {
LAB_0042db3e:
    puVar3 = (undefined4 *)FUN_004102ab(iVar7);
    uVar4 = FUN_004e988f(*puVar3);
    FUN_004e9c34(uVar4,unaff_EBP + -0x18);
    cVar1 = FUN_005d49dc(*(undefined4 *)(unaff_EBP + 8));
    if (cVar1 != '\0') goto LAB_0042dada;
  }
LAB_0042db72:
  uVar6 = 1;
LAB_0042db74:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

