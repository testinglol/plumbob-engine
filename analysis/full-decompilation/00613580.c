
undefined4 FUN_00613580(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  iVar1 = *(int *)(param_1 + 0x10);
  uVar2 = 1;
  local_20 = 0;
  local_1c = 0;
  local_24 = 0;
  local_14 = param_2;
  if (0 < iVar1) {
    local_20 = **(undefined4 **)(param_1 + 0x14);
    local_1c = (*(undefined4 **)(param_1 + 0x14))[1];
  }
  if (1 < iVar1) {
    local_24 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 8);
  }
  if (2 < iVar1) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10);
  }
  FUN_00613650(*(undefined4 *)(param_1 + 0xc),&local_14,local_20,local_1c,local_24,local_24,uVar2);
  return 1;
}

