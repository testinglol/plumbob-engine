
undefined4 __thiscall
FUN_0057dc59(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  iVar2 = (**(code **)(*(int *)param_1[0x31] + 0xb8))();
  if (iVar2 != 0) {
    uVar3 = (**(code **)(*(int *)param_1[0x31] + 0xb8))();
    iVar2 = FUN_0057c0ff(uVar3);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc0) == 0)) {
      return 1;
    }
  }
  *(undefined1 *)((int)param_1 + 0x1cf) = 0;
  param_1[0x2a] = 0;
  param_1[0x32] = (int)param_1;
  (**(code **)(*param_1 + 0x84))(1,param_2,0);
  (**(code **)(*param_1 + 0x84))(2,param_3,0);
  (**(code **)(*param_1 + 0x84))(3,param_4,0);
  if (((char)param_1[0x71] != '\0') && (cVar1 = (**(code **)(*param_1 + 0x74))(), cVar1 != '\0')) {
    param_1[0x72] = 1;
    uVar3 = (**(code **)(*param_1 + 0x5c))();
    return uVar3;
  }
  param_1[0x72] = 0;
  if (((char)param_1[0x71] == '\0') || (iVar2 = (**(code **)(*param_1 + 0x88))(0x37), iVar2 != 0)) {
    iVar2 = 0;
    if (0 < param_1[0x34]) {
      do {
        *(undefined4 *)(param_1[0x36] + iVar2 * 4) = *(undefined4 *)(DAT_006f6854 + iVar2 * 4);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x34]);
    }
    local_8 = 0;
    if (0 < param_1[8]) {
      do {
        iVar2 = local_8 * 4;
        local_8 = local_8 + 1;
        *(undefined4 *)(iVar2 + param_1[10]) = *(undefined4 *)(iVar2 + DAT_006f6904);
      } while (local_8 < param_1[8]);
    }
    local_8 = 0;
    do {
      if ((local_8 < param_1[0x35]) || (param_1[0x34] + param_1[0x35] <= local_8)) {
        if ((param_1[9] <= local_8) && (local_8 < param_1[8] + param_1[9])) {
          iVar2 = (**(code **)(*(int *)param_1[0x31] + 0xb4))(local_8);
          goto joined_r0x0057dde0;
        }
      }
      else {
        iVar2 = (**(code **)(*(int *)param_1[0x31] + 0xb4))(local_8);
joined_r0x0057dde0:
        if (iVar2 != -0x80000000) {
          FUN_005805fa(local_8,iVar2);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < 0x7f);
    iVar2 = (**(code **)(*param_1 + 0x28))();
    if (iVar2 == 0) {
      (**(code **)(*param_1 + 0x24))();
    }
    else if (iVar2 == 1) {
      FUN_005805fa(0x13,param_2);
      FUN_005805fa(0x14,param_3);
    }
    else if (iVar2 == 2) {
      FUN_005805fa(0x13,param_3);
      FUN_005805fa(0x14,param_4);
      (**(code **)(*param_1 + 0x20))(param_2);
    }
    uVar3 = (**(code **)(*(int *)param_1[0x31] + 0x88))(0x32);
    FUN_0057f91e(uVar3);
    FUN_0057fa52();
    FUN_0057fa16();
    iVar2 = FUN_0057dedb();
    param_1[0x67] = iVar2;
    param_1[0x68] = iVar2;
    FUN_00602b9f();
    FUN_00602b9f();
    param_1[0x70] = (int)(param_1 + 0x6b);
    param_1[0x66] = *(int *)(DAT_006f6a78 + 0x58);
    (**(code **)(*param_1 + 0x94))(0x2e,1,0);
    *(undefined1 *)(param_1 + 0x71) = 1;
    (**(code **)(*param_1 + 0x58))();
  }
  return 1;
}

