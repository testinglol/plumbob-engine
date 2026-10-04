
void __fastcall FUN_0050c729(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_10;
  
  if (param_1[0x3c] != 0) {
    iVar1 = FUN_004cb7c0();
    iVar6 = (int)*(char *)((int)param_1 + 0xde);
    if (iVar1 == 0) {
      *(undefined1 *)((int)param_1 + 0xdd) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x37) = 1;
      *(char *)((int)param_1 + 0xde) = (char)iVar1;
      (**(code **)(*param_1 + 0x168))();
    }
    iVar2 = FUN_00636bef(iVar6);
    iVar3 = FUN_00636bef(iVar1);
    if ((iVar1 == 0) || (iVar6 == 0)) {
      bVar7 = true;
    }
    else {
      bVar7 = iVar6 * iVar1 < 0;
    }
    if ((iVar3 != iVar2) || (bVar7)) {
      (**(code **)(*param_1 + 0x168))();
      iVar4 = FUN_00636bef(iVar6);
      iVar1 = FUN_00636bef(iVar1);
      iVar6 = ((-1 < *(char *)((int)param_1 + 0xde)) - 1 & 0xfe0100) + 0xff00;
      if (bVar7) {
        local_10 = iVar1;
        if (0 < iVar1) {
          do {
            FUN_0050c54c(0x52,iVar6,500);
            local_10 = local_10 + -1;
          } while (local_10 != 0);
        }
        if (iVar1 < 5) {
          iVar1 = 5 - iVar1;
          do {
            FUN_0050c54c(0x52,0x52,0);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      else if (iVar3 - iVar2 < 1) {
        if ((iVar3 - iVar2 < 0) && (iVar1 <= iVar4 + -1)) {
          iVar1 = ((iVar4 + -1) - iVar1) + 1;
          do {
            uVar9 = 500;
            uVar8 = 0x52;
            uVar5 = FUN_0050c626(0x52,500);
            FUN_0050c54c(uVar5,uVar8,uVar9);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      else {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = iVar4 + -1;
        }
        if (iVar4 < iVar1) {
          iVar1 = iVar1 - iVar4;
          do {
            uVar8 = 500;
            iVar2 = iVar6;
            uVar5 = FUN_0050c626(iVar6,500);
            FUN_0050c54c(uVar5,iVar2,uVar8);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
    }
  }
  return;
}

