
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0058707c(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  short local_10;
  short local_e;
  float local_c;
  int local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (((iVar1 != 0) && (*(short *)(iVar1 + 0x8e) == 0)) && (-1 < *(short *)(iVar1 + 0x84))) {
    piVar2 = *(int **)(DAT_006e486c + 4);
    local_14 = param_1;
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    iVar1 = *(int *)(iVar3 + 0x10);
    iVar3 = *(int *)(iVar3 + 0x14);
    local_8 = (**(code **)(*piVar2 + 0x14))();
    local_c = _DAT_00671d58 * _DAT_00666cbc;
    FUN_00434e9b(&local_c);
    local_c = (float)(1 << ((char)local_8 + 1U & 0x1f));
    local_c = (float)__ftol();
    iVar4 = *(int *)(local_14 + 4);
    local_8 = *(int *)(iVar4 + 0x110);
    local_24 = *(undefined4 *)(iVar4 + 0xf4);
    local_20 = *(undefined4 *)(iVar4 + 0xf8);
    FUN_0047bd91(&local_20,&local_24,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
    (**(code **)*piVar2)(&local_10,local_24,local_20,local_8,DAT_006f0088,0);
    local_1c = (int)local_e;
    local_18 = (int)local_10;
    local_14 = *(int *)(DAT_006f2a08 + 0xb0);
    iVar4 = (**(code **)(*piVar2 + 0x38))();
    if (local_8 == iVar4) {
      if (((local_1c < iVar1 / 4) || (local_18 < iVar3 / 4 + (int)local_c)) ||
         (((iVar1 * 3) / 4 <= local_1c || ((iVar3 * 3) / 4 <= local_18)))) {
        FUN_004a798b(local_1c,local_18 - (int)local_c / 2,param_2);
        FUN_004b1668(0,0);
      }
    }
    else {
      local_18 = local_18 + (int)local_c / -2;
      FUN_004a82db(local_8,0);
      FUN_004b1668(0,0);
      if (local_14 != 0) {
        FUN_004cefa3(local_8,0);
      }
      FUN_004a798b(local_1c,local_18,param_2);
    }
  }
  return;
}

