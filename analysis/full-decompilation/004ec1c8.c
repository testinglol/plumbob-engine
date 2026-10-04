
void __fastcall FUN_004ec1c8(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0xe8) = 0;
  if (*(int *)(param_1 + 0xe0) == 0) {
    if (*(char *)(param_1 + 0x169) == '\0') {
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0xe4) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0xe4) = 2;
  }
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1b4) - *(int *)(param_1 + 0x1b0) >> 2 != 0) {
    puVar2 = (undefined4 *)(param_1 + 0x194);
    do {
      (**(code **)(*(int *)*puVar2 + 0x90))(2,*(int *)(param_1 + 0xe0) != 0);
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar1 < (uint)(*(int *)(param_1 + 0x1b4) - *(int *)(param_1 + 0x1b0) >> 2));
  }
  return;
}

