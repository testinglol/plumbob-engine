
void FUN_00588907(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  (**(code **)(*extraout_ECX + 0x10))();
  iVar2 = FUN_004580cc(0);
  extraout_ECX[0xa0] = iVar2;
  *(undefined2 *)(extraout_ECX[0x4e] + 0x5b8) = 0;
  *(undefined2 *)(extraout_ECX[0x4e] + 0x5ba) = 0;
  if (extraout_ECX[2] != 0) {
    FUN_0058a17c(0);
  }
  iVar2 = FUN_004705f2(0xd,0xffffffff);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != 0) {
    FUN_0046f824(unaff_EBP + -0x28c,0,0x100);
    *(undefined ***)(unaff_EBP + -0x298) = &PTR_FUN_00666524;
    FUN_0046f8cb(*(undefined4 *)(unaff_EBP + -0x10));
    FUN_0046f824(unaff_EBP + -0x114,0,0x100);
    *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
    FUN_0046f847(&DAT_006c1070,0xffffffff);
    iVar2 = FUN_0046f973(unaff_EBP + -0x120);
    if (iVar2 == 0) {
      *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 0;
    }
    else {
      FUN_0046f824(unaff_EBP + -0x114,0,0x100);
      *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
      FUN_0046f847(s_female_006c1068,0xffffffff);
      iVar2 = FUN_0046f973(unaff_EBP + -0x120);
      if (iVar2 == 0) {
        *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 1;
      }
      else {
        FUN_0046f824(unaff_EBP + -0x114,0,0x100);
        *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
        FUN_0046f847(s_dogmale_006c1060,0xffffffff);
        iVar2 = FUN_0046f973(unaff_EBP + -0x120);
        if (iVar2 == 0) {
          *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 2;
        }
        else {
          FUN_0046f824(unaff_EBP + -0x114,0,0x100);
          *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
          FUN_0046f847(s_dogfemale_006c1054,0xffffffff);
          iVar2 = FUN_0046f973(unaff_EBP + -0x120);
          if (iVar2 == 0) {
            *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 3;
          }
          else {
            FUN_0046f824(unaff_EBP + -0x114,0,0x100);
            *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
            FUN_0046f847(s_catmale_006c104c,0xffffffff);
            iVar2 = FUN_0046f973(unaff_EBP + -0x120);
            if (iVar2 == 0) {
              *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 4;
            }
            else {
              FUN_0046f824(unaff_EBP + -0x114,0,0x100);
              *(undefined ***)(unaff_EBP + -0x120) = &PTR_FUN_00666524;
              FUN_0046f847(s_catfemale_006c1040,0xffffffff);
              iVar2 = FUN_0046f973(unaff_EBP + -0x120);
              if (iVar2 == 0) {
                *(undefined2 *)(extraout_ECX[0x4e] + 0x60e) = 5;
              }
            }
          }
        }
      }
    }
  }
  iVar2 = FUN_004705f2(0xe,0xffffffff);
  if (iVar2 != 0) {
    uVar1 = FUN_00635f62(iVar2);
    *(undefined2 *)(extraout_ECX[0x4e] + 0x600) = uVar1;
  }
  iVar2 = FUN_004705f2(0xf,0xffffffff);
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if (iVar2 != 0) {
    uVar3 = FUN_00401f77();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x18c) = &PTR_FUN_0066643c;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00470383(*(undefined4 *)(unaff_EBP + -0x10),0x2000,0);
    *(undefined2 *)(extraout_ECX[0x4e] + 0x604) = 0;
    FUN_0046f824(unaff_EBP + -0x4a4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x4b0) = &PTR_FUN_00666524;
    FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
    *(undefined4 *)(unaff_EBP + -0x10) = 2;
    iVar2 = FUN_0046fbe5(0xffffffff);
    if (1 < iVar2) {
      do {
        uVar3 = FUN_004705f2(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
        *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
        FUN_0046f824(unaff_EBP + -0x398,0,0x100);
        *(undefined ***)(unaff_EBP + -0x3a4) = &PTR_FUN_00666524;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x14),0xffffffff);
        iVar2 = FUN_0046f973(unaff_EBP + -0x3a4);
        if (iVar2 == 0) {
          *(short *)(extraout_ECX[0x4e] + 0x604) = (short)*(undefined4 *)(unaff_EBP + -0x10) + -1;
          break;
        }
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        iVar2 = FUN_0046fbe5(0xffffffff);
      } while (*(int *)(unaff_EBP + -0x10) <= iVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_00470467();
  }
  (**(code **)(*extraout_ECX + 0x18))();
  extraout_ECX[0x6c] = -1;
  extraout_ECX[0x6d] = -1;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  return;
}

