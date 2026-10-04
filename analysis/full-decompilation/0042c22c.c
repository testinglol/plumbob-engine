
void FUN_0042c22c(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  uint uVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = extraout_ECX;
  DVar1 = timeGetTime();
  FUN_005bc6cb(DVar1);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xa0) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_0046f824(unaff_EBP + -0x1a0,0,0x100);
  piVar5 = DAT_006e486c;
  *(undefined ***)(unaff_EBP + -0x1ac) = &PTR_FUN_00666524;
  if ((*(byte *)((int)piVar5 + 0x66) & 0x40) != 0) {
    iVar8 = 0;
    while (iVar2 = FUN_0043ad1f(iVar8), iVar2 != 0) {
      if ((*(short *)(*(int *)(iVar2 + 0x60) + 0x12) == 0x800) && (*(int *)(unaff_EBP + -0x14) == 0)
         ) {
        uVar3 = FUN_0045741b();
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      }
      iVar8 = iVar8 + 1;
    }
    iVar8 = *(int *)(unaff_EBP + -0x18);
    uVar7 = 0;
    piVar5 = (int *)(iVar8 + 0x154);
    if (*(int *)(iVar8 + 0x158) - *piVar5 >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(*piVar5 + uVar7 * 4) + 0x10c) == 5000) {
          *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*piVar5 + uVar7 * 4);
          break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(iVar8 + 0x158) - *piVar5 >> 2));
    }
    uVar3 = FUN_0041532c(9,unaff_EBP + -0xa0,0);
    FUN_004fff98(0x10f,uVar3);
    iVar8 = *(int *)(unaff_EBP + -0x10);
    if (iVar8 == 0) {
      iVar8 = *(int *)(unaff_EBP + 8);
      pvVar4 = operator_new(0x15c);
      *(void **)(unaff_EBP + -0x1c) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_004100cf(*(undefined4 *)(*DAT_006e486c + 0x14),5000);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
      uVar3 = FUN_004705f2(1,0xffffffff);
      FUN_0046f8cb(uVar3);
      FUN_004108c4(unaff_EBP + -0x1ac);
      FUN_0042eb8e(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x24) = 2;
      *(undefined4 *)(unaff_EBP + -0x1c) = 3;
    }
    else {
      if (*(uint *)(unaff_EBP + 8) <= (uint)(*(int *)(iVar8 + 0x130) - *(int *)(iVar8 + 300) >> 2))
      goto LAB_0042c554;
      iVar2 = *(int *)(iVar8 + 0x130);
      *(undefined4 *)(unaff_EBP + -0x24) = 4;
      iVar8 = *(int *)(iVar8 + 300);
      *(undefined4 *)(unaff_EBP + -0x1c) = 5;
      iVar8 = *(uint *)(unaff_EBP + 8) - (iVar2 - iVar8 >> 2);
    }
    pvVar4 = operator_new(0x13c);
    *(void **)(unaff_EBP + -0x34) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00525cfd();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005a5631(0x13cf,unaff_EBP + -0x20,4);
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      FUN_005260b1(*(undefined4 *)(unaff_EBP + -0x20),1);
    }
    uVar3 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x24),0xffffffff);
    FUN_005d4956(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_00525fb7(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    uVar3 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x1c),0xffffffff);
    FUN_005d4956(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005260e7(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    (**(code **)(*piVar5 + 0x138))();
    piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar6 = (int *)(**(code **)(*piVar6 + 8))();
    (**(code **)(*piVar6 + 0x20))(piVar5);
    (**(code **)(*piVar5 + 0x94))();
    (**(code **)(*piVar5 + 0x44))();
    FUN_00526e66(iVar8);
    (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
    for (iVar8 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x130) -
                 *(int *)(*(int *)(unaff_EBP + -0x10) + 300) >> 2; iVar8 < *(int *)(unaff_EBP + 8);
        iVar8 = iVar8 + 1) {
      FUN_00526e73();
      (*(code *)**(undefined4 **)(DAT_006e486c[0x13] + 0x48))();
      iVar2 = FUN_0042c68b(iVar8,*(undefined4 *)(unaff_EBP + -0x14));
      if (iVar2 != 0) {
        FUN_004108dc(iVar2);
      }
    }
    FUN_005da4c7(piVar5);
    FUN_00425316(DAT_006e486c[0x11]);
  }
LAB_0042c554:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

