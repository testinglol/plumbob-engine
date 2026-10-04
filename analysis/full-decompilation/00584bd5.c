
void FUN_00584bd5(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  FUN_00634c24();
  iVar2 = (**(code **)(*extraout_ECX + 0xac))();
  if (iVar2 == 0) {
    uVar3 = FUN_004705f2(1,0xffffffff);
    FUN_005b870f(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (*(int *)(unaff_EBP + -0x18) == *(int *)(unaff_EBP + -0x1c)) {
      FUN_005d4bbf(&DAT_006d0498);
    }
    pvVar4 = operator_new(0xb0);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar4 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005a04d1();
    }
    extraout_ECX[2] = iVar2;
    uVar7 = 0;
    iVar2 = unaff_EBP + -0x1c;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    uVar6 = 0;
    uVar3 = DAT_006f6b64;
    uVar5 = DAT_006f6b68;
    (**(code **)(*extraout_ECX + 0xac))(DAT_006f6b64,DAT_006f6b68,iVar2,0,0);
    iVar2 = FUN_005a055f(uVar3,uVar5,iVar2,uVar6,uVar7);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*extraout_ECX + 0xac))();
      *(int **)(iVar2 + 0x14) = extraout_ECX;
      (**(code **)(*extraout_ECX + 0xc))();
      *(undefined1 *)(extraout_ECX + 0x36) = 1;
      *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
      (**(code **)(*extraout_ECX + 0x1c))();
      extraout_ECX[0x26] = -1;
      extraout_ECX[3] = 0;
      *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
      (**(code **)(*extraout_ECX + 0x60))();
      iVar2 = *(int *)(DAT_006e486c + 4);
      iVar1 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar2 + 0x28);
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar2 + 0x2c);
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar2 + 0x30);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar2 + 0x34);
      (**(code **)(iVar1 + 0x6c))(unaff_EBP + -0x2c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

