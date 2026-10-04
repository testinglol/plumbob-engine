
int __thiscall FUN_0042612b(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **local_440 [3];
  undefined1 local_434 [256];
  undefined **local_334 [3];
  undefined1 local_328 [256];
  undefined **local_228;
  undefined4 local_224;
  undefined1 local_21c [256];
  undefined **local_11c [3];
  undefined1 local_110 [260];
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(DAT_006e486c + 0x28);
  if (param_3 == 0) {
LAB_00426160:
    uVar1 = 0x7fd96b54;
  }
  else if (param_3 == 1) {
    uVar1 = 0x4a70df92;
  }
  else {
    if (param_3 != 2) goto LAB_00426160;
    uVar1 = 0x7bea0977;
  }
  iVar2 = FUN_00425769(uVar1);
  if (iVar2 == 0) {
    return -1;
  }
  if (*(undefined4 **)(iVar2 + 8) == (undefined4 *)0x0) {
    return -1;
  }
  local_c = **(undefined4 **)(iVar2 + 8);
  param_3 = -0x2b;
  FUN_0046f824(local_110,0,0x104);
  local_11c[0] = &PTR_FUN_006664e8;
  if (*(int *)(param_1 + 0x160) < 32000) {
    do {
      if (param_3 != -0x2b) break;
      FUN_0046fb9b(local_21c,0x100);
      local_228 = &PTR_LAB_0066655c;
      FUN_00635858(local_224,s_User_05d_006c2650,*(undefined4 *)(param_1 + 0x160));
      FUN_0046f824(local_328,0,0x100);
      local_334[0] = &PTR_FUN_00666524;
      FUN_0046f8e4(&local_228);
      FUN_0046f847(&DAT_006c2648,0xffffffff);
      FUN_00412122(param_1,local_11c);
      FUN_0046f847(s_Characters__006c1d48,0xffffffff);
      FUN_0046f917(local_334,0xffffffff);
      FUN_0046f824(local_434,0,0x100);
      local_440[0] = &PTR_FUN_00666524;
      FUN_0046f8e4(&local_228);
      FUN_0046fa24(0x20);
      FUN_0047234b();
      FUN_0047239b(local_440);
      param_3 = FUN_004723b0(local_c,local_11c);
      *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    } while (*(int *)(param_1 + 0x160) < 32000);
    if (*(int *)(param_1 + 0x160) < 32000) goto LAB_00426311;
  }
  *(undefined4 *)(param_1 + 0x160) = 0;
LAB_00426311:
  if (param_3 != 0) {
    return param_3;
  }
  FUN_0043c422(local_11c);
  iVar4 = 0;
  param_3 = 0;
  iVar2 = FUN_0043ad1f(0);
  if (iVar2 != 0) {
    do {
      if (((*(short *)(*(int *)(iVar2 + 0x60) + 0x12) == 2) &&
          (iVar3 = FUN_004257ba(iVar2), iVar3 == 0)) && (iVar4 == 0)) {
        iVar4 = FUN_004257ef(iVar2,param_4);
      }
      param_3 = param_3 + 1;
      iVar2 = FUN_0043ad1f(param_3);
    } while (iVar2 != 0);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 8) != 0)) {
      *param_2 = iVar4;
      return 0;
    }
  }
  return -1;
}

