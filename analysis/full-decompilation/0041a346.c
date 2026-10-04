
void __thiscall FUN_0041a346(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_50;
  int local_4c;
  byte local_46;
  
  iVar2 = FUN_0041a545(&local_50,param_2);
  if (iVar2 == 0) {
    local_46 = local_46 | 4;
    local_50 = 0x58585858;
    piVar1 = (int *)(*(int *)(param_1 + 0x18) + 0xc);
    *piVar1 = *piVar1 + local_4c;
    FUN_0041a5ac(&local_50,param_2);
  }
  return;
}

