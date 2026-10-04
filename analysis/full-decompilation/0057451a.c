
void __thiscall FUN_0057451a(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_005763bc(&local_24,&param_3);
  local_10 = local_18;
  local_c = local_24;
  local_8 = local_20;
  while( true ) {
    if (local_c == local_1c) {
      *param_2 = 0;
      param_2[1] = param_1 + 0xd4;
      return;
    }
    if (*(int *)(local_c + 8) == param_4) break;
    FUN_00576e56();
  }
  *param_2 = local_c;
  param_2[1] = local_8;
  return;
}

