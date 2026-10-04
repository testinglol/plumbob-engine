
undefined4 __thiscall FUN_005bf37b(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_2;
  if (param_2 == 0xffffffff) {
    uVar1 = 0;
  }
  uVar1 = uVar1 & 0xfffffffe;
  if ((uVar1 != 0) && (uVar1 < 4)) {
    uVar1 = 4;
  }
  if (0x1f4000 < uVar1) {
    uVar1 = 0x1f4000;
  }
  if (uVar1 < *(uint *)(param_1 + 0x50)) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  *(uint *)(param_1 + 0x50) = uVar1;
  if (*(int *)(param_1 + 0x54) != *(int *)(param_1 + 0x58)) {
    param_2 = param_2 & 0xffffff;
    FUN_005bfb21(uVar1,(int)&param_2 + 3);
  }
  uVar1 = param_3;
  if (param_3 == 0xffffffff) {
    uVar1 = 0;
  }
  uVar1 = uVar1 & 0xfffffffe;
  if ((uVar1 != 0) && (uVar1 < 4)) {
    uVar1 = 4;
  }
  if (0x1f4000 < uVar1) {
    uVar1 = 0x1f4000;
  }
  if (uVar1 < *(uint *)(param_1 + 0x68)) {
    FUN_005bf04f();
  }
  *(uint *)(param_1 + 0x68) = uVar1;
  if (*(int *)(param_1 + 0x6c) != *(int *)(param_1 + 0x70)) {
    param_2 = param_2 & 0xffffff;
    FUN_005bfb21(uVar1,(int)&param_2 + 3);
  }
  return 1;
}

