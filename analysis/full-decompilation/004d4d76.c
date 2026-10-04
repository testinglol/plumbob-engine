
void __thiscall FUN_004d4d76(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  SHORT SVar1;
  undefined1 local_18 [12];
  undefined2 local_c;
  undefined2 local_a;
  ushort local_8;
  
  if (((char)param_1[0x24] != '\0') && (*(char *)((int)param_1 + 0x92) == '\0')) {
    (**(code **)(*param_1 + 8))(param_2,param_3,param_4);
    FUN_005d98fc(param_1[0x20]);
    if (param_1[1] == 0) {
      local_8 = 0;
      local_a = (undefined2)param_2;
      local_c = (undefined2)param_3;
      if ((param_4 & 1) != 0) {
        local_8 = 0x200;
      }
      if ((param_4 & 2) != 0) {
        local_8 = local_8 | 0x100;
      }
      SVar1 = GetKeyState(1);
      FUN_00476d78(local_18,SVar1 < 0);
    }
  }
  return;
}

