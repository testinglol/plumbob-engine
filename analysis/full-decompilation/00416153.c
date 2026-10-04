
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00416153(void)

{
  int iVar1;
  undefined2 uVar2;
  char cVar3;
  int iVar4;
  int extraout_ECX;
  undefined4 uVar5;
  int unaff_EBP;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  uVar7 = *(undefined4 *)(DAT_006e486c + 0x44);
  uVar5 = 0;
  FUN_0046f824(unaff_EBP + -0x364,0,0x104);
  *(undefined ***)(unaff_EBP + -0x370) = &PTR_FUN_006664e8;
  FUN_00412122(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x370);
  FUN_0046f847(s_HouseTemp_iff_006c1f78,0xffffffff);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00465a37(unaff_EBP + -0x370,1);
  cVar3 = (**(code **)(*(int *)(unaff_EBP + -0x260) + 0x28))();
  if (cVar3 == '\0') {
    uVar5 = 0xfffffbb4;
  }
  else {
    cVar3 = (**(code **)(*(int *)(unaff_EBP + -0x260) + 0x20))();
    if (cVar3 != '\0') {
      FUN_0041607b();
      uVar6 = _DAT_006c1ef0;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX + 0x20);
      *(undefined4 *)(unaff_EBP + -0x14) = s_IMISSUOH_006c1ef4._0_4_;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666730;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00464eab(unaff_EBP + -0x1c,uVar7,unaff_EBP + -0x260,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00465055();
      uVar2 = DAT_006c1ef2;
      *(int *)(unaff_EBP + -0x18) = extraout_ECX;
      *(undefined2 *)(unaff_EBP + -0x10) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = s_IMISSUOH_006c1ef4._4_4_;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666720;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00464eab(unaff_EBP + -0x1c,uVar7,unaff_EBP + -0x260,*(undefined4 *)(unaff_EBP + -0x10));
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00465055();
      FUN_00476bac(0);
      FUN_004a1356(unaff_EBP + -0x260,*(undefined4 *)(extraout_ECX + 0x1c));
      FUN_004c624f(unaff_EBP + -0x260,*(undefined4 *)(extraout_ECX + 0x1c));
      FUN_004783f6(unaff_EBP + -0x260,uVar7);
      FUN_0043fb5b(unaff_EBP + -0x260);
      FUN_0040766a(0x92,unaff_EBP + -0x260);
      (**(code **)(*(int *)(unaff_EBP + -0x260) + 0x18))();
      iVar1 = *(int *)(unaff_EBP + 8);
      iVar4 = FUN_0046b546(iVar1);
      if (iVar4 == 0) {
        uVar7 = *(undefined4 *)(iVar1 + 4);
        uVar6 = *(undefined4 *)(unaff_EBP + -0x36c);
        FUN_005b8e25(uVar6,uVar7);
        cVar3 = FUN_005b9849(uVar6,uVar7);
        if (cVar3 == '\0') {
          uVar5 = 0xffffffff;
        }
        goto LAB_00416353;
      }
      FUN_0046b546(unaff_EBP + -0x370);
    }
    uVar5 = 0xfffffbb5;
  }
LAB_00416353:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

