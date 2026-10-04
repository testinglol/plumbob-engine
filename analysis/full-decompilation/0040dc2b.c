
void __thiscall FUN_0040dc2b(int param_1,uint param_2,char param_3)

{
  undefined **local_110;
  undefined4 local_10c;
  undefined1 local_104 [256];
  
  FUN_0040db91();
  FUN_0046f824(local_104,0,0x100);
  local_110 = &PTR_FUN_00666524;
  if (param_2 != 0xffffffff) {
    if ((int)param_2 < 0) {
      return;
    }
    if ((uint)(((*(int **)(param_1 + 0x88))[1] - **(int **)(param_1 + 0x88)) / 0x98) <= param_2) {
      return;
    }
    FUN_00473047(&local_110);
  }
  FUN_005876ac(0x21,local_10c);
  if (param_3 != '\0') {
    FUN_0040a5ea();
  }
  return;
}

