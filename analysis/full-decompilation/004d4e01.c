
void __thiscall FUN_004d4e01(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 local_18 [12];
  undefined2 local_c;
  undefined2 local_a;
  ushort local_8;
  
  if ((char)param_1[0x24] != '\0') {
    local_8 = 0;
    local_c = (undefined2)param_3;
    local_a = (undefined2)param_2;
    if ((param_4 & 1) != 0) {
      local_8 = 0x200;
    }
    if ((param_4 & 2) != 0) {
      local_8 = local_8 | 0x100;
    }
    FUN_00476e6f(local_18);
    FUN_005d9912(param_1[0x20]);
    (**(code **)(*param_1 + 8))(param_2,param_3,param_4);
  }
  return;
}

