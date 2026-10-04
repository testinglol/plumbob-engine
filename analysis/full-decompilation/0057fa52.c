
uint __fastcall FUN_0057fa52(int *param_1)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int local_c;
  
  piVar1 = (int *)param_1[0x74];
  if (piVar1 == (int *)0x0) {
    uVar7 = in_EAX & 0xffffff00;
  }
  else {
    local_c = (**(code **)(*param_1 + 0x88))(0x13);
    iVar2 = (**(code **)(*param_1 + 0x88))(0x12);
    (**(code **)(*param_1 + 0x88))(0x14);
    iVar3 = (**(code **)(*param_1 + 0x88))(0x1a);
    (**(code **)(*param_1 + 0x88))(0x1b);
    (**(code **)(*param_1 + 0x88))(0x1c);
    (**(code **)(*param_1 + 0x88))(0x1d);
    iVar4 = (**(code **)(*param_1 + 0x88))(0x1e);
    iVar5 = (**(code **)(*param_1 + 0x88))(0x1f);
    uVar6 = (**(code **)(*param_1 + 0x88))(0x20);
    (**(code **)(*param_1 + 0x88))(0x38);
    (**(code **)(*param_1 + 0x88))(0x39);
    if (iVar3 == 0) {
      (**(code **)(*piVar1 + 0x48))(param_1[0x11]);
    }
    else {
      iVar8 = iVar4 - *(int *)(DAT_006f6a78 + 0xcc);
      iVar3 = iVar5 - *(int *)(DAT_006f6a78 + 0xd0);
      FUN_00636bef(iVar3 * iVar3 + iVar8 * iVar8 * 2);
      (**(code **)(*piVar1 + 0x4c))(iVar4,iVar5,uVar6);
    }
    iVar3 = (**(code **)(*(int *)param_1[0x31] + 0xb8))();
    if (iVar3 != 0) {
      iVar3 = FUN_0057c0ff(iVar3);
      if (*(int *)(iVar3 + 0xc0) != 0x400) {
        local_c = (*(int *)(iVar3 + 0xc0) * local_c) / 0x400;
      }
    }
    local_c = (iVar2 * local_c) / 0x400;
    iVar2 = (**(code **)(*param_1 + 0x88))(0x7b);
    if (iVar2 != 0) {
      iVar3 = (**(code **)(*param_1 + 0x88))(0x19);
      if (iVar3 < iVar2) {
        local_c = local_c / 2;
      }
    }
    uVar7 = (**(code **)(*piVar1 + 0x40))(local_c);
  }
  return uVar7;
}

