
void FUN_00429cc7(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x24) = iVar1 + 1;
  FUN_0046f824(unaff_EBP + -0x180,0,0x104);
  *(undefined ***)(unaff_EBP + -0x18c) = &PTR_FUN_006664e8;
  FUN_00425691(*(undefined4 *)(extraout_ECX + 0x164),unaff_EBP + -0x18c);
  FUN_00418fea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00418fea();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar3 = FUN_004190d3(unaff_EBP + -0x18c,1);
  if (iVar3 == 0) {
    iVar3 = FUN_004190d3(extraout_ECX,1);
    if (iVar3 == 0) {
      FUN_0046cee2();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00424464();
      if (iVar1 == 0) {
        *(undefined2 *)(unaff_EBP + -0x10) = DAT_006c1ef0;
        *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x4e4;
        *(undefined4 *)(unaff_EBP + -0x14) = s_IMISSUOH_006c1ef4._0_4_;
        *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666730;
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_00464f5b(unaff_EBP + -0x1c,unaff_EBP + -0x7c,*(undefined4 *)(unaff_EBP + -0x10),
                     unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00465055();
        FUN_0046dae0(0x1a,0);
        uVar2 = DAT_006c1ef0;
        *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666730;
        *(undefined2 *)(unaff_EBP + -0x10) = uVar2;
        *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x4e4;
        *(undefined4 *)(unaff_EBP + -0x14) = s_IMISSUOH_006c1ef4._0_4_;
        *(undefined1 *)(unaff_EBP + -4) = 5;
        FUN_00464eab(unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x7c,
                     *(undefined4 *)(unaff_EBP + -0x10));
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_00465055();
      }
      *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x338;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x4e474248;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666d04;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_00464f5b(unaff_EBP + -0x1c,unaff_EBP + -0x50,1,unaff_EBP + -0x20);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00465055();
      *(undefined2 *)(unaff_EBP + -0x20c) = 0;
      *(undefined2 *)(unaff_EBP + -0x20e) = *(undefined2 *)(unaff_EBP + -0x24);
      *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x338;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x4e474248;
      *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666d04;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_00464eab(unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x50,1);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00465055();
      if (*(int *)(unaff_EBP + 8) == 0) {
        FUN_0046dae0(0x1a,0);
      }
      *(undefined2 *)(extraout_ECX + 0x12a) = *(undefined2 *)(unaff_EBP + -0x24);
      *(undefined2 *)(extraout_ECX + 300) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00424560();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046d08e();
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0041905d();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041905d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

