
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00585c3e(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  int local_c;
  undefined1 local_5;
  
  iVar2 = (**(code **)(*param_1 + 0xac))();
  if (iVar2 == 0) {
    return;
  }
  iVar3 = (**(code **)(*param_1 + 0x34))();
  local_c = iVar3;
  (**(code **)(*param_1 + 0x38))();
  iVar2 = param_1[4];
  local_5 = 1;
  param_1[0x2d] = iVar3;
  if ((iVar2 != 0) && (ABS(*(float *)(iVar2 + 0x2c)) <= _DAT_0067343c)) {
    (**(code **)(*param_1 + 0xac))(iVar2);
    FUN_005a0903(iVar2);
    param_1[4] = 0;
  }
  (**(code **)(*param_1 + 0x58))();
  cVar1 = FUN_00422665(param_1[1] + 0xf4);
  if (cVar1 == '\0') {
    if ((((float)param_1[0x20] == DAT_00671d64) || ((float)param_1[0x21] == DAT_00671d64)) ||
       ((float)param_1[0x22] == DAT_00671d64)) {
      (**(code **)(*param_1 + 0x60))();
    }
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x5c))();
    local_1c = *puVar4;
    uStack_18 = puVar4[1];
    uStack_14 = puVar4[2];
    uStack_10 = puVar4[3];
    if ((param_2 == '\0') || (cVar1 = (**(code **)(*param_1 + 0x6c))(&local_1c), cVar1 != '\0')) {
      param_1[0x1e] = 0;
      uVar6 = 1;
      piVar5 = param_1 + 0xe;
      iVar2 = local_c;
      (**(code **)(*param_1 + 0xac))(piVar5,local_c,1);
      FUN_005a0d7d(piVar5,iVar2,uVar6);
      *(undefined1 *)((int)param_1 + 0x109) = 1;
    }
    else {
      piVar5 = param_1 + 0xe;
      param_1[0x1e] = 0;
      iVar2 = local_c;
      (**(code **)(*param_1 + 0xac))(piVar5,local_c);
      FUN_005a0e85(piVar5,iVar2);
      *(undefined1 *)((int)param_1 + 0x109) = 0;
    }
    FUN_004341a6(0);
    if ((*(char *)((int)param_1 + 0x109) == '\0') && (param_2 != '\0')) {
      local_5 = 0;
    }
    (**(code **)(*param_1 + 0xac))();
    FUN_005992ca(param_1[0x2d],local_5,0);
    (**(code **)(*param_1 + 0x60))();
    FUN_005994da(0);
    uVar6 = 0;
    (**(code **)(*param_1 + 0xac))(0);
    FUN_005a1444(uVar6);
    (**(code **)(*param_1 + 0x6c))(&local_1c);
    return;
  }
  return;
}

