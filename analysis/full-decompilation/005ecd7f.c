
void __thiscall FUN_005ecd7f(int param_1,int *param_2)

{
  undefined4 uVar1;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(param_1 + 0x94) != 0) {
    local_14 = *param_2;
    local_10 = param_2[1];
    local_c = param_2[2];
    local_8 = param_2[3];
    FUN_005de841(&local_14,*(int *)(param_1 + 0x78) + 0x2a4);
    if ((local_14 < local_c) && (local_10 < local_8)) {
      uVar1 = FUN_004b469d();
      FUN_005caf65(uVar1);
    }
    local_24 = *param_2;
    local_20 = param_2[1];
    local_1c = param_2[2];
    local_18 = param_2[3];
    FUN_005de841(&local_24,*(int *)(param_1 + 0x78) + 0x2b4);
    if ((local_24 < local_1c) && (local_20 < local_18)) {
      uVar1 = FUN_004b469d();
      FUN_005caf53(uVar1);
    }
  }
  return;
}

