
undefined4 __thiscall FUN_00476c67(int *param_1,int param_2,short param_3)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = (**(code **)(*param_1 + 0x38))();
  iVar1 = DAT_006e57d8;
  if (local_8 == 0) {
    local_8 = 1;
  }
  if (DAT_006e54ac == (int *)0x0) {
LAB_00476c8e:
    uVar3 = 0;
  }
  else {
    local_14 = DAT_006e57d8;
    local_10 = DAT_006e57dc;
    if ((param_3 != 0) &&
       (sVar2 = (**(code **)(*DAT_006e54ac + 8))(), piVar4 = DAT_006e54b0, sVar2 != 0)) {
      for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
        (**(code **)(*piVar4 + 0x44))(iVar1,local_10,local_8);
      }
    }
    (**(code **)(*DAT_006e54ac + 0x44))((undefined4 *)(param_2 + 0xc));
    uVar3 = *(undefined4 *)(param_2 + 0xc);
    local_c = 0;
    piVar4 = (int *)(**(code **)(*param_1 + 4))(local_1c,uVar3,1);
    iVar1 = *piVar4;
    local_18 = piVar4[1];
    sVar2 = (**(code **)(*DAT_006e54ac + 0x10))();
    if (sVar2 != 0) {
      local_c = (**(code **)(*param_1 + 0x28))(uVar3,local_8,1);
    }
    if (param_3 == 0) {
      (**(code **)(*DAT_006e54ac + 0x1c))(iVar1,local_18,local_c,param_2);
    }
    else {
      sVar2 = (**(code **)(*DAT_006e54ac + 4))();
      if (((sVar2 == 0) && (local_10 == local_18)) && (local_14 == iVar1)) goto LAB_00476c8e;
      (**(code **)(*DAT_006e54ac + 0x28))(iVar1,local_18,local_c,param_2);
    }
    uVar3 = 1;
  }
  return uVar3;
}

