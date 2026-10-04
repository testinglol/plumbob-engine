
void __fastcall FUN_00432984(int param_1)

{
  char local_20 [4];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined1 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  local_1c = 0;
  local_18 = 0;
  FUN_004328f3(local_20);
  if (local_14 == 0) {
    if (local_20[0] != '\0') {
      local_8 = (undefined1)(local_18 >> 4);
      local_7 = (undefined1)(local_1c >> 4);
      local_6 = local_c;
      FUN_00432888(&local_8,0);
    }
  }
  else {
    *(undefined2 *)(*(int *)(local_14 + 0x130) + 0x10 + local_10 * 0x24) = 0;
  }
  *(undefined2 *)(param_1 + 0x66) = 0xffff;
  *(undefined2 *)(param_1 + 0x7e) = 0;
  return;
}

