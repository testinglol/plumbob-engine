
uint __thiscall FUN_005fbd8e(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  short local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined4 local_c;
  undefined2 local_8;
  undefined2 local_6;
  
  uVar3 = 0;
  FUN_005b8e25(param_2,0);
  iVar1 = FUN_005b936f(param_2,uVar3);
  *(int *)(param_1 + 0xf0c) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xf64) = 1;
    uVar2 = 0;
    goto LAB_005fbeb8;
  }
  FUN_005b903c(0x1000,0);
  FUN_005b8f4a(0);
  iVar1 = FUN_005b8e6a((char *)(param_1 + 0xf48),8);
  if (iVar1 == 8) {
    if ((*(char *)(param_1 + 0xf48) == 'X') && (*(char *)(param_1 + 0xf49) == 'A')) {
      iVar1 = FUN_005b8e6a(&local_14,0x10);
      if (iVar1 != 0x10) goto LAB_005fbe22;
      if (local_14 == 1) {
        *(undefined2 *)(param_1 + 0xf50) = 1;
        *(undefined2 *)(param_1 + 0xf52) = local_12;
        *(undefined4 *)(param_1 + 0xf54) = local_10;
        *(undefined4 *)(param_1 + 0xf58) = local_c;
        *(undefined2 *)(param_1 + 0xf5c) = local_8;
        *(undefined2 *)(param_1 + 0xf5e) = local_6;
        *(undefined2 *)(param_1 + 0xf60) = 0;
        *(undefined4 *)(param_1 + 0xf68) = *(undefined4 *)(param_1 + 0xf4c);
        *(undefined4 *)(param_1 + 0xf04) = 0xf00;
        *(undefined4 *)(param_1 + 0xf08) = 0;
        return 1;
      }
    }
    *(undefined4 *)(param_1 + 0xf64) = 3;
  }
  else {
LAB_005fbe22:
    *(undefined4 *)(param_1 + 0xf64) = 4;
  }
  uVar3 = *(undefined4 *)(param_1 + 0xf0c);
  FUN_005b8e25(uVar3);
  uVar2 = FUN_005b95c0(uVar3);
  *(undefined4 *)(param_1 + 0xf0c) = 0;
LAB_005fbeb8:
  return uVar2 & 0xffffff00;
}

