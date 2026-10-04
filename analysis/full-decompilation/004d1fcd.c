
undefined1 FUN_004d1fcd(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = DAT_006fe8cc;
  piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  iVar5 = (**(code **)(*piVar4 + 8))();
  iVar1 = *(int *)(iVar5 + 0x7c);
  iVar7 = *(int *)(iVar5 + 0x84);
  iVar2 = *(int *)(iVar5 + 0x80);
  iVar5 = *(int *)(iVar5 + 0x88);
  uVar6 = (**(code **)(*DAT_006fe8bc + 0x34))();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d6516(&PTR_DAT_006c7c80,unaff_EBP + -0x1c,1);
  iVar7 = FUN_00413d0e(uVar3,iVar7 - iVar1,iVar5 - iVar2,*(undefined4 *)(DAT_006f2a08 + 0xc0),
                       *(undefined4 *)(DAT_006f2a08 + 0xcc),*(undefined4 *)(unaff_EBP + -0x1c));
  iVar1 = DAT_006e486c;
  if (iVar7 == 0) {
    if (DAT_006e486c != 0) {
      thunk_FUN_004151c6();
      FUN_006321f0(iVar1);
    }
    DAT_006e486c = 0;
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

