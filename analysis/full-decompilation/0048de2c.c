
void __fastcall FUN_0048de2c(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  FUN_00587cc7();
  if (*(char *)(param_1 + 0xd8) != '\0') {
    (**(code **)(*DAT_006fe8bc + 0x18))();
    piVar1 = (int *)FUN_004b46a0();
    (**(code **)(*piVar1 + 0x24))(*(undefined4 *)(param_1 + 0xdc));
    (**(code **)(**(int **)(param_1 + 0xdc) + 0x264))();
  }
  if (*(char *)(param_1 + 0xda) != '\0') {
    FUN_005ddfdc(0);
  }
  if (*(char *)(param_1 + 0xd9) != '\0') {
    FUN_005ddfdc(0);
  }
  FUN_0048e3fa(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50));
  return;
}

