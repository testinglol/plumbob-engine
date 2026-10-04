
void __thiscall FUN_0062dafd(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  iVar5 = param_2 * 0xa0 + (int)param_3 * 0x48;
  iVar4 = iVar5 + 0x34e4 + param_1;
  iVar5 = *(int *)(iVar5 + 0x34f0 + param_1);
  iVar6 = (int)(char)(&DAT_0067d758)[iVar5];
  iVar5 = (int)(char)(&DAT_0067d768)[iVar5];
  if ((*(int *)(iVar4 + 0x10) == 0) || (*(int *)(iVar4 + 0x14) != 2)) {
    iVar4 = param_2 * 0xa0 + param_1;
    if ((*(int *)(iVar4 + 0x34d4) == 0) || (param_3 == (undefined4 *)0x0)) {
      iVar1 = param_2 * 0xf8 + param_1;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3614) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3618) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x361c) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3620) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3624) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3628) = uVar2;
    }
    if ((*(int *)(iVar4 + 0x34d8) == 0) || (param_3 == (undefined4 *)0x0)) {
      iVar1 = param_2 * 0xf8 + param_1;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x362c) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3630) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3634) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x3638) = uVar2;
      uVar2 = FUN_0062cc47(iVar6);
      *(undefined4 *)(iVar1 + 0x363c) = uVar2;
    }
    if ((*(int *)(iVar4 + 0x34dc) == 0) || (param_3 == (undefined4 *)0x0)) {
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)((param_2 + 0x38) * 0xf8 + param_1) = uVar2;
      iVar6 = param_2 * 0xf8 + param_1;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar6 + 0x3644) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar6 + 0x3648) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar6 + 0x364c) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar6 + 0x3650) = uVar2;
    }
    if ((*(int *)(iVar4 + 0x34e0) == 0) || (param_3 == (undefined4 *)0x0)) {
      iVar4 = param_2 * 0xf8 + param_1;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar4 + 0x3654) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar4 + 0x3658) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar4 + 0x365c) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar4 + 0x3660) = uVar2;
      uVar2 = FUN_0062cc47(iVar5);
      *(undefined4 *)(iVar4 + 0x3664) = uVar2;
    }
    param_1 = param_1 + param_2 * 0xf8;
    *(undefined4 *)(param_1 + 0x3668) = 0;
    *(undefined4 *)(param_1 + 0x366c) = 0;
  }
  else if (*(int *)(iVar4 + 0x18) == 0) {
    param_1 = param_1 + param_2 * 0xf8;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x3670) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36a4) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36d8) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x3674) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36a8) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36dc) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x3678) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36ac) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36e0) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x367c) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 14000) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36e4) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x3680) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36b4) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36e8) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x3684) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36b8) = uVar2;
    uVar2 = FUN_0062cc47(iVar6);
    *(undefined4 *)(param_1 + 0x36ec) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3688) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36bc) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36f0) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x368c) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36c0) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36f4) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3690) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36c4) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36f8) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3694) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36c8) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36fc) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3698) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36cc) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3700) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x369c) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x36d0) = uVar2;
    uVar2 = FUN_0062cc47(iVar5);
    *(undefined4 *)(param_1 + 0x3704) = uVar2;
    *(undefined4 *)(param_1 + 0x36a0) = 0;
    *(undefined4 *)(param_1 + 0x36d4) = 0;
    *(undefined4 *)(param_1 + 0x3708) = 0;
  }
  else {
    param_1 = param_1 + param_2 * 0xf8;
    param_3 = (undefined4 *)0x8;
    puVar3 = (undefined4 *)(param_1 + 0x3614);
    do {
      uVar2 = FUN_0062cc47((int)(char)(&DAT_0067d758)[*(int *)(iVar4 + 0xc)]);
      *puVar3 = uVar2;
      puVar3 = puVar3 + 1;
      param_3 = (undefined4 *)((int)param_3 + -1);
    } while (param_3 != (undefined4 *)0x0);
    param_3 = (undefined4 *)(param_1 + 0x367c);
    local_8 = 3;
    do {
      local_c = 3;
      puVar3 = param_3;
      do {
        uVar2 = FUN_0062cc47((int)(char)(&DAT_0067d758)[*(int *)(iVar4 + 0xc)]);
        *puVar3 = uVar2;
        puVar3 = puVar3 + 0xd;
        local_c = local_c + -1;
      } while (local_c != 0);
      param_3 = param_3 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    param_3 = (undefined4 *)(param_1 + 0x3688);
    local_8 = 6;
    do {
      local_c = 3;
      puVar3 = param_3;
      do {
        uVar2 = FUN_0062cc47((int)(char)(&DAT_0067d768)[*(int *)(iVar4 + 0xc)]);
        *puVar3 = uVar2;
        puVar3 = puVar3 + 0xd;
        local_c = local_c + -1;
      } while (local_c != 0);
      param_3 = param_3 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    puVar3 = (undefined4 *)(param_1 + 0x36a0);
    iVar5 = 3;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 0xd;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

