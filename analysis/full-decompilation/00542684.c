
void __fastcall FUN_00542684(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x388) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  else {
    *(int *)(param_1 + 900) = *(int *)(param_1 + 900) + 1;
    if (*(int *)(param_1 + 900) % 5 == 0) {
      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
    }
    if (*(int *)(param_1 + 0x7c) == 6) {
      *(undefined4 *)(param_1 + 0x7c) = 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x7c);
  }
  FUN_005429ae(0,0x3e,uVar1);
  return;
}

