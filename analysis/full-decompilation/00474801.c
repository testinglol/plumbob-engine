
void __thiscall FUN_00474801(ushort *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  byte *pbVar1;
  ushort *local_8;
  
  if (0x19 < param_3) {
    local_8 = param_1;
    FUN_00464973(param_1 + 2,1);
  }
  if (*param_1 == 0xffff) {
    local_8 = (ushort *)0xffffffff;
  }
  else {
    local_8 = (ushort *)(*param_1 & 0x7fff);
  }
  FUN_00464973(&local_8,1);
  if ((ushort)local_8 == 0xffff) {
    *param_1 = 0xffff;
  }
  else {
    *param_1 = *param_1 & 0x8000 | (ushort)local_8;
  }
  FUN_00464973(param_1 + 1,1);
  FUN_00464895(param_1 + 3,1);
  pbVar1 = (byte *)((int)param_1 + 7);
  FUN_00464895(pbVar1,1);
  FUN_00464973(param_1 + 8,*pbVar1);
  FUN_00464973(param_1 + *pbVar1 + 8,(char)param_1[3]);
  FUN_00464a5e(param_1 + 4,1);
  (**(code **)*param_4)(param_1 + 6,param_2,param_3);
  return;
}

