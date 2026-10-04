
void __thiscall FUN_00418036(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  int local_10;
  byte local_a;
  
  iVar1 = FUN_004181b3(&local_14,param_2);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + local_10;
    local_a = local_a | 4;
    local_14 = 0x58585858;
    FUN_00418223(&local_14,param_2);
  }
  return;
}

