
undefined4 FUN_00610450(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  uVar3 = 0x2d;
  uVar2 = 3;
  if (puVar1 != (undefined4 *)0x0) {
    if (0 < *(int *)(param_1 + 0x10)) {
      uVar3 = *puVar1;
    }
    if (1 < *(int *)(param_1 + 0x10)) {
      uVar2 = puVar1[2];
    }
  }
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  FUN_006104c0(*(undefined4 *)(param_1 + 0xc),&local_c,uVar3,uVar2);
  return 1;
}

