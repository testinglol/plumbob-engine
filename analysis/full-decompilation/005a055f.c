
undefined4 FUN_005a055f(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[2] = *(undefined4 *)(unaff_EBP + 0xc);
  puVar1 = operator_new(0x80);
  *(undefined4 **)(unaff_EBP + 8) = puVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_005d3b23(0);
    *puVar1 = &PTR_FUN_00672164;
    puVar2 = puVar1;
  }
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[3] = puVar2;
  iVar3 = FUN_00646330(*puVar1,&DAT_006d0498);
  if (iVar3 == 0) {
    pvVar5 = operator_new(0xd4);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar5 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00598f28();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[1] = uVar4;
    FUN_005b870f(&DAT_006d0498);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_00599030(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    pvVar5 = operator_new(0x16c);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar5 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_00598953();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b870f(&DAT_006c45a4);
    *(undefined4 *)(unaff_EBP + -4) = 4;
    FUN_00595f2a(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    *(undefined1 *)(iVar3 + 300) = 1;
    FUN_0059903f(iVar3);
LAB_005a06a0:
    if (extraout_ECX[1] != 0) {
      iVar3 = *(int *)(unaff_EBP + 0x14);
      *(undefined4 **)(extraout_ECX[1] + 0x9c) = extraout_ECX;
      if (iVar3 != 0) {
        iVar3 = FUN_005a02d8(*(undefined4 *)(unaff_EBP + 0x14));
        if (iVar3 != 0) {
          FUN_0059943e(iVar3,0,0,0xffffffff);
        }
      }
      if (*(int *)(unaff_EBP + 0x18) != 0) {
        iVar3 = FUN_005a026f(*(undefined4 *)(unaff_EBP + 0x18));
        uVar4 = DAT_006e5490;
        if (iVar3 != 0) {
          *(undefined4 *)(unaff_EBP + 0x14) = 0x3f800000;
          *(undefined4 *)(unaff_EBP + 0x18) = 0x3f800000;
          FUN_0059913f(iVar3,1,unaff_EBP + 0x18,unaff_EBP + 0x14,uVar4,0);
        }
      }
      if (extraout_ECX[1] != 0) {
        FUN_00599362(0);
        FUN_005a0f8b(0);
      }
      uVar4 = 0;
      goto LAB_005a0720;
    }
  }
  else {
    iVar3 = FUN_005a020f(puVar1);
    extraout_ECX[1] = iVar3;
    if (iVar3 != 0) {
      uVar4 = FUN_00598dab();
      extraout_ECX[1] = uVar4;
      goto LAB_005a06a0;
    }
  }
  uVar4 = 1;
LAB_005a0720:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

